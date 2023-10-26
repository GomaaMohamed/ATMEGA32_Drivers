/*****************************************************************************
* @file:    EEPROM_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2  
* @date:    Wed, 20 Sep 2023 00:01:58 +0300
* @brief:   EEPROM Driver for Atmega32.
******************************************************************************/
#ifndef _EEPROM_PRIVATE_H
#define _EEPROM_PRIVATE_H

/* ==================================================================== */
/* =================== Private Variables and Macros =================== */
/* ==================================================================== */

/* EEPROM Registers */
#define OFFSET_ADDRESS 0x20

/* EEPROM Control Register */
#define EECR	*((volatile u8*)(OFFSET_ADDRESS+0x1C))

/* EEPROM Data Register */
#define EEDR	*((volatile u8*)(OFFSET_ADDRESS+0x1D))

/* EEPROM Address Register */
#define EEAR	*((volatile u8*)(OFFSET_ADDRESS+0x1E))
#define EEARL	*((volatile u8*)(OFFSET_ADDRESS+0x1E))
#define EEARH	*((volatile u8*)(OFFSET_ADDRESS+0x1F))

/* EECR bits */
#define EERIE 	 3
#define EEMWE    2
#define EEWE     1
#define EERE     0


#endif

