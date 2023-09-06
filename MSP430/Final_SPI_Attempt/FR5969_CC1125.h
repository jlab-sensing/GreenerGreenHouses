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

void ConfigRegisters(uint8_t MODE);

void SendTx();
void PollRx(uint8_t MODE);
#endif /* FR5969_CC1125_H_ */
