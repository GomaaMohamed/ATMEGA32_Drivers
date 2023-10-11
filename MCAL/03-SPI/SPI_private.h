/************************************************************************
* @file:    SPI_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2  
* @date:    Sat, 16 Sep 2023 11:01:07 +0300
* @brief:   SPI Driver for Atmega32.
*************************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* ==================================================================== */
/* =================== Private Variables and Macros =================== */
/* ==================================================================== */

/* SPI Registers */
#define OFFSET_ADDRESS 0x20

#define SPCR *((volatile u8*)(OFFSET_ADDRESS + 0x0D))

#define SPSR *((volatile u8*)(OFFSET_ADDRESS + 0x0E))

#define SPDR *((volatile u8*)(OFFSET_ADDRESS + 0x0F))

/* SPCR bits */
#define SPIE 7
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

/* SPSR */
#define SPIF  7
#define WCOL  6
#define SPI2X 0

/* Private Configurations */
#define SPI_MASTER 0
#define SPI_SLAVE  1 

#define SPI_CPOL_0 0
#define SPI_CPOL_1 1

#define SPI_CPHA_LEADING  0
#define SPI_CPHA_TRAILING 1

#define SPI_MSB 7
#define SPI_LSB 0

#define SPI_NORMAL 0
#define SPI_DOUBLE 1

#define SPI_PRESCALER_4   4
#define SPI_PRESCALER_16  16
#define SPI_PRESCALER_64  64
#define SPI_PRESCALER_128 128

#define SPI_PRESCALER_2   2
#define SPI_PRESCALER_8   8
#define SPI_PRESCALER_32  32


#endif

