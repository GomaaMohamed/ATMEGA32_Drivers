/*****************************************************************************
* @file:    ADC_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Mon, 18 Sep 2023 09:29:28 +0300
* @brief:   ADC Driver for Atmega32.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize adc module
void ADC_init(AdcConfig_type *Object)
{
    // Initialize ADC pins
    #if ADC_CH0_EN == ADC_CH_ENABLED
        GPIO_setPinDirection(ADC_CH0_PORT, ADC_CH0_PIN, INPUT);
    #endif
    #if ADC_CH1_EN == ADC_CH_ENABLED
        GPIO_setPinDirection(ADC_CH1_PORT, ADC_CH1_PIN, INPUT);
    #endif
    #if ADC_CH2_EN == ADC_CH_ENABLED
        GPIO_setPinDirection(ADC_CH2_PORT, ADC_CH2_PIN, INPUT);
    #endif
    #if ADC_CH3_EN == ADC_CH_ENABLED
        GPIO_setPinDirection(ADC_CH3_PORT, ADC_CH3_PIN, INPUT);
    #endif
    #if ADC_CH4_EN == ADC_CH_ENABLED
        GPIO_setPinDirection(ADC_CH4_PORT, ADC_CH4_PIN, INPUT);
    #endif
    #if ADC_CH5_EN == ADC_CH_ENABLED
        GPIO_setPinDirection(ADC_CH5_PORT, ADC_CH5_PIN, INPUT);
    #endif
    #if ADC_CH6_EN == ADC_CH_ENABLED
        GPIO_setPinDirection(ADC_CH6_PORT, ADC_CH6_PIN, INPUT);
    #endif
    #if ADC_CH7_EN == ADC_CH_ENABLED
        GPIO_setPinDirection(ADC_CH7_PORT, ADC_CH7_PIN, INPUT);
    #endif

    SET_BIT(ADCSRA ,ADEN ); // Enable adc module

	// Select reference voltage 
	if (Object->AdcReferenceVoltage ==ADC_VREF_AREF_PIN)
	{
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
	}
	else if (Object->AdcReferenceVoltage ==ADC_VREF_AVCC_PIN)
	{
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
	}
	else
	{
	   SET_BIT(ADMUX,REFS0);
	   SET_BIT(ADMUX,REFS1);
	}

	// Select adc channel 
	if (Object->AdcChannel == SINGLE_ENDED_CH0_ADC0)
	{
		CLR_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == SINGLE_ENDED_CH1_ADC1)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == SINGLE_ENDED_CH2_ADC2)
	{
		CLR_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == SINGLE_ENDED_CH3_ADC3)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == SINGLE_ENDED_CH4_ADC4)
	{
		CLR_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == SINGLE_ENDED_CH5_ADC5)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == SINGLE_ENDED_CH6_ADC6)
	{
		CLR_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == SINGLE_ENDED_CH7_ADC7)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	#if ADC_DIFFERENTIAL_EN == DIFFERENTIAL_ENABLED
	
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_10X_POSITIVE_ADC1_NEGATIVE_ADC0)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_200X_POSITIVE_ADC1_NEGATIVE_ADC0)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_10X_POSITIVE_ADC3_NEGATIVE_ADC2)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_200X_POSITIVE_ADC3_NEGATIVE_ADC2)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC0_NEGATIVE_ADC1)
	{
		CLR_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC2_NEGATIVE_ADC1)
	{
		CLR_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC3_NEGATIVE_ADC1)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC4_NEGATIVE_ADC1)
	{
		CLR_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC5_NEGATIVE_ADC1)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC6_NEGATIVE_ADC1)
	{
		CLR_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC7_NEGATIVE_ADC1)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC0_NEGATIVE_ADC2)
	{
		CLR_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC1_NEGATIVE_ADC2)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC3_NEGATIVE_ADC2)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
        SET_BIT(ADMUX , MUX4);
	}
    else if (Object->AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC4_NEGATIVE_ADC2)
    {
            CLR_BIT(ADMUX, MUX0);
            CLR_BIT(ADMUX, MUX1);
            SET_BIT(ADMUX, MUX2);
            SET_BIT(ADMUX, MUX3);
            SET_BIT(ADMUX, MUX4);
	}
	else if (Object->AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC5_NEGATIVE_ADC2)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	#endif
	
	// Select prescaler
	if (Object->AdcPrescaler == ADC_PRESCALER_DIV_2)
	{
		SET_BIT(ADCSRA , ADPS0);
		CLR_BIT(ADCSRA , ADPS1);
		CLR_BIT(ADCSRA , ADPS2);
	}
	else if (Object->AdcPrescaler == ADC_PRESCALER_DIV_4)
	{
		CLR_BIT(ADCSRA , ADPS0);
		SET_BIT(ADCSRA , ADPS1);
		CLR_BIT(ADCSRA , ADPS2);
	}
	else if (Object->AdcPrescaler == ADC_PRESCALER_DIV_8)
	{
		SET_BIT(ADCSRA , ADPS0);
		SET_BIT(ADCSRA , ADPS1);
		CLR_BIT(ADCSRA , ADPS2);
	}
	else if (Object->AdcPrescaler == ADC_PRESCALER_DIV_16)
	{
		CLR_BIT(ADCSRA , ADPS0);
		CLR_BIT(ADCSRA , ADPS1);
		SET_BIT(ADCSRA , ADPS2);
	}

	else if (Object->AdcPrescaler == ADC_PRESCALER_DIV_64)
	{
		CLR_BIT(ADCSRA , ADPS0);
		SET_BIT(ADCSRA , ADPS1);
		SET_BIT(ADCSRA , ADPS2);
	}
	else if (Object->AdcPrescaler == ADC_PRESCALER_DIV_128)
	{
		SET_BIT(ADCSRA , ADPS0);
		SET_BIT(ADCSRA , ADPS1);
		SET_BIT(ADCSRA , ADPS2);
	}
	else
	{
		CLR_BIT(ADCSRA , ADPS0);
		CLR_BIT(ADCSRA , ADPS1);
		CLR_BIT(ADCSRA , ADPS2);
	}

	// disable auto trigger
	if (Object->AdcAutotriggerSource == AUTOTRIGGER_DISABLED)
	{
		CLR_BIT(ADCSRA , ADATE);  // disable auto trigger
	}

	// Auto Trigger select
	#if ADC_AUTOTRIGGER_EN == AUTOTRIGGER_ENABLED
	else if (Object->AdcAutotriggerSource == AUTOTRIGGER_FREE_RUNNING)
	{
		
		CLR_BIT(SFIOR , ADTS0);
		CLR_BIT(SFIOR , ADTS1);
		CLR_BIT(SFIOR , ADTS2);
	}
	
	else{	
		
		if (Object->AdcAutotriggerSource == AUTOTRIGGER_ANALOG_COMPARATOR)
		{
			SET_BIT(SFIOR , ADTS0);
		    CLR_BIT(SFIOR , ADTS1);
		    CLR_BIT(SFIOR , ADTS2);
		}
		else if (Object->AdcAutotriggerSource == AUTOTRIGGER_EXTERNAL_INT0 )
		{
			CLR_BIT(SFIOR , ADTS0);
			SET_BIT(SFIOR , ADTS1);
			CLR_BIT(SFIOR , ADTS2);
		}
		else if (Object->AdcAutotriggerSource == AUTOTRIGGER_TIMER_COUNTER0_COMPARE_MATCH)
		{
			SET_BIT(SFIOR , ADTS0);
			SET_BIT(SFIOR , ADTS1);
			CLR_BIT(SFIOR , ADTS2);
		}
		else if (Object->AdcAutotriggerSource == AUTOTRIGGER_TIMER_COUNTER0_OVERFLOW )
		{
			CLR_BIT(SFIOR , ADTS0);
			CLR_BIT(SFIOR , ADTS1);
			SET_BIT(SFIOR , ADTS2);
		}
		else if (Object->AdcAutotriggerSource == AUTOTRIGGER_TIMER_COUNTER_COMPARE_MATCH_B)
		{
			SET_BIT(SFIOR , ADTS0);
			CLR_BIT(SFIOR , ADTS1);
			SET_BIT(SFIOR , ADTS2);
		}
		else if (Object->AdcAutotriggerSource == AUTOTRIGGER_TIMER_COUNTER1_OVERFLOW)
		{
			CLR_BIT(SFIOR , ADTS0);
			SET_BIT(SFIOR , ADTS1);
			SET_BIT(SFIOR , ADTS2);
		}
		else if (Object->AdcAutotriggerSource == AUTOTRIGGER_TIMER_COUNTER1_CAPTURE_EVENT)
		{
			SET_BIT(SFIOR , ADTS0);
			SET_BIT(SFIOR , ADTS1);
			SET_BIT(SFIOR , ADTS2);
		}
	}
	SET_BIT(ADCSRA , ADATE);; // Enable autotrigger
	
	#endif
}

// Function to read from adc 
u16 ADC_read(void)
{
	u16 Data=0;
	ADC_startConversion();              // start conversion
	while(GET_BIT(ADCSRA ,ADIF) == 0);  // wait until conversion completes , flag = 1when conversion completes
	Data=((u8)ADCL)|(((u8)ADCH<<8));
	return Data;
}

// Function to change prescaler
void ADC_changePrescalar(AdcPrescaler_type AdcPrescaler)
{
	// Select prescaler
	if (AdcPrescaler == ADC_PRESCALER_DIV_2)
	{
		SET_BIT(ADCSRA , ADPS0);
		CLR_BIT(ADCSRA , ADPS1);
		CLR_BIT(ADCSRA , ADPS2);
	}
	else if (AdcPrescaler == ADC_PRESCALER_DIV_4)
	{
		CLR_BIT(ADCSRA , ADPS0);
		SET_BIT(ADCSRA , ADPS1);
		CLR_BIT(ADCSRA , ADPS2);
	}
	else if (AdcPrescaler == ADC_PRESCALER_DIV_8)
	{
		SET_BIT(ADCSRA , ADPS0);
		SET_BIT(ADCSRA , ADPS1);
		CLR_BIT(ADCSRA , ADPS2);
	}
	else if (AdcPrescaler == ADC_PRESCALER_DIV_16)
	{
		CLR_BIT(ADCSRA , ADPS0);
		CLR_BIT(ADCSRA , ADPS1);
		SET_BIT(ADCSRA , ADPS2);
	}

	else if (AdcPrescaler == ADC_PRESCALER_DIV_64)
	{
		CLR_BIT(ADCSRA , ADPS0);
		SET_BIT(ADCSRA , ADPS1);
		SET_BIT(ADCSRA , ADPS2);
	}
	else if (AdcPrescaler == ADC_PRESCALER_DIV_128)
	{
		SET_BIT(ADCSRA , ADPS0);
		SET_BIT(ADCSRA , ADPS1);
		SET_BIT(ADCSRA , ADPS2);
	}
	else
	{
		CLR_BIT(ADCSRA , ADPS0);
		CLR_BIT(ADCSRA , ADPS1);
		CLR_BIT(ADCSRA , ADPS2);
	}

}

// Function to switch channel
void ADC_changeChannel(AdcChannel_type AdcChannel)
{
	// Select adc channel 
	if (AdcChannel == SINGLE_ENDED_CH0_ADC0)
	{
		CLR_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == SINGLE_ENDED_CH1_ADC1)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == SINGLE_ENDED_CH2_ADC2)
	{
		CLR_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == SINGLE_ENDED_CH3_ADC3)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == SINGLE_ENDED_CH4_ADC4)
	{
		CLR_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == SINGLE_ENDED_CH5_ADC5)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == SINGLE_ENDED_CH6_ADC6)
	{
		CLR_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == SINGLE_ENDED_CH7_ADC7)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	#if ADC_DIFFERENTIAL_EN == DIFFERENTIAL_ENABLED
	
	else if (AdcChannel == DIFFERENTIAL_GAIN_10X_POSITIVE_ADC1_NEGATIVE_ADC0)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	
	else if (AdcChannel == DIFFERENTIAL_GAIN_200X_POSITIVE_ADC1_NEGATIVE_ADC0)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	
	else if (AdcChannel == DIFFERENTIAL_GAIN_10X_POSITIVE_ADC3_NEGATIVE_ADC2)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	
	else if (AdcChannel == DIFFERENTIAL_GAIN_200X_POSITIVE_ADC3_NEGATIVE_ADC2)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		CLR_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC0_NEGATIVE_ADC1)
	{
		CLR_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	
	else if (AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC2_NEGATIVE_ADC1)
	{
		CLR_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC3_NEGATIVE_ADC1)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC4_NEGATIVE_ADC1)
	{
		CLR_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC5_NEGATIVE_ADC1)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC6_NEGATIVE_ADC1)
	{
		CLR_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC7_NEGATIVE_ADC1)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		CLR_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC0_NEGATIVE_ADC2)
	{
		CLR_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	else if (AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC1_NEGATIVE_ADC2)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	
	else if (AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC3_NEGATIVE_ADC2)
	{
		SET_BIT(ADMUX , MUX0);
		SET_BIT(ADMUX , MUX1);
		CLR_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
        SET_BIT(ADMUX , MUX4);
	}
    else if (AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC4_NEGATIVE_ADC2)
    {
            CLR_BIT(ADMUX, MUX0);
            CLR_BIT(ADMUX, MUX1);
            SET_BIT(ADMUX, MUX2);
            SET_BIT(ADMUX, MUX3);
            SET_BIT(ADMUX, MUX4);
	}
	else if (AdcChannel == DIFFERENTIAL_GAIN_1X_POSITIVE_ADC5_NEGATIVE_ADC2)
	{
		SET_BIT(ADMUX , MUX0);
		CLR_BIT(ADMUX , MUX1);
		SET_BIT(ADMUX , MUX2);
		SET_BIT(ADMUX , MUX3);
		SET_BIT(ADMUX , MUX4);
	}
	#endif
}

// Function to change trigger source
void ADC_changeTriggerSource(AdcAutotriggerSource_type AdcAutotriggerSource)
{
	// Auto Trigger select
	#if ADC_AUTOTRIGGER_EN == AUTOTRIGGER_ENABLED
	else if (AdcAutotriggerSource == AUTOTRIGGER_FREE_RUNNING)
	{
		
		CLR_BIT(SFIOR , ADTS0);
		CLR_BIT(SFIOR , ADTS1);
		CLR_BIT(SFIOR , ADTS2);
	}
	
	else{	
		
		if (AdcAutotriggerSource == AUTOTRIGGER_ANALOG_COMPARATOR)
		{
			SET_BIT(SFIOR , ADTS0);
		    CLR_BIT(SFIOR , ADTS1);
		    CLR_BIT(SFIOR , ADTS2);
		}
		else if (AdcAutotriggerSource == AUTOTRIGGER_EXTERNAL_INT0 )
		{
			CLR_BIT(SFIOR , ADTS0);
			SET_BIT(SFIOR , ADTS1);
			CLR_BIT(SFIOR , ADTS2);
		}
		else if (AdcAutotriggerSource == AUTOTRIGGER_TIMER_COUNTER0_COMPARE_MATCH)
		{
			SET_BIT(SFIOR , ADTS0);
			SET_BIT(SFIOR , ADTS1);
			CLR_BIT(SFIOR , ADTS2);
		}
		else if (AdcAutotriggerSource == AUTOTRIGGER_TIMER_COUNTER0_OVERFLOW )
		{
			CLR_BIT(SFIOR , ADTS0);
			CLR_BIT(SFIOR , ADTS1);
			SET_BIT(SFIOR , ADTS2);
		}
		else if (AdcAutotriggerSource == AUTOTRIGGER_TIMER_COUNTER_COMPARE_MATCH_B)
		{
			SET_BIT(SFIOR , ADTS0);
			CLR_BIT(SFIOR , ADTS1);
			SET_BIT(SFIOR , ADTS2);
		}
		else if (AdcAutotriggerSource == AUTOTRIGGER_TIMER_COUNTER1_OVERFLOW)
		{
			CLR_BIT(SFIOR , ADTS0);
			SET_BIT(SFIOR , ADTS1);
			SET_BIT(SFIOR , ADTS2);
		}
		else if (AdcAutotriggerSource == AUTOTRIGGER_TIMER_COUNTER1_CAPTURE_EVENT)
		{
			SET_BIT(SFIOR , ADTS0);
			SET_BIT(SFIOR , ADTS1);
			SET_BIT(SFIOR , ADTS2);
		}
	}
	SET_BIT(ADCSRA , ADATE);; // Enable autotrigger
	
	#endif
}

// Function to change ref voltage
void ADC_changeReferenceVoltage(AdcReferenceVoltage_type AdcReferenceVoltage)
{
	// Select reference voltage 
	if (AdcReferenceVoltage ==ADC_VREF_AREF_PIN)
	{
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
	}
	else if (AdcReferenceVoltage ==ADC_VREF_AVCC_PIN)
	{
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
	}
	else
	{
	   SET_BIT(ADMUX,REFS0);
	   SET_BIT(ADMUX,REFS1);
	}

}

// Function to enable adc
void ADC_enable(void)
{
	SET_BIT(ADCSRA ,ADEN );
}

// Function to disable adc
void ADC_disable(void)
{
	CLR_BIT(ADCSRA ,ADEN );
}

// Function to start conversion
void ADC_startConversion(void)
{
	SET_BIT(ADCSRA , ADSC);
}




