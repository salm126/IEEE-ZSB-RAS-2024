/*
*    Created on: 16/07/2024
 *     Author: Salma Sameh
*/

#ifndef F_CPU
#define F_CPU 100000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include"LED_private.h"

void init_ADC() {
	// set reference voltage to AVcc and select ADC0
	ADMUX = (1 << REFS0);
	// Enable ADC and set prescaler to 128
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t Read_ADC() {
	// start conversion
	ADCSRA |= (1 << ADSC);
	// wait for conversion to complete
	while (ADCSRA & (1 << ADSC))
		;
	// Return ADC value
	return ADC;
}


int main() {

	init_ADC();
	// set PORTC and PORTD as output
	DDRC = 0xFF;
	DDRD = 0xFF;
	while (1) {
		uint16_t adc_value = Read_ADC();
		// map the ADC value to the number of LEDs (0-8)
		uint8_t num_leds = (adc_value * 8) / 1024;
		// turn on 8 LEDs when ADC value is maximum
		if (adc_value == 1023) {
			num_leds = 8;
			PORTC = 0xFF;
			PORTD = 0xFF;
		}
		control_led(num_leds);
		_delay_ms(100);
	}

	return 0;
}
