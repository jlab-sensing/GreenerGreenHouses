#include <msp430.h> 
#include "hal_spi_rf_trxeb.h"
#include "cc112x_spi.h"
#include "hal_spi_rf_trxeb.h"
#include "stdint.h"


/**
 * main.c
 */
uint8_t DeviceID[8] = {0};
uint8_t DevAdd[1] = {0xA};
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	PM5CTL0 &= ~LOCKLPM5;
	trxRfSpiInterfaceInit(4);
	cc112xSpiWriteReg(CC112X_DEV_ADDR,DevAdd, 1);

	cc112xSpiReadReg(CC112X_DEV_ADDR,DeviceID, 1);
	int j=0;
	while(1){

	    j = 1;
	}


	return 0;
}
