/*****************************************************************************
* @file:    UART_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Fri, 08 Sep 2023 21:34:43 +0300
* @brief:   UART Driver for Atmega32.
******************************************************************************/
#ifndef _UART_CONFIG_H
#define _UART_CONFIG_H

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/* UART pins */
#define UART_TX_PORT GPIOD
#define UART_TX_PIN  PIN1

#define UART_RX_PORT GPIOD
#define UART_RX_PIN  PIN0

/* SPEED_MODE Options: [ NORMAL_SPEED | DOUBLE_SPEED | TOTAL_SPEED_MODE ] */
#define SPEED_MODE NORMAL_SPEED

/* CPU_F Options: [ CPU_4_MHZ | CPU_8_MHZ | CPU_16_MHZ | TOTAL_CPU_F ] */
#define CPU_F CPU_16_MHZ

/* BUAD_RATE Options: [ BAUD_2400 | BAUD_4800 | BAUD_9600 | BAUD_14400 | BAUD_19200 | BAUD_28800 | TOTAL_BAUD_RATE ] */
#define  BUAD_RATE   BAUD_9600

/* SYNCH_MODE Options: [ SYNCH | ASYNCH */
#define  SYNCH_MODE   ASYNCH

/* PARITY_MODE Options: [ NO_PARITY | EVEN_PARITY | ODD_PARITY ] */
#define  PARITY_MODE   NO_PARITY

/* NUMBER_OF_DATA_BITS Options: [ DATA_BITS_5 | DATA_BITS_6 | DATA_BITS_7 | DATA_BITS_8 | DATA_BITS_9 ] */
#define  NUMBER_OF_DATA_BITS   DATA_BITS_8

/* NUMBER_OF_STOP_BITS Options: [ ONE_STOP_BIT | TWO_STOP_BIT ] */
#define  NUMBER_OF_STOP_BITS   ONE_STOP_BIT



#endif

