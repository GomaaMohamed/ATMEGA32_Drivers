/*
 * SS_Program.h
 *
 *  Created on: Nov 13, 2022
 *      Author: Kimo Store
 */

#include "../../MCAL/GPIO_Driver/GPIO_Interface.h"
#include "SS_Private.h"
#include "SS_Interface.h"
#include "SS_Config.h"


void SS_void_init()
{


	GPIO_void_SET_PORT_DIR(SevenSegment_GPIO , OUTPUT);
}

void SS_void_DisplayNum(u8 Copy_u8Number)
{
#if SevenSegment_Mode == WithoutDecoder

#if SevenSegmentCommon == Anode
	switch(Copy_u8Number)
	{
	case 0:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , ZERO);
		break;
	case 1:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , ONE);
		break;
	case 2:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , TWO);
		break;
	case 3:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , THREE);
		break;
	case 4 :
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , FOUR);
		break;
	case 5:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , FIVE);
		break;
	case 6:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , SIX);
		break;
	case 7:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , SEVEN);
		break;
	case 8 :
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , EIGHT);
		break;
	case 9:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , NINE);
		break;
	default:
		break;
	}
#elif SevenSegmentCommon == Cathode

	switch(Copy_u8Number)
	{
	case 0:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , (u8)~ZERO);
		break;
	case 1:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , (u8)~ONE);
		break;
	case 2:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , (u8)~TWO);
		break;
	case 3:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO ,(u8)~THREE);
		break;
	case 4 :
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , (u8)~FOUR);
		break;
	case 5:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , (u8)~FIVE);
		break;

	case 6:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , (u8)~SIX);
		break;
	case 7:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , (u8)~SEVEN);
		break;
	case 8 :
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , (u8)~EIGHT);
		break;
	case 9:
		GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , (u8)~NINE);
		break;
	default:
		break;
	}
#endif

#elif SevenSegment_Mode == WithDecoder

	GPIO_void_SET_PORT_VALUE(SevenSegment_GPIO , Copy_u8Number);

#endif
}

