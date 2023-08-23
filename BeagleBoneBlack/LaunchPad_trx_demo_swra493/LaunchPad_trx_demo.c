/******************************************************************************
 *  Filename: LaunchPad_trx_demo.c
 *
 *  Description: Range Test for various EVM boards and transcievers
 *  	         This wireless demo applications is meant to show the
 *  	         advantage of using. Frequency hopping Spread Spectrum (FHSS)
 *  	         to implement your wireless sensor network. This code base
 *  	         has been developed to run on a number of TI devices including
 *  	         most MSP430F2x and MSP430F5x series microcontrolers using stand
 *               alone wireless transcievers (CC1101, CC112x).
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

#include <cc1x_utils.h>
#include "stdio.h"
#include "stdlib.h"
#include "msp430.h"
#include "hal_timer.h"
#include "LaunchPad_trx_demo.h"
#include "uart_drv.h"
#include "hal_spi_rf.h"
#include "radio_drv.h"

/******************************************************************************
 * DEFINES - define the system ID and channel hopping scheme
 */
#define ENABLE_DEBUG_UART   TRUE       // display data over a UART link
#define MAX_HOP_CHANNELS    50         // Sets the number of channels
#define SYSTEM_ID           0          // 0 and 255
#define ENABLE_HOPPING      FALSE       // can be disable for debugging
#define ENABLE_TWO_WAY_LINK TRUE       // a reverse packet is expected
#define PRE_SYNC_CRC_LEN    10         // 10 bytes of preamble, sync, and CRC
#define MAX_PACKET_ERROR_COUNT    50   // after 50 dropped packets re-link

/******************************************************************************
 * EXTERNAL FUNCTIONS
 */
int ee_printf(const char *fmt, ...);
unsigned int hal_timer_get_time(unsigned long *sec, unsigned long *ms);

/******************************************************************************
 * INTERNAL FUNCTIONS
 */
void uartSendString(char *str);
unsigned char data_to_uart(unsigned char *data, unsigned char length);
void byte_to_hex(unsigned char byte, char *hex);
unsigned char str_to_data(char *str, unsigned int *data, unsigned char length);

/******************************************************************************
 * INTERNAL VARIABLES - state machine control
 */
char radio_mode;                                // statemachine control variable
char radio_mode_idle_count = 0;                 // timeout counter
unsigned char chan_hop_seq[MAX_HOP_CHANNELS];   // channels hopping sequence

/******************************************************************************
 * INTERNAL VARIABLES - state machine control
 */
extern char user_button_pushed;                 // user button has been pressed
extern const unsigned char rand_data[];         // pointer to predefined payload

/******************************************************************************
 * @fn         parse_ui_cmd
 *
 * @brief      Parses commands implementing a simple menu system on a terminal
 *
 * input parameters
 *
 * @param       trx_cfg_struct *trx_cfg    -  structure for control information
 *              char *ui_cmd               -  pointer to buffer from terminal
 *
 * output parameters
 *
 * @return      trx_cfg->trx_mode
 *
 */
char parse_ui_cmd(trx_cfg_struct *trx_cfg, char *ui_cmd, unsigned char ui_cmd_length)
{
	unsigned int data_s[4], line;
	unsigned long timer_values;


	str_to_data(ui_cmd, data_s, ui_cmd_length);
	line = data_s[0];
	switch(line)
	{
	case 1:                                              /* "Unmodulated TX" */
		trx_cfg->trx_mode  = MENU_TX_UNMOD;
		trx_cfg->cc_state  = CC_IDLE;
		trx_cfg->rf_channel = data_s[1];
		break;
	case 2:                                         /* "Modulated TX w. MCU" */
		trx_cfg->trx_mode  = MENU_TX_nMCU;
		trx_cfg->cc_state  = CC_IDLE;
		trx_cfg->rf_channel = data_s[1];
		break;
	case 3:                                         /* Modulated TX no MCU" */
		trx_cfg->trx_mode  = MENU_RX_STATIC;
		trx_cfg->cc_state  = CC_IDLE;
		trx_cfg->rf_channel = data_s[1];
		break;
	case 4:                                           /* " TX burst BER test" */
		trx_cfg->trx_mode  = MENU_TX_BER;
		trx_cfg->cc_state  = CC_IDLE;
		trx_cfg->rf_channel = data_s[1];
		trx_cfg->no_burst = data_s[2];
		break;
	case 5:                                           /* "RX burst BER test" */
		trx_cfg->trx_mode  = MENU_RX_BER;
		trx_cfg->cc_state  = CC_IDLE;
		trx_cfg->rf_channel = data_s[1];
		trx_cfg->no_burst = data_s[2];
		break;
	case 6:                                           /* "TX FHSS BER test" */
		trx_cfg->trx_mode  = MENU_TX_FHSS_BER;
		trx_cfg->cc_state  = CC_IDLE;
		trx_cfg->no_burst = data_s[1];
		break;
	case 7:                                           /* "RX FHSS BER test" */
		trx_cfg->trx_mode  = MENU_RX_FHSS_BER;
		trx_cfg->cc_state  = CC_IDLE;
		trx_cfg->no_burst = data_s[1];
		break;
	case 8:                                           /* " Packet Sniffer */
		trx_cfg->trx_mode  = MENU_RX_SNIFF;
		trx_cfg->cc_state  = CC_IDLE;
		trx_cfg->rf_channel = data_s[1];
		trx_cfg->b_length = data_s[2];
		break;
	case 9:                                           /* " SmartRF Studio selector" */
		trx_cfg->trx_mode  = MENU_RESTART;
		trx_cfg->cc_state  = CC_IDLE;
		trx_cfg->smartrf_selector = data_s[1];
		trx_cfg->bit_rate = radio_init(trx_cfg->smartrf_selector);
		trx_cfg->bit_rate = trx_cfg->bit_rate * 100;
		// use worst case packet length for calculations
		if(trx_cfg->bit_rate == 1200)
		{
			trx_cfg->b_length = 20;
		} else {
			trx_cfg->b_length = 64;
		}
		// master packet timing (assuming 32768 Hz ACLK)
		timer_values = trx_cfg->b_length+PRE_SYNC_CRC_LEN;
		timer_values = (timer_values*640000)/trx_cfg->bit_rate;
		trx_cfg->packet_timer = (unsigned int)timer_values;

		// packet timeout - if it has not happen, just turn off the RX.
		trx_cfg->normal_wait_timer = trx_cfg->packet_timer/2;

		// packet timeout - this setting is long enough to have at least 1 burst and
		trx_cfg->max_wait_timer = trx_cfg->packet_timer*3;

		// burst timing - This calibrates the timer to the burst duration and period
		timer_values = trx_cfg->b_length+PRE_SYNC_CRC_LEN;
		timer_values = (timer_values*256000)/trx_cfg->bit_rate;
		trx_cfg->sync_timer = (unsigned int)timer_values+32;

		// xtal statup wait - this values make the mcu wait for the xtal to start up
		trx_cfg->xtal_wait_timer = 32;

		break;
	case 10:                                          /* "9) Setup Radio page" */
		trx_cfg->trx_mode  = MENU_RESTART;
		trx_cfg->cc_state  = CC_IDLE;
		trx_cfg->start_freq = (unsigned long)data_s[1]*1000 + data_s[2];
		radio_set_freq(trx_cfg->start_freq);
		trx_cfg->ch_spc = data_s[3];
		break;
	default:
		trx_cfg->trx_mode  = MENU_RESTART;
		trx_cfg->cc_state  = CC_IDLE;
		break;
	}

	return trx_cfg->trx_mode;
}

