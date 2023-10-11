/*****************************************************************************
* @file:    SERVO_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sun, 01 Oct 2023 22:24:42 +0300
* @brief:   Servo Motor Driver.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "TIMER_interface.h"

#include "SERVO_interface.h"
#include "SERVO_private.h"
#include "SERVO_config.h"


/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize servo motor
void SERVO_init(void)
{
    TIMER1_init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER_SCALER_64,TIMER_OC_NON_INVERTING,TIMER_OC_DISCONNECTED);
	GPIO_setPinDirection(GPIOD, PIN5, OUTPUT);
}

// Function to set position
void SERVO_setPosition(u8 Degree)
{
    u8 Temp = Degree*3/18;
    TIMER1_generateFastPWM(Temp, 50, 8000000, 64);
}