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

uint8_t Msgg[4] = {0};


void initTimer(){
    TA0CCTL0 |= CCIE;
    TA0CCR0 = 32678;
    TA0CTL |= TASSEL__ACLK | MC__CONTINUOUS;
    __bis_SR_register(LPM0_bits | GIE);
}
int main()
{
    WDTCTL = WDTPW | WDTHOLD; //Disable Watchdog Timer
    PM5CTL0 &= ~LOCKLPM5;

    uint8_t Temperature, Humidity;
    //basic I2C library initialization
    initClockTo16MHz();
    initGPIO();

    InitUart();
    initI2C(HDC2021_ADDRESS);
    trxRfSpiInterfaceInit(4);
    initTimer();
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

    while (1){
        Sensor_TriggerMeasurement();
        Temperature = Sensor_ReadRawTemp();
        Humidity = Sensor_ReadRawHumidity();
        //transmit message "Test" with packet number after it every second
        createPacket(Msgg,Temperature,Humidity,DEVICE_ID);
        cc112xSpiWriteTxFifo(Msgg, sizeof(Msgg));
        trxSpiCmdStrobe(CC112X_STX);
        //Re-enter LP mode

    }

}


// Timer A0 interrupt service routine
       #if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
       #pragma vector = TIMER0_A0_VECTOR
       __interrupt void Timer_A (void)
       #elif defined(__GNUC__)
       void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer_A (void)
       #else
       #error Compiler not supported!
       #endif
       {

           //wake up from LP mode here
           TA0CCR0 += 32678;                             // Add Offset to TACCR0
       }

