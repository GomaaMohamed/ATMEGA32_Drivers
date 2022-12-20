/*
 * DcMotor_Program.c
 *
 *  Created on: Nov 16, 2022
 *      Author: Kimo Store
 */
#include "DcMotor_Private.h"
#include "DcMotor_Interface.h"
#include "DcMotor_Config.h"

void DcMotor_voidInit()
{
	Timer_voidInit(Timer0 , FAST_PWM);
	GPIO_void_Set_Direction_PIN(DcMotor_Port , DcMotor_Pin0 , OUTPUT);
	GPIO_void_Set_Direction_PIN(DcMotor_Port , DcMotor_Pin1 , OUTPUT);

	Timer_voidStart(Timer0 , 0);

}

void DcMotor_voidRightToLeft()
{
	GPIO_void_Set_Value_PIN(DcMotor_Port , DcMotor_Pin0 , HIGH);
	GPIO_void_Set_Value_PIN(DcMotor_Port , DcMotor_Pin1 , LOW);

}

void DcMotor_voidLeftToRight()
{

	GPIO_void_Set_Value_PIN(DcMotor_Port , DcMotor_Pin0 , LOW);
	GPIO_void_Set_Value_PIN(DcMotor_Port , DcMotor_Pin1 , HIGH);

}
void DcMotor_voidSetSpeed(u16 Copy_u16MotorSpeed)
{


	Timer_SetDutyCycle(Timer0 , Copy_u16MotorSpeed);
}
