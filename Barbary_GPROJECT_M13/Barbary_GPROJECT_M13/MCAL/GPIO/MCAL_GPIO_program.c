/**
 * @file MCAL_GPIO_program.c
 * @author Mohamed El Barbary (Mohmbarbary@gmail.com)
 * @brief This c file contains the implementation for the function prototypes used in MCAL_GPIO_interface.h
 * @version 1.0
 * @date 29-01-2021 10:19:20 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */
#include "LSTD_BITMATH.h"
#include "LSTD_TYPES.h"
#include "MCAL_GPIO_private.h"
#include "MCAL_GPIO_interface.h"


/**
 * @brief MCAL_GPIO_PinMode is used to change the Mode of a pin/pins from any given port.
 * 
 * @param au8_port is the port to be selected from our macro list PORTA, PORTB, PORTC or PORTD.
 * @param au8_pin is the port to be selected from our macro list PIN1 ... PIN7.
 * @param au8_type is the mode selected from our macro list INPUT_FLOAT, INPUT_PULLUP or OUTPUT. 
 */
void MCAL_GPIO_PinMode(u8_t au8_port , u8_t au8_pin , u8_t au8_type){
	/**
	 * @brief We will switch over the au_8port given and once we find it, we will switch over the au8_type and then we set up our mode.
	 * 
	 */
	switch(au8_port){
		/**
		 * @brief The registers used in order to alter the I/P or O/P modes. MCAL_DDRx, MCAL_PORTx.
		 * 
		 */
		case PORTA:
			switch(au8_type)
			{
				case INPUT_FLOAT:
					MCAL_DDRA &= ~au8_pin;
					break;
				case INPUT_PULLUP:
					MCAL_DDRA &= ~au8_pin;
					MCAL_PORTA |= au8_pin;
					break;
				case OUTPUT:
					MCAL_DDRA |= au8_pin;
					break;
				default:
					break;
			}
			break;
		case PORTB:
		switch(au8_type)
		{
			case INPUT_FLOAT:
				MCAL_DDRB &= ~au8_pin;
				break;
			case INPUT_PULLUP:
				MCAL_DDRB &= ~au8_pin;
			MCAL_PORTB |= au8_pin;
				break;
			case OUTPUT:
				MCAL_DDRB |= au8_pin;
				break;
			default:
				break;
		}
		break;
		case PORTC:
		switch(au8_type)
		{
			case INPUT_FLOAT:
				MCAL_DDRC &= ~au8_pin;
				break;
			case INPUT_PULLUP:
				MCAL_DDRC &= ~au8_pin;
				MCAL_PORTC |= au8_pin;
				break;
			case OUTPUT:
				MCAL_DDRC |= au8_pin;
				break;
			default:
				break;
		}
		break;
		case PORTD:
		switch(au8_type)
		{
			case INPUT_FLOAT:
				MCAL_DDRD &= ~au8_pin;
				break;
			case INPUT_PULLUP:
				MCAL_DDRD &= ~au8_pin;
				MCAL_PORTD |= au8_pin;
				break;
			case OUTPUT:
				MCAL_DDRD |= au8_pin;
				break;
			default:
				break;
		}
		break;
	}
	return;
}
/**
 * @brief MCAL_GPIO_PinState is used to change the State of a pin/pins from any given port to HIGH or LOW.
 * 
 * @param au8_port is the port to be selected from our macro list PORTA, PORTB, PORTC or PORTD.
 * @param au8_pin is the port to be selected from our macro list PIN1 ... PIN7.
 * @param au8_state  is the mode selected from our macro list HIGH or LOW. 
 */
void MCAL_GPIO_PinState(u8_t au8_port , u8_t au8_pin , u8_t au8_state){
	/**
	 * @brief We will switch over the au_8port given and once we find it, we will switch over the au8_type and then we set up our state.
	 * 
	 */
	switch(au8_port){
		/**
		 * @brief The registers used in order to alter the I/P or O/P states. MCAL_PORTx.
		 * 
		 */
		case PORTA:
		switch(au8_state)
		{
			case LOW:
			MCAL_PORTA &= ~au8_pin;
			break;
			case HIGH:
			MCAL_PORTA |= au8_pin;
			break;
			default:
			break;
		}
		break;
	}
	switch(au8_port){
		case PORTB:
			switch(au8_state)
			{
				case LOW:
					MCAL_PORTB &= ~au8_pin;
					break;
				case HIGH:
					MCAL_PORTB |= au8_pin;
					break;
				default:
					break;
			}
			break;
	}
	switch(au8_port){
		case PORTC:
			switch(au8_state)
			{
				case LOW:
					MCAL_PORTC &= ~au8_pin;
					break;
				case HIGH:
					MCAL_PORTC |= au8_pin;
					break;
				default:
					break;
			}
			break;
	}
	switch(au8_port){
		case PORTD:
			switch(au8_state)
			{
				case LOW:
					MCAL_PORTD &= ~au8_pin;
					break;
				case HIGH:
					MCAL_PORTD |= au8_pin;
					break;
				default:
					break;
			}
			break;
	}
	return;
}

/**
 * @brief MCAL_GPIO_TogglePin is used to toggel the State of a pin given a port.
 * 
 * @param au8_port The PORT used in the toggling operation.
 * @param au8_pin The PIN to be toggled.
 */
void MCAL_GPIO_TogglePin(u8_t au8_port , u8_t au8_pin){
	switch(au8_port){
		case PORTA:
			MCAL_PORTA ^= au8_pin;
			break;
		case PORTB:
			MCAL_PORTB ^= au8_pin;
			break;
		case PORTC:
			MCAL_PORTC ^= au8_pin;
			break;
		case PORTD:
			MCAL_PORTD ^= au8_pin;
			break;
		default:
			break;
	}
	
	return;
}
/**
 * @brief MCAL_GPIO_GetPinState is a function that gets the state of a gien PORT and PIN combination.
 * 
 * @param au8_port the given PORT from our macros list.
 * @param au8_pin the given PIN from our macros list.
 * @return u8_t returns true if the state is HIGH and false if the state is LOW.
 */
u8_t MCAL_GPIO_GetPinState(u8_t au8_port , u8_t au8_pin){
	u8_t au8_pinValue = 0;
	switch(au8_port){
		case PORTA:
			if((MCAL_PINA & au8_pin))
			{
				au8_pinValue  = HIGH;
			}
			else
			{
				au8_pinValue  = LOW;
			}
			break;
		case PORTB:
			if((MCAL_PINB & au8_pin))
			{
				au8_pinValue  = HIGH;
			}
			else
			{
				au8_pinValue  = LOW;
			}
			break;
		case PORTC:
			if((MCAL_PINC & au8_pin))
			{
				au8_pinValue  = HIGH;
			}
			else
			{
				au8_pinValue  = LOW;
			}
			break;
		case PORTD:
			if((MCAL_PIND & au8_pin))
			{
				au8_pinValue  = HIGH;
			}
			else
			{
				au8_pinValue  = LOW;
			}
			break;		
	}
	return au8_pinValue;
}

//End of function definitions
