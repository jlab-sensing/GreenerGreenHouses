/*
 * Uart.h
 *
 *  Created on: Sep 5, 2023
 *      Author: matth
 */

#ifndef UART_H_
#define UART_H_

#include <eusci_a_uart.h>
#include <string.h>

void putcha(char c);

void putstring(char *s);

#endif /* UART_H_ */
