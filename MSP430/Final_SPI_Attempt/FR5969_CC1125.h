/*
 * FR5969_CC1125.h
 *
 *  Created on: Sep 1, 2023
 *      Author: matth
 */

#ifndef FR5969_CC1125_H_
#define FR5969_CC1125_H_

#include <stdint.h>

#define RX_MODE 0
#define TX_MODE 1

void ConfigRegisters(uint8_t MODE);

#endif /* FR5969_CC1125_H_ */
