/**
 * @file APP_SMARTHOME_interface.h
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Interfacing file that contains the MACROS and Function prototypes used to make the SMARTHOME DRIVER.
 * @version 1.0
 * @date 03-04-2021 3:21:54 AM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#ifndef APP_SMARTHOME_INTERFACE_H_
#define APP_SMARTHOME_INTERFACE_H_

//AUTHORITY MACROs
#define MASTER_MCU (0)
#define SLAVE_MCU  (1)

//APP to LCD MACROS
//LCD ROWS
#define APP_LCD_ROW00  (0x80)
#define APP_LCD_ROW01  (0xC0)

//LCD COLUMNS
#define APP_LCD_COL00 (0)
#define APP_LCD_COL01 (1)
#define APP_LCD_COL02 (2)
#define APP_LCD_COL03 (3)
#define APP_LCD_COL04 (4)
#define APP_LCD_COL05 (5)
#define APP_LCD_COL06 (6)
#define APP_LCD_COL07 (7)
#define APP_LCD_COL08 (8)
#define APP_LCD_COL09 (9)
#define APP_LCD_COL10 (10)
#define APP_LCD_COL11 (11)
#define APP_LCD_COL12 (12)
#define APP_LCD_COL13 (13)
#define APP_LCD_COL14 (14)
#define APP_LCD_COL15 (15)

//LED MACROS
#define APP_LED_KITCHEN (1)
#define APP_LED_GARAGE  (3)
#define APP_LED_NULL    (0)

//DOOR (MOTOR) MACROS
#define APP_GARAGE_DOOR_OFF (0)
#define APP_GARAGE_DOOR_ON  (1)

/**
 * @brief Used to assign the authority of the calling MCU unit.
 * 
 * @param au8_Authority the variable containing the Authority of the MCU (!USE THE MACROS!)
 */
void APP_authority(u8_t au8_Authority);

/**
 * @brief Initializes the application (MASTER/SLAVE have different initializations).
 * 
 */
void APP_init(void);


/**
 * @brief Receives a command via BLUETOOTH/SPI DEPENDING ON THE AUTHORITY. (MASTER/SLAVE COMMAND)
 * 
 * @param pu8_dataHolder A pointer to the variable that will hold the data received.
 */
void APP_recvCMD(u8_t* pu8_dataHolder); 

/**
 * @brief Sends a command via SPI (MASTER ONLY COMMAND)
 * 
 * @param au8_dataSent A variable containing the data to be sent.
 * @param pu8_dataRecv A pointer to a variable for the data to be received.
 */
void APP_sendCMD(u8_t au8_dataSent, u8_t* pu8_dataRecv);

/**
 * @brief Used to write strings on the LCD. (SLAVE ONLY COMMAND)
 * 
 * @param pu8_string A pointer to a variable that contains the string to be shown on the LCD.
 */
void APP_useWriteLCD(u8_t* pu8_string);

/**
 * @brief Used to clear the LCD. (SLAVE ONLY COMMAND)
 * 
 */
void APP_useClearLCD();

/**
 * @brief Used to put the cursor of the LCD at a specific location. (SLAVE ONLY COMMAND)
 * 
 * @param au8_row The variable containing the ROW where we want our cursor to be.
 * @param au8_col The variable containing the COLUMN where we want our cursor to be.
 */
void APP_useCursorLCD(u8_t au8_row, u8_t au8_col);

/**
 * @brief Used to power LED given MACRO NAMES or NUMBERS. (SLAVE ONLY COMMAND)
 * 
 * @param au8_ledName The variable that stores the values of the LEDS to be powered.
 */
void APP_powerLeds(u8_t au8_ledName);

/**
 * @brief Used to power the garage MOTOR. (SLAVE ONLY COMMAND)
 * 
 * @param au8_state The variable that stores the values to toggle the MOTOR. (!USE THE MACROS!)
 */
void APP_powerGarageDoor(u8_t au8_state);

#endif /* APP_SMARTHOME_INTERFACE_H_ */