/*
*  MSP430_I2C.c
 * Header file for implementation of I2C communication via MSP430EXPFR5969
 * Written in Code Composer Studio 12.4
 * Adapted from TI's msp430fr59xx_eusci_i2c_standard_master example
 * Created on: Aug 17, 2023
 * Author: Matthew Kaltman
 * Last Modified: 8/21/23
 */


#include <stdlib.h>
#include "MSP430_I2C.h"
#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>
#include "cs.h"
#include <stdio.h>

I2C_Mode MasterMode = IDLE_MODE;                        //Used to track the state of the software state machine

uint8_t TransmitRegAddr = 0;                                //The register address/command to use

uint8_t ReceiveBuffer[MAX_BUFFER_SIZE] = {0};               //Buffer used to receive data in the ISR
uint8_t RXByteCtr = 0;                                      //Number of bytes left to receive
uint8_t ReceiveIndex = 0;                                   //The index of the next byte to be received in ReceiveBuffer
uint8_t TransmitBuffer[MAX_BUFFER_SIZE] = {0};              //Buffer used to transmit data in the ISR
uint8_t TXByteCtr = 0;                                      //Number of bytes left to transfer
uint8_t TransmitIndex = 0;
uint8_t CopyIndex = 0;//The index of the next byte to be transmitted in transmitBuffer


I2C_Mode I2C_Controller_ReadReg(uint8_t dev_addr, uint8_t reg_addr, uint8_t count)
{
    /* Initialize state machine */
    MasterMode = TX_REG_ADDRESS_MODE;
    TransmitRegAddr = reg_addr;
    RXByteCtr = count;
    TXByteCtr = 0;
    ReceiveIndex = 0;
    TransmitIndex = 0;

    /* Initialize slave address and interrupts */
    UCB2I2CSA = dev_addr;
    UCB2IFG &= ~(UCTXIFG + UCRXIFG);       // Clear any pending interrupts
    UCB2IE &= ~UCRXIE;                       // Disable RX interrupt
    UCB2IE |= UCTXIE;                        // Enable TX interrupt

    UCB2CTLW0 |= UCTR + UCTXSTT;             // I2C TX, start condition
    __bis_SR_register(LPM0_bits + GIE);              // Enter LPM0 w/ interrupts

    return MasterMode;

}

void CopyTxArray(uint8_t *source,uint8_t count);


void CopyTxArray(uint8_t *source,uint8_t count)
{
        for (CopyIndex = 0; CopyIndex < count; CopyIndex++)
        {
            TransmitBuffer[CopyIndex] = source[CopyIndex];
        }
}


I2C_Mode I2C_Controller_WriteReg(uint8_t dev_addr, uint8_t reg_addr, uint8_t *reg_data, uint8_t count)
{
    /* Initialize state machine */
    MasterMode = TX_REG_ADDRESS_MODE;
    TransmitRegAddr = reg_addr;

    //Copy register data to TransmitBuffer
    CopyTxArray(reg_data, count);

    TXByteCtr = count;
    RXByteCtr = 0;
    ReceiveIndex = 0;
    TransmitIndex = 0;

    /* Initialize slave address and interrupts */
    UCB2I2CSA = dev_addr;
    UCB2IFG &= ~(UCTXIFG + UCRXIFG);       // Clear any pending interrupts
    UCB2IE &= ~UCRXIE;                       // Disable RX interrupt
    UCB2IE |= UCTXIE;                        // Enable TX interrupt

    UCB2CTLW0 |= UCTR + UCTXSTT;             // I2C TX, start condition
    __bis_SR_register(LPM0_bits + GIE);              // Enter LPM0 w/ interrupts

    return MasterMode;
}


void CopyRxArray(uint8_t *dest, uint8_t count)
{
    for (CopyIndex = 0; CopyIndex < count; CopyIndex++)
    {
        dest[CopyIndex] = ReceiveBuffer[CopyIndex];
    }
}

void initGPIO()
{
    // I2C pins
       P7SEL0 |= BIT0 | BIT1;
       P7SEL1 &= ~(BIT0 | BIT1);

    // Disable the GPIO power-on default high-impedance mode to activate
    // previously configured port settings
    UCB0CTLW0 |= UCSWRST;
    PM5CTL0 &= ~LOCKLPM5;
}

