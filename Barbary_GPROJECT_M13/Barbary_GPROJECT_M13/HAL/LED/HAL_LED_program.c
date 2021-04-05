/**
 * @file HAL_LED_program.c
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Program file that contains the implementation for the function prototypes defined in the header file.
 * @version 1.0
 * @date 05-04-2021 3:30:09 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#include "LSTD_TYPES.h"
#include "MCAL_GPIO_interface.h"

/**
 * @brief Initializer function that sets up the ports for given leds as OUTPUT using the GPIO DRIVER.
 * 
 */
void HAL_LED_init(void){
	
	//SET PIN0, PIN1, PIN4 and PIN5 as OUTPUTS.
	MCAL_GPIO_PinMode(PORTD, (PIN0 | PIN1 | PIN4 | PIN5), OUTPUT);
	return;
}

/**
 * @brief Powers up given LEDS/LED MACROS using the GPIO DRIVER.
 * 
 * @param au8_ledNumber variable that contains the number of the leds that will be used.
 */
void HAL_LED_power(u8_t au8_ledNumber){
	
	switch (au8_ledNumber) 										//SWITCH OVER THE CASES USING THE LEDNUMBER/NAME MACRO
	{
		case 1: 												//LED 1 & 2 = OFF and  LED 3 & 4 = ON
			MCAL_GPIO_PinState(PORTD, (PIN0 | PIN1), LOW);
			MCAL_GPIO_PinState(PORTD, (PIN4 | PIN5), HIGH);
			break;
		case 3:													//LED 1 & 2 = ON and  LED 3 & 4 = OFF
			MCAL_GPIO_PinState(PORTD, (PIN0 | PIN1), HIGH);
			MCAL_GPIO_PinState(PORTD, (PIN4 | PIN5), LOW);
		break;
		default:												//LED 1, 2, 3 AND 4 = OFF
			MCAL_GPIO_PinState(PORTD, (PIN0 | PIN1), LOW);
			MCAL_GPIO_PinState(PORTD, (PIN4 | PIN5), LOW);
			break;
	}
	return;
}