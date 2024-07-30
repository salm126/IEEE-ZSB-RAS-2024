/*
 * UART_program.c
 *
 *      Created on: 30/7/2024
 *      Author: Salma Sameh
 */

#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"
#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

void UART_init(void) {
    SET_BIT(UCSRA, UCSRA_U2X);


    /*********************************UCSRB Description*****************************
         * RXCIE = 0 Disable USART RX Complete Interrupt Enable
         * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
         * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
         * RXEN  = 1 Receiver Enable
         * TXEN  = 1 Transmitter Enable
         * UCSZ2 = 0 For 8-bit data mode
         * RXB8 & TXBB not used for 8-bit data mode
        ******************************************************************************/

    /* UCSRB Configuration */
    SET_BIT(UCSRB, UCSRB_RXEN);
    SET_BIT(UCSRB, UCSRB_TXEN);

    /*********************************UCSRC Description ***************************
         * URSEL   = 1    The URSEL must be one when writing the UCSRC
         * UMSEL   = 0    Asynchronous Operation
         * UPM1:   = 0 0  Disable parity bit
         * USBS    = 0    One stop bit
         * UCSZ1:0 = 1 1 For 8-bit data mode
         * UCPOL   = 0    Used with the Synchronous Operation Only
    	 ****************************************************************************/

    /* UCSRC Configuration */
    SET_BIT(UCSRC, UCSRC_URSEL);      // writing on UCSRC
    SET_BIT(UCSRC, UCSRC_UCSZ1);     // Bits 5:4 =>10> Enable Even Parity
    SET_BIT(UCSRC, UCSRC_UCSZ0);    // Bits 2:1 => 11 => character size 8-bits



    /* Baud Rate Configuration */
    /* First 8 bits from the BAUD PRESCALE inside UBRRL and last 4 bits in UBRRH */
    UBRRH = (u8)(BAUD_PRESCALE >> 8);
    UBRRL = (u8)BAUD_PRESCALE;
}

u8 UART_sendByte(u8 data) {
	/*UDRE Flag is sat when the Tx buffer (UDK) is empty and ready for transmitting a new byte to wait until this
	      flag is set to one then send the data*/
    while (BIT_IS_CLEAR(UCSRA, UCSRA_UDRE)) {}
    UDR = data;
    return OK;
}

u8 UART_receiveByte(void) {
	/* RXC Ling is set when the UART receive data to wait until this flag is set to one then read the data*/
    while (BIT_IS_CLEAR(UCSRA, UCSRA_RXC)) {
        // Wait for data to be received

    }
    return UDR;
}
