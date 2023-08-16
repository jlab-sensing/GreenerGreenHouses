#include <msp430.h>
#include <stdio.h>
#include <stdlib.h>




int main()
{
    WDTCTL = WDTPW | WDTHOLD;
   //uart_setup();
   // uart_putchar('c');
    return 1;
}