/******************************************************************************
 * @fn         rf_default_setup
 *
 * @brief      read chip information to identity the specific device in circuit
 *
 * input parameters
 *
 * @param       trx_cfg_struct *trx_cfg    -  structure for control information
 *
 * output parameters
 *
 * @return      void
 *
 */
void rf_default_setup(trx_cfg_struct *trx_cfg)
{
	trx_cfg->trx_mode   = MENU_RESTART;
	trx_cfg->cc_state   = CC_IDLE;
	trx_cfg->no_burst   = 1000;
	trx_cfg->rf_channel = 0;
	trx_cfg->smartrf_selector = 1;
	trx_cfg->packet_timer = 16000;
	trx_cfg->normal_wait_timer = 8000;
	trx_cfg->max_wait_timer = 32000;
	trx_cfg->sync_timer = 6432;
	trx_cfg->xtal_wait_timer = 32;
	trx_cfg->b_length = 20;
	trx_cfg->start_freq = 902750;
	trx_cfg->ch_spc = 500;
	trx_cfg->cc_device_id = get_device_id();
}

/******************************************************************************
 * @fn         unmodulated_tx
 *
 * @brief      configure unmodulated TX mode
 *
 * input parameters
 *
 * @param       trx_cfg_struct *trx_cfg    -  structure for control information
 *
 * output parameters
 *
 * @return      void
 *
 */
void unmodulated_tx(trx_cfg_struct *trx_cfg)
{
	unsigned char payload = 255;

	// Make sure the radio is IDLE, then reprogram the registers for umodulated tx
	radio_idle();

	/* small delay */
	__delay_cycles(1000000);

	/* configure the tx frequency */
	radio_set_freq(trx_cfg->start_freq+(trx_cfg->ch_spc*trx_cfg->rf_channel));

	/* configure teh unmodulated test mode */
	set_tx_unmodulated_test_mode();

	/* add one byte to the FIFO */
	radio_prepare(&payload, 1);

	/* start the TX chain */
	radio_transmit();

	uartSendString("\n\r");
	uartSendString("Started unmodulated TX, Press RETURN key twice to stop\n\r");
	return;
}


/******************************************************************************
 * @fn         modulated_tx_no_mcu
 *
 * @brief      configure modulated TX mode
 *
 * input parameters
 *
 * @param       trx_cfg_struct *trx_cfg    -  structure for control information
 *
 * output parameters
 *
 * @return      void
 *
 */
void modulated_tx_no_mcu(trx_cfg_struct *trx_cfg)
{

	unsigned char payload = 255;

	// Make sure the radio is IDLE, then reprogram the registers for modulated tx
	radio_idle();

	/* small delay */
	__delay_cycles(1000000);

	/* configure the rx frequency to perform packet sniffing on */
	radio_set_freq(trx_cfg->start_freq+(trx_cfg->ch_spc*trx_cfg->rf_channel));

	set_tx_modulated_test_mode();

	/* add one byte to the FIFO */
	radio_prepare(&payload, 1);

	radio_transmit();

	uartSendString("\n\r");
	uartSendString("Started modulated TX using PN9 inside CC device\n\r");
	uartSendString("Press RETURN key twice to stop\n\r");
	return;
}


