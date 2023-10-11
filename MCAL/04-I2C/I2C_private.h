/*****************************************************************************
* @file:    I2C_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 19 Sep 2023 18:11:03 +0300
* @brief:   I2C Driver for Atmega32.
******************************************************************************/
#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

/* ==================================================================== */
/* =================== Private Variables and Macros =================== */
/* ==================================================================== */

/******** I2C Registers ************/
#define OFFSET_ADDRESS 0x20

#define TWBR   *((volatile u8*)(OFFSET_ADDRESS + 0x00))
#define TWCR   *((volatile u8*)(OFFSET_ADDRESS + 0x36))
#define TWSR   *((volatile u8*)(OFFSET_ADDRESS + 0x01))
#define TWDR   *((volatile u8*)(OFFSET_ADDRESS + 0x03))
#define TWAR   *((volatile u8*)(OFFSET_ADDRESS + 0x02))

/* TWBR bits */
#define TWBR0 0
#define TWBR1 1
#define TWBR2 2
#define TWBR3 3
#define TWBR4 4
#define TWBR5 5
#define TWBR6 6
#define TWBR7 7

/* TWCR bits */
#define TWINT 7
#define TWEA 6
#define TWSTA 5
#define TWSTO 4
#define TWWC 3
#define TWEN 2
#define TWIE 0

/* TWSR bits */
#define TWS7 7
#define TWS6 6
#define TWS5 5
#define TWS4 4
#define TWS3 3
#define TWPS1 1
#define TWPS0 0

/* TWDR bits */
#define TWD0 0
#define TWD1 1
#define TWD2 2
#define TWD3 3
#define TWD4 4
#define TWD5 5
#define TWD6 6
#define TWD7 7

/* TWAR bits */
#define TWGCE 0
#define TWA0 1
#define TWA1 2
#define TWA2 3
#define TWA3 4
#define TWA4 5
#define TWA5 6
#define TWA6 7

/* Private configigurations definition */
#define I2C_PRESCALER_1   1
#define I2C_PRESCALER_4   4
#define I2C_PRESCALER_16  16
#define I2C_PRESCALER_64  64

#define I2C_MASTER 0
#define I2C_SLAVE  1

#define GCA_DISABLED 0
#define GCA_ENABLED  1




#endif

