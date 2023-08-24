
//required libraries for example to work
#include <msp430.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "HDC2021.h"
#include "MSP430_I2C.h"
#include "UART.h"

float Temperature;
float Humidity;

//char test[] = "Test";

int main(){
    WDTCTL = WDTPW | WDTHOLD; //Disable Watchdog Timer

    //basic I2C library initialization
    initClockTo16MHz();
    initGPIO();
    initI2C(HDC2021_ADDRESS);

    //basic UART library initialization
    //UART_Init_GPIO();
    //UART_Init();

    //TXTransmit(test, strlen(test));

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

    //first valid measurements stored
    Temperature = Sensor_ReadTemp();
    Humidity = Sensor_ReadHumidity();

    //char temp_string[40] = {0};
    //char hum_string[40] = {0};
    //int i = 0;

//    sprintf(temp_string, "%s%d", "Temp: \n", (int)Temperature);
//
//    while(1) {
//        Temperature = Sensor_ReadTemp();
//        sprintf(temp_string, "%s%d", "Temp: ", (int)Temperature);
//        TXTransmit(temp_string, strlen(temp_string));
//
//        for(i = 0; i < 1000000; i++) {
//            _NOP();
//        }
//    }

}

