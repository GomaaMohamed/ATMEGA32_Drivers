/*****************************************************************************
* @file:    EXEEPROM_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sat, 23 Sep 2023 12:18:05 +0300
* @brief:   External EEPROM Driver.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "I2C_interface.h"

#include <util/delay.h>

#include "EXEEPROM_interface.h"
#include "EXEEPROM_private.h"
#include "EXEEPROM_config.h"


/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize eeprom
void EXEEPROM_Init()
{
	I2C_init();
}

// Function to write byte at eeprom
EepromState_type EXEEPROM_WriteByte(u16 Addr,u8 data)
{
	u8 PageNo = Addr / 256;
	u8 ByteNo = Addr % 256;
	u8 BlckAddr = (0xA << 3) | PageNo;
    
	StartState_type CheckA = I2C_Start(BlckAddr,WRITE);
	if(CheckA != ADDRESS_ACK){return ERROR;}

	DataState_type CheckD0 = I2C_Write(ByteNo);
	if(CheckD0 != DATA_ACK){return ERROR;}

	DataState_type CheckD1 = I2C_Write(data);
	if(CheckD1 != DATA_ACK){return ERROR;}
		
	I2C_Stop();
	return SUCCESS;	
}

// Function to read byte from eeprom
EepromState_type EXEEPROM_ReadByte(u16 Addr,u8 *data)
{
	u8 PageNo = Addr / 256;
	u8 ByteNo = Addr % 256;
	u8 BlckAddr = (0x0A << 3) | PageNo;
	
	StartState_type CheckA0 = I2C_Start(BlckAddr,WRITE);
	if(CheckA0 != ADDRESS_ACK){
		return ERROR;}
	
	DataState_type CheckD0 = I2C_Write(ByteNo);
	if(CheckD0 != DATA_ACK){
		return ERROR;}
	
	StartState_type CheckA1 = I2C_RepeatedStart(BlckAddr,READ);
	if(CheckA1 != ADDRESS_ACK){
		return ERROR;}
	
	*data = I2C_ReadNotAck();
	I2C_Stop();

	return SUCCESS;	
}






