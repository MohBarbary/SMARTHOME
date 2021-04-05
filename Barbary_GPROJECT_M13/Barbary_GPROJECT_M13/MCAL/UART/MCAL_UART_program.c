/**
 * @file MCAL_UART_program.c
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Program file that contains the implementation for the function prototypes defined in the header files.
 * @version 1.0
 * @date 05-04-2021 9:03:12 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#include "../LSTD/LSTD_BITMATH.h"
#include "../LSTD/LSTD_TYPES.h"
#include "MCAL_UART_private.h"
#include "MCAL_UART_interface.h"

#define F_CPU 16000000UL
#include <util/delay.h>

//SYSTEM MACRO

#define TIMEOUT_DELAY (10)

/**
 * @brief Initialize a UART connection with a given BAUD RATE.
 * 
 * @param au16_baudRate the baud rate to be passed for the init function (!Please use the pre-defined MACROS!).
 */
void MCAL_UART_init(u16_t au16_baudRate){
	
	//8 BIT MODE TX/RX ENABLE
	MCAL_UART_UCSRB = 0x18;
	
	//8 BIT MODE ASYNCHRONOUS, NO PARITY BIT, 1 STOP BIT
	MCAL_UART_UCSRC = (0x80) | (0x06);
	
	//STORE THE FIRST 8 BITS 
	MCAL_UART_UBRRL = (u8_t)(au16_baudRate);
	
	//STORE THE SECOND 8 BITS AND CLEAR BIT 7 TO ACCESS MCAL_UART_UBRRH
	MCAL_UART_UBRRH = (u8_t)(au16_baudRate >> 8);
	
	return;
}

/**
 * @brief Send one byte via an already established UART connection.
 * 
 * @param au8_dataByte the data to be sent.
 */
void MCAL_UART_sendByte(u8_t au8_dataByte){
	
	u8_t au8_timeOut = 0;
	//CHECKING UART DATA REGISTER ENABLE BIT
	if(getBit(MCAL_UART_UCSRA, 5))
	{
		//TRANSMIT THE DATA
		MCAL_UART_UDR = au8_dataByte;
		//Waiting until the transmission is complete
		while( (!getBit(MCAL_UART_UCSRA, 6)) && (au8_timeOut < TIMEOUT_DELAY)){
			//INC TIMEOUT
			au8_timeOut++;
			//DELAY FOR 1 MS
			_delay_ms(1);
		}
	}
	else
	{
		//DO NOTHING
	}
	
	//CLEAR TXC FLAG
	setBit(MCAL_UART_UCSRA, 6);
	return;
}

/**
 * @brief Send a stream of data via an already established UART connection.
 * 
 * @param pu8_dataStream a pointer to the data to be sent.
 * @param au8_dataSize the size of that data.
 */
void MCAL_UART_sendStream(u8_t* pu8_dataStream, u8_t au8_dataSize){
	u8_t au8_iterator = 0;
	while(au8_dataSize--)
	{
		MCAL_UART_sendByte(pu8_dataStream[au8_iterator]);
		au8_iterator++;
	}
	return;
}

/**
 * @brief Receive one byte via an already established UART connection.
 * 
 * @param pu8_dataBye a pointer to the data to be received.
 */
void MCAL_UART_recvByte(u8_t* pu8_dataBye){
	//CHECK IF THERE'S ANY DATA IN UDR REGISTER 
	if(getBit(MCAL_UART_UCSRA, 7))
	{
		*pu8_dataBye = MCAL_UART_UDR;
	}
	else
	{
		//DO NOTHING
	}
	return;
}