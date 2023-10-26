/*****************************************************************************
* @file:    PB_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed. 
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sat, 09 Sep 2023 13:05:05 +0300
* @brief:   Push Button Driver.
******************************************************************************/
#ifndef _PB_INTERFACE_H
#define _PB_INTERFACE_H

/* ==================================================================== */
/* ======================= Public Data Types ========================== */
/* ==================================================================== */

/* Push Button date type */
typedef enum
{
	BUTTON1=0,
	BUTTON2,
	BUTTON3,
	BUTTON4,
	MAX_BUTTON
}ButtonId_type;

/* Push Button Status date type */
typedef enum
{
	PRESSED,
	RELEASED
}ButtonStatus_type;

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize push button module 
 * @return--------------------> none
 * @preconditions-------------> none
 * @postconditions------------> none
 * @synchronous/asynchronous--> synchronous
 * @reentrant/non-reentrant---> reentrant 
 */
void PB_init(void);

/**
 * @brief---------------------> Get push button status
 * @parameter1----------------> (ButtonId) push button id
 * @return--------------------> push button status
 * @preconditions-------------> push button module is initialized
 * @postconditions------------> none
 * @synchronous/asynchronous--> synchronous
 * @reentrant/non-reentrant---> reentrant
 */
ButtonStatus_type PB_getStatus(ButtonId_type ButtonId);




#endif

