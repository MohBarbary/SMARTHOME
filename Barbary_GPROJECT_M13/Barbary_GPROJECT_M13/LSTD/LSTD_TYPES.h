/**
 * @file LSTD_TYPES.h
 * @author Mohamed El Barbary (Mohmbarbary@gmail.com)
 * @brief This is a standard library layer file that is used to make aliases for the standard data types inorder to make the code more portable and to avoid changes in data type sizes when using different compilers.
 * giving our standard data types new aliases:
 * unsigned char and signed char -> u8_t and s8_t.
 * unsigned short int and signed short int -> u16_t and s16_t.
 * unsigned long int and signed long int -> u32_t and s32_t.
 * float -> f32_t.
 * double -> f64_t.
 * @version 1.0
 * @date 2021-01-29 10:19:20 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#ifndef _LSTD_TYPES_H_
#define _LSTD_TYPES_H_

typedef unsigned char       u8_t;
typedef signed char         s8_t;

typedef unsigned short int u16_t;
typedef signed short int   s16_t;

typedef unsigned long int  u32_t;
typedef signed long int    s32_t;

typedef float              f32_t;

typedef double             f64_t;

#endif
