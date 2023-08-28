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
