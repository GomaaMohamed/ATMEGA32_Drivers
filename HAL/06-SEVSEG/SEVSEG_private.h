/*****************************************************************************
* @file:    SEVSEG_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.  
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2  
* @date:    Wed, 13 Sep 2023 12:48:20 +0300
* @brief:   Seven Segments Driver with multiplixer.
******************************************************************************/
#ifndef _SEVSEG_PRIVATE_H
#define _SEVSEG_PRIVATE_H

/* ==================================================================== */
/* =================== Private Variables and Macros =================== */
/* ==================================================================== */

static u8 BcdDigits[4];


/* ==================================================================== */
/* ==================== Private Functions Declaration ================= */
/* ==================================================================== */

static void SEVSEG_convertDecimalToBCD(u32 DecimalNumber);
static void SEVSEG_writeDigit(u8 Digit);
#endif

