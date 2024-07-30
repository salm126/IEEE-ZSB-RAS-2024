/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Hassan Sameh
 */

#ifndef F_CPU
#define F_CPU 800000UL
#endif
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "UART_interface.h"
#include "STD_TYPES.h"

int main(void) {
    DDRC = 0x07;  // PC0 = 0000 0111
    UART_init();

    while(1) {
        PORTC = UART_receiveByte();
        _delay_ms(100);
    }
}
