/*****************************************************************************
* @file:    TIMER_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 06 Sep 2023 10:51:56 +0300
* @brief:   Timer Driver for Atmega32.
******************************************************************************/

/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

/* ==================================================================== */
/* ================= Public functions Implementation ================== */
/* ==================================================================== */

/********************** Timer0 public functions implementation *********************/

// Function to initialize timer0
void TIMER0_init(TimerMode_type TimerMode,
				 TimerPrescaler_type TimerPrescaler,
				 TimerOcMode_type TimerOcMode)
{
    // Validate inputs
    ASSERT((TimerMode >= TIMER_NORMAL_MODE && TimerMode < TIMER_MAX_MODE));
    ASSERT((TimerPrescaler >= TIMER_STOP && TimerMode < TIMER_MAX_SCALER));
    ASSERT((TimerOcMode >= TIMER_OC_DISCONNECTED && TimerOcMode < TIMER_MAX_OC));

    // Set timer0 mode
    switch (TimerMode)
    {
    case TIMER_NORMAL_MODE:
        CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
        break;
    case TIMER_PHASECORRECT_MODE:
        SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
        break;
    case TIMER_CTC_MODE:
        CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
        break;
    case TIMER_FASTPWM_MODE:
        SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
        break;
    default:
        // Do nothing
        break;
    }

    // Select mode of OC Pin
    switch (TimerOcMode)
	{
		case TIMER_OC_DISCONNECTED:
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
			break;
		case TIMER_OC_TOGGLE:
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
			break;
		case TIMER_OC_NON_INVERTING:
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break;
		case TIMER_OC_INVERTING:
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break;
    	default:
        	// Do nothing
        	break;
	}
	// Set timer0 prescaler to start timer
    TCCR0&=0xF8;
	TCCR0|=TimerPrescaler;
    Timer0Scaler=TimerPrescaler;
}

// Function to reload timer value
void TIMER0_reloadTimerValue(u8 TimerValue)
{
	// Stop timer
	CLR_MASK(TCCR0,TIM_STOP);
	// Load timer
    TCNT0=TimerValue;
	// Start timer
	TCCR0&=0XF8;
	TCCR0|=Timer1Scaler;
}

// Function to reload output compare value
void TIMER0_reloadCompareValue(u8 CompareValue)
{
    OCR0 = CompareValue;
}

// Function to get current timer value
u8 TIMER0_getCurrentTimerValue(void){
    return TCNT0;
}

// Function to stop timer
void TIMER0_stopTimer(void)
{
    SET_MASK(TCCR0,TIM_STOP);
}

// Function to restart timer
void TIMER0_restartTimer(void)
{

    TCCR0|=Timer0Scaler;
}

// Function to enable overflow interrupt
void TIMER0_enableOverflowInterrupt(void)
{
    SET_BIT(TIMSK,TOIE0);
}

// Function to disable overflow interrupt
void TIMER0_disableOverflowInterrupt(void)
{
    CLR_BIT(TIMSK,TOIE0);
}

// Function to enable output compare interrupt
void TIMER0_enableOutputCompareInterrupt(void)
{
    SET_BIT(TIMSK,OCIE0);
}

// Function to disable output compare interrupt
void TIMER0_disableOutputCompareInterrupt(void)
{
    CLR_BIT(TIMSK,OCIE0);
}

// Function to set overflow callback
void TIMER0_setOverflowCallBack(void(*Callback)(void))
{
    TIMER0_OVF_CallBack = Callback;
}

// Function to set output compare callback
void TIMER0_setCompareCallBack(void(*Callback)(void))
{
    TIMER0_CMP_CallBack = Callback;
}

