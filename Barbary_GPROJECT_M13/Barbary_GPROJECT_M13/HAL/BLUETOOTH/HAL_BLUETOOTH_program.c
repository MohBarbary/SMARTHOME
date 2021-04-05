/**
 * @file HAL_BLUETOOTH_program.c
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Program file that contains the implementation of the functions defined in the header file for the BLUETOOTH DRIVER.
 * @version 1.0
 * @date 03-04-2021 2:44:53 AM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#include "LSTD_TYPES.h"
#include "LSTD_BITMATH.h"
#include "MCAL_UART_interface.h"
#include "MCAL_GPIO_interface.h"
#include "HAL_BLUETOOTH_interface.h"


/**
 * @brief Establishes a Bluetooth connection with a given BAUD RATE. (!PLEASE USE THE DEFAULT BAUD-RATE FOR BLUETOOTH!)
 * 
 * @param au16_baudRate variable that contains the BAUD RATE to be passed to the function.
 */

void HAL_establishBluetooth(u16_t au16_baudRate){
	
	//SETTING RX PIN
	MCAL_GPIO_PinMode(PORTD, PIN0, INPUT_FLOAT);
	
	//SETTING TX PIN
	MCAL_GPIO_PinMode(PORTD, PIN1, OUTPUT);
	
	//INITIALIZE THE UART CONNECTION TO TRANSMIT DATA
	MCAL_UART_init(au16_baudRate);
	
	return;
}

/**
 * @brief Receive data from an already established BLUETOOTH connection with a given device.
 * 
 * @param pu8_dataHolder pointer to the variable that contains the data received from the BLUETOOTH Transmission.
 */
void HAL_recvBluetooth(u8_t* pu8_dataHolder){
	
	//RECEIVE A BYTE FROM THE SENDER (MOBILE DEVICE ON BLUTERM)
	MCAL_UART_recvByte(pu8_dataHolder);
	
	return;
}
