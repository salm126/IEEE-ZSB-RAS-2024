/*
 * calc.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Hassan Sameh
 */


#include "calc.h"

static uint8 key;

static uint8 op;

static uint8 op_char;

uint32 a, b;

static double result;

static uint8 lcd_buf[16];

void cal_op(void)
{
	switch(key){
		case'+':
			key=0;
			op=1;
			op_char='+';
			break;
		case'-':
			key=0;
			op=2;
			op_char='-';
			break;
		case'*':
			key=0;
			op=3;
			op_char='x';
			break;
		case'/':
			key=0;
			op=4;
			op_char='/';
			break;
		case'0':
			key=0;
			break;
		case'=':
			key=0;
			op=5;
			break;
		case'C':
			a=0;
			b=0;
			result=0;
			op=0;
			key = 0;
			LCD_clearScreen();
			break;
	}
}



void cal_run(void)
{

		if(op==0)
		{
			a=a*10+key;
			sprintf(lcd_buf,"%1li",a);
			LCD_displayStringRowColumn(0,0,lcd_buf);
		}
		else if(op==1 || op==2 || op==3 || op==4)
		{
			b=b*10+key;
			sprintf(lcd_buf,"%1li%c%1li",a,op_char,b);
			LCD_displayStringRowColumn(0,0,lcd_buf);
		}

		else if(op==5)
		{
			switch(op_char){
				case'+':
					result=a+b;
					break;

				case'-':
					result=a-b;
					break;

				case'x':
					result=a*b;
					break;

				case'/':
					result=(float)a/b;
					break;
			}

			sprintf(lcd_buf,"=%.2f",result);
			LCD_displayStringRowColumn(1,0,lcd_buf);

			while(KeyPad_getPressedKey()!='C'){}
		}
}


void calculate(void)
{
	while(1){
		key = KeyPad_getPressedKey();

		if (key != 0)
		{
			cal_op();
			cal_run();
			key = 0;
		}
		_delay_ms(500);
	}
}
