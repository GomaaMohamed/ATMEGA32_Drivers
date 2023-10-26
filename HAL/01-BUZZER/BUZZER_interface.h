/*****************************************************************************
* @file:    BUZZER_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2  
* @date:    Sat, 09 Sep 2023 21:50:19 +0300
* @brief:   Buzzer Driver.
******************************************************************************/
#ifndef _BUZZER_INTERFACE_H
#define _BUZZER_INTERFACE_H


/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize buzzer module 
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void BUZZER_init(void);

/**
 * @brief---------------------> Turn on led
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Buzzer module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void BUZZER_turnOn(void);

/**
 * @brief---------------------> Turn off buzzer
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Buzzer module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void BUZZER_turnOff(void);


/**
 * @brief---------------------> Toggle buzzer state
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Buzzer module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void BUZZER_toggle(void);



#endif

