/*
 * USART_Config.h
 *
 *  Created on: Oct 18, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_USART_DRIVER_USART_CONFIG_H_
#define MCAL_USART_DRIVER_USART_CONFIG_H_

#include "USART_Interface.h"

/* Options
 *ASynchronousNormal
 *ASynchronousUDoubleSpeed
 *SynchronousMasterMode */
#define USARTMODE	ASynchronousNormal


/* Options For Parity
 No_Parity
 Odd_Parity
 Even_Parity
*/

#define USART_Parity	No_Parity

/* Options for Stop bit
 * 1
 * 2
*/

#define USART_StopBit 1


/* Options For Data Frame Size
	1) 5 Bit
	2) 6 Bit
	3) 7 Bit
	4) 8 Bit
	5) 9 Bit
*/
#define USART_FrameSize 8

#endif /* MCAL_USART_DRIVER_USART_CONFIG_H_ */
