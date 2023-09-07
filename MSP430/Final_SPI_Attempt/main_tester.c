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

#define MSG_SIZE 256

    char Message[MSG_SIZE] = {0};
    float Temperature,Humidity;


int main(){
    WDTCTL = WDTPW | WDTHOLD; //Disable Watchdog Timer
    PM5CTL0 &= ~LOCKLPM5;

    //basic I2C library initialization
    initClockTo16MHz();
    initGPIO();
    InitUart();
  initI2C(HDC2021_ADDRESS);

     // uint16_t Temperature,Humidity;
    //HDC2021 Initialization
    Sensor_Reset();
    Sensor_SetMeasurementMode(TEMP_AND_HUMID);
    Sensor_SetMeasurementRate(ONE_SECOND);
    Sensor_SetTempResolution(FOURTEEN_BIT);
    Sensor_SetHumidityResolution(FOURTEEN_BIT);
    Sensor_TriggerMeasurement();

    //first measurement needs to be thrown away as HDC2021 stabilizes
    Temperature = Sensor_ReadTemp();
    Humidity = Sensor_ReadHumidity();
//
//    //first valid measurements stored
//    Temperature = Sensor_ReadTemp();
//    Humidity = Sensor_ReadHumidity();
    //int j = 0;
    putstring("Beginning sensor integration with LoRa\r\n");
    while(1){
        //first valid measurements stored
        Sensor_TriggerMeasurement();
        Temperature = Sensor_ReadTemp();
        Humidity = Sensor_ReadHumidity();
        sprintf(Message,"Temperature: %f C    Humidity: %f %  \r\n",Temperature,Humidity);
        putstring(Message);
        memset(Message,0,MSG_SIZE);
        __delay_cycles(1000000);
    }
    return 0;
}

