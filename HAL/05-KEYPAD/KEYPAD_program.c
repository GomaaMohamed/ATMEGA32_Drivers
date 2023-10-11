/************************************************************************
* @file:    KEYPAD_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 13 Sep 2023 17:17:21 +0300
* @brief:   Keypad Driver 4*4.
*************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "util/delay.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize keypad module
void KEYPAD_init(void){
    // Initialize rows as output
    GPIO_setPinDirection(ROW1_PORT, ROW1_PIN, OUTPUT);
    GPIO_setPinDirection(ROW2_PORT, ROW2_PIN, OUTPUT);
    GPIO_setPinDirection(ROW3_PORT, ROW3_PIN, OUTPUT);
    GPIO_setPinDirection(ROW4_PORT, ROW4_PIN, OUTPUT);
    // Initialize Cols as input pushpull
    GPIO_setPinDirection(COL1_PORT, COL1_PIN, INPUT);
    GPIO_setPinDirection(COL2_PORT, COL2_PIN, INPUT);
    GPIO_setPinDirection(COL3_PORT, COL3_PIN, INPUT);
    GPIO_setPinDirection(COL4_PORT, COL4_PIN, INPUT);
}

// Function to scan keypad
u8 KEYPAD_scanKeypad(void){
    _delay_ms(150);
    Column_type Column = KEYPAD_readColumn();
    Row_type Row = KEYPAD_readRow();
    if (Column < COLUMN_ERR )
    {
        return keypadchars[Row][Column];
    }
    else{
        return 0xFF;
    }
}

/* ==================================================================== */
/* ================ Private Functions Implementation ================== */
/* ==================================================================== */

// Function to read column
static Column_type KEYPAD_readColumn(void){
    // Variable to hold column
    Column_type PressedColumn;

    // Make all rows high
    GPIO_setPinValue(ROW1_PORT,ROW1_PIN,LOW);
    GPIO_setPinValue(ROW2_PORT,ROW2_PIN,LOW);
    GPIO_setPinValue(ROW3_PORT,ROW3_PIN,LOW);
    GPIO_setPinValue(ROW4_PORT,ROW4_PIN,LOW);

    // Read all column
    if (GPIO_getPinValue(COL1_PORT,COL1_PIN)==LOW){
        PressedColumn = COLUMN1;
    }
    else if(GPIO_getPinValue(COL2_PORT,COL2_PIN)==LOW)
    {
        PressedColumn = COLUMN2;
    }
    else if(GPIO_getPinValue(COL3_PORT,COL3_PIN)==LOW)
    {
        PressedColumn = COLUMN3;
    }
    else if(GPIO_getPinValue(COL4_PORT,COL4_PIN)==LOW)
    {
        PressedColumn = COLUMN4;
    }
    else
    {
        PressedColumn = COLUMN_ERR;
    }
    return PressedColumn;
}

// Function to read row
static Row_type KEYPAD_readRow(void){
    // Variable to hold column
    Row_type PressedRow;

    Row_type Row = KEYPAD_readColumn();

    // Make all rows high except row1
    GPIO_setPinValue(ROW1_PORT,ROW1_PIN,LOW);
    GPIO_setPinValue(ROW2_PORT,ROW2_PIN,HIGH);
    GPIO_setPinValue(ROW3_PORT,ROW3_PIN,HIGH);
    GPIO_setPinValue(ROW4_PORT,ROW4_PIN,HIGH);

    // Read all column
    if (GPIO_getPinValue(COL1_PORT,COL1_PIN)==LOW){
        PressedRow = ROW1;
    }
    else if(GPIO_getPinValue(COL2_PORT,COL2_PIN)==LOW)
    {
        PressedRow = ROW1;
    }
    else if(GPIO_getPinValue(COL3_PORT,COL3_PIN)==LOW)
    {
        PressedRow = ROW1;
    }
    else if(GPIO_getPinValue(COL4_PORT,COL4_PIN)==LOW)
    {
        PressedRow = ROW1;
    }

    // Make all rows high except row1
    GPIO_setPinValue(ROW1_PORT,ROW1_PIN,HIGH);
    GPIO_setPinValue(ROW2_PORT,ROW2_PIN,LOW);

    // Read all column
    if (GPIO_getPinValue(COL1_PORT,COL1_PIN)==LOW){
        PressedRow = ROW2;
    }
    else if(GPIO_getPinValue(COL2_PORT,COL2_PIN)==LOW)
    {
        PressedRow = ROW2;
    }
    else if(GPIO_getPinValue(COL3_PORT,COL3_PIN)==LOW)
    {
        PressedRow = ROW2;
    }
    else if(GPIO_getPinValue(COL4_PORT,COL4_PIN)==LOW)
    {
        PressedRow = ROW2;
    }

    // Make all rows high except row1
    GPIO_setPinValue(ROW2_PORT,ROW2_PIN,HIGH);
    GPIO_setPinValue(ROW3_PORT,ROW3_PIN,LOW);

    // Read all column
    if (GPIO_getPinValue(COL1_PORT,COL1_PIN)==LOW){
        PressedRow = ROW3;
    }
    else if(GPIO_getPinValue(COL2_PORT,COL2_PIN)==LOW)
    {
        PressedRow = ROW3;
    }
    else if(GPIO_getPinValue(COL3_PORT,COL3_PIN)==LOW)
    {
        PressedRow = ROW3;
    }
    else if(GPIO_getPinValue(COL4_PORT,COL4_PIN)==LOW)
    {
        PressedRow = ROW3;
    }

    // Make all rows high except row1
    GPIO_setPinValue(ROW3_PORT,ROW3_PIN,HIGH);
    GPIO_setPinValue(ROW4_PORT,ROW4_PIN,LOW);

    // Read all column
    if (GPIO_getPinValue(COL1_PORT,COL1_PIN)==LOW){
        PressedRow = ROW4;
    }
    else if(GPIO_getPinValue(COL2_PORT,COL2_PIN)==LOW)
    {
        PressedRow = ROW4;
    }
    else if(GPIO_getPinValue(COL3_PORT,COL3_PIN)==LOW)
    {
        PressedRow = ROW4;
    }
    else if(GPIO_getPinValue(COL4_PORT,COL4_PIN)==LOW)
    {
        PressedRow = ROW4;
    }
    
    return PressedRow;
}






