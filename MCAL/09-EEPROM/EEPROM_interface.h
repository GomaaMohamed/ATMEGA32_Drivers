/******************************************************************************
* @file:    EEPROM_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 20 Sep 2023 00:01:58 +0300
* @brief:   EEPROM Driver for Atmega32.
*******************************************************************************/
#ifndef _EEPROM_INTERFACE_H
#define _EEPROM_INTERFACE_H

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Write data to eeprom at a specific address
 * @parameter1----------------> (Address) address of data
 * @parameter2----------------> (Data) data itself to be written
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant             
 */
void EEPROM_write(u16 Address, u8 Data);


/**
 * @brief---------------------> Read data from eeprom 
 * @parameter1----------------> (Address) address of data
 * @return--------------------> Data to be read
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant             
 */
u8 EEPROM_read(u16 Address);

/**
 * @brief---------------------> Read 4 bytes data from eeprom 
 * @parameter1----------------> (Address) address of data
 * @return--------------------> Data
 * @preconditions-------------> Uart module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant             
 */
u32 EEPROM_read4Bytes(u16 Address);

/**
 * @brief---------------------> Write 4 bytes data to eeprom 
 * @parameter1----------------> (Address) address of data
 * @parameter2----------------> (Data) data itself
 * @return--------------------> None
 * @preconditions-------------> Uart module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant             
 */
void EEPROM_write4Bytes(u16 Address,u32 Data);



#endif

