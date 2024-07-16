/*
 * LED_program.c
 *
 *  Created on: 16/07/2024
 *      Author: Salma Sameh
 */


#include <avr/io.h>
#include"LED_private.h"

void control_led(uint8_t num_leds) {
 // set PORTC and PORTD pins according to the number of LEDs to be turned on
	PORTC = 0x00;
	PORTD = 0x00;

	for (uint8_t i = 0; i < num_leds; i++) {
		switch (i) {
		case 0:
			PORTC |= (1 << 0);
			break;
		case 1:
			PORTC |= (1 << 1);
			break;
		case 2:
			PORTC |= (1 << 2);
			break;
		case 3:
			PORTC |= (1 << 3);
			break;
		case 4:
			PORTC |=0xff;
			PORTD |= (1 << 4);
			break;
		case 5:
			PORTC |=0xff;
			PORTD |= (1 << 5);
			break;
		case 6:
			PORTC |=0xff;
			PORTD |= (1 << 6);
			break;
		case 7:
			PORTC |=0xff;
			PORTD |= (1 << 7);
			break;
		case 8:
			PORTC |=0xff;
			PORTD |= (1 << 0);
			break;
		default:
			break;
		}
	}
}
