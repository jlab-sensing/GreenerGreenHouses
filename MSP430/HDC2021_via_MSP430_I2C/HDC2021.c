/*
 * HDC2021.c
 *
 *  Created on: Aug 17, 2023
 *      Author: matth
 */

#include <stdlib.h>
#include <stdint.h>
#include "HDC2021.h"
#include "MSP430_I2C.h"

#define HDC2021_ADDRESS 0x40
#define TEMP_LO_REG 0x00
#define TEMP_HI_REG 0x01
#define HUMIDITY_LO_REG 0x02
#define HUMIDITY_HI_REG 0x03
#define CONFIG_REG 0x0E
#define MEAS_CONFIG_REG 0x0F

float Sensor_ReadTemp(void) {
	
}

float Sensor_ReadHumidity() {

}


void Sensor_TriggerMeasurement(void) {

}

void Sensor_SetMeasurementRate(int Rate) {
	uint8_t configContents[1] = {0};
	//Read register CONFIG_REG to configContents[0]
	switch(Rate) {
		case MANUAL:
			configContents[0] = configContents[0] & 0x8F;
			break;
		case TWO_MINS:
			configContents[0] = configContents[0] & 0x9F;
			configContents[0] = configContents[0] | 0x10;
			break;
		case ONE_MINS:
			configContents[0] = configContents[0] & 0xAF;
			configContents[0] = configContents[0] | 0x20;
			break;
		case TEN_SECONDS:
			configContents[0] = configContents[0] & 0xBF;
			configContents[0] = configContents[0] | 0x30;
			break;
		case FIVE_SECONDS:
			configContents[0] = configContents[0] & 0xCF;
			configContents[0] = configContents[0] | 0x40;
			break;
		default:
			configContents[0] = configContents[0] & 0x8F;
	}
	//Write configContents[0] to register CONFIG_REG
}

void Sensor_MeasurementMode(int Mode) {
	uint8_t configContents[1] = {0};
	//Read register MEAS_CONFIG_REG to configContents[0]
	switch(Mode) {
		case TEMP_AND_HUMID:
			configContents[0] = configContents[0] & 0xF9;
			break;
		case TEMP_ONLY:
			configContents[0] = configContents[0] & 0xFC;
			configContents[0] = configContents[0] | 0x02;
			break;
		case HUMID_ONLY:
			configContents[0] = configContents[0] & 0xFD;
			configContents[0] = configContents[0] | 0x04;
			break;
		default:
			configContents[0] = configContents[0] & 0xF9;
	}
	//Write configContents[0] to register 0x0F
}

void Sensor_SetHumidityResolution(int Resolution) {
    uint8_t configContents[1] = {0};
    //Read register MEAS_CONFIG_REG to configContents[0]
    switch(Resolution) {
    case FOURTEEN_BIT:
        configContents[0] = configContents[0] & 0x3F;
        break;
    case ELEVEN_BIT:
        configContents[0] = configContents[0] & 0x7F;
        configContents[0] = configContents[0] | 0x40;
        break;
    case NINE_BIT:
        configContents[0] = configContents[0] & 0xB7;
        configContents[0] = configContents[0] | 0x80;
        break;
    default:
        configContents[0] = configContents[0] & 0x3F;
    }
    //Write configContents[0] to MEAS_CONFIG_REG
}

void Sensor_SetTempResolution(int Resolution) {

}
