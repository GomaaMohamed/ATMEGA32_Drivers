/*
 * LM35_Program.c
 *
 *  Created on: Nov 15, 2022
 *      Author: Kimo Store
 */

#include "LM35_Private.h"
#include "LM35_Interface.h"
#include "LM35_Config.h"


void LM35_voidInit()
{

	ADC_voidInit();

}


u16 LM35_u16SensorValue(u8 Copy_u8Channel)
{


	u16 Read = 0;

	Read = ADC_u16Read(Copy_u8Channel);

	return Read;

}
