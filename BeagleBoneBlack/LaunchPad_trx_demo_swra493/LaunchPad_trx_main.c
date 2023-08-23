/******************************************************************************
 *  Filename: LaunchPad_trx_main.c
 *
 *  Description: TRX_ui Range Test for various EVM boards and transcievers
 *  	         This wireless demo applications is meant to show the
 *  	         advantage of using. Frequency hopping Spread Spectrum (FHSS)
 *  	         to implement your wireless sensor network.
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
//#include "msp430.h"
#include "BBBREVC.h"
#include "stdio.h"
#include "radio_drv/radio_drv.h"
#include "radio_drv/cc1x_utils.h"
#include "radio_drv/hal_spi_rf.h"
#include "uart_drv/uart_drv.h"
#include "LaunchPad_trx_demo.h"

/******************************************************************************
 * LOCAL FUNCTIONS
 */
extern void msp_setup(void);
extern unsigned long volatile time_counter;

/******************************************************************************
 * GLOBALS
 */
char u_str[UART_BUFF_SIZE];
unsigned char txBuffer[TX_BUFF_SIZE];
char user_button_pushed;
unsigned char wakeup_on_wdt;
trx_cfg_struct trx_cfg;

/******************************************************************************
 * PAYLOAD
 */
const unsigned char rand_data[60] =  {49,231,121,199,255,153,138,232,220,203,
		51,253,117,172,161,191,79,58,225,215,149,251,15,163,153,236,141,172,3,
		186,224,37,224,210,75,69,117,58,153,207,61,203,19,125,76,90,143,226,11,
		208,16,72,109,217,100,12,128,228,185,142};


/******************************************************************************
 * @fn         main
 *
 * @brief      Main GUI application level control loop is implemented in the
 *             main loop. It is a state machine that cycles thru various states
 *             during the interactive use by the operator. The presents a text
 *             based GUI, the user is then promted to type in a command with
 *             a given set of parameters. The state machine then calls a simpler
 *             parser that tries to figure out what the user wants to do.
 *
 * input parameters
 *
 * @param       void
 *
 * output parameters
 *
 * @return      void
 *
 */
