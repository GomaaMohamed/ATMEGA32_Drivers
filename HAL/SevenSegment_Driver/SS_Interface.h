/*
 * SS_Interface.h
 *
 *  Created on: Nov 13, 2022
 *      Author: Kimo Store
 */

#ifndef HAL_SEVENSEGMENT_DRIVER_SS_INTERFACE_H_
#define HAL_SEVENSEGMENT_DRIVER_SS_INTERFACE_H_

#define WithDecoder 0

#define WithoutDecoder 1

#define Cathode 0

#define Anode 1


void SS_void_init();

void SS_void_DisplayNum(u8 Copy_u8Numbe);



#endif /* HAL_SEVENSEGMENT_DRIVER_SS_INTERFACE_H_ */
