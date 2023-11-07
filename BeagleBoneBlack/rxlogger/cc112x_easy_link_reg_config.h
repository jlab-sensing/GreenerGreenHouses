//*****************************************************************************
//! @file       cc112x_easy_link_reg_config.h
//! @brief      Template for CC112x register export from SmartRF Studio 
//
//  Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions
//  are met:
//
//      Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//
//      Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//      Neither the name of Texas Instruments Incorporated nor the names of
//      its contributors may be used to endorse or promote products derived
//      from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//****************************************************************************/

#ifndef CC112X_EASY_LINK_REG_CONFIG_H
#define CC112X_EASY_LINK_REG_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
 * INCLUDES
 */
#include "hal_spi_rf_trxeb.h"
#include "cc112x_spi.h"
  
/******************************************************************************
 * VARIABLES
 */  

// ETSI CAT 1 868 packet txrx
static const registerSetting_t preferredSettings[]= 
{
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
    {CC112X_PKT_CFG0,          0x00}, /* 0x20 variable length, 0x00 fixed length */
    {CC112X_PKT_LEN,           0x06}, /* packet length in bytes */
    {CC112X_IF_MIX_CFG,        0x00},
    {CC112X_FREQOFF_CFG,       0x22},
    {CC112X_FREQ2,             0x56},
    {CC112X_FREQ1,             0xEC},
    {CC112X_FREQ0,             0x28},
    {CC112X_IF_ADC0,           0x05},
    {CC112X_FS_DIG1,           0x00},
    {CC112X_FS_DIG0,           0x5F},
    {CC112X_FS_CAL0,           0x0E},
    {CC112X_FS_CHP,            0x2F},
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
    // {CC112X_PARTNUMBER,        0x58},
    // {CC112X_PARTVERSION,       0x21},
    // {CC112X_MODEM_STATUS1,     0x10},
    // {CC112X_XOSC_TEST1,        0x00},
};



static const registerSetting_t ETSI_CAT1_869_S1_Bootup_Sequence_Part_1[] = {
    {CC112X_FS_CAL0         ,0x0e},
    {CC112X_FS_CFG          ,0x12},
    {CC112X_FS_DIG0         ,0x5f},
    {CC112X_FS_DIG1         ,0x00},
    {CC112X_FS_DIVTWO       ,0x03},
    {CC112X_FS_DSM0         ,0x33},
    {CC112X_FS_DVC0         ,0x17},
    {CC112X_FS_PFD          ,0x50},
    {CC112X_FS_PRE          ,0x6e},
    {CC112X_FS_REG_DIV_CML  ,0x14},
    {CC112X_FS_SPARE        ,0xac},
    {CC112X_IF_ADC0         ,0x05},
    {CC112X_IOCFG0          ,0x40},
    {CC112X_IOCFG1          ,0xb0},
    {CC112X_IOCFG2          ,0x06},
    {CC112X_IOCFG3          ,0xb0},
    {CC112X_SETTLING_CFG    ,0x0b},
    {CC112X_XOSC1           ,0x07},
    {CC112X_XOSC3           ,0xc7},
    {CC112X_XOSC5           ,0x0e},
    {CC112X_AGC_CFG0        ,0xcf},
    {CC112X_AGC_CFG1        ,0xa9},
    {CC112X_AGC_CFG2        ,0x20},
    {CC112X_AGC_CFG3        ,0x91},
    {CC112X_AGC_CS_THR      ,0x19},
    {CC112X_AGC_GAIN_ADJUST ,0x00},
    {CC112X_AGC_REF         ,0x20},
    {CC112X_CHAN_BW         ,0x10},
    {CC112X_DCFILT_CFG      ,0x1c},
    {CC112X_DEVIATION_M     ,0xa3},
    {CC112X_SYMBOL_RATE0    ,0x10},
    {CC112X_SYMBOL_RATE1    ,0x75},
    {CC112X_SYMBOL_RATE2    ,0x3f},
    {CC112X_FREQ0           ,0x28},
    {CC112X_FREQ1           ,0xec},
    {CC112X_FREQ2           ,0x56},
    {CC112X_FREQOFF_CFG     ,0x22},
    {CC112X_FREQ_IF_CFG     ,0x33},
    {CC112X_IF_MIX_CFG      ,0x00},
    {CC112X_IQIC            ,0xc6},
    {CC112X_MDMCFG0         ,0x05},
    {CC112X_MDMCFG1         ,0x46},
    {CC112X_MODCFG_DEV_E    ,0x0a},
    {CC112X_PA_CFG0         ,0x7c},
    {CC112X_PA_CFG1         ,0x56},
    {CC112X_PA_CFG2         ,0x7f},
    {CC112X_PREAMBLE_CFG0   ,0x2a},
    {CC112X_PREAMBLE_CFG1   ,0x14},
    {CC112X_CFM_DATA_CFG    ,0x00},
    {CC112X_SYNC0           ,0xde},
    {CC112X_SYNC1           ,0x51},
    {CC112X_SYNC2           ,0x0b},
    {CC112X_SYNC3           ,0x93},
    {CC112X_SYNC_CFG0       ,0x17},
    {CC112X_SYNC_CFG1       ,0x08},
    {CC112X_TOC_CFG         ,0x0b},
    {CC112X_PA_CFG1         ,0x56},
    {CC112X_PA_CFG2         ,0x7f},
};
    // SIDLE
    // SFTX
    
