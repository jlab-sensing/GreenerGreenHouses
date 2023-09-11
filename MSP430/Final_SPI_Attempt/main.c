
//Essential includes
#include <msp430.h> 
#include "hal_spi_rf_trxeb.h"
#include "cc112x_spi.h"
#include "stdint.h"
#include "smartRF1125.h"
#include <stdio.h>
#include <Uart.h>
#include "HDC2021.h"
#include "MSP430_I2C.h"
#include "FR5969_CC1125.h"
#include <gpio.h>
#include <hw_memmap.h>
#include <cs.h>
#include <string.h>
//#include <driverlib/MSP430FR5xx_6xx/eusci_b_spi.h>
//#include <pmm.h>
//#include <wdt_a.h>
//#include <driverlib/MSP430FR5xx_6xx/cs.h>


#define RXSIZE 256
#define MESSAGE_SIZE 6

char Debug_Msg[RXSIZE] = {0};
uint8_t TxBuff[MESSAGE_SIZE] = {0};
uint8_t RxBuff[RXSIZE] = {0}; //uint8_t array to store value from CC1125 Rx Fifo buffer
char SerialMsg[RXSIZE] = {0}; //char array to send out over Uart to terminal
uint8_t RxLength = 0;		//Custom slave address for BOOSTXL CC1125 LoRa pack
char message = "Test";
int packet_count = 0;

rfStatus_t s;

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

enum modes {
    RX_test,
    TX_test
};

const int test_select = RX_test;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	PM5CTL0 &= ~LOCKLPM5;

	if(!InitUart()){
	    return 0;
	}
	   //initialize SPI block, set 4 as prescaller for SCLK
	    trxRfSpiInterfaceInit(4);

	putstring("Test program for communication between MSP430FR5969 and CC1125 LoRa\r\n\r\n");
	putstring("==========================================================\r\n");
    putstring("==========================================================\r\n");
    if(test_select == TX_test) {
        putstring("TX transmission test mode\r\n");
    }
    else if(test_select == RX_test) {
        putstring("RX recieving test mode\r\n");
    }


	ConfigRegisters(PACKET_MODE);
	manualCalibration();

	int i = 0;

    switch(test_select) {
        case TX_test:
            //transmit message "Test" with packet number after it every second
	        for(i = 0; i < 10; i++) {
	            sprintf(TxBuff, "%s %d\n", message, packet_count);

	            cc112xSpiWriteTxFifo(TxBuff, sizeof(TxBuff));
	            trxSpiCmdStrobe(CC112X_STX);
	            memset(TxBuff,0,6);
	            packet_count++;
	            __delay_cycles(1000000);
	        }
            break;
        


        case RX_test:
            putstring("Made it to RX TEST\n");
            trxSpiCmdStrobe(CC112X_SRX);
	        //dummy variable for debug break-point
	        int j=0;
	        //infinite while loop program trap
	        while(1){

	            if(cc112xGetRxStatus() == 0x9){
	                putstring("Made it to RX ACTUAL\n");
	                //get number of bytes in CC1125 Rx Fifo
	                cc112xSpiReadReg(CC112X_NUM_RXBYTES,&RxLength,1);

	                //read CC1125 Rx Fifo
	                cc112xSpiReadRxFifo(RxBuff,RxLength);

	                //cast CC1125 Rx from int to char
	                for(j = 0; j < RxLength; j++)
	                {
	                    SerialMsg[j] = (char)RxBuff[j];

	                }

                   //print the message received, and the size of the RX buffer
	                putstring("RX RECEIVED MSG:");
	                putstring(SerialMsg);
	                putstring("\r\n");
	                memset(RxBuff,0,RXSIZE);
	                trxSpiCmdStrobe(CC112X_SRX);

	            }
	        }
	        break;
    }

	while(1);

}
