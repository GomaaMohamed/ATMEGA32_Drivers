/*****************************************************************************
* @file:    ADC_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2  
* @date:    Mon, 18 Sep 2023 09:29:28 +0300
* @brief:   ADC Driver for Atmega32.
******************************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* ==================================================================== */
/* =================== Private Variables and Macros =================== */
/* ==================================================================== */

/* Offset Address */
#define OFFSET_ADDRESS 0x20

/* ADC Registers */
#define ADMUX    *((volatile u8*)(OFFSET_ADDRESS + 0x07))
#define ADCSRA   *((volatile u8*)(OFFSET_ADDRESS + 0x06))
#define ADC      *((volatile u16*)(OFFSET_ADDRESS + 0x04))
#define ADCH     *((volatile u8*)(OFFSET_ADDRESS + 0x05))
#define ADCL     *((volatile u8*)(OFFSET_ADDRESS + 0x04))
#define SFIOR    *((volatile u8*)(OFFSET_ADDRESS + 0x30))

/* ADMUX bits */
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4
#define ADLAR 5
#define REFS0 6
#define REFS1 7

/* ADCSRA bits */
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 7

/* SFIOR bits */
#define ADTS2 7
#define ADTS1 6
#define ADTS0 5

#define ADC_CH_ENABLED  1
#define ADC_CH_DISABLED 0

#define DIFFERENTIAL_ENABLED  1
#define DIFFERENTIAL_DISABLED 0

#define AUTOTRIGGER_ENABLED  1
#define AUTOTRIGGER_DISABLED 0


#endif

