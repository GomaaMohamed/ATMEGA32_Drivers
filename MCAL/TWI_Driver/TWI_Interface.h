/*
 * TWI_Interface.h
 *
 *  Created on: Oct 27, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_TWI_DRIVER_TWI_INTERFACE_H_
#define MCAL_TWI_DRIVER_TWI_INTERFACE_H_
#include "TWI_Private.h"

typedef enum
{
	Read,
	Write
}TWI_ReadOrWrite;


/* Master */
void TWI_voidInit();

void TWI_voidStart();

void TWI_voidStop();

void TWI_voidWriteSlaveAddressR_W(TWI_ReadOrWrite R_W , u8 Copy_u8SlaveAddress);

void TWI_voidWriteData(u8 Copy_u8Char);

u8 TWI_voidRead(u8 Copy_u8ACK);


/*  Slave */

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

u8 TWI_voidSLaveRead(u8 Copy_u8ACK);

void TWI_voidSlaveWrite(u8 Copy_u8Char);


#endif /* MCAL_TWI_DRIVER_TWI_INTERFACE_H_ */
