/*
 * Keypad_Interface.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Kimo Store
 */

#ifndef HAL_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"
#include "../../MCAL/GPIO_Driver/GPIO_Interface.h"
#include "../Button_Driver/Btn_interface.h"
#include <util/delay.h>

void Keypad_voidInit();

u8 Keypad_voidGetPressedKey();

#endif /* HAL_KEYPAD_DRIVER_KEYPAD_INTERFACE_H_ */
