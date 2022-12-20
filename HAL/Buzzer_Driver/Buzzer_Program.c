/*
 * Buzzer_Program.c
 *
 *  Created on: Nov 15, 2022
 *      Author: Kimo Store
 */

#include "Buzzer_Private.h"
#include "Buzzer_Interface.h"
#include "Buzzer_Config.h"

void Buzzer_voidInit()
{

	GPIO_void_Set_Direction_PIN(Buzzer_PORT , Buzzer_PIN , OUTPUT);
	GPIO_void_Set_Value_PIN(Buzzer_PORT , Buzzer_PIN , LOW);

}

void Buzzer_voidON()
{

	GPIO_void_Set_Value_PIN(Buzzer_PORT , Buzzer_PIN , HIGH);

}

void Buzzer_voidOFF()
{

	GPIO_void_Set_Value_PIN(Buzzer_PORT , Buzzer_PIN , LOW);
}
