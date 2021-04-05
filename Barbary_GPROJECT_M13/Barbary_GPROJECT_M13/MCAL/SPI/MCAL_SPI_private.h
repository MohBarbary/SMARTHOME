/**
 * @file MCAL_SPI_private.h
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Private file that contains the addresses for the registers to be used in the SPI DRIVER.
 * @version 1.0
 * @date 05-04-2021 8:15:38 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */


#ifndef MCAL_SPI_PRIVATE_H_
#define MCAL_SPI_PRIVATE_H_

//SPI REGISTERS

#define MCAL_SPI_SPCR (*(volatile u8_t*)(0x2D))
#define MCAL_SPI_SPSR (*(volatile u8_t*)(0x2E))
#define MCAL_SPI_SPDR (*(volatile u8_t*)(0x2F))

#endif /* MCAL_SPI_PRIVATE_H_ */