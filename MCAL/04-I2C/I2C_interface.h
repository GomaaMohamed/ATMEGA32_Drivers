/*****************************************************************************
* @file:    I2C_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 19 Sep 2023 18:11:03 +0300
* @brief:   I2C Driver for Atmega32.
******************************************************************************/
#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

/* ==================================================================== */
/* ======================= Public Data Types ========================== */
/* ==================================================================== */

/* Start state data type */
typedef enum
{
    START_FAILED=0,
    ADDRESS_ACK,
    ADDRESS_NOTACK,
    ARBITRATION_LOST,
} StartState_type;

/* Data state data type */
typedef enum
{
    DATA_FAILED=0,
    DATA_ACK,
    DATA_NOTACK,
} DataState_type;

/* Read write data type */
typedef enum
{
    WRITE,
    READ
} ReadWrite_type;


/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize i2c module
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void I2C_init(void);

/**
 * @brief---------------------> Make a start condition
 * @parameter1----------------> (Address) slave address
 * @parameter2----------------> (ReadWrite) select read or write operation
 * @return--------------------> State of start sequence and slave address ack
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
StartState_type I2C_Start(u8 Address,ReadWrite_type ReadWrite);	

/**
 * @brief---------------------> Make a repeated start condition
 * @parameter1----------------> (Address) slave address
 * @parameter2----------------> (ReadWrite) select read or write operation
 * @return--------------------> State of start sequence and slave address ack
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
StartState_type I2C_RepeatedStart(u8 Address,ReadWrite_type ReadWrite);	

/**
 * @brief---------------------> Write data on i2c bus
 * @parameter1----------------> (Data) data to be sent 
 * @return--------------------> State of write ack or not
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant             
 */		
DataState_type  I2C_Write(u8 Data);

/**
 * @brief---------------------> Read data through i2c bus and send ack
 * @param---------------------> None
 * @return--------------------> Data
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */		
u8 I2C_ReadAck(void);

/**
 * @brief---------------------> Read data through i2c bus and send not ack
 * @param---------------------> None
 * @return--------------------> Data
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */	
u8  I2C_ReadNotAck(void);

/**
 * @brief---------------------> Make a sop condition
 * @param---------------------> None
 * @return--------------------> State of start sequence and slave address ack
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void   I2C_Stop(void);

/**
 * @brief---------------------> Read data through i2c bus and send ack at a slave mode
 * @param---------------------> None
 * @return--------------------> Data
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */	
u8 I2C_SlaveReadAck(void);

/**
 * @brief---------------------> Read data through i2c bus and send not ack at a slave mode
 * @param---------------------> None
 * @return--------------------> Data
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */	
u8 I2C_SlaveReadNotAck(void);

/**
 * @brief---------------------> Send data over i2c bus at a slave mode
 * @parameter1----------------> (Data) data to be sent over i2c bus
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant             
 */	
void I2C_SlaveWrite(u8 Data);


#endif
