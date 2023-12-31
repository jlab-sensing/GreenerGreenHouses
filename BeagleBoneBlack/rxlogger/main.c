/*
Filename: rxlogger.c
Last updated: 2023-09-18 11:30 AM
Author: Jack Lin <jlin143@ucsc.edu>

Brief:
rxlogger (running on a BeagleBone Black) polls the CC1125 sub 1 GHz radio for 
4-byte data packets sent from an IoT tag (MSP430) containing temperature and 
relative humidity. The temperature and relative humidity is used to update 
the BeagleBone Black's modbus registers with the latest data for the device ID, 
and is also logged to a CSV file. rxlogger provides the temperature and 
relative humidity data to a modbus master (Argus Controls) through a USB-RS485 
FTDI cable.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
// #include <signal.h>
// #include <linux/spi/spidev.h>
// #include <linux/types.h>
// #include <sys/ioctl.h>
// #include <fcntl.h>
#include <modbus/modbus.h>
#include "cc112x_spi.h"
#include "cc112x_easy_link_reg_config.h"
#include <time.h>
#include <errno.h>

// #define LIST_ALL_REGISTERS

// #define SKIP_LORA
// #define SKIP_MODBUS
// #define MODBUS_DEBUG_ENABLE

#define PACKET_STATUS_BYTES 2 // can be 0 or 2 depending on register config

#define MODBUS_NONBLOCKING
#ifdef MODBUS_NONBLOCKING
#define MODBUS_RECEIVE_TIMEOUT_SEC  0
#define MODBUS_RECEIVE_TIMEOUT_USEC 500000
#endif

#define MAX_PACKET_LENGTH 128
#define MAX_FILENAME_LENGTH 50

#ifndef SPI_BBBREVC_H // from "SPI.h"
#define SPI_DEV_BUS0_CS0 "/dev/spidev0.0"
#define SPI_DEV_BUS1_CS0 "/dev/spidev1.0"
#define SPI_DEV_BUS1_CS1 "/dev/spidev1.1"
#endif
#define SPI_DEVICE SPI_DEV_BUS0_CS0

#ifndef SPIDEV_H // from <linux/spi/spidev.h>
#define SPI_CPHA        0x01
#define SPI_CPOL        0x02
#define SPI_MODE_0      (0|0)
#define SPI_MODE_1      (0|SPI_CPHA)
#define SPI_MODE_2      (SPI_CPOL|0)
#define SPI_MODE_3      (SPI_CPOL|SPI_CPHA)
#endif

// Bitmasks for the CC1125 marcstate register
#define MARCSTATE_NOT_USED_MASK 0x80
#define MARC_2PIN_STATE_MASK 0x60
#define MARC_STATE_MASK 0x1F
#define RX_FIFO_ERROR 0x11

// Modbus (slave/server) ID of the device running this program.
// This program responds to requests to the ID listed here.
#define MODBUS_SLAVE_ID 0x01

// Highest tag device ID supported by this program
#define MAX_TAG_DEVICE_ID 0xF

// Modbus map size (# of rows)
#define MAP_SIZE_BITS   0
#define MAP_SIZE_IBITS  0
#define MAP_SIZE_REGS   ((MAX_TAG_DEVICE_ID + 1) * 6) // 6 registers per tag (temperature, humidity: 16 bit raw and 32 bit floats)
#define MAP_SIZE_IREGS  0
#if ((MAP_SIZE_BITS + MAP_SIZE_IBITS + MAP_SIZE_IREGS) == 0)
#define MAP_PRINT_REGS_ONLY // enables x by y register table printing, and omits bits, ibits, and iregs. Comment out the condition to force this option.
#endif

// Modbus RTU settings
#define RTU_PORT        "/dev/ttyUSB0" // set this string to the USB/serial device connected to the RS485 cable.
#define RTU_BAUD        19200
#define RTU_PARITY      'N'
#define RTU_DATA_BITS   8
#define RTU_STOP_BITS   1

typedef enum {
    UNKNOWN,
    RH_T_16_BIT, // full 16 bits regardless of set accuracy
    RH_T_14_BIT,
    RH_T_11_BIT,
    RH_T_9_BIT
} packetType_t;

// Struct that holds the fields that a packet may have.
// Depending on the packet type and CC1125 configuration, only certain fields 
// may be relevant (i.e. rssi enable/disable, crc16 retained/discarded).
typedef struct {
    packetType_t type;
    int deviceID;
    uint16_t temperature_raw;
    float temperature_scaled;
    uint16_t humidity_raw;
    float humidity_scaled;
    uint16_t rssi;
    uint16_t crc16;
} packetStruct_t;

// Function Prototypes
static int spi_init(int baudrate);

static int radio_init(void);
static void manualCalibration(void);
static uint16_t registerConfig(const registerSetting_t *reg, int numRegisters);

static int modbus_init(modbus_t **mb, modbus_mapping_t **map, unsigned int bits, unsigned int ibits, unsigned int regs, unsigned int iregs);
static void print_modbus_mapping(modbus_mapping_t *map);

static packetType_t packetParser(uint8_t *packet, uint8_t length, packetStruct_t *returnPacket);

int main(int argc, char *argv[]){
    
    FILE *fpData = NULL;
    modbus_t *mb = NULL;
    modbus_mapping_t *map = NULL;

    printf("Program start.\n");
    
    if (spi_init(1000000) == -1){
        printf("spi_init() error\n");
    }
    
#ifndef SKIP_LORA
    printf("Initializing radio...\n");
    if (radio_init() == -1){
        printf("radio_init() error\n");
        return -1;
    }else{
        printf("Done initializing radio\n");
    }
#else
    printf("SKIP_LORA\n");
#endif

#ifndef SKIP_MODBUS
    printf("modbus init...\n");
    if (modbus_init(&mb, &map, MAP_SIZE_BITS, MAP_SIZE_IBITS, MAP_SIZE_REGS, MAP_SIZE_IREGS) == -1){
        printf("modbus_init() error\n");
        return -1;
    }else{
        printf("Done initializing modbus\n");
    }
#else
    printf("SKIP_MODBUS\n");
#endif

    char fpDataFileName[MAX_FILENAME_LENGTH];
    if (sprintf(fpDataFileName, "%ld_data.csv", time(NULL)) < 0){
        printf("Error generating fpDataFileName.\n");
        return -1;
    }
    fpData = fopen(fpDataFileName, "a");
    if (fpData == NULL){
        printf("fopen() failed to open %s\n", fpDataFileName);
        return -1;
    }
    printf("write column names to CSV\n");
    fprintf(fpData, "time_unix, id, temperature_raw, temperature_celsius, humidity_raw, humidity_percent\n");
    fflush(fpData);
    
#ifndef SKIP_LORA
    printf("Strobing SRX and entering main loop.\n");
    trxSpiCmdStrobe(CC112X_SRX);
#endif

    uint8_t marcState = 0;
    uint8_t lastMarcState = 0;
    
    while(1){
#ifndef SKIP_LORA
        // LoRa
        
        rfStatus_t status;
        uint8_t rxBuffer[MAX_PACKET_LENGTH] = {0};
        uint8_t rxBytes;
        packetStruct_t parsedPacket;

        status = cc112xSpiReadReg(CC112X_MARCSTATE, &marcState, 1);
        
        // A change in marcstate indicates a CC1125 state machine transition
        // Note: What if the marcstate is not polled at the right times?
        // Consider using CC1125-generated interrupts
        if (marcState != lastMarcState){
            if((marcState & MARC_STATE_MASK) == RX_FIFO_ERROR) {
                printf("\tMARCSTATE RX_FIFO_ERROR, flushing\n");
                trxSpiCmdStrobe(CC112X_SFRX);
            }
            
            status = cc112xSpiReadReg(CC112X_NUM_RXBYTES, &rxBytes, 1);
            if (rxBytes != 0){
                printf("rxBytes = %d (0x%02X)\n", rxBytes, status);
                status = cc112xSpiReadRxFifo(rxBuffer, rxBytes);
                printf("FIFO (0x%02X) {hex} : ", status);
                for (int i = 0; i < rxBytes; i++){
                    printf("%02X ", rxBuffer[i]);
                }
                printf("\n");
                
                switch (packetParser(rxBuffer, rxBytes, &parsedPacket)){
                    case RH_T_16_BIT:
                    case RH_T_14_BIT:
                    case RH_T_11_BIT:
                    case RH_T_9_BIT:
                        printf("writing\n");
                        
                        fprintf(fpData, "%ld, %d, %d, %f, %d, %f\n", time(NULL), parsedPacket.deviceID, parsedPacket.temperature_raw, parsedPacket.temperature_scaled, parsedPacket.humidity_raw, parsedPacket.humidity_scaled);
                        fflush(fpData); // immediately write to CSV
                        
                        printf("modifying modbus registers\n");
                        uint32_t mappedAddress = ((uint32_t) parsedPacket.deviceID) << 1;
                        if (mappedAddress <= MAP_SIZE_REGS){
                            // Address is inbounds
                            map->tab_registers[mappedAddress] = parsedPacket.temperature_raw;

                            memcpy(&(map->tab_registers[mappedAddress + 1]), &(parsedPacket.temperature_scaled), sizeof(float));
                            
                            map->tab_registers[mappedAddress + 3] = parsedPacket.humidity_raw;
                            
                            memcpy(&(map->tab_registers[mappedAddress + 4]), &(parsedPacket.humidity_scaled), sizeof(float));
                        }else{
                            // Address is out of bounds
                            printf("error: invalid id\n");
                        }
#ifndef SKIP_MODBUS
                        print_modbus_mapping(map);
#endif
                        break;
                    case UNKNOWN:
                        break;
                    default:
                        break;
                }
            }
            lastMarcState = 0;
            trxSpiCmdStrobe(CC112X_SRX);
        }
#endif
#ifndef SKIP_MODBUS
        // Modbus
        
        int requestLength, responseLength;
        uint8_t req[MODBUS_MAX_ADU_LENGTH];
        int errnoSaved = 0;
        
#ifdef SKIP_LORA
        print_modbus_mapping(map);
#endif
        printf("modbus_receive\n");
        requestLength = modbus_receive(mb, req);
        switch(requestLength){
            case 0:
                printf("Ignore request (other slave address)\n");
                break;
            case -1:
                errnoSaved = errno;
                switch (errnoSaved){
                    case ETIMEDOUT:
                        printf("ETIMEDOUT (%d) %s\n", errnoSaved, modbus_strerror(errnoSaved));
                        break;
                    default:
                        printf("Unknown error, check 'errno %d' (modbus: %s)\n", errnoSaved, modbus_strerror(errnoSaved));
                        break;
                }
                break;
            default:
                printf("Handling request (length %d)\n", requestLength);
                responseLength = modbus_reply(mb, req, requestLength, map);
                if (responseLength == -1){
                    printf("Could not reply\n");
                }else{
                    printf("Sent reply (length %d)\n", responseLength);
                }
                break;
        }
#endif
    }
    
    if (fpData != NULL) fclose(fpData);
    trxRfSpiInterfaceClose();
    if (map != NULL) modbus_mapping_free(map);
    if (mb != NULL){
        modbus_close(mb);
        modbus_free(mb);
    }
    return 0;
}

// returns file descriptor for the SPI interface on success, else -1
// Note: trxRfSpiInterfaceInit may not return -1 due to SPI.c/h exiting on error
static int spi_init(int baudrate)
{
    return trxRfSpiInterfaceInit(SPI_DEVICE, SPI_MODE_0, baudrate);
}

// Returns 0 on success, else -1
static int radio_init(void)
{
    uint16_t registerErrorAddr = registerConfig(preferredSettings, sizeof(preferredSettings)/sizeof(registerSetting_t));
    printf("exited registerConfig, reentered radio_init\n");
    if (registerErrorAddr != 0xFFFF){
        printf("radio_init() failed to write to register 0x%04X\n", registerErrorAddr);
        return -1;
    }
    printf("manualCalibration start\n");
    manualCalibration();
    printf("manualCalibration done\n");

#ifdef LIST_ALL_REGISTERS
    // Read ALL registers from radio
    printf("Reading ALL registers\n");
    printf("addr\tvalue\tstatus\n");
    for(int i = 0; i < (sizeof(allSettings)/sizeof(registerSetting_t)); i++) {
        status = cc112xSpiReadReg(allSettings[i].addr, &readByte, 1);
        printf("0x%04X\t0x%02X\t0x%02X\n", allSettings[i].addr, readByte, status);
    }
    printf("Done reading ALL registers\n\n\n");
#endif
    return (registerErrorAddr == 0xFFFF)?(0):(-1);
}

// returns 0 on success, else -1
static int modbus_init(modbus_t **mb, modbus_mapping_t **map, unsigned int bits, unsigned int ibits, unsigned int regs, unsigned int iregs)
{
    printf("Setting up modbus struct and config.\n");
    printf("given mb = 0x%0X\n", mb);
    printf("given *mb = 0x%0X\n", *mb);    
    
    printf("Instantiating Modbus RTU on %s at %d baud (%d%c%d).\n", RTU_PORT, RTU_BAUD, RTU_DATA_BITS, RTU_PARITY, RTU_STOP_BITS);
    *mb = modbus_new_rtu(RTU_PORT, RTU_BAUD, RTU_PARITY, RTU_DATA_BITS, RTU_STOP_BITS);
    printf("(after) *mb = 0x%02X\n", (uint32_t) *mb);
    
#ifdef MODBUS_DEBUG_ENABLE
    printf("\tMODBUS_DEBUG_ENABLE\n");
    if (modbus_set_debug(*mb, TRUE) != 0){
        printf("Failed to enable debug on mb = 0x%02X with flag %d\n", *mb, TRUE);
        return -1;
    }else{
        printf("Enabled debug.\n");
    }
#endif
    
    printf("Check Modbus RTU settings:\n");
    int serial_mode = modbus_rtu_get_serial_mode(*mb);
    printf("\tSerial mode: %d ", serial_mode);
    switch(serial_mode){
        case MODBUS_RTU_RS232:
            printf("MODBUS_RTU_RS232\n");
            break;
        case MODBUS_RTU_RS485:
            printf("MODBUS_RTU_RS485\n");
            break;
        default:
            printf("Invalid serial mode\n");
            return -1;
            break;
    }
    int rts_mode = modbus_rtu_get_rts(*mb);
    printf("\tRTS mode: %d ", rts_mode);
    switch(rts_mode){
        case MODBUS_RTU_RTS_NONE:
            printf("MODBUS_RTU_RTS_NONE\n");
            break;
        case MODBUS_RTU_RTS_UP:
            printf("MODBUS_RTU_RTS_UP\n");
            break;
        case MODBUS_RTU_RTS_DOWN:
            printf("MODBUS_RTU_RTS_DOWN\n");
            break;
        default:
            printf("Invalid rts mode\n");
            return -1;
            break;
    }
    int rts_delay = modbus_rtu_get_rts_delay(*mb);
    printf("\tRTS delay: %d us\n", rts_delay);
    if (rts_delay == -1){
        printf("Invalid rts delay\n");
        return -1;
    }
    
    printf("*mb = 0x%02X\n", (uint32_t) *mb);
    printf("set_slave (slave:address; master:destination) address 0x%02X (%d)\n", MODBUS_SLAVE_ID, MODBUS_SLAVE_ID);
    if (modbus_set_slave(*mb, MODBUS_SLAVE_ID) < 0)
    {
        printf("modbus_set_slave failed to set the slave number.\n");
        return -1;
    }
    
    printf("get_slave = 0x%02X\n", modbus_get_slave(*mb));
    
    printf("Opening connection.\n");
    if (modbus_connect(*mb) != 0){
        printf("modbus_connect(*mb=0x%02X) failed to connect.\n", (uint32_t) *mb);
        return -1;
    }
    
    printf("get_socket == %d, flushed %d bytes\n", modbus_get_socket(*mb), modbus_flush(*mb));
    
#ifdef MODBUS_NONBLOCKING
    // Timeout info
    uint32_t sec;
    uint32_t usec;
    int timeoutStatus;
    printf("timeouts\n");
    timeoutStatus = modbus_get_indication_timeout(*mb, &sec, &usec);
    printf("\tget indication (%d) = %d s %d us\n", timeoutStatus, sec, usec);
    
    sec = MODBUS_RECEIVE_TIMEOUT_SEC;
    usec = MODBUS_RECEIVE_TIMEOUT_USEC;
    
    timeoutStatus = modbus_set_indication_timeout(*mb, sec, usec);
    printf("\tset indication (%d) = %d s %d us\n", timeoutStatus, sec, usec);
    timeoutStatus = modbus_get_indication_timeout(*mb, &sec, &usec);
    printf("\tget indication (%d) = %d s %d us\n", timeoutStatus, sec, usec);
#endif
    
    printf("Mapping\n");
    printf("given map = 0x%0X\n", map);
    printf("given *map = 0x%0X\n", *map);
    // map = modbus_mapping_new_start_address();
    *map = modbus_mapping_new(bits, ibits, regs, iregs);
    printf("after *map = 0x%0X\n", *map);
    /* 
        map->tab_bits[0]
        map->tab_input_bits[0]
        map->tab_input_registers[0]
        map->tab_registers[0]
    */
    
    if (*map == NULL){
        printf("modbus_mapping_new failed to allocate.\n");
        return -1;
    }
    
    printf("*map located at 0x%X\n", (uint32_t) *map);
    print_modbus_mapping(*map);
    
    return 0;
}

