/*****************************************************************************
* @file:    LED_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2  
* @date:    Sat, 09 Sep 2023 13:04:37 +0300
* @brief:   Led Driver.
******************************************************************************/
#ifndef _LED_INTERFACE_H
#define _LED_INTERFACE_H

/* ==================================================================== */
/* ======================= Public Data Types ========================== */
/* ==================================================================== */

/* Led data type */
typedef enum
{   LED_RED=0,
    LED_GREEN,
    LED_BLUE,
    LED_YELLOW,
    MAX_LED
} Led_type;

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */


/**
 * @brief---------------------> Initialize led module 
 * @return--------------------> none
 * @preconditions-------------> none
 * @postconditions------------> none
 * @synchronous/asynchronous--> synchronous
 * @reentrant/non-reentrant---> reentrant 
 */
void LED_init(void);

/**
 * @brief---------------------> Turn on led
 * @parameter1----------------> (LedId) led id
 * @return--------------------> none
 * @preconditions-------------> led module is initialized
 * @postconditions------------> none
 * @synchronous/asynchronous--> synchronous
 * @reentrant/non-reentrant---> reentrant
 */
void LED_turnOn(Led_type LedId);

/**
 * @brief---------------------> Turn of led
 * @parameter1----------------> (LedId) led id
 * @return--------------------> none
 * @preconditions-------------> led module is initialized
 * @postconditions------------> none
 * @synchronous/asynchronous--> synchronous
 * @reentrant/non-reentrant---> reentrant
 */
void LED_turnOff(Led_type LedId);


/**
 * @brief---------------------> toggle led state
 * @parameter1----------------> (LedId) led id
 * @return--------------------> none
 * @preconditions-------------> led module is initialized
 * @postconditions------------> none
 * @synchronous/asynchronous--> synchronous
 * @reentrant/non-reentrant---> reentrant
 */
void LED_toggle(Led_type LedId);

#endif

