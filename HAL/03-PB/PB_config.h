/*****************************************************************************
* @file:    PB_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sat, 09 Sep 2023 13:05:05 +0300
* @brief:   Push Button Driver.
******************************************************************************/
#ifndef _PB_CONFIG_H
#define _PB_CONFIG_H

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/***************************** Configurations of PB1 ************************************/

/* PB1_ACTIVATION Options: [ PB_ENABLED | PB_DISABLED ] */
#define PB1_ACTIVATION   PB_ENABLED 

/* PB1_PORT Options: [ GPIOA | GPIOB | GPIOC | GPIOD ] */
#define PB1_PORT    GPIOD 

/* PB1_PIN Options: [ PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | PIN5 | PIN6 | PIN7 ] */
#define PB1_PIN     PIN7

/* PB1_MODE Options: [ PULL_UP | PULL_DOWN ] */
#define PB1_MODE    EXTERNAL_PULL_UP


/********************************* Configurations of PB2 *********************************/

/* PB2_ACTIVATION Options: [ PB_ENABLED | PB_DISABLED ] */
#define PB2_ACTIVATION   PB_ENABLED 

/* PB1_PORT Options: [ GPIOA | GPIOB | GPIOC | GPIOD ] */
#define PB2_PORT    GPIOD 

/* PB1_PIN Options: [ PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | PIN5 | PIN6 | PIN7 ] */
#define PB2_PIN     PIN6

/* PB1_MODE Options: [ INTERNAL_PULL_UP | EXTERNAL_PULL_UP | EXTERNAL_PULL_DOWN ] */
#define PB2_MODE    EXTERNAL_PULL_UP


/******************************* Configurations of PB3 **********************************/

/* PB3_ACTIVATION Options: [ PB_ENABLED | PB_DISABLED ] */
#define PB3_ACTIVATION   PB_ENABLED 

/* PB1_PORT Options: [ GPIOA | GPIOB | GPIOC | GPIOD ] */
#define PB3_PORT    GPIOD 

/* PB1_PIN Options: [ PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | PIN5 | PIN6 | PIN7 ] */
#define PB3_PIN     PIN5

/* PB1_MODE Options: [ PULL_UP | PULL_DOWN ] */
#define PB3_MODE    EXTERNAL_PULL_UP


/******************************** Configurations of PB4 *********************************/

/* PB4_ACTIVATION Options: [ PB_ENABLED | PB_DISABLED ] */
#define PB4_ACTIVATION   PB_DISAABLED 

/* PB1_PORT Options: [ GPIOA | GPIOB | GPIOC | GPIOD ] */
#define PB4_PORT    GPIOD 

/* PB1_PIN Options: [ PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | PIN5 | PIN6 | PIN7 ] */
#define PB4_PIN     PIN3

/* PB1_MODE Options: [ PULL_UP | PULL_DOWN ] */
#define PB4_MODE    EXTERNAL_PULL_UP


#endif

