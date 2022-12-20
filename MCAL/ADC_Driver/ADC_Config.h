/*
 * ADC_Config.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_ADC_DRIVER_ADC_CONFIG_H_
#define MCAL_ADC_DRIVER_ADC_CONFIG_H_

/* Options
 * 1) AREF
 * 2) AVCC
 * 3) AVCC_DIV_2*/
#define ADC_VRef AVCC


/* Options
 * 1) 2
 * 2) 4
 * 3) 8
 * 4) 16
 * 5) 32
 * 6) 64
 * 7) 128
 * */
#define ADC_Prescaler 64

#endif /* MCAL_ADC_DRIVER_ADC_CONFIG_H_ */
