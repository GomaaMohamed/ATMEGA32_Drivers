/*****************************************************************************
* @file:    SPI_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sat, 16 Sep 2023 11:01:07 +0300
* @brief:   SPI Driver for Atmega32.
******************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/* ==================================================================== */
/* ======================= Public Data Types ========================== */
/* ==================================================================== */

/* Spi receive data state */
typedef enum
{
    SPI_DATA_UNRECEIVED = 0,
    SPI_DATA_RECEIVED
} SpiReceiveState_type;

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize spi module
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void SPI_init(void);

/**
 * @brief---------------------> Send 8-bit data over spi at master mode
 * @parameter1----------------> (Data) data to be sent over spi
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant            
 */
void SPI_sendDataMaster(u8 Data);

/**
 * @brief---------------------> Send string over spi at master mode
 * @parameter1----------------> (String) string to be sent over spi
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant            
 */
void SPI_sendStringMaster(u8 *String);

/**
 * @brief---------------------> Receive 8-bit data through spi at master mode
 * @param---------------------> None
 * @return--------------------> Received data
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
u8 SPI_receiveDataMaster(void);

/**
 * @brief---------------------> Send 8-bit data over spi at slave mode
 * @parameter1----------------> (Data) data to be sent over spi
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant            
 */
void SPI_sendDataSlave(u8 Data);

/**
 * @brief---------------------> Receive 8-bit data polling through spi at slave mode
 * @param---------------------> None
 * @return--------------------> Received data
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
u8 SPI_receiveDataPollingSlave(void);

/**
 * @brief---------------------> Receive 8-bit data polling through spi at slave mode
 * @parameter1----------------> (Data) Received data
 * @return--------------------> Receive data state [data received or not]
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
SpiReceiveState_type SPI_receiveDataSlave(u8 *Data);

#endif

