/*****************************************************************************
* @file:    LCD_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2  
* @date:    Thu, 07 Sep 2023 19:09:10 +0300
* @brief:   LCD Driver.
******************************************************************************/
#ifndef _LCD_PRIVATE_H
#define _LCD_PRIVATE_H

/* ==================================================================== */
/* =================== Private Variables and Macros =================== */
/* ==================================================================== */

/* LCD Type Options */
#define LCD_16X2 0
#define LCD_20X4 1

/* LCD Mode Options */
#define M_4BIT_SAMEPORT  0
#define M_4BIT_SEPARATED 1
#define M_8BIT           2

/* Private variables */
static u8 CurrentCursorPosition = 0;

/* ==================================================================== */
/* ==================== Private Functions Declaration ================= */
/* ==================================================================== */

static void LCD_writeCommand(u8 Command);
static void LCD_writeData(u8 Data);


#endif

