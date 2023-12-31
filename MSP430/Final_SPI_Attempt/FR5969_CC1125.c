/*
 * FR5969_CC1125.c
 *
 * Specific library containing the implementations of function to setup the CC1125 module, and packet creator/unpacker
 *
 *  Created on: Sep 1, 2023
 *      Author: matth
 */
#include <msp430.h>
#include "hal_spi_rf_trxeb.h"
#include "FR5969_CC1125.h"
#include "cc112x_spi.h"
#include "smartRF1125.h"
#include <stdio.h>
#include "Uart.h"
#include <cs.h>
#include <gpio.h>
#include <hw_memmap.h>
#include <cs.h>
#include <string.h>
#include <string.h>

#define MSG_LENGTH 256
#define TX_MSG_SIZE 4
#define DEV_ID_1 0b0110
uint8_t TxBuffer[TX_MSG_SIZE] = {0};
char Msg[MSG_LENGTH] = { 0 };

#define VCDAC_START_OFFSET 2
#define FS_VCO2_INDEX 0
#define FS_VCO4_INDEX 1
#define FS_CHP_INDEX 2


void ConfigRegisters(uint8_t MODE)
{

    uint8_t writeByte;
    uint8_t readByte;
    uint16_t i;
    rfStatus_t status;

    switch (MODE)
    {

    case RX_MODE:

        putstring("Configuring CC1125 for Continuous Rx Mode\r\n");
        // Reset radio
        putstring("Resetting radio.\n");
        status = trxSpiCmdStrobe(CC112X_SRES);
        sprintf(Msg, "Status byte: 0x%02X\n", status);
        putstring(Msg);
        memset(Msg, 0, MSG_LENGTH);

        putstring("\r\n");
        putstring("==========================================================\r\n");
        putstring("==========================================================\r\n");
        putstring("Reading initial register states: \n");
        putstring("\r\n");
        for (i = 0;
                i < (sizeof(ETSI_CAT1_869_S1_Rx) / sizeof(registerSetting_t));
                i++)
        {
            sprintf(Msg, "i = %d\t", i);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);
            sprintf(Msg, "expect = 0x%02X\t", ETSI_CAT1_869_S1_Rx[i].data);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);
            status = cc112xSpiReadReg(ETSI_CAT1_869_S1_Rx[i].addr, &readByte,
                                      1);
            sprintf(Msg, "value = 0x%02X\t", readByte);

            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

            if (readByte == ETSI_CAT1_869_S1_Rx[i].data)
            {
                putstring("OK\n");

            }
            else
            {

                putstring("UNEXPECTED REGISTER VALUE\n");

            }
        }
        putstring("\r\n");
        putstring("==========================================================\r\n");
        putstring("==========================================================\r\n");
        // Write registers to radio
        putstring("Writing register values based on MODE selection\n");
        putstring("MODE: RX_MODE 0\n");
        putstring("      TX_MODE 1\r\n\r\n");

        for (i = 0;i < (sizeof(ETSI_CAT1_869_S1_Rx) / sizeof(registerSetting_t)); i++)
        {
            sprintf(Msg, "i = %d\t", i);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

            writeByte = ETSI_CAT1_869_S1_Rx[i].data;
            sprintf(Msg, "writeByte = 0x%02X\t", writeByte);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

            status = cc112xSpiWriteReg(ETSI_CAT1_869_S1_Rx[i].addr, &writeByte,
                                       1);
            sprintf(Msg, "status = 0x%02X\n", status);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

        }
        putstring("\r\n");
        putstring("==========================================================\r\n");
              putstring("==========================================================\r\n");
        // Read registers from radio
        putstring("Reading registers after write to ensure correct configuration\r\n");
        putstring("\r\n");

        for (i = 0;
                i < (sizeof(ETSI_CAT1_869_S1_Rx) / sizeof(registerSetting_t));
                i++)
        {
            sprintf(Msg, "i = %d\t", i);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

            sprintf(Msg, "expect = 0x%02X\t", ETSI_CAT1_869_S1_Rx[i].data);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

            status = cc112xSpiReadReg(ETSI_CAT1_869_S1_Rx[i].addr, &readByte,
                                      1);
            sprintf(Msg, "value = 0x%02X\t", readByte);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

            if (readByte == ETSI_CAT1_869_S1_Rx[i].data)
            {
                putstring("OK\n");


            }
            else
            {
                putstring("UNEXPECTED REGISTER VALUE\n");

            }
        }
        putstring("==========================================================\r\n");
        putstring("==========================================================\r\n");

        putstring("Done configuring Rx registers.\n");
        break;

    case TX_MODE:

                putstring("Configuring CC1125 for Continuous Tx Mode\r\n");
                // Reset radio
                putstring("Resetting radio.\n");
                status = trxSpiCmdStrobe(CC112X_SRES);
                sprintf(Msg, "Status byte: 0x%02X\n", status);
                putstring(Msg);
                memset(Msg, 0, MSG_LENGTH);

                putstring("\r\n");
                putstring("==========================================================\r\n");
                putstring("==========================================================\r\n");
                putstring("Reading initial register states: \n");
                putstring("\r\n");
                for (i = 0;
                        i < (sizeof(ETSI_CAT1_869_S1_Tx) / sizeof(registerSetting_t));
                        i++)
                {
                    sprintf(Msg, "i = %d\t", i);
                    putstring(Msg);
                    memset(Msg, 0, MSG_LENGTH);
                    sprintf(Msg, "expect = 0x%02X\t", ETSI_CAT1_869_S1_Tx[i].data);
                    putstring(Msg);
                    memset(Msg, 0, MSG_LENGTH);
                    status = cc112xSpiReadReg(ETSI_CAT1_869_S1_Tx[i].addr, &readByte,
                                              1);
                    sprintf(Msg, "value = 0x%02X\t", readByte);

                    putstring(Msg);
                    memset(Msg, 0, MSG_LENGTH);

                    if (readByte == ETSI_CAT1_869_S1_Tx[i].data)
                    {
                        putstring("OK\n");

                    }
                    else
                    {

                        putstring("UNEXPECTED REGISTER VALUE\n");

                    }
                }
                putstring("\r\n");
                putstring("==========================================================\r\n");
                putstring("==========================================================\r\n");
                // Write registers to radio
                putstring("Writing register values based on MODE selection\n");
                putstring("MODE: RX_MODE 0\n");
                putstring("      TX_MODE 1\r\n\r\n");

                for (i = 0;i < (sizeof(ETSI_CAT1_869_S1_Tx) / sizeof(registerSetting_t)); i++)
                {
                    sprintf(Msg, "i = %d\t", i);
                    putstring(Msg);
                    memset(Msg, 0, MSG_LENGTH);

                    writeByte = ETSI_CAT1_869_S1_Tx[i].data;
                    sprintf(Msg, "writeByte = 0x%02X\t", writeByte);
                    putstring(Msg);
                    memset(Msg, 0, MSG_LENGTH);

                    status = cc112xSpiWriteReg(ETSI_CAT1_869_S1_Tx[i].addr, &writeByte,
                                               1);
                    sprintf(Msg, "status = 0x%02X\n", status);
                    putstring(Msg);
                    memset(Msg, 0, MSG_LENGTH);

                }
                putstring("\r\n");
                putstring("==========================================================\r\n");
                      putstring("==========================================================\r\n");
                // Read registers from radio
                putstring("Reading registers after write to ensure correct  Tx configuration\r\n");
                putstring("\r\n");

                for (i = 0;
                        i < (sizeof(ETSI_CAT1_869_S1_Tx) / sizeof(registerSetting_t));
                        i++)
                {
                    sprintf(Msg, "i = %d\t", i);
                    putstring(Msg);
                    memset(Msg, 0, MSG_LENGTH);

                    sprintf(Msg, "expect = 0x%02X\t", ETSI_CAT1_869_S1_Tx[i].data);
                    putstring(Msg);
                    memset(Msg, 0, MSG_LENGTH);

                    status = cc112xSpiReadReg(ETSI_CAT1_869_S1_Tx[i].addr, &readByte, 1);
                    sprintf(Msg, "value = 0x%02X\t", readByte);
                    putstring(Msg);
                    memset(Msg, 0, MSG_LENGTH);

                    if (readByte == ETSI_CAT1_869_S1_Tx[i].data)
                    {
                        putstring("OK\n");

                    }
                    else
                    {
                        putstring("UNEXPECTED REGISTER VALUE\n");

                    }
                }
                putstring("==========================================================\r\n");
                putstring("==========================================================\r\n");

                putstring("Done configuring Tx registers.\n");
        break;

    case PACKET_MODE:

        putstring("Configuring CC1125 for packet Rx/Tx mode\r\n");
        // Reset radio
        putstring("Resetting radio.\n");
        status = trxSpiCmdStrobe(CC112X_SRES);
        sprintf(Msg, "Status byte: 0x%02X\n", status);
        putstring(Msg);
        memset(Msg, 0, MSG_LENGTH);

        putstring("\r\n");
        putstring("==========================================================\r\n");
        putstring("==========================================================\r\n");
        putstring("Reading initial register states: \n");
        putstring("\r\n");
        for (i = 0;
                i < (sizeof(ETSI_CAT1_869_S1_PacketTxRx) / sizeof(registerSetting_t));
                i++)
        {
            sprintf(Msg, "i = %d\t", i);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);
            sprintf(Msg, "expect = 0x%02X\t", ETSI_CAT1_869_S1_PacketTxRx[i].data);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);
            status = cc112xSpiReadReg(ETSI_CAT1_869_S1_PacketTxRx[i].addr, &readByte,
                                      1);
            sprintf(Msg, "value = 0x%02X\t", readByte);

            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

            if (readByte == ETSI_CAT1_869_S1_PacketTxRx[i].data)
            {
                putstring("OK\n");

            }
            else
            {

                putstring("UNEXPECTED REGISTER VALUE\n");

            }
        }
        putstring("\r\n");
        putstring("==========================================================\r\n");
        putstring("==========================================================\r\n");
        // Write registers to radio
        putstring("Writing register values based on MODE selection\n");
        putstring("MODE: RX_MODE 0\n");
        putstring("      TX_MODE 1\r\n\r\n");

        for (i = 0;i < (sizeof(ETSI_CAT1_869_S1_PacketTxRx) / sizeof(registerSetting_t)); i++)
        {
            sprintf(Msg, "i = %d\t", i);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

            writeByte = ETSI_CAT1_869_S1_PacketTxRx[i].data;
            sprintf(Msg, "writeByte = 0x%02X\t", writeByte);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

            status = cc112xSpiWriteReg(ETSI_CAT1_869_S1_PacketTxRx[i].addr, &writeByte,
                                       1);
            sprintf(Msg, "status = 0x%02X\n", status);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

        }
        putstring("\r\n");
        putstring("==========================================================\r\n");
              putstring("==========================================================\r\n");
        // Read registers from radio
        putstring("Reading registers after write to ensure correct  Tx configuration\r\n");
        putstring("\r\n");

        for (i = 0;
                i < (sizeof(ETSI_CAT1_869_S1_PacketTxRx) / sizeof(registerSetting_t));
                i++)
        {
            sprintf(Msg, "i = %d\t", i);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

            sprintf(Msg, "expect = 0x%02X\t", ETSI_CAT1_869_S1_PacketTxRx[i].data);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

            status = cc112xSpiReadReg(ETSI_CAT1_869_S1_PacketTxRx[i].addr, &readByte, 1);
            sprintf(Msg, "value = 0x%02X\t", readByte);
            putstring(Msg);
            memset(Msg, 0, MSG_LENGTH);

            if (readByte == ETSI_CAT1_869_S1_PacketTxRx[i].data)
            {
                putstring("OK\n");

            }
            else
            {
                putstring("UNEXPECTED REGISTER VALUE\n");

            }
        }
        putstring("==========================================================\r\n");
        putstring("==========================================================\r\n");

        putstring("Done configuring packet Rx/Tx registers.\n");
        break;
    default:

        break;
    }

    return;

}