static const registerSetting_t ETSI_CAT1_869_S1_Bootup_Sequence_Part_2[] = {
    {CC112X_MDMCFG1         ,0x46},
    {CC112X_FS_CFG          ,0x12},
    {CC112X_PKT_CFG1        ,0x05},
    // {CC112X_PKT_CFG0        ,0x20},
    {CC112X_RFEND_CFG1      ,0x0f},
    {CC112X_FIFO_CFG        ,0x00},
    {CC112X_FS_CFG          ,0x12},
    {CC112X_XOSC1           ,0x07},
    {CC112X_CFM_DATA_CFG    ,0x00},
    {CC112X_CFM_TX_DATA_IN  ,0x00},
    {CC112X_IOCFG2          ,0x06},
    {CC112X_IOCFG3          ,0xb0},
    {CC112X_PKT_CFG2        ,0x04},
    // {CC112X_PKT_LEN         ,0xff},
    {CC112X_PREAMBLE_CFG1   ,0x14},
    {CC112X_SERIAL_STATUS   ,0x00},
    {CC112X_SYNC0           ,0xde},
    {CC112X_SYNC1           ,0x51},
    {CC112X_SYNC2           ,0x0b},
    {CC112X_SYNC3           ,0x93},
    {CC112X_MDMCFG0         ,0x05},
    {CC112X_IOCFG0          ,0x40},
    {CC112X_FREQOFF_CFG     ,0x22},
    {CC112X_AGC_CFG1        ,0xa9},
    {CC112X_SYNC_CFG1       ,0x08},
    {CC112X_SETTLING_CFG    ,0x03},
    
    {CC112X_PKT_CFG0        ,0x00},
    // {CC112X_PKT_LEN         ,0x7e},
    
    {CC112X_PKT_LEN         ,0x04},
};

static const registerSetting_t ETSI_CAT1_869_S1_Bootup_Sequence_Part_3[] = {
    {CC112X_FS_VCO2         ,0x00},
    {CC112X_FS_CAL2         ,0x22},
    {CC112X_FS_VCO2         ,0x00},
    {CC112X_FS_CAL2         ,0x20},
    {CC112X_FS_CHP          ,0x30},
};