// Function to generate pwm
void TIMER0_generatePWM(u8 DutyCycle)
{
	u8 Temp = 255*(DutyCycle/100);
	OCR0 = Temp;
}
/********************** Timer1 public functions implementation *********************/
void TIMER1_init( Timer1Mode_type TimerMode,
                  TimerPrescaler_type TimerPrescaler,
                  TimerOcMode_type TimerOcMode1A,
                  TimerOcMode_type TimerOcMode1B)
{
    // Validate inputs
    ASSERT((TimerMode >= TIMER1_NORMAL_MODE && TimerMode < TIMER1_MAX_MODE));
    ASSERT((TimerPrescaler >= TIMER_STOP && TimerMode < TIMER_MAX_SCALER));
    ASSERT((TimerOcMode1A >= TIMER_OC_DISCONNECTED && TimerOcMode1A < TIMER_MAX_OC));
    ASSERT((TimerOcMode1B >= TIMER_OC_DISCONNECTED && TimerOcMode1B < TIMER_MAX_OC));

    // Set timer mode
    switch (TimerMode)
	{
		case TIMER1_NORMAL_MODE:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
		    break;
		case TIMER1_CTC_ICR_TOP_MODE:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
		    break;
		case TIMER1_CTC_OCRA_TOP_MODE:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_FASTPWM_ICR_TOP_MODE:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
       		break;
		case TIMER1_PCPWM_ICR_TOP_MODE:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_PCPWM_OCRA_TOP_MODE:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
       		break;
		case TIMER1_PCFCPWM_ICR_TOP_MODE:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_PCFCPWM_OCRA_TOP_MODE:
			SET_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
        	break;
        default:
        	// Do nothing
        	break;
    }
    
    // Select mode of OC PinA
    switch (TimerOcMode1A)
	{
		case TIMER_OC_DISCONNECTED:
			CLR_BIT(TCCR1A,COM1A0);
			CLR_BIT(TCCR1A,COM1A1);
			break;
		case TIMER_OC_TOGGLE:
			SET_BIT(TCCR1A,COM1A0);
			CLR_BIT(TCCR1A,COM1A1);
			break;
		case TIMER_OC_NON_INVERTING:
			CLR_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break;
		case TIMER_OC_INVERTING:
			SET_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break;
	    default:
        	// Do nothing
        	break;
    }

    // Select mode of OC PinB
	switch (TimerOcMode1B)
	{
		case TIMER_OC_DISCONNECTED:
			CLR_BIT(TCCR1A,COM1B0);
			CLR_BIT(TCCR1A,COM1B1);
			break;
		case TIMER_OC_TOGGLE:
			SET_BIT(TCCR1A,COM1B0);
			CLR_BIT(TCCR1A,COM1B1);
			break;
		case TIMER_OC_NON_INVERTING:
			CLR_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
			break;
		case TIMER_OC_INVERTING:
			SET_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
			break;
        default:
        	// Do nothing
        	break;
	}

    // Set timer1 prescaler to start timer
    TCCR1B&=0xF8;
	TCCR1B|=TimerPrescaler;
    Timer1Scaler=TimerPrescaler;

}

// Function to reload timer value
void TIMER1_reloadTimerValue(u16 TimerValue)
{
	// Stop timer
	CLR_MASK(TCCR1B,TIM_STOP);
	// Load timer
    TCNT1=TimerValue;
	// Start timer
	TCCR1B&=0XF8;
	TCCR1B|=Timer1Scaler;
}

// Function to reload output compare value
void TIMER1_reloadCompareValueA(u16 CompareValue)
{
	// Load output compare
    OCR1A=CompareValue;
}

// Function to reload output compare value
void TIMER1_reloadCompareValueB(u16 CompareValue)
{
	// Load output compare
	OCR1B=CompareValue;
}// Function to reload ICU value

void TIMER1_reloadIcuValue(u16 IcuValue)
{
	// Load output input capture
    ICR1=IcuValue;
}

// Function to get ICU value
u16 TIMER1_getIcuValue(void)
{
    return ICR1;
}

// Function to set ICU edge
void TIMER1_setInputCaptureEdge(TimerIcuEdge_type TimerIcueEdge)
{
    if(TimerIcueEdge == TIMER_ICU_RISING){
		SET_BIT(TCCR1B,ICES1);
    }
	else if(TimerIcueEdge == TIMER_ICU_FALLING){
		CLR_BIT(TCCR1B,ICES1);
    }
}

// Function to get current timer value
u16  TIMER1_getCurrentTimerValue(void)
{
    return TCNT1;
}

