/******************************************************************************
 *  Filename: hal_spi_rf.c
 *
 *  Description: Implementation file for common spi access with the CCxxxx
 *               transceiver radios using trxeb. Supports CC1101/CC112X radios
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
#include "hal_defs.h"
#include "hal_types.h"
// #include "msp430.h"
#include "hal_spi_rf.h"


/******************************************************************************
 * LOCAL FUNCTIONS
 */
static void trxReadWriteBurstSingle(uint8 addr,uint8 *pData,uint16 len) ;


/******************************************************************************
 * FUNCTIONS
 */

#if defined (__MSP430G2553__)

/******************************************************************************
 * @fn          void trxRfSpiInterfaceInit_exp430g2(uint8 prescalerValue)
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

	// 1) Set USCI in reset state
	UCB0CTL1 |= UCSWRST;

	// 2) Init USCI registers with UCSWRST = 1
	UCB0CTL0  =  0x00+UCMST + UCSYNC + UCMODE_0 + UCMSB + UCCKPH;
	UCB0CTL1 |=  UCSSEL_3;
	//data rate:
	UCB0BR1   =  0x00;
	UCB0BR0   =  prescalerValue; // division factor of clock source
	// 3) Configure ports
	// MISO -> P1.6
	// MOSI -> P1.7
	// SCLK -> P1.5
	// CS_N -> manualy set. (XOUT P2.7)

	// select bit RF_MISO_PIN, RF_MOSI_PIN, RF_SCLK as SPI peripheral
	RF_PORT_SEL  |= RF_MISO_PIN + RF_MOSI_PIN + RF_SCLK_PIN;
	RF_PORT_SEL2 |= RF_MISO_PIN + RF_MOSI_PIN + RF_SCLK_PIN;
	// and set the correct direction on the port
	RF_PORT_DIR |= RF_MOSI_PIN + RF_SCLK_PIN;
	RF_PORT_DIR &= ~RF_MISO_PIN;

	// select chip select bit RF_CS_N_PORT_SEL as a port
	RF_CS_N_PORT_SEL &= ~RF_CS_N_PIN;
	RF_CS_N_PORT_DIR |= RF_CS_N_PIN;
	RF_CS_N_PORT_OUT |= RF_CS_N_PIN;

	// configure the GDO line as GPIO style input on the MSP430
	RF_GDO_SEL &= ~RF_GDO_PIN;
	RF_GDO_DIR &= ~RF_GDO_PIN;
	RF_GDO_OUT &= ~RF_GDO_PIN;

	// 4) Clear UCSWRST. Release for operation
	UCB0CTL1 &= ~UCSWRST;
	// 5) Enable interrupts UCxRXIE and UCxTXIE

	return;
}
#endif

#if defined (__MSP430F5438A__) || defined (__MSP430F5529__)

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
	UCB0CTL1 |= UCSWRST;

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
	UCB0CTL0  =  0x00+UCMST + UCSYNC + UCMODE_0 + UCMSB + UCCKPH;
	UCB0CTL1 |=  UCSSEL_2;
	UCB0BR1   =  0x00;

	UCB0BR0 = prescalerValue;

	// select bit RF_MISO_PIN, RF_MOSI_PIN, RF_SCLK as peripheral
	RF_PORT_SEL |= RF_MISO_PIN + RF_MOSI_PIN + RF_SCLK_PIN;
	// and set the correct direction on the port
	RF_PORT_DIR |= RF_MOSI_PIN + RF_SCLK_PIN;
	RF_PORT_DIR &= ~RF_MISO_PIN;

	// select chip select bit RF_CS_N_PORT_SEL as a port
	RF_CS_N_PORT_SEL &= ~RF_CS_N_PIN;
	RF_CS_N_PORT_DIR |= RF_CS_N_PIN;
	RF_CS_N_PORT_OUT |= RF_CS_N_PIN;

	/* Release for operation */
	UCB0CTL1 &= ~UCSWRST;
	return;
}

#endif


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
rfStatus_t trx8BitRegAccess(uint8 accessType, uint8 addrByte, uint8 *pData, uint16 len)
{
	uint8 readValue;

	/* Pull CS_N low and wait for SO to go low before communication starts */
	RF_SPI_BEGIN();
	while(RF_PORT_IN & RF_MISO_PIN);
	/* send register address byte */
	RF_SPI_TX(accessType|addrByte);
	RF_SPI_WAIT_DONE();
	/* Storing chip status */
	readValue = RF_SPI_RX();
	trxReadWriteBurstSingle(accessType|addrByte,pData,len);
	RF_SPI_END();
	/* return the status byte value */
	return(readValue);
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
rfStatus_t trx16BitRegAccess(uint8 accessType, uint8 extAddr, uint8 regAddr, uint8 *pData, uint8 len)
{
	uint8 readValue;

	RF_SPI_BEGIN();
	while(RF_PORT_IN & RF_MISO_PIN);
	/* send extended address byte with access type bits set */
	RF_SPI_TX(accessType|extAddr);
	RF_SPI_WAIT_DONE();
	/* Storing chip status */
	readValue = RF_SPI_RX();
	RF_SPI_TX(regAddr);
	RF_SPI_WAIT_DONE();
	/* Communicate len number of bytes */
	trxReadWriteBurstSingle(accessType|extAddr,pData,len);
	RF_SPI_END();
	/* return the status byte value */
	return(readValue);
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
	RF_SPI_BEGIN();
	while(RF_PORT_IN & RF_MISO_PIN);
	RF_SPI_TX(cmd);
	RF_SPI_WAIT_DONE();
	rc = RF_SPI_RX();
	RF_SPI_END();
	return(rc);
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
 *              RF_SPI_BEGIN();
 *              while(RF_PORT_IN & RF_SPI_MISO_PIN);
 *              ...[Depending on type of register access]
 *              trxReadWriteBurstSingle(uint8 addr,uint8 *pData,uint16 len);
 *              RF_SPI_END();
 *
 * input parameters
 *
 * @param       none
 *
 * output parameters
 *
 * @return      void
 */
static void trxReadWriteBurstSingle(uint8 addr,uint8 *pData,uint16 len)
{
	uint16 i;
	/* Communicate len number of bytes: if RX - the procedure sends 0x00 to push bytes from slave*/
	if(addr&RADIO_READ_ACCESS)
	{
		if(addr&RADIO_BURST_ACCESS)
		{
			for (i = 0; i < len; i++)
			{
				RF_SPI_TX(0);            /* Possible to combining read and write as one access type */
				RF_SPI_WAIT_DONE();
				*pData = RF_SPI_RX();     /* Store pData from last pData RX */
				pData++;
			}
		}
		else
		{
			RF_SPI_TX(0);
			RF_SPI_WAIT_DONE();
			*pData = RF_SPI_RX();
		}
	}
	else
	{
		if(addr&RADIO_BURST_ACCESS)
		{
			/* Communicate len number of bytes: if TX - the procedure doesn't overwrite pData */
			for (i = 0; i < len; i++)
			{
				RF_SPI_TX(*pData);
				RF_SPI_WAIT_DONE();
				pData++;
			}
		}
		else
		{
			RF_SPI_TX(*pData);
			RF_SPI_WAIT_DONE();
		}
	}
	return;
}
