#ifndef F_CPU
#define F_CPU 1000000UL
#endif
/*
 *    Created on: 22/07/2024
 *     Author: Salma Sameh
 */
#include <avr/io.h>
#include <avr/interrupt.h>

#include "DIO_interface.h"
#include "LED_interface.h"
#include "TIMER_interface.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

volatile uint8_t tot_overflow;
volatile uint8_t led_state = 0;

void timer0_init() {
	TCCR0 = (1 << CS02);
	TCNT0 = 0;
	TIMSK = (1 << TOIE0);
	sei();
	tot_overflow = 0;
}

void timer1_init() {
	TCCR1B |= (1 << WGM12) | (1 << CS12);
	TCNT1 = 0;
	OCR1A = 62500;
	TIMSK |= (1 << OCIE1A);
}

void timer2_init() {
	TCCR2 |= (1 << WGM21) | (1 << WGM20) | (1 << CS22) | (1 << CS21)
			| (1 << CS20);
	TCNT2 = 0;
	OCR2 = 250;
	TIMSK |= (1 << TOIE2);
}

ISR(TIMER0_OVF_vect) {
	tot_overflow++;
}

ISR(TIMER1_COMPA_vect) {
	PORTC ^= (1 << 1);
}

ISR(TIMER2_OVF_vect) {
	led_state = (led_state + 1) % 8;
	PORTB = (PORTB & ~(0b111 << PB3)) | (led_state << PB3);
}

int main(void) {
	DDRB |= (1 << PB0) | (1 << PB3);
	DDRC |= (1 << PC1);

	timer0_init();
	timer1_init();
	timer2_init();

	while (1) {
		if (tot_overflow >= 12) {
			if (TCNT0 >= 53) {
				PORTB ^= (1 << PB0);
				TCNT0 = 0;
				tot_overflow = 0;
			}
		}
	}
}
