/*****************************************************************************
* @file:    SEVSEG_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 13 Sep 2023 12:48:20 +0300
* @brief:   Seven Segments Driver with multiplixer.
******************************************************************************/
#ifndef _SEVSEG_CONFIG_H
#define _SEVSEG_CONFIG_H

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/********** BCD Decoder Input Pins Configuration ****************/
/* PINA configurations */
#define DECODER_PINA_PORT GPIOB
#define DECODER_PINA_PIN  PIN0

/* PINB configurations */
#define DECODER_PINB_PORT GPIOB
#define DECODER_PINB_PIN  PIN1

/* PINC configurations */
#define DECODER_PINC_PORT GPIOB
#define DECODER_PINC_PIN  PIN2

/* PIND configurations */
#define DECODER_PIND_PORT GPIOB
#define DECODER_PIND_PIN  PIN4

/********* Seven Segments Common Pins Configurations **********/
/* COM1 Configurations */
#define COM1_PORT GPIOA
#define COM1_PIN  PIN3

/* COM2 Configurations */
#define COM2_PORT GPIOA
#define COM2_PIN  PIN2

/* COM3 Configurations */
#define COM3_PORT GPIOB
#define COM3_PIN  PIN5

/* COM4 Configurations */
#define COM4_PORT GPIOB
#define COM4_PIN  PIN6


#endif

