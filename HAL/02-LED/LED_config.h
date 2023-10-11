/*****************************************************************************
* @file:    LED_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2  
* @date:    Sat, 09 Sep 2023 13:04:37 +0300
* @brief:   Led Driver.
******************************************************************************/
#ifndef LED_CONFIG_H
#define LED_CONFIG_H

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/************************** Configurations of Red Led ******************************/

/* LED_RED_ACTIVATION Options: [ LED_ENABLED | LED_DISABLED ] */
#define LED_RED_ACTIVATION   LED_DISABLED 

/* LED_RED_PORT Options: [ GPIOA | GPIOB | GPIOC | GPIOD ] */
#define LED_RED_PORT   GPIOB 

/* LED_RED_PIN Options: [ PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | PIN5 | PIN6 | PIN7 ] */
#define LED_RED_PIN     PIN7

/* LED_RED_MODE Options: [ LED_SOURCE | LED_SINK ] */
#define LED_RED_MODE    LED_SOURCE


/************************** Configurations of BLUE Led ******************************/

/* LED_BLUE_ACTIVATION Options: [ LED_ENABLED | LED_DISABLED ] */
#define LED_BLUE_ACTIVATION   LED_DISABLED  

/* LED_BLUE_PORT Options: [ GPIOA | GPIOB | GPIOC | GPIOD ] */
#define LED_BLUE_PORT   GPIOA 

/* LED_BLUE_PIN Options: [ PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | PIN5 | PIN6 | PIN7 ] */
#define LED_BLUE_PIN     PIN5

/* LED_BLUE_MODE Options: [ LED_SOURCE | LED_SINK ] */
#define LED_BLUE_MODE    LED_SOURCE


/************************** Configurations of Green Led ******************************/

/* LED_GREEN_ACTIVATION Options: [ LED_ENABLED | LED_DISABLED ] */
#define LED_GREEN_ACTIVATION   LED_ENABLED  

/* LED_GREEN_PORT Options: [ GPIOA | GPIOB | GPIOC | GPIOD ] */
#define LED_GREEN_PORT   GPIOA 

/* LED_GREEN_PIN Options: [ PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | PIN5 | PIN6 | PIN7 ] */
#define LED_GREEN_PIN     PIN4

/* LED_GREEN_MODE Options: [ LED_SOURCE | LED_SINK ] */
#define LED_GREEN_MODE    LED_SOURCE


/************************** Configurations of Yellow Led ******************************/

/* LED_YELLOW_ACTIVATION Options: [ LED_ENABLED | LED_DISABLED ] */
#define LED_YELLOW_ACTIVATION   LED_DISABLED 

/* LED_YELLOW_PORT Options: [ GPIOA | GPIOB | GPIOC | GPIOD ] */
#define LED_YELLOW_PORT   GPIOA 

/* LED_YELLOW_PIN Options: [ PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | PIN5 | PIN6 | PIN7 ] */
#define LED_YELLOW_PIN     PIN6

/* LED_YELLOW_MODE Options: [ LED_SOURCE | LED_SINK ] */
#define LED_YELLOW_MODE    LED_SOURCE

#endif