/******************************************************************************
 * @fn         rx_static
 *
 * @brief      configure continuous RX mode
 *
 * input parameters
 *
 * @param       trx_cfg_struct *trx_cfg    -  structure for control information
 *
 * output parameters
 *
 * @return      void
 *
 */
void rx_static(trx_cfg_struct *trx_cfg)
{

	/* configure the rx frequency to perform packet sniffing on */
	radio_set_freq(trx_cfg->start_freq+(trx_cfg->ch_spc*trx_cfg->rf_channel));

	radio_receive_on();
	uartSendString("\n\r");
	uartSendString("Started static RX, Press RETURN key twice to stop\n\r");
	return;
}


/******************************************************************************
 * @fn         main_menu
 *
 * @brief      displays the main menu text
 *
 * input parameters
 *
 * @param       trx_cfg_struct *trx_cfg    -  structure for control information
 *
 * output parameters
 *
 * @return      void
 *
 */
void main_menu(trx_cfg_struct *trx_cfg)
{
	unsigned int freq_mhz, freq_khz;

	uartSendString("\n\r");
	uartSendString("Long Range Sub1Ghz demonstration\n\r");
	uartSendString("Select from items below:\n\r");
	uartSendString("***********************************************************************\n\r");
	uartSendString(" 1) Continuous Unmodulated TX   (line, chan) eg.(1 25)\n\r");
	uartSendString(" 2) Continuous Modulated TX     (line, chan) eg.(2 25)\n\r");
	uartSendString(" 3) Static RX (RX leakage test) (line, chan) eg.(3 25)\n\r");
	uartSendString(" 4) TX Single Channel BER       (line, chan, pkt) eg.(4 25 1000)\n\r");
	uartSendString(" 5) RX Single Channel BER       (line, chan, pkt) eg.(5 25 1000)\n\r");
	uartSendString(" 6) TX freq. hopping BER        (line, pkt) eg.(6 1000)\n\r");
	uartSendString(" 7) RX freq. hopping BER        (line, pkt) eg.(7 1000)\n\r");
	uartSendString(" 8) RX sniff mode        (line, chan, len) eg.(8 25 20) len=0 > variable\n\r");
	uartSendString(" 9) SmartRF Selector     (line, 1=Low, 2=Med, 3=High) eg.(9 2)\n\r");
	uartSendString("10) Radio Setup          (line, freq, chan spc) eg. (10 902 750 500)\n\r");
	uartSendString("***********************************************************************\n\r");

	ee_printf("Current configuration: (Device = ");
	switch (trx_cfg->cc_device_id)
	{
	case DEV_UNKNOWN:
		ee_printf("Unknown)\n\r");
		break;
	case DEV_CC2500:
		ee_printf("CC2500)\n\r");
		break;
	case DEV_CC1100:
		ee_printf("CC1100)\n\r");
		break;
	case DEV_CC1101:
		ee_printf("CC1101)\n\r");
		break;
	case DEV_CC430x:
		ee_printf("CC430x)\n\r");
		break;
	case DEV_CC1125:
		ee_printf("CC1125)\n\r");
		break;
	case DEV_CC1120:
		ee_printf("CC1120)\n\r");
		break;
	case DEV_CC1121:
		ee_printf("CC1121)\n\r");
		break;
	case DEV_CC1175:
		ee_printf("CC1175)\n\r");
		break;
	}

	ee_printf("   Current configuration:\n\r");

	switch (trx_cfg->bit_rate)
	{
	case 1200:
		ee_printf("Config:  9 Low data rate => 1200bps, 4kHz dev, 25kHz RX BW \n\r");
		break;
	case 38400:
		ee_printf("Config:  9 Med data rate => 38.4kbps, 20kHz dev, 100kHz RX BW \n\r");
		break;
	case 50000:
		ee_printf("Config:  9 High data rate  => 50kbps, 25kHz dev, 100kHz RX BW \n\r");
		break;
	case 250000:
		ee_printf("Config:  9 High data rate  => 250kbps, 127kHz dev, 542kHz RX BW \n\r");
		break;
	default:
		ee_printf("Unknown)\n\r");
		break;
	}
	freq_mhz = (unsigned int)(trx_cfg->start_freq/1000);
	freq_khz = (unsigned int)(trx_cfg->start_freq - freq_mhz*1000);
	ee_printf("Freq  : 10 %03i %03i %3i\n\r", freq_mhz, freq_khz, trx_cfg->ch_spc);

	uartSendString("*************************************************************\n\r");
	uartSendString("CMD >\n\r");
	return;
}

/******************************************************************************
 * @fn         generate_hopping_table
 *
 * @brief      generate the table required to perform frequency hopping
 *
 * input parameters
 *
 * @param       unsigned char *hop_table    -  structure for hopping table
 *
 * output parameters
 *
 * @return      void
 *
 */
void generate_hopping_table(unsigned char *hop_table, unsigned char length_table)
{
	int channel_found,ii,jj;
	unsigned int chan_int;
	int rand_seed = SYSTEM_ID;

	/* if the rand_seed is positive generate a PN hopping table */
	if(ENABLE_HOPPING == TRUE)
	{

		/* start by placing the seed */
		srand(rand_seed);

		/* ii is the table index */
		for (ii=0;ii<length_table;ii++)
		{
			/* search for overlaps */
			channel_found = 1;

			while(channel_found > 0)
			{

				/* find a new random number */
				chan_int =  length_table * (rand()>>7);
				hop_table[ii] =  chan_int >> 8;
				channel_found = 0;

				/* check to see if already exists */
				for (jj=0;jj<ii;jj++)
				{
					if(hop_table[ii] == hop_table[jj]) channel_found++;
				}
			}
		}
	}
	else
	{
		/* generate a simple table of all the same values based on the negative input */
		for (ii=0;ii<length_table;ii++)
		{
			hop_table[ii] = rand_seed;
		}
	}

	return;
}

