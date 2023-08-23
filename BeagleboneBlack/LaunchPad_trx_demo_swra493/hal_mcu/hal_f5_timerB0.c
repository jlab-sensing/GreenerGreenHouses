/******************************************************************************
 *  Filename: hal_f5_timerB0.c
 *
 *  Description: Timer abstration layer api
 *
 *  Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************/

#if defined (__MSP430F5438A__) || defined (__MSP430F5529__)
#include "msp430.h"
#include "hal_timer.h"

unsigned char volatile timer_event;
unsigned long volatile time_counter = 0;

/******************************************************************************
 * @fn         hal_timer_init
 *
 * @brief      Start packet timer using Timer using ACLK as reference
 *
 *
 * input parameters
 *
 * @param       unsigned int master_count - master packet timer value
 *
 * output parameters
 *
 * @return      void
 *
 */

void hal_timer_init(unsigned int master_count) {

  // Start Timer 0 using the ACLK as a source (this enables the use of
  // various low power modes). Timer 0 will be used to keep RF burst time
  TBCCR0  = master_count - 1;              // Seting for MASTER SCHEDULE
  TBCCR1  = 0;                             // will be used for burst alignnment
  TBCCR2  = 0;                             // will be used for expiration counter
  TBCTL   = TBSSEL_1 + MC_1 + TBCLR + ID_0;// ACLK, Up to CCR0, clear TB0R, div/1

  return;
}


/******************************************************************************
 * @fn         hal_timer_adjust
 *
 * @brief      Align packet timer by modifying the main count value
 *
 *
 * input parameters
 *
 * @param       unsigned int adjust - modify the timer count value
 *
 * output parameters
 *
 * @return      void
 *
 */
void hal_timer_adjust(unsigned int adjust) {

  TB0R = adjust;      

  return;
}

/******************************************************************************
 * @fn         hal_timer_get
 *
 * @brief      Get the current timer count value
 *
 *
 * input parameters
 *
 * @param       void
 *
 * output parameters
 *
 * @return      unsigned int timer count value
 *
 */
unsigned int hal_timer_get(void) {

	return(TB0R);
}


/******************************************************************************
 * @fn         hal_timer_get_time
 *
 * @brief      Calculate the time in seconds and milliseconds after last reset
 *
 *
 * input parameters
 *
 * @param       unsigned long *sec - pointer to seconds counter value
 *              unsigned long *ms  - pointer to millisecond count value
 *
 * output parameters
 *
 * @return      unsigned int timer count value
 *
 */
unsigned int hal_timer_get_time(unsigned long *sec, unsigned long *ms) {

	unsigned int ms_uint;
	unsigned long ms_long;

	/* grap the time counter values from the global value */
	*sec = time_counter;

	/* grap the time counter value (1/32768) second resolution */
	ms_uint = TB0R;

	/* convert information to milliseconds */
	ms_long = (unsigned long)ms_uint * 1000;
	ms_long = ms_long>>15;
	*ms = ms_long;

	/* return count value */
	return(ms_uint);
}

/******************************************************************************
 * @fn         hal_timer_stop
 *
 * @brief      Stop the timer
 *
 *
 * input parameters
 *
 * @param       void
 *
 * output parameters
 *
 * @return      void
 *
 */

void hal_timer_stop(void) {

  /* clear timer configuration register, stopping the timer */
  TBCTL = 0;

  return;
}

/******************************************************************************
 * @fn         hal_timer_expire
 *
 * @brief      wait until the timer master count expires (for packet alignment)
 *
 *
 * input parameters
 *
 * @param       void
 *
 * output parameters
 *
 * @return      void
 *
 */
void hal_timer_expire(void) {
  
  /* enable timer interrupt */
  TBCCTL1 = CCIE;

  /* enter low power mode and wait */
  _BIS_SR(LPM0_bits + GIE);

  /* disable interrupt again */
  TBCCTL1 = 0;
  
  return;
}

