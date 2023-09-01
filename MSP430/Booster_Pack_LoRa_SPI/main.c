#include <driverlib/MSP430FR5xx_6xx/cs.h>
#include <driverlib/MSP430FR5xx_6xx/eusci_a_uart.h>
#include <driverlib/MSP430FR5xx_6xx/gpio.h>
#include <driverlib/MSP430FR5xx_6xx/inc/hw_memmap.h>
#include <driverlib/MSP430FR5xx_6xx/eusci_b_spi.h>
#include <driverlib/MSP430FR5xx_6xx/pmm.h>
#include <driverlib/MSP430FR5xx_6xx/wdt_a.h>
#include <intrinsics.h>
#include <msp430fr5969.h>
#include <stdint.h>
#include <msp430fr5xx_6xxgeneric.h>
#include <sys/_stdint.h>
#include <string.h>
//#include "cc112x_easy_link_reg_config.h"
#include "cc112x_spi.h"


/**
 * main.c
 */
uint16_t i;
uint16_t RXData = 0, TXData = 0;
uint8_t check = 0;

#define PARTNUM_ADD      0x8F
#define EXTENDED_ADD     0x2F

void putc(char c){
 EUSCI_A_UART_transmitData(EUSCI_A0_BASE,c);
}

void puts(char *s){
    int i= 0;
    int length = ((strlen(s)) - 1);

    for(i = length; i >= 0; i--)
    {
        putc(s[length - i]);
    }
}

uint8_t get_device_number(uint8_t* pData, int len) {
    uint8_t readVal;
    //0x8000 leftmost READ REQUEST bit
    uint16_t TXRequest = 0x8000 | (EXTENDED_ADD << 8) | PARTNUM_ADD;

    EUSCI_B_SPI_transmitData(EUSCI_B0_BASE,TXRequest);
    readVal = EUSCI_B_SPI_receiveData(EUSCI_B0_BASE);
    while(!(UCB0IFG & UCRXIFG));

    EUSCI_B_SPI_transmitData(EUSCI_B0_BASE, (EXTENDED_ADD << 8) | PARTNUM_ADD);
    while(!(UCB0IFG & UCRXIFG));

    int i;
    for(i = 0; i < len; i++) {
        EUSCI_B_SPI_transmitData(EUSCI_B0_BASE, 0);
        while(!(UCB0IFG & UCRXIFG));
        EUSCI_B_SPI_transmitData(EUSCI_B0_BASE, *pData);
        *pData++;
    }
    return readVal;
}



//#define UART_TEST
#define SPI_TEST

int DeviceID1 = 0x0;
int DeviceID2 = 0x0;
int RealID[8] = {0};
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

