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
#include <msp430.h>
#include "hal_types.h"
#include "hal_defs.h"
#include "hal_spi_rf_trxeb.h"

/******************************************************************************
 * LOCAL FUNCTIONS
 */
static void trxReadWriteBurstSingle(uint8 addr, uint8 *pData, uint16 len);

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
void trxRfSpiInterfaceInit(uint8 prescalerValue)
{

    /* Keep peripheral in reset state*/
    UCA1CTL1 |= UCSWRST;

    /* Configuration
     * -  8-bit
     * -  Master Mode
     * -  3-pin
     * -  synchronous mode
     * -  MSB first
     * -  Clock phase select = captured on first edge
     * -  Inactive state is low
     * -  SMCLK as clock source
     * -  Spi clk is adjusted corresponding to systemClock as the highest rate
     *    supported by the supported radios: this could be optimized and done
     *    after chip detect.
     */
    UCA1CTLW0 = 0x00 + UCMST + UCSYNC + UCMODE_0 + UCMSB + UCCKPH + UCSSEL_2;
    // UCB0CTL1 |=  UCSSEL_2;

    UCA1BRW = 0x00;
    UCA1BRW = prescalerValue;

    ///* Configuring UCB0BR0
    // * Set up spi clk to comply with the maximum spi clk speed for the radios
    // * according to userguides. Takes the slowest spi clk into account.
    // */
    //switch(systemClock)
    //{
    //  case 0:
    //    /* Do not divide SMCLK */
    //    UCB0BR0 = 0x01;
    //    break;
    //  case 1:
    //    /* Do not divide SMCLK */
    //    UCB0BR0 = 0x01;
    //    break;
    //  case 2:
    //    /* Divide SMCLK by 2*/
    //    UCB0BR0 = 0x02;
    //    break;
    //  case 3:
    //    /* Divide SMCLK by 2*/
    //    UCB0BR0 = 0x02;
    //    break;
    //  case 4:
    //    /* Divide SMCLK by 3*/
    //    UCB0BR0 = 0x03;
    //    break;
    //  case 5:
    //    /* Divide SMCLK by 4*/
    //    UCB0BR0 = 0x04;
    //    break;
    //  case 6:
    //    /* Divide SMCLK by 4*/
    //    UCB0BR0 = 0x04;
    //    break;
    //  default:
    //    /* Divide SMCLK by 4*/
    //    UCB0BR0 = 0x04;
    //    break;
    //}

    /* Configure port and pins
     * - MISO/MOSI/SCLK GPIO controlled by peripheral
     * - CS_n GPIO controlled manually, set to 1
     */

    TRXEM_PORT_SEL0 &= ~(TRXEM_SPI_MOSI_PIN + TRXEM_SPI_MISO_PIN);
    TRXEM_PORT_SEL1 |= TRXEM_SPI_MOSI_PIN + TRXEM_SPI_MISO_PIN;

    TRXEM_PORT_CS_SEL0 &= ~BIT3;
    TRXEM_PORT_CS_SEL1 &= ~BIT3;

    P2SEL0 &= ~BIT4;
    P2SEL1 |= BIT4;

    TRXEM_PORT_OUT |= TRXEM_SPI_MISO_PIN;/* Pullup on MISO */
    TRXEM_PORT_CS_OUT |= TRXEM_SPI_SC_N_PIN;

    TRXEM_PORT_CS_DIR |= TRXEM_SPI_SC_N_PIN;

//  /* In case not automatically set */
//  TRXEM_PORT_DIR |= TRXEM_SPI_MOSI_PIN + TRXEM_SPI_SCLK_PIN;
//  TRXEM_PORT_DIR &= ~TRXEM_SPI_MISO_PIN;
//  P2OUT |= BIT2;

    /* Release for operation */
    UCA1CTL1 &= ~UCSWRST;
    return;
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
rfStatus_t trx8BitRegAccess(uint8 accessType, uint8 addrByte, uint8 *pData,
                            uint16 len)
{
    uint8 readValue;

    /* Pull CS_N low and wait for SO to go low before communication starts */
    TRXEM_SPI_BEGIN();
    while (TRXEM_PORT_IN & TRXEM_SPI_MISO_PIN)
        ;
    /* send register address byte */
    TRXEM_SPI_TX(accessType | addrByte);
    TRXEM_SPI_WAIT_DONE();
    /* Storing chip status */
    readValue = TRXEM_SPI_RX();
    trxReadWriteBurstSingle(accessType | addrByte, pData, len);
    TRXEM_SPI_END();
    /* return the status byte value */
    return (readValue);
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
rfStatus_t trx16BitRegAccess(uint8 accessType, uint8 extAddr, uint8 regAddr,
                             uint8 *pData, uint8 len)
{
    uint8 readValue;

    TRXEM_SPI_BEGIN();
    while (TRXEM_PORT_IN & TRXEM_SPI_MISO_PIN)
        ;
    /* send extended address byte with access type bits set */
    TRXEM_SPI_TX(accessType | extAddr);
    TRXEM_SPI_WAIT_DONE();
    /* Storing chip status */
    readValue = TRXEM_SPI_RX();
    TRXEM_SPI_TX(regAddr);
    TRXEM_SPI_WAIT_DONE();
    /* Communicate len number of bytes */
    trxReadWriteBurstSingle(accessType | extAddr, pData, len);
    TRXEM_SPI_END();
    /* return the status byte value */
    return (readValue);
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
rfStatus_t trxSpiCmdStrobe(uint8 cmd)
{
    uint8 rc;
    TRXEM_SPI_BEGIN();
    while (TRXEM_PORT_IN & TRXEM_SPI_MISO_PIN)
        ;
    TRXEM_SPI_TX(cmd);
    TRXEM_SPI_WAIT_DONE();
    rc = TRXEM_SPI_RX();
    TRXEM_SPI_END();
    return (rc);
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
 *              trxReadWriteBurstSingle(uint8 addr,uint8 *pData,uint16 len);
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
static void trxReadWriteBurstSingle(uint8 addr, uint8 *pData, uint16 len)
{
    uint16 i;
    /* Communicate len number of bytes: if RX - the procedure sends 0x00 to push bytes from slave*/
    if (addr & RADIO_READ_ACCESS)
    {
        if (addr & RADIO_BURST_ACCESS)
        {
            for (i = 0; i < len; i++)
            {
                TRXEM_SPI_TX(0); /* Possible to combining read and write as one access type */
                TRXEM_SPI_WAIT_DONE();
                *pData = TRXEM_SPI_RX(); /* Store pData from last pData RX */
                pData++;
            }
        }
        else
        {
            TRXEM_SPI_TX(0);
            TRXEM_SPI_WAIT_DONE();
            *pData = TRXEM_SPI_RX();
        }
    }
    else
    {
        if (addr & RADIO_BURST_ACCESS)
        {
            /* Communicate len number of bytes: if TX - the procedure doesn't overwrite pData */
            for (i = 0; i < len; i++)
            {
                TRXEM_SPI_TX(*pData);
                TRXEM_SPI_WAIT_DONE();
                pData++;
            }
        }
        else
        {
            TRXEM_SPI_TX(*pData);
            TRXEM_SPI_WAIT_DONE();
        }
    }
    return;
}
