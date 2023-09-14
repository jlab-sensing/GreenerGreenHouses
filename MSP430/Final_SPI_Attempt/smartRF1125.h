/*
 * smartRF1125.h
 *
 *  Created on: Sep 1, 2023
 *      Author: matth
 */

#ifndef SMARTRF1125_H_
#define SMARTRF1125_H_

#include "hal_spi_rf_trxeb.h"
#include "cc112x_spi.h"

#define PACKET_LEN          0x04

//RX mode preferred register settings
static const registerSetting_t ETSI_CAT1_869_S1_Rx[] = {
 {CC112X_IOCFG3,            0xB0},                                  //GPIO3 Pin Configuration
 {CC112X_IOCFG2,            0x08},                                  //GPIO2 Pin Configuration
 {CC112X_IOCFG1,            0xB0},                                  //GPIO1 Pin Configuration
 {CC112X_IOCFG0,            0x09},                                  //GPIO0 Pin Configuration
 {CC112X_SYNC3,             0xAA},                                  //Sync3 Word Configuration
 {CC112X_SYNC2,             0xAA},                                  //Sync2 Word Configuration
 {CC112X_SYNC1,             0xAA},                                  //Sync1 Word Configuration
 {CC112X_SYNC0,             0xAA},                                  //Sync0 Word Configuration
 {CC112X_SYNC_CFG1,         0x1F},                                  //Sync Word Detection Configuration Reg. 1
 {CC112X_DEVIATION_M,       0xA3},                                  //Sync Word Length Configuration Reg. 0
 {CC112X_MODCFG_DEV_E,      0x0A},                                  //Modulation Format and Frequency Deviation Configuration
 {CC112X_DCFILT_CFG,        0x1C},                                  //Digital DC Removal Configuration
 {CC112X_PREAMBLE_CFG1,     0x00},                                  //Preamble Length Configuration Reg. 1
 {CC112X_FREQ_IF_CFG,       0x33},                                  //RX Mixer Frequency Configuration
 {CC112X_IQIC,              0xC6},                                  //Digital Image Channel Compensation Configuration
 {CC112X_CHAN_BW,           0x10},                                  //Channel Filter Configuration
 {CC112X_MDMCFG1,           0x06},                                  //General Modem Parameter Configuration Reg. 1
 {CC112X_MDMCFG0,           0x0A},                                  //General Modem Parameter Configurationn Reg. 0
 {CC112X_SYMBOL_RATE2,      0x3F},                                  //Symbol Rate Configuration Exponent and Mantissa [19:16]
 {CC112X_SYMBOL_RATE1,      0x75},                                  //Symbol Rate Configuration Mantissa [15:8]
 {CC112X_SYMBOL_RATE0,      0x10},                                  //Symbol Rate Configuration Mantissa [7:0]
 {CC112X_AGC_REF,           0x20},                                  //AGC Reference Level Configuration
 {CC112X_AGC_CS_THR,        0x19},                                  //Carrier Sense Threshold Configuration
 {CC112X_AGC_CFG1,          0x0A},                                  //Automatic Gain Control Configuration Reg. 1
 {CC112X_AGC_CFG0,          0xCF},                                  //Automatic Gain Control Configuration Reg. 0
 {CC112X_FIFO_CFG,          0x00},                                  //FIFO Configuration
 {CC112X_SETTLING_CFG,      0x03},                                  //Frequency Synthesizer Calibration and Settling Configuration
 {CC112X_FS_CFG,            0x12},                                  //Frequency Synthesizer Configuration
 {CC112X_PKT_CFG2,          0x05},                                  //Packet Configuration Reg. 2
 {CC112X_PKT_CFG1,          0x00},                                  //Packet Configuration Reg. 1
 {CC112X_PKT_CFG0,          0x20},                                  //Packet Configuratiion Reg. 0
 {CC112X_IF_MIX_CFG,        0x00},                                  //IF Mix Configuration
 {CC112X_FREQOFF_CFG,       0x22},                                  //Frequency Offset COrrection Configuration
 {CC112X_FREQ2,             0x56},                                  //Frequency Configuration [23:16]
 {CC112X_FREQ1,             0xEC},                                  //Frequency Configuration [15:8]
 {CC112X_FREQ0,             0x28},                                  //Frequency Configuration [7:0]
 {CC112X_IF_ADC0,           0x05},                                  //Analog to Digital Converter Configuration Reg. 0
 {CC112X_FS_DIG1,           0x00},                                  //Frequency Synthesizer Digital Reg. 1
 {CC112X_FS_DIG0,           0x5F},                                  //Frequency Synthesizer Digital Reg. 0
 {CC112X_FS_CAL0,           0x0E},                                  //Frequency Synthesizer Calibration Reg. 0
 {CC112X_FS_DIVTWO,         0x03},                                  //Frequency Synthesizer Divide by 2
 {CC112X_FS_DSM0,           0x33},                                  //FS Digital Synthesizer Module Configuration Reg. 0
 {CC112X_FS_DVC0,           0x17},                                  //Frequency Synthesizer Divider Chain Configuration Reg. 1
 {CC112X_FS_PFD,            0x50},                                  //Frequency Synthesizer Phase Frequency Detector Configuration
 {CC112X_FS_PRE,            0x6E},                                  //Frequency Synthesizer Prescaler Configuration
 {CC112X_FS_REG_DIV_CML,    0x14},                                  //Frequency Synthesizer Divider Regulator Configuration
 {CC112X_FS_SPARE,          0xAC},                                  //Frequency Synthesizer Spare
 {CC112X_XOSC5,             0x0E},                                  //Crystal Oscillator Configuration Reg. 5
 {CC112X_XOSC3,             0xC7},                                  //Crystal Oscillator Configuration Reg. 3
 {CC112X_XOSC1,             0x07},                                  //Crystal Oscillator Configuration Reg. 1
 {CC112X_PARTNUMBER,        0x58},                                  //Part Number
 {CC112X_PARTVERSION,       0x21},                                  //Part Revision
 {CC112X_SERIAL_STATUS,     0x08},                                  //Serial Status
 {CC112X_MODEM_STATUS1,     0x10},                                  //Modem Status Reg. 1
 {CC112X_XOSC_TEST1,        0x00},                                  //Crystal Oscillator Test Reg. 1
};