void manualCalibration(void)
{

    uint8 original_fs_cal2;
    uint8 calResults_for_vcdac_start_high[3];
    uint8 calResults_for_vcdac_start_mid[3];
    uint8 marcstate;
    uint8 writeByte;

    // 1) Set VCO cap-array to 0 (FS_VCO2 = 0x00)
    writeByte = 0x00;
    cc112xSpiWriteReg(CC112X_FS_VCO2, &writeByte, 1);

    // 2) Start with high VCDAC (original VCDAC_START + 2):
    cc112xSpiReadReg(CC112X_FS_CAL2, &original_fs_cal2, 1);
    writeByte = original_fs_cal2 + VCDAC_START_OFFSET;
    cc112xSpiWriteReg(CC112X_FS_CAL2, &writeByte, 1);

    // 3) Calibrate and wait for calibration to be done
    //   (radio back in IDLE state)
    trxSpiCmdStrobe(CC112X_SCAL);

    do
    {
        cc112xSpiReadReg(CC112X_MARCSTATE, &marcstate, 1);
    }
    while (marcstate != 0x41);

    // 4) Read FS_VCO2, FS_VCO4 and FS_CHP register obtained with
    //    high VCDAC_START value
    cc112xSpiReadReg(CC112X_FS_VCO2,
                     &calResults_for_vcdac_start_high[FS_VCO2_INDEX], 1);
    cc112xSpiReadReg(CC112X_FS_VCO4,
                     &calResults_for_vcdac_start_high[FS_VCO4_INDEX], 1);
    cc112xSpiReadReg(CC112X_FS_CHP,
                     &calResults_for_vcdac_start_high[FS_CHP_INDEX], 1);

    // 5) Set VCO cap-array to 0 (FS_VCO2 = 0x00)
    writeByte = 0x00;
    cc112xSpiWriteReg(CC112X_FS_VCO2, &writeByte, 1);

    // 6) Continue with mid VCDAC (original VCDAC_START):
    writeByte = original_fs_cal2;
    cc112xSpiWriteReg(CC112X_FS_CAL2, &writeByte, 1);

    // 7) Calibrate and wait for calibration to be done
    //   (radio back in IDLE state)
    trxSpiCmdStrobe(CC112X_SCAL);

    do
    {
        cc112xSpiReadReg(CC112X_MARCSTATE, &marcstate, 1);
    }
    while (marcstate != 0x41);

    // 8) Read FS_VCO2, FS_VCO4 and FS_CHP register obtained
    //    with mid VCDAC_START value
    cc112xSpiReadReg(CC112X_FS_VCO2,
                     &calResults_for_vcdac_start_mid[FS_VCO2_INDEX], 1);
    cc112xSpiReadReg(CC112X_FS_VCO4,
                     &calResults_for_vcdac_start_mid[FS_VCO4_INDEX], 1);
    cc112xSpiReadReg(CC112X_FS_CHP,
                     &calResults_for_vcdac_start_mid[FS_CHP_INDEX], 1);

    // 9) Write back highest FS_VCO2 and corresponding FS_VCO
    //    and FS_CHP result
    if (calResults_for_vcdac_start_high[FS_VCO2_INDEX]
            > calResults_for_vcdac_start_mid[FS_VCO2_INDEX])
    {
        writeByte = calResults_for_vcdac_start_high[FS_VCO2_INDEX];
        cc112xSpiWriteReg(CC112X_FS_VCO2, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_high[FS_VCO4_INDEX];
        cc112xSpiWriteReg(CC112X_FS_VCO4, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_high[FS_CHP_INDEX];
        cc112xSpiWriteReg(CC112X_FS_CHP, &writeByte, 1);
    }
    else
    {
        writeByte = calResults_for_vcdac_start_mid[FS_VCO2_INDEX];
        cc112xSpiWriteReg(CC112X_FS_VCO2, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_mid[FS_VCO4_INDEX];
        cc112xSpiWriteReg(CC112X_FS_VCO4, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_mid[FS_CHP_INDEX];
        cc112xSpiWriteReg(CC112X_FS_CHP, &writeByte, 1);
    }
}

void createPacket(uint8_t *packet, uint16_t temp, uint16_t hum, uint16_t deviceID) {
    // New 48 bit packet format: 16 bit id, 16 bit temp, 16 bit humidity

    packet[0] = (deviceID & 0xFF00) >> 8;   // ID high byte
    packet[1] = (deviceID & 0x00FF);        // ID low byte
    packet[2] = (temp & 0xFF00) >> 8;       // temp high byte
    packet[3] = (temp & 0x00FF);            // temp low byte
    packet[4] = (hum & 0xFF00) >> 8;        // hum high byte
    packet[5] = (hum & 0x00FF);             // hum low byte

/*// Old 32 bit packet format: 4 bit id, 14 bit temp, 14 bit humidity
    uint32_t temporary;

    temporary  = (uint32_t)hum >> 2;
    temporary |= (((uint32_t)temp  << 12) & 0x0FFFC000);
    temporary |= (((uint32_t)deviceID << 28) & 0xF0000000);

     packet[0] = (temporary & 0xff000000) >> 24;
     packet[1] = (temporary & 0x00ff0000) >> 16;
     packet[2] = (temporary & 0x0000ff00) >> 8;
     packet[3] = (temporary & 0x000000ff);
*/
}


void InitTxTimer(void){
    TA0CCTL0 |= CCIE;
    TA0CCR0 = 32678;
    TA0CTL |= TASSEL__ACLK | MC__CONTINUOUS;

    __bis_SR_register(LPM0_bits | GIE);

}
