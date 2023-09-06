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
    int length = ((strlen(s)) - 1);

    for(i = length; i >= 0; i--)
    {
        putcha(s[length - i]);                      //least significant char transmitted first
    }
}
