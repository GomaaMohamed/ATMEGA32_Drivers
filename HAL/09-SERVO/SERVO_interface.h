/*****************************************************************************
* @file:    SERVO_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2
* @date:    Sun, 01 Oct 2023 22:24:42 +0300
* @brief:   Servo Motor Driver.
******************************************************************************/
#ifndef _SERVO_INTERFACE_H
#define _SERVO_INTERFACE_H


/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize servo module 
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void SERVO_init(void);

/**
 * @brief---------------------> Set angle 
 * @parameter1----------------> (Degree) angle in degrees from 0 to 180
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void SERVO_setPosition(u8 Degree);



#endif

