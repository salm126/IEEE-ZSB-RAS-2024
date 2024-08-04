/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Salma  Sameh
 */



#define F_CPU 4000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void masterInit(void) {
    DDRB = (1 << 7) | (1 << 5) | (1 << 4);
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0) | (1 << CPHA);
}

void masterTransmit(char spiData) {
    SPDR = spiData;
    while (!(SPSR & (1 << SPIF)));
}

char masterReceive(void) {
    while (!(SPSR & (1 << SPIF)));
    return SPDR;
}

void tc72Init(void) {
    PORTB |= (1 << 4);
    masterTransmit(0x80);
    masterTransmit(0x04);
    PORTB &= ~(1 << 4);
    _delay_ms(150);
}

void displayTemperature(char msb, char lsb) {
    char ssd[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
    char sign = 0;
    int temp;

    if (msb & 0x80) {
        msb = (~msb) + 1;
        sign = 1;
    }

    temp = (msb * 100) + ((lsb >> 6) * 25);

    PORTD = 0x00;
    if (sign == 1) {
        PORTC = 0x40; // Display '-' sign
        PORTD = (1 << 0);
        _delay_ms(10);
    }

    PORTC = ssd[temp / 100];
    PORTD = (1 << 1);
    _delay_ms(10);

    PORTC = ssd[(temp % 100) / 10];
    PORTD = (1 << 2);
    _delay_ms(10);

    PORTC = ssd[temp % 10] | 0x80; // Display decimal point
    PORTD = (1 << 3);
    _delay_ms(10);

    PORTC = ssd[(lsb >> 6) * 25 / 10];
    PORTD = (1 << 4);
    _delay_ms(10);

    PORTC = ssd[(lsb >> 6) * 25 % 10];
    PORTD = (1 << 5);
    _delay_ms(10);

    PORTD = 0x00;
    PORTC = 0x63; // Display '°C'
    PORTD = (1 << 6);
    _delay_ms(10);
}

int main(void) {
    char msb, lsb;
    DDRC = 0xFF;
    DDRD = 0xFF;
    DDRA = 0xFF;
    masterInit();
    tc72Init();
    _delay_ms(150);

    while (1) {
        PORTB |= (1 << 4);
        masterTransmit(0x02);
        masterTransmit(0x00);
        PORTB &= ~(1 << 4);

        _delay_ms(1);
        msb = masterReceive();

        PORTB |= (1 << 4);
        masterTransmit(0x01);
        masterTransmit(0x00);
        PORTB &= ~(1 << 4);

        _delay_ms(1);
        lsb = masterReceive();
        PORTA = lsb;
        displayTemperature(msb, lsb);
    }
}
