
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
uint8_t RxBuff[RXSIZE] = {0};
uint8_t DevAdd[1] = {0xA};		//Custom slave address for BOOSTXL CC1125 LoRa pack


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


	ConfigRegisters(TX_MODE);


	//dummy variable for debug break-point
	int j=0;
    //infinite while loop program trap
	while(1){
	    if(cc112xGetRxStatus() == CC112X_STATE_RX){
	            cc112xSpiReadRxFifo(RxBuff,CC112X_NUM_RXBYTES);
	            putstring(RxBuff);
	            putstring("\r\n");
	            memset(RxBuff,0,RXSIZE);
	        }
	}


	return 0;
}
