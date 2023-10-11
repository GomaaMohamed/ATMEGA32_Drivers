/************************************************************************
* @file:    LED_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2
* @date:    Sat, 09 Sep 2023 13:04:37 +0300
* @brief:   Led Driver.
*************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

#include "GPIO_interface.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize leds
void LED_init(void){

    // Set direcions of the io pins which is related to LedRED
    #if LED_RED_ACTIVATION == LED_ENABLED 
        GPIO_setPinDirection(LED_RED_PORT,LED_RED_PIN,OUTPUT);
    #endif

    #if LED_BLUE_ACTIVATION == LED_ENABLED
        GPIO_setPinDirection(LED_BLUE_PORT,LED_BLUE_PIN,OUTPUT);
    #endif

    #if LED_GREEN_ACTIVATION == LED_ENABLED
        GPIO_setPinDirection(LED_GREEN_PORT,LED_GREEN_PIN,OUTPUT);
    #endif

    #if LED_YELLOW_ACTIVATION == LED_ENABLED
        GPIO_setPinDirection(LED_YELLOW_PORT,LED_YELLOW_PIN,OUTPUT);
    #endif
}

// Function to turn on led
void LED_turnOn(Led_type LedId){
    // Validate input prameters
    ASSERT((LedId>=0)&&(LedId<MAX_LED));

    // Select led id and set its mode
    switch (LedId)
    {
    case LED_BLUE:
        #if LED_BLUE_MODE == LED_SOURCE
        GPIO_setPinValue(LED_BLUE_PORT,LED_BLUE_PIN, HIGH);
        #elif LED_BLUE_MODE == LED_SINK
        GPIO_setPinValue(LED_BLUE_PORT,LED_BLUE_PIN, LOW);
        #endif
        break;

    case LED_RED:
        #if LED_RED_MODE == LED_SOURCE
        GPIO_setPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
        #elif LED_RED_MODE == LED_SINK
        GPIO_setPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
        #endif
        break;

    case LED_GREEN:
        #if LED_GREEN_MODE == LED_SOURCE
        GPIO_setPinValue(LED_GREEN_PORT,LED_GREEN_PIN, HIGH);
        #elif LED_GREEN_MODE == LED_SINK
        GPIO_setPinValue(LED_GREEN_PORT,LED_GREEN_PIN, LOW);
        #endif
        break;

    case LED_YELLOW:
        #if LED_YELLOW_MODE == LED_SOURCE
        GPIO_setPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN, HIGH);
        #elif LED_YELLOW_MODE == LED_SINK
        GPIO_setPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN, LOW);
        #endif
        break;

    default:
        // Do nothing
        break;
    }
}

// Function to turn off led
void LED_turnOff(Led_type LedId){
    // Validate input prameters
    ASSERT((LedId>=0)&&(LedId<MAX_LED));

    // Select led id and set its mode
    switch (LedId)
    {
    case LED_BLUE:
        #if LED_BLUE_MODE == LED_SOURCE
        GPIO_setPinValue(LED_BLUE_PORT,LED_BLUE_PIN, LOW);
        #elif LED_BLUE_MODE == LED_SINK
        GPIO_setPinValue(LED_BLUE_PORT,LED_BLUE_PIN, HIGH);
        #endif
        break;

    case LED_RED:
        #if LED_RED_MODE == LED_SOURCE
        GPIO_setPinValue(LED_RED_PORT,LED_RED_PIN, LOW);
        #elif LED_RED_MODE == LED_SINK
        GPIO_setPinValue(LED_RED_PORT,LED_RED_PIN, HIGH);
        #endif
        break;

    case LED_GREEN:
        #if LED_GREEN_MODE == LED_SOURCE
        GPIO_setPinValue(LED_GREEN_PORT,LED_GREEN_PIN, LOW);
        #elif LED_GREEN_MODE == LED_SINK
        GPIO_setPinValue(LED_GREEN_PORT,LED_GREEN_PIN, HIGH);
        #endif
        break;

    case LED_YELLOW:
        #if LED_YELLOW_MODE == LED_SOURCE
        GPIO_setPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN, LOW);
        #elif LED_YELLOW_MODE == LED_SINK
        GPIO_setPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN, HIGH);
        #endif
        break;

    default:
        // Do nothing
        break;
    }
}

// Function to toggle on led
void LED_toggle(Led_type LedId){
    // Validate input prameters
    ASSERT((LedId>=0)&&(LedId<MAX_LED));

    // Select led id and toggle its state
    switch (LedId)
    {
    case LED_BLUE:
        GPIO_togglePin(LED_BLUE_PORT,LED_BLUE_PIN);
        break;

    case LED_RED:
        GPIO_togglePin(LED_RED_PORT,LED_RED_PIN);
        break;

    case LED_GREEN:
        GPIO_togglePin(LED_GREEN_PORT,LED_GREEN_PIN);
    break;

    case LED_YELLOW:
        GPIO_togglePin(LED_YELLOW_PORT,LED_YELLOW_PIN);
        break;

    default:
        // Do nothing
        break;
    }
}








