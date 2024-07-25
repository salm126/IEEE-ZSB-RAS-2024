/*
 * main.c
 *
 *  Created on: 25/7/2024
 *      Author: Salma Sameh
 */

#ifndef F_CPU
#define F_CPU 100000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

void adjustDutyCycle(void) {
    static unsigned char temp = 0;

    // Increase duty cycle
    if ((PINC & 0x01) == 0) {
        _delay_ms(250);
        if (temp < 90) temp += 10;
    }

    // Reset duty cycle
    if ((PINC & 0x02) == 0) {
        _delay_ms(250);
        temp = 0;
    }

    // Decrease duty cycle
    if ((PINC & 0x04) == 0) {
        _delay_ms(250);
        if (temp > 0) temp -= 10;
    }

    // Duty cycle adjust
    OCR0 = (0xFF * temp) / 100;
}

int main(void) {
    // Set PORTC pins 0, 1, and 2 as digital inputs
    DDRC = 0xf8;
    PORTC = 0x07;

   // Clear duty cycle
    OCR0 = 0x00;

    // Set DDRB pin 3 as output
    DDRB = (1 << 3);

    // Select fast PWM mode, non-inverting output
    TCCR0 |= (1 << COM01) | (1 << WGM00) | (1 << WGM01);
    // Set prescaler to 118
    TCCR0 |= (1 << CS01);

    while (1) {
        adjustDutyCycle();
    }

    return 0;
}
