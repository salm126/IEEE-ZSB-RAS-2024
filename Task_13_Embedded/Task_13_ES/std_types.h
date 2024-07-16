/*
 * std_types.h
 *    Created on: 16/07/2024
 *     Author: Salma Sameh
 */
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char bool;
#ifndef FALSE
#define FALSE (0)
#endif
#ifndef TRUE
#define TRUE (1)
#endif
#define HIGH (1)
#define LOW (0)

typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned long uint32;
typedef signed long sint32;
typedef unsigned long long uint64;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#endif /* STD_TYPES_H_ */
