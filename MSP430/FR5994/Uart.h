/*
 * Uart.h
 * Header file for implementation of simple UART TX transmission via MSP430EXPFR5969
 * Written in Code Composer Studio 12.4
 * Created on: September 1, 2023
 * Last Modified: 9/5/23
 */

#ifndef UART_H_
#define UART_H_

#include <eusci_a_uart.h>
#include <string.h>//Essential includes
#include <msp430.h>

#include "stdint.h"

#include <stdio.h>
#include <Uart.h>


#include <gpio.h>
#include <hw_memmap.h>
#include <cs.h>
#include <string.h>

uint8_t InitUart(void);
/*
* transmits character over UART TX transmission
* param: c, char type, single character to transmit
*/
void putcha(char c);

/*
* transmits whole string over UART TX transmission, one character at a time using
* putcha
* param: *s, char pointer to string to transmit
*/
void putstring(char *s);

#endif /* UART_H_ */
