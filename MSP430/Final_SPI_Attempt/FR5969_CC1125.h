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

/*
 * Configure Registers: configures and sets registers found in CC1125 to correct modes given input
 * Param: MODE, the mode with which you want to control the CC1125, RX, TX, or continuous PACKET mode
*/
void ConfigRegisters(uint8_t MODE);

void SendTx();

void PollRx(uint8_t MODE);

uint32_t createPacket(uint16_t temp, uint16_t hum, uint8_t deviceID);
#endif /* FR5969_CC1125_H_ */
