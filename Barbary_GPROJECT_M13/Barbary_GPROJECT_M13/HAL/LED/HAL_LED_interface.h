/**
 * @file HAL_LED_interface.h
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Interfacing file that contains macros and function prototypes for the LED DRIVER.
 * @version 1.0
 * @date 05-04-2021 3:29:53 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#ifndef HAL_LED_INTERFACE_H_
#define HAL_LED_INTERFACE_H_

/**
 * @brief Initializer function that sets up the ports for given leds as OUTPUT using the GPIO DRIVER.
 * 
 */
void HAL_LED_init(void);

/**
 * @brief Powers up given LEDS/LED MACROS using the GPIO DRIVER.
 * 
 * @param au8_ledNumber variable that contains the number of the leds that will be used.
 */
void HAL_LED_power(u8_t au8_ledNumber);
#endif /* HAL_LED_INTERFACE_H_ */