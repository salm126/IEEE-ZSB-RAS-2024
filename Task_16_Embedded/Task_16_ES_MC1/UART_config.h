/*
 * UART_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Hassan Sameh
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define SYSTEM_FREQUENCY              1000000UL
#define USART_BAUD_RATE               9600UL
#define USART_SYSTEM_SPEED            USART_X1
#define USART_u32TIMEOUT              10000UL
#define USART_MPCM                    DISABLE
#define USART_RX_COMPLETE_INTERRUPT   DISABLE
#define USART_UDR_EMPTY_INTERRUPT     DISABLE
#define USART_RECEIVER_ENABLE         ENABLE
#define USART_TRANSMITTER_ENABLE      ENABLE
#define USART_MODE                    ASYNCHRONOUS
#define USART_PARITY_MODE             DISABLE
#define USART_STOP_BIT                STOP_BIT_1
#define USART_DATA_SIZE               DATA_SIZE_8_BIT
#define USART_CLOCK_POLARITY          XCK_RISING_TX_XCH_FALLING_RX

#endif /* UART_CONFIG_H_ */