/******************************************************************************
 * @fn         tx_ber_fhss
 *
 * @brief      Perform RF burst transmit function with frequency hopping
 *
 * input parameters
 *
 * @param       trx_cfg_struct *trx_cfg    -  structure for control information
 *
 * output parameters
 *
 * @return      void
 *
 */
void tx_ber_fhss(unsigned char *txBuffer, trx_cfg_struct *trx_cfg)
{
	unsigned int bb, cc, dd;
	unsigned short rx_length, data_error;
	signed int rssi_forward, rssi_reverse, freq_error;
	unsigned int status, total_pkt_count;
	unsigned long error_forward, error_reverse;

	uartSendString("\n\r");
	uartSendString("Perform RF burst transmit function with frequency hopping\n\r");

	// Generate the frequency hopping sequence table that we will be using
	generate_hopping_table(chan_hop_seq, MAX_HOP_CHANNELS);

	data_to_uart(chan_hop_seq, MAX_HOP_CHANNELS);
	uartSendString("\n\r");

	// Set the packet length to a fixed packet size
	set_rf_packet_length(trx_cfg->b_length);

	HAL_LED1_OFF();                                             // Initialize LED1
	HAL_LED2_OFF();                                             // Initialize LED2

	error_forward = 0;
	error_reverse = 0;
	total_pkt_count = 0;

	// start the timer
	hal_timer_init(trx_cfg->packet_timer);
	// start transmitting burst, one on each of the MAX_HOP_CHANNELS channels in the PN sequence

	ee_printf("PKT CHAN FW-RSSI/ERR RW-RSSI/ERR\n\r");

	bb = 0;
	for(cc=0; cc<trx_cfg->no_burst; cc++)
	{

		/* update channel counter */
		if(bb-- == 0) bb=(MAX_HOP_CHANNELS-1);

		// enter low power mode and wait for TimerA1
		hal_timer_expire();

		// put some data into the payload
		txBuffer[0] =  SYSTEM_ID;                            // System ID
		txBuffer[1] = (cc>>8) & 0xFF;                        // Burst number (MSB)
		txBuffer[2] =  cc     & 0xFF;                        // Burst number (LSB)
		for(dd=3;dd<trx_cfg->b_length;dd++)
		{
			txBuffer[dd] = rand_data[dd];
		}
		// Transmit packet. The MCU does not exit this until the TX is complete.
		HAL_LED2_ON();
		radio_set_freq(trx_cfg->start_freq+(trx_cfg->ch_spc*chan_hop_seq[bb]));
		radio_send(txBuffer, trx_cfg->b_length);
		radio_wait_for_idle(0);         // 0 = no timeout, just wait
		HAL_LED2_OFF();

		if(ENABLE_TWO_WAY_LINK == TRUE)
		{
			HAL_LED2_ON();
			radio_receive_on();              // Change state to RX, receive packet
			// wait until end_of_packet is found or timeout (if packet is not found)
			status = radio_wait_for_idle(trx_cfg->normal_wait_timer);
			HAL_LED2_OFF();

			if(status < trx_cfg->normal_wait_timer)
			{
				rx_length = trx_cfg->b_length;
				radio_read(txBuffer, &rx_length);

				/* calculate the RSSI from the information from the RADIO registers */
				rssi_reverse = radio_get_rssi();
				freq_error = radio_freq_error();
				if(txBuffer[3] >= 128)
				{
					rssi_forward = -(256 - txBuffer[3]);
				} else {
					rssi_forward = txBuffer[3];
				}
				/* count the byte error in the incomming packet */
				data_error = 0;
				for(dd=5; dd<trx_cfg->b_length; dd++)
				{
					if( txBuffer[dd] != rand_data[dd] )
					{
						data_error++;
					}
				}
				dd = (txBuffer[1] << 8) + txBuffer[2];
				error_forward = error_forward + txBuffer[4];
				error_reverse = error_reverse + data_error;
				total_pkt_count++;
			}
			else
			{
				/* packet error hanppenned, blink red LED and flush FIFO */
				HAL_LED1_ON();
				__delay_cycles(1000);         // this is just so we can see the LED blink
				radio_idle();                 // Force IDLE state and Flush the RX FIFO's
				rssi_forward = 0;
				rssi_reverse = 0;
				data_error   = trx_cfg->b_length;
				error_forward = error_forward + data_error;
				error_reverse = error_reverse + data_error;
				total_pkt_count++;
				HAL_LED1_OFF();
			}
		}

#if ENABLE_DEBUG_UART == TRUE
		if(ENABLE_TWO_WAY_LINK == TRUE)
		{
			ee_printf("%4d %2d %3i %3i %3i %3i %3i\n\r", cc, chan_hop_seq[bb],
					rssi_forward, txBuffer[4], rssi_reverse, data_error, freq_error);
		} else {
			ee_printf("%4d %2d %3i\n\r", cc, chan_hop_seq[bb], freq_error);
		}
#endif
	}
	hal_timer_stop();

	radio_mode = RADIO_IDLE;

	ee_printf("Total packets Sent     : %5d\n\r", trx_cfg->no_burst);
	ee_printf("Total packets Received : %5d\n\r", total_pkt_count);
	ee_printf("Forward Error count    : %7ld\n\r", error_forward);
	ee_printf("Reverse Error count    : %7ld\n\r", error_reverse);

	return;
}