//TX mode preferred register settings
static const registerSetting_t ETSI_CAT1_869_S1_Tx[] = {
{CC112X_IOCFG3,             0xB0},
{CC112X_IOCFG2,             0x08},
{CC112X_IOCFG1,             0xB0},
{CC112X_IOCFG0,             0x09},
{CC112X_SYNC_CFG1,          0x08},
{CC112X_DEVIATION_M,        0xA3},
{CC112X_MODCFG_DEV_E,       0x0A},
{CC112X_DCFILT_CFG,         0x1C},
{CC112X_PREAMBLE_CFG1,      0x00},
{CC112X_FREQ_IF_CFG,        0x33},
{CC112X_IQIC,               0xC6},
{CC112X_CHAN_BW,            0x10},
{CC112X_MDMCFG1,            0x06},
{CC112X_MDMCFG0,            0x05},
{CC112X_SYMBOL_RATE2,       0x3F},
{CC112X_SYMBOL_RATE1,       0x75},
{CC112X_SYMBOL_RATE0,       0x10},
{CC112X_AGC_REF,            0x20},
{CC112X_AGC_CS_THR,         0x19},
{CC112X_AGC_CFG1,           0xA9},
{CC112X_AGC_CFG0,           0xCF},
{CC112X_FIFO_CFG,           0x00},
{CC112X_SETTLING_CFG,       0x03},
{CC112X_FS_CFG,             0x12},
{CC112X_PKT_CFG2,           0x05},
{CC112X_PKT_CFG1,           0x00},
{CC112X_PKT_CFG0,           0x20},
{CC112X_IF_MIX_CFG,         0x00},
{CC112X_FREQOFF_CFG,        0x22},
{CC112X_FREQ2,              0x56},
{CC112X_FREQ1,              0xEC},
{CC112X_FREQ0,              0x28},
{CC112X_IF_ADC0,            0x05},
{CC112X_FS_DIG1,            0x00},
{CC112X_FS_DIG0,            0x5F},
{CC112X_FS_CAL0,            0x0E},
{CC112X_FS_DIVTWO,          0x03},
{CC112X_FS_DSM0,            0x33},
{CC112X_FS_DVC0,            0x17},
{CC112X_FS_PFD,             0x50},
{CC112X_FS_PRE,             0x6E},
{CC112X_FS_REG_DIV_CML,     0x14},
{CC112X_FS_SPARE,           0xAC},
{CC112X_XOSC5,              0x0E},
{CC112X_XOSC3,              0xC7},
{CC112X_XOSC1,              0x07},
{CC112X_PARTNUMBER,         0x58},
{CC112X_PARTVERSION,        0x21},
{CC112X_SERIAL_STATUS,      0x08},
{CC112X_MODEM_STATUS1,      0x10},
{CC112X_XOSC_TEST1,         0x00},
};

