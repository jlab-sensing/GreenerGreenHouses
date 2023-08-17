/*
 * MSP430_I2C.h
 * Header file for implementation of I2C communication with the MSP430FR5969
 * Adapted from TI's msp430fr59xx_eusci_i2c_standard_master example
 * Written in Code Composer Studio 12.4
 * Created on: Aug 17, 2023
 * Author: Matthew Kaltman
 * Last Modified: 8/17/23
 */

#ifndef MSP430_I2C_H_
#define MSP430_I2C_H_

#include <stdint.h>




/****************************************************************
 *** CONFIGURATION-DEFINES **************************************
 ***************************************************************/

//size of internal Rx/Tx buffer in bytes
#define MAX_BUFFER_SIZE     20

//size of message being sent/received, typically 1 byte
#define STD_MSG_LENGTH      1


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

///* ReceiveBuffer: Buffer used to receive data in the ISR
// * RXByteCtr: Number of bytes left to receive
// * ReceiveIndex: The index of the next byte to be received in ReceiveBuffer
// * TransmitBuffer: Buffer used to transmit data in the ISR
// * TXByteCtr: Number of bytes left to transfer
// * TransmitIndex: The index of the next byte to be transmitted in TransmitBuffer
// * */
// uint8_t ReceiveBuffer[MAX_BUFFER_SIZE] = {0};
// uint8_t RXByteCtr = 0;
// uint8_t ReceiveIndex = 0;
// uint8_t TransmitBuffer[MAX_BUFFER_SIZE] = {0};
// uint8_t TXByteCtr = 0;
// uint8_t TransmitIndex = 0;


/* For peripheral device with dev_addr, writes the data specified in *reg_data
 *
 * dev_addr: The peripheral device address.
 * reg_addr: The register to write to.
 * *reg_data: The buffer to write
 * count: The length of *reg_data in bytes
 *  */
I2C_Mode I2C_Controller_WriteReg(uint8_t dev_addr, uint8_t reg_addr, uint8_t *reg_data, uint8_t count);



/* For peripheral device with dev_addr, read the data specified in peripherals reg_addr.
 * The received data is available in ReceiveBuffer
 * dev_addr: The peripheral device address.
 * reg_addr: The register to read from.
 * count: The length of data to read
 *  */
I2C_Mode I2C_Controller_ReadReg(uint8_t dev_addr, uint8_t reg_addr, uint8_t count);

/*
 * Copies the data read from peripheral from the Rx buffer to array
 * *source: Rx buffer
 * *dest: Array to store data
 * count: length of array
 */
void CopyArray(uint8_t *source, uint8_t *dest, uint8_t count);

/*
 * Clears GPIO output latch and configures
 * p1.7 and p1.6 as SCL and SDA respectively
 */
void initGPIO(void);


/*
 * Configure one FRAM waitstate as required by the device datasheet for MCLK
 * operation beyond 8MHz _before_ configuring the clock system.
 */
void initClockTo16MHz(void);

/*
 * Enables I2C interrupts and sets initial peripheral address
 */
void initI2C(uint8_t dev_add);


#endif /* MSP430_I2C_H_ */
