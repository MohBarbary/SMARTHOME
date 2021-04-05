/**
 * @file MCAL_SPI_program.c
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Program file that contains the implementation of the function prototypes defined in the header files for the SPI DRIVER.
 * @version 1.0
 * @date 05-04-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../LSTD/LSTD_TYPES.h"
#include "../LSTD/LSTD_BITMATH.h"
#include "MCAL_SPI_private.h"
#include "MCAL_SPI_interface.h"

#define F_CPU 16000000UL
#include <util/delay.h>

#define TIMEOUT_DELAY (100)

/**
 * @brief Initializer function for an SPI connection. (!USE THE MACROS!)
 * 
 * @param au8_spiMode  MASTER or Slave mode variable.
 * @param au8_dataOutMode MSB or LSB DATA OUT MODES.
 * @param au8_clockMode CLOCK MODES (LEADING AND TRAILING EDGES respectively defined in MACROS).
 * @param au8_spiSpeed connection speed variable.
 */
void MCAL_SPI_init(u8_t au8_spiMode, u8_t au8_dataOutMode, u8_t au8_clockMode, u8_t au8_spiSpeed){
	//CLEAR THE REGISTER
	MCAL_SPI_SPCR = 0; 
	
	//CHECK IF SPI NEEDS TO ENABLE SPI2X
	if(!(au8_spiSpeed%2))
	{
		//ENABLE SPI2X
		setBit(MCAL_SPI_SPSR, 0);
	}
	else
	{
		//DO NOTHING
	}
	
	//ENABLE SPI PERIPHERAL //SET SPI MODE //SET DATA OUT ORDER MODE //SET CLK MODE //SET SPI SPEED
	MCAL_SPI_SPCR |= (0xC0) | (au8_spiMode << 4) | (au8_dataOutMode << 5) | (au8_clockMode << 2) | (au8_spiSpeed/2);

	return;
}

/**
 * @brief Sending or Receiving one byte as a MASTER.
 * 
 * @param au8_sentData data to be sent.
 * @param pu8_recvData data to be received.
 */
void MCAL_SPI_masterSendRecvByte(u8_t au8_sentData, u8_t* pu8_recvData){
	
	u8_t au8_timeOut = 0;
	
	//STORE THE DATA THAT WILL BE SENT
	MCAL_SPI_SPDR = au8_sentData;
	
	//WAIT FOR GPIO TO SET SS TO LOW
	
	while(!(getBit(MCAL_SPI_SPSR, 7)) && (au8_timeOut < TIMEOUT_DELAY)){
		au8_timeOut++;
		_delay_us(1);
	}
	
	*pu8_recvData = MCAL_SPI_SPDR;
	
	return;
}

/**
 * @brief Sending or Receiving one byte as a SLAVE.
 * 
 * @param au8_sentData data to be sent.
 * @param pu8_recvData data to be received.
 */
void MCAL_SPI_slaveSendRecvByte(u8_t au8_sentData, u8_t* pu8_recvData){
	
	//MCAL_SPI_SPDR = au8_sentData;
	
	if(getBit(MCAL_SPI_SPSR, 7))
	{
		*pu8_recvData = MCAL_SPI_SPDR;
	}
	else
	{
		//DO NOTHING
	}
	return;
}
