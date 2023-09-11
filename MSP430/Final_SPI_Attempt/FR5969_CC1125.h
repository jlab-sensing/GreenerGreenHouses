/*
 * FR5969_CC1125.h
 *
 *  Created on: Sep 1, 2023
 *      Author: matth
 */

#ifndef FR5969_CC1125_H_
#define FR5969_CC1125_H_

#include <stdint.h>

#define RX_MODE 0 //continuous Rx
#define TX_MODE 1 //continuous Tx
#define PACKET_MODE 2 //packet mode, same for Rx and Tx
#define DEVICE_ID 0x0A //IOT Tag device
/*
 * Configure Registers: configures and sets registers found in CC1125 to correct modes given input
 * Param: MODE, the mode with which you want to control the CC1125, RX, TX, or continuous PACKET mode
*/
void ConfigRegisters(uint8_t MODE);

void manualCalibration(void);

void PollRx(uint8_t MODE);

//takes address of packet to send, temperature value, humidity value, and device ID
// and fills Pkt with correct information to be sent over CC1125 module
void createPacket(uint8_t *Pkt, uint16_t temp, uint16_t hum, uint8_t deviceID);

void InitTxTimer(void);
#endif /* FR5969_CC1125_H_ */
