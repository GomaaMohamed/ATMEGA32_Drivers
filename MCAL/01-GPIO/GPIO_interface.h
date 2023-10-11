/*****************************************************************************
* @file:    GPIO_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed Gomaa.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Fri, 8 Sep 2023 18:21:12 +0200
* @brief:   GPIO Driver for Atmega32
******************************************************************************/
#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

/* ==================================================================== */
/* ======================= public data types ========================== */
/* ==================================================================== */

/* Port data type */
typedef enum
{
	GPIOA=0,
	GPIOB, 
	GPIOC,
	GPIOD,
	MAX_PORT
}Port_type;

/* Pin data type */
typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	MAX_PIN
}Pin_type;

/* Mode data type */
typedef enum
{
	INPUT = 0,
	OUTPUT,
	MAX_MODE
}Mode_type;

/* State data type */
typedef enum
{
	LOW=0,
	HIGH,
	MAX_STATE
}PinState_type;

/* ==================================================================== */
/* ==================== public function prototypes ==================== */
/* ==================================================================== */

/**
 * @brief---------------------> Set pin direction [INPUT/OUTPUT]
 * @parameter1----------------> (Port) port that contains the pin
 * @parameter2----------------> (Pin) pin to set its direction
 * @parameter3----------------> (Mode) direction of the pin
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant              
 */
void GPIO_setPinDirection(Port_type Port , Pin_type Pin , Mode_type Mode);

/**
 * @brief---------------------> Set pin value [HIGH/LOW]
 * @parameter1----------------> (Port) port that contains the pin
 * @parameter2----------------> (Pin) pin to set its value
 * @parameter3----------------> (PinState) state of the pin [HIGT/LOW]
 * @return--------------------> None
 * @preconditions-------------> Pin direction must be set
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant
 */
void GPIO_setPinValue(Port_type Port , Pin_type Pin , PinState_type PinState);

/**
 * @brief---------------------> Toggle the state of the pin
 * @parameter1----------------> (Port) port that contains the pin
 * @parameter2----------------> (Pin) pin to toggle its state
 * @return--------------------> None
 * @preconditions-------------> Pin direction must be set
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void GPIO_togglePin(Port_type Port , Pin_type Pin);

/**
 * @brief---------------------> Get the state of the pin
 * @parameter1----------------> (Port) port that contains the pin
 * @parameter2----------------> (Pin) pin to be get its state
 * @return--------------------> None
 * @preconditions-------------> Pin direction must be set
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant       
 */
void GPIO_enablePullup(Port_type Port, Pin_type Pin);

/**
 * @brief---------------------> Get the state of the pin
 * @parameter1----------------> (Port) port that contains the pin
 * @parameter2----------------> (Pin) pin to be get its state
 * @return--------------------> State of the pin [HIGH/LOW]
 * @preconditions-------------> Pin direction must be set
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant         
 */
PinState_type GPIO_getPinValue(Port_type Port , Pin_type Pin);

/**
 * @brief---------------------> Set port mask direction [INPUT/OUTPUT]
 * @parameter1----------------> (Port) port to set its direction
 * @parameter2----------------> (Mask) mask to set its direction
 * @parameter3----------------> (Mode) Direction of the port mask
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant              
 */
void GPIO_setPortMaskDirection(Port_type Port ,u8 Mask, Mode_type Mode);

/**
 * @brief---------------------> Set port mask direction [INPUT/OUTPUT]
 * @parameter1----------------> (Port) port to set its mask value
 * @parameter2----------------> (Mask) mask to set its value
 * @parameter3----------------> (State) state of port mask
 * @return--------------------> None
 * @preconditions-------------> Port mask direction must be setted
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant        
 */
void GPIO_setPortMaskValue(Port_type Port, u8 Mask, PinState_type State);

/**
 * @brief---------------------> Set port mask Pullup
 * @parameter1----------------> (Port) port to set its mask Pullup
 * @parameter2----------------> (Mask) mask to set its Pullup
 * @return--------------------> None
 * @preconditions-------------> Port mask direction must be set to INPUT Mode
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant           
 */
void GPIO_enablePortMaskPullup(Port_type Port, u8 Mask);

#endif
