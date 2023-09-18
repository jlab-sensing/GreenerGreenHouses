/******************************************************************************
*  Filename: hal_spi_rf_trxeb.c
*
*  Description: Implementation file for common spi access with the CCxxxx 
*               tranceiver radios using trxeb. Supports CC1101/CC112X radios
*
*  Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
*
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*******************************************************************************/


/******************************************************************************
 * INCLUDES
 */
// #include "hal_types.h"
// #include "hal_defs.h"
#include <stdint.h>
#include "hal_spi_rf_trxeb.h"

#include "SPI.h"
// #include <linux/spi/spidev.h>
#include <stdio.h>

static int spiFileDesc = -1; // from main.c

static uint8_t txBuffer[SPI_BUFFER_SIZE];
static uint8_t rxBuffer[SPI_BUFFER_SIZE];

/******************************************************************************
 * LOCAL FUNCTIONS
 */
// static void trxReadWriteBurstSingle(uint8_t addr,uint8_t *pData,uint16_t len) ;

/******************************************************************************
 * FUNCTIONS
 */

/******************************************************************************
 * @fn          trxRfSpiInterfaceInit
 *
 * @brief       Function to initialize TRX SPI. CC1101/CC112x is currently
 *              supported. The supported prescalerValue must be set so that
 *              SMCLK/prescalerValue does not violate radio SPI constraints.
 *
 * input parameters
 *
 * @param       prescalerValue - SMCLK/prescalerValue gives SCLK frequency
 *
 * output parameters
 *
 * @return      void
 */
int trxRfSpiInterfaceInit(char* spiDevice, int mode, int freqHz)
{
    // int spiFileDesc = 0;
    if (freqHz < 0){
        printf("trxRfSpiInterfaceInit(): freqHz must be greater than 0.\n");
    }
    spiFileDesc = SPI_initPort(spiDevice, mode, freqHz);
    if (spiFileDesc < 0) {
		printf("Error: Can't open device %s", spiDevice);
        return 0;
    }
    
    for (int i = 0; i < SPI_BUFFER_SIZE; i++){
        txBuffer[i] = 0;
        rxBuffer[i] = 0;
    }
    return spiFileDesc;
}

int trxRfSpiInterfaceClose(void)
{
    return SPI_closePort(spiFileDesc);
}


/*******************************************************************************
 * @fn          trx8BitRegAccess
 *
 * @brief       This function performs a read or write from/to a 8bit register
 *              address space. The function handles burst and single read/write
 *              as specfied in addrByte. Function assumes that chip is ready.
 *
 * input parameters
 *
 * @param       accessType - Specifies if this is a read or write and if it's
 *                           a single or burst access. Bitmask made up of
 *                           RADIO_BURST_ACCESS/RADIO_SINGLE_ACCESS/
 *                           RADIO_WRITE_ACCESS/RADIO_READ_ACCESS.
 * @param       addrByte - address byte of register.
 * @param       pData    - data array
 * @param       len      - Length of array to be read(TX)/written(RX)
 *
 * output parameters
 *
 * @return      chip status
 */
rfStatus_t trx8BitRegAccess(uint8_t accessType, uint8_t addrByte, uint8_t *pData, uint16_t len)
{
    // Prepare txBuffer for transmission
    txBuffer[0] = accessType | addrByte;
    if (txBuffer[0] & RADIO_READ_ACCESS){  // read (write 0x00)
        for (int i = 0; i < len; i++){
            txBuffer[i + 1] = 0;
        }
    }else{                          // write (from pData)
        for (int i = 0; i < len; i++){
            txBuffer[i + 1] = pData[i];
        }
    }
    
    SPI_transfer(spiFileDesc, txBuffer, rxBuffer, len + 1);
    if (txBuffer[0] & RADIO_READ_ACCESS){  // read
        for (int i = 0; i < len; i++){ // Write to pData
            pData[i] = rxBuffer[i + 1];
        }
    }else{                          // write (from pData)
        // do not overwrite pData
    }
    
    /* return the status byte value */
    return rxBuffer[0];
}

/******************************************************************************
 * @fn          trx16BitRegAccess
 *
 * @brief       This function performs a read or write in the extended adress
 *              space of CC112X.
 *
 * input parameters
 *
 * @param       accessType - Specifies if this is a read or write and if it's
 *                           a single or burst access. Bitmask made up of
 *                           RADIO_BURST_ACCESS/RADIO_SINGLE_ACCESS/
 *                           RADIO_WRITE_ACCESS/RADIO_READ_ACCESS.
 * @param       extAddr - Extended register space address = 0x2F.
 * @param       regAddr - Register address in the extended address space.
 * @param       *pData  - Pointer to data array for communication
 * @param       len     - Length of bytes to be read/written from/to radio
 *
 * output parameters
 *
 * @return      rfStatus_t
 */
