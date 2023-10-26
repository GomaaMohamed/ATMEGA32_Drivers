/*****************************************************************************
* @file:    BUZZER_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sat, 09 Sep 2023 21:50:19 +0300
* @brief:   Buzzer Driver.
******************************************************************************/
#ifndef _BUZZER_CONFIG_H
#define _BUZZER_CONFIG_H

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/************************** Configurations of Buzzer ******************************/

/* LED_RED_PORT Options: [ GPIOA | GPIOB | GPIOC | GPIOD ] */
#define BUZZER_PORT   GPIOC 

/* LED_RED_PIN Options: [ PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | PIN5 | PIN6 | PIN7 ] */
#define BUZZER_PIN     PIN6


#endif

