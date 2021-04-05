 /**
 * @file MCAL_GPIO_interface.h
 * @author Mohamed El Barbary (Mohmbarbary@gmail.com)
 * @brief This .h file contains the interfacing macros, declarations and function prototypes for the GPIO Driver.
 * @version 1.0
 * @date 29-01-2021 10:19:20 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */



#ifndef MCAL_GPIO_INTERFACE_H_
#define MCAL_GPIO_INTERFACE_H_

//PORT MACROS
#define PORTA  (0)
#define PORTB  (1)
#define PORTC  (2)
#define PORTD  (3)

/**
 * @brief creating macros for the PIN registers, we will be writing them in binary, so that we can do bit operations on them for ease of use.
 * 
 */
#define PIN0   (0b00000001)
#define PIN1   (0b00000010)
#define PIN2   (0b00000100)
#define PIN3   (0b00001000)
#define PIN4   (0b00010000)
#define PIN5   (0b00100000)
#define PIN6   (0b01000000)
#define PIN7   (0b10000000)


/**
 * @brief creating a macro for the data direction types.
 * 
 */
#define INPUT_FLOAT  (0)
#define INPUT_PULLUP (1)
#define OUTPUT       (2)

//STATES
/**
 * @brief creating a macro for the possible states.
 * 
 */

#define LOW	   (0)
#define HIGH   (1)
	


/**
 * @brief MCAL_GPIO_PinMode is used to change the Mode of a pin/pins from any given port.
 * 
 * @param au8_port is the port to be selected from our macro list PORTA, PORTB, PORTC or PORTD.
 * @param au8_pin is the port to be selected from our macro list PIN1 ... PIN7.
 * @param au8_type is the mode selected from our macro list INPUT_FLOAT, INPUT_PULLUP or OUTPUT. 
 */
void MCAL_GPIO_PinMode(u8_t au8_port , u8_t au8_pin , u8_t au8_type);


/**
 * @brief MCAL_GPIO_PinState is used to change the State of a pin/pins from any given port to HIGH or LOW.
 * 
 * @param au8_port is the port to be selected from our macro list PORTA, PORTB, PORTC or PORTD.
 * @param au8_pin is the port to be selected from our macro list PIN1 ... PIN7.
 * @param au8_state  is the mode selected from our macro list HIGH or LOW. 
 */
void MCAL_GPIO_PinState(u8_t au8_port , u8_t au8_pin , u8_t au8_state);

/**
 * @brief MCAL_GPIO_TogglePin is used to toggel the State of a pin given a port.
 * 
 * @param au8_port The PORT used in the toggling operation.
 * @param au8_pin The PIN to be toggled.
 */
void MCAL_GPIO_TogglePin(u8_t au8_port , u8_t au8_pin);

/**
 * @brief MCAL_GPIO_GetPinState is a function that gets the state of a gien PORT and PIN combination.
 * 
 * @param au8_port the given PORT from our macros list.
 * @param au8_pin the given PIN from our macros list.
 * @return u8_t returns true if the state is HIGH and false if the state is LOW.
 */
u8_t MCAL_GPIO_GetPinState(u8_t au8_port , u8_t au8_pin);

#endif