/*****************************************************************************
* @file:    EEPROM_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 20 Sep 2023 00:01:58 +0300
* @brief:   EEPROM Driver for Atmega32.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to write to eeprom
void EEPROM_write(u16 Address, u8 Data)
{
    // Wait for completion of previous write 
	while(EECR & (1<<EEWE));
	// Set up address and data registers 
	EEAR = Address;
	EEDR = Data;
	// Write logical one to EEMWE 
	EECR |= (1<<EEMWE);
	// Start eeprom write by setting EEWE 
	EECR |= (1<<EEWE);
}

// Function to read from eeprom
u8 EEPROM_read(u16 Address)
{
    // Wait for completion of previous write 
	while(EECR & (1<<EEWE));
	// Set up address register 
	EEAR = Address;
	// Start eeprom read by writing EERE 
	EECR |= (1<<EERE);
	// Return data from data register 
	return EEDR;
}

// Function to read 4 bytes from eeprom
u32 EEPROM_read4Bytes(u16 Address)
{
    u8 Value=0;
	u32 Result=0;
	for(u8 i=0;i<4;i++)
	{
		Value=EEPROM_read(Address+i);
		Result=Result+((u32)Value<<i*8);

	}
	return Result;
}

// Function to write 4 bytes to eeprom
void EEPROM_write4Bytes(u16 Address,u32 Data)
{
    for(u8 i=0;i<4;i++)
	{
	EEPROM_write(Address+i,(u8)(Data>>(i*8)));
	}
}




/* ==================================================================== */
/* ================ Private Functions Implementation ================== */
/* ==================================================================== */

/* Function Implementation for private (static) functions go here */






