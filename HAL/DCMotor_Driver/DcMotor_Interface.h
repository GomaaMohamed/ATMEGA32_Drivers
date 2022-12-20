/*
 * DcMotor_Interface.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Kimo Store
 */

#ifndef HAL_DCMOTOR_DRIVER_DCMOTOR_INTERFACE_H_
#define HAL_DCMOTOR_DRIVER_DCMOTOR_INTERFACE_H_

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../MCAL/GPIO_Driver/GPIO_Interface.h"
#include "../../MCAL/Timer_Driver/Timer_interface.h"


void DcMotor_voidInit();

void DcMotor_voidRightToLeft();

void DcMotor_voidLeftToRight();

void DcMotor_voidSetSpeed(u16 Copy_u16MotorSpeed);

#endif /* HAL_DCMOTOR_DRIVER_DCMOTOR_INTERFACE_H_ */
