/*****************************************************************************
* @file:    LM35_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Mon, 18 Sep 2023 18:14:04 +0300
* @brief:   Temprature Sensor(LM35) Driver.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "ADC_interface.h"

#include "LM35_interface.h"
#include "LM35_config.h"
#include "LM35_private.h"


/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize lm35
void LM35_init(void)
{
    ADC_init(&Config);
}

// Function to get temprature
u8 LM35_getTemprature(void)
{
    u16 Val = ADC_read();
    u8 Temp = (Val * 49)/100;
    return Temp;
}
