/*****************************************************************************
* @file:    WDG_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sun, 01 Oct 2023 22:26:56 +0300
* @brief:   Watch Dog Driver for Atmega32.
******************************************************************************/
#ifndef WDG_PRIVATE_H
#define WDG_PRIVATE_H

/* ==================================================================== */
/* =================== Private Variables and Macros =================== */
/* ==================================================================== */

#define BASE_ADDRESS 0x20
/************ Watch Dog timer registers ******************/
#define WDTCR    *((volatile u8*)(BASE_ADDRESS + 0x21))

/*** WDTCR bits ***/
/* bits 7-5 reserved */
#define WDTOE   4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0


#endif