static const registerSetting_t ETSI_CAT1_869_S1_PacketTxRx[] = {
    {CC112X_IOCFG3,         0xB0},
    {CC112X_IOCFG2,         0x06},
    {CC112X_IOCFG1,         0xB0},
    {CC112X_IOCFG0,         0xB0},
    {CC112X_SYNC_CFG1,      0x0B},
    {CC112X_DCFILT_CFG,     0x1C},
    {CC112X_IQIC,           0xC6},
    {CC112X_CHAN_BW,        0x08},
    {CC112X_MDMCFG0,        0x05},
    {CC112X_AGC_REF,        0x20},
    {CC112X_AGC_CS_THR,     0x19},
    {CC112X_AGC_CFG1,       0xA9},
    {CC112X_AGC_CFG0,       0xCF},
    {CC112X_FIFO_CFG,       0x00},
    {CC112X_SETTLING_CFG,   0x03},
    {CC112X_FS_CFG,         0x12},
    {CC112X_PKT_CFG1,       0x05},
    {CC112X_PKT_CFG0,       0x20},
    {CC112X_PA_CFG2,        0x4F},
    {CC112X_PA_CFG1,        0x56},
    {CC112X_PA_CFG0,        0x1C},
    {CC112X_PKT_LEN,        0xFF},
    {CC112X_IF_MIX_CFG,     0x00},
    {CC112X_FREQOFF_CFG,    0x22},
    {CC112X_FREQ2,          0x6C},
    {CC112X_FREQ1,          0x80},
    {CC112X_FREQ0,          0x00},
    {CC112X_FS_DIG1,        0x00},
    {CC112X_FS_DIG0,        0x5F},
    {CC112X_FS_CAL0,        0x0E},
    {CC112X_FS_DIVTWO,      0x03},
    {CC112X_FS_DSM0,        0x33},
    {CC112X_FS_DVC0,        0x17},
    {CC112X_FS_PFD,         0x50},
    {CC112X_FS_PRE,         0x6E},
    {CC112X_FS_REG_DIV_CML, 0x14},
    {CC112X_FS_SPARE,       0xAC},
    {CC112X_XOSC5,          0x0E},
    {CC112X_XOSC3,          0xC7},
    {CC112X_XOSC1,          0x07},
};

