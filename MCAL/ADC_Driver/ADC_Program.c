/*
 * ADC_Program.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Kimo Store
 */

#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "ADC_Config.h"

#include "../../MCAL/GPIO_Driver/GPIO_Interface.h"

u16 ADC_Value;

ISR(ADC_Conv_Complete_VECT)
{

	ADC_Value = ADC;
	SET_BIT(ADCSRA , ADSC);  // Start Conversion
}


void ADC_voidInit()
{

	//GPIO_void_Set_Direction_PIN(GPIOA , Copy_u16Channel , INPUT);

	/* This Setting for Single Ended Input ADC  (Just 8 Channels)   No  Differential Input */


	ADMUX = (1<<REFS0);
	ADCSRA = (1<<ADEN)|(1<<ADPS1)|(1<<ADPS2) ;

	//CLEAR_BIT(ADMUX , ADLAR); // ADCL is Low & ADCH is High
}

void ADC_voidEnableInterrupt(u8 Copy_u16Channel)
{

	sei();
	SET_BIT(ADCSRA , ADIE);
	Copy_u16Channel &= 0x07;
	ADMUX = ADMUX & 0xE0;
	   // To prevent user Enter any value greater than 7
	SET_BIT(ADCSRA , ADSC);  // Start Conversion

}

u16 ADC_u16Read(u8 Copy_u8Channel )
{
	/* SW Filter 0----7 */
	Copy_u8Channel &= 0x07;

	ADMUX &=0xE0;

	ADMUX |=Copy_u8Channel;
	/* Start Conversion */
	ADCSRA |=(1<<ADSC);
	//Waiting End of conv. Flag
	while(  (ADCSRA &(1<<ADSC) )  );

	// Get The Result
	return ADC;
}

void ADC_voidCallBack( u16*ptr)
{
	*ptr = ADC_Value;
}


