/*****************************************************************************
* @file:    LM35_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Mon, 18 Sep 2023 18:14:04 +0300
* @brief:   Temprature Sensor(LM35) Driver.
******************************************************************************/
#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize lm35 module 
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void LM35_init(void);

/**
 * @brief---------------------> Get temprature 
 * @param---------------------> None
 * @return--------------------> Temprature C
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant  
 */
u8 LM35_getTemprature(void);

#endif

