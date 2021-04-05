/**
 * @file HAL_LCD_interface.h
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief This is the h file that is used for our macros, function prototypes and declaration used in our LCD16x2 Driver. !PLEASE DON'T FORGET TO USE DELAYS!
 * @version 1.0
 * @date 29-01-2021 10:19:20 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */


#ifndef HAL_LCD_INTERFACE_H_
#define HAL_LCD_INTERFACE_H_

//START INTERFACING MACROS

//Defining the LCD ROWS (THE MEMORY ADDRESSES ARE AVAILABLE IN THE DATA SHEET) and COLUMNS

#define HAL_LCD_ROW00  (0x80)
#define HAL_LCD_ROW01  (0xC0)

#define HAL_LCD_COL00 (0)
#define HAL_LCD_COL01 (1)
#define HAL_LCD_COL02 (2)
#define HAL_LCD_COL03 (3)
#define HAL_LCD_COL04 (4)
#define HAL_LCD_COL05 (5)
#define HAL_LCD_COL06 (6)
#define HAL_LCD_COL07 (7)
#define HAL_LCD_COL08 (8)
#define HAL_LCD_COL09 (9)
#define HAL_LCD_COL10 (10)
#define HAL_LCD_COL11 (11)
#define HAL_LCD_COL12 (12)
#define HAL_LCD_COL13 (13)
#define HAL_LCD_COL14 (14)
#define HAL_LCD_COL15 (15)


//END OF INTERFACING MACROS

/**
 * @brief HAL_LCD_init is the LCD16x2 Initializing function.
 * 
 */
void HAL_LCD_init(void);

/**
 * @brief HAL_LCD_displayCharacter is a function that displays the character passed as a parameter on the LCD16x2.
 * 
 * @param au8_charData is the data that will be passed to the LCD16x2.
 */
void HAL_LCD_displayCharacter(u8_t au8_charData);

/**
 * @brief HAL_LCD_displayString is a function that displays a given string on the LCD16x2 screen (!Be careful of character overflows!)
 * 
 * @param pu8_srtData is a pointer to the 8 bits of dat that will be displayed. 
 */
void HAL_LCD_displayString(u8_t* pu8_srtData);

/**
 * @brief HAL_LCD_putAtLoc is a function that moves the cursor of the LCD16x2 to the DDRAM address passed.
 * 
 * @param au8_row is the variable containing the row where we want to move (!DO NOT FORGET TO USE THE MACROS!)
 * @param au8_col is the variable containing the column where we want to move (!DO NOT FORGET TO USE THE MACROS!)
 */
void HAL_LCD_putAtLoc(u8_t au8_row, u8_t au8_col);
/**
 * @brief HAL_LCD_clearDisplay is a function that clears the display of the LCD16x2.
 * 
 */
void HAL_LCD_clearDisplay(void);

#endif 