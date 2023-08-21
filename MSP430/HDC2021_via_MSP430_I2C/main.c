
//required libraries for example to work
#include <msp430.h>
#include "MSP430_I2C.h"
#include <stdint.h>
#include "HDC2021.h"



//global to view value in debug memory
uint16_t Temperature = 0;
uint16_t Humidity = 0;

int main(){
    WDTCTL = WDTPW | WDTHOLD; //Disable Watchdog Timer

//    //basic I2C library initialization
//    initClockTo16MHz();
//    initGPIO();
//    initI2C(HDC2021_ADDRESS);
//
//
//    //HDC2021 Initialization
//    Sensor_Reset();
//    Sensor_SetMeasurementMode(TEMP_AND_HUMID);
//    Sensor_SetMeasurementRate(ONE_SECOND);
//    Sensor_SetTempResolution(FOURTEEN_BIT);
//    Sensor_SetHumidityResolution(FOURTEEN_BIT);
//    Sensor_TriggerMeasurement();
//
//    //first measurement needs to be thrown away as HDC2021 stabilizes
//    Temperature = Sensor_ReadTemp();
//    Humidity = Sensor_ReadHumidity();
//
//    //first valid measurements stored
//    Temperature = Sensor_ReadTemp();
//    Humidity = Sensor_ReadHumidity();

    uint8_t* message = "Hello World!";
    uint8_t message_len = sizeof(message);

    UART_Init_GPIO();
    UART_Init_Clock();
    UART_Init();

    TXTransmit(message, message_len);

 return 0;
}


