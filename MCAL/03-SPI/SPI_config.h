/*****************************************************************************
* @file:    SPI_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sat, 16 Sep 2023 11:01:07 +0300
* @brief:   SPI Driver for Atmega32.
******************************************************************************/
#ifndef _SPI_CONFIG_H
#define _SPI_CONFIG_H

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/********************* Spi pins Configurations ***********************/
/* Mosi pin Configuration */
#define SPI_MOSI_PORT GPIOB
#define SPI_MOSI_PIN  PIN5

/* Miso pin Configuration */
#define SPI_MISO_PORT GPIOB
#define SPI_MISO_PIN  PIN6

/* SCK pin Configuration */
#define SPI_SCK_PORT GPIOB
#define SPI_SCK_PIN  PIN7

/* SS pin Configuration */
#define SPI_SS_PORT GPIOB
#define SPI_SS_PIN  PIN4

/********************* Spi Mode Configurations ***********************/

/* SPI_MODE options: [ SPI_MASTER | SPI_SLAVE ] */
#define SPI_MODE            SPI_SLAVE

/* SPI_CLOCK_POL options: [ SPI_CPOL_0 | SPI_CPOL_1 ] */
#define SPI_CLOCK_POL       SPI_CPOL_0

/* PI_CLOCK_PHASE options: [ SPI_CPHA_LEADING | SPI_CPHA_TRAILING ] */
#define SPI_CLOCK_PHASE     SPI_CPHA_LEADING

/* SPI_DATA_ORDER options: [ SPI_LSB | SPI_MSB ] */
#define SPI_DATA_ORDER      SPI_LSB

/* SPI_SPEED options: [ SPI_NORMAL | SPI_DOUBLE ] */
#define SPI_SPEED           SPI_NORMAL

/* SPI_PRESCALER optins at SPI_NORMAL : [ SPI_PRESCALER_4 | SPI_PRESCALER_16 | SPI_PRESCALER_64 | SPI_PRESCALER_128 ] */
/* SPI_PRESCALER optins at SPI_DOUBLE : [ SPI_PRESCALER_2 | SPI_PRESCALER_8 | SPI_PRESCALER_32 ] */
#define SPI_PRESCALER       SPI_PRESCALER_4


#endif

