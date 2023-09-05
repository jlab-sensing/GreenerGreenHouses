#include <fcntl.h> // open()
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
// #include <linux/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "cc112x_spi.h"
#include "SPI.h"
#include "cc112x_easy_link_reg_config.h"

// #define uint8_t u_int8_t
// #define SPI_BUFFER_SIZE 4

#define SPI_DEV_BUS0_CS0 "/dev/spidev0.0"

#define CC1125_REG_READ_nWRITE 0x80
#define CC1125_REG_BURST 0x40

// Global
int spiFileDesc = 0;

static void manualCalibration(void);
static void registerConfig(void);

int main(int argc, char *argv[]){
    
    printf("Program start.\n");
    
    printf("Opening %s in O_RDWR (r+).\n", SPI_DEV_BUS0_CS0);
    // SPI_MODE_x: (or combine SPI_CPOL and SPI_CPHA accordingly)
    // 0: no pol, no pha
    // 1: yes pol, no pha
    // 2: no pol, yes pha
    // 3: yes pol, yes pha
    // Frequencies:
    // SPEED_HZ_DEFAULT
    // choose your own
    // spiFileDesc = SPI_initPort(SPI_DEV_BUS0_CS0, SPI_MODE_0, 115200);
    trxRfSpiInterfaceInit(0);
    if (spiFileDesc < 0){
        printf("Error: Could not init SPI.\n");
        exit(1);
    }

    if (SPI_readSettings(spiFileDesc) < 0){
        printf("Error: Could not read SPI mode settings.\n");
        exit(1);
    }
    
    
    registerConfig();
    
    manualCalibration();
    trxSpiCmdStrobe(CC112X_SRX);
    
    rfStatus_t status = 0;
    uint8 readByte;
    printf("\n\n\n");
    // Read ALL registers from radio
    printf("Reading ALL registers\n");
    for(uint16 i = 0; i < (sizeof(allSettings)/sizeof(registerSetting_t)); i++) {
        status = cc112xSpiReadReg(allSettings[i].addr, &readByte, 1);
        printf("[0x%04X]\t0x%02X\t0x%02X\n", allSettings[i].addr, readByte, status);
    }
    printf("\n\n\n");
    
    uint16 address = 0x00;
    uint8 rxData[SPI_BUFFER_SIZE];
    for (int i = 0; i < sizeof(rxData); i++) rxData[i] = 0;
    
    while(1){
        // SPI_transfer(spiFileDesc, txBuffer, rxBuffer, SPI_BUFFER_SIZE);
        // sleep(1);
        // printf("\nrxBuffer: ");
        // for (int i = 0; i < SPI_BUFFER_SIZE; i++){
            // printf("0x%X ", rxBuffer[i]);
        // }
        
        // printf("TX status: %X\nRX status: %X\n", cc112xGetTxStatus(), cc112xGetRxStatus());
        
        
        // status = cc112xSpiReadReg(address, rxData, 1);
        // if (address >= 0x2FD9){
            // address = 0x00;
        // }else{
            // address++;
        // }
        
        // printf("[0x%02X] status = 0x%02X\trxData = 0x%02X\n", address, status, rxData[0]);
        
        status = cc112xGetRxStatus();
        printf("GetRxStatus status = 0x%02X\n", status);
        uint8_t rxStatus_chip;
        uint8_t rxStatus_state;
        uint8_t rxStatus_rxfifobytes;
        rxStatus_chip = status >> 7
        rxStatus_state;
        rxStatus_rxfifobytes;
        printf("\tCHIP_RDY | STATE[2:0] | FIFO_BYTES_AVAILABLE (available bytes in the RX FIFO\n");
        status = cc112xSpiReadRxFifo(rxData, length);
        printf("ReadRxFifo status = 0x%02X\n", status);
        sleep(1);
    }

    printf("Closing \"/dev/spidev0.0\".\n");
    // fclose(spiFileDesc);
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
*   @return     none
*/
static void registerConfig(void) {

    uint8 writeByte;
    uint8 readByte;
    rfStatus_t status;
    
    for(uint16 i = 0; i < (sizeof(preferredSettings)/sizeof(registerSetting_t)); i++) {
        printf("%d\t0x%02X\t0x%02X\n", i, preferredSettings[i].data, preferredSettings[i].addr);
    }

    // Reset radio
    printf("Resetting radio.\n");
    status = trxSpiCmdStrobe(CC112X_SRES);
    printf("Status byte: 0x%02X\n", status);
    
    // Wait for reset
    sleep(1);
    
    // Read registers from radio
    printf("Reading\n");
    for(uint16 i = 0; i < (sizeof(preferredSettings)/sizeof(registerSetting_t)); i++) {
        printf("i = %d\t", i);
        printf("expect = 0x%02X\t", preferredSettings[i].data);
        status = cc112xSpiReadReg(preferredSettings[i].addr, &readByte, 1);
        printf("value = 0x%02X\t", readByte);
        
        if (readByte == preferredSettings[i].data){
            printf("OK\n");
        }else{
            printf("UNEXPECTED REGISTER VALUE\n");
        }
    }

    // Write registers to radio
    printf("Writing\n");
    for(uint16 i = 0; i < (sizeof(preferredSettings)/sizeof(registerSetting_t)); i++) {
        printf("i = %d\t", i);
        writeByte = preferredSettings[i].data;
        printf("writeByte = 0x%02X\t", writeByte);
        status = cc112xSpiWriteReg(preferredSettings[i].addr, &writeByte, 1);
        printf("status = 0x%02X\n", status);
    }
    
    // Read registers from radio
    printf("Reading\n");
    for(uint16 i = 0; i < (sizeof(preferredSettings)/sizeof(registerSetting_t)); i++) {
        printf("i = %d\t", i);
        printf("expect = 0x%02X\t", preferredSettings[i].data);
        status = cc112xSpiReadReg(preferredSettings[i].addr, &readByte, 1);
        printf("value = 0x%02X\t", readByte);
        
        if (readByte == preferredSettings[i].data){
            printf("OK\n");
        }else{
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
