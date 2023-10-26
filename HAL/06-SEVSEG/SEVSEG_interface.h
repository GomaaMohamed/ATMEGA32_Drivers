/*****************************************************************************
* @file:    SEVSEG_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 13 Sep 2023 12:48:20 +0300
* @brief:   Seven Segments Driver with multiplixer.
******************************************************************************/
#ifndef _SEVSEG_INTERFACE_H
#define _SEVSEG_INTERFACE_H

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize seven segments module 
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void SEVSEG_init(void);

/**
 * @brief---------------------> Write number on seven segments 
 * @parameter1----------------> (Number) number to be written
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void SEVSEG_writeNumber(u32 Number);

#endif