#ifdef SPI_TEST
	    volatile uint16_t i;

	    //Stop watchdog timer
	    WDT_A_hold(WDT_A_BASE);

	    /*
	     * Select Port 1
	     * Set Pin 0 as output
	     */
	    GPIO_setAsOutputPin(
	        GPIO_PORT_P1,
	        GPIO_PIN0
	    );
	    /*
	    * Select Port 1
	    * Set Pin 0 to output Low.
	    */
	    GPIO_setOutputLowOnPin(
	        GPIO_PORT_P1,
	        GPIO_PIN0
	    );

	    //Set DCO frequency to max DCO setting
	    CS_setDCOFreq(CS_DCORSEL_0,CS_DCOFSEL_3);
	    //Select DCO as the clock source for SMCLK with no frequency divider
	    CS_initClockSignal(CS_SMCLK,CS_DCOCLK_SELECT,CS_CLOCK_DIVIDER_1);

	    /*
	    * Select Port 2
	    * Set Pin 2 to input Secondary Module Function, (UCB0CLK).
	    */
	    GPIO_setAsPeripheralModuleFunctionInputPin(
	        GPIO_PORT_P2,
	        GPIO_PIN2,
	        GPIO_SECONDARY_MODULE_FUNCTION
	    );

	    /*
	    * Select Port 1
	    * Set Pin 6, 7 to input Secondary Module Function, (UCB0TXD/UCB0SIMO, UCB0RXD/UCB0SOMI).
	    */
	    GPIO_setAsPeripheralModuleFunctionInputPin(
	        GPIO_PORT_P1,
	        GPIO_PIN6 + GPIO_PIN7,
	        GPIO_SECONDARY_MODULE_FUNCTION
	    );

	    /*
	    * Disable the GPIO power-on default high-impedance mode to activate
	    * previously configured port settings
	    */
	    PMM_unlockLPM5();

	    //Initialize Master
	    EUSCI_B_SPI_initMasterParam param = {0};
	    param.selectClockSource = EUSCI_B_SPI_CLOCKSOURCE_SMCLK;
	    param.clockSourceFrequency = CS_getSMCLK();
	    param.desiredSpiClock = 115200;
	    param.msbFirst = EUSCI_B_SPI_MSB_FIRST;
	    param.clockPhase = EUSCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT;
	    param.clockPolarity = EUSCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH;
	    param.spiMode = EUSCI_B_SPI_3PIN;
	    EUSCI_B_SPI_initMaster(EUSCI_B0_BASE, &param);

	    //Enable SPI module
	    EUSCI_B_SPI_enable(EUSCI_B0_BASE);

	    EUSCI_B_SPI_clearInterrupt(EUSCI_B0_BASE,
	            EUSCI_B_SPI_RECEIVE_INTERRUPT);
	    // Enable USCI_B0 RX interrupt
	    EUSCI_B_SPI_enableInterrupt(EUSCI_B0_BASE,
	        EUSCI_B_SPI_RECEIVE_INTERRUPT);

	    //Wait for slave to initialize
	    //__delay_cycles(100);

	    TXData = 0x2F8F;                             // Holds TX data

	    //USCI_B0 TX buffer ready?
	    while (!EUSCI_B_SPI_getInterruptStatus(EUSCI_B0_BASE,
	        EUSCI_B_SPI_TRANSMIT_INTERRUPT)) ;

//	    //Transmit Data to slave
//	    EUSCI_B_SPI_transmitData(EUSCI_B0_BASE,TXData);
//	    DeviceID1 = EUSCI_B_SPI_receiveData(EUSCI_B0_BASE);

	    uint8_t readVal;
	    unsigned char deviceNum;
	    readVal = get_device_number(&deviceNum, 1);


//	    for(i = 0; i < 8; i++){
//	        EUSCI_B_SPI_transmitData(EUSCI_B0_BASE,0x0);
//	        RealID[i] = EUSCI_B_SPI_receiveData(EUSCI_B0_BASE);
//	    }





	  //  __bis_SR_register(LPM0_bits + GIE);      // CPU off, enable interrupts
	  //  __no_operation();                       // Remain in LPM0


#endif
	}

/************************************************************************
 ***************************   INTERRUPTS   *****************************
 ***********************************************************************/


//***********UART********************************************************
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
//**********************************************************************
//**********************************************************************

//***********SPI********************************************************


#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=USCI_B0_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(USCI_B0_VECTOR)))
#endif
void USCI_B0_ISR (void)
{
    switch (__even_in_range(UCB0IV, USCI_SPI_UCTXIFG))
    {
        case USCI_SPI_UCRXIFG:      // UCRXIFG
            //USCI_B0 TX buffer ready?
            while (!EUSCI_B_SPI_getInterruptStatus(EUSCI_B0_BASE,
                        EUSCI_B_SPI_TRANSMIT_INTERRUPT));

            RXData = EUSCI_B_SPI_receiveData(EUSCI_B0_BASE);
//
//            //Increment data
//            TXData++;
//
//            //Send next value
//            EUSCI_B_SPI_transmitData(EUSCI_B0_BASE,
//                TXData
//                );
//
//            //Delay between transmissions for slave to process information
//            __delay_cycles(40);
            break;
        default:
            break;
    }
}

//**********************************************************************
//**********************************************************************
