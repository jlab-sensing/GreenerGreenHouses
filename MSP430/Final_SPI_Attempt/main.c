
//Essential includes
#include <msp430.h> 
#include "hal_spi_rf_trxeb.h"
#include "cc112x_spi.h"
#include "stdint.h"
#include "smartRF1125.h"
#include <stdio.h>
#include <Uart.h>

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
char Debug_Msg[RXSIZE] = {0};
uint8_t RxBuff[RXSIZE] = {0}; //uint8_t array to store value from CC1125 Rx Fifo buffer
char SerialMsg[RXSIZE] = {0}; //char array to send out over Uart to terminal
uint8_t RxLength = 0;		//Custom slave address for BOOSTXL CC1125 LoRa pack


uint8_t initSpi(void){
    /* Select Port J
    * Set Pin 4, 5 to input Primary Module Function, LFXT.
    */
    GPIO_setAsPeripheralModuleFunctionInputPin(
        GPIO_PORT_PJ,
        GPIO_PIN4 + GPIO_PIN5,
        GPIO_PRIMARY_MODULE_FUNCTION
    );

    //Set DCO frequency to 1 MHz
    CS_setDCOFreq(CS_DCORSEL_0,CS_DCOFSEL_0);
    //Set external clock frequency to 32.768 KHz
    CS_setExternalClockSource(32768,0);
    //Set ACLK=LFXT
    CS_initClockSignal(CS_ACLK,CS_LFXTCLK_SELECT,CS_CLOCK_DIVIDER_1);
    //Set SMCLK = DCO with frequency divider of 1
    CS_initClockSignal(CS_SMCLK,CS_DCOCLK_SELECT,CS_CLOCK_DIVIDER_1);
    //Set MCLK = DCO with frequency divider of 1
    CS_initClockSignal(CS_MCLK,CS_DCOCLK_SELECT,CS_CLOCK_DIVIDER_1);
    //Start XT1 with no time out
    CS_turnOnLFXT(CS_LFXT_DRIVE_0);


    // Configure UART pins
    //Set P2.0 and P2.1 as Secondary Module Function Input.
    /*
    * Select Port 2d
    * Set Pin 0, 1 to input Secondary Module Function, (UCA0TXD/UCA0SIMO, UCA0RXD/UCA0SOMI).
    */
    GPIO_setAsPeripheralModuleFunctionInputPin(
    GPIO_PORT_P2,
    GPIO_PIN0 + GPIO_PIN1,
    GPIO_SECONDARY_MODULE_FUNCTION
    );

    //UART parameter object, setttings set for UART communication
    EUSCI_A_UART_initParam param;
    param.selectClockSource = EUSCI_A_UART_CLOCKSOURCE_SMCLK;
    param.clockPrescalar = 0x6;
    param.firstModReg = 0x8;
    param.secondModReg = 0x11;
    param.parity = EUSCI_A_UART_NO_PARITY;
    param.msborLsbFirst = EUSCI_A_UART_LSB_FIRST;
    param.numberofStopBits = EUSCI_A_UART_ONE_STOP_BIT;
    param.uartMode = EUSCI_A_UART_MODE;
    param.overSampling = 0x1;


    //UART initialization failure check
    if(STATUS_FAIL ==EUSCI_A_UART_init(EUSCI_A0_BASE,&param)){
      return 0;
    }

    //enable UART block
    EUSCI_A_UART_enable(EUSCI_A0_BASE);

    //reset interupt
    EUSCI_A_UART_clearInterrupt(EUSCI_A0_BASE,
        EUSCI_A_UART_RECEIVE_INTERRUPT);

    // Enable USCI_A0 RX interrupt
    EUSCI_A_UART_enableInterrupt(EUSCI_A0_BASE,
        EUSCI_A_UART_RECEIVE_INTERRUPT);

    __enable_interrupt();

    //initialize SPI block, set 4 as prescaller for SCLK
    trxRfSpiInterfaceInit(4);

    return 1;
}
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




//main
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	PM5CTL0 &= ~LOCKLPM5;

	if(!initSpi()){
	    return 0;
	}
	putstring("Test program for communication between MSP430FR5969 and CC1125 LoRa\r\n\r\n");
	putstring("==========================================================\r\n");
    putstring("==========================================================\r\n");


	ConfigRegisters(PACKET_MODE);
	manualCalibration();
	trxSpiCmdStrobe(CC112X_SRX);
	//dummy variable for debug break-point
	int j=0;
    //infinite while loop program trap
	while(1){

	    //if the rx status is not idle
	  //  s = cc112xGetRxStatus();
	   // char status = (char)s;
//	    if (j <= 100)
//	    {
//	    sprintf(Debug_Msg,"STATUS: 0x%x",s);
//	    putstring(Debug_Msg);
//	    putstring("\r\n");
//
//	    j++;
//	    }

//	    if(cc112xGetRxStatus() == CC112X_STATE_RX){
//	            //get number of bytes in CC1125 Rx Fifo
//	            cc112xSpiReadReg(CC112X_NUM_RXBYTES,&RxLength,1);
//	            putstring("RX FIFO SIZE:");
//	            putcha(RxLength);
//	            //read CC1125 Rx Fifo
//	            cc112xSpiReadRxFifo(RxBuff,RxLength);
//
//	            //cast CC1125 Rx from int to char
//	            for(j = 0; j < RxLength; j++)
//	            {
//	                SerialMsg[j] = (char)RxBuff[j];
//	            }
//	            putstring(SerialMsg);
//	            putstring("\r\n");
//	            memset(RxBuff,0,RXSIZE);
//	        }
	    if(cc112xGetRxStatus() == 0x9){
	                //get number of bytes in CC1125 Rx Fifo
	                cc112xSpiReadReg(CC112X_NUM_RXBYTES,&RxLength,1);
//	                putstring("RX FIFO SIZE:");
//	                putcha(RxLength);
//	                putstring("\r\n");
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


	//return 0;
}