// Function to stop timer
void TIMER1_stopTimer(void)
{
    CLR_MASK(TCCR1B,TIM_STOP);
}

// Function to restart timer
void TIMER1_restartTimer(void)
{
    TCCR1B|=Timer1Scaler;
}

// Function to enable icu interrupt
void TIMER1_enableIcuInterrupt(void)
{
    SET_BIT(TIMSK,TICIE1);
}

// Function to disable icu interrupt
void TIMER1_disableIcuInterrupt(void)
{
    CLR_BIT(TIMSK,TICIE1);
}

// Function to enable overflow interrupt
void TIMER1_enableOverflowInterrupt(void)
{
    SET_BIT(TIMSK,TOIE1);
}

// Function to disable overflow interrupt
void TIMER1_disableOverflowInterrupt(void)
{
    CLR_BIT(TIMSK,TOIE1);
}

// Function to enable output compare interrupt
void TIMER1_enableOutputCompareAInterrupt(void)
{
    SET_BIT(TIMSK,OCIE1A);
}

// Function to disable output compare interrupt
void TIMER1_disableOutputCompareAInterrupt(void)
{
    CLR_BIT(TIMSK,OCIE1A);
}

// Function to enable output compare interrupt
void TIMER1_enableOutputCompareBInterrupt(void)
{
    SET_BIT(TIMSK,OCIE1B);
}

// Function to disable output compare interrupt
void TIMER1_disableOutputCompareBInterrupt(void)
{
    CLR_BIT(TIMSK,OCIE1B);
}

// Function to set overflow callback
void TIMER1_setOverflowCallBack(void(*Callback)(void))
{
    TIMER1_OVF_CallBack = Callback;
}

// Function to set output compare callback
void TIMER1_setCompareACallBack(void(*Callback)(void))
{
    TIMER1_CMPA_CallBack = Callback;
}

// Function to set output comoare callback
void TIMER1_setCompareBCallBack(void(*Callback)(void))
{
    TIMER1_CMPB_CallBack = Callback;
}

// Function to set icu callback
void TIMER1_setIcuCallBack(void(*Callback)(void))
{
    TIMER1_ICU_CallBack = Callback;
}

// Function to generate pwm
void TIMER1_generateFastPWM(u8 DutyCycle,u32 Frequency,u32 Clock,u16 Prescaler)
{
	u16 Temp1 = (Clock/(Prescaler*Frequency))+1;
	u16 Temp2 = (((Temp1+1)/ 100)*DutyCycle)+1;
	ICR1 = Temp1;
	OCR1A = Temp2;
}

// Function to generate pwm
void TIMER1_generatePhaseCorrectPWM(u8 DutyCycle,u32 Frequency,u32 Clock,u16 Prescaler)
{
	u16 Temp1 = Clock/(2*Prescaler*Frequency);
	u16 Temp2 = (Temp1/ 100)*DutyCycle;
	ICR1 = Temp1;
	OCR1A = Temp2;
}

/* ==================================================================== */
/* ================ private functions Implementation ================== */
/* ==================================================================== */

ISR(TIMER0_OVF_vect)
{
	if(TIMER0_OVF_CallBack!=NULL)
	{
		TIMER0_OVF_CallBack();
	}
}
ISR(TIMER0_COMP_vect)
{
	if(TIMER0_CMP_CallBack!=NULL)
	{
		TIMER0_CMP_CallBack();
	}
}
ISR(TIMER1_OVF_vect)
{
	if(TIMER1_OVF_CallBack!=NULL)
	{
		TIMER1_OVF_CallBack();
	}
}
ISR(TIMER1_COMPA_vect)
{
	if(TIMER1_CMPA_CallBack!=NULL)
	{
		TIMER1_CMPA_CallBack();
	}
}
ISR(TIMER1_COMPB_vect)
{
	if(TIMER1_CMPB_CallBack!=NULL)
	{
		TIMER1_CMPB_CallBack();
	}
}
ISR(TIMER1_CAPT_vect)
{
	if(TIMER1_ICU_CallBack!=NULL)
	{
		TIMER1_ICU_CallBack();
	}
}





