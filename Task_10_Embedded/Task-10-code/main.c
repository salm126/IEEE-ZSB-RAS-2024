/*
 /*
 * main.c
 *
 *  Created on: 30/6/2024
 *      Author: Eng Salma Sameh
 */

#ifndef F_CPU
#define F_CPU 100000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

const char column[64] = {
		// #GAZA //
		0x6c, 0x3c, 0x38, 0xfe, 0x38, 0x00, 0x00, 0x00, 0x6c, 0x66, 0x6c, 0xc6,
		0x6c, 0x00, 0x00, 0x00, 0xfe, 0xc0, 0xc6, 0x8c, 0xc6, 0x00, 0x00, 0x00,
		0x6c, 0xc0, 0xfe, 0x18, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0xce, 0xc6, 0x32,
		0xc6, 0x00, 0x00, 0x00, 0x6c, 0x62, 0xc6, 0x66, 0xc6, 0x00, 0x00, 0x00,
		0x6c, 0x3e, 0xc6, 0xfe, 0xc6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, };
char i, scan = 0x01;

int main(void) {
	DDRA = 0xFF;
	DDRC = 0xFF;
	DDRB = 0xFF;

	while (1) {
		// Display the LED matrix for 1 seconds
		for (int j = 0; j < 20; j++) { // 20 iterations for 2 seconds (500us * 20 = 10000us)
			scan = 0x01;
			for (int i = 0; i < 64; i += 8) {
				PORTC = scan;

				PORTA = 0x01;
				PORTD = column[i];

				PORTA = 0x02;
				PORTD = column[i + 1];

				PORTA = 0x04;
				PORTD = column[i + 2];

				PORTA = 0x08;
				PORTD = column[i + 3];

				PORTA = 0x10;
				PORTD = column[i + 4];

				PORTA = 0x20;
				PORTD = column[i + 5];

				PORTA = 0x40;
				PORTD = column[i + 6];

				PORTA = 0x80;
				PORTD = column[i + 7];
				_delay_us(500);

				scan <<= 1;
			}
		}

		// Turn off the LED matrix for 1 seconds
		PORTA = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
		_delay_ms(500);
	}
}
