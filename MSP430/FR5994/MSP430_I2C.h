/*
 * MSP430_I2C.h
 * Header file for implementation of I2C communication with the MSP430FR5969
 * Adapted from TI's msp430fr59xx_eusci_i2c_standard_master example
 * Written in Code Composer Studio 12.4
 * Created on: Aug 17, 2023
 * Author: Matthew Kaltman
 * Last Modified: 8/21/23
 */

#ifndef MSP430_I2C_H_
#define MSP430_I2C_H_

#include <stdint.h>



/****************************************************************
 *** CONFIGURATION-DEFINES **************************************
 ***************************************************************/

#define MAX_BUFFER_SIZE     20          //size of internal Rx/Tx buffer in bytes

#define STD_MSG_LENGTH      1           //size of message being sent/received, typically 1 byte


// Enum for I2C statemachine
typedef enum I2C_ModeEnum{
    IDLE_MODE,
    NACK_MODE,
    TX_REG_ADDRESS_MODE,
    RX_REG_ADDRESS_MODE,
    TX_DATA_MODE,
    RX_DATA_MODE,
    SWITCH_TO_RX_MODE,
    SWITHC_TO_TX_MODE,
    TIMEOUT_MODE
} I2C_Mode;

/*
 * @function I2C_Controller_WriteReg
 *
 * For peripheral device with dev_addr, writes the data specified in reg_data pointer
 *
 * @param dev_addr:                     uint8_t Peripheral device address
 * @param reg_addr:                     uint8_t Destination register address
 * @param reg_data:                     uint8_t pointer to register data
 * @param count:                        uint8_t length of reg_data array in bytes
 *
 * @return                              I2C_Mode status
 */
I2C_Mode I2C_Controller_WriteReg(uint8_t dev_addr, uint8_t reg_addr, uint8_t *reg_data, uint8_t count);


/*
 * @function I2C_Controller_ReadReg
 *
 * For peripheral device with dev_addr, read the data specified in peripherals reg_addr
 * The received data is available in Receive Buffer
 *
 * @param dev_addr:                     uint8_t Peripheral device address
 * @param reg_addr:                     uint8_t Source register address
 * @param count:                        uint8_t Length of data to read from
 *
 * @return                              I2C_Mode status
 */
I2C_Mode I2C_Controller_ReadReg(uint8_t dev_addr, uint8_t reg_addr, uint8_t count);

/*
 * Copies the data read from peripheral from the Rx buffer to array
 * *source: Rx buffer
 * *dest: Array to store data
 * count: length of array
 */

/*
 * @function CopyRxArray
 *
 * Copies data read from peripheral from the RX buffer to given destination array
 *
 * @param dest:                         uint8_t Pointer to destination array for data storing
 * @param count:                        uint8_t Length of array
 */
void CopyRxArray(uint8_t *dest, uint8_t count);


/*
 * @function initGPIO
 *
 * Clears GPIO output latch and configures p1.7 and p1.6 as SCL and SDA respectively
 */
void initGPIO(void);


/*
 * @function initClockTo16MHz
 *
 * Configures one FRAM wait-state as required by the device datasheet for MCLK
 * operation beyond 8MHz _before_ configuring the clock system
 */
void initClockTo16MHz(void);


/*
 * @function initI2C
 *
 * Enables I2C interrupts and sets initial peripheral address
 *
 *@param dev_add:                       uint8_t Address of peripheral device
 */
void initI2C(uint8_t dev_add);


void InitTxTimer(void);

#endif /* MSP430_I2C_H_ */
