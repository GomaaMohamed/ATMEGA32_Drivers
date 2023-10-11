/*****************************************************************************
* @file:    PB_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sat, 09 Sep 2023 13:05:05 +0300
* @brief:   Push Button Driver..
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "GPIO_interface.h"

#include "PB_interface.h"
#include "PB_private.h"
#include "PB_config.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize push buttons
void PB_init(void){
    
    // Set PB1 Configurations
    #if PB1_ACTIVATION == PB_ENABLED
        // Set IO pins to be Input
        GPIO_setPinDirection(PB1_PORT,PB1_PIN,INPUT);
        // Set pins of PB1 in case of internal pull up
        #if PB1_MODE == INTERNAL_PULL_UP
        GPIO_setPinValue(PB1_PORT,PB1_PIN,HIGH);
        #endif
    #endif

    #if PB2_ACTIVATION == PB_ENABLED
        GPIO_setPinDirection(PB2_PORT,PB2_PIN,INPUT);
        #if PB2_MODE == INTERNAL_PULL_UP
        GPIO_setPinValue(PB2_PORT,PB2_PIN,HIGH);
        #endif
    #endif

    #if PB3_ACTIVATION == PB_ENABLED
        GPIO_setPinDirection(PB3_PORT,PB3_PIN,INPUT);
        #if PB3_MODE == INTERNAL_PULL_UP
        GPIO_setPinValue(PB3_PORT,PB3_PIN,HIGH);
        #endif
    #endif

    #if PB4_ACTIVATION == PB_ENABLED
        GPIO_setPinDirection(PB4_PORT,PB4_PIN,INPUT);
        #if PB4_MODE == INTERNAL_PULL_UP
        GPIO_setPinValue(PB4_PORT,PB4_PIN,HIGH);
        #endif
    #endif
}

// Fucnction to get the status of any push button
ButtonStatus_type PB_getStatus(ButtonId_type ButtonId){
    // Validate input prameters
    ASSERT((ButtonId>=0)&&(ButtonId<MAX_BUTTON));

    ButtonStatus_type PushButtonStatus; // Variable to hold Push Button State
    PinState_type PinState;             // Variable to hold Pin State
    switch (ButtonId)
    {
    case BUTTON1:
        // Read IO pin which is realated to the PB1
        PinState = GPIO_getPinValue(PB1_PORT,PB1_PIN);
        // Check push button mode (Conditional Compilation)
        #if ((PB1_MODE == INTERNAL_PULL_UP) || (PB1_MODE == EXTERNAL_PULL_UP))
            // Check pin state and set push botton status
            if (PinState == LOW){PushButtonStatus = PRESSED;}else{PushButtonStatus = RELEASED;}    
        #elif PB1_MODE == EXTERNAL_PULL_DOWN
            if (PinState == HIGH){PushButtonStatus = PRESSED;}else{SPushButtonStatus = RELEASED;}
        #endif
        break;

    case BUTTON2:
        // Read IO pin which is realated to the PB2
        PinState = GPIO_getPinValue(PB2_PORT,PB2_PIN);
        // Check push button mode (Conditional Compilation)
        #if ((PB2_MODE == INTERNAL_PULL_UP) || (PB2_MODE == EXTERNAL_PULL_UP))
            // Check pin state and set push botton status
            if (PinState == LOW){PushButtonStatus = PRESSED;}else{PushButtonStatus = RELEASED;}    
        #elif PB2_MODE == EXTERNAL_PULL_DOWN
            if (PinState == HIGH){PushButtonStatus = PRESSED;}else{PushButtonStatus = RELEASED;}
        #endif
        break;

    case BUTTON3:
        // Read IO pin which is realated to the PB3
        PinState = GPIO_getPinValue(PB3_PORT,PB3_PIN);
        // Check push button mode (Conditional Compilation)
        #if ((PB3_MODE == INTERNAL_PULL_UP) || (PB3_MODE == EXTERNAL_PULL_UP))
            // Check pin state and set push botton status
            if (PinState == LOW){PushButtonStatus = PRESSED;}else{PushButtonStatus = RELEASED;}    
        #elif PB3_MODE == EXTERNAL_PULL_DOWN
            if (PinState == HIGH){PushButtonStatus = PRESSED;}else{PushButtonStatus = RELEASED;}
        #endif
        break;

    case BUTTON4:
        // Read IO pin which is realated to the PB4
        PinState = GPIO_getPinValue(PB4_PORT,PB4_PIN);
        // Check push button mode (Conditional Compilation)
        #if ((PB4_MODE == INTERNAL_PULL_UP) || (PB4_MODE == EXTERNAL_PULL_UP))
            // Check pin state and set push botton status
            if (PinState == LOW){PushButtonStatus = PRESSED;}else{PushButtonStatus = RELEASED;}    
        #elif PB4_MODE == EXTERNAL_PULL_DOWN
            if (PinState == HIGH){PushButtonStatus = PRESSED;}else{PushButtonStatus = RELEASED;}
        #endif
        break;

    default:
        // Do nothing
        break;
    }
    
    return PushButtonStatus;
}







