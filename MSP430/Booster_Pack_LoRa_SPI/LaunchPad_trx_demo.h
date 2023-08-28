/******************************************************************************
 *  Filename: LaunchPAD_TrxDemo.h
 *
 *  Description: TRX_ui Range Test for various EVM boards and transcievers
 *  	         This wireless demo applications is meant to show the
 *  	         advantage of using. Frequency hopping Spread Spectrum (FHSS)
 *  	         to implement your wireless sensor network. This code base
 *  	         has been developed to run on a number of TI devices including
 *  	         most MSP430F2x and MSP430F5x series microcontrolers using stand
 *               alone wireless transcievers (CC2500 and CC1101/CC1100).
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
#define DCO_MULT_1MHZ           30
#define DCO_MULT_4MHZ           122
#define DCO_MULT_8MHZ           244
#define DCO_MULT_12MHZ          366
#define DCO_MULT_16MHZ          488
#define DCO_MULT_20MHZ          610
#define DCO_MULT_25MHZ          763

#define DCORSEL_1MHZ            DCORSEL_2
#define DCORSEL_4MHZ            DCORSEL_4
#define DCORSEL_8MHZ            DCORSEL_4
#define DCORSEL_12MHZ           DCORSEL_5
#define DCORSEL_16MHZ           DCORSEL_5
#define DCORSEL_20MHZ           DCORSEL_6
#define DCORSEL_25MHZ           DCORSEL_7

// CC State machine definition
#define CC_BOOT        1
#define CC_IDLE        2
#define CC_SETUP       3
#define CC_TX_ACTIVE   4
#define CC_RX_ACTIVE   5
#define CC_RF_ACTIVE   6

// Memu system state machine variables
#define MENU_SETUP           20
#define MENU_RESTART         21
#define MENU_IDLE            22
#define MENU_RF_IDLE         23
#define MENU_TX_UNMOD        24
#define MENU_TX_nMCU         25
#define MENU_TX_wMCU         26
#define MENU_RX_STATIC       27
#define MENU_RX_SINGLE       28
#define MENU_RX_SNIFF        29
#define MENU_TX_BER          30
#define MENU_RX_BER          31
#define MENU_TX_FHSS_BER     32
#define MENU_RX_FHSS_BER     33


// Buffer sizes
#define UART_BUFF_SIZE 80
#define TX_BUFF_SIZE   64
#define RSSI_OFFSET    72

typedef struct trx_cfg {
  unsigned char trx_mode;            // mode of operation in progress
  unsigned char cc_state;            // lastest state of CC device
  unsigned char cc_device_id;        // ID from CC device (is it a CC1101 or CC2500)
  unsigned char smartrf_selector;    // Select Low, Mid or high data rate pre-config
  unsigned long start_freq;          // start frequency for all tasks
  unsigned char rf_channel;          // current RF channel
  unsigned int  ch_spc;              // channel spacing to be used by CC device
  unsigned int  no_burst;            // number of TX burst requested
  unsigned int  tx_pwr;              // actual TX power to be used
  unsigned long  bit_rate;            // TRX bitrate
  unsigned char b_length;            // burst length in bytes.
  unsigned int  packet_timer;
  unsigned int  normal_wait_timer;
  unsigned int  max_wait_timer;
  unsigned int  sync_timer;
  unsigned int  xtal_wait_timer;
} trx_cfg_struct;


void main_menu(trx_cfg_struct *trx_cfg);
char parse_ui_cmd(trx_cfg_struct *trx_cfg, char *ui_cmd, unsigned char ui_cmd_length);
void uartSendString(char *UART_Text);
void rf_default_setup(trx_cfg_struct *trx_cfg);
void rf_initial_setup(trx_cfg_struct *trx_cfg);
void rf_send_setup(trx_cfg_struct *trx_cfg);
void rf_get_setup(trx_cfg_struct *trx_cfg);
void unmodulated_tx(trx_cfg_struct *trx_cfg);
void modulated_tx_no_mcu(trx_cfg_struct *trx_cfg);
void rx_static(trx_cfg_struct *trx_cfg);
void tx_ber_single(unsigned char *txBuffer, trx_cfg_struct *trx_cfg);
void rx_ber_single(unsigned char *txBuffer, trx_cfg_struct *trx_cfg);
void tx_ber_fhss(unsigned char *txBuffer, trx_cfg_struct *trx_cfg);
void rx_ber_fhss(unsigned char *txBuffer, trx_cfg_struct *trx_cfg);
void rx_sniff(unsigned char *txBuffer, trx_cfg_struct *trx_cfg);
void print_rf_settings(void);
int calculate_rssi(unsigned char cc_rssi);
void generate_hopping_table(unsigned char *hop_table, unsigned char length_table);