/******************************************************************************
 * @fn         hal_timer_wait
 *
 * @brief      wait an asigned amount of time or until a GPIO event (packet)
 *
 *
 * input parameters
 *
 * @param       unsigned int time  - maximum time to wait
 *
 * output parameters
 *
 * @return      unsigned int time - actual time waited
 *
 */
unsigned int hal_timer_wait(unsigned int time) {
  unsigned int wait_count, TBR_init;

  TBR_init = TB0R;   // store the current value of the timer register
  wait_count = TBR_init + time;

  // if the requested wait time exceeds the TBCCR0 (max value) then make a loop
  while(wait_count > TBCCR0) {

	  // configure the timeout for 1 less than the master clock
	  TBCCR2  = TBCCR0-1;

	  // calculate the remaining wait time remaining
	  wait_count = wait_count - (TBCCR2 - TBR_init);

	  // do not count the initial timer values more that once, zero it out
	  timer_event = 0;
	  TBR_init = 0;

	  // enable interupts and wait for timer (or CC1x GDO ISR)
	  TBCCTL2 = CCIE;                       // interrupt enabled
	  _BIS_SR(LPM0_bits + GIE);             // Enter LPM0

      // check to see if the timer woke us up or not
	  if (timer_event == 0)
		  // it did not, return imidiately and note time actual delay
		  return (time - (wait_count - TB0R));
  }

  // in the case of loop, this executes the remaining wait, in the case of no
  // loop this is the only wait that gets executed

  /* define maximum timeout by using timer counter 2 */
  TBCCR2  = wait_count;

  /* enable interrupt */
  TBCCTL2 = CCIE;

  /* enter low power mode and wait for event (timer or radio) */
  _BIS_SR(LPM0_bits + GIE);

  /* disable interupts on CCR2 */
  TBCCTL2 = 0;

  /* return the time spend in sleep */
  return (time - (wait_count-TB0R));
}

/******************************************************************************
 * @fn         TIMERB0_ISR
 *
 * @brief      Timer interrupt service routine
 *
 *
 * input parameters
 *
 * @param       void
 *
 * output parameters
 *
 * @return      void
 *
 */
// Timer B0 interrupt service routine
#pragma vector=TIMERB0_VECTOR
__interrupt void TIMERB0_ISR (void) {
   //_BIC_SR_IRQ(LPM3_bits);                       // Clear LPM3 bits from 0(SR)      
}

/******************************************************************************
 * @fn         TIMERB0_ISR
 *
 * @brief      Timer interrupt service routine
 *
 *
 * input parameters
 *
 * @param       void
 *
 * output parameters
 *
 * @return      void
 *
 */
#pragma vector=TIMERB1_VECTOR
__interrupt void TIMERB1_ISR(void) {

	/* Any access, read or write, of the TBIV register automatically
	 * resets the highest "pending" interrupt flag. */

	switch( __even_in_range(TBIV,14) ) {
    case  TB0IV_NONE: break;               // No interrupt
    case  TB0IV_TBCCR1:                    // Used to wake up radio from sleep
      timer_event = TB0IV_TBCCR1;
      _BIC_SR_IRQ(LPM3_bits);              // Clear LPM3 bits from 0(SR)
      break;       
    case  TB0IV_TBCCR2:                    // Use as secondary timer function
       timer_event = TB0IV_TBCCR2;
      _BIC_SR_IRQ(LPM3_bits);              // Clear LPM3 bits from 0(SR)
      break;       
    case  TB0IV_TBCCR3:                    // CCR3 not used
    	break;
    case  TB0IV_TBCCR4:                    // CCR4 not used
    	break;
    case  TB0IV_TBCCR5:                    // CCR5 not used
    	break;
    case  TB0IV_TBCCR6:                    // CCR6 not used
    	break;
    case  TB0IV_TBIFG:                     // IFG not used
    	break;
    default:
    	break;
  }
}

#endif
