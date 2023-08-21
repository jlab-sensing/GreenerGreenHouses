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


/*
 * Enables UART interrupts and sets initial timers
 */
void initUART(void);

void initGPIO(void);

void initClock(void);

void CopyTXArray(uint8_t *source,uint8_t count)

/*
 * Raises TX interrupt flag and transmits data byte by byte through UART TX buffer
 * Once all bytes are passed through, lowers TX interrupt flag
 * data: char pointer (string) of data to be passed
 */
void TXTransmit(uint8_t* data, int length);

#endif
