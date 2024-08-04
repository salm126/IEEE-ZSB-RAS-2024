/*
 * SPI_private.h
 *
 *  Created on:3/8/2024
 *      Author: Salma Sameh
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define  SPI_u8_SPDR_REG      *((volatile u8*)0x2F)
#define  SPI_u8_SPSR_REG      *((volatile u8*)0x2E)
#define  SPI_u8_SPCR_REG      *((volatile u8*)0x2D)

#define SPI_u8_MASTER_MODE      1
#define SPI_u8_SLAVE_MODE       2





#endif /* SPI_PRIVATE_H_ */
