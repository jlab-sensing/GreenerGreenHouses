#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <signal.h>
#include <linux/spi/spidev.h>
// #include <linux/types.h>
// #include <sys/ioctl.h>
// #include <fcntl.h>
#include <modbus/modbus.h>
#include "cc112x_spi.h"
#include "cc112x_easy_link_reg_config.h"

// #define LIST_ALL_REGISTERS
// #define PACKET_PARSER
#define SKIP_LORA

#define RX_BUFFER_SIZE 16

#define SPI_DEV_BUS0_CS0 "/dev/spidev0.0"

#define RX_FIFO_ERROR 0x11

#define MODBUS_SLAVE_ID 0xAB

#define MAP_SIZE_BITS 4
#define MAP_SIZE_IBITS 8
#define MAP_SIZE_IREGS 16
#define MAP_SIZE_REGS 16

#define RTU_PORT        "/dev/ttyUSB0"
#define RTU_BAUD        19200
#define RTU_PARITY      'N'
#define RTU_DATA_BITS   8
#define RTU_STOP_BITS   1

// Global
static FILE* fp = NULL;
static modbus_t *mb = NULL;
static modbus_mapping_t *map;

static void manualCalibration(void);
static void registerConfig(const registerSetting_t *reg, int numRegisters);
static void packetParser(uint8 *packet, uint8 length);
void intHandler(int sig);
modbus_t * modbus_setup(const char *device, int baud, char parity, int data_bit, int stop_bit);
void print_modbus_mapping(void);

int spi_init(void);
int radio_init(void);
int modbus_init(unsigned int bits, unsigned int ibits, unsigned int iregs, unsigned int regs);

int spi_init(void)
{
    printf("Opening %s in O_RDWR (r+).\n", SPI_DEV_BUS0_CS0);
    trxRfSpiInterfaceInit(SPI_DEV_BUS0_CS0, SPI_MODE_0, 1000000);

    // if (SPI_readSettings(spiFileDesc) < 0){
        // printf("Error: Could not read SPI mode settings.\n");
        // exit(1);
    // }
    return 0;
}

int radio_init(void)
{
    registerConfig(preferredSettings, sizeof(preferredSettings)/sizeof(registerSetting_t));
    manualCalibration();
    
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
    return 0;
}

int modbus_init(unsigned int bits, unsigned int ibits, unsigned int iregs, unsigned int regs)
{
    printf("Setting up modbus struct and config.\n");
    mb = modbus_setup(RTU_PORT, RTU_BAUD, RTU_PARITY, RTU_DATA_BITS, RTU_STOP_BITS);
    printf("mb = 0x%02X\n", (unsigned int) mb);
    printf("set_slave (slave:address; master:destination) address 0x%02X (%d) ", MODBUS_SLAVE_ID, MODBUS_SLAVE_ID);
    if (modbus_set_slave(mb, MODBUS_SLAVE_ID) < 0)
    {
        printf("modbus_set_slave failed to set the slave number.\n");
    }
    
    printf("Opening connection.\n");
    if (modbus_connect(mb) != 0){
        printf("modbus_connect(mb=0x%02X) failed to connect.\n", (unsigned int) mb);
        return -1;
    }
    
    printf("get_socket == %d, flushed %d bytes\n", modbus_get_socket(mb), modbus_flush(mb));
    
    printf("Mapping\n");
    // map = modbus_mapping_new_start_address();
    map = modbus_mapping_new(bits, ibits, iregs, regs);
    /* 
        map->tab_bits[0]
        map->tab_input_bits[0]
        map->tab_input_registers[0]
        map->tab_registers[0]
    */
    
    if (map == NULL){
        printf("modbus_mapping_new failed to allocate.\n");
        return -1;
    }else{
        printf("map located at 0x%X\n", (unsigned int) map);
        printf("sizeof(map) = %d\n", sizeof(map));
    }
    return 0;
}