/*******************************************************************************
*   @fn         registerConfig
*
*   @brief      Write register settings as given by SmartRF Studio found in
*               cc112x_easy_link_reg_config.h
*
*   @param      none
*
*   @return     uint16_t errorFlag -- 0xFFFF on success
*                                     else first written register with error
*/
static uint16_t registerConfig(const registerSetting_t *reg, int numRegisters) {

    uint8_t writeByte;
    uint8_t readByte;
    rfStatus_t status;
    
    uint16_t errorFlag = 0xFFFF;

    // Reset radio
    printf("Resetting radio\n");
    status = trxSpiCmdStrobe(CC112X_SRES);
    printf("Status byte: 0x%02X\n", status);
    
    // Wait for reset
    sleep(1);

    // Read registers from radio
    printf("Reading registers that will be written to\n");
    printf("#\taddr\texpect\tvalue\tcompare\n");
    for(uint16_t i = 0; i < numRegisters; i++) {
        printf("%d\t0x%02X\t0x%02X", i, reg[i].addr, reg[i].data);
        status = cc112xSpiReadReg(reg[i].addr, &readByte, 1);
        if (readByte == reg[i].data){
            printf(" == 0x%02X\tOK\n", readByte);
        }else{
            printf(" != 0x%02X\tUNEXPECTED REGISTER VALUE\n", readByte);
        }
    }

    // Write registers to radio
    printf("Writing registers based on reg\n");
    printf("#\taddr\t    write\n");
    for(uint16_t i = 0; i < numRegisters; i++) {
        printf("%d\t", i);
        writeByte = reg[i].data;
        printf("0x%02X\t<-- 0x%02X\n", reg[i].addr, writeByte);
        status = cc112xSpiWriteReg(reg[i].addr, &writeByte, 1);
    }
    
    // Read registers from radio
    printf("Reading registers that were written to\n");
    printf("#\taddr\texpect\tvalue\tcompare\n");
    for(uint16_t i = 0; i < numRegisters; i++) {
        printf("%d\t0x%02X\t0x%02X", i, reg[i].addr, reg[i].data);
        status = cc112xSpiReadReg(reg[i].addr, &readByte, 1);
        if (readByte == reg[i].data){
            printf(" == 0x%02X\tOK\n", readByte);
        }else{
            printf(" != 0x%02X\tUNEXPECTED REGISTER VALUE\n", readByte);
            if (errorFlag == 0xFFFF) errorFlag = reg[i].addr;
        }
    }
    
    printf("Done configuring registers.\n");
    return errorFlag;
}

