/**
 * @file MCAL_UART_interface.h
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Interfacing file that contains interfacing macros and function prototypes for the UART driver.
 * @version 1.0
 * @date 05-04-2021 9:02:39 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#ifndef MCAL_UART_INTERFACE_H_
#define MCAL_UART_INTERFACE_H_

//INTERFACING MACROS

//BAUD RATE REGISTER VALUES AT 16MHz
#define MCAL_UART_BR_2400   (416) //UBRR HIGH AND LOW
#define MCAL_UART_BR_4800   (207) //UBRR LOW
#define MCAL_UART_BR_9600   (103)
#define MCAL_UART_BR_19200  (51)
#define MCAL_UART_BR_115200 (8)

//Functions prototypes

/**
 * @brief Initialize a UART connection with a given BAUD RATE.
 * 
 * @param au16_baudRate the baud rate to be passed for the init function (!Please use the pre-defined MACROS!).
 */
void MCAL_UART_init(u16_t au16_baudRate);

/**
 * @brief Send one byte via an already established UART connection.
 * 
 * @param au8_dataByte the data to be sent.
 */
void MCAL_UART_sendByte(u8_t au8_dataByte);

/**
 * @brief Send a stream of data via an already established UART connection.
 * 
 * @param pu8_dataStream a pointer to the data to be sent.
 * @param au8_dataSize the size of that data.
 */
void MCAL_UART_sendStream(u8_t* pu8_dataStream, u8_t au8_dataSize);

/**
 * @brief Receive one byte via an already established UART connection.
 * 
 * @param pu8_dataBye a pointer to the data to be received.
 */
void MCAL_UART_recvByte(u8_t* pu8_dataBye);

#endif /* MCAL_UART_INTERFACE_H_ */