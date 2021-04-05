/**
 * @file APP_SMARTHOME_program.c
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Program file that contains the implementation of the function prototypes defined in the header files for the SMARTHOME DRIVER.
 * @version 1.0
 * @date 03-04-2021 3:22:13 AM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#include "LSTD_TYPES.h"
#include "LSTD_BITMATH.h"
#include "MCAL_GPIO_interface.h"
#include "MCAL_UART_interface.h"
#include "MCAL_SPI_interface.h"
#include "HAL_BLUETOOTH_interface.h"
#include "APP_SMARTHOME_interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>

u8_t gu8_Authority = 2; //AUTHORITY = 0 -> MASTER, AUTHORITY = 1 -> MASTER, AUTHORITY > 1 -> UNDEFINED

/**
 * @brief Used to assign the authority of the calling MCU unit.
 * 
 * @param au8_Authority the variable containing the Authority of the MCU (!USE THE MACROS!)
 */
void APP_authority(u8_t au8_selectAuthority){
	
	if (!au8_selectAuthority) //IF AUTH == 0 THEN MCU IS MASTER ELSE MCU IS SLAVE
	{
		gu8_Authority = 0;
	} 
	else
	{
		gu8_Authority = 1;
	}
	return;
}

/**
 * @brief Initializes the application (MASTER/SLAVE have different initializations).
 * 
 */
void APP_init(void){
	
	if(!gu8_Authority) //CHECK IF MASTER MCU
	{
		//ESTABLISHING BLUETOOTH CONNECTION
		HAL_establishBluetooth(BLUETOOTH_DATA_BAUDRATE);
		
		//INITIALIZING SPI CONNECTION FOR A MASTER//
		
		//SET SS, MOSI, SCLK -> OUTPUT respectively.
		MCAL_GPIO_PinMode(PORTB, (PIN4 | PIN5 | PIN7), OUTPUT);
		//SET MISO -> INPUT_FLOAT
		MCAL_GPIO_PinMode(PORTB, PIN6, INPUT_FLOAT);
		
		//INITIALIZING A MASTER SPI
		MCAL_SPI_init(MCAL_SPI_MASTER, MCAL_SPI_MSB, MCAL_SPI_SAMPLE_R_SETUP_F, MCAL_SPI_CLK_BY_16);
	}
	else //SLAVE MCU COMMANDS
	{
		
		//SET SS, MOSI, SCLK -> INPUT_FLOAT respectively.
		MCAL_GPIO_PinMode(PORTB, (PIN4 | PIN5 | PIN7), INPUT_FLOAT);
		//SET MISO -> OUTPUT
		MCAL_GPIO_PinMode(PORTB, PIN6, OUTPUT);
		
		//INITIALIZING A SLAVE SPI
		MCAL_SPI_init(MCAL_SPI_SLAVE, MCAL_SPI_MSB, MCAL_SPI_SAMPLE_R_SETUP_F, MCAL_SPI_CLK_BY_16);
		
		//INITIALIZE THE LCD
		HAL_LCD_init();
		//INITIALIZE THE LED PINS
		HAL_LED_init();
		
		//INITIALIZE GARAGE MOTOR
		MCAL_GPIO_PinMode(PORTC, PIN0, OUTPUT);
		
	}
	return;
}

/**
 * @brief Receives a command via BLUETOOTH/SPI DEPENDING ON THE AUTHORITY. (MASTER/SLAVE COMMAND)
 * 
 * @param pu8_dataHolder A pointer to the variable that will hold the data received.
 */
void APP_recvCMD(u8_t* pu8_dataHolder){
	
	if (!gu8_Authority)
	{
		//CALLING THE RECEPTIVE BLUETOOTH FUNCTION
		HAL_recvBluetooth(pu8_dataHolder);	
	} 
	else
	{
		MCAL_SPI_slaveSendRecvByte(0, pu8_dataHolder); //DO I NEED TO SEND DATA?
	}
	return;
}

/**
 * @brief Sends a command via SPI (MASTER ONLY COMMAND)
 * 
 * @param au8_dataSent A variable containing the data to be sent.
 * @param pu8_dataRecv A pointer to a variable for the data to be received.
 */
void APP_sendCMD(u8_t au8_dataSent, u8_t* pu8_dataRecv){
	
	if (!gu8_Authority) //IF MASTER
	{
		//PULL SS TO LOW TO INITIATE TRANSACTION
		MCAL_GPIO_PinState(PORTB, PIN4, LOW);
		
		//SENDING & RECEIVING SPI DATA AS A MASTER
		MCAL_SPI_masterSendRecvByte(au8_dataSent, pu8_dataRecv);
		
		//PULL SS TO HIGH END TRANSACTION
		MCAL_GPIO_PinState(PORTB, PIN4, HIGH);
		
		_delay_ms(50);
	} 
	else				//IF SLAVE
	{
		//DO NOTHING
	}
	
	return;
}

/**
 * @brief Used to write strings on the LCD. (SLAVE ONLY COMMAND)
 * 
 * @param pu8_string A pointer to a variable that contains the string to be shown on the LCD.
 */
void APP_useWriteLCD(u8_t* pu8_string){
		
	if (gu8_Authority) //IF SLAVE
	{
		HAL_LCD_displayString(pu8_string);
	}
	else				//IF MASTER
	{
		//DO NOTHING
	}
	return;
}

/**
 * @brief Used to clear the LCD. (SLAVE ONLY COMMAND)
 * 
 */
void APP_useClearLCD(){
	if (gu8_Authority)  //IF SLAVE
	{
		HAL_LCD_clearDisplay();
		_delay_ms(50);
	}
	else				//IF MASTER
	{
		//DO NOTHING
	}
	return;
}

/**
 * @brief Used to put the cursor of the LCD at a specific location. (SLAVE ONLY COMMAND)
 * 
 * @param au8_row The variable containing the ROW where we want our cursor to be.
 * @param au8_col The variable containing the COLUMN where we want our cursor to be.
 */
void APP_useCursorLCD(u8_t au8_row, u8_t au8_col){
	if (gu8_Authority)  //IF SLAVE
	{
		HAL_LCD_putAtLoc(au8_row, au8_col);
		_delay_ms(50);
	}
	else				//IF MASTER
	{
		//DO NOTHING
	}
	return;
}

/**
 * @brief Used to power LED given MACRO NAMES or NUMBERS. (SLAVE ONLY COMMAND)
 * 
 * @param au8_ledName The variable that stores the values of the LEDS to be powered.
 */
void APP_powerLeds(u8_t au8_ledName){
	if (gu8_Authority)  //IF SLAVE
	{
		HAL_LED_power(au8_ledName);
	}
	else				//IF MASTER
	{
		//DO NOTHING
	}
	return;	
}

/**
 * @brief Used to power the garage MOTOR. (SLAVE ONLY COMMAND)
 * 
 * @param au8_state The variable that stores the values to toggle the MOTOR. (!USE THE MACROS!)
 */
void APP_powerGarageDoor(u8_t au8_state){
	//SWITCH OVER THE STATE ON/OFF MACROS
	switch (au8_state)
	{
		case 0: MCAL_GPIO_PinState(PORTC, PIN0, LOW);
			break;
		case 1: MCAL_GPIO_PinState(PORTC, PIN0, HIGH);
			break;
		default: MCAL_GPIO_PinState(PORTC, PIN0, LOW);
			break;
	}
	return;
}