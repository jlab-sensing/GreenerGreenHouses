/*
 * HDC2021.h
 * Header file for implementation of HDC2021 RH/T Sensor via MSP430EXPFR5969
 * Written in Code Composer Studio 12.4
 * Created on: Aug 17, 2023
 * Author: Matthew Kaltman, Tim Kraemer
 * Last Modified: 8/24/23
 */

#ifndef HDC2021_H_
#define HDC2021_H_


/****************************************************************
 *** CONFIGURATION-DEFINES **************************************
 ***************************************************************/

#define HDC2021_ADDRESS 0x40

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



/****************************************************************
 *** ACESS-FUNCTIONS ********************************************
 ***************************************************************/

//Reads and returns the temperature of the HDC2021 as a float for high precision
float Sensor_ReadTemp(void);

//Reads and returns the relative humidity of the HDC2021 as a float for high precision
float Sensor_ReadHumidity(void);

//Reads and returns the Temperature Hi [8] and Temperature Lo registers [8],
//storing and returning as concatenated integer [16]
uint16_t Sensor_ReadRawTemp(void);


//Reads and returns the Humidity Hi [8] and Humidity Lo registers [8],
//storing and returning as concatenated integer [16]
uint16_t Sensor_ReadRawHumidity(void);




/****************************************************************
 *** MANIPULATOR-FUNCTIONS **************************************
 ***************************************************************/

/*
 *Sets bit 7 of CONFIG register to trigger soft reset,
 *Run at the beginning of initialization to clear registers
 */
void Sensor_Reset(void);

/*
 * Sets bit 0 of the measurement CONFIG register to enable measurements,
 * Run only after setting rate, mode, and resolutions
 */
void Sensor_TriggerMeasurement(void);

/*
 * Sets the rate at which the sensor is polled
 * 1s,5s,10s,1min,5min,manual
 */
void Sensor_SetMeasurementRate(int Rate);

/*
 * Sets the measurement mode of the sensor
 * RH , T , RH/T
 */
void Sensor_SetMeasurementMode(int Mode);

/*
 * Sets humidity reading resolution:
 * 9b,11b,14b
 */
void Sensor_SetHumidityResolution(int Resolution);

/*
 * Sets temperature reading resolution:
 * 9b,11b,14b
 */
void Sensor_SetTempResolution(int Resolution);

/*
 * Sets a temperature offset
 * offset: 8 bit offset value for Temperature measurement
 */
void setTempOffsetAdjust(uint8_t offset);

/*
 * Sets a humidity offset
 * offset: 8 bit offset value for Humidity measurement
 */
void setHumidityOffsetAdjust(uint8_t offset);

/*
 * Returns the temperature offset set in the TEMP_OFFSET_ADJUST register
 */
uint8_t returnTempOffset(void);

/*
 * Returns the humidity offset set inthe HUM_OFFSET_ADJUST register
 */
uint8_t returnHumidityOffset(void);

/*
 * Enables the heating element of the HDC2021 sensor
 */
void enableHeater(void);

/*
 * Disables the heating element of the HDC2021 sensor
 */
void disableHeater(void);




#endif /* HDC2021_H_ */
