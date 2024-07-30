/*
 /*
 * UART_private.h
 *
 *  Created on: ??�/??�/????
 *      Author: Eng Hassan Sameh
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/* Registers */
#define UDR     _SFR_MEM8(0x2C)
#define UCSRA   _SFR_MEM8(0x2B)
#define UCSRB   _SFR_MEM8(0x2A)
#define UCSRC   _SFR_MEM8(0x40)
#define UBRRL   _SFR_MEM8(0x29)
#define UBRRH   _SFR_MEM8(0x40)

/* UCSRA Bits */
#define UCSRA_RXC  7
#define UCSRA_TXC  6
#define UCSRA_UDRE 5
#define UCSRA_FE   4
#define UCSRA_DOR  3
#define UCSRA_PE   2
#define UCSRA_U2X  1
#define UCSRA_MPCM 0

/* UCSRB Bits */
#define UCSRB_RXCIE  7
#define UCSRB_TXCIE  6
#define UCSRB_UDRIE  5
#define UCSRB_RXEN   4
#define UCSRB_TXEN   3
#define UCSRB_UCSZ2  2
#define UCSRB_RXB8   1
#define UCSRB_TXB8   0

/* UCSRC Bits */
#define UCSRC_URSEL  7
#define UCSRC_UMSEL  6
#define UCSRC_UPM1   5
#define UCSRC_UPM0   4
#define UCSRC_USBS   3
#define UCSRC_UCSZ1  2
#define UCSRC_UCSZ0  1
#define UCSRC_UCPOL  0

/* UART Modes */
#define DISABLE                        0
#define ENABLE                         1
#define USART_X1                       1
#define USART_X2                       2
#define ASYNCHRONOUS                   0
#define SYNCHRONOUS                    1
#define EVEN_PARITY                    0
#define ODD_PARITY                     1
#define STOP_BIT_1                     0
#define STOP_BIT_2                     1
#define DATA_SIZE_5_BIT                0
#define DATA_SIZE_6_BIT                1
#define DATA_SIZE_7_BIT                2
#define DATA_SIZE_8_BIT                3
#define DATA_SIZE_9_BIT                4
#define XCK_RISING_TX_XCH_FALLING_RX   0
#define XCK_RISING_RX_XCH_FALLING_TX   1
#define UBRRL_MAX                      256

#endif /* UART_PRIVATE_H_ */