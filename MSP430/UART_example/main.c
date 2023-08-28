/*
 * main.c
 * Main test file for UART driver library
 * Written using Max Dunne's UART and Circular Buffer Library
 * Written in Code Composer Studio 12.4
 * Created on: Aug 21, 2023
 * Author: Tim Kraemer
 * Last Modified: 8/28/23
 */

#include "msp430.h"
#include "CircularBuffer.h"
#include "UART.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;                 // Stop Watchdog

  UART_Init_GPIO();
  UART_Init_Clock();
  UART_Init();


  char message1[] = "Message1\n";
  //char message2[] = "Message2\n";

  UART_Write_Data(message1, strlen(message1));
  //UART_Write_Data(message2, strlen(message2));

  while(1);
}