/*******************************************************************************
*   @fn         manualCalibration
*
*   @brief      Calibrates radio according to CC112x errata
*
*   @param      none
*
*   @return     none
*/
#define VCDAC_START_OFFSET 2
#define FS_VCO2_INDEX 0
#define FS_VCO4_INDEX 1
#define FS_CHP_INDEX 2
static void manualCalibration(void) {

    uint8_t original_fs_cal2;
    uint8_t calResults_for_vcdac_start_high[3];
    uint8_t calResults_for_vcdac_start_mid[3];
    uint8_t marcstate;
    uint8_t writeByte;

    // 1) Set VCO cap-array to 0 (FS_VCO2 = 0x00)
    writeByte = 0x00;
    cc112xSpiWriteReg(CC112X_FS_VCO2, &writeByte, 1);

    // 2) Start with high VCDAC (original VCDAC_START + 2):
    cc112xSpiReadReg(CC112X_FS_CAL2, &original_fs_cal2, 1);
    writeByte = original_fs_cal2 + VCDAC_START_OFFSET;
    cc112xSpiWriteReg(CC112X_FS_CAL2, &writeByte, 1);

    // 3) Calibrate and wait for calibration to be done
    //   (radio back in IDLE state)
    trxSpiCmdStrobe(CC112X_SCAL);

    do {
        cc112xSpiReadReg(CC112X_MARCSTATE, &marcstate, 1);
    } while (marcstate != 0x41);

    // 4) Read FS_VCO2, FS_VCO4 and FS_CHP register obtained with 
    //    high VCDAC_START value
    cc112xSpiReadReg(CC112X_FS_VCO2,
                     &calResults_for_vcdac_start_high[FS_VCO2_INDEX], 1);
    cc112xSpiReadReg(CC112X_FS_VCO4,
                     &calResults_for_vcdac_start_high[FS_VCO4_INDEX], 1);
    cc112xSpiReadReg(CC112X_FS_CHP,
                     &calResults_for_vcdac_start_high[FS_CHP_INDEX], 1);

    // 5) Set VCO cap-array to 0 (FS_VCO2 = 0x00)
    writeByte = 0x00;
    cc112xSpiWriteReg(CC112X_FS_VCO2, &writeByte, 1);

    // 6) Continue with mid VCDAC (original VCDAC_START):
    writeByte = original_fs_cal2;
    cc112xSpiWriteReg(CC112X_FS_CAL2, &writeByte, 1);

    // 7) Calibrate and wait for calibration to be done
    //   (radio back in IDLE state)
    trxSpiCmdStrobe(CC112X_SCAL);

    do {
        cc112xSpiReadReg(CC112X_MARCSTATE, &marcstate, 1);
    } while (marcstate != 0x41);

    // 8) Read FS_VCO2, FS_VCO4 and FS_CHP register obtained 
    //    with mid VCDAC_START value
    cc112xSpiReadReg(CC112X_FS_VCO2, 
                     &calResults_for_vcdac_start_mid[FS_VCO2_INDEX], 1);
    cc112xSpiReadReg(CC112X_FS_VCO4,
                     &calResults_for_vcdac_start_mid[FS_VCO4_INDEX], 1);
    cc112xSpiReadReg(CC112X_FS_CHP,
                     &calResults_for_vcdac_start_mid[FS_CHP_INDEX], 1);

    // 9) Write back highest FS_VCO2 and corresponding FS_VCO
    //    and FS_CHP result
    if (calResults_for_vcdac_start_high[FS_VCO2_INDEX] >
        calResults_for_vcdac_start_mid[FS_VCO2_INDEX]) {
        writeByte = calResults_for_vcdac_start_high[FS_VCO2_INDEX];
        cc112xSpiWriteReg(CC112X_FS_VCO2, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_high[FS_VCO4_INDEX];
        cc112xSpiWriteReg(CC112X_FS_VCO4, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_high[FS_CHP_INDEX];
        cc112xSpiWriteReg(CC112X_FS_CHP, &writeByte, 1);
    } else {
        writeByte = calResults_for_vcdac_start_mid[FS_VCO2_INDEX];
        cc112xSpiWriteReg(CC112X_FS_VCO2, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_mid[FS_VCO4_INDEX];
        cc112xSpiWriteReg(CC112X_FS_VCO4, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_mid[FS_CHP_INDEX];
        cc112xSpiWriteReg(CC112X_FS_CHP, &writeByte, 1);
    }
}

// returnPacket will be populated based on the packet type.
// packetType describes which fields in returnPacket are relevant.
static packetType_t packetParser(uint8_t *packet, uint8_t length, packetStruct_t *returnPacket)
{
    // New 6 byte packet structure
    // 2 byte id
    // 2 byte temp
    // 2 byte humidity
    // depending on radio settings
    //      crc16 may be appended by the sender (and auto-removed by receiver)
    //      rssi may be appended by the receiver
    
    // INCLUDES
    if (length == 6 + PACKET_STATUS_BYTES){ // Identify packet type based on length
        returnPacket->type = RH_T_16_BIT;
        
        uint16_t id             = (packet[0] << 8) | (packet[1]);
        uint16_t temperature    = (packet[2] << 8) | (packet[3]);
        uint16_t humidity       = (packet[4] << 8) | (packet[5]);
        uint8_t rssi            = packet[6];
        uint8_t crc_ok          = (packet[7] & 0x80) >> 7; // 1 when ok (no error), 0 when not ok (error)
        uint8_t link_quality    = packet[7] & 0x7F; // Low is good
        
        printf("%04X %04X %04X (%d %d %d)\n", id, temperature, humidity, rssi, crc_ok, link_quality);
        printf("\tID: 0x%04X\n\trawtemp: 0x%04X\n\trawhum: 0x%04X\n\trssi: %d\n\tcrcOK: %d\n\tlinkQuality: %d\n", id, temperature, humidity, rssi, crc_ok, link_quality);
        
        returnPacket->deviceID = id;
        returnPacket->temperature_raw = temperature;
        returnPacket->temperature_scaled = (((float)temperature * 165.0f) / 65536.0f) - 40.0f;
        returnPacket->humidity_raw = humidity;
        returnPacket->humidity_scaled = ((float)humidity / 65536.0f) * 100.0f;
        
        printf("temp calcs %X %d %f\n", temperature, temperature, (float)temperature);
        returnPacket->temperature_scaled = temperature;
        printf("\t%f\n", returnPacket->temperature_scaled);
        returnPacket->temperature_scaled *= 165.0f;
        printf("\t%f\n", returnPacket->temperature_scaled);
        returnPacket->temperature_scaled /= 65536.0f;
        printf("\t%f\n", returnPacket->temperature_scaled);
        returnPacket->temperature_scaled -= 40.0f;
        printf("\t%f\n", returnPacket->temperature_scaled);
        
        printf("humidity calcs %X %d %f\n", humidity, humidity, (float)humidity);
        returnPacket->humidity_scaled = humidity;
        printf("\t%f\n", returnPacket->humidity_scaled);
        returnPacket->humidity_scaled /= 65536.0f;
        printf("\t%f\n", returnPacket->humidity_scaled);
        returnPacket->humidity_scaled *= 100.0f;
        printf("\t%f\n", returnPacket->humidity_scaled);
    }else{
        printf("Unrecognized packet format\n");
        returnPacket->type = UNKNOWN;
    }
    return returnPacket->type;
}

static void print_modbus_mapping(modbus_mapping_t *map)
{
    printf("time %ld\n", time(NULL));
#ifdef MAP_PRINT_REGS_ONLY
    
    // column headers (MSB)
    printf("LO\\HI\t");
    for (int i = 0; i <= ((MAP_SIZE_REGS - 1) >> 4); i++){
        printf("%01X_\t", i);
    }
    printf("\n");
    for (int i = 0; i <= ((MAP_SIZE_REGS - 1) >> 4) + 1; i++){
        printf("--------");
    }
    printf("\n");
    
    
    for (int i = 0; i <= 0xF; i++){
        printf("_%01X |\t", i); // row header
        for (int j = i; j < MAP_SIZE_REGS; j += 0x10){
            printf("%04X\t", map->tab_registers[j]);
        }
        printf("\n");
    }
#else
    printf("addr\tbit\tibit\treg\tireg\n");
    printf("------------------------------------\n");
    for (int i = 0; (i < MAP_SIZE_BITS) || (i < MAP_SIZE_IBITS) || (i < MAP_SIZE_REGS) || (i < MAP_SIZE_IREGS); i++){
        printf("%04X ||\t", i);
        if (i < MAP_SIZE_BITS){
            printf("%04X\t", map->tab_bits[i]);
        }else{
            printf("\t");
        }
        if (i < MAP_SIZE_IBITS){
            printf("%04X\t", map->tab_input_bits[i]);
        }else{
            printf("\t");
        }
        if (i < MAP_SIZE_REGS){
            printf("%04X\t", map->tab_registers[i]);
        }else{
            printf("\t");
        }
        if (i < MAP_SIZE_IREGS){
            printf("%04X\t", map->tab_input_registers[i]);
        }else{
            printf("\t");
        }
        printf("\n");
    }
#endif
}