/******************************************************************************
 * @fn         rx_ber_fhss
 *
 * @brief      Perform RF burst receive function with frequency hopping
 *
 * input parameters
 *
 * @param            unsigned char *txBuffer
 *                   trx_cfg_struct *trx_cfg    -  structure for control information
 *
 * output parameters
 *
 * @return      void
 *
 */
void rx_ber_fhss(unsigned char *txBuffer, trx_cfg_struct *trx_cfg)
{
	int channel_index, mis_packet_counter, dd, rssi, freq_error, status;
	unsigned short rx_length;
	char char_rssi;
	unsigned char done = FALSE, cc_status;
	unsigned int pck_cnt = 0, pck_good_cnt = 0, max_wait_current, curr_pkt_id;


#if ENABLE_DEBUG_UART == TRUE

	uartSendString("\n\r");
	uartSendString("Perform RF burst receive function with frequency hopping\n\r");
#endif   

	// Generate the frequency hopping sequence table that we will be using
	generate_hopping_table(chan_hop_seq, MAX_HOP_CHANNELS );

	data_to_uart(chan_hop_seq, MAX_HOP_CHANNELS);
	uartSendString("\n\r");

	// Set the packet length to a fixed packet size
	set_rf_packet_length(trx_cfg->b_length);

	user_button_pushed = 0;

	// Initialize various control variable used in the FHSS algorithm
	channel_index = 0;      // determines the current channels index (lookup value)
	mis_packet_counter = 0;     // counts how many packets we have missed in a row

	// Sets the mode in which we operate:
	// trx_cfg->max_wait_timer; indicates that we are not locked to a basestation and we
	//                          need to perform adaptive seeking of basestation signal
	// trx_cfg->normal_wait_timer: We are locked to a basestation and should proceed in
	//                             normal operation
	max_wait_current = trx_cfg->max_wait_timer;   // sets the mode it which we operate

	// start the medium access control timer, this timer is used to figure out when
	// to wake up to receive a new burst.
	hal_timer_init(trx_cfg->packet_timer);

	HAL_LED1_ON();
	HAL_LED2_OFF();
	HAL_LED3_OFF();
	HAL_LED4_OFF();

	done = FALSE;
	while (done == FALSE)
	{
		// Wait for the next burst time slot

		hal_timer_expire();                 // wait for timer to expire

		/* update channel counter */
		if(channel_index-- == 0) channel_index=(MAX_HOP_CHANNELS-1);

		// Wake radio from sleep
		radio_idle();

		//hal_timer_wait(XTAL_START_WAIT);
		radio_set_freq(trx_cfg->start_freq+(trx_cfg->ch_spc*chan_hop_seq[channel_index]));

		HAL_LED1_ON();
		HAL_LED2_OFF();
		HAL_LED3_OFF();
		HAL_LED4_OFF();
		radio_receive_on();              // Change state to RX, receive packet

		// wait until end_of_packet is found, but with timeout (if packet is not found)
		status = radio_wait_for_idle(max_wait_current);
		HAL_LED1_OFF();

		// This case we have been waiting for a burst with RX continuesly running
		if(max_wait_current == trx_cfg->max_wait_timer)
		{
			// This means we have found a packet and should syncronize to it
			if(status < trx_cfg->max_wait_timer)
			{

				// Aligns timer for next burst to arrive
				hal_timer_adjust(trx_cfg->sync_timer);   // align the timer with burst

				pck_cnt = 1;                               // reset the counter for display

				max_wait_current = trx_cfg->normal_wait_timer;
				rx_length = trx_cfg->b_length;
				cc_status = radio_read(txBuffer, &rx_length);
				rssi = radio_get_rssi();

				if(cc_status > 0)
				{
					pck_good_cnt = 1;
					HAL_LED2_ON();
					char_rssi = (char)rssi;
					txBuffer[3] = (unsigned char)char_rssi;           // insert measurement in
					txBuffer[4] = 0;

					for(dd=5;dd<trx_cfg->b_length;dd++)               // count errors in data
					{
						if( txBuffer[dd] != rand_data[dd] )
						{
							txBuffer[4] = txBuffer[4] + 1;                // error count is byte 3
							txBuffer[dd] = rand_data[dd];                 // clean data for return
						}
					}

					if(ENABLE_TWO_WAY_LINK == TRUE)
					{
						radio_send(txBuffer, trx_cfg->b_length);  // standard packet send
					}
					curr_pkt_id = (txBuffer[1]<<8) + txBuffer[2];
#if ENABLE_DEBUG_UART == TRUE
					ee_printf("F:%d %d %i %d\n\r", channel_index, chan_hop_seq[channel_index],
							curr_pkt_id, txBuffer[3]);
#endif
					mis_packet_counter = 0;
				} else {
					pck_good_cnt = 0;
					HAL_LED1_ON();
				}
			}
		}

		// default setting is that we have been running a standard RX burst
		if( max_wait_current == trx_cfg->normal_wait_timer )
		{
			if(status <  max_wait_current )
			{
				pck_cnt++;
				mis_packet_counter = 0;
				hal_timer_adjust(trx_cfg->sync_timer);   // align the timer with burst

				rx_length = trx_cfg->b_length;
				cc_status = radio_read(txBuffer, &rx_length);         // read content of FIFO
				rssi = radio_get_rssi();
				freq_error = radio_freq_error();

				if(cc_status > 0)
				{
					pck_good_cnt++;
					HAL_LED2_ON();
				}
				else
				{
					HAL_LED1_ON();
				}
				char_rssi = (char)rssi;
				txBuffer[3] = (unsigned char)char_rssi;          // insert measurement in
				txBuffer[4] = 0;                                 // return data

				for(dd=5;dd<trx_cfg->b_length;dd++)              // count errors in data
				{
					if( txBuffer[dd] != rand_data[dd] )
					{
						txBuffer[4] = txBuffer[4] + 1;                // error count is byte 3
						txBuffer[dd] = rand_data[dd];                 // clean data for return
					}
				}
				if(ENABLE_TWO_WAY_LINK == TRUE) {

					radio_send(txBuffer, trx_cfg->b_length);  // standard packet send
				}
#if ENABLE_DEBUG_UART == TRUE
				curr_pkt_id = (txBuffer[1]<<8) + txBuffer[2];
				ee_printf("N: %d %d %i %d %d\n\r", channel_index, chan_hop_seq[channel_index],
						curr_pkt_id, rssi, freq_error);
#endif          
			}
			else
			{
				// Check to see if we have lost the connection and we need to stop and hold
				radio_idle();                          // force idle and flush fifos
				// if max_wait == 0 that means we are waiting for first sync burst to appear

				if(mis_packet_counter > MAX_PACKET_ERROR_COUNT)
				{
					max_wait_current = trx_cfg->max_wait_timer;
				}
				else
				{
					mis_packet_counter++;
				}
#if ENABLE_DEBUG_UART == TRUE
				ee_printf("M:%d %d\n\r", channel_index, chan_hop_seq[channel_index]);
#endif         
			}
		}
		// Check to see if the user button has been pressed, exit the rx_ber()
		if(user_button_pushed == 1)
		{
			user_button_pushed = 0;
			done = TRUE;
		}
	}
	hal_timer_stop();

	return;
}


