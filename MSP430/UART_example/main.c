#include "msp430.h"
#include "UART.h"
#include <string.h>
#include <stdint.h>

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;                 // Stop Watchdog

  UART_Init_GPIO();
  UART_Init_Clock();
  UART_Init();


  char message[] = "Matt is such a cool guy\n";
  unsigned char message_length = strlen(message);

  UART_Write_Data(message, message_length);

  while(1);


}
