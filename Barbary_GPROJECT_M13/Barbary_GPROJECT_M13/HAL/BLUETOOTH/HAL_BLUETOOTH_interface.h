/**
 * @file HAL_BLUETOOTH_interface.h
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Interfacing file that contains the MACROS and Function prototypes used to make the BLUETOOTH DRIVER.
 * @version 1.0
 * @date 03-04-2021 2:49:17 AM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#ifndef HAL_BLUETOOTH_INTERFACE_H_
#define HAL_BLUETOOTH_INTERFACE_H_


//Interfacing Macros

#define BLUETOOTH_DATA_BAUDRATE (103)


//Function prototypes

/**
 * @brief Establishes a Bluetooth connection with a given BAUD RATE. (!PLEASE USE THE DEFAULT BAUD-RATE FOR BLUETOOTH!)
 * 
 * @param au16_baudRate variable that contains the BAUD RATE to be passed to the function.
 */
void HAL_establishBluetooth(u16_t au16_baudRate);

/**
 * @brief Receive data from an already established BLUETOOTH connection with a given device.
 * 
 * @param pu8_dataHolder pointer to the variable that contains the data received from the BLUETOOTH Transmission.
 */
void HAL_recvBluetooth(u8_t* pu8_dataHolder);


#endif /* HAL_BLUETOOTH_INTERFACE_H_ */