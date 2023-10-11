/*****************************************************************************
* @file:    BUZZER_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2  
* @date:    Sat, 09 Sep 2023 21:50:19 +0300
* @brief:   Buzzer Driver..
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "BUZZER_interface.h"
#include "BUZZER_private.h"
#include "BUZZER_config.h"


/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize buzzer module
void BUZZER_init(void){
    GPIO_setPinDirection(BUZZER_PORT,BUZZER_PIN,OUTPUT);
}

// Function to turn buzzer on
void BUZZER_turnOn(void){
    GPIO_setPinValue(BUZZER_PORT,BUZZER_PIN,HIGH);
}

// Function to turn buzzer off
void BUZZER_turnOff(void){
    GPIO_setPinValue(BUZZER_PORT,BUZZER_PIN,LOW);
}


// Function to toggle buzzer state
void BUZZER_toggle(void){
    GPIO_togglePin(BUZZER_PORT,BUZZER_PIN);
}





