/*******************************************************************************
*  Filename:        hal_msp430.h
*  Revised:         $Date: 2014-01-10 14:24:45 +0100 (fr, 10 jan 2014) $
*  Revision:        $Revision: 11715 $
*
*  Description:     HAL defines for MSP430.
*
*  Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef HAL_MSP430_H
#define HAL_MSP430_H

/******************************************************************************
* INCLUDES
*/

#include <hal_types.h>
#include <hal_defs.h>
#include <hal_board.h>

/******************************************************************************
* MACROS
*/

#define MCU_IO_TRISTATE   1
#define MCU_IO_PULLUP     2
#define MCU_IO_PULLDOWN   3


//-----------------------------------------------------------------------------
//  Macros for simple configuration of IO pins on MSP430
//-----------------------------------------------------------------------------
#define MCU_IO_PERIPHERAL(port, pin)   MCU_IO_PERIPHERAL_PREP(port, pin)
#define MCU_IO_INPUT(port, pin, func)  MCU_IO_INPUT_PREP(port, pin, func)
#define MCU_IO_OUTPUT(port, pin, val)  MCU_IO_OUTPUT_PREP(port, pin, val)
#define MCU_IO_SET(port, pin, val)     MCU_IO_SET_PREP(port, pin, val)
#define MCU_IO_SET_HIGH(port, pin)     MCU_IO_SET_HIGH_PREP(port, pin)
#define MCU_IO_SET_LOW(port, pin)      MCU_IO_SET_LOW_PREP(port, pin)
#define MCU_IO_TGL(port, pin)          MCU_IO_TGL_PREP(port, pin)
#define MCU_IO_GET(port, pin)          MCU_IO_GET_PREP(port, pin)



//-----------------------------------------------------------------------------
// Safe polling for state change of variable set in interrupt context
//-----------------------------------------------------------------------------
#define SAFE_POLL(exit_condition, sleep_mode) \
    { istate_t key = halIntLock(); \
      while (!(exit_condition)) \
      { halMcuSetLowPowerMode((sleep_mode)); \
        key = halIntLock(); \
      } \
      halIntUnlock(key); }



//-----------------------------------------------------------------------------
//  Macros for internal use (the MCU_IO macros above need a new round in the 
//  preprocessor)
//-----------------------------------------------------------------------------
#define MCU_IO_PERIPHERAL_PREP(port, pin)  st( P##port##SEL |= BIT##pin##; )

#if defined(P1REN_) || defined(P1REN)
#define MCU_IO_INPUT_PREP(port, pin, func) st( P##port##SEL &= ~BIT##pin##; \
                                               P##port##DIR &= ~BIT##pin##; \
                                               switch (func) { \
                                               case MCU_IO_PULLUP: \
                                                   P##port##REN |= BIT##pin##; \
                                                   P##port##OUT |= BIT##pin##; \
                                                   break; \
                                               case MCU_IO_PULLDOWN: \
                                                   P##port##REN |= BIT##pin##; \
                                                   P##port##OUT &= ~BIT##pin##; \
                                                   break; \
                                               default: \
                                                   P##port##REN &= ~BIT##pin##; \
                                                   break; } )
#else
#define MCU_IO_INPUT_PREP(port, pin, func) st( P##port##SEL &= ~BIT##pin##; \
                                               P##port##DIR &= ~BIT##pin##; )
#endif

#define MCU_IO_OUTPUT_PREP(port, pin, val) st( P##port##SEL &= ~BIT##pin##; \
                                               MCU_IO_SET(port, pin, val); \
                                               P##port##DIR |= BIT##pin##; )

#define MCU_IO_SET_HIGH_PREP(port, pin)    st( P##port##OUT |= BIT##pin##; )
#define MCU_IO_SET_LOW_PREP(port, pin)     st( P##port##OUT &= ~BIT##pin##; )

#define MCU_IO_SET_PREP(port, pin, val)    st( if (val) \
                                                   { MCU_IO_SET_HIGH(port, pin); } \
                                               else \
                                                   { MCU_IO_SET_LOW(port, pin); })

#define MCU_IO_TGL_PREP(port, pin)         st( P##port##OUT ^= BIT##pin##; )
#define MCU_IO_GET_PREP(port, pin)         (P##port##IN & BIT##pin##)


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


/* Code Composer support */

#if defined __TI_COMPILER_VERSION__
#define NOP()  _nop()
#define _PRAGMA(x) _Pragma(#x)

#define HAL_ISR_FUNC_DECLARATION(f,v)   \
    _PRAGMA(vector=v##_VECTOR) __interrupt void f(void)
#define HAL_ISR_FUNC_PROTOTYPE(f,v)     \
    _PRAGMA(vector=v##_VECTOR) __interrupt void f(void)
#define HAL_ISR_FUNCTION(f,v) HAL_ISR_FUNC_DECLARATION(f,v)


/*
 * Control bits in the processor status register, SR.
 */

#define __SR_GIE     (1<<3)
#define __SR_CPU_OFF (1<<4)
#define __SR_OSC_OFF (1<<5)
#define __SR_SCG0    (1<<6)
#define __SR_SCG1    (1<<7)


/*
 * Functions for controlling the processor operation modes.
 */

#define __low_power_mode_0() (__bis_SR_register(  __SR_GIE      \
                                                | __SR_CPU_OFF))

#define __low_power_mode_1() (__bis_SR_register(  __SR_GIE      \
                                                | __SR_CPU_OFF  \
                                                | __SR_SCG0))

#define __low_power_mode_2() (__bis_SR_register(  __SR_GIE      \
                                                | __SR_CPU_OFF  \
                                                | __SR_SCG1))

#define __low_power_mode_3()                    \
  (_bis_SR_register(  __SR_GIE                  \
                     | __SR_CPU_OFF             \
                     | __SR_SCG0                \
                     | __SR_SCG1))

#define __low_power_mode_4()                    \
  (_bis_SR_register(  __SR_GIE                  \
                     | __SR_CPU_OFF             \
                     | __SR_SCG0                \
                     | __SR_SCG1                \
                     | __SR_OSC_OFF))

#define __low_power_mode_off_on_exit()          \
  (_bic_SR_register_on_exit(  __SR_CPU_OFF      \
                             | __SR_SCG0        \
                             | __SR_SCG1        \
                             | __SR_OSC_OFF))

#endif
#endif
