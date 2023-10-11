/*****************************************************************************
* @file:    LM35_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Mon, 18 Sep 2023 18:14:04 +0300
* @brief:   Temprature Sensor(LM35) Driver.
******************************************************************************/
#ifndef LM35_PRIVATE_H
#define LM35_PRIVATE_H

/* ==================================================================== */
/* =================== Private Variables and Macros =================== */
/* ==================================================================== */

static AdcConfig_type Config = {ADC_VREF_AVCC_PIN,
						        LM35_CHANNEL,
						        ADC_PRESCALER_DIV_128,
						        AUTOTRIGGER_DISABLED};





#endif

