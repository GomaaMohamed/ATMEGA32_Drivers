/*****************************************************************************
* @file:    UART_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Fri, 08 Sep 2023 21:34:43 +0300
* @brief:   UART Driver for Atmega32.
******************************************************************************/
#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

/* ==================================================================== */
/* ======================= Public Data Types ========================== */
/* ==================================================================== */

/* UART received state data type */
typedef enum
{
    UART_DATA_UNRECEIVED=0,
    UART_DATA_RECEIVED,
} UartReceiveState_type;


/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize uart module
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void UART_init(void);

/**
 * @brief---------------------> Send 8-bit data over uart 
 * @parameter1----------------> (Data) data to be sent over uart
 * @return--------------------> None
 * @preconditions-------------> Uart module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant             
 */
void UART_sendCharacter(u8 Character);

/**
 * @brief---------------------> Receive 8-bit data through uart
 * @parameter1----------------> (Character) received data
 * @return--------------------> State of the data [received or not]
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
UartReceiveState_type UART_receiveCharacter(u8 *Character);

/**
 * @brief---------------------> Send a string over uart 
 * @parameter1----------------> (String) string to be sent over uart
 * @return--------------------> None
 * @preconditions-------------> Uart module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant             
 */
void UART_sendString(u8 *String);

/**
 * @brief---------------------> Receive a string through uart 
 * @parameter1----------------> (String) received string 
 * @return--------------------> None
 * @preconditions-------------> Uart module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void UART_receiveString(u8 *String);

/**
 * @brief---------------------> Send a string over uart using interrupt(asynchronous)
 * @parameter1----------------> (String) string to be sent over uart
 * @return--------------------> None
 * @preconditions-------------> Uart module is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void UART_sendStringAsynch(u8 *String);

/**
 * @brief---------------------> Enable rx interrupt
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void UART_enableRxInterrupt(void);


/**
 * @brief---------------------> Disable rx interrupt
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void UART_disableRxInterrupt(void);

/**
 * @brief---------------------> Enable tx interrupt
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void UART_enableTxInterrupt(void);


/**
 * @brief---------------------> Enable tx interrupt
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void UART_disableTxInterrupt(void);

/**
 * @brief---------------------> Set rx call back
 * @parameter1----------------> (Callback) callback function to ba called at interrupt
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void UART_setRxCallBack(void (*Callback)(void));

/**
 * @brief---------------------> Set tx call back
 * @parameter1----------------> (Callback) callback function to ba called at interrupt
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void UART_setTxCallBack(void (*Callback)(void));

#endif

