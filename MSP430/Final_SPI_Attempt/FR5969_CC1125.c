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


#define MSG_LENGTH 256
char Msg[MSG_LENGTH] = {0};


void ConfigRegisters(uint8_t MODE){

        uint8_t writeByte;
        uint8_t readByte;
        uint16_t i;
        rfStatus_t status;

        switch(MODE)
        {

        case RX_MODE:
            for(i = 0; i < (sizeof(ETSI_CAT1_869_S1_Rx)/sizeof(registerSetting_t)); i++)
                {
                    sprintf(Msg,"%d\t0x%02X\t0x%02X\n", i, ETSI_CAT1_869_S1_Rx[i].data, ETSI_CAT1_869_S1_Rx[i].addr);
                    putstring(Msg);
                    memset(Msg,0,MSG_LENGTH);


                }

                // Reset radio
                putstring("Resetting radio.\n");
                status = trxSpiCmdStrobe(CC112X_SRES);
                sprintf(Msg,"Status byte: 0x%02X\n", status);
                putstring(Msg);
                memset(Msg,0,MSG_LENGTH);
                // Wait for reset
      //
      //         for(i = 0; i <= 500000;i++){
      //             NOP();
      //         }


                putstring("Reading\n");
                for(i = 0; i < (sizeof(ETSI_CAT1_869_S1_Rx)/sizeof(registerSetting_t)); i++) {
                    sprintf(Msg,"i = %d\t", i);
                    putstring(Msg);
                    memset(Msg,0,MSG_LENGTH);
                    sprintf(Msg,"expect = 0x%02X\t", ETSI_CAT1_869_S1_Rx[i].data);
                    putstring(Msg);
                    memset(Msg,0,MSG_LENGTH);
                    status = cc112xSpiReadReg(ETSI_CAT1_869_S1_Rx[i].addr, &readByte, 1);
                    sprintf(Msg,"value = 0x%02X\t", readByte);

                    putstring(Msg);
                    memset(Msg,0,MSG_LENGTH);

                    if (readByte == ETSI_CAT1_869_S1_Rx[i].data){
                        putstring("OK\n");

                    }else{

                       putstring("UNEXPECTED REGISTER VALUE\n");

                    }
                }

                // Write registers to radio
                putstring("Writing\n");
                for(i = 0; i < (sizeof(ETSI_CAT1_869_S1_Rx)/sizeof(registerSetting_t)); i++) {
                    sprintf(Msg,"i = %d\t", i);
                    putstring(Msg);
                    memset(Msg,0,MSG_LENGTH);

                    writeByte = ETSI_CAT1_869_S1_Rx[i].data;
                    sprintf(Msg,"writeByte = 0x%02X\t", writeByte);
                    putstring(Msg);
                    memset(Msg,0,MSG_LENGTH);

                    status = cc112xSpiWriteReg(ETSI_CAT1_869_S1_Rx[i].addr, &writeByte, 1);
                    sprintf(Msg,"status = 0x%02X\n", status);
                    putstring(Msg);
                    memset(Msg,0,MSG_LENGTH);

                }

                // Read registers from radio
                putstring("Reading\n");
                for(i = 0; i < (sizeof(ETSI_CAT1_869_S1_Rx)/sizeof(registerSetting_t)); i++) {
                    sprintf(Msg,"i = %d\t", i);
                    putstring(Msg);
                    memset(Msg,0,MSG_LENGTH);

                    sprintf(Msg,"expect = 0x%02X\t", ETSI_CAT1_869_S1_Rx[i].data);
                    putstring(Msg);
                    memset(Msg,0,MSG_LENGTH);

                    status = cc112xSpiReadReg(ETSI_CAT1_869_S1_Rx[i].addr, &readByte, 1);
                    sprintf(Msg,"value = 0x%02X\t", readByte);
                    putstring(Msg);
                    memset(Msg,0,MSG_LENGTH);

                    if (readByte == ETSI_CAT1_869_S1_Rx[i].data){
                        putstring("OK\n");

                    }else{
                        putstring("UNEXPECTED REGISTER VALUE\n");

                    }
                }

                putstring("Done configuring Rx registers.\n");
            break;

        case TX_MODE:

            for(i = 0; i < (sizeof(ETSI_CAT1_869_S1_Tx)/sizeof(registerSetting_t)); i++)
                   {
                       sprintf(Msg,"%d\t0x%02X\t0x%02X\n", i, ETSI_CAT1_869_S1_Tx[i].data, ETSI_CAT1_869_S1_Tx[i].addr);
                       putstring(Msg);
                       memset(Msg,0,MSG_LENGTH);


                   }

                   // Reset radio
                   putstring("Resetting radio.\n");
                   status = trxSpiCmdStrobe(CC112X_SRES);
                   sprintf(Msg,"Status byte: 0x%02X\n", status);
                   putstring(Msg);
                   memset(Msg,0,MSG_LENGTH);
                   // Wait for reset
         //
         //         for(i = 0; i <= 500000;i++){
         //             NOP();
         //         }


                   putstring("Reading\n");
                   for(i = 0; i < (sizeof(ETSI_CAT1_869_S1_Tx)/sizeof(registerSetting_t)); i++) {
                       sprintf(Msg,"i = %d\t", i);
                       putstring(Msg);
                       memset(Msg,0,MSG_LENGTH);
                       sprintf(Msg,"expect = 0x%02X\t", ETSI_CAT1_869_S1_Tx[i].data);
                       putstring(Msg);
                       memset(Msg,0,MSG_LENGTH);
                       status = cc112xSpiReadReg(ETSI_CAT1_869_S1_Tx[i].addr, &readByte, 1);
                       sprintf(Msg,"value = 0x%02X\t", readByte);

                       putstring(Msg);
                       memset(Msg,0,MSG_LENGTH);

                       if (readByte == ETSI_CAT1_869_S1_Tx[i].data){
                           putstring("OK\n");

                       }else{

                          putstring("UNEXPECTED REGISTER VALUE\n");

                       }
                   }

                   // Write registers to radio
                   putstring("Writing\n");
                   for(i = 0; i < (sizeof(ETSI_CAT1_869_S1_Tx)/sizeof(registerSetting_t)); i++) {
                       sprintf(Msg,"i = %d\t", i);
                       putstring(Msg);
                       memset(Msg,0,MSG_LENGTH);

                       writeByte = ETSI_CAT1_869_S1_Tx[i].data;
                       sprintf(Msg,"writeByte = 0x%02X\t", writeByte);
                       putstring(Msg);
                       memset(Msg,0,MSG_LENGTH);

                       status = cc112xSpiWriteReg(ETSI_CAT1_869_S1_Tx[i].addr, &writeByte, 1);
                       sprintf(Msg,"status = 0x%02X\n", status);
                       putstring(Msg);
                       memset(Msg,0,MSG_LENGTH);

                   }

                   // Read registers from radio
                   putstring("Reading\n");
                   for(i = 0; i < (sizeof(ETSI_CAT1_869_S1_Tx)/sizeof(registerSetting_t)); i++) {
                       sprintf(Msg,"i = %d\t", i);
                       putstring(Msg);
                       memset(Msg,0,MSG_LENGTH);

                       sprintf(Msg,"expect = 0x%02X\t", ETSI_CAT1_869_S1_Tx[i].data);
                       putstring(Msg);
                       memset(Msg,0,MSG_LENGTH);

                       status = cc112xSpiReadReg(ETSI_CAT1_869_S1_Tx[i].addr, &readByte, 1);
                       sprintf(Msg,"value = 0x%02X\t", readByte);
                       putstring(Msg);
                       memset(Msg,0,MSG_LENGTH);

                       if (readByte == ETSI_CAT1_869_S1_Tx[i].data){
                           putstring("OK\n");

                       }else{
                           putstring("UNEXPECTED REGISTER VALUE\n");

                       }
                   }

                   putstring("Done configuring Tx registers.\n");
            break;

        default:

            break;
        }


          return;



}


