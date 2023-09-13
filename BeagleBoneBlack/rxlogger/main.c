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
#include <time.h>
#include <errno.h>

// #define LIST_ALL_REGISTERS
// #define TEST_PACKET_PARSER
#define PARSE_PACKET_CAST_32
#define SKIP_LORA
// #define SKIP_MODBUS
#define PACKET_INCLUDES_RSSI 2 // Set to 0 if no RSSI bytes
#define MODBUS_NONBLOCKING
#ifdef MODBUS_NONBLOCKING
#include <sys/socket.h>
#endif

#define MAX_PACKET_LENGTH 16
#define MAX_FILENAME_LENGTH 50

#define SPI_DEV_BUS0_CS0 "/dev/spidev0.0"

#define MARCSTATE_NOT_USED_MASK 0x80
#define MARC_2PIN_STATE_MASK 0x60
#define MARC_STATE_MASK 0x1F
#define RX_FIFO_ERROR 0x11

#define MODBUS_SLAVE_ID 0xAB

#define MAP_SIZE_BITS 0
#define MAP_SIZE_IBITS 0
#define MAP_SIZE_REGS 1
#define MAP_SIZE_IREGS 1

#define RTU_PORT        "/dev/ttyUSB0"
#define RTU_BAUD        19200
#define RTU_PARITY      'N'
#define RTU_DATA_BITS   8
#define RTU_STOP_BITS   1

typedef enum {
    RH_T_14_BIT,
    RH_T_11_BIT,
    RH_T_9_BIT,
    UNKNOWN
} packetType_t;

/* Struct that holds the fields that a packet may have.
   Depending on the packet type, only certain fields may be relevant.
*/
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

// Global
static FILE* fpData = NULL;
static modbus_t *mb = NULL;
static modbus_mapping_t *map = NULL;

static void manualCalibration(void);
static void registerConfig(const registerSetting_t *reg, int numRegisters);
static packetType_t packetParser(uint8 *packet, uint8 length, packetStruct_t *returnPacket);
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
    printf("mb = 0x%02X\n", (uint32_t) mb);
    printf("set_slave (slave:address; master:destination) address 0x%02X (%d) ", MODBUS_SLAVE_ID, MODBUS_SLAVE_ID);
    if (modbus_set_slave(mb, MODBUS_SLAVE_ID) < 0)
    {
        printf("modbus_set_slave failed to set the slave number.\n");
    }
    
    printf("Opening connection.\n");
    if (modbus_connect(mb) != 0){
        printf("modbus_connect(mb=0x%02X) failed to connect.\n", (uint32_t) mb);
        return -1;
    }
    
    printf("get_socket == %d, flushed %d bytes\n", modbus_get_socket(mb), modbus_flush(mb));
    
#ifdef MODBUS_NONBLOCKING
    // Timeout info
    uint32_t sec;
    uint32_t usec;
    int timeoutStatus;
    printf("timeouts\n");
    timeoutStatus = modbus_get_response_timeout(mb, &sec, &usec);
    printf("\tresponse (%d) = %d s %d us\n", timeoutStatus, sec, usec);
    timeoutStatus = modbus_set_indication_timeout(mb, sec, usec);
    printf("\tindication (%d) = %d s %d us\n", timeoutStatus, sec, usec);
    timeoutStatus = modbus_get_byte_timeout(mb, &sec, &usec);
    printf("\tbyte (%d) = %d s %d us\n", timeoutStatus, sec, usec);
    // Set socket as nonblocking
    // getsockopt();
#endif
    
    printf("Mapping\n");
    // map = modbus_mapping_new_start_address();
    map = modbus_mapping_new(bits, ibits, regs, iregs);
    print_modbus_mapping();
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
        printf("map located at 0x%X\n", (uint32_t) map);
        printf("sizeof(map) = %d\n", sizeof(map));
    }
    return 0;
}

int main(int argc, char *argv[]){
#ifdef TEST_PACKET_PARSER
    printf("%ld\n", time(NULL));
    return 0;

    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }
    if (argc < 2){
        printf("TEST_PACKET_PARSER usage: <program> <1 byte hex> <1 byte hex> {max 16 bytes}\nExample: ./out 30 E5 6F 1A");
        return -1;
    }
    
    // All arguments (after the name of the program) are interpreted as the data packet
    uint8 testBuffer[MAX_PACKET_LENGTH] = {0};
    for (int i = 1; i < argc; i++){
        testBuffer[i - 1] = strtoul(argv[i], NULL, 16);
        printf("testBuffer[%d] = 0x%02X\n", i - 1, testBuffer[i - 1]);
    }
    
    packetStruct_t parsedPacket;
    printf("Calling packetParser\n");
    switch (packetParser(testBuffer, argc - 1, &parsedPacket)){
        case RH_T_14_BIT:
        case RH_T_11_BIT:
        case RH_T_9_BIT:
            printf("%d: temp 0x%X %f, hum 0x%X %f\n", parsedPacket.deviceID, parsedPacket.temperature_raw, parsedPacket.temperature_scaled, parsedPacket.humidity_raw, parsedPacket.humidity_scaled);
            break;
        case UNKNOWN:
            break;
        default:
            break;
    }
    return 0;
