#include <msp430.h> 
#include <driverlib/MSP430FR5xx_6xx/eusci_a_spi.h>

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
//	EUSCI_A_SPI_initMaster(uint16_t baseAddress, EUSCI_A_SPI_initMasterParam *param);
//	EUSCI_A_SPI_changeMasterClock(uint16_t baseAddress,EUSCI_A_SPI_changeMasterClockParam *param);
//	EUSCI_A_SPI_enable(uint16_t baseAddress);

	return 0;
}