void initClockTo16MHz()
{

    // Configure one FRAM waitstate as required by the device datasheet for MCLK
     // operation beyond 8MHz _before_ configuring the clock system.
     FRCTL0 = FRCTLPW | NWAITS_1;

     // Clock System Setup
     CSCTL0_H = CSKEY_H;                     // Unlock CS registers
     CSCTL1 = DCOFSEL_0;                     // Set DCO to 1MHz

     // Set SMCLK = MCLK = DCO, ACLK = LFXTCLK (VLOCLK if unavailable)
     CSCTL2 = SELA__LFXTCLK | SELS__DCOCLK | SELM__DCOCLK;

     // Per Device Errata set divider to 4 before changing frequency to
     // prevent out of spec operation from overshoot transient
     CSCTL3 = DIVA__4 | DIVS__4 | DIVM__4;   // Set all corresponding clk sources to divide by 4 for errata
     CSCTL1 = DCOFSEL_4 | DCORSEL;           // Set DCO to 16MHz

     // Delay by ~10us to let DCO settle. 60 cycles = 20 cycles buffer + (10us / (1/4MHz))
     __delay_cycles(60);
     CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1;   // Set all dividers to 1 for 16MHz operation
     CSCTL0_H = 0;                           // Lock CS registers
}

void initI2C(uint8_t dev_add)
{
    UCB2CTLW0 = UCSWRST;                      // Enable SW reset
       UCB2CTLW0 |= UCMODE_3 | UCMST | UCSSEL__SMCLK | UCSYNC; // I2C master mode, SMCLK
       UCB2BRW = 160;                            // fSCL = SMCLK/160 = ~100kHz
       UCB2I2CSA = dev_add;                   // Slave Address
       UCB2CTLW0 &= ~UCSWRST;                    // Clear SW reset, resume operation
       UCB2IE |= UCNACKIE;
}


void InitTxTimer(void){
    TA0CCTL0 |= CCIE;
    TA0CCR0 = 32678;
    TA0CTL |= TASSEL__ACLK | MC__CONTINUOUS;

    __bis_SR_register(LPM0_bits | GIE);
}



