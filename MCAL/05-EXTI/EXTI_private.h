/*****************************************************************************
* @file:    EXTI_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sat, 16 Sep 2023 06:48:06 +0300
* @brief:   EXTI driver for Atmega32.
******************************************************************************/
#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H

/* ==================================================================== */
/* =================== Private Variables and Macros =================== */
/* ==================================================================== */

#define OFFSET_ADDRESS 0x20

#define MCUCR  *((volatile u8 *)(OFFSET_ADDRESS + 0x35))
#define MCUCSR *((volatile u8 *)(OFFSET_ADDRESS + 0x34))
#define GICR   *((volatile u8 *)(OFFSET_ADDRESS + 0x3B)) 
#define GIFR   *((volatile u8 *)(OFFSET_ADDRESS + 0x3A))
#define SREG   *((volatile u8 *)(OFFSET_ADDRESS + 0x3F)) 

/* MCUCR bits */
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

/* MCUCSR bits */ 
#define ISC2 6

/* GICR bits */
#define INT1 7
#define INT0 6
#define INT2 5

/* SREG bits */
#define GIE_PIN 7

/* Callbacks */
void (*INT0_Callback)(void);
void (*INT1_Callback)(void);
void (*INT2_Callback)(void);



#endif

