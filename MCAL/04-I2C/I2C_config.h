/************************************************************************
* @file:    I2C_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 19 Sep 2023 18:11:03 +0300
* @brief:   I2C Driver for Atmega32.
*************************************************************************/
#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/****************** I2C pins configuration *******************/
#define I2C_SCL_PORT  GPIOC
#define I2C_SCL_PIN   PIN0

#define I2C_SDA_PORT  GPIOC
#define I2C_SDA_PIN   PIN1

/***************** I2C parameters configuration ***************/

/* I2C_MODE options: [ I2C_MASTER | I2C_SLAVE ] */
#define I2C_MODE  I2C_MASTER

/* Define the Slave Address in case of SLAVE mode */
#if I2C_MODE == I2C_SLAVE
#define I2C_SLAVE_ADDRESS  0x80
#endif

#define I2C_GENARAL_CALL_ADDRESS  GCA_DISABLED

/* I2C_F_CPU options: [ 8000000UL | 16000000UL ] */
#define I2C_F_CPU      16000000UL

/* I2C_PRESCALER options: [ I2C_PRESCALER_1 | I2C_PRESCALER_4 | I2C_PRESCALER_16 | I2C_PRESCALER_64 ] */
#define I2C_PRESCALER  I2C_PRESCALER_1

/* I2C_BIT_RATE options: put value up to 400 KBPS */
#define I2C_BIT_RATE  100000






#endif

