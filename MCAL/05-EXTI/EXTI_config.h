/*****************************************************************************
* @file:    EXTI_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sat, 16 Sep 2023 06:48:06 +0300
* @brief:   EXTI driver for Atmega32.
******************************************************************************/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/***************** EXTI pin configurations *********************/
#define INT0_PORT GPIOD
#define INT0_PIN  PIN2

#define INT1_PORT GPIOD
#define INT1_PIN  PIN3

#define INT2_PORT GPIOB
#define INT2_PIN  PIN2




#endif

