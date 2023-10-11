/*****************************************************************************
* @file:    EXTI_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sat, 16 Sep 2023 06:48:06 +0300
* @brief:   EXTI driver for Atmega32.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to enable an external interrupt
void EXTI_enableExternalInterrupt(ExtiId_type InterruptId,ExtiSensingLevel_type SensingLevel)
{
    // Validate input parameters
    ASSERT(InterruptId >= 0 && InterruptId < EXTI_ERR);
    ASSERT(SensingLevel >= 0 && SensingLevel < SENSING_ERR);

    // Select Exti Id then set its sensing level
    switch (InterruptId)
    {
	case EXTI_INT0:
        GPIO_setPinDirection(INT0_PORT, INT0_PIN, INPUT);
        SET_BIT(GICR, INT0);
        switch(SensingLevel)
	    {
	    case SENSING_LOW_LEVEL:
	    	CLR_BIT(MCUCR ,ISC00);
	    	CLR_BIT(MCUCR ,ISC01);
	    	break;
	    case SENSING_FALLING:
	    	CLR_BIT(MCUCR ,ISC00);
	    	SET_BIT(MCUCR ,ISC01);
	    	break;
	    case SENSING_RISING:
	    	SET_BIT(MCUCR ,ISC00);
	    	SET_BIT(MCUCR ,ISC01);
	    	break;
	    case SENSING_ON_CHANGE:
	    	SET_BIT(MCUCR ,ISC00);
	    	CLR_BIT(MCUCR ,ISC01);
	    	break;
	    default:
	    	// Do nothing
	    	break;
	    }
	    break;
	case EXTI_INT1:
    GPIO_setPinDirection(INT1_PORT, INT1_PIN, INPUT);
	    SET_BIT(GICR , INT1);
	    switch(SensingLevel)
	    {
	    case SENSING_LOW_LEVEL:
	    	CLR_BIT(MCUCR ,ISC10);
	    	CLR_BIT(MCUCR ,ISC11);
	    	break;
	    case SENSING_FALLING:
	    	CLR_BIT(MCUCR ,ISC10);
	    	SET_BIT(MCUCR ,ISC11);
	    	break;
	    case SENSING_RISING:
	    	SET_BIT(MCUCR ,ISC10);
	    	SET_BIT(MCUCR ,ISC11);
	    	break;
	    case SENSING_ON_CHANGE:
	    	SET_BIT(MCUCR ,ISC10);
	    	CLR_BIT(MCUCR ,ISC11);
	    	break;
	    default:
	    	// Do nothing
	    	break;
	    }
	    break;
	case EXTI_INT2:
        GPIO_setPinDirection(INT2_PORT, INT2_PIN, INPUT);
	    SET_BIT(GICR , INT2);
	    switch(SensingLevel)
	    {
	    case SENSING_FALLING:
	    	CLR_BIT(MCUCSR ,ISC2);
	    	break;
	    case SENSING_RISING:
	    	SET_BIT(MCUCSR ,ISC2);
	    	break;
	    default:
	    	// Do nothing
	    	break;
	    }
	    break;
	    default:
	    	// Donothing
	    break;
	    }
}

// Function to disable an external interrupt
void EXTI_disableExternalInterrupt(ExtiId_type InterruptId)
{
    // Validate input parameters
    ASSERT(InterruptId >= 0 && InterruptId < EXTI_ERR);

    // Select Exti Id then disable it
	switch(InterruptId)
	{
	case EXTI_INT0:
		CLR_BIT(GICR , INT0);
		break;
	case EXTI_INT1:
		CLR_BIT(GICR , INT1);
		break;
	case EXTI_INT2:
		CLR_BIT(GICR , INT2);
		break;
	default:
		// Do nothing
		break;
	}
}

// Function to set callback of external interrupts
void EXTI_setCallback(ExtiId_type InterruptId,void (*Callback)(void))
{
    // Validate input parameters
    ASSERT(InterruptId >= 0 && InterruptId < EXTI_ERR);
    ASSERT(Callback != NULL);

    // Select Exti Id then set its callback
    switch (InterruptId)
    {
    case EXTI_INT0:
        INT0_Callback = Callback;
        break;
    case EXTI_INT1:
        INT1_Callback = Callback;
        break;
    case EXTI_INT2:
        INT2_Callback = Callback;
        break;
    default:
        // Do nothing
        break;
    }
}

void enableGlobalInterrupt(void)
{
    asm("sei");
}
void disableGlobalInterrupt(void)
{
    asm("cli");
}

/* ==================================================================== */
/* ================ Private Functions Implementation ================== */
/* ==================================================================== */

/* ISRs */
ISR(INT0_vect){
    if (INT0_Callback != NULL)
    {
        INT0_Callback();
    }
}

ISR(INT1_vect){
    if (INT1_Callback != NULL)
    {
        INT1_Callback();
    }
}

ISR(INT2_vect){
    if (INT2_Callback != NULL)
    {
        INT2_Callback();
    }
}






