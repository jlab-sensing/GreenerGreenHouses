/******************************************************************************
 *  Filename: hal_mcu.c
 *
 *  Description: Configuration of MCU core registers
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

#include "msp430.h"
#include "hal_spi_rf.h"

#if defined (__MSP430F5438A__)
/*******************************************************************************
 * @brief Setup all the peripherals of the MSP430, set the CPU speed to 16MHz,
 *        enable the 32KHz and configure WDT for a 1 sec tick speed.
 *
 *        (MSP430F5438 version)
 *
 * @param  none
 *
 * @return none
 *******************************************************************************/
void msp_setup(void) {

	BUTTON_DIR  	&= ~BUTTON_PIN;           // Set output direction
	BUTTON_OUT 		=   BUTTON_PIN;           // Set output direction
	BUTTON_PxIE  	|=  BUTTON_PIN;           // interrupt enabled
	BUTTON_PxIES 	|=  BUTTON_PIN;           // Hi/lo edge
	BUTTON_REN 		|=  BUTTON_PIN;           // Pull up resistor
	BUTTON_PxIFG 	&= ~BUTTON_PIN;           // IFG cleared

	// Setup the XTAL ports to use the external 32K oscillilator
	P7SEL |= 0x03;                            // Select XT1
	UCSCTL6 |= XCAP_3;                        // Internal load cap

	// Loop until XT1,XT2 & DCO stabilizes
	do  {
		UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG);
		// Clear XT2,XT1,DCO fault flags
		SFRIFG1 &= ~OFIFG;                      // Clear fault flags
	} while (SFRIFG1&OFIFG);                  // Test oscillator fault flag
	UCSCTL6 &= ~(XT1DRIVE_3);                 // Xtal is now stable, reduce drive

	// Set up clock system on MCU to fit your system
	// Target specific implementation
	UCSCTL0 = 0x00;                           // Set lowest possible DCOx, MODx
	UCSCTL1 = DCORSEL_6;                      // Select suitable range
	UCSCTL2 = 488;                            // DCO = 488 * 32768Hz ~= 16MHz
	UCSCTL4 = SELA__XT1CLK | SELS__DCOCLK | SELM__DCOCLK ;

	// Setup Watch dog timer for 1 second tick using 32Khz XTAL on MSP430F5438A
	WDTCTL = WDT_ADLY_1000;                    // WDT 15.6ms, ACLK, interval timer
	SFRIE1 |= WDTIE;                           // Enable WDT interrupt
}

#endif

#if defined (__MSP430F5529__)
/*******************************************************************************
 * @brief Setup all the peripherals of the MSP430, set the CPU speed to 16MHz,
 *        enable the 32KHz and configure WDT for a 1 sec tick speed.
 *
 *        (MSP430F5529 version)
 *
 * @param  none
 *
 * @return none
 *******************************************************************************/
void msp_setup(void) {

	// Enable the interupts on port 2 to catch the user button (TRXEB)

	BUTTON_DIR   &= ~BUTTON_PIN;       // input direction
	BUTTON_OUT   |=  BUTTON_PIN;       // set high on port
	BUTTON_PxIE  |=  BUTTON_PIN;       // enable interupt
	BUTTON_PxIES |=  BUTTON_PIN;       // Hi/lo edge
	BUTTON_REN   |=  BUTTON_PIN;       // Pull up resistor
	BUTTON_PxIES &= ~BUTTON_PIN;       // IFG cleared

	// Setup the XTAL ports to use the external 32K oscillilator
	P5SEL |= BIT4+BIT5;                            // Select XT1
	UCSCTL6 |= XCAP_3;                             // Internal load cap

	// Loop until XT1,XT2 & DCO stabilizes
	do  {
		UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);
		// Clear XT2,XT1,DCO fault flags
		SFRIFG1 &= ~OFIFG;                      // Clear fault flags
	} while (SFRIFG1&OFIFG);                  // Test oscillator fault flag
	UCSCTL6 &= ~(XT1DRIVE_3);                 // Xtal is now stable, reduce drive

	// Set up clock system on MCU to fit your system
	// Target specific implementation
	UCSCTL0 = 0x00;                           // Set lowest possible DCOx, MODx
	UCSCTL1 = DCORSEL_6;                      // Select suitable range
	UCSCTL2 = 488;                            // DCO = 488 * 32768Hz ~= 16MHz
	UCSCTL4 = SELA__XT1CLK | SELS__DCOCLK | SELM__DCOCLK ;

	// Setup Watch dog timer for 1 second tick using 32Khz XTAL on MSP430F5438A
	WDTCTL = WDT_ADLY_1000;                    // WDT 15.6ms, ACLK, interval timer
	SFRIE1 |= WDTIE;                           // Enable WDT interrupt
}

#endif


#if defined (__MSP430G2553__)
/*******************************************************************************
 * @brief Setup all the peripherals of the MSP430, set the CPU speed to 16MHz,
 *        enable the 32KHz and configure WDT for a 1 sec tick speed.
 *
 *        (MSP430G2553 version)
 *
 * @param  none
 *
 * @return none
 *******************************************************************************/
void msp_setup(void) {

	BUTTON_DIR  	&= ~BUTTON_PIN;           // Set output direction
	BUTTON_OUT 		=   BUTTON_PIN;           // Set output direction
	BUTTON_PxIE  	|=  BUTTON_PIN;           // interrupt enabled
	BUTTON_PxIES 	|=  BUTTON_PIN;           // Hi/lo edge
	BUTTON_REN 		|=  BUTTON_PIN;           // Pull up resistor
	BUTTON_PxIFG 	&= ~BUTTON_PIN;           // IFG cleared

	// set system clock to 16MHz
	DCOCTL  = CALDCO_16MHZ;
	BCSCTL1 = CALBC1_16MHZ;

	 // Setup Watch dog timer for a 1 second tick using a 32KHz external XTAL
	 BCSCTL1 |= DIVA_0;                        // ACLK/1 = 32.768KHz
	 WDTCTL = WDT_ADLY_1000;                   // WDT 1s interval timer
	 IE1 |= WDTIE;                             // Enable WDT interrupt

}
#endif
