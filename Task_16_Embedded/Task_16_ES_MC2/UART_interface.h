/*
 * UART_interface.h
 *
 *  Created on: 30/7/2024
 *      Author: Salma  Sameh
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include <avr/io.h>
#include "STD_TYPES.h"


#define USART_BAUDRATE     38400
#define BAUD_PRESCALE      (((F_CPU / (USART_BAUDRATE * 8UL))) - 1)

void UART_init             (void);
u8 UART_sendByte         (u8 data);
u8 UART_receiveByte      (void);


#endif /* UART_INTERFACE_H_ */
