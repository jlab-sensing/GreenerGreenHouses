/*
 * main_tester.c
 *
 *  Created on: Sep 7, 2023
 *      Author: matth
 *
 */
//
//required libraries for example to work
#include <msp430.h>
#include <stdint.h>
#include "MSP430_I2C.h"
#include "HDC2021.h"
#include <gpio.h>
#include <hw_memmap.h>
#include <cs.h>
#include <string.h>
#include "smartRF1125.h"
#include "FR5969_CC1125.h"
#include "cc112x_spi.h"
#include "Uart.h"

#define DEBUG_UART

//
void EnterLPM3(void){
     CSCTL4 |= SMCLKOFF;
     CSCTL6 |= SMCLKREQEN;
     __bis_SR_register(LPM3_bits | GIE);
}

void ExitLPM3(void){
      CSCTL4 &= ~SMCLKOFF;
      CSCTL6 &= ~ SMCLKREQEN;
}


int main()
{
    WDTCTL = WDTPW | WDTHOLD; //Disable Watchdog Timer
    PM5CTL0 &= ~LOCKLPM5;

    //variables to store raw temp and humidity values
    uint16_t Temperature, Humidity;

    //array to store packet information, filled in createPacket()
    uint8_t Msgg[4] = { 0 };

    //basic I2C library initialization
    initClockTo16MHz();
    initGPIO();
#ifdef DEBUG_UART
    //uart initialization, used for debugging
    InitUart(); // DONT USE IF U WANT LPM3
#endif
    //for some reason we have to init uart before i2c because they share euscia
    initI2C(HDC2021_ADDRESS);

    //SPI and CC1125 initialization
    trxRfSpiInterfaceInit(4);
    ConfigRegisters(PACKET_MODE);
    manualCalibration();

    //HDC2021 Initialization
    Sensor_Reset();
    Sensor_SetMeasurementMode(TEMP_AND_HUMID);
    Sensor_SetMeasurementRate(ONE_SECOND);
    Sensor_SetTempResolution(FOURTEEN_BIT);
    Sensor_SetHumidityResolution(FOURTEEN_BIT);

    //first measurement needs to be thrown away as HDC2021 stabilizes
    Sensor_TriggerMeasurement();
    Temperature = Sensor_ReadRawTemp();
    Humidity = Sensor_ReadRawHumidity();

    //Timer initialization for timed wakeup and low-power sleep
    InitTxTimer();


    //only entered when out of low power mode

    while (1)
    {
        //trigger and store measurements
        Sensor_TriggerMeasurement();
        Temperature = Sensor_ReadRawTemp();
        Humidity = Sensor_ReadRawHumidity();

        //create and send packet array based on temp,humidity, and
        //constant device ID set in FR5969_CC1125.h (0x0A)
        createPacket(Msgg, Temperature, Humidity, DEVICE_ID);
#ifdef DEBUG_UART
        putcha(Msgg[0]);
        putcha(Msgg[1]);
        putcha(Msgg[2]);
        putcha(Msgg[3]);
        putcha('\r');
        putcha('\n');
#endif

        cc112xSpiWriteTxFifo(Msgg, sizeof(Msgg));

        trxSpiCmdStrobe(CC112X_STX);

     CS_turnOffSMCLK();
    __bis_SR_register(LPM3_bits | GIE);


    }

}


// Timer A0 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A(void)
#elif defined(__GNUC__)
       void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer_A (void)
       #else
       #error Compiler not supported!
       #endif
{
    CS_turnOnSMCLK();
    __bic_SR_register_on_exit(LPM3_bits);
    //effectively clearing IF, resets to 1s rollover
    TA0CCR0 += 32678;                             // Add Offset to TACCR0
}