static const registerSetting_t allSettings[]=
{
    {CC112X_IOCFG3                  ,0x00},
    {CC112X_IOCFG2                  ,0x01},
    {CC112X_IOCFG1                  ,0x02},
    {CC112X_IOCFG0                  ,0x03},
    {CC112X_SYNC3                   ,0x04},
    {CC112X_SYNC2                   ,0x05},
    {CC112X_SYNC1                   ,0x06},
    {CC112X_SYNC0                   ,0x07},
    {CC112X_SYNC_CFG1               ,0x08},
    {CC112X_SYNC_CFG0               ,0x09},
    {CC112X_DEVIATION_M             ,0x0A},
    {CC112X_MODCFG_DEV_E            ,0x0B},
    {CC112X_DCFILT_CFG              ,0x0C},
    {CC112X_PREAMBLE_CFG1           ,0x0D},
    {CC112X_PREAMBLE_CFG0           ,0x0E},
    {CC112X_FREQ_IF_CFG             ,0x0F},
    {CC112X_IQIC                    ,0x10},
    {CC112X_CHAN_BW                 ,0x11},
    {CC112X_MDMCFG1                 ,0x12},
    {CC112X_MDMCFG0                 ,0x13},
    {CC112X_SYMBOL_RATE2            ,0x14},
    {CC112X_SYMBOL_RATE1            ,0x15},
    {CC112X_SYMBOL_RATE0            ,0x16},
    {CC112X_AGC_REF                 ,0x17},
    {CC112X_AGC_CS_THR              ,0x18},
    {CC112X_AGC_GAIN_ADJUST         ,0x19},
    {CC112X_AGC_CFG3                ,0x1A},
    {CC112X_AGC_CFG2                ,0x1B},
    {CC112X_AGC_CFG1                ,0x1C},
    {CC112X_AGC_CFG0                ,0x1D},
    {CC112X_FIFO_CFG                ,0x1E},
    {CC112X_DEV_ADDR                ,0x1F},
    {CC112X_SETTLING_CFG            ,0x20},
    {CC112X_FS_CFG                  ,0x21},
    {CC112X_WOR_CFG1                ,0x22},
    {CC112X_WOR_CFG0                ,0x23},
    {CC112X_WOR_EVENT0_MSB          ,0x24},
    {CC112X_WOR_EVENT0_LSB          ,0x25},
    {CC112X_PKT_CFG2                ,0x26},
    {CC112X_PKT_CFG1                ,0x27},
    {CC112X_PKT_CFG0                ,0x28},
    {CC112X_RFEND_CFG1              ,0x29},
    {CC112X_RFEND_CFG0              ,0x2A},
    {CC112X_PA_CFG2                 ,0x2B},
    {CC112X_PA_CFG1                 ,0x2C},
    {CC112X_PA_CFG0                 ,0x2D},
    {CC112X_PKT_LEN                 ,0x2E},
    {CC112X_IF_MIX_CFG              ,0x00}, /* Extended 0x2F##*/
    {CC112X_FREQOFF_CFG             ,0x01}, /* Extended 0x2F##*/
    {CC112X_TOC_CFG                 ,0x02}, /* Extended 0x2F##*/
    {CC112X_MARC_SPARE              ,0x03}, /* Extended 0x2F##*/
    {CC112X_ECG_CFG                 ,0x04}, /* Extended 0x2F##*/
    {CC112X_CFM_DATA_CFG            ,0x05}, /* Extended 0x2F##*/
    {CC112X_EXT_CTRL                ,0x06}, /* Extended 0x2F##*/
    {CC112X_RCCAL_FINE              ,0x07}, /* Extended 0x2F##*/
    {CC112X_RCCAL_COARSE            ,0x08}, /* Extended 0x2F##*/
    {CC112X_RCCAL_OFFSET            ,0x09}, /* Extended 0x2F##*/
    {CC112X_FREQOFF1                ,0x0A}, /* Extended 0x2F##*/
    {CC112X_FREQOFF0                ,0x0B}, /* Extended 0x2F##*/
    {CC112X_FREQ2                   ,0x0C}, /* Extended 0x2F##*/
    {CC112X_FREQ1                   ,0x0D}, /* Extended 0x2F##*/
    {CC112X_FREQ0                   ,0x0E}, /* Extended 0x2F##*/
    {CC112X_IF_ADC2                 ,0x0F}, /* Extended 0x2F##*/
    {CC112X_IF_ADC1                 ,0x10}, /* Extended 0x2F##*/
    {CC112X_IF_ADC0                 ,0x11}, /* Extended 0x2F##*/
    {CC112X_FS_DIG1                 ,0x12}, /* Extended 0x2F##*/
    {CC112X_FS_DIG0                 ,0x13}, /* Extended 0x2F##*/
    {CC112X_FS_CAL3                 ,0x14}, /* Extended 0x2F##*/
    {CC112X_FS_CAL2                 ,0x15}, /* Extended 0x2F##*/
    {CC112X_FS_CAL1                 ,0x16}, /* Extended 0x2F##*/
    {CC112X_FS_CAL0                 ,0x17}, /* Extended 0x2F##*/
    {CC112X_FS_CHP                  ,0x18}, /* Extended 0x2F##*/
    {CC112X_FS_DIVTWO               ,0x19}, /* Extended 0x2F##*/
    {CC112X_FS_DSM1                 ,0x1A}, /* Extended 0x2F##*/
    {CC112X_FS_DSM0                 ,0x1B}, /* Extended 0x2F##*/
    {CC112X_FS_DVC1                 ,0x1C}, /* Extended 0x2F##*/
    {CC112X_FS_DVC0                 ,0x1D}, /* Extended 0x2F##*/
    {CC112X_FS_LBI                  ,0x1E}, /* Extended 0x2F##*/
    {CC112X_FS_PFD                  ,0x1F}, /* Extended 0x2F##*/
    {CC112X_FS_PRE                  ,0x20}, /* Extended 0x2F##*/
    {CC112X_FS_REG_DIV_CML          ,0x21}, /* Extended 0x2F##*/
    {CC112X_FS_SPARE                ,0x22}, /* Extended 0x2F##*/
    {CC112X_FS_VCO4                 ,0x23}, /* Extended 0x2F##*/
    {CC112X_FS_VCO3                 ,0x24}, /* Extended 0x2F##*/
    {CC112X_FS_VCO2                 ,0x25}, /* Extended 0x2F##*/
    {CC112X_FS_VCO1                 ,0x26}, /* Extended 0x2F##*/
    {CC112X_FS_VCO0                 ,0x27}, /* Extended 0x2F##*/
    {CC112X_GBIAS6                  ,0x28}, /* Extended 0x2F##*/
    {CC112X_GBIAS5                  ,0x29}, /* Extended 0x2F##*/
    {CC112X_GBIAS4                  ,0x2A}, /* Extended 0x2F##*/
    {CC112X_GBIAS3                  ,0x2B}, /* Extended 0x2F##*/
    {CC112X_GBIAS2                  ,0x2C}, /* Extended 0x2F##*/
    {CC112X_GBIAS1                  ,0x2D}, /* Extended 0x2F##*/
    {CC112X_GBIAS0                  ,0x2E}, /* Extended 0x2F##*/
    {CC112X_IFAMP                   ,0x2F}, /* Extended 0x2F##*/
    {CC112X_LNA                     ,0x30}, /* Extended 0x2F##*/
    {CC112X_RXMIX                   ,0x31}, /* Extended 0x2F##*/
    {CC112X_XOSC5                   ,0x32}, /* Extended 0x2F##*/
    {CC112X_XOSC4                   ,0x33}, /* Extended 0x2F##*/
    {CC112X_XOSC3                   ,0x34}, /* Extended 0x2F##*/
    {CC112X_XOSC2                   ,0x35}, /* Extended 0x2F##*/
    {CC112X_XOSC1                   ,0x36}, /* Extended 0x2F##*/
    {CC112X_XOSC0                   ,0x37}, /* Extended 0x2F##*/
    {CC112X_ANALOG_SPARE            ,0x38}, /* Extended 0x2F##*/
    {CC112X_PA_CFG3                 ,0x39}, /* Extended 0x2F##*/
    {CC112X_IRQ0M                   ,0x3F}, /* Extended 0x2F##*/
    {CC112X_IRQ0F                   ,0x40}, /* Extended 0x2F##*/
    {CC112X_WOR_TIME1               ,0x64}, /* Extended 0x2F##*/
    {CC112X_WOR_TIME0               ,0x65}, /* Extended 0x2F##*/
    {CC112X_WOR_CAPTURE1            ,0x66}, /* Extended 0x2F##*/
    {CC112X_WOR_CAPTURE0            ,0x67}, /* Extended 0x2F##*/
    {CC112X_BIST                    ,0x68}, /* Extended 0x2F##*/
    {CC112X_DCFILTOFFSET_I1         ,0x69}, /* Extended 0x2F##*/
    {CC112X_DCFILTOFFSET_I0         ,0x6A}, /* Extended 0x2F##*/
    {CC112X_DCFILTOFFSET_Q1         ,0x6B}, /* Extended 0x2F##*/
    {CC112X_DCFILTOFFSET_Q0         ,0x6C}, /* Extended 0x2F##*/
    {CC112X_IQIE_I1                 ,0x6D}, /* Extended 0x2F##*/
    {CC112X_IQIE_I0                 ,0x6E}, /* Extended 0x2F##*/
    {CC112X_IQIE_Q1                 ,0x6F}, /* Extended 0x2F##*/
    {CC112X_IQIE_Q0                 ,0x70}, /* Extended 0x2F##*/
    {CC112X_RSSI1                   ,0x71}, /* Extended 0x2F##*/
    {CC112X_RSSI0                   ,0x72}, /* Extended 0x2F##*/
    {CC112X_MARCSTATE               ,0x73}, /* Extended 0x2F##*/
    {CC112X_LQI_VAL                 ,0x74}, /* Extended 0x2F##*/
    {CC112X_PQT_SYNC_ERR            ,0x75}, /* Extended 0x2F##*/
    {CC112X_DEM_STATUS              ,0x76}, /* Extended 0x2F##*/
    {CC112X_FREQOFF_EST1            ,0x77}, /* Extended 0x2F##*/
    {CC112X_FREQOFF_EST0            ,0x78}, /* Extended 0x2F##*/
    {CC112X_AGC_GAIN3               ,0x79}, /* Extended 0x2F##*/
    {CC112X_AGC_GAIN2               ,0x7A}, /* Extended 0x2F##*/
    {CC112X_AGC_GAIN1               ,0x7B}, /* Extended 0x2F##*/
    {CC112X_AGC_GAIN0               ,0x7C}, /* Extended 0x2F##*/
    {CC112X_CFM_RX_DATA_OUT         ,0x7D}, /* Extended 0x2F##*/
    {CC112X_CFM_TX_DATA_IN          ,0x7E}, /* Extended 0x2F##*/
    {CC112X_ASK_SOFT_RX_DATA        ,0x7F}, /* Extended 0x2F##*/
    {CC112X_RNDGEN                  ,0x80}, /* Extended 0x2F##*/
    {CC112X_MAGN2                   ,0x81}, /* Extended 0x2F##*/
    {CC112X_MAGN1                   ,0x82}, /* Extended 0x2F##*/
    {CC112X_MAGN0                   ,0x83}, /* Extended 0x2F##*/
    {CC112X_ANG1                    ,0x84}, /* Extended 0x2F##*/
    {CC112X_ANG0                    ,0x85}, /* Extended 0x2F##*/
    {CC112X_CHFILT_I2               ,0x86}, /* Extended 0x2F##*/
    {CC112X_CHFILT_I1               ,0x87}, /* Extended 0x2F##*/
    {CC112X_CHFILT_I0               ,0x88}, /* Extended 0x2F##*/
    {CC112X_CHFILT_Q2               ,0x89}, /* Extended 0x2F##*/
    {CC112X_CHFILT_Q1               ,0x8A}, /* Extended 0x2F##*/
    {CC112X_CHFILT_Q0               ,0x8B}, /* Extended 0x2F##*/
    {CC112X_GPIO_STATUS             ,0x8C}, /* Extended 0x2F##*/
    {CC112X_FSCAL_CTRL              ,0x8D}, /* Extended 0x2F##*/
    {CC112X_PHASE_ADJUST            ,0x8E}, /* Extended 0x2F##*/
    {CC112X_PARTNUMBER              ,0x8F}, /* Extended 0x2F##*/
    {CC112X_PARTVERSION             ,0x90}, /* Extended 0x2F##*/
    {CC112X_SERIAL_STATUS           ,0x91}, /* Extended 0x2F##*/
    {CC112X_MODEM_STATUS1           ,0x92}, /* Extended 0x2F##*/
    {CC112X_MODEM_STATUS0           ,0x93}, /* Extended 0x2F##*/
    {CC112X_MARC_STATUS1            ,0x94}, /* Extended 0x2F##*/
    {CC112X_MARC_STATUS0            ,0x95}, /* Extended 0x2F##*/
    {CC112X_PA_IFAMP_TEST           ,0x96}, /* Extended 0x2F##*/
    {CC112X_FSRF_TEST               ,0x97}, /* Extended 0x2F##*/
    {CC112X_PRE_TEST                ,0x98}, /* Extended 0x2F##*/
    {CC112X_PRE_OVR                 ,0x99}, /* Extended 0x2F##*/
    {CC112X_ADC_TEST                ,0x9A}, /* Extended 0x2F##*/
    {CC112X_DVC_TEST                ,0x9B}, /* Extended 0x2F##*/
    {CC112X_ATEST                   ,0x9C}, /* Extended 0x2F##*/
    {CC112X_ATEST_LVDS              ,0x9D}, /* Extended 0x2F##*/
    {CC112X_ATEST_MODE              ,0x9E}, /* Extended 0x2F##*/
    {CC112X_XOSC_TEST1              ,0x9F}, /* Extended 0x2F##*/
    {CC112X_XOSC_TEST0              ,0xA0}, /* Extended 0x2F##*/
    {CC112X_RXFIRST                 ,0xD2}, /* Extended 0x2F##*/
    {CC112X_TXFIRST                 ,0xD3}, /* Extended 0x2F##*/
    {CC112X_RXLAST                  ,0xD4}, /* Extended 0x2F##*/
    {CC112X_TXLAST                  ,0xD5}, /* Extended 0x2F##*/
    {CC112X_NUM_TXBYTES             ,0xD6}, /* Extended 0x2F##*/
    {CC112X_NUM_RXBYTES             ,0xD7}, /* Extended 0x2F##*/
    {CC112X_FIFO_NUM_TXBYTES        ,0xD8}, /* Extended 0x2F##*/
    {CC112X_FIFO_NUM_RXBYTES        ,0xD9}, /* Extended 0x2F##*/
    {CC112X_SINGLE_TXFIFO           ,0x3F},
    {CC112X_BURST_TXFIFO            ,0x7F},
    {CC112X_SINGLE_RXFIFO           ,0xBF},
    {CC112X_BURST_RXFIFO            ,0xFF},
    {CC112X_SRES                    ,0x30},
    {CC112X_SFSTXON                 ,0x31},
    {CC112X_SXOFF                   ,0x32},
    {CC112X_SCAL                    ,0x33},
    {CC112X_SRX                     ,0x34},
    {CC112X_STX                     ,0x35},
    {CC112X_SIDLE                   ,0x36},
    {CC112X_SWOR                    ,0x38},
    {CC112X_SPWD                    ,0x39},
    {CC112X_SFRX                    ,0x3A},
    {CC112X_SFTX                    ,0x3B},
    {CC112X_SWORRST                 ,0x3C},
    {CC112X_SNOP                    ,0x3D},
    {CC112X_AFC                     ,0x37},
};

