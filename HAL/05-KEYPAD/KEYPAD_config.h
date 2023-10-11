/*****************************************************************************
* @file:    KEYPAD_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.1   
* @date:    Wed, 13 Sep 2023 17:17:21 +0300
* @brief:   Keypad Driver 4*4.
******************************************************************************/
#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/************* Rows Configurations *************/
/* Rows Mode Configuration [ OUTPUT | INPUT | INPUT_PULL_UP ] */
#define ROW_MODE  OUTPUT

/* Row1 Configurations */
#define ROW1_PORT GPIOC
#define ROW1_PIN  PIN5

/* Row2 Configurations */
#define ROW2_PORT GPIOC
#define ROW2_PIN  PIN4

/* Row3 Configurations */
#define ROW3_PORT GPIOC
#define ROW3_PIN  PIN3

/* Row4 Configurations */
#define ROW4_PORT GPIOC
#define ROW4_PIN  PIN2

/************* Columns Configurations *************/
/* Columns Mode Configuration [ OUTPUT | INPUT | INPUT_PULL_UP ] */
#define COL_MODE  OUTPUT

/* Col1 Configurations */
#define COL1_PORT GPIOD
#define COL1_PIN  PIN7

/* Col2 Configurations */
#define COL2_PORT GPIOD
#define COL2_PIN  PIN6

/* Col3 Configurations */
#define COL3_PORT GPIOD
#define COL3_PIN  PIN5

/* Col4 Configurations */
#define COL4_PORT GPIOD
#define COL4_PIN  PIN3






#endif

