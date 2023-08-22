
//required libraries for example to work
#include <msp430.h>
#include <stdint.h>
#include "UART.h"




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

    // Configure GPIO
      P2SEL1 |= BIT0 | BIT1;                    // USCI_A0 UART operation
      P2SEL0 &= ~(BIT0 | BIT1);

      // Disable the GPIO power-on default high-impedance mode to activate
      // previously configured port settings
      PM5CTL0 &= ~LOCKLPM5;

      // Startup clock system with max DCO setting ~8MHz
      CSCTL0_H = CSKEY >> 8;                    // Unlock clock registers
      CSCTL1 = DCOFSEL_3 | DCORSEL;             // Set DCO to 8MHz
      CSCTL2 = SELA__VLOCLK | SELS__DCOCLK | SELM__DCOCLK;
      CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1;     // Set all dividers
      CSCTL0_H = 0;                             // Lock CS registers

      // Configure USCI_A0 for UART mode
      UCA0CTLW0 = UCSWRST;                      // Put eUSCI in reset
      UCA0CTLW0 |= UCSSEL__SMCLK;               // CLK = SMCLK
      // Baud Rate calculation
      // 8000000/(16*9600) = 52.083
      // Fractional portion = 0.083
      // User's Guide Table 21-4: UCBRSx = 0x04
      // UCBRFx = int ( (52.083-52)*16) = 1
      UCA0BR0 = 52;                             // 8000000/16/9600
      UCA0BR1 = 0x00;
      UCA0MCTLW |= UCOS16 | UCBRF_1;
      UCA0CTLW0 &= ~UCSWRST;                    // Initialize eUSCI


      //__bis_SR_register(LPM3_bits | GIE);       // Enter LPM3, interrupts enabled
      __no_operation();

      char message [] = "Hello World!";
      unsigned char message_len = sizeof(message);

      TXTransmit(message, message_len);

      while(1);

}