// Carrier frequency = 868.000000 
// Symbol rate = 1.2 
// Bit rate = 1.2 
// Deviation = 3.997803 
// Manchester enable = false 
// Bit rate = 1.2 
// Modulation format = 2-FSK 
// Bit rate = 1.2 
// RX filter BW = 25.000000 
// TX power = -6 
// PA ramping = true 
// Packet length mode = Variable 
// Whitening = false 
// Address config = No address check. 
// Packet length = 255 
// Device address = 0 
// static const registerSetting_t preferredSettings[] = {
    // {CC112X_IOCFG3,         0xB0},
    // {CC112X_IOCFG2,         0x06},
    // {CC112X_IOCFG1,         0xB0},
    // {CC112X_IOCFG0,         0xB0},
    // {CC112X_SYNC_CFG1,      0x0B},
    // {CC112X_DCFILT_CFG,     0x1C},
    // {CC112X_IQIC,           0xC6},
    // {CC112X_CHAN_BW,        0x08},
    // {CC112X_MDMCFG0,        0x05},
    // {CC112X_AGC_REF,        0x20},
    // {CC112X_AGC_CS_THR,     0x19},
    // {CC112X_AGC_CFG1,       0xA9},
    // {CC112X_AGC_CFG0,       0xCF},
    // {CC112X_FIFO_CFG,       0x00},
    // {CC112X_SETTLING_CFG,   0x03},
    // {CC112X_FS_CFG,         0x12},
    // {CC112X_PKT_CFG1,       0x05},  
    // {CC112X_PKT_CFG0,       0x20},
    // {CC112X_PA_CFG2,        0x4F},
    // {CC112X_PA_CFG1,        0x56},
    // {CC112X_PA_CFG0,        0x1C},
    // {CC112X_PKT_LEN,        0xFF},
    // {CC112X_IF_MIX_CFG,     0x00},
    // {CC112X_FREQOFF_CFG,    0x22},
    // {CC112X_FREQ2,          0x6C},
    // {CC112X_FREQ1,          0x80},
    // {CC112X_FREQ0,          0x00},
    // {CC112X_FS_DIG1,        0x00},
    // {CC112X_FS_DIG0,        0x5F},
    // {CC112X_FS_CAL0,        0x0E},
    // {CC112X_FS_DIVTWO,      0x03},
    // {CC112X_FS_DSM0,        0x33},
    // {CC112X_FS_DVC0,        0x17},
    // {CC112X_FS_PFD,         0x50},
    // {CC112X_FS_PRE,         0x6E},
    // {CC112X_FS_REG_DIV_CML, 0x14},
    // {CC112X_FS_SPARE,       0xAC},
    // {CC112X_XOSC5,          0x0E},
    // {CC112X_XOSC3,          0xC7},
    // {CC112X_XOSC1,          0x07},
// };

#ifdef  __cplusplus
}
#endif

#endif
