/*
 * HDC2021.c
 *
 *  Created on: Aug 17, 2023
 *      Author: matth
 */

#include <stdlib.h>
#include "HDC2021.h"
#include "MSP430_I2C.h"

#define HDC2021_ADDRESS 0x40
#define TEMP_LO_REG 0x00
#define TEMP_HI_REG 0x01
#define HUMIDITY_LO_REG 0x02
#define HUMIDITY_HI_REG 0x03
#define CONFIG_REG 0x0E
#define MEAS_CONFIG_REG 0x0F
