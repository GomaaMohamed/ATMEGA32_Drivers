/*****************************************************************************
* @file:    UART_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Fri, 08 Sep 2023 21:34:43 +0300
* @brief:   UART Driver for Atmega32.
*************************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/* ==================================================================== */
/* =================== Private Variables and Macros =================== */
/* ==================================================================== */

/* Registers of UART */
#define OFFSET_ADDRESS 0x20

#define UDR		*((volatile u8*)(0x0C + OFFSET_ADDRESS))

#define UCSRA	*((volatile u8*)(0x0B + OFFSET_ADDRESS))


#define UCSRB  	*((volatile u8*)(0x0A + OFFSET_ADDRESS))



#define UBRRL	*((volatile u8*)(0x09 + OFFSET_ADDRESS))
#define UBRRH   *((volatile u8*)(0x20 + OFFSET_ADDRESS))

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


/******************** UART mode *************************/
#define NORMAL_SPEED      0
#define DOUBLE_SPEED      1
#define TOTAL_SPEED_MODE  2 
/******************** Cpu freqs ***************************/
#define   CPU_4_MHZ         0
#define   CPU_8_MHZ         1
#define   CPU_16_MHZ        2
#define   TOTAL_CPU_F       3
/*******************baud rate *****************************/
#define  BAUD_2400       0
#define  BAUD_4800       1
#define  BAUD_9600       2
#define  BAUD_14400      3
#define  BAUD_19200      4
#define  BAUD_28800      5
#define  TOTAL_BAUD_RATE 6
/******************* Parity bit *************************/
#define NO_PARITY    0
#define EVEN_PARITY  1
#define ODD_PARITY   2
/*************** number of data bits ********************/
#define  DATA_BITS_5    5
#define  DATA_BITS_6    6
#define  DATA_BITS_7    7
#define  DATA_BITS_8    8
#define  DATA_BITS_9    9

/*************** Sync mode *************************/
#define  SYNCH  0
#define  ASYNCH 1
/************ Number of stop bits *****************/
#define  ONE_STOP_BIT   1
#define  TWO_STOP_BIT   2

static void (*UART_RX_Callback) (void);
static void (*UART_TX_Callback) (void);



#endif

