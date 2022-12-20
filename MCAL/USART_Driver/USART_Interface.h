/*
 * USART_Interface.h
 *
 *  Created on: Oct 18, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_USART_DRIVER_USART_INTERFACE_H_
#define MCAL_USART_DRIVER_USART_INTERFACE_H_

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "USART_Private.h"


typedef enum
{
	USART_OK,
	USART_ERROR
}USART_State;

#define ASynchronousNormal 0
#define ASynchronousUDoubleSpeed 1
#define SynchronousMasterMode 2


void USART_voidReceiveCharacterInterrupt(u8 *Copy_u8Data);

void USART_voidInit(u32 Copy_u8BaudRate);
void USART_voidInitInterrupt();
void USART_voidSendCharacterPolling(u8 Copy_u8Char);
void USART_voidSendStringPolling(u8 *Copy_u8String);
u8 USART_voidReceiveCharacterPolling();
void USART_voidReceiveStringPolling(u8 *Copy_u8String);






#endif /* MCAL_USART_DRIVER_USART_INTERFACE_H_ */
