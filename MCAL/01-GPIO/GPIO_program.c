/*****************************************************************************
* @file:    GPIO_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed Gomaa.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Fri, 8 Sep 2023 18:21:12 +0200
* @brief:   GPIO Driver for Atmega32
******************************************************************************/

/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

/* ==================================================================== */
/* ======================= functions definition ======================= */
/* ==================================================================== */

// Function to set the pin direction 
void GPIO_setPinDirection(Port_type Port , Pin_type Pin , Mode_type Mode)
{
	// Validate input prameters
	ASSERT(((Port>=0)&&(Port<MAX_PORT)));
	ASSERT(((Pin>=0)&&(Pin<MAX_PIN)));
	ASSERT(((Mode>=0)&&(Mode<MAX_MODE)));

	// Select pin mode
	if(Mode == OUTPUT)
	{
		// Select port and pin to set its direction
		switch(Port)
		{
		case GPIOA: 
			SET_BIT(DDRA , Pin);
			break;
		case GPIOB:
			SET_BIT(DDRB , Pin);
			break;
		case GPIOC:
			SET_BIT(DDRC , Pin);
			break;
		case GPIOD:
			SET_BIT(DDRD , Pin);
			break;
		default:
			// Do nothing
			break;
		}
	}
	else if (Mode ==  INPUT)
	{
		switch(Port)
		{
		case GPIOA:
			CLR_BIT(DDRA , Pin);
			break;
		case GPIOB:
			CLR_BIT(DDRB , Pin);
			break;
		case GPIOC:
			CLR_BIT(DDRC , Pin);
			break;
		case GPIOD:
			CLR_BIT(DDRD , Pin);
			break;
		default :
			// Do nothing
			break;
		}

	}
	else
	{
		// Do nothing
	}
}

// Function to set the value
void GPIO_setPinValue(Port_type Port , Pin_type Pin , PinState_type PinState)
{
	// Validate input prameters
	ASSERT(((Port>=0)&&(Port<MAX_PORT)));
	ASSERT(((Pin>=0)&&(Pin<MAX_PIN)));
	ASSERT(((PinState>=0)&&(PinState<MAX_STATE)));
    
	// Select pin state
	if(PinState == HIGH)
	{
		// Select port and pin to set its value
		switch(Port)
		{
		case GPIOA:
			SET_BIT(PORTA , Pin);
			break;
		case GPIOB:
			SET_BIT(PORTB , Pin);
			break;
		case GPIOC:
			SET_BIT(PORTC , Pin);
			break;
		case GPIOD:
			SET_BIT(PORTD , Pin);
			break;
		default:
			// Do nothing
			break;
		}
	}
	else if (PinState == LOW)
	{
		switch(Port)
		{
		case GPIOA:
			CLR_BIT(PORTA , Pin);
			break;
		case GPIOB:
			CLR_BIT(PORTB , Pin);
			break;
		case GPIOC:
			CLR_BIT(PORTC , Pin);
			break;
		case GPIOD:
			CLR_BIT(PORTD , Pin);
			break;
		default:
			// Do nothing
			break;
		}
	}

	else
	{
		// Do nothing
	}
}

// Function to toggle pin state
void GPIO_togglePin(Port_type Port , Pin_type Pin)
{
	// Validate input prameters
	ASSERT((Port >= 0) && (Port < MAX_PORT));
	ASSERT((Pin >= 0)  && (Pin < MAX_PIN));
	 
	// Select port and pin to toggle it
	switch(Port)
	{
	case GPIOA:
	{
		TOG_BIT(PORTA , Pin);
		break;
	}
	case GPIOB:
	{
		TOG_BIT(PORTB , Pin);
		break;
	}
	case GPIOC:
	{
		TOG_BIT(PORTC , Pin);
		break;
	}
	case GPIOD:
	{
		TOG_BIT(PORTD , Pin);
		break;
	}
	default:
		// Do nothing
		break;

	}
}

// Function to get the pin state
PinState_type GPIO_getPinValue(Port_type Port , Pin_type Pin)
{
	// Validate input prameters
	ASSERT((Port >= 0) && (Port < MAX_PORT));
	ASSERT((Pin >= 0)  && (Pin < MAX_PIN));
    
	// Variable to hold pin state
	PinState_type State = LOW;

	// Select port and pin to get its value
	switch(Port)
	{
	case GPIOA:
	{
		if(!GET_BIT(PINA , Pin))
		{
			State =  LOW;
		}
		else
		{
			State = HIGH;
		}
		break;
	}
	case GPIOB:
	{
		if(!GET_BIT(PINB , Pin))
		{
			State = LOW;
		}
		else
		{
			State = HIGH;
		}
		break;
	}
	case GPIOC:
	{
		if(!GET_BIT(PINC , Pin))
		{
			State = LOW;
		}
		else
		{
			State = HIGH;
		}
		break;
	}
	case GPIOD:
	{
		if(!GET_BIT(PIND , Pin))
		{
			State = LOW;
		}
		else
		{
			State = HIGH;
		}
		break;
	}

	}

	return State;
}

