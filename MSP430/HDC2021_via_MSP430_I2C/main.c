#include <msp430.h> 
#include <stdlib.h>
#include "MSP430_I2C.h"
#include "HDC2021.h"

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	return 0;
}
