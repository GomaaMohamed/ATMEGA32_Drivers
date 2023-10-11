/*****************************************************************************
* @file:    I2C_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 19 Sep 2023 18:11:03 +0300
* @brief:   I2C Driver for Atmega32.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "GPIO_interface.h"
#include "LCD_interface.h"

#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize i2c module
void I2C_init(void)
{
    // Set address in case of slave mode
    #if   I2C_MODE == I2C_SLAVE
        TWAR |= (I2C_SLAVE_ADDRESS << 1);
    #endif 

    #if I2C_GENARAL_CALL_ADDRESS == GCA_ENABLED
            SET_BIT(TWAR,0);
    #endif

    // Set prescaler
    #if   I2C_PRESCALER == I2C_PRESCALER_1
        CLR_BIT(TWSR, TWPS0);
        CLR_BIT(TWSR, TWPS1);
    #elif I2C_PRESCALER == I2C_PRESCALER_4
        SET_BIT(TWSR, TWPS0);
        CLR_BIT(TWSR, TWPS1);
    #elif I2C_PRESCALER == I2C_PRESCALER_16
        CLR_BIT(TWSR, TWPS0);
        SET_BIT(TWSR, TWPS1);
    #elif I2C_PRESCALER == I2C_PRESCALER_64
        SET_BIT(TWSR, TWPS0);
        SET_BIT(TWSR, TWPS1);
    #endif

    // Set bit rate
    u8 BitRate = ((I2C_F_CPU / I2C_BIT_RATE) - 16) / (2 * I2C_PRESCALER);
    TWBR = (u8)BitRate;

    // Enable I2C and Ack
    TWCR |= (1<<TWEN)|(1<<TWEA);
    TWSR = 0x00;
}

// Function to make a start sequence
StartState_type I2C_Start(u8 Address,ReadWrite_type ReadWrite)
{
    StartState_type ReturnState;
    u8 Status;

    // Enable TWI, generate start condition and clear interrupt flag 
    TWCR |= (1<<TWSTA)|(1<<TWEN)|(1<<TWINT); 
    // Wait until TWI finish its current job (start condition) 
	while (GET_BIT(TWCR,TWINT)==0);
    // Read TWI status register with masking lower three bits 			
	Status = TWSR & 0xF8;

    // Check weather start condition transmitted successfully or not? 					
	if (Status != 0x8 )						
	{
        // If not then return 0 to indicate start condition fail 
        ReturnState = START_FAILED;
    }
    else
    {
        // If yes then write SLA+W in TWI data register
        if (ReadWrite == WRITE)
        {
            TWDR = (Address<<1);
            // Enable TWI and clear interrupt flag 		  
	        TWCR |= (1<<TWEN)|(1<<TWINT); 
            // Wait until TWI finish its current job (Write operation) 
	        while (GET_BIT(TWCR,TWINT)==0);  
            // Read TWI status register with masking lower three bits 
	        Status = TWSR & 0xF8;	
            // Check weather SLA+W transmitted & ack received or not? 	  	
	        if (Status == 0x18)			  
	        {
                // If yes indicate ack received i.e. ready to accept data byte
                ReturnState = ADDRESS_ACK;  
            }
            // Check weather SLA+W transmitted & nack received or not? 
            else if (Status == 0x20)
            {
                // If not indicate nack received i.e. device is busy 
                ReturnState = ADDRESS_NOTACK;
            }
            else 
            {
                // Else indicate SLA+W failed 
                ReturnState = ARBITRATION_LOST; 
            }
        }
        else if (ReadWrite == READ)
        {
            TWDR = ((Address<<1)+1);
            // Enable TWI and clear interrupt flag 		  
	        TWCR |= (1<<TWEN)|(1<<TWINT); 
            // Wait until TWI finish its current job (Write operation) 
	        while (GET_BIT(TWCR,TWINT)==0);  
            // Read TWI status register with masking lower three bits 
	        Status = TWSR & 0xF8;	
            // Check weather SLA+W transmitted & ack received or not? 	  	
	        if (Status == 0x40)			  
	        {
                // If yes indicate ack received i.e. ready to accept data byte
                ReturnState = ADDRESS_ACK;  
            }
            // Check weather SLA+W transmitted & nack received or not? 
            else if (Status == 0x48)
            {
                // If not indicate nack received i.e. device is busy 
                ReturnState = ADDRESS_NOTACK;
            }
            else 
            {
                // Else indicate SLA+W failed 
                ReturnState = ARBITRATION_LOST; 
            }
        }   
    }
    // Clear start bit
    CLR_BIT(TWCR,TWSTA);
    return ReturnState;
}

// Function to make a repeated start sequence
StartState_type  I2C_RepeatedStart(u8 Address,ReadWrite_type ReadWrite)
{
    StartState_type ReturnState;
    u8 Status;

    // Enable TWI, generate start condition and clear interrupt flag 
    TWCR |= (1<<TWSTA)|(1<<TWEN)|(1<<TWINT); 
    // Wait until TWI finish its current job (start condition) 
	while (GET_BIT(TWCR,TWINT)==0);
    // Read TWI status register with masking lower three bits 			
	Status = TWSR & 0xF8;

    // Check weather start condition transmitted successfully or not? 					
	if (Status != 0x10 )						
	{
        // If not then return 0 to indicate start condition fail 
        ReturnState = START_FAILED;
    }
    else
    {
        // If yes then write SLA+W in TWI data register
        if (ReadWrite == WRITE)
        {
            TWDR = (Address<<1);
            // Enable TWI and clear interrupt flag 		  
	        TWCR |= (1<<TWEN)|(1<<TWINT); 
            // Wait until TWI finish its current job (Write operation) 
	        while (GET_BIT(TWCR,TWINT)==0);  
            // Read TWI status register with masking lower three bits 
	        Status = TWSR & 0xF8;	
            // Check weather SLA+W transmitted & ack received or not? 	  	
	        if (Status == 0x18)			  
	        {
                // If yes indicate ack received i.e. ready to accept data byte
                ReturnState = ADDRESS_ACK;
                
            }
            // Check weather SLA+W transmitted & nack received or not? 
            else if (Status == 0x20)
            {
                // If not indicate nack received i.e. device is busy 
                ReturnState = ADDRESS_NOTACK;
            }
            else 
            {
                // Else indicate SLA+W failed 
                ReturnState = ARBITRATION_LOST; 
            }
        }
        else if (ReadWrite == READ)
        {
            TWDR = ((Address<<1)+1);
            // Enable TWI and clear interrupt flag 		  
	        TWCR |= (1<<TWEN)|(1<<TWINT); 
            // Wait until TWI finish its current job (Write operation) 
	        while (GET_BIT(TWCR,TWINT)==0);  
            // Read TWI status register with masking lower three bits 
	        Status = TWSR & 0xF8;	
            // Check weather SLA+W transmitted & ack received or not? 	  	
	        if (Status == 0x40)			  
	        {
                // If yes indicate ack received i.e. ready to accept data byte
                ReturnState = ADDRESS_ACK; 
            }
            // Check weather SLA+W transmitted & nack received or not? 
            else if (Status == 0x48)
            {
                // If not indicate nack received i.e. device is busy 
                ReturnState = ADDRESS_NOTACK;
            }
            else 
            {
                // Else indicate SLA+W failed 
                ReturnState = ARBITRATION_LOST; 
            }
        }   
    }
    // Clear start bit
    CLR_BIT(TWCR,TWSTA);
    return ReturnState;

}

// Function to make a stop sequence
void I2C_Stop(void)
{
    _delay_us(100);
    // Enable TWI, generate stop condition and clear interrupt flag
    TWCR |= (1<<TWSTO)|(1<<TWINT)|(1<<TWEN);	
    // Wait until stop condition execution 				
	while(GET_BIT(TWCR,TWSTO) == 1);								 
}								

// Function to write data on i2c bus
DataState_type  I2C_Write(u8 Data)
{
    DataState_type ReturnState;
    u8 Status;

    // Copy data in TWI data register 											
	TWDR = Data;
    // Enable TWI and clear interrupt flag 										
	TWCR |= (1<<TWEN)|(1<<TWINT);
    // Wait until TWI finish its current job (Write operation) 							
	while (GET_BIT(TWCR,TWINT)==0);
    // Read TWI status register with masking lower three bits 							
	Status = TWSR & 0xF8;
    // Check weather data transmitted & ack received or not? 									
	if (Status == 0x28)										
	{
        // If yes then return 0 to indicate ack received 
        ReturnState = DATA_ACK;
    }
    // Check weather data transmitted & nack received or not? 												
	else if (Status == 0x30)										
	{
        // If yes then return 1 to indicate nack received 
        ReturnState = DATA_NOTACK;
    }												
	else
    {
        // Else return 2 to indicate data transmission failed 
        ReturnState = DATA_FAILED;
    }
	return ReturnState;                                               
}

// Function to read data on i2c bus and send ack
u8 I2C_ReadAck(void)
{
    CLR_BIT(TWCR,TWSTA);
    // Enable TWI, generation of ack and clear interrupt flag 
    TWCR |=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);	
    // Wait until TWI finish its current job (read operation) 				
	while (GET_BIT(TWCR,TWINT)==0);	
    // Return received data 
    return TWDR;											
}

// Function to read data on i2c bus and send not ack
u8  I2C_ReadNotAck(void)
{
    CLR_BIT(TWCR,TWSTA);
    // Enable TWI and clear interrupt flag 
    CLR_BIT(TWCR, TWEA);
    TWCR|=(1<<TWEN)|(1<<TWINT);	
    // Wait until TWI finish its current job (read operation) 							
	while (GET_BIT(TWCR,TWINT)==0);	
    SET_BIT(TWCR, TWEA);
    // Return received data						
	return TWDR;
}

// Function to read data on i2c bus and send ack at slave mode
u8 I2C_SlaveReadAck(void)
{ 
	TWCR |= (1<< TWINT) | (1<< TWEN) | (1<< TWEA);
	return TWDR;
}

// Function to read data on i2c bus and send not ack at slave mode
u8 I2C_SlaveReadNotAck(void)
{
	TWCR |= (1<< TWINT) | (1<< TWEN);
	return TWDR;
}

// Function to write data on i2c bus at slave mode
void I2C_SlaveWrite(u8 Data)
{
	TWDR = Data;
	TWCR |= (1<< TWINT) | (1<< TWEN);
	while (GET_BIT(TWCR,TWINT)==0);
}







