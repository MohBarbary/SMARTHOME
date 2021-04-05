/**
 * @file HAL_LCD_private.h
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief This is the h file that is used to store the private variables and declarations of our LCD16x2 Driver. !PLEASE DON'T FORGET TO USE DELAYS!
 * @version 1.0
 * @date 29-01-2021 10:19:20 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#ifndef HAL_LCD_PRIVATE_H_
#define HAL_LCD_PRIVATE_H_

//Definition of LCD pins

//CONTROL PINS of LCD

#define HAL_LCD_CTRL_PORT (PORTB)
#define HAL_LCD_RS_PIN	  (PIN1)
#define HAL_LCD_RW_PIN    (PIN2)
#define HAL_LCD_EN_PIN    (PIN3)

//DATA PINS of LCD

#define HAL_LCD_DATA_PORT (PORTA)
#define HAL_LCD_D0_PIN	  (PIN0)
#define HAL_LCD_D1_PIN	  (PIN1)
#define HAL_LCD_D2_PIN	  (PIN2)
#define HAL_LCD_D3_PIN	  (PIN3)

//My development kit had only 4 bits for data.

#define HAL_LCD_D4_PIN	  (PIN4)
#define HAL_LCD_D5_PIN	  (PIN5)
#define HAL_LCD_D6_PIN	  (PIN6)
#define HAL_LCD_D7_PIN	  (PIN7)

#endif