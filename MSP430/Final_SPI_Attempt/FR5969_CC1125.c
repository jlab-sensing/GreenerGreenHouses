/*
 * FR5969_CC1125.c
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



void createPacket(uint8_t *Pkt, uint16_t temp, uint16_t hum, uint8_t deviceID) {
    uint32_t temporary;

    temporary  = hum;
    temporary |= ((uint32_t)temp << 14);
    temporary |= ((uint32_t)deviceID << 28);

     Pkt[0] = (temporary & 0xff000000) >> 24;
     Pkt[1] = (temporary & 0x00ff0000) >> 16;
     Pkt[2] = (temporary & 0x0000ff00) >> 8;
     Pkt[3] = (temporary & 0x000000ff);

}
