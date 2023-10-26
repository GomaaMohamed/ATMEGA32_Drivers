/*****************************************************************************
* @file:    KEYPAD_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2  
* @date:    Wed, 13 Sep 2023 17:17:21 +0300
* @brief:   Keypad Driver 4*4.
******************************************************************************/
#ifndef _KEYPAD_INTERFACE_H
#define _KEYPAD_INTERFACE_H

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */


/**
 * @brief---------------------> Initialize keypad module 
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant 
 */
void KEYPAD_init(void);


/**
 * @brief---------------------> Scan keypad
 * @param---------------------> None
 * @return--------------------> Pressed button
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant  
 */
u8 KEYPAD_scanKeypad(void);


#endif
