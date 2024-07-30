/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Hassan Sameh
 */


#ifndef F_CPU
#define F_CPU 800000UL
#endif

#include<avr/io.h>
#include<util/delay.h>
#include "UART_interface.h"
#include "STD_TYPES.h"

u8  count =0;
int main(void) {

	UART_init ();

	while (1) {

   if(count <=10){
    UART_sendByte(count);
    _delay_ms(100);
   }


   count++;
	}

}
