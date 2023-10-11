/*****************************************************************************
* @file:    EXEEPROM_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sat, 23 Sep 2023 12:18:05 +0300
* @brief:   External EEPROM Driver.
******************************************************************************/
#ifndef EXEEPROM_INTERFACE_H
#define EXEEPROM_INTERFACE_H

/* ==================================================================== */
/* ======================= Public Data Types ========================== */
/* ==================================================================== */

typedef enum
{
    ERROR = 0,
    SUCCESS
} EepromState_type;
/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize eeprom module 
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void EXEEPROM_Init();

/**
 * @brief---------------------> Write byte to eeprom 
 * @parameter1----------------> (Addr) address of data
 * @parameter2----------------> (Data) data to be written 
 * @return--------------------> State of write
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant  
 */
EepromState_type EXEEPROM_WriteByte(u16 Addr,u8 data);

/**
 * @brief---------------------> Read byte from eeprom 
 * @parameter1----------------> (Addr) address of data
 * @parameter2----------------> (Data) data to be read
 * @return--------------------> State of read
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant  
 */
EepromState_type EXEEPROM_ReadByte(u16 Addr,u8 *data);



#endif

