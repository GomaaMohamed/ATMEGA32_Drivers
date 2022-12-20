/*
 * ADC_Interface.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_ADC_DRIVER_ADC_INTERFACE_H_
#define MCAL_ADC_DRIVER_ADC_INTERFACE_H_

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"


#define AREF 0
#define AVCC 1
#define AVCC_DIV_2 2

void ADC_voidInit();

u16 ADC_u16Read(u8 Copy_u8Channel );

void ADC_voidEnableInterrupt(u8 Copy_u16Channel);

void ADC_voidCallBack( u16*ptr);




#endif /* MCAL_ADC_DRIVER_ADC_INTERFACE_H_ */
