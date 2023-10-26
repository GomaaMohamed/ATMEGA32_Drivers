/*****************************************************************************
* @file:    USONIC_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Mon, 25 Sep 2023 15:12:09 +0300
* @brief:   Ultrasonic Sensor Driver.
******************************************************************************/
#ifndef _USONIC_CONFIG_H
#define _USONIC_CONFIG_H

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/* ULTRASONIC_TRIG_PORT Configuration */
#define ULTRASONIC_TRIG_PORT GPIOC
#define ULTRASONIC_TRIG_PIN  PIN0

#define ULTRASONIC_ECHO_PORT GPIOD
#define ULTRASONIC_ECHO_PIN  PIN6

/* Define CPU and Timer Parameters */
#define USONIC_CPU_F         1000000UL
#define USONIC_ICU_PRESCALER 1





#endif

