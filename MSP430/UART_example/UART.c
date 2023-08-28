/*
 * UART.c
 * Header file for implementation of UART communication with the MSP430FR5969
 * Adapted from TI's msp430fr59xx_euscia_0uart2 example
 * Written in Code Composer Studio 12.4
 * Created on: Aug 21, 2023
 * Author: Tim Kraemer
 * Last Modified: 8/21/23
 */

#include <stdlib.h>
#include <msp430.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "UART.h"
#include "CircularBuffer.h"

static CircularBuffer uart1TxBuffer;
static uint8_t u1TxBuf[1024];


void UART_Init() {
    // First initialize the necessary circular buffers.
    CB_Init(&uart1TxBuffer, u1TxBuf, sizeof (u1TxBuf));


    // Configure USCI_A0 for UART mode
      UCA0CTLW0 = UCSWRST;                      // Put eUSCI in reset
      UCA0CTLW0 |= UCSSEL__SMCLK;               // CLK = SMCLK
      // Baud Rate calculation
      // 8000000/(16*9600) = 52.083
      // Fractional portion = 0.083
      // User's Guide Table 21-4: UCBRSx = 0x04
      // UCBRFx = int ( (52.083-52)*16) = 1
      UCA0BR0 = 52;                             // 8000000/16/9600
      UCA0BR1 = 0x00;
      UCA0MCTLW |= UCOS16 | UCBRF_1;
      UCA0CTLW0 &= ~UCSWRST;                    // Initialize eUSCI

      __bis_SR_register(GIE);       // Enter LPM3, interrupts enabled
}


void UART_Init_Clock() {
    // Startup clock system with max DCO setting ~8MHz
    CSCTL0_H = CSKEY >> 8;                    // Unlock clock registers
    CSCTL1 = DCOFSEL_3 | DCORSEL;             // Set DCO to 8MHz
    CSCTL2 = SELA__VLOCLK | SELS__DCOCLK | SELM__DCOCLK;
    CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1;     // Set all dividers
    CSCTL0_H = 0;
}


void UART_Init_GPIO() {
    // Configure GPIO
    P2SEL1 |= BIT0 | BIT1;                    // USCI_A0 UART operation
    P2SEL0 &= ~(BIT0 | BIT1);

    // Disable the GPIO power-on default high-impedance mode to activate
    // previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;
}


void UART_Start_Transmission() {
    while(uart1TxBuffer.dataSize > 0) {
        uint8_t c;
        CB_ReadByte(&uart1TxBuffer, &c);
        UCA0TXBUF = c;
        __delay_cycles(10000);
    }
}

int UART_Write_Data(const void *data, size_t length) {
    int success = CB_WriteMany(&uart1TxBuffer, data, length, false);
    UCA0IE |= UCTXIE;
    return success;
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(USCI_A0_VECTOR))) USCI_A0_ISR (void)
#else
#error Compiler not supported!
#endif
{
    switch(__even_in_range(UCA0IV,USCI_UART_UCTXCPTIFG))
    {
      case USCI_NONE: break;
      case USCI_UART_UCRXIFG: break;

      case USCI_UART_UCTXIFG:

          UART_Start_Transmission();
          UCA0IE &= ~UCTXIE;

      case USCI_UART_UCSTTIFG: break;
      case USCI_UART_UCTXCPTIFG: break;
      default: break;
    }
}
