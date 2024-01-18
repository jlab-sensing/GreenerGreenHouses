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
#include "Uart.h"


//
//void EnterLPM3(void){
//     CSCTL4 |= SMCLKOFF;
//     CSCTL6 |= SMCLKREQEN;
//     __bis_SR_register(LPM3_bits | GIE);
//}
//
//void ExitLPM3(void){
//      CSCTL4 &= ~SMCLKOFF;
//      CSCTL6 &= ~ SMCLKREQEN;
//}


int main()
{
    WDTCTL = WDTPW | WDTHOLD; //Disable Watchdog Timer
    PM5CTL0 &= ~LOCKLPM5;

    //variables to store raw temp and humidity values
    uint16_t Temperature, Humidity;

    //array to store packet information, filled in createPacket()
 //   uint8_t Msgg[6] = { 0 };

    //basic I2C library initialization
    initClockTo16MHz();
    initGPIO();

    //uart initialization, used for debugging
    InitUart(); // DONT USE IF U WANT LPM3


    putstring("Beginning FR5994 Tests\r\n");
    //for some reason we have to init uart before i2c because they share euscia
    initI2C(HDC2021_ADDRESS);
    //putstring("Made it past initialization\r\n");


    //HDC2021 Initialization
    Sensor_Reset();
   // putstring("Made it past Sensor Initialization\r\n");
    Sensor_SetMeasurementMode(TEMP_AND_HUMID);
   // putstring("Made it past Sensor Initialization\r\n");
    Sensor_SetMeasurementRate(ONE_SECOND);
   // putstring("Made it past Sensor Initialization\r\n");
    Sensor_SetTempResolution(FOURTEEN_BIT);
   // putstring("Made it past Sensor Initialization\r\n");
    Sensor_SetHumidityResolution(FOURTEEN_BIT);
   // putstring("Made it past Sensor Initialization\r\n");
    //first measurement needs to be thrown away as HDC2021 stabilizes
    Sensor_TriggerMeasurement();
    Temperature = Sensor_ReadTemp();
    Humidity = Sensor_ReadHumidity();
    //putstring("Made it past Sensor Read\r\n");
    //Timer initialization for timed wakeup and low-power sleep
   // InitTxTimer();
    //putstring("Made it Timer\r\n");
    char Msg[256] = { 0 };
    //only entered when out of low power mode

    while (1)
    {
        //trigger and store measurements
        Sensor_TriggerMeasurement();
        Temperature = Sensor_ReadTemp();
        Humidity = Sensor_ReadHumidity();
       // putcha('a');
    //    putstring("HELLO\r\n");
                  //sprintf(Msg, "%d\r\n", Humidity);
                  sprintf(Msg,"Temp: %dC    Humidity: %d%% \r\n",Temperature, Humidity);
                  putstring(Msg);
                  memset(Msg, 0, 256);

//     CS_turnOffSMCLK();
//    __bis_SR_register(LPM3_bits | GIE);
//

    }

}

////
//// Timer A0 interrupt service routine
//#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
//#pragma vector = TIMER0_A0_VECTOR
//__interrupt void Timer_A(void)
//#elif defined(__GNUC__)
//       void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer_A (void)
//       #else
//       #error Compiler not supported!
//       #endif
//{
//    CS_turnOnSMCLK();
//    __bic_SR_register_on_exit(LPM3_bits);
//    //effectively clearing IF, resets to 1s rollover
//    TA0CCR0 += 32678;                             // Add Offset to TACCR0
//}



