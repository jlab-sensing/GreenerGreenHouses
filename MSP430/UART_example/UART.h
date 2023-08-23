/*
 * UART.h
 * Header file for implementation of UART communication with the MSP430FR5969
 * Adapted from TI's msp430fr59xx_euscia_0uart2 example
 * Written in Code Composer Studio 12.4
 * Created on: Aug 21, 2023
 * Author: Tim Kraemer
 * Last Modified: 8/21/23
 */

#ifndef MSP430_UART_H_
#define MSP430_UART_H_

#include <stdint.h>

//define max size of TX buffer
#define MAX_BUFFER_SIZE_UART 50

/*
 * Enables UART interrupts and sets initial timers
 * Baudrate is set by default to 9600
 */
void UART_Init(void);

/*
* Disable the GPIO power-on default high-impedance mode to activate
* previously configured port settings
 */
void UART_Init_GPIO(void);

/*
 * Initializes the UART Clocks
 */
void UART_Init_Clock(void);

/*
 * Raises TX interrupt flag and transmits data byte by byte through UART TX buffer
 * Once all bytes are passed through, lowers TX interrupt flag
 * data: char pointer (string) of data to be passed
 */
void TXTransmit(char* data, unsigned char length);

#endif