/******************************************************************************
 * @fn         tx_ber_single
 *
 * @brief      Perform RF burst transmit function on a single channel
 *
 * input parameters
 *
 * @param       trx_cfg_struct *trx_cfg    -  structure for control information
 *
 * output parameters
 *
 * @return      void
 *
 */
void tx_ber_single(unsigned char *txBuffer, trx_cfg_struct *trx_cfg)
{
	unsigned int cc, dd;
	unsigned short rx_length, data_error;
	signed int rssi_forward, rssi_reverse, freq_error;
	unsigned int status, total_pkt_count;
	unsigned long error_forward, error_reverse;

	uartSendString("\n\r");
	uartSendString("Perform RF burst transmit function with fixed channel\n\r");

	// Set the packet length to a fixed packet size
	set_rf_packet_length(trx_cfg->b_length);

	/* configure the rx frequency to perform packet sniffing on */
	radio_set_freq(trx_cfg->start_freq+(trx_cfg->ch_spc*trx_cfg->rf_channel));

	HAL_LED1_OFF();                                             // Initialize LED1
	HAL_LED2_OFF();                                             // Initialize LED2

	error_forward = 0;
	error_reverse = 0;
	total_pkt_count = 0;

	// start the timer
	hal_timer_init(trx_cfg->packet_timer);

	// start transmitting burst
	ee_printf(" PKT FW-RSSI/ERR RW-RSSI/ERR FREQ_ERR\n\r");

	for(cc=0; cc<trx_cfg->no_burst; cc++)
	{

		// enter low power mode and wait for TimerA1
		hal_timer_expire();

		// put some data into the payload
		txBuffer[0] =  SYSTEM_ID;                            // System ID
		txBuffer[1] = (cc>>8) & 0xFF;                        // Burst number (MSB)
		txBuffer[2] =  cc     & 0xFF;                        // Burst number (LSB)
		for(dd=3;dd<trx_cfg->b_length;dd++)
		{
			txBuffer[dd] = rand_data[dd];
		}
		// Transmit packet. The MCU does not exit this until the TX is complete.
		HAL_LED2_ON();
		radio_send(txBuffer, trx_cfg->b_length);
		radio_wait_for_idle(0);         // 0 = no timeout, just wait
		HAL_LED2_OFF();

		if(ENABLE_TWO_WAY_LINK == TRUE)
		{
			HAL_LED2_ON();
			radio_receive_on();              // Change state to RX, receive packet
			// wait until end_of_packet is found or timeout (if packet is not found)
			status = radio_wait_for_idle(trx_cfg->normal_wait_timer);
			HAL_LED2_OFF();

			if(status < trx_cfg->normal_wait_timer)
			{

				rx_length = trx_cfg->b_length;
				radio_read(txBuffer, &rx_length);

				/* calculate the RSSI from the information from the RADIO registers */
				rssi_reverse = radio_get_rssi();
				freq_error = radio_freq_error();
				if(txBuffer[3] >= 128)
				{
					rssi_forward = -(256 - txBuffer[3]);
				} else {
					rssi_forward = txBuffer[3];
				}

				data_error = 0;
				for(dd=5; dd<trx_cfg->b_length; dd++){
					if( txBuffer[dd] != rand_data[dd] )
					{
						data_error++;
					}
				}
				dd = (txBuffer[1] << 8) + txBuffer[2];
				error_forward = error_forward + txBuffer[4];
				error_reverse = error_reverse + data_error;
				total_pkt_count++;
			}
			else
			{
				HAL_LED1_ON();
				__delay_cycles(1000);         // this is just so we can see the LED blink
				radio_idle();                 // Force IDLE state and Flush the RX FIFO's
				rssi_forward = 0;
				rssi_reverse = 0;
				data_error   = trx_cfg->b_length;
				error_forward = error_forward + data_error;
				error_reverse = error_reverse + data_error;
				total_pkt_count++;
				HAL_LED1_OFF();
			}
		}

#if ENABLE_DEBUG_UART == TRUE
		if(ENABLE_TWO_WAY_LINK == TRUE)
		{
			ee_printf("%4d %3i %3i     %3i %3i     %3i\n\r", cc, rssi_forward, txBuffer[4],
					rssi_reverse, data_error, freq_error);
		}
		else
		{
			ee_printf("%4d %3i\n\r", cc, freq_error);
		}
#endif
	}
	hal_timer_stop();

	radio_mode = RADIO_IDLE;

	ee_printf("Total packets Sent     : %5d\n\r", trx_cfg->no_burst);
	ee_printf("Total packets Received : %5d\n\r", total_pkt_count);
	ee_printf("Forward Error count    : %7ld\n\r", error_forward);
	ee_printf("Reverse Error count    : %7ld\n\r", error_reverse);

	return;
}