void main (void)
{

	char idle_counter = 0;
	unsigned char u_str_length;

	/*  Stop WDT */
	// WDTCTL = WDTPW + WDTHOLD;

	/* Setup MSP specific functions, IO's, timers and WDT */
	msp_setup();

	/* Initialize the UART port */
	hal_uart_init();

	/* enable uart echo function */
	uart_drv_toggle_echo();

	/* initialize the radio subsystem */
	trx_cfg.bit_rate = radio_init(1);
	trx_cfg.bit_rate = trx_cfg.bit_rate * 100;

	// Perform initial setup of the CC radio
	trx_cfg.b_length = TX_BUFF_SIZE;
	rf_default_setup(&trx_cfg);

	/* Configure LED ports */
	LED1_PxDIR |= LED1_PIN;
	LED2_PxDIR |= LED2_PIN;
	LED3_PxDIR |= LED3_PIN;
	LED4_PxDIR |= LED4_PIN;

	/* default all LEDs to off */
	HAL_LED1_OFF();
	HAL_LED2_OFF();
	HAL_LED3_OFF();
	HAL_LED4_OFF();

	/* Generally we use the WDT time wake the statemachine */
	wakeup_on_wdt = 1;

	/* indicator that button has been pressed */
	user_button_pushed = 0;

	/* Infinite loop with a 1 second timer */
	while(1)
	{

		/* Put MCU in low power mode, wait for UART and blink LED */
		HAL_LED2_OFF();
		_BIS_SR(LPM0_bits + GIE);
		HAL_LED2_ON();
		idle_counter++;

		/* Check to see if the user has pushed the putton and take appropriate action */
		if(user_button_pushed == 1)
		{
			user_button_pushed = 0;
			trx_cfg.trx_mode = MENU_RX_BER;
			// trx_cfg.trx_mode = MENU_RX_FHSS_BER;
		}

		/*
		 * For each idle loop (1 second) a counter is incremented, if check to see
		 * if we have had 60 idle loops, if so we enter a default action. This enables
		 * the board to automatically start doing something (used for becoming a
		 * reciever in a TX/RX BER system
		 */
		if((idle_counter>60) && trx_cfg.cc_state == CC_IDLE)
		{
			trx_cfg.trx_mode = MENU_TX_BER;
			// trx_cfg.trx_mode = MENU_TX_FHSS_BER;
			idle_counter = 0;
		}

		/*
		 *  Check to see if the UART driver has detected an end-of-line from the user
		 *  if we have an end-of-line event decode the command and take action
		 */
		if (uart_get_rx_end_of_str() == END_OF_LINE_DETECTED )
		{
			uart_reset_rx_end_of_str();
			idle_counter = 0;
			if(uart_get_rx_str_length() > 1)
			{
				trx_cfg.trx_mode = MENU_SETUP;
			} else {
				trx_cfg.trx_mode = MENU_IDLE;
			}
		}

		/*
		 *    Main loop of state machine
		 */
		switch(trx_cfg.trx_mode)
		{
		/* print the main menu to the UART buffer */
		case MENU_RESTART:
			main_menu(&trx_cfg);
			trx_cfg.trx_mode = MENU_IDLE;
			break;
		/* command string has been found on UART, parse it */
		case MENU_SETUP:
			u_str_length = uart_get_rx_str_length();       // get the number of bytes in fifo
			uart_get_str(u_str, u_str_length);             // retrieve all data
			parse_ui_cmd(&trx_cfg, u_str, u_str_length);
			break;
		/* blink led to indicate alive but idle state */
		case MENU_IDLE:
			HAL_LED1_TOGGLE();
			break;
		/* force idle on the RF subsystem and restart the statemachine */
		case MENU_RF_IDLE:
			trx_cfg.trx_mode = MENU_RESTART;
			trx_cfg.cc_state = CC_IDLE;
			break;
		/* FCC test case, enable unmodulated TX carrier */
		case MENU_TX_UNMOD:
			wakeup_on_wdt = 0;
			unmodulated_tx(&trx_cfg);
			trx_cfg.trx_mode = MENU_IDLE;
			trx_cfg.cc_state = CC_TX_ACTIVE;
			wakeup_on_wdt = 1;
			break;
		/* FCC test case, enable modulated TX carrier */
		case MENU_TX_nMCU:
			wakeup_on_wdt = 0;
			modulated_tx_no_mcu(&trx_cfg);
			trx_cfg.trx_mode = MENU_IDLE;
			trx_cfg.cc_state = CC_TX_ACTIVE;
			wakeup_on_wdt = 1;
			break;
		/* ETSI test case, enable RX mode to check for LO leakage */
		case MENU_RX_STATIC:
			wakeup_on_wdt = 0;
			rx_static(&trx_cfg);
			trx_cfg.trx_mode = MENU_IDLE;
			trx_cfg.cc_state = CC_RX_ACTIVE;
			wakeup_on_wdt = 1;
			break;
		/* Packet sniffer mode, print all date on UART port */
		case MENU_RX_SNIFF:
			wakeup_on_wdt = 0;
			rx_sniff(txBuffer, &trx_cfg);
			trx_cfg.trx_mode = MENU_RESTART;
			trx_cfg.cc_state = CC_IDLE;
			wakeup_on_wdt = 1;
			break;
		/* TX Packet error rate mode, non frequency hopping */
		case MENU_TX_BER:
			wakeup_on_wdt = 0;
			tx_ber_single(txBuffer, &trx_cfg);
			wakeup_on_wdt = 1;
			trx_cfg.trx_mode = MENU_RESTART;
			trx_cfg.cc_state = CC_IDLE;
			break;
		/* RX Packet error rate mode, non frequency hopping */
		case MENU_RX_BER:
			wakeup_on_wdt = 0;
			rx_ber_single(txBuffer, &trx_cfg);
			wakeup_on_wdt = 1;
			trx_cfg.trx_mode = MENU_RESTART;
			trx_cfg.cc_state = CC_IDLE;
			break;
		/* TX Packet error rate mode, with frequency hopping */
		case MENU_TX_FHSS_BER:
			wakeup_on_wdt = 0;
			tx_ber_fhss(txBuffer, &trx_cfg);
			wakeup_on_wdt = 1;
			trx_cfg.trx_mode = MENU_RESTART;
			trx_cfg.cc_state = CC_IDLE;
			break;
		/* RX Packet error rate mode, with frequency hopping */
		case MENU_RX_FHSS_BER:
			wakeup_on_wdt = 0;
			rx_ber_fhss(txBuffer, &trx_cfg);
			wakeup_on_wdt = 1;
			trx_cfg.trx_mode = MENU_RESTART;
			trx_cfg.cc_state = CC_IDLE;
			break;
		default:
			trx_cfg.trx_mode = MENU_RESTART;
			break;
		}
	}
}  


/******************************************************************************
 * @fn         wdt_isr
 *
 * @brief      Interrupt service routine for watch dog timer.
 *
 * input parameters
 *
 * @param       void
 *
 * output parameters
 *
 * @return      void
 *
 */
#pragma vector=WDT_VECTOR
__interrupt void wdt_isr (void)
{
	/* global "1-second" counter used for printing time stamped packet sniffer data */
	time_counter++;

	/* check to see if wake on wdt is enabled */
	if(wakeup_on_wdt == 1)
	{

		/* exit from low power mode on ISR exit */
		_BIC_SR_IRQ(LPM3_bits);
	}
}


/******************************************************************************
 * @fn         button_isr
 *
 * @brief      Interrupt service routine for button function
 *
 * input parameters
 *
 * @param       void
 *
 * output parameters
 *
 * @return      void
 *
 */
#pragma vector=BUTTON_VECTOR
__interrupt void button_isr(void)
{
	 /* reset the RF_GDO_PIN */
	BUTTON_PxIFG &= ~BUTTON_PIN;

	/* indicate button event */
	user_button_pushed = 1;

	/* exit from low power mode on ISR exit */
	_BIC_SR_IRQ(LPM3_bits);
}
