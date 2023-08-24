
//required libraries for example to work
#include <msp430.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "HDC2021.h"
#include "MSP430_I2C.h"
#include "UART.h"

#define ONE_SEC     16000000                            //16 million cycles equal 1 second wait time

float Temperature;
float Humidity;

int main(){
    WDTCTL = WDTPW | WDTHOLD; //Disable Watchdog Timer

    //basic I2C library initialization
    initClockTo16MHz();
    initGPIO();
    initI2C(HDC2021_ADDRESS);

    //basic UART library initialization
    UART_Init_GPIO();
    UART_Init();

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

    char temp_and_humidity_string[40] = {0};

    while(1) {
        Temperature = Sensor_ReadTemp();                                        //read Temperature and Humidity Data
        Humidity = Sensor_ReadHumidity();
        sprintf(temp_and_humidity_string, "%s%d%s%d%s", "Temp: ",               //Compile data into a singular string
                (int)Temperature, "°C   Humidity: ", (int)Humidity, "%\n\n");
        TXTransmit(temp_and_humidity_string,                                    //Transmit to TX buffer
                   strlen(temp_and_humidity_string));

       __delay_cycles(ONE_SEC);                                                 //Transmit to TX buffer
    }

}

