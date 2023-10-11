/*****************************************************************************
* @file:    EXTI_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sat, 16 Sep 2023 06:48:06 +0300
* @brief:   EXTI driver for Atmega32.
******************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* ==================================================================== */
/* ======================= public data types ========================== */
/* ==================================================================== */

/* External interrupt id data type */
typedef enum{
    EXTI_INT0,
    EXTI_INT1,
    EXTI_INT2,
    EXTI_ERR
} ExtiId_type;

/* Sensing level data type */
typedef enum 
{	
	SENSING_LOW_LEVEL,
	SENSING_FALLING,
	SENSING_RISING,
	SENSING_ON_CHANGE,
    SENSING_ERR
}ExtiSensingLevel_type;

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Enable a specific external interrupt
 * @parameter1----------------> (InterruptId) id of the interrupt to be enabled
 * @parameter2----------------> (SensingLevel) sensing level of the interrupt
 * @return--------------------> None
 * @preconditions-------------> Enable global interrupt and set callback
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void EXTI_enableExternalInterrupt(ExtiId_type InterruptId,ExtiSensingLevel_type SensingLevel);

/**
 * @brief---------------------> Disable a specific external interrupt
 * @parameter1----------------> (InterruptId) id of the interrupt to be disabled
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void EXTI_disableExternalInterrupt(ExtiId_type InterruptId);

/**
 * @brief---------------------> Set callbback of a specific external interrupt
 * @parameter1----------------> (InterruptId) id of the interrupt to be enabled
 * @parameter2----------------> (Callback) callback function of the interrupt
 * @return--------------------> None
 * @preconditions-------------> Enable global interrupt and the in
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void EXTI_setCallback(ExtiId_type InterruptId,void (*Callback)(void));

/**
 * @brief---------------------> Enable global interrupt
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant 
 */
void enableGlobalInterrupt(void);

/**
 * @brief---------------------> Disable global interrupt
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant 
 */
void disableGlobalInterrupt(void);


#endif