/******************************************************************************
 * @fn         rx_ber_single
 *
 * @brief      Perform RF burst receive function with frequency hopping
 *
 * input parameters
 *
 * @param            unsigned char *txBuffer
 *                   trx_cfg_struct *trx_cfg    -  structure for control information
 *
 * output parameters
 *
 * @return      void
 *
 */
void rx_ber_single(unsigned char *txBuffer, trx_cfg_struct *trx_cfg)
{
	int dd;
	unsigned short rx_length;
	unsigned char done = FALSE, cc_status;
	unsigned int pck_good_cnt = 0;
	int rssi, freq_error;
	char char_rssi;
	unsigned int curr_pkt_id;

#if ENABLE_DEBUG_UART == TRUE

	uartSendString("\n\r");
	uartSendString("Perform RF burst receive function with fixed channel\n\r");
#endif

	// Set the packet length to a fixed packet size
	set_rf_packet_length(trx_cfg->b_length);

	/* configure the rx frequency to perform packet sniffing on */
	radio_set_freq(trx_cfg->start_freq+(trx_cfg->ch_spc*trx_cfg->rf_channel));

	/* configure the timer for a 1 second tick */
	hal_timer_init(32768);

	user_button_pushed = 0;

	HAL_LED1_OFF();
	HAL_LED2_OFF();
	HAL_LED3_OFF();
	HAL_LED4_OFF();

	done = FALSE;

	/* Initialize the RX chain, receive packet */
	radio_receive_on();

	// start transmitting burst
	ee_printf(" PKT FW-RSSI/ERR FREQ_ERR\n\r");

	while (done == FALSE)
	{

		// wait until end_of_packet is found, no timeout
		radio_wait_for_idle(0);

		rx_length = trx_cfg->b_length;
		cc_status = radio_read(txBuffer, &rx_length);         // read content of FIFO

		if(cc_status > 0)
		{
			pck_good_cnt++;
			HAL_LED2_ON();
			rssi = radio_get_rssi();
			freq_error = radio_freq_error();
			if(ENABLE_TWO_WAY_LINK == TRUE)
			{
				char_rssi = (char)rssi;
				txBuffer[3] = (unsigned char)char_rssi;          // insert measurement in
				txBuffer[4] = 0;                                  // return data

				for(dd=5;dd<trx_cfg->b_length;dd++)              // count errors in data
				{
					if( txBuffer[dd] != rand_data[dd] )
					{
						txBuffer[4] = txBuffer[4] + 1;                // error count is byte 3
						txBuffer[dd] = rand_data[dd];                 // clean data for return
					}
				}

				radio_send(txBuffer, trx_cfg->b_length);  // standard packet send

				radio_wait_for_idle(0);         // 0 = no timeout, just wait
			}
		}
		else
		{
			HAL_LED1_ON();
			// Check to see if we have lost the connection and we need to stop and hold
			radio_idle();                          // force idle and flush fifos
			// if max_wait == 0 that means we are waiting for first sync burst to appear
		}

		/* Initialize the RX chain, receive packet */
		radio_receive_on();

#if ENABLE_DEBUG_UART == TRUE
			curr_pkt_id = (txBuffer[1]<<8) + txBuffer[2];
			ee_printf("%4d %3i %3i\n\r", curr_pkt_id, rssi, freq_error);
#endif

		// Check to see if the user button has been pressed, exit the rx_ber()
		if(user_button_pushed == 1)
		{
			user_button_pushed = 0;
			done = TRUE;
		}
	}

	return;
}


/******************************************************************************
 * @fn         rx_sniff
 *
 * @brief      Implements a simple packet sniffer printing all data on uart
 *
 * input parameters
 *
 * @param            unsigned char *txBuffer
 *                   trx_cfg_struct *trx_cfg    -  structure for control information
 *
 * output parameters
 *
 * @return      void
 *
 */
