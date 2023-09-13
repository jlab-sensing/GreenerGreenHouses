/*
 * FR5969_CC1125.h
 *
 * Specific library for setup of the CC1125 RF module by Texas Instruments, including custom packet creator and unpacker
 *
 *  Created on: Sep 1, 2023
 *      Author: matth
 */

#ifndef FR5969_CC1125_H_
#define FR5969_CC1125_H_

#include <stdint.h>

#define RX_MODE 0           //continuous Rx
#define TX_MODE 1           //continuous Tx
#define PACKET_MODE 2       //packet mode, same for Rx and Tx
#define DEVICE_ID 0x0A      //IOT Tag device


/*
 * @function ConfigRegisters
 *
 * Configures and sets registers found in CC1125 to correct modes given input, register configuration
 * determined using Texas Instrument's RF Studio set to preferred settings
 *
 * @param MODE:         The mode with which you want to control the CC1125
 *                      - RX: Continuous RX mode
 *                      - TX: Continuous TX mode
 *                      - PACKET: predefined packet size in RX and TX mode
 *
 */
void ConfigRegisters(uint8_t MODE);


/*
 * @function manualCalibration
 *
 * Calibrates the CC1125 FR module to ensure correct Tx/Rx setup, function provided by Texas Instruments
 */
void manualCalibration(void);


/*
 * @function createPacket
 *
 * Constructs a specific data packet containing temperature and humidity
 * data from HDC2021 sensor, and deviceID for FR transmission to BBB
 * 
 * @param Pkt:          pointer to uint8_t packet array
 * @param temp:	        14 bit raw temperature value
 * @param hum:          14 bit raw humidity value
 * @param deviceID      4 bit deviceID, custom to micro-C
 */
void createPacket(uint8_t *packet, uint16_t temp, uint16_t hum, uint8_t deviceID);

/*
 * @function InitTXTimer
 *
 * Initializes ACLK to roll-over every 1s and leave low-power mode for sensor read/CC1125 Tx
 */
void InitTxTimer(void);


#endif /* FR5969_CC1125_H_ */
