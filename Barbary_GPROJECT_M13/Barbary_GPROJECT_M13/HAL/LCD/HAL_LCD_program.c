/**
 * @file HAL_LCD_program.c
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief HAL_LCD_program.c is the file that contains the implementation for the function prototypes found in the HAL_LCD_interface.h file.
 * @version 1.0
 * @date 25-03-2021 10:19:20 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

//Start of INCLUDED FILES
#include "LSTD_BITMATH.h"
#include "LSTD_TYPES.h"
#include "MCAL_GPIO_interface.h"
#include "HAL_LCD_private.h"
#include "HAL_LCD_interface.h"

#define F_CPU 16000000UL
#include <util/delay.h>

//End of INCLUDED FILES


//Start of function definitions
/**
 * @brief HAL_LCD_sendCMD is a static helper function created to improve the readability of the code and to make it easier to understand. This function is used to process any command that
 * we pass to it from any other function.
 * 
 * @param au8_cmd is the variable that contains the 8 bit command that we cant to excute. (!MY KIT ONLY HAD 4 BITS, WHICH IS WHY THE IMPLEMENTATION OF THE FUNCTION SENDS THE 8 BITS ON TWO STAGES!)
 */
static void HAL_LCD_sendCMD(u8_t au8_cmd){
	
	//Set RS PIN OF CTRL PORT TO LOW (SEND CMD)
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_RS_PIN, LOW);
	
	//Set R/W PIN TO LOW TO WRITE OVER LCD
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_RW_PIN, LOW);
	
	//Getting the pin state of au8_cmd and setting each pin with same value [ UPPER NIBBLE ]
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D4_PIN, getBit(au8_cmd, 4));
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D5_PIN, getBit(au8_cmd, 5));
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D6_PIN, getBit(au8_cmd, 6));
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D7_PIN, getBit(au8_cmd, 7));
	
	//sending enable signal for [ UPPER NIBBLE ]
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_EN_PIN, LOW);	
	_delay_us(50);
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_EN_PIN, HIGH);
	
	//Getting the pin state of au8_cmd and setting each pin with same value [ LOWER NIBBLE ]
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D4_PIN, getBit(au8_cmd, 0));
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D5_PIN, getBit(au8_cmd, 1));
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D6_PIN, getBit(au8_cmd, 2));
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D7_PIN, getBit(au8_cmd, 3));
		
	//sending enable signal for [ LOWER NIBBLE ]
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_EN_PIN, LOW);
	_delay_us(50);
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_EN_PIN, HIGH);
		
	return;
}

/**
 * @brief HAL_LCD_sendData is a static helper function created to improve the readability of the code and to make it easier to understand. This function is used to process any data that
 * we pass to it from any other function.
 * 
 * @param au8_data is the variable containing the data that we will display on the LCD16x2
 */
static void HAL_LCD_sendData(u8_t au8_data){
	
	//Set RS PIN OF CTRL PORT TO HIGH (SEND DATA)
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_RS_PIN, HIGH);
	
	//Set R/W PIN TO LOW TO WRITE OVER LCD
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_RW_PIN, LOW);
	
	//Getting the pin state of au8_cmd and setting each pin with same value [ UPPER NIBBLE ]
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D4_PIN, getBit(au8_data, 4));
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D5_PIN, getBit(au8_data, 5));
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D6_PIN, getBit(au8_data, 6));
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D7_PIN, getBit(au8_data, 7));
	
	//sending enable signal for [ UPPER NIBBLE ]
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_EN_PIN, LOW);
	//_delay_us(50);
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_EN_PIN, HIGH);
	
	//Getting the pin state of au8_cmd and setting each pin with same value [ LOWER NIBBLE ]
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D4_PIN, getBit(au8_data, 0));
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D5_PIN, getBit(au8_data, 1));
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D6_PIN, getBit(au8_data, 2));
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D7_PIN, getBit(au8_data, 3));
	
	//sending enable signal for [ LOWER NIBBLE ]
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_EN_PIN, LOW);
	_delay_us(50);
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_EN_PIN, HIGH);
	
	return;
}

