/*
 * HDC2021.h
 * Header file for implementation of HDC2021 RH/T Sensor via MSP430EXPFR5969
 * Written in Code Composer Studio 12.4
 *  Created on: Aug 17, 2023
 *      Author: Matthew Kaltman
 *
 */

#ifndef HDC2021_H_
#define HDC2021_H_

//Available measurement resolution for temperature and humidity
#define FOURTEEN_BIT 0
#define ELEVEN_BIT 1
#define NINE_BIT 2

//Sensor sample rate choices
#define MANUAL 0
#define TWO_MINS 1
#define ONE_MINS 2
#define TEN_SECONDS 3
#define FIVE_SECONDS 4
#define ONE_SECOND 5

//Sensor measurement modes
#define TEMP_AND_HUMID 0
#define TEMP_ONLY 1
#define HUMID_ONLY 2
#define ACTIVE_LOW 0
#define ACTIVE_HIGH 1
#define LEVEL_MODE 0
#define COMPARATOR_MODE 1


/****************************************************************
 *** ACESS-FUNCTIONS ********************************************
 ***************************************************************/

//Reads and returns the temperature of the HDC2021 as a float for high precision
float Sensor_ReadTemp();

//Reads and returns the relative humidity of the HDC2021 as a float for high precision
float Sensor_ReadHumidity();



/**********************************************************************
 *** MANIPULATOR-FUNCTIONS ********************************************
 *********************************************************************/

void Sensor_Begin();

void Sensor_Reset();

void Sensor_TriggerMeasurement();

void Sensor_SetMeasurementRate(int Rate);

void Sensor_SetMeasurementMode(int Mode);

void Sensor_SetHumidityResolution(int Resolution);

void Sensor_SetTempResolution(int Resolution);























#endif /* HDC2021_H_ */