// Function to set the port mask direction
void GPIO_setPortMaskDirection(Port_type Port , u8 Mask , Mode_type Mode)
{
	// Validate input prameters
	ASSERT((Port >= GPIOA) && (Port < MAX_PORT));
	ASSERT((Mode >= INPUT) && (Mode < MAX_MODE));

	// Select port and mode to set its mask direction
	switch(Port)
	{
	case GPIOA:
	{
		if(Mode == OUTPUT)
		{
			SET_MASK(DDRA, Mask);
		}
		else if (Mode == INPUT)
		{
			CLR_MASK(DDRA, Mask);
		}
		break;
	}
	case GPIOB:
	{
		if(Mode == OUTPUT)
		{
			SET_MASK(DDRB, Mask);
		}
		else if (Mode == INPUT)
		{
			CLR_MASK(DDRB, Mask);
		}
		break;
	}
	case GPIOC:
	{
		if(Mode == OUTPUT)
		{
			SET_MASK(DDRC, Mask);
		}
		else if (Mode == INPUT)
		{
			CLR_MASK(DDRC, Mask);
		}
		break;
	}
	case GPIOD:
	{
		if(Mode == OUTPUT)
		{
			SET_MASK(DDRD, Mask);
		}
		else if (Mode == INPUT)
		{
			CLR_MASK(DDRD, Mask);
		}
		break;
	}
	default:
		// Do nothing
		break;

	}
}

// Function to set the port mask value
void GPIO_setPortMaskValue(Port_type Port ,u8 Mask ,PinState_type State)
{
	// Validate input prameters
	ASSERT((Port >= GPIOA) && (Port < MAX_PORT));
	ASSERT((State >= LOW) && (State < MAX_STATE));

	// Select port to set its mask value
	switch(Port)
	{
	case GPIOA:
	{
		if(State == HIGH)
		{
			SET_MASK(PORTA, Mask);
		}
		else if (State == LOW)
		{
			CLR_MASK(PORTA, Mask);
		}
		break;
	}
	case GPIOB:
	{
		if(State == HIGH)
		{
			SET_MASK(PORTB, Mask);
		}
		else if (State == LOW)
		{
			CLR_MASK(PORTB, Mask);
		}
		break;
	}
	case GPIOC:
	{
		if(State == HIGH)
		{
			SET_MASK(PORTC, Mask);
		}
		else if (State == LOW)
		{
			CLR_MASK(PORTC, Mask);
		}
		break;
	}
	case GPIOD:
	{
		if(State == HIGH)
		{
			SET_MASK(PORTD, Mask);
		}
		else if (State == LOW)
		{
			CLR_MASK(PORTD, Mask);
		}
		break;
	}
	default:
		// Do nothing
		break;

	}
}

// Function to enable Pullup for a specific pic
void GPIO_enablePullup(Port_type Port, Pin_type Pin){
	// Validate input prameters
	ASSERT((Port >= 0) && (Port < MAX_PORT));
	ASSERT((Pin >= 0)  && (Pin < MAX_PIN));
	 
	// Select port and pin to toggle it
	switch(Port)
	{
	case GPIOA:
	{
		SET_BIT(PORTA , Pin);
		break;
	}
	case GPIOB:
	{
		SET_BIT(PORTB , Pin);
		break;
	}
	case GPIOC:
	{
		SET_BIT(PORTC , Pin);
		break;
	}
	case GPIOD:
	{
		SET_BIT(PORTD , Pin);
		break;
	}
	default:
		// Do nothing
		break;

	}
}

// Function to enable Pullup for a specific port mask
void GPIO_enablePortMaskPullup(Port_type Port, u8 Mask){
	// Validate input prameters
	ASSERT((Port >= 0) && (Port < MAX_PORT));
	 
	// Select port and pin to toggle it
	switch(Port)
	{
	case GPIOA:
	{
		SET_MASK(PORTA , Mask);
		break;
	}
	case GPIOB:
	{
		SET_MASK(PORTA , Mask);
		break;
	}
	case GPIOC:
	{
		SET_MASK(PORTA , Mask);
		break;
	}
	case GPIOD:
	{
		SET_MASK(PORTA , Mask);
		break;
	}
	default:
		// Do nothing
		break;

	}
}


