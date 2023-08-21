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



/*
 * HDC2080 Register Map
 */
#define HDC2021_ADDRESS 0x40
#define TEMP_LO_REG 0x00
#define TEMP_HI_REG 0x01
#define HUMIDITY_LO_REG 0x02
#define HUMIDITY_HI_REG 0x03
#define CONFIG_REG 0x0E
#define MEAS_CONFIG_REG 0x0F



float Sensor_ReadTemp(void) {
	uint8_t byte1[1] = {0};
	uint8_t byte2[1] = {0};
	uint16_t temp = 0;
	I2C_Controller_ReadReg(HDC2021_ADDRESS, TEMP_LO_REG, 1);            //Poll Upper and Lower temp Registers for 8b temp data
	CopyRxArray(byte1, 1);
    I2C_Controller_ReadReg(HDC2021_ADDRESS, TEMP_HI_REG, 1);
    CopyRxArray(byte2, 1);

	temp = byte2[0];                                                    //Temperature conversion to readable values (HDC2080 datasheet)
	temp = (temp << 8) | byte1[0];
	float f = temp;
	f = ((f * 165.0f) / 65536.0f) - 40.0f;
	return f;
}

float Sensor_ReadHumidity() {
    uint8_t byte1[1] = {0};
    uint8_t byte2[1] = {0};
    uint16_t humidity = 0;
    I2C_Controller_ReadReg(HDC2021_ADDRESS, HUMIDITY_LO_REG, 1);        //Poll upper and lower humidity registers for 8b humidity data
    CopyRxArray(byte1, 1);
    I2C_Controller_ReadReg(HDC2021_ADDRESS, HUMIDITY_HI_REG, 1);
    CopyRxArray(byte2, 1);

    humidity = byte2[0];                                                //Humidity conversion to readable values (HDC2080 datasheet)
    humidity = (humidity << 8) | byte1[0];
    float f = humidity;
    f = (f / 65536.0f) * 100.0f;
    return f;
}


void Sensor_TriggerMeasurement(void) {
    uint8_t configContents[1] = {0};
    I2C_Controller_ReadReg(HDC2021_ADDRESS, MEAS_CONFIG_REG, 1);
    CopyRxArray(configContents, 1);

    configContents[0] |= 0x01;                                                       //b. 0 in register 0x0F (MEAS_CONFIG_REG)
                                                                                     //triggers sensor measurement
    I2C_Controller_WriteReg(HDC2021_ADDRESS, MEAS_CONFIG_REG, configContents, 1);    //Register Write-back
}

void Sensor_Reset(void) {
    uint8_t configContents[1] = {0};
    I2C_Controller_ReadReg(HDC2021_ADDRESS, CONFIG_REG, 1);
    CopyRxArray(configContents, 1);

    configContents[0] |= 0x80;                                                       //b. 8 in register 0x0E (CONFIG_REG)
                                                                                     //triggers soft reset. Bit is self-clearing

    I2C_Controller_WriteReg(HDC2021_ADDRESS, CONFIG_REG, configContents, 1);
}

void Sensor_SetMeasurementRate(int Rate) {
	uint8_t configContents[1] = {0};
	I2C_Controller_ReadReg(HDC2021_ADDRESS, CONFIG_REG, 1);
	CopyRxArray(configContents, 1);

	switch(Rate) {                                                                  //5 cases (2 minutes, 1 minute, 10 sec, 5 sec
		case MANUAL:                                                                //Manual Mode, no frequency set
			configContents[0] &= 0x8F;                                              //Soft reset bit enabled for each option
			break;
		case TWO_MINS:
			configContents[0] &= 0x9F;
			configContents[0] |= 0x10;
			break;
		case ONE_MINS:
			configContents[0] &= 0xAF;
			configContents[0] |= 0x20;
			break;
		case TEN_SECONDS:
			configContents[0] &= 0xBF;
			configContents[0] |= 0x30;
			break;
		case FIVE_SECONDS:
			configContents[0] &= 0xCF;
			configContents[0] |= 0x40;
			break;
		default:
			configContents[0] &= 0x8F;                                              //Default case resorts to MANUAL mode
	}

	I2C_Controller_WriteReg(HDC2021_ADDRESS, CONFIG_REG, configContents, 1);
}

void Sensor_SetMeasurementMode(int Mode) {
	uint8_t configContents[1] = {0};
	I2C_Controller_ReadReg(HDC2021_ADDRESS, MEAS_CONFIG_REG, 1);
	CopyRxArray(configContents, 1);

	switch(Mode) {
		case TEMP_AND_HUMID:
			configContents[0] &= 0xF9;
			break;
		case TEMP_ONLY:
			configContents[0] &= 0xFC;
			configContents[0] |= 0x02;
			break;
		case HUMID_ONLY:
			configContents[0] &= 0xFD;
			configContents[0] |= 0x04;
			break;
		default:
			configContents[0] &= 0xF9;                                             //Default case sets mode to temperature and humidity
	}

	I2C_Controller_WriteReg(HDC2021_ADDRESS, MEAS_CONFIG_REG, configContents, 1);
}

void Sensor_SetHumidityResolution(int Resolution) {
    uint8_t configContents[1] = {0};
    I2C_Controller_ReadReg(HDC2021_ADDRESS, MEAS_CONFIG_REG, 1);
    CopyRxArray(configContents, 1);

    switch(Resolution) {
    case FOURTEEN_BIT:
        configContents[0] &= 0x3F;
        break;
    case ELEVEN_BIT:
        configContents[0] &= 0x7F;
        configContents[0] |= 0x40;
        break;
    case NINE_BIT:
        configContents[0] &= 0xBF;
        configContents[0] |= 0x80;
        break;
    default:
        configContents[0] &= 0x3F;                                                     //Default case, 14 bit resolution
    }

    I2C_Controller_WriteReg(HDC2021_ADDRESS, MEAS_CONFIG_REG, configContents, 1);
}

void Sensor_SetTempResolution(int Resolution) {
    uint8_t configContents[1] = {0};
    I2C_Controller_ReadReg(HDC2021_ADDRESS, MEAS_CONFIG_REG, 1);
    CopyRxArray(configContents, 1);

    switch(Resolution) {
        case FOURTEEN_BIT:
            configContents[0] &= 0xCF;
            break;
        case ELEVEN_BIT:
            configContents[0] &= 0xDF;
            configContents[0] |= 0x10;
            break;
        case NINE_BIT:
            configContents[0] &= 0xEF;
            configContents[0] |= 0x20;
            break;
        default:
            configContents[0] &= 0xCF;                                                 //Default case, 14 bit resolution
    }

    I2C_Controller_WriteReg(HDC2021_ADDRESS, MEAS_CONFIG_REG, configContents, 1);
}
