/**
 * @file MCAL_GPIO_private.h
 * @author Mohamed El Barbary (Mohmbarbary@gmail.com)
 * @brief This .h file contains the private macros and declarations for the GPIO Driver.
 * @version 1.0
 * @date 29-01-2021 10:19:20 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */
/**
 * @brief Header guard for the .h file
 * 
 */

#ifndef MCAL_GPIO_private_H_
#define MCAL_GPIO_private_H_

/* Start of GPIO Registers section */

// Registers of PORT A
/**
 * @brief defining the memory mapped addresses for the PORTA, DDRA, PINA Registers.
 * 
 */
#define MCAL_PORTA (*(volatile u8_t*)(0x3B))
#define MCAL_DDRA  (*(volatile u8_t*)(0x3A))
#define MCAL_PINA  (*(volatile u8_t*)(0x39))

// Registers of PORT B
/**
 * @brief defining the memory mapped addresses for the PORTB, DDRB, PINB Registers.
 * 
 */
#define MCAL_PORTB (*(volatile u8_t*)(0x38))
#define MCAL_DDRB  (*(volatile u8_t*)(0x37))
#define MCAL_PINB  (*(volatile u8_t*)(0x36))

// Registers of PORT C
/**
 * @brief defining the memory mapped addresses for the PORTC, DDRC, PINC Registers.
 * 
 */
#define MCAL_PORTC (*(volatile u8_t*)(0x35))
#define MCAL_DDRC  (*(volatile u8_t*)(0x34))
#define MCAL_PINC  (*(volatile u8_t*)(0x33))

// Registers of PORT D
/**
 * @brief defining the memory mapped addresses for the PORTD, DDRD, PIND Registers.
 * 
 */
#define MCAL_PORTD (*(volatile u8_t*)(0x32))
#define MCAL_DDRD  (*(volatile u8_t*)(0x31))
#define MCAL_PIND  (*(volatile u8_t*)(0x30))

/* End of GPIO Registers section */
#endif