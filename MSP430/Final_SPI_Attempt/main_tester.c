/*
 * main_tester.c
 *
 *  Created on: Sep 7, 2023
 *      Author: matth
 */

//required libraries for example to work
#include <msp430.h>
#include <stdint.h>
#include "MSP430_I2C.h"
#include "HDC2021.h"
#include "Uart.h"
#include <gpio.h>
#include <hw_memmap.h>
#include <cs.h>
#include <string.h>
#include "smartRF1125.h"
#include "FR5969_CC1125.h"

#define MSG_SIZE 256
#define VCDAC_START_OFFSET 2
#define FS_VCO2_INDEX 0
#define FS_VCO4_INDEX 1
#define FS_CHP_INDEX 2
static uint8_t Temperature, Humidity;


static void manualCalibration(void)
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

int main()
{
    WDTCTL = WDTPW | WDTHOLD; //Disable Watchdog Timer
    PM5CTL0 &= ~LOCKLPM5;

    //basic I2C library initialization
    initClockTo16MHz();
    initGPIO();
      InitUart();
    initI2C(HDC2021_ADDRESS);
     trxRfSpiInterfaceInit(4);

    ConfigRegisters(PACKET_MODE);
    manualCalibration();
    // uint16_t Temperature,Humidity;
    //HDC2021 Initialization
    Sensor_Reset();
    Sensor_SetMeasurementMode(TEMP_AND_HUMID);
    Sensor_SetMeasurementRate(ONE_SECOND);
    Sensor_SetTempResolution(FOURTEEN_BIT);
    Sensor_SetHumidityResolution(FOURTEEN_BIT);


    //first measurement needs to be thrown away as HDC2021 stabilizes
    Sensor_TriggerMeasurement();
    Temperature = Sensor_ReadTemp();
    Humidity = Sensor_ReadHumidity();
    //uint32_t Packet = 0x0;
    uint8_t Msg[4] = {0};

    while (1)
    {

        //first valid measurements stored
        Sensor_TriggerMeasurement();
        Temperature = Sensor_ReadTemp();
        Humidity = Sensor_ReadHumidity();

        //transmit message "Test" with packet number after it every second

      //sprintf(TXBuff, "Temp: %x  || Humidity: %x", Temperature,Humidity);
        createPacket(Msg,Temperature,Humidity,DEVICE_ID);

       //cc112xSpiWriteTxFifo(TXBuff, sizeof(TXBuff));

        cc112xSpiWriteTxFifo(Msg, sizeof(Msg));
        trxSpiCmdStrobe(CC112X_STX);
//        sprintf(TxBuff0,"Packet Num: %d || Packet Data:",i)
//        sprintf(TxBuff1,"")

              //memset(TXBuff, 0, 32);


        __delay_cycles(1000000);
    }

}