/**
 * @brief HAL_LCD_init is the LCD16x2 Initializing function.
 * 
 */
void HAL_LCD_init(void){
	
	//SET CTRL PINS TO OUTPUT
	MCAL_GPIO_PinMode(HAL_LCD_CTRL_PORT, (HAL_LCD_RS_PIN | HAL_LCD_RW_PIN | HAL_LCD_EN_PIN), OUTPUT);
	
	//SET DATA PINS TO OUTPUT
	MCAL_GPIO_PinMode(HAL_LCD_DATA_PORT, (HAL_LCD_D4_PIN | HAL_LCD_D5_PIN | HAL_LCD_D6_PIN | HAL_LCD_D7_PIN), OUTPUT);
	
	//Initialize enable TO HIGH
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_EN_PIN, HIGH);
	
	//INITIALIZE THE LCD
	_delay_ms(50);
	
	//Set RS PIN OF CTRL PORT TO LOW (SEND CMD)
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_RS_PIN, LOW);
	
	//Set R/W PIN TO LOW TO WRITE OVER LCD
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_RW_PIN, LOW);
	
	//Getting the pin state of au8_cmd and setting each pin with same value [ UPPER NIBBLE ]
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D4_PIN, LOW);
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D5_PIN, HIGH);
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D6_PIN, LOW);
	MCAL_GPIO_PinState(HAL_LCD_DATA_PORT, HAL_LCD_D7_PIN, LOW);
	
	//sending enable signal for [ UPPER NIBBLE ]
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_EN_PIN, LOW);
	_delay_us(50);
	MCAL_GPIO_PinState(HAL_LCD_CTRL_PORT, HAL_LCD_EN_PIN, HIGH);
	
	//Function set command
	HAL_LCD_sendCMD(0x2C);
	
	//wait for 50us
	_delay_us(50);
	
	//Display ON/OFF command
	HAL_LCD_sendCMD(0x0F);
	
	//wait for 50us
	_delay_us(50);
	
	//CLEAR DISPLAY command
	HAL_LCD_sendCMD(0x01);
	
	_delay_ms(2); //!SUPER IMPORTANT!//
	
	//Entry mode command
	HAL_LCD_sendCMD(0x06);
	
	return;
}

/**
 * @brief HAL_LCD_displayCharacter is a function that displays the character passed as a parameter on the LCD16x2.
 * 
 * @param au8_charData is the data that will be passed to the LCD16x2.
 */
void HAL_LCD_displayCharacter(u8_t au8_charData){
	
	//send character data
	HAL_LCD_sendData(au8_charData);
	
	return;
}

/**
 * @brief HAL_LCD_displayString is a function that displays a given string on the LCD16x2 screen (!Be careful of character overflows!)
 * 
 * @param pu8_srtData is a pointer to the 8 bits of dat that will be displayed. 
 */
void HAL_LCD_displayString(u8_t* pu8_srtData){
	
	u8_t au8_i = -1;
	
	while(pu8_srtData[++au8_i] != '\0')
	{
		HAL_LCD_sendData(pu8_srtData[au8_i]);
	}
	
	return;
}

/**
 * @brief HAL_LCD_putAtLoc is a function that moves the cursor of the LCD16x2 to the DDRAM address passed.
 * 
 * @param au8_row is the variable containing the row where we want to move (!DO NOT FORGET TO USE THE MACROS!)
 * @param au8_col is the variable containing the column where we want to move (!DO NOT FORGET TO USE THE MACROS!)
 */
void HAL_LCD_putAtLoc(u8_t au8_row, u8_t au8_col){
	
	HAL_LCD_sendCMD(au8_row | au8_col);
}

/**
 * @brief HAL_LCD_clearDisplay is a function that clears the display of the LCD16x2.
 * 
 */
void HAL_LCD_clearDisplay(void){
	
	HAL_LCD_sendCMD(0x01);
	
	//_delay_ms(2);
	
	return;
}

//End of function definitions