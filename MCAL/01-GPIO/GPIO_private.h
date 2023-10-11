/*****************************************************************************
* @file:    GPIO_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed Gomaa.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Fri, 8 Sep 2023 18:21:12 +0200
* @brief:   GPIO Driver for Atmega32
******************************************************************************/
#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

/* ==================================================================== */
/* ======================== private constants ========================= */
/* ==================================================================== */

/******* Registers of GPIO Driver ***********/

/* OFFSET ADDRESS FOR SFR */
#define __SFR_OFFSET   0x20

/* ADDRESSES FOR SFR OF PORTA */
#define DDRA  *((volatile u8*)(0x1A + __SFR_OFFSET))
#define PORTA *((volatile u8*)(0x1B + __SFR_OFFSET))
#define PINA  *((volatile u8*)(0x19 + __SFR_OFFSET))

/* ADDRESSES FOR SFR OF PORTB */
#define DDRB  *((volatile u8*)(0x17 + __SFR_OFFSET))
#define PORTB *((volatile u8*)(0x18 + __SFR_OFFSET))
#define PINB  *((volatile u8*)(0x16 + __SFR_OFFSET))

/* ADDRESSES FOR SFR OF PORTC */
#define DDRC  *((volatile u8*)(0x14 + __SFR_OFFSET))
#define PORTC *((volatile u8*)(0x15 + __SFR_OFFSET))
#define PINC  *((volatile u8*)(0x13 + __SFR_OFFSET))

/* ADDRESSES FOR SFR OF PORTD */
#define DDRD  *((volatile u8*)(0x11 + __SFR_OFFSET))
#define PORTD *((volatile u8*)(0x12 + __SFR_OFFSET))
#define PIND  *((volatile u8*)(0x10 + __SFR_OFFSET))

#endif
