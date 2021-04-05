/**
 * @file MCAL_UART_private.h
 * @author Mohamed El Barbary (mohmbarbary@gmail.com)
 * @brief Private file that contains the addresses of the registers used in the UART driver.
 * @version 1.0
 * @date 05-04-2021 9:01:59 PM
 * 
 * @copyright Copyright GPL(c) 2021
 * 
 */

#ifndef MCAL_UART_PRIVATE_H_
#define MCAL_UART_PRIVATE_H_

//UART RELATED REGISTERS
#define MCAL_UART_UDR   (*(volatile u8_t*)(0x2C))
#define MCAL_UART_UCSRA (*(volatile u8_t*)(0x2B))
#define MCAL_UART_UCSRB (*(volatile u8_t*)(0x2A))
#define MCAL_UART_UCSRC (*(volatile u8_t*)(0x40))
#define MCAL_UART_UBRRH (*(volatile u8_t*)(0x40))
#define MCAL_UART_UBRRL (*(volatile u8_t*)(0x29))

#endif /* MCAL_UART_PRIVATE_H_ */