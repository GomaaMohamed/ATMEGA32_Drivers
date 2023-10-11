/*****************************************************************************
* @file:    SEVSEG_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 13 Sep 2023 12:48:20 +0300
* @brief:   Seven Segments Driver with multiplixer.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "GPIO_interface.h"

#include "SEVSEG_interface.h"
#include "SEVSEG_private.h"
#include "SEVSEG_config.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize sevseg module
void SEVSEG_init(void)
{
    // Initialize decoder input pins
    GPIO_setPinDirection(DECODER_PINA_PORT, DECODER_PINA_PIN, OUTPUT);
    GPIO_setPinDirection(DECODER_PINB_PORT, DECODER_PINB_PIN, OUTPUT);
    GPIO_setPinDirection(DECODER_PINC_PORT, DECODER_PINC_PIN, OUTPUT);
    GPIO_setPinDirection(DECODER_PIND_PORT, DECODER_PIND_PIN, OUTPUT);

    // Initialize seven segments common pins
    GPIO_setPinDirection(COM1_PORT, COM1_PIN, OUTPUT);
    GPIO_setPinDirection(COM2_PORT, COM2_PIN, OUTPUT);
    GPIO_setPinDirection(COM3_PORT, COM3_PIN, OUTPUT);
    GPIO_setPinDirection(COM4_PORT, COM4_PIN, OUTPUT);   
}

// Function to write number
void SEVSEG_writeNumber(u32 Number)
{
    SEVSEG_convertDecimalToBCD(Number);
    
    GPIO_setPinValue(COM1_PORT, COM1_PIN, LOW);
    SEVSEG_writeDigit(0);
    GPIO_setPinValue(COM1_PORT, COM1_PIN, HIGH);

    GPIO_setPinValue(COM2_PORT, COM2_PIN, LOW);
    SEVSEG_writeDigit(1);
    GPIO_setPinValue(COM2_PORT, COM2_PIN, HIGH);

    GPIO_setPinValue(COM3_PORT, COM3_PIN, LOW);
    SEVSEG_writeDigit(2);
    GPIO_setPinValue(COM3_PORT, COM3_PIN, HIGH);

    GPIO_setPinValue(COM4_PORT, COM4_PIN, LOW);
    SEVSEG_writeDigit(3);
    GPIO_setPinValue(COM4_PORT, COM4_PIN, HIGH);
}

/* ==================================================================== */
/* ================ Private Functions Implementation ================== */
/* ==================================================================== */

static void SEVSEG_convertDecimalToBCD(u32 DecimalNumber) 
{
    u32 Remainder;
    u8 i = 0;
    for (i = 0; i < 4; i++)
    {
        BcdDigits[i] = 0;
    }
    i = 0;
    while (DecimalNumber != 0)
    {
        Remainder = DecimalNumber % 10;
        BcdDigits[i] = Remainder;
        DecimalNumber /= 10;
        i++;
    }
}

static void SEVSEG_writeDigit(u8 Digit) 
{
    u8 Bit;
    Bit = GET_BIT(BcdDigits[Digit], 0);
    GPIO_setPinValue(DECODER_PINA_PORT, DECODER_PINA_PIN, Bit);

    Bit = GET_BIT(BcdDigits[Digit], 1);
    GPIO_setPinValue(DECODER_PINB_PORT, DECODER_PINB_PIN, Bit);

    Bit = GET_BIT(BcdDigits[Digit], 2);
    GPIO_setPinValue(DECODER_PINC_PORT, DECODER_PINC_PIN, Bit);

    Bit = GET_BIT(BcdDigits[Digit], 3);
    GPIO_setPinValue(DECODER_PIND_PORT, DECODER_PIND_PIN, Bit);
    _delay_us(500);
}