//Packet mode preferred register settings
static const registerSetting_t ETSI_CAT1_869_S1_PacketTxRx[] = {
{CC112X_IOCFG3,            0xB0},
{CC112X_IOCFG2,            0x06},
{CC112X_IOCFG1,            0xB0},
{CC112X_IOCFG0,            0x40},
{CC112X_SYNC_CFG1,         0x08},
{CC112X_DEVIATION_M,       0xA3},
{CC112X_MODCFG_DEV_E,      0x0A},
{CC112X_DCFILT_CFG,        0x1C},
{CC112X_FREQ_IF_CFG,       0x33},
{CC112X_IQIC,              0xC6},
{CC112X_CHAN_BW,           0x10},
{CC112X_MDMCFG0,           0x05},
{CC112X_SYMBOL_RATE2,      0x3F},
{CC112X_SYMBOL_RATE1,      0x75},
{CC112X_SYMBOL_RATE0,      0x10},
{CC112X_AGC_REF,           0x20},
{CC112X_AGC_CS_THR,        0x19},
{CC112X_AGC_CFG1,          0xA9},
{CC112X_AGC_CFG0,          0xCF},
{CC112X_FIFO_CFG,          0x00},
{CC112X_SETTLING_CFG,      0x03},
{CC112X_FS_CFG,            0x12},
{CC112X_PKT_CFG0,          0x00},           //0x20 variable length mode, 0x00 for fixed length mode
{CC112X_PKT_LEN,           PACKET_LEN},     //set to 0x04, fixed packet size
{CC112X_IF_MIX_CFG,        0x00},
{CC112X_FREQOFF_CFG,       0x22},
{CC112X_FREQ2,             0x56},
{CC112X_FREQ1,             0xEC},
{CC112X_FREQ0,             0x28},
{CC112X_IF_ADC0,           0x05},
{CC112X_FS_DIG1,           0x00},
{CC112X_FS_DIG0,           0x5F},
{CC112X_FS_CAL0,           0x0E},
{CC112X_FS_DIVTWO,         0x03},
{CC112X_FS_DSM0,           0x33},
{CC112X_FS_DVC0,           0x17},
{CC112X_FS_PFD,            0x50},
{CC112X_FS_PRE,            0x6E},
{CC112X_FS_REG_DIV_CML,    0x14},
{CC112X_FS_SPARE,          0xAC},
{CC112X_XOSC5,             0x0E},
{CC112X_XOSC3,             0xC7},
{CC112X_XOSC1,             0x07},
{CC112X_PARTNUMBER,        0x58},
{CC112X_PARTVERSION,       0x21},
{CC112X_MODEM_STATUS1,     0x10},
{CC112X_XOSC_TEST1,        0x00},
};


#endif /* SMARTRF1125_H_ */
