/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STD_MACROS.h || BIT_MATH.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Author  : Mahmoud Karem Zamel
 *  Layer  : LIB
 *
 *
 */ 
 

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define REGISTER_SIZE 8

#define SET_BIT(reg, bit)     (reg |= (1 << (bit)))
#define CLR_BIT(reg, bit)     (reg &= ~(1 << (bit)))
#define TOG_BIT(reg, bit)     (reg ^= (1 << (bit)))
#define GET_BIT(reg, bit)     ((reg >> (bit)) & 0x01)
#define IS_BIT_SET(reg, bit)  ((reg >> (bit)) & 0x01)
#define IS_BIT_CLR(reg, bit)  (!((reg >> (bit)) & 0x01))

#define ROR(reg, num)         (reg = (reg << (REGISTER_SIZE - (num))) | (reg >> (num)))
#define ROL(reg, num)         (reg = (reg >> (REGISTER_SIZE - (num))) | (reg << (num)))

#define BIT_IS_CLEAR(reg, bit) (!(reg & (1 << (bit))))

#endif // BIT_MATH_H_
