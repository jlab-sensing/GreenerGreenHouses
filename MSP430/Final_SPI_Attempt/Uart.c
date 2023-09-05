/*
 * Uart.c
 *
 *  Created on: Sep 5, 2023
 *      Author: matth
 */


/*
* transmits character over UART TX transmission
* param: c, char type, single character to transmit
*/

#include "Uart.h"
void putcha(char c){

 EUSCI_A_UART_transmitData(EUSCI_A0_BASE,c);

}


/*
* transmits whole string over UART TX transmission, one character at a time using
* putcha
* param: *s, char pointer to string to transmit
*/
void putstring(char *s){
    int i= 0;
    int length = ((strlen(s)) - 1);

    for(i = length; i >= 0; i--)
    {
        putcha(s[length - i]);
    }
}
