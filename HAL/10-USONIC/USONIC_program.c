/*****************************************************************************
* @file:    USONIC_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Mon, 25 Sep 2023 15:12:09 +0300
* @brief:   Ultrasonic Sensor Driver.
******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "GPIO_interface.h"
#include "TIMER_interface.h"

#include "USONIC_interface.h"
#include "USONIC_private.h"
#include "USONIC_config.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize ultrasonic module
void USONIC_init(void)
{
    // Enable timer
    TIMER1_init(TIMER1_NORMAL_MODE, TIMER_SCALER_8, TIMER_OC_DISCONNECTED, TIMER_OC_DISCONNECTED);
    
    // Initialize ultrasonic pins
    GPIO_setPinDirection(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, OUTPUT);
    GPIO_setPinDirection(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN, INPUT);
    
    // Enable Global interrupt
    sei();
    // Set Timer Callback
    TIMER1_setIcuCallBack(UltraSonicCallback);
}

// Function to get distance
UltrasonicDistance_type USONIC_getDistance(u32 *Distance)
{
    UltrasonicDistance_type ReturnState = OUT_OF_RANGE_DISTANCE;

    // Reset Parameters
    TriggerFlag = 0;
    EchoFlag = 0;
    TriggerTimerValue = 0;
    EchoTimerValue = 0;
    
	// Set Edge of the timer
    TIMER1_setInputCaptureEdge(TIMER_ICU_RISING);
    // enable ICU interrupt
    TIMER1_enableIcuInterrupt();
    // Reload Timer
    TIMER1_reloadTimerValue(0);
    // Make a trigger
    makeTrigger();
    // wait until echo received
    _delay_ms(100);

    // Deactivate Timer
    TIMER1_disableIcuInterrupt();
    TIMER1_stopTimer();

    // Get distance
    if ((TriggerFlag == 1) && (EchoFlag == 1))
    {
        u32 Time = (EchoTimerValue - TriggerTimerValue);
        *Distance = (Time/56);
        if (*Distance > 0 && *Distance <= 400)
        {
            ReturnState = VALID_DISTANCE;
        }
    }
    return ReturnState;
}
/* ==================================================================== */
/* ================ Private Functions Implementation ================== */
/* ==================================================================== */

// Function to generate a trigger
static void makeTrigger(void)
{
    GPIO_setPinValue(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, HIGH);
    _delay_us(20);
    GPIO_setPinValue(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, LOW);
}

// Logic as a callback
static void UltraSonicCallback(void)
{
    
    if (TriggerFlag == 0)
    {
        TriggerTimerValue = TIMER1_getIcuValue();
        TIMER1_setInputCaptureEdge(TIMER_ICU_FALLING);
        TriggerFlag = 1;
    }
    else if (EchoFlag == 0)
    {
        EchoTimerValue = TIMER1_getIcuValue();
        TIMER1_setInputCaptureEdge(TIMER_ICU_RISING);
        EchoFlag = 1;
    }
}