//******************************************************************************
// I2C Interrupt ***************************************************************
//******************************************************************************

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = USCI_B2_VECTOR
__interrupt void USCI_B2_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(USCI_B2_VECTOR))) USCI_B2_ISR (void)
#else
#error Compiler not supported!
#endif
{
  //Must read from UCB2RXBUF
  uint8_t rx_val = 0;
  switch(__even_in_range(UCB2IV, USCI_I2C_UCBIT9IFG))
  {
    case USCI_NONE:          break;         // Vector 0: No interrupts
    case USCI_I2C_UCALIFG:   break;         // Vector 2: ALIFG
    case USCI_I2C_UCNACKIFG:                // Vector 4: NACKIFG
      break;
    case USCI_I2C_UCSTTIFG:  break;         // Vector 6: STTIFG
    case USCI_I2C_UCSTPIFG:  break;         // Vector 8: STPIFG
    case USCI_I2C_UCRXIFG3:  break;         // Vector 10: RXIFG3
    case USCI_I2C_UCTXIFG3:  break;         // Vector 12: TXIFG3
    case USCI_I2C_UCRXIFG2:  break;         // Vector 14: RXIFG2
    case USCI_I2C_UCTXIFG2:  break;         // Vector 16: TXIFG2
    case USCI_I2C_UCRXIFG1:  break;         // Vector 18: RXIFG1
    case USCI_I2C_UCTXIFG1:  break;         // Vector 20: TXIFG1
    case USCI_I2C_UCRXIFG0:                 // Vector 22: RXIFG0
        rx_val = UCB2RXBUF;
        if (RXByteCtr)
        {
          ReceiveBuffer[ReceiveIndex++] = rx_val;
          RXByteCtr--;
        }

        if (RXByteCtr == 1)
        {
          UCB2CTLW0 |= UCTXSTP;
        }
        else if (RXByteCtr == 0)
        {
          UCB2IE &= ~UCRXIE;
          MasterMode = IDLE_MODE;
          __bic_SR_register_on_exit(CPUOFF);      // Exit LPM0
        }
        break;
    case USCI_I2C_UCTXIFG0:                 // Vector 24: TXIFG0
        switch (MasterMode)
        {
          case TX_REG_ADDRESS_MODE:
              UCB2TXBUF = TransmitRegAddr;
              if (RXByteCtr)
                  MasterMode = SWITCH_TO_RX_MODE;   // Need to start receiving now
              else
                  MasterMode = TX_DATA_MODE;        // Continue to transmision with the data in Transmit Buffer
              break;

          case SWITCH_TO_RX_MODE:
              UCB2IE |= UCRXIE;              // Enable RX interrupt
              UCB2IE &= ~UCTXIE;             // Disable TX interrupt
              UCB2CTLW0 &= ~UCTR;            // Switch to receiver
              MasterMode = RX_DATA_MODE;    // State state is to receive data
              UCB2CTLW0 |= UCTXSTT;          // Send repeated start
              if (RXByteCtr == 1)
              {
                  //Must send stop since this is the N-1 byte
                  while((UCB2CTLW0 & UCTXSTT));
                  UCB2CTLW0 |= UCTXSTP;      // Send stop condition
              }
              break;

          case TX_DATA_MODE:
              if (TXByteCtr)
              {
                  UCB2TXBUF = TransmitBuffer[TransmitIndex++];
                  TXByteCtr--;
              }
              else
              {
                  //Done with transmission
                  UCB2CTLW0 |= UCTXSTP;     // Send stop condition
                  MasterMode = IDLE_MODE;
                  UCB2IE &= ~UCTXIE;                       // disable TX interrupt
                  __bic_SR_register_on_exit(CPUOFF);      // Exit LPM0
              }
              break;

          default:
              __no_operation();
              break;
        }
        break;
    default: break;
  }
}
////******************************************************************************
//// I2C Interrupt ***************************************************************
////******************************************************************************
//
//#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
//#pragma vector = USCI_B0_VECTOR
//__interrupt void USCI_B0_ISR(void)
//#elif defined(__GNUC__)
//void __attribute__ ((interrupt(USCI_B0_VECTOR))) USCI_B0_ISR (void)
//#else
//#error Compiler not supported!
//#endif
//{
//  //Must read from UCB0RXBUF
//  uint8_t rx_val = 0;
//  switch(__even_in_range(UCB0IV, USCI_I2C_UCBIT9IFG))
//  {
//    case USCI_NONE:          break;                         // Vector 0: No interrupts
//    case USCI_I2C_UCALIFG:   break;                         // Vector 2: ALIFG
//    case USCI_I2C_UCNACKIFG:                                // Vector 4: NACKIFG
//      break;
//    case USCI_I2C_UCSTTIFG:  break;                         // Vector 6: STTIFG
//    case USCI_I2C_UCSTPIFG:  break;                         // Vector 8: STPIFG
//    case USCI_I2C_UCRXIFG3:  break;                         // Vector 10: RXIFG3
//    case USCI_I2C_UCTXIFG3:  break;                         // Vector 12: TXIFG3
//    case USCI_I2C_UCRXIFG2:  break;                         // Vector 14: RXIFG2
//    case USCI_I2C_UCTXIFG2:  break;                         // Vector 16: TXIFG2
//    case USCI_I2C_UCRXIFG1:  break;                         // Vector 18: RXIFG1
//    case USCI_I2C_UCTXIFG1:  break;                         // Vector 20: TXIFG1
//    case USCI_I2C_UCRXIFG0:                                 // Vector 22: RXIFG0
//        CS_enableClockRequest(CS_SMCLK);
//        rx_val = UCB0RXBUF;
//        if (RXByteCtr)
//        {
//          ReceiveBuffer[ReceiveIndex++] = rx_val;
//          RXByteCtr--;
//        }
//
//        if (RXByteCtr == 1)
//        {
//          UCB0CTLW0 |= UCTXSTP;
//        }
//        else if (RXByteCtr == 0)
//        {
//          UCB0IE &= ~UCRXIE;
//          ControllerMode = IDLE_MODE;
//          __bic_SR_register_on_exit(CPUOFF);                // Exit LPM0
//          CS_disableClockRequest(CS_SMCLK);
//        }
//        break;
//    case USCI_I2C_UCTXIFG0:                                 // Vector 24: TXIFG0
//        CS_enableClockRequest(CS_SMCLK);
//        switch (ControllerMode)
//        {
//          case TX_REG_ADDRESS_MODE:
//              UCB0TXBUF = TransmitRegAddr;
//              if (RXByteCtr)
//                  ControllerMode = SWITCH_TO_RX_MODE;       // Need to start receiving now
//              else
//                  ControllerMode = TX_DATA_MODE;            // Continue to transmision with the data in Transmit Buffer
//              break;
//
//          case SWITCH_TO_RX_MODE:
//              UCB0IE |= UCRXIE;                             // Enable RX interrupt
//              UCB0IE &= ~UCTXIE;                            // Disable TX interrupt
//              UCB0CTLW0 &= ~UCTR;                           // Switch to receiver
//              ControllerMode = RX_DATA_MODE;                // State state is to receive data
//              UCB0CTLW0 |= UCTXSTT;                         // Send repeated start
//              if (RXByteCtr == 1)
//              {
//                  //Must send stop since this is the N-1 byte
//                  while((UCB0CTLW0 & UCTXSTT));
//                  UCB0CTLW0 |= UCTXSTP;                     // Send stop condition
//              }
//              break;
//
//          case TX_DATA_MODE:
//              if (TXByteCtr)
//              {
//                  UCB0TXBUF = TransmitBuffer[TransmitIndex++];
//                  TXByteCtr--;
//              }
//              else
//              {
//                  //Done with transmission
//                  UCB0CTLW0 |= UCTXSTP;                     // Send stop condition
//                  ControllerMode = IDLE_MODE;
//                  UCB0IE &= ~UCTXIE;                        // disable TX interrupt
//                  __bic_SR_register_on_exit(CPUOFF);        // Exit LPM0
//                  CS_disableClockRequest(CS_SMCLK);
//              }
//              break;
//
//          default:
//              __no_operation();
//              break;
//        }
//        break;
//    default: break;
//  }
//}



