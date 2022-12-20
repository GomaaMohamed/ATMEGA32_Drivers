/*
 * TWI_Program.c
 *
 *  Created on: Oct 27, 2022
 *      Author: Kimo Store
 */

#include "TWI_Interface.h"
#include "TWI_Config.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"

void TWI_voidInit()
{
	TWBR = 0x02;
	TWCR = (1<<TWEN);
	TWSR = 0x00;
}


void TWI_voidStart()
{
	TWCR = (1<< TWINT) | (1<<TWSTA) | (1<< TWEN);
	/*
	SET_BIT(TWCR , TWINT);
	SET_BIT(TWCR , TWSTA);
	SET_BIT(TWCR , TWEN);
	 */
	while(!(TWCR & (1<<TWINT)));
}


void TWI_voidStop()
{
	TWCR = (1<< TWINT) | (1<< TWEN) | (1<<TWSTO);
	/*
	SET_BIT(TWCR , TWINT);
	SET_BIT(TWCR , TWEN);
	SET_BIT(TWCR , TWSTO);
	 */
}
void TWI_voidWriteSlaveAddressR_W(TWI_ReadOrWrite R_W , u8 Copy_u8SlaveAddress)
{

	switch(R_W)
	{
	case Read:


		TWDR = Copy_u8SlaveAddress + 1;

		TWCR = (1<< TWINT) | (1<< TWEN);
		/*
					SET_BIT(TWCR ,TWINT);
					SET_BIT(TWCR , TWEN);
		 */
		while((CHECK_BIT(TWCR, TWINT)) == 0);


		break;



	case Write:

		TWDR = Copy_u8SlaveAddress +0;
		TWCR = (1<< TWINT) | (1<< TWEN);
		/*
						SET_BIT(TWCR ,TWINT);
						SET_BIT(TWCR , TWEN);
		 */
		while((CHECK_BIT(TWCR, TWINT)) == 0);
		break;

	}


}
void TWI_voidWriteData(u8 Copy_u8Char)
{
	TWDR = Copy_u8Char;

	TWCR = (1<< TWINT) | (1<< TWEN);
	/*
		SET_BIT(TWCR ,TWINT);
		SET_BIT(TWCR , TWEN);
	 */
	while(!(TWCR & (1<<TWINT)));
}

u8 TWI_voidRead(u8 Copy_u8ACK)
{

	switch(Copy_u8ACK)
	{
	case 0:

		TWCR = (1<< TWINT) | (1<< TWEN);
		break;


	case 1:

		TWCR = (1<< TWINT) | (1<< TWEN) | (1<< TWEA);
		break;
	}

	/*
		SET_BIT(TWCR ,TWINT);
		SET_BIT(TWCR , TWEN);

	if(Copy_u8ACK == 0)
	{
		TWCR = (1<< TWINT) | (1<< TWEN);
		//CLEAR_BIT(TWCR , TWEA);
	}
	else
	{
		TWCR = (1<< TWINT) | (1<< TWEN) | (1<< TWEA);
		//SET_BIT(TWCR , TWEA);
	}
	 */
	//while(!(TWCR & (1<<TWINT)));

	return TWDR;
}


void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	TWAR = Copy_u8SlaveAddress ;
}

u8 TWI_voidSLaveRead(u8 Copy_u8ACK)
{

	switch(Copy_u8ACK)
	{
	case 0:

		TWCR = (1<< TWINT) | (1<< TWEN);
		break;


	case 1:

		TWCR = (1<< TWINT) | (1<< TWEN) | (1<< TWEA);
		break;
	}
	/*
		SET_BIT(TWCR ,TWINT);
		SET_BIT(TWCR , TWEN);

	if(Copy_u8ACK == 0)
	{
		TWCR = (1<< TWINT) | (1<< TWEN);
		//CLEAR_BIT(TWCR , TWEA);
	}
	else
	{
		TWCR = (1<< TWINT) | (1<< TWEN) | (1<< TWEA);
		//SET_BIT(TWCR , TWEA);
	}
	 */
	//while(!(TWCR & (1<<TWINT)));

	return TWDR;
}

void TWI_voidSlaveWrite(u8 Copy_u8Char)
{
	TWDR = Copy_u8Char;
	TWCR = (1<< TWINT) | (1<< TWEN);
	/*
		SET_BIT(TWCR ,TWINT);
		SET_BIT(TWCR , TWEN);
	 */
	while(!(TWCR & (1<<TWINT)));
}
