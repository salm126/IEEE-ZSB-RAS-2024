/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Hassan Sameh
 */


#include "calc.h"

int main(void)
{
	LCD_init();
	LCD_displayStringRowColumn(0,0,"Calculator");
	LCD_displayStringRowColumn(1,0,"PLEASE PRESS ON");
	_delay_ms(50);

	while(1)
	{
		if(KeyPad_getPressedKey()=='C'){
			LCD_clearScreen();
			calculate();
		}
	}
}
