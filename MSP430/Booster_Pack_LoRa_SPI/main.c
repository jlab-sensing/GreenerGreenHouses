#include <driverlib/MSP430FR5xx_6xx/cs.h>
#include <driverlib/MSP430FR5xx_6xx/eusci_a_uart.h>
#include <driverlib/MSP430FR5xx_6xx/gpio.h>
#include <driverlib/MSP430FR5xx_6xx/inc/hw_memmap.h>
#include <driverlib/MSP430FR5xx_6xx/pmm.h>
#include <driverlib/MSP430FR5xx_6xx/wdt_a.h>
#include <intrinsics.h>
#include <msp430fr5969.h>
#include <msp430fr5xx_6xxgeneric.h>
#include <sys/_stdint.h>
#include <string.h>


/**
 * main.c
 */
uint16_t i;
uint8_t RXData = 0, TXData = 0;
uint8_t check = 0;


void putc(char c){
 EUSCI_A_UART_transmitData(EUSCI_A0_BASE,c);
}

void puts(char *s){
    int i= 0;
    int length = strlen(s);
    for(i = 0; i <= length-1; i++)
    {
        putc(s[i]);
    }
}

//#define UART_TEST
#define SPI_TEST

int main(void)
{
#ifdef UART_TEST
    WDT_A_hold(WDT_A_BASE);// stop watchdog timer
    // LFXT Setup
      //Set PJ.4 and PJ.5 as Primary Module Function Input.
      /*

      * Select Port J
      * Set Pin 4, 5 to input Primary Module Function, LFXT.
      */
      GPIO_setAsPeripheralModuleFunctionInputPin(
          GPIO_PORT_PJ,
          GPIO_PIN4 + GPIO_PIN5,
          GPIO_PRIMARY_MODULE_FUNCTION
      );

      //Set DCO frequency to 1 MHz
      CS_setDCOFreq(CS_DCORSEL_0,CS_DCOFSEL_0);
      //Set external clock frequency to 32.768 KHz
      CS_setExternalClockSource(32768,0);
      //Set ACLK=LFXT
      CS_initClockSignal(CS_ACLK,CS_LFXTCLK_SELECT,CS_CLOCK_DIVIDER_1);
      //Set SMCLK = DCO with frequency divider of 1
      CS_initClockSignal(CS_SMCLK,CS_DCOCLK_SELECT,CS_CLOCK_DIVIDER_1);
      //Set MCLK = DCO with frequency divider of 1
      CS_initClockSignal(CS_MCLK,CS_DCOCLK_SELECT,CS_CLOCK_DIVIDER_1);
      //Start XT1 with no time out
      CS_turnOnLFXT(CS_LFXT_DRIVE_0);


      // Configure UART pins
      //Set P2.0 and P2.1 as Secondary Module Function Input.
      /*

      * Select Port 2d
      * Set Pin 0, 1 to input Secondary Module Function, (UCA0TXD/UCA0SIMO, UCA0RXD/UCA0SOMI).
      */
      GPIO_setAsPeripheralModuleFunctionInputPin(
      GPIO_PORT_P2,
      GPIO_PIN0 + GPIO_PIN1,
      GPIO_SECONDARY_MODULE_FUNCTION
      );

      /*
       * Disable the GPIO power-on default high-impedance mode to activate
       * previously configured port settings
       */
      PMM_unlockLPM5();
    EUSCI_A_UART_initParam param;
    param.selectClockSource = EUSCI_A_UART_CLOCKSOURCE_SMCLK;
    param.clockPrescalar = 0x6;
    param.firstModReg = 0x8;
    param.secondModReg = 0x11;
    param.parity = EUSCI_A_UART_NO_PARITY;
    param.msborLsbFirst = EUSCI_A_UART_LSB_FIRST;
    param.numberofStopBits = EUSCI_A_UART_ONE_STOP_BIT;
    param.uartMode = EUSCI_A_UART_MODE;
    param.overSampling = 0x1;


    if(STATUS_FAIL ==EUSCI_A_UART_init(EUSCI_A0_BASE,&param)){
        return 0;
    }

	EUSCI_A_UART_enable(EUSCI_A0_BASE);
	   EUSCI_A_UART_clearInterrupt(EUSCI_A0_BASE,
	      EUSCI_A_UART_RECEIVE_INTERRUPT);

	    // Enable USCI_A0 RX interrupt
	    EUSCI_A_UART_enableInterrupt(EUSCI_A0_BASE,
	      EUSCI_A_UART_RECEIVE_INTERRUPT);                     // Enable interrupt

	    __enable_interrupt();

	    char test_string1[] = {"Hello World!\r\n"};

	    char test_string2[] = {"test 2\r\n"};
	    puts(test_string1);
	    puts(test_string2);

	    return 0;
#endif

//#ifdef SPI_TEST
//WDT_A_hold(WDT_A_BASE);// stop watchdog timer
//
//
//PMM_unlockLPM5();
//
//
//#endif
	}


#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=USCI_A0_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(USCI_A0_VECTOR)))
#endif
void USCI_A0_ISR(void)
{
  switch(__even_in_range(UCA0IV,USCI_UART_UCTXCPTIFG))
  {
    case USCI_NONE: break;
    case USCI_UART_UCRXIFG:
      RXData = EUSCI_A_UART_receiveData(EUSCI_A0_BASE);

      break;
    case USCI_UART_UCTXIFG: break;
    case USCI_UART_UCSTTIFG: break;
    case USCI_UART_UCTXCPTIFG: break;
  }
}
