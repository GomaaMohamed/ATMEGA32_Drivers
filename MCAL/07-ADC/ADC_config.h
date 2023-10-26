/*****************************************************************************
* @file:    ADC_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Mon, 18 Sep 2023 09:29:28 +0300
* @brief:   ADC Driver for Atmega32.
******************************************************************************/
#ifndef _ADC_CONFIG_H
#define _ADC_CONFIG_H

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/******************* ADC pins configuration ****************************/

/* ADC_CHx_EN options: [ ADC_CH_DISABLED | ADC_CH_ENABLED ] */
#define ADC_CH0_EN    ADC_CH_DISABLED
#define ADC_CH0_PORT  GPIOA
#define ADC_CH0_PIN   PIN0

#define ADC_CH1_EN    ADC_CH_ENABLED
#define ADC_CH1_PORT  GPIOA
#define ADC_CH1_PIN   PIN1

#define ADC_CH2_EN    ADC_CH_DISABLED
#define ADC_CH2_PORT  GPIOA
#define ADC_CH2_PIN   PIN2

#define ADC_CH3_EN    ADC_CH_DISABLED
#define ADC_CH3_PORT  GPIOA
#define ADC_CH3_PIN   PIN3

#define ADC_CH4_EN    ADC_CH_DISABLED
#define ADC_CH4_PORT  GPIOA
#define ADC_CH4_PIN   PIN4

#define ADC_CH5_EN    ADC_CH_DISABLED
#define ADC_CH5_PORT  GPIOA
#define ADC_CH5_PIN   PIN5

#define ADC_CH6_EN    ADC_CH_DISABLED
#define ADC_CH6_PORT  GPIOA
#define ADC_CH6_PIN   PIN6

#define ADC_CH7_EN    ADC_CH_DISABLED
#define ADC_CH7_PORT  GPIOA
#define ADC_CH7_PIN   PIN7

/* Single ended and differntial configuration */
/* ADC_DIFFERENTIAL_EN options: [ DIFFERENTIAL_DISABLED | ADIFFERENTIAL_ENABLED ] */
#define ADC_DIFFERENTIAL_EN    DIFFERENTIAL_DISABLED

/* ADC_AUTOTRIGGER_EN options: [ AUTOTRIGGER_DISABLED | AUTOTRIGGER_ENABLED ] */
#define ADC_AUTOTRIGGER_EN    AUTOTRIGGER_DISABLED



#endif

