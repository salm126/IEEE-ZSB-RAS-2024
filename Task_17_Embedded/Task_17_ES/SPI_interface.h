/*
 * SPI_private.h
 *
 *  Created on:3/8/2024
 *      Author: Salma Sameh
 */

#include "STD_TYPES.h"

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


 void SPI_voidInit(void);
 u8 SPI_u8TransRecieve(u8 Copy_u8TransmittedByte,u8 *Copy_pu8RecieveByte);
 void SPI_voidSlaveSendByte(u8 Copy_u8_DataByte);
 u8 SPI_u8RecieveByte(u8 *Copy_pu8RecieveByte);


#endif /* SPI_INTERFACE_H_ */