#endif
    printf("Program start.\n");
    
    signal(SIGINT, intHandler);
    
    spi_init();
    
#ifndef SKIP_LORA
    radio_init();
#endif

#ifndef SKIP_MODBUS
    modbus_init(MAP_SIZE_BITS, MAP_SIZE_IBITS, MAP_SIZE_REGS, MAP_SIZE_IREGS);
#endif

    char fpDataFileName[MAX_FILENAME_LENGTH];
    if (sprintf(fpDataFileName, "%ld_data.csv", time(NULL)) < 0){
        printf("Error generating fpDataFileName.\n");
        return -1;
    }
    fpData = fopen(fpDataFileName, "a");
    if (fpData == NULL){
        printf("fopen() failed to open %s\n", fpDataFileName);
    }
    printf("write column names to CSV\n");
    fprintf(fpData, "time_unix, id, temperature_raw, temperature_celsius, humidity_raw, humidity_percent\n");
    
#ifndef SKIP_LORA
    printf("Strobing SRX and entering main loop.\n");
    trxSpiCmdStrobe(CC112X_SRX);
#endif

    uint8 marcState = 0;
    uint8 lastMarcState = 0;
    
    while(1){
#ifndef SKIP_LORA
        // LoRa
        
        rfStatus_t status;
        uint8 rxBuffer[MAX_PACKET_LENGTH] = {0};
        uint8_t rxBytes;
        packetStruct_t parsedPacket;

        printf("marcstate\n");
        status = cc112xSpiReadReg(CC112X_MARCSTATE, &marcState, 1);
        if (marcState != lastMarcState){
            // printf("\tPACKET INCOMING\n");
            // return 0;
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
                
                switch (packetParser(rxBuffer, rxBytes - PACKET_INCLUDES_RSSI, &parsedPacket)){
                    case RH_T_14_BIT:
                    case RH_T_11_BIT:
                    case RH_T_9_BIT:
                        printf("writing\n");
                        
                        fprintf(fpData, "%ld, %d, %d, %f, %d, %f\n", time(NULL), parsedPacket.deviceID, parsedPacket.temperature_raw, parsedPacket.temperature_scaled, parsedPacket.humidity_raw, parsedPacket.humidity_scaled);
                        
                        printf("modifying modbus registers\n");
                        uint32_t mappedAddress = ((uint32_t) parsedPacket.deviceID) << 1;
                        map->tab_registers[mappedAddress] = parsedPacket.temperature_raw;
                        map->tab_registers[mappedAddress + 1] = parsedPacket.humidity_raw;
                        
                        // fwrite(rxBuffer, rxBytes, sizeof(rxBuffer[0]), fpData);
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
        
        print_modbus_mapping();
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
                        printf("ETIMEDOUT (%d)\n", errnoSaved);
                        break;
                    default:
                        printf("Unknown error, check 'errno %d'\n", errnoSaved);
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
        
    printf("Closing %s.\n", SPI_DEV_BUS0_CS0);
    trxRfSpiInterfaceClose();
    printf("Closing data.\n");
    fclose(fpData);
    return 0;
}

/*******************************************************************************
*   @fn         intHandler
*
*   @brief      Interrupt handler for catching SIGINT (CTRL + C).
*
*   @param      int sig
*
*   @return     none
*/
void intHandler(int sig) {
    if (fpData != NULL) fclose(fpData);
    trxRfSpiInterfaceClose();
    
    if (map != NULL) modbus_mapping_free(map);
    if (mb != NULL){
        modbus_close(mb);
        printf("Flushed %d bytes.\n", modbus_flush(mb));
        printf("Freeing mb = 0x%02X\n", (uint32_t) mb);
        modbus_free(mb);
    }
    
    
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

// Do not include RSSI (2 bytes)
// returnPacket will be populated based on the packet type
// packetType describes which fields in returnPacket are relevant
static packetType_t packetParser(uint8 *packet, uint8 length, packetStruct_t *returnPacket)
{
    /*  Packet Structure for temp/humidity
        | Device ID (4 bits) | Temperature (14 bits) | Humidity (14 bits) | CRC16 (16 bits) |
        
          [   0   ] [   1   ] [   2   ] [   3   ] [   4   ] [   5   ]
        0b0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
          [ID] [  Temperature  ][    Humidity   ] [      RSSI?      ]
        
        ID (store as uint8_t)
        xxxx ABCD
        0: upp 4    ABCD xxxx
        
        Temperature (store as uint16_t)
        ABCD EFGH IJKL MNxx
        0: low 4    xxxx ABCD
        1: all 8    EFGH IJKL
        2: upp 2    MNxx xxxx
        
        Humidity (store as uint16_t)
        ABCD EFGH IJKL MNxx
        2: low 6    xxAB CDEF
        3: all 8    GHIJ KLMN
    */
    
    // To do: Return struct which breaks out the received raw packet into its constituent segments
    // Consider: What about multi-packet messages? Out of scope?
    
    if ((length == 4) || (length == 6)){ // Identify packet type based on length
        returnPacket->type = RH_T_14_BIT;
#ifdef PARSE_PACKET_CAST_32
        uint32_t bigPacket = (packet[0] << 24) | (packet[1] << 16) | (packet[2] << 8) | (packet[3]);
        printf("%X\n", bigPacket);
        
        uint8_t  id             = (bigPacket & 0xF0000000) >> 28; // align LSB
        uint16_t temperature    = (bigPacket & 0x0FFFC000) >> 12; // align MSB
        uint16_t humidity       = (bigPacket & 0x00003FFF) <<  2; // align MSB
        
        printf("%01X %04X %04X\n", id, temperature, humidity);
        
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
        
#else
        uint8   id            = (packet[0] >> 4) & 0x0F;
        uint16  temperature   = ((packet[0] << 10) & 0x3C00) | \
                                ((packet[1] <<  2) & 0x03FC) | \
                                ((packet[2] >>  6) & 0x0003);
        uint16  humidity      = ((packet[2] << 8) & 0x3F00) | \
                                (packet[3] & 0x00FF);
        // uint16  crc =           (packet[4] << 8) | (packet[5]);
        
        printf("raw: %02X %02X %02X %02X\n", packet[0], packet[1], packet[2], packet[3]);
        
        returnPacket->deviceID = id;
        returnPacket->temperature_raw = temperature;
        returnPacket->temperature_scaled = temperature;
        returnPacket->temperature_scaled = ((returnPacket->temperature_scaled * 165.0f) / 65536.0f) - 40.0f;
        
        printf("\ttemp calcs\n");
        printf("\t\tstart 0x%X %f %A\n", temperature, (float)temperature, (float)temperature);
        printf("\t\tmult 165.0 %f\n", (float)temperature * 165.0f);
        printf("\t\tdiv 65536.0f %f\n", ((float)temperature * 165.0f) / 65536.0f);
        printf("\t\tsub 40.0f %f\n", (((float)temperature * 165.0f) / 65536.0f) - 40.0f);
        
        returnPacket->humidity_raw = humidity;
        returnPacket->humidity_scaled = humidity;
        returnPacket->humidity_scaled = (returnPacket->humidity_scaled / 65536.0f) * 100.0f;
        
        printf("\thumi calcs\n");
        printf("\t\tstart 0x%X %f\n", humidity, (float)humidity);
        printf("\t\tdiv 65536.0f %f\n", (float)humidity / 65536.0f);
        printf("\t\tmult 100.0 %f\n", ((float)humidity / 65536.0f) * 100.0f);
        
        printf("\tID:\t0x%01X (%d)\n", id, id);
        printf("\tTemp:\t0x%04X (%d) [%f ; %A]\n", temperature, temperature, returnPacket->temperature_scaled, returnPacket->temperature_scaled);
        printf("\tHumi:\t0x%04X (%d) [%f ; %A]\n", humidity, humidity, returnPacket->humidity_scaled, returnPacket->humidity_scaled);
#endif
    }else{
        printf("Unrecognized packet format\n");
        returnPacket->type = UNKNOWN;
    }
    return returnPacket->type;
}

modbus_t * modbus_setup(const char *device, int baud, char parity, int data_bit, int stop_bit)
{
    modbus_t *mb;
    // printf("\t(before) mb = 0x%02X\n", mb);
    printf("\tInstantiating Modbus RTU on %s at %d baud (%d%c%d).\n", device, baud, data_bit, parity, stop_bit);
    mb = modbus_new_rtu(device, baud, parity, data_bit, stop_bit);
    printf("\t(after) mb = 0x%02X\n", (uint32_t) mb);
    
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
    printf("addr\tbit\tibit\treg\tireg\n");
    printf("------------------------------------\n");
    for (int i = 0; (i < MAP_SIZE_BITS) || (i < MAP_SIZE_IBITS) || (i < MAP_SIZE_REGS) || (i < MAP_SIZE_IREGS); i++){
        printf("%04X|\t", i);
        if (i < MAP_SIZE_BITS){
            printf("%04X\t", map->tab_bits[i]);
        }else{
            printf("\t");
        }
        // usleep(1000);
        if (i < MAP_SIZE_IBITS){
            printf("%04X\t", map->tab_input_bits[i]);
        }else{
            printf("\t");
        }
        // usleep(1000);
        if (i < MAP_SIZE_REGS){
            printf("%04X\t", map->tab_registers[i]);
        }else{
            printf("\t");
        }
        // usleep(1000);
        if (i < MAP_SIZE_IREGS){
            // printf("ireg %d\n", i);
            printf("%04X\t", map->tab_input_registers[i]);
        }else{
            printf("\t");
        }
        // usleep(1000);
        printf("\n");
    }
}