int main(int argc, char *argv[]){
    rfStatus_t status = 0;
    uint8 rxBuffer[RX_BUFFER_SIZE] = {0};
    uint8_t rxBytes;
    uint8 marcState;
    uint8 lastMarcState;
    int req_length;
    uint8_t req[MODBUS_MAX_ADU_LENGTH];
    
    printf("Program start.\n");
    
    signal(SIGINT, intHandler);
    
    spi_init();
#ifndef SKIP_LORA
    radio_init();
#endif
    modbus_init(MAP_SIZE_BITS, MAP_SIZE_IBITS, MAP_SIZE_IREGS, MAP_SIZE_REGS);

    fp = fopen("data", "w");
    if (fp == NULL){
        printf("null\n");
    }
    
    printf("Strobing SRX and entering main loop.\n");
    trxSpiCmdStrobe(CC112X_SRX);
    
    while(1){
        // LoRa
#ifndef SKIP_LORA
        status = cc112xSpiReadReg(CC112X_MARCSTATE, &marcState, 1);
        if (marcState == lastMarcState){
            continue;
        }
        
        if((marcState & 0x1F) == RX_FIFO_ERROR) {
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
            
            printf("writing\n");
            fwrite(rxBuffer, rxBytes, sizeof(rxBuffer[0]), fp);
        }
        lastMarcState = marcState;
        trxSpiCmdStrobe(CC112X_SRX);
#endif
        // Modbus
        
        print_modbus_mapping();
        printf("waiting on modbus_receive\n");
        req_length = modbus_receive(mb, req);
        switch(req_length){
            case 0:
                printf("Ignore request (other slave address)\n");
                break;
            case -1:
                printf("Error receiving\n");
                break;
            default:
                printf("Handling request (length %d)\n", req_length);
                sleep(1);
                status = modbus_reply(mb, req, req_length, map);
                if (status == -1){
                    printf("Could not reply\n");
                }else{
                    printf("Sent reply (length %d)\n", status);
                }
                break;
        }
    }
        
    printf("Closing %s.\n", SPI_DEV_BUS0_CS0);
    trxRfSpiInterfaceClose();
    printf("Closing data.\n");
    fclose(fp);
    return 0;
}

void intHandler(int sig) {
    if (fp != NULL) fclose(fp);
    trxRfSpiInterfaceClose();
    
    modbus_mapping_free(map);
    
    modbus_close(mb);
    printf("Flushing non-transmitted data.\n");
    int bytes_flushed;
    bytes_flushed = modbus_flush(mb);
    printf("Flushed %d bytes.\n", bytes_flushed);
    
    printf("Freeing mb = 0x%02X\n", (unsigned int) mb);
    modbus_free(mb);
    
    printf("Program end.\n");
    exit(0);
}