void rx_sniff(unsigned char *txBuffer, trx_cfg_struct *trx_cfg)
{
	unsigned int done;
	int rssi;
	unsigned short rx_length;
	unsigned long sec, ms;
	int cc_status;

	uartSendString("\n\r");
	uartSendString("Started RX sniff analyzer:\n\r");

	done = FALSE;

	/* if the packet length is 0, then configure variable packet length mode */
	if(trx_cfg->b_length > 0)
	{
		// Set the packet length to a fixed packet size
		set_rf_packet_length(trx_cfg->b_length);
	}
	else
	{
		/* re-initialize the radio, this reset the configuration to variable packet length */
		radio_init(trx_cfg->smartrf_selector);
		trx_cfg->b_length = TX_BUFF_SIZE;
	}

	/* configure the timer for a 1 second tick */
	hal_timer_init(32768);

	/* configure the rx frequency to perform packet sniffing on */
	radio_set_freq(trx_cfg->start_freq+(trx_cfg->ch_spc*trx_cfg->rf_channel));

	/* Initialize the RX chain, receive packet */
	radio_receive_on();

	while (done == FALSE)
	{

		HAL_LED3_OFF();
		HAL_LED4_OFF();

		// wait until end_of_packet is found, no timeout
		radio_wait_for_idle(0);
		HAL_LED4_ON();

		//get time passed in seconds and milliseconds
		hal_timer_get_time(&sec, &ms);

		// read content of FIFO
		rx_length = trx_cfg->b_length;
		cc_status = radio_read(txBuffer, &rx_length);
		rssi = radio_get_rssi();

		//re-start the receiver as fast as possible.
		radio_receive_on();

		if(cc_status > 0)
		{
			HAL_LED4_OFF();
			HAL_LED3_ON();
		}

#if ENABLE_DEBUG_UART == TRUE
		ee_printf("%4u.%03u: ", (unsigned int)sec, (unsigned int)ms);
		data_to_uart(txBuffer, rx_length);
		ee_printf("[%i]  \n\r", rssi);
#endif
	}
	return;
}


/******************************************************************************
 * @fn         uartSendString
 *
 * @brief      Implements a simple uart string sender by automatically finding
 *             the end of line delimeter and using it to call the uart sub
 *             functions
 *
 * input parameters
 *
 * @param            unsigned char *str
 *
 * output parameters
 *
 * @return      void
 *
 */
void uartSendString(char *str)
{
	unsigned char ii;

	for(ii=0;ii<UART_BUFF_SIZE;ii++)
	{
		if(str[ii] == 13)
		{
			uart_put_str(str, ii+1);
			ii = UART_BUFF_SIZE;
		}
	}

	return;
}

/******************************************************************************
 * @fn         data_to_uart
 *
 * @brief      Implements a simple data to hex converter by translating each
 *             incomming unsigned 8bit value into ascii hex. The function will
 *             add a space between each 8bit hex value to enable easy reading
 *
 * input parameters
 *
 * @param      unsigned char *data
 *             unsigned char length
 *
 * output parameters
 *
 * @return     unsigned char length - number of characters generated
 *
 */
unsigned char data_to_uart(unsigned char *data, unsigned char length)
{
	unsigned char dd;
	char str[3];

	for (dd=0; dd<length; dd++)
	{
		// check to see if the next byte is a valid hex character if so convert it
		byte_to_hex(data[dd], str);
		uart_put_char(str[0]);
		uart_put_char(str[1]);
		uart_put_char(' ');
	}
	return dd;
}

/******************************************************************************
 * @fn         byte_to_hex
 *
 * @brief      Implements a simple data to hex converter by translating each
 *             incomming unsigned 8bit value into ascii hex.
 *
 * input parameters
 *
 * @param      unsigned char byte
 *             char *hex
 *
 * output parameters
 *
 * @return     void
 *
 */
void byte_to_hex(unsigned char byte, char *hex)
{
	unsigned char tmp;
	unsigned char ii;

	tmp = (byte & 0xF0)>>4;
	for (ii=0; ii<2; ii++)
	{
		if(tmp < 10)
		{
			hex[ii] = tmp + '0';
		}
		else
		{
			hex[ii] = tmp - 10 + 'A';
		}
		tmp = (byte & 0x0F);
	}
	return;
}

/******************************************************************************
 * @fn         chars_to_data
 *
 * @brief      Implements a simple str to data converter by translating each
 *             incomming char value into unsigned 16bit int. The function will
 *             look for space's between each value to identify new values.
 *
 * input parameters
 *
 * @param      unsigned char *data
 *             char *str
 *             unsigned char length
 *
 * output parameters
 *
 * @return     unsigned char length - number of integers generated
 *
 */
unsigned int chars_to_data(char *str, unsigned char length)
{
	unsigned int cc;
	unsigned char dd, tmp;

	cc = 0;
	for (dd=0; dd<length; dd++)
	{
		tmp = str[dd];
		cc = 10 * cc;
		if((tmp >= '0') && (tmp <= '9'))
		{
			cc = cc + (tmp -'0');
		}
	}
	return cc;
}

/******************************************************************************
 * @fn         str_to_data
 *
 * @brief      Implements a simple str to data converter by translating each
 *             incomming char value into unsigned 16bit int. The function will
 *             look for space's between each value to identify new values.
 *
 * input parameters
 *
 * @param      unsigned char *data
 *             char *str
 *             unsigned char length
 *
 * output parameters
 *
 * @return     unsigned char length - number of integers generated
 *
 */
unsigned char str_to_data(char *str, unsigned int *data, unsigned char length)
{
	unsigned char cc, dd, ee;

	cc = 0;
	ee = 0;
	for (dd=0; dd<length; dd++)
	{
		if(str[dd] == ' ' || str[dd] == 13) {
			data[ee++] = chars_to_data(&str[cc], dd-cc);
			cc = dd;
		}
	}
	return cc;
}

