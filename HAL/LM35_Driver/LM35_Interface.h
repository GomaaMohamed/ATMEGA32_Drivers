/*
 * LM35_Interface.h
 *
 *  Created on: Nov 15, 2022
 *      Author: Kimo Store
 */

#ifndef HAL_LM35_DRIVER_LM35_INTERFACE_H_
#define HAL_LM35_DRIVER_LM35_INTERFACE_H_

#include "../../MCAL/ADC_Driver/ADC_Interface.h"


void LM35_voidInit();
u16 LM35_u16SensorValue(u8 Copy_u8Channel);

#endif /* HAL_LM35_DRIVER_LM35_INTERFACE_H_ */
