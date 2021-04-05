/**
 * @file LSTD_BITMATH.h
 * @author Mohamed El Barbary (Mohmbarbary@gmail.com)
 * @brief This is a standard library layer file that contains bitmath macros that can come in handy while coding.
 * @version 1.0
 * @date 2021-01-29 10:19:20 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */
#ifndef LSTD_BITMATH_H_
#define LSTD_BITMATH_H_

#define setBit(REG, POS)	(REG |=  (1 << POS))
#define clearBit(REG, POS)	(REG &= ~(1 << POS))
#define toggleBit(REG, POS) (REG ^= (1 << POS))
#define getBit(REG, POS)	((REG >> POS) & 1)

#endif