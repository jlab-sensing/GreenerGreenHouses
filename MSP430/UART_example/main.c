#include "msp430.h"
#include "UART.h"
#include <string.h>
#include <stdint.h>

//hi

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;                 // Stop Watchdog

  UART_Init_GPIO();
  UART_Init_Clock();
  UART_Init();


  char message[] = "Matt is such a cool guy";
  unsigned char message_length = strlen(message);

  TXTransmit(message, message_length);

  while(1);


}
