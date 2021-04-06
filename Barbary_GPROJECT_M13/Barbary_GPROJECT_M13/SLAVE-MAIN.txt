/**
 * @file main.c
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Main file for the SMARTHOME Graduation project from AMIT LEARNING'S DIPLOMA (THIS IS THE SLAVE FILE)(!FOUND AND BUILT IN RELEASE FOLDER!).
 * @version 1.0
 * @date 02-04-2021 6:58:46 PM
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "LSTD_TYPES.h"
#include "APP_SMARTHOME_interface.h"

/**
 * @brief main entry point for the program.
 * 
 * @return int (0 on successful completion of the main or anything else for errors).
 */
int main_SLAVE_DOCUMENTATION(void)
{
	u8_t au8_variable = 0;										//INITIALIZING VARIABLES FOR USE WITH SPI COMMS
	u8_t au8_variable2;
	
	APP_authority(SLAVE_MCU);									//GIVING OUR MCU SLAVE AUTHORITY OF THE APP LAYER
	
	APP_init();													//INITIALIZING THE SLAVE APPLICATION			
    
	while (1) 
    {
		APP_recvCMD(&au8_variable);								//RECEIVE MCU2 COMMAND THROUGH SPI
		
		if(au8_variable == '1')									//CASE 1: TURN ON LED 3 & 4, TURN OFF LED 1 & 2.
		{
			APP_useClearLCD();
			APP_powerLeds(APP_LED_KITCHEN);
			APP_useWriteLCD((u8_t*)"LED 1 & 2 = OFF");
			APP_useCursorLCD(APP_LCD_ROW01, APP_LCD_COL00);
			APP_useWriteLCD((u8_t*)"LED 3 & 4 = ON");
		}
		else if(au8_variable == '2')							//CASE 2: TURN ON LED 1 & 2, TURN OFF LED 3 & 4.
		{
			APP_useClearLCD();
			APP_powerLeds(APP_LED_GARAGE);
			APP_useWriteLCD((u8_t*)"LED 1 & 2 = ON");
			APP_useCursorLCD(APP_LCD_ROW01, APP_LCD_COL00);
			APP_useWriteLCD((u8_t*)"LED 3 & 4 = OFF");
		}
		else if(au8_variable == '3')							//CASE 3: OPEN GARAGE DOOR (MOTOR) AND TURN OFF ALL LIGHTS
		{
			APP_useClearLCD();
			APP_powerLeds(APP_LED_NULL);
			APP_powerGarageDoor(APP_GARAGE_DOOR_ON);
			APP_useWriteLCD((u8_t*)"Garage Door ON!");
		}
		else if(au8_variable == '4')							//CASE 4: CLOSE GARAGE DOOR (MOTOR) AND TURN ON GARAGE LIGHTS
		{
			APP_useClearLCD();
			APP_powerLeds(APP_LED_GARAGE);
			APP_powerGarageDoor(APP_GARAGE_DOOR_OFF);
			APP_useWriteLCD((u8_t*)"Garage Door OFF!");
			APP_useCursorLCD(APP_LCD_ROW01, APP_LCD_COL00);
			APP_useWriteLCD((u8_t*)"Welcome Back Moh!");
		}
		else
		{
			//DO NOTHING
		}
		au8_variable = 0;										//RESET THE VARIABLE BEFORE RESTARTING THE SUPER LOOP
    }
	return 0;
}
