#include <msp430.h> 
#include <stdlib.h>
#include "MSP430_I2C.h"
#include "HDC2021.h"
#include <stdint.h>

/**
 * main.c
 */

extern uint8_t ReceiveBuffer[MAX_BUFFER_SIZE];

#define I2C_INITIAL_COMM_TEST

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
    initClockTo16MHz();
    initGPIO();
    initI2C(HDC2021_ADDRESS);

#ifdef I2C_INITIAL_COMM_TEST

    uint8_t DeviceID_Hi[1] = {0};
    uint8_t DeviceID_Lo[1] = {0};
    uint8_t ManufacturerID_Hi[1] = {0};
    uint8_t ManufacturerID_Lo[1] = {0};
    uint16_t DeviceID = 0x00;
    uint16_t ManufacturerID = 0x00;
    uint8_t data1[2],data2[2];

I2C_Controller_ReadReg(HDC2021_ADDRESS,0xFD ,STD_MSG_LENGTH );
CopyArray(ReceiveBuffer, ManufacturerID_Hi, STD_MSG_LENGTH);
I2C_Controller_ReadReg(HDC2021_ADDRESS, 0xFC, STD_MSG_LENGTH);
CopyArray(ReceiveBuffer, ManufacturerID_Lo, STD_MSG_LENGTH);

data1[0] = ManufacturerID_Lo[0];
data1[1] = ManufacturerID_Hi[0];

ManufacturerID = data1[1];
ManufacturerID = (ManufacturerID << 8) | data1[0];


I2C_Controller_ReadReg(HDC2021_ADDRESS,0xFF ,STD_MSG_LENGTH );
CopyArray(ReceiveBuffer, DeviceID_Hi, STD_MSG_LENGTH);
I2C_Controller_ReadReg(HDC2021_ADDRESS, 0xFE, STD_MSG_LENGTH);
CopyArray(ReceiveBuffer, DeviceID_Lo, STD_MSG_LENGTH);

data2[0] = DeviceID_Lo[0];
data2[1] = DeviceID_Hi[0];

DeviceID = data2[1];
DeviceID = (DeviceID << 8) | data2[0];

#endif


	return 0;
}