/*******************************************************************************
*   @fn         registerConfig
*
*   @brief      Write register settings as given by SmartRF Studio found in
*               cc112x_easy_link_reg_config.h
*
*   @param      none
*
*   @return     none
*/
static void registerConfig(const registerSetting_t *reg, int numRegisters) {

    uint8 writeByte;
    uint8 readByte;
    rfStatus_t status;
    
    printf("sizeof(reg) = %d\n", sizeof(reg));
    printf("sizeof(&reg) = %d\n", sizeof(&reg));
    
    printf("Registers to write\n");
    printf("#\taddr\tvalue\n");
    for(uint16 i = 0; i < numRegisters; i++) {
        printf("%d\t0x%02X\t0x%02X\n", i, reg[i].addr, reg[i].data);
    }
    printf("Done listing registers to write\n");

    // Reset radio
    printf("Resetting radio\n");
    status = trxSpiCmdStrobe(CC112X_SRES);
    printf("Status byte: 0x%02X\n", status);
    
    // Wait for reset
    sleep(1);
    
    // Read registers from radio
    printf("Reading registers that will be written to\n");
    printf("#\taddr\texpect\tvalue\tcompare\n");
    for(uint16 i = 0; i < numRegisters; i++) {
        printf("%d\t0x%02X\t0x%02X", i, reg[i].addr, reg[i].data);
        status = cc112xSpiReadReg(reg[i].addr, &readByte, 1);
        
        if (readByte == reg[i].data){
            printf(" == 0x%02X\t", readByte);
            printf("OK\n");
        }else{
            printf(" != 0x%02X\t", readByte);
            printf("UNEXPECTED REGISTER VALUE\n");
        }
    }

    // Write registers to radio
    printf("Writing registers based on reg\n");
    printf("#\taddr\t    write\n");
    for(uint16 i = 0; i < numRegisters; i++) {
        printf("%d\t", i);
        writeByte = reg[i].data;
        printf("0x%02X\t<-- 0x%02X\n", reg[i].addr, writeByte);
        status = cc112xSpiWriteReg(reg[i].addr, &writeByte, 1);
        // printf("status = 0x%02X\n", status);
    }
    
    // Read registers from radio
    printf("Reading registers that were written to\n");
    printf("#\taddr\texpect\tvalue\tcompare\n");
    for(uint16 i = 0; i < numRegisters; i++) {
        printf("%d\t0x%02X\t0x%02X", i, reg[i].addr, reg[i].data);
        status = cc112xSpiReadReg(reg[i].addr, &readByte, 1);
        
        if (readByte == reg[i].data){
            printf(" == 0x%02X\t", readByte);
            printf("OK\n");
        }else{
            printf(" != 0x%02X\t", readByte);
            printf("UNEXPECTED REGISTER VALUE\n");
        }
    }
    
    printf("Done configuring registers.\n");
    return;
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

    uint8 original_fs_cal2;
    uint8 calResults_for_vcdac_start_high[3];
    uint8 calResults_for_vcdac_start_mid[3];
    uint8 marcstate;
    uint8 writeByte;

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

static void packetParser(uint8 *packet, uint8 length)
{
    /*  Packet Structure for temp/humidity
        | Device ID (4 bits) | Temperature (14 bits) | Humidity (14 bits) | CRC16 (16 bits) |
        
        0b0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
          [ID] [  Temperature  ][    Humidity   ] [      CRC16      ]
        
        ID (store as uint8_t)
        xxxx ABCD
        0: upp 4    ABCD xxxx
        
        Temperature (store as uint16_t)
        xxAB CDEF GHIJ KLMN
        0: low 4    xxxx ABCD
        1: all 8    EFGH IJKL
        2: upp 2    MNxx xxxx
        
        Humidity (store as uint16_t)
        xxAB CDEF GHIJ KLMN
        2: low 6    xxAB CDEF
        3: all 8    GHIJ KLMN
        
        CRC16 (store as uint16_t)
        ABCD EFGH IJKL MNOP
        4: all 8    ABCD EFGH
        5: all 8    IJKL MNOP
    */
    
    // To do: Return struct which breaks out the received raw packet into its constituent segments
    // Consider: What about multi-packet messages? Out of scope?
    
    if (length == 6){
        uint8   id = (packet[0] & 0xF0) >> 4;
        uint16  temperature =   ((packet[0] & 0x0F) << 10) | \
                                ((packet[1] & 0xFF) << 2) | \
                                ((packet[2] & 0xC0) >> 6);
        uint16  humidity =  ((packet[2] & 0x3F) << 8) | \
                            ((packet[3] & 0xFF));
        uint16  crc = (packet[4] << 8) | (packet[5]);
        
        printf("\tID:\t0x%01X (%d)\n", id, id);
        printf("\tTemp:\t0x%04X (%d)\n", temperature, temperature);
        printf("\tHumi:\t0x%04X (%d)\n", humidity, humidity);
        printf("\tCRC16:\t0x%04X\n", crc);
    }else{
        printf("Unrecognized packet format\n");
    }
}

modbus_t * modbus_setup(const char *device, int baud, char parity, int data_bit, int stop_bit)
{
    modbus_t *mb;
    // printf("\t(before) mb = 0x%02X\n", mb);
    printf("\tInstantiating Modbus RTU on %s at %d baud (%d%c%d).\n", device, baud, data_bit, parity, stop_bit);
    mb = modbus_new_rtu(device, baud, parity, data_bit, stop_bit);
    printf("\t(after) mb = 0x%02X\n", (unsigned int) mb);
    
#ifdef MODBUS_DEBUG_ENABLE
    printf("\tMODBUS_DEBUG_ENABLE\n");
    if (modbus_set_debug(mb, TRUE) != 0){
        printf("Failed to enable debug on mb = 0x%02X with flag %d\n", mb, TRUE);
        // return 0;
    }
    // printf("Enabled debug.\n");
#endif
    
    printf("\tCheck Modbus RTU settings:\n");
    int serial_mode = modbus_rtu_get_serial_mode(mb);
    printf("\t\tSerial mode: %d ", serial_mode);
    switch(serial_mode){
        case MODBUS_RTU_RS232:
            printf("MODBUS_RTU_RS232\n");
            break;
        case MODBUS_RTU_RS485:
            printf("MODBUS_RTU_RS485\n");
            break;
        default:
            printf("ERROR\n");
            break;
    }
    int rts_mode = modbus_rtu_get_rts(mb);
    printf("\t\tRTS mode: %d ", rts_mode);
    switch(serial_mode){
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
            printf("ERROR\n");
            break;
    }
    int rts_delay = modbus_rtu_get_rts_delay(mb);
    printf("\t\tRTS delay: %d us\n", rts_delay);
    if (rts_delay == -1) printf("ERROR\n");
    
    return mb;
}

void print_modbus_mapping(void)
{
    // printf("Dumping data (hex):\n");
    // printf("info: %d, reg %d, reg0 %d\n", sizeof(mbmap), sizeof(mbmap->tab_registers), sizeof(mbmap->tab_registers[0]));
    printf("addr\tbit\tibit\tireg\treg\n");
    printf("------------------------------------\n");
    for (int i = 0; (i < MAP_SIZE_BITS) || (i < MAP_SIZE_IBITS) || (i < MAP_SIZE_IREGS) || (i < MAP_SIZE_REGS); i++){
        printf("%04X|\t", i);
        if (i < MAP_SIZE_BITS){
            printf("%04X\t", map->tab_bits[i]);
        }else{
            printf("\t");
        }
        usleep(1000);
        if (i < MAP_SIZE_IBITS){
            printf("%04X\t", map->tab_input_bits[i]);
        }else{
            printf("\t");
        }
        usleep(1000);
        if (i < MAP_SIZE_IREGS){
            // printf("ireg %d\n", i);
            printf("%04X\t", map->tab_input_registers[i]);
        }else{
            printf("\t");
        }
        usleep(1000);
        if (i < MAP_SIZE_REGS){
            printf("%04X\n", map->tab_registers[i]);
        }else{
            printf("\t\n");
        }
        usleep(1000);
    }
}