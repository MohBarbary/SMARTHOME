/**
 * @file main.c
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Main file for the SMARTHOME Graduation project from AMIT LEARNING'S DIPLOMA (THIS IS THE MASTER FILE)(!FOUND AND BUILT IN DEBUG FOLDER!).
 * @version 1.0
 * @date 02-04-2021 6:58:46 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#include "LSTD_TYPES.h"
#include "APP_SMARTHOME_interface.h"

/**
 * @brief main entry point for the program.
 * 
 * @return int (0 on successful completion of the main or anything else for errors).
 */
int main(void)
{
	u8_t au8_variable = 0;								//INITIALIZING VARIABLES FOR USE WITH UART AND SPI COMMS
	u8_t au8_variable2;
								
	APP_authority(MASTER_MCU);							//GIVING OUR MCU MASTER AUTHORITY OF THE APP LAYER

	APP_init(); 										//INITIALIZING THE MASTER APPLICATION
    while (1) 
    {
		APP_recvCMD(&au8_variable);						//RECEIVE THE COMMAND TO BE EXECUTED FROM MOBILE APP TERMINAL THROUGH BLUETOOTH
		if(au8_variable)								//IGNORING THE ZERO WITH THE IF CONDITION
		{
			APP_sendCMD(au8_variable, &au8_variable2);	//SEND THE COMMAND TO BE EXECUTED TO MCU2 THROUGH SPI
			au8_variable = 0;							//RESET THE VARIABLE BEFORE RESTARTING THE SUPERLOOP
		}
    }
	return 0;
}