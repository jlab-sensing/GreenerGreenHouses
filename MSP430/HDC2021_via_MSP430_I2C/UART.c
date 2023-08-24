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

#include "UART.h"

char TXBuffer[MAX_BUFFER_SIZE_UART] = {0};
unsigned char TXbytes = 0;
uint8_t messageLength = 0;

void CopyTXArray(char *source, unsigned char count);

void CopyTXArray(char *source, unsigned char count)
{
        uint8_t copyIndex = 0;
        for (copyIndex = 0; copyIndex < count; copyIndex++)
        {
            TXBuffer[copyIndex] = source[copyIndex];
        }
}


void UART_Init() {
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


void TXTransmit(char *message, unsigned char length) {
    CopyTXArray(message, length);                                              //Copy message into TX buffer for transmission
    messageLength = length;
    UCA0IE |= UCTXIE;                                                        //Enable TX interrupt flag
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

          // Transmit the byte
          UCA0TXBUF = TXBuffer[TXbytes++];

          // If last byte sent, disable the interrupt
          if(TXbytes == messageLength)
          {
              UCA0IE &= ~UCTXIE;
              TXbytes = 0;
          }
          break;

      case USCI_UART_UCSTTIFG: break;
      case USCI_UART_UCTXCPTIFG: break;
      default: break;
    }
}
