/*
 *
 *
 *  Created on:3/8/2024
 *      Author: Salma Sameh
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include <util/delay.h>
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidInit(void) {
#if (SPI_u8_MODE == SPI_u8_MASTER_MODE)
    /* Data order = MSB First */
    CLR_BIT(SPI_u8_SPCR_REG, 5);
    /* Choose CPOL and CPHA => Falling,Raising /Setup,Sample */
    SET_BIT(SPI_u8_SPCR_REG, 3);
    SET_BIT(SPI_u8_SPCR_REG, 2);

    /* Select Master Mode */
    SET_BIT(SPI_u8_SPCR_REG, 4);
    /* Select CLK => Frequency_oscillator/64 */
    SET_BIT(SPI_u8_SPCR_REG, 0);
    SET_BIT(SPI_u8_SPCR_REG, 1);
#elif (SPI_u8_MODE == SPI_u8_SLAVE_MODE)
    /* Data order = MSB First */
    CLR_BIT(SPI_u8_SPCR_REG, 5);
    /* Choose CPOL and CPHA => Falling,Raising /Setup,Sample */
    SET_BIT(SPI_u8_SPCR_REG, 3);
    SET_BIT(SPI_u8_SPCR_REG, 2);

    /* Select SLAVE Mode */
    CLR_BIT(SPI_u8_SPCR_REG, 4);
    /* Select CLK => Frequency_oscillator/64 */
    SET_BIT(SPI_u8_SPCR_REG, 0);
    SET_BIT(SPI_u8_SPCR_REG, 1);
#endif
    /* Enable SPI */
    SET_BIT(SPI_u8_SPCR_REG, 6);
}

u8 SPI_u8TransRecieve(u8 Copy_u8TransmittedByte, u8 *Copy_pu8RecieveByte) {
    u8 Local_u8ErrorState = NOK;
    if (Copy_pu8RecieveByte != NULL) {
        /* Send Byte */
        SPI_u8_SPDR_REG = Copy_u8TransmittedByte;
        /* check if transmitted is completed */
        while ((GET_BIT(SPI_u8_SPSR_REG, 7)) == 0)
            /* Read Byte */
            *Copy_pu8RecieveByte = SPI_u8_SPDR_REG;
        Local_u8ErrorState = OK;
    }
    return Local_u8ErrorState;
}

void SPI_voidSlaveSendByte(u8 Copy_u8_DataByte) {
    u8 Local_u8ErrorState = NOK;
    u8 *Copy_pu8RecieveByte = NULL;
    SPI_u8_SPDR_REG = Copy_u8_DataByte;
    /* check if transmitted is completed */
    if (Copy_pu8RecieveByte != NULL) {
        while ((GET_BIT(SPI_u8_SPSR_REG, 7)) == 0) {
            /* Read Byte */
            *Copy_pu8RecieveByte = SPI_u8_SPDR_REG;
            Local_u8ErrorState = OK;
        }
    }
}
