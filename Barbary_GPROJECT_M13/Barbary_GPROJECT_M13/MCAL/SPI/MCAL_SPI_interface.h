/**
 * @file MCAL_SPI_interface.h
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Interfacing file that contains all the needed interfacing macros as well as function prototypes.
 * @version 1.0
 * @date 05-04-2021 8:15:25 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#ifndef MCAL_SPI_INTERFACE_H_
#define MCAL_SPI_INTERFACE_H_

//INTERFACING MACROS

//SPI MODE MACROS
#define MCAL_SPI_MASTER	(1)	
#define MCAL_SPI_SLAVE	(0)

//DATA OUT MODE MACROS
#define MCAL_SPI_MSB (0)
#define MCAL_SPI_LSB (1)

//CLOCK MODE //LEADING_EDGE TRAILING_EDGE
#define MCAL_SPI_SAMPLE_R_SETUP_F (0)
#define MCAL_SPI_SETUP_R_SAMPLE_F (1)
#define MCAL_SPI_SAMPLE_F_SETUP_R (2)
#define MCAL_SPI_SETUP_F_SAMPLE_R (3)

//SPEED
#define MCAL_SPI_CLK_BY_2   (0)
#define MCAL_SPI_CLK_BY_4   (1)
#define MCAL_SPI_CLK_BY_8   (2)
#define MCAL_SPI_CLK_BY_16  (3)
#define MCAL_SPI_CLK_BY_32  (4)
#define MCAL_SPI_CLK_BY_64  (5)
#define MCAL_SPI_CLK_BY_128 (7)


//Function prototypes

/**
 * @brief Initializer function for an SPI connection. (!USE THE MACROS!)
 * 
 * @param au8_spiMode  MASTER or Slave mode variable.
 * @param au8_dataOutMode MSB or LSB DATA OUT MODES.
 * @param au8_clockMode CLOCK MODES (LEADING AND TRAILING EDGES respectively defined in MACROS).
 * @param au8_spiSpeed connection speed variable.
 */
void MCAL_SPI_init(u8_t au8_spiMode, u8_t au8_dataOutMode, u8_t au8_clockMode, u8_t au8_spiSpeed);

/**
 * @brief Sending or Receiving one byte as a MASTER.
 * 
 * @param au8_sentData data to be sent.
 * @param pu8_recvData data to be received.
 */
void MCAL_SPI_masterSendRecvByte(u8_t au8_sentData, u8_t* pu8_recvData);

/**
 * @brief Sending or Receiving one byte as a SLAVE.
 * 
 * @param au8_sentData data to be sent.
 * @param pu8_recvData data to be received.
 */
void MCAL_SPI_slaveSendRecvByte(u8_t au8_sentData, u8_t* pu8_recvData);
#endif /* MCAL_SPI_INTERFACE_H_ */