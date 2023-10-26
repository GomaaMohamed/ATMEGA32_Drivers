/*****************************************************************************
* @file:    KEYPAD_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 13 Sep 2023 17:17:21 +0300
* @brief:   Keypad Driver 4*4.
******************************************************************************/
#ifndef _KEYPAD_PRIVATE_H
#define _KEYPAD_PRIVATE_H

/* ==================================================================== */
/* ====================== Private Data Types ========================== */
/* ==================================================================== */

/* Column data type */
typedef enum
{
    COLUMN1,
    COLUMN2,
    COLUMN3,
    COLUMN4,
    COLUMN_ERR
} Column_type;

/* Row data type */
typedef enum
{
    ROW1,
    ROW2,
    ROW3,
    ROW4,
    ROW_ERR
} Row_type;

/* ==================================================================== */
/* =================== Private Variables and Macros =================== */
/* ==================================================================== */
static u8   keypadchars[4][4] = {   {'1','2','3','a'},
		                            {'4','5','6','b'},
		                            {'7','8','9','c'},
		                            {'*','0','#','d'}
                                };


/* ==================================================================== */
/* ==================== Private Functions Declaration ================= */
/* ==================================================================== */

static Column_type KEYPAD_readColumn(void);
static Row_type KEYPAD_readRow(void);

#endif

