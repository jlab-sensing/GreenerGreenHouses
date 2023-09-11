#include <fcntl.h> // open()
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
// #include <linux/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>

#include "cc112x_spi.h"
#include "SPI.h"
#include "cc112x_easy_link_reg_config.h"

#define RX_BUFFER_SIZE 16

// #define LIST_ALL_REGISTERS
// #define PACKET_PARSER

#define SPI_DEV_BUS0_CS0 "/dev/spidev0.0"

#define CC1125_REG_READ_nWRITE 0x80
#define CC1125_REG_BURST 0x40

#define RX_FIFO_ERROR 0x11

// Global
int spiFileDesc = 0;
FILE* fp = NULL;

static void manualCalibration(void);
static void registerConfig(const registerSetting_t *reg, int numRegisters);
static void packetParser(uint8 *packet, uint8 length);
void intHandler(int dummy);

int main(int argc, char *argv[]){
    
    printf("Program start.\n");
    
    signal(SIGINT, intHandler);
    
    printf("Opening %s in O_RDWR (r+).\n", SPI_DEV_BUS0_CS0);
    trxRfSpiInterfaceInit(0);
    if (spiFileDesc < 0){
        printf("Error: Could not init SPI.\n");
        exit(1);
    }

    if (SPI_readSettings(spiFileDesc) < 0){
        printf("Error: Could not read SPI mode settings.\n");
        exit(1);
    }
    
    printf("sizeof(preferredSettings) = %d\n", sizeof(preferredSettings));
    printf("sizeof(&preferredSettings) = %d\n", sizeof(&preferredSettings));
    printf("sizeof(registerSetting_t) = %d\n", sizeof(registerSetting_t));
    registerConfig(preferredSettings, sizeof(preferredSettings)/sizeof(registerSetting_t));
    
    manualCalibration();
    
    rfStatus_t status = 0;
    uint8 readByte;
    printf("\n\n\n");
    
#ifdef LIST_ALL_REGISTERS
    // Read ALL registers from radio
    printf("Reading ALL registers\n");
    printf("addr\tvalue\tstatus\n");
    for(uint16 i = 0; i < (sizeof(allSettings)/sizeof(registerSetting_t)); i++) {
        status = cc112xSpiReadReg(allSettings[i].addr, &readByte, 1);
        printf("0x%04X\t0x%02X\t0x%02X\n", allSettings[i].addr, readByte, status);
    }
    printf("Done reading ALL registers\n\n\n");
#endif
    
    uint8 rxBuffer[RX_BUFFER_SIZE] = {0};
    uint8_t rxBytes;
    uint8 marcState;
    uint8 lastMarcState;
    
    printf("Marcstate loop\n");
    int iteration = 0;
    printf("RX mode\n");
    trxSpiCmdStrobe(CC112X_SRX);

    fp = fopen("data", "w");
    if (fp == NULL){
        printf("null\n");
    }
    
    while(1){
        status = cc112xSpiReadReg(CC112X_MARCSTATE, &marcState, 1);
        if (marcState == lastMarcState){
            continue;
        }
        
        // printf("[%d] marcstate = 0x%02X, status = 0x%02X\n", iteration++, marcState, status);
        status = cc112xSpiReadReg(CC112X_NUM_RXBYTES, &rxBytes, 1);
        /*
        // if((marcState & 0x1F) == RX_FIFO_ERROR) {
            // Flush RX FIFO
            // printf("\tMARCSTATE RX_FIFO_ERROR, flushing\n");
            // trxSpiCmdStrobe(CC112X_SFRX);
        // }else if ((marcState & 0x6D) == 0x6D) { // RX
            // printf("\tRX\n");
        // }else if ((marcState & 0x6E) == 0x6E) { // RX_END
            // printf("\tRX_END\n");
        // }
        */
        if (rxBytes != 0){
            printf("\trxBytes = %d (0x%02X)\n", rxBytes, status);
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
        continue;
        
        
        
        
        
        status = cc112xSpiReadReg(CC112X_NUM_RXBYTES, &rxBytes, 1);
        
        if (rxBytes != 0){
            printf("RX FIFO %d bytes, status = 0x%02X\n", rxBytes, status);
            // Check MARCSTATE for RX FIFO error
            // Flush RX FIFO if error
            // Else read RX FIFO
            status = cc112xSpiReadReg(CC112X_MARCSTATE, &marcState, 1);

            // Mask out MARCSTATE bits and check if we have a RX FIFO error
            if((marcState & 0x1F) == RX_FIFO_ERROR) {
                // Flush RX FIFO
                printf("MARCSTATE RX_FIFO_ERROR, flushing\n");
                trxSpiCmdStrobe(CC112X_SFRX);
            } else {
                printf("marcstate = 0x%02X, rxBytes = %d\n", marcState, rxBytes);

                // status = cc112xSpiReadRxFifo(rxBuffer, rxBytes);
                status = cc112xSpiReadRxFifo(rxBuffer, RX_BUFFER_SIZE);

                printf("FIFO (0x%02X) {hex} : ", status);
                for (int i = 0; i < RX_BUFFER_SIZE; i++){
                    printf("%02X ", rxBuffer[i]);
                }
                printf("\n");
            }
            trxSpiCmdStrobe(CC112X_SRX);
            usleep(100);
        }
    }

    printf("Closing %s.\n", SPI_DEV_BUS0_CS0);
    // fclose(spiFileDesc);
    return 0;
}

void intHandler(int dummy) {
    fclose(fp);
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