/*
 * Uart.h
 * Header file for implementation of simple implementation of UART TX transmission via MSP430EXPFR5969
 * Written in Code Composer Studio 12.4
 * Created on: September 1, 2023
 * Last Modified: 9/5/23
 */

//Includes
#include "Uart.h"


void putcha(char c){

 EUSCI_A_UART_transmitData(EUSCI_A0_BASE,c);        //transmit singular character through UART TX buffer (defined in eusci_a_uart.h)
                                                    //EUSCI_A0_BASE: UART A0 base address, (defined in msp430fr5969.h)
}

void putstring(char *s){
    int i= 0;
    unsigned int length = ((strlen(s)) - 1);

    for(i = length; i >= 0; i--)
    {
        putcha(s[length - i]);                      //least significant char transmitted first
    }
}
uint8_t InitUart (void){
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



    return 1;
}
