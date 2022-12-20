/*
 * USART_Private.h
 *
 *  Created on: Oct 18, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_USART_DRIVER_USART_PRIVATE_H_
#define MCAL_USART_DRIVER_USART_PRIVATE_H_

#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"

#define OFFSET_ADDRESS 0x20
#define NULL ((void*) 0)

#define ISR(vector, ...)            \
		void vector (void) __attribute__ ((signal)) __VA_ARGS__; \
		void vector (void)


#define USART_RX_VECTOR __vector_13
#define USART_TX_VECTOR __vector_15
#define USART_BUFFER_EMPTY_VECTOR __vector_14


#define UDR		_MMIO_BYTE(0x0C + OFFSET_ADDRESS)

#define UCSRA	_MMIO_BYTE(0x0B + OFFSET_ADDRESS)


#define UCSRB  	_MMIO_BYTE(0x0A + OFFSET_ADDRESS)



#define UBRRL	_MMIO_BYTE(0x09 + OFFSET_ADDRESS)
#define UBRRH   _MMIO_BYTE(0x20 + OFFSET_ADDRESS)

#define UCSRC	UBRRH

/* UCSRA */
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0

/* UCSRB */
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

/* UCSRC */
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0

#define No_Parity 	0
#define Odd_Parity	1
#define Even_Parity 2


#endif /* MCAL_USART_DRIVER_USART_PRIVATE_H_ */