rfStatus_t trx16BitRegAccess(uint8_t accessType, uint8_t extAddr, uint8_t regAddr, uint8_t *pData, uint8_t len)
{
    // Prepare txBuffer for transmission
    txBuffer[0] = accessType | extAddr;
    txBuffer[1] = regAddr;
    if (txBuffer[0] & RADIO_READ_ACCESS){  // read (write 0x00)
        for (int i = 0; i < len; i++){
            txBuffer[i + 2] = 0;
        }
    }else{                          // write (from pData)
        for (int i = 0; i < len; i++){
            txBuffer[i + 2] = pData[i];
        }
    }
    // printf("SPI_transfer with len %d\n", len+2);
    SPI_transfer(spiFileDesc, txBuffer, rxBuffer, len + 2);
    if (txBuffer[0] & RADIO_READ_ACCESS){  // read
        for (int i = 0; i < len; i++){ // Write to pData
            pData[i] = rxBuffer[i + 2];
        }
    }else{                          // write (from pData)
        // do not overwrite pData
    }
    
    /* return the status byte value */
    return rxBuffer[0];
}

/*******************************************************************************
 * @fn          trxSpiCmdStrobe
 *
 * @brief       Send command strobe to the radio. Returns status byte read
 *              during transfer of command strobe. Validation of provided
 *              is not done. Function assumes chip is ready.
 *
 * input parameters
 *
 * @param       cmd - command strobe
 *
 * output parameters
 *
 * @return      status byte
 */
rfStatus_t trxSpiCmdStrobe(uint8_t cmd)
{
    // Prepare txBuffer for transmission
    txBuffer[0] = cmd;
    
    SPI_transfer(spiFileDesc, txBuffer, rxBuffer, 1);
    
    /* return the status byte value */
    return rxBuffer[0];
}

/*******************************************************************************
 * @fn          trxReadWriteBurstSingle
 *
 * @brief       When the address byte is sent to the SPI slave, the next byte
 *              communicated is the data to be written or read. The address
 *              byte that holds information about read/write -and single/
 *              burst-access is provided to this function.
 *
 *              Depending on these two bits this function will write len bytes to
 *              the radio in burst mode or read len bytes from the radio in burst
 *              mode if the burst bit is set. If the burst bit is not set, only
 *              one data byte is communicated.
 *
 *              NOTE: This function is used in the following way:
 *
 *              TRXEM_SPI_BEGIN();
 *              while(TRXEM_PORT_IN & TRXEM_SPI_MISO_PIN);
 *              ...[Depending on type of register access]
 *              trxReadWriteBurstSingle(uint8_t addr,uint8_t *pData,uint16_t len);
 *              TRXEM_SPI_END();
 *
 * input parameters
 *
 * @param       none
 *
 * output parameters
 *
 * @return      void
 */
// static void trxReadWriteBurstSingle(uint8_t addr,uint8_t *pData,uint16_t len)
// {
	// uint16_t i;
	// /* Communicate len number of bytes: if RX - the procedure sends 0x00 to push bytes from slave*/
  // if(addr&RADIO_READ_ACCESS)
  // {
    // if(addr&RADIO_BURST_ACCESS)
    // {
      // for (i = 0; i < len; i++)
      // {
          // TRXEM_SPI_TX(0);            /* Possible to combining read and write as one access type */
          // TRXEM_SPI_WAIT_DONE();
          // *pData = TRXEM_SPI_RX();     /* Store pData from last pData RX */
          // pData++;
      // }
    // }
    // else
    // {
      // TRXEM_SPI_TX(0);
      // TRXEM_SPI_WAIT_DONE();
      // *pData = TRXEM_SPI_RX();
    // }
  // }
  // else
  // {
    // if(addr&RADIO_BURST_ACCESS)
    // {
      // /* Communicate len number of bytes: if TX - the procedure doesn't overwrite pData */
      // for (i = 0; i < len; i++)
      // {
        // TRXEM_SPI_TX(*pData);
        // TRXEM_SPI_WAIT_DONE();
        // pData++;
      // }
    // }
    // else
    // {
      // TRXEM_SPI_TX(*pData);
      // TRXEM_SPI_WAIT_DONE();
    // }
  // }
  // return;
// }