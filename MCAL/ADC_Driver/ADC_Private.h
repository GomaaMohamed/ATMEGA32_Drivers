/*
 * ADC_Private.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_ADC_DRIVER_ADC_PRIVATE_H_
#define MCAL_ADC_DRIVER_ADC_PRIVATE_H_

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"

#define OFFSET_ADDRESS 0x20

#define NULL ((void*) 0)

#define ISR(vector, ...)            \
		void vector (void) __attribute__ ((signal)) __VA_ARGS__; \
		void vector (void)

#define ADC_Conv_Complete_VECT __vector_16

#define ADMUX _MMIO_BYTE(OFFSET_ADDRESS + 0x07)
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADCSRA _MMIO_BYTE(OFFSET_ADDRESS + 0x06)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 7

#define ADC _MMIO_WORD(OFFSET_ADDRESS + 0x04)

#define ADCH _MMIO_BYTE(OFFSET_ADDRESS + 0x05)
#define ADCL _MMIO_BYTE(OFFSET_ADDRESS + 0x04)

#define SFIOR _MMIO_BYTE(OFFSET_ADDRESS + 0x30)
#define ADTS2 7
#define ADTS1 6
#define ADTS0 5





#endif /* MCAL_ADC_DRIVER_ADC_PRIVATE_H_ */
