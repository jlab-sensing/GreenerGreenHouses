/*
 * FR5969_CC1125.c
 *
 *  Created on: Sep 1, 2023
 *      Author: matth
 */
#include <msp430.h>
#include "hal_spi_rf_trxeb.h"
#include "cc112x_spi.h"
#include "stdint.h"
#include "smartRF1125.h"
#include <stdio.h>
#include <eusci_a_uart.h>
#include <gpio.h>
#include <hw_memmap.h>
#include <cs.h>
#include <string.h>

#define MSG_LENGTH 256
char Msg[MSG_LENGTH] = {0};


/*
* transmits character over UART TX transmission
* param: c, char type, single character to transmit
*/
void putcha(char c){

 EUSCI_A_UART_transmitData(EUSCI_A0_BASE,c);

}


/*
* transmits whole string over UART TX transmission, one character at a time using
* putcha
* param: *s, char pointer to string to transmit
*/
void putstring(char *s){
    int i= 0;
    int length = ((strlen(s)) - 1);

    for(i = length; i >= 0; i--)
    {
        putcha(s[length - i]);
    }
}

void ConfigRegisters(void){

        uint8_t writeByte;
        uint8_t readByte;
        uint16_t i;
        rfStatus_t status;
          for(i = 0; i < (sizeof(preferredSettings)/sizeof(registerSetting_t)); i++)
          {
              sprintf(Msg,"%d\t0x%02X\t0x%02X\n", i, preferredSettings[i].data, preferredSettings[i].addr);
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
          for(i = 0; i < (sizeof(preferredSettings)/sizeof(registerSetting_t)); i++) {
              sprintf(Msg,"i = %d\t", i);
              putstring(Msg);
              memset(Msg,0,MSG_LENGTH);
              sprintf(Msg,"expect = 0x%02X\t", preferredSettings[i].data);
              putstring(Msg);
              memset(Msg,0,MSG_LENGTH);
              status = cc112xSpiReadReg(preferredSettings[i].addr, &readByte, 1);
              sprintf(Msg,"value = 0x%02X\t", readByte);

              putstring(Msg);
              memset(Msg,0,MSG_LENGTH);

              if (readByte == preferredSettings[i].data){
                  putstring("OK\n");

              }else{

                 putstring("UNEXPECTED REGISTER VALUE\n");

              }
          }

          // Write registers to radio
          putstring("Writing\n");
          for(i = 0; i < (sizeof(preferredSettings)/sizeof(registerSetting_t)); i++) {
              sprintf(Msg,"i = %d\t", i);
              putstring(Msg);
              memset(Msg,0,MSG_LENGTH);

              writeByte = preferredSettings[i].data;
              sprintf(Msg,"writeByte = 0x%02X\t", writeByte);
              putstring(Msg);
              memset(Msg,0,MSG_LENGTH);

              status = cc112xSpiWriteReg(preferredSettings[i].addr, &writeByte, 1);
              sprintf(Msg,"status = 0x%02X\n", status);
              putstring(Msg);
              memset(Msg,0,MSG_LENGTH);

          }

          // Read registers from radio
          putstring("Reading\n");
          for(i = 0; i < (sizeof(preferredSettings)/sizeof(registerSetting_t)); i++) {
              sprintf(Msg,"i = %d\t", i);
              putstring(Msg);
              memset(Msg,0,MSG_LENGTH);

              sprintf(Msg,"expect = 0x%02X\t", preferredSettings[i].data);
              putstring(Msg);
              memset(Msg,0,MSG_LENGTH);

              status = cc112xSpiReadReg(preferredSettings[i].addr, &readByte, 1);
              sprintf(Msg,"value = 0x%02X\t", readByte);
              putstring(Msg);
              memset(Msg,0,MSG_LENGTH);

              if (readByte == preferredSettings[i].data){
                  putstring("OK\n");

              }else{
                  putstring("UNEXPECTED REGISTER VALUE\n");

              }
          }

          putstring("Done configuring registers.\n");

          return;



}


