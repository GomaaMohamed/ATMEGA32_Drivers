/*****************************************************************************
* @file:    WDG_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sun, 01 Oct 2023 22:26:56 +0300
* @brief:   Watch Dog Driver for Atmega32.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDG_interface.h"
#include "WDG_private.h"
#include "WDG_config.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to start WDG
void WDG_startTimer(WatchDogTime_type WatchDogTime)
{
    // Validate input parameters
    ASSERT(WatchDogTime >= 0 && WatchDogTime < WDGT_ERR);

    // Set watch dog time
    #if   WDG_OPERATION_VOLTAGE == 5
        switch (WatchDogTime)
        {
            case WDGT_5V_16_3ms:
                CLR_BIT(WDTCR, WDP0);
                CLR_BIT(WDTCR, WDP1);
                CLR_BIT(WDTCR, WDP2);
                break;
            case WDGT_5V_32_5ms:
                SET_BIT(WDTCR, WDP0);
                CLR_BIT(WDTCR, WDP1);
                CLR_BIT(WDTCR, WDP2);
                break;
            case WDGT_5V_65_0ms:
                CLR_BIT(WDTCR, WDP0);
                SET_BIT(WDTCR, WDP1);
                CLR_BIT(WDTCR, WDP2);
                break;
            case WDGT_5V_0_13s:
                SET_BIT(WDTCR, WDP0);
                SET_BIT(WDTCR, WDP1);
                CLR_BIT(WDTCR, WDP2);
                break;
            case WDGT_5V_0_26s:
                CLR_BIT(WDTCR, WDP0);
                CLR_BIT(WDTCR, WDP1);
                SET_BIT(WDTCR, WDP2);
                break;
            case WDGT_5V_0_52s:
                SET_BIT(WDTCR, WDP0);
                CLR_BIT(WDTCR, WDP1);
                SET_BIT(WDTCR, WDP2);
                break;
            case WDGT_5V_1_0s:
                CLR_BIT(WDTCR, WDP0);
                SET_BIT(WDTCR, WDP1);
                SET_BIT(WDTCR, WDP2);
                break;
            case WDGT_5V_2_1s:
                SET_BIT(WDTCR, WDP0);
                SET_BIT(WDTCR, WDP1);
                SET_BIT(WDTCR, WDP2);
                break;
            default:
                // Do nothing 
                break;
        }
    #elif WDG_OPERATION_VOLTAGE == 3
        switch (WatchDogTime)
        {
            case WDGT_3V_17_1ms:
                CLR_BIT(WDTCR, WDP0);
                CLR_BIT(WDTCR, WDP1);
                CLR_BIT(WDTCR, WDP2);
                break;
            case WDGT_3V_34_3ms:
                SET_BIT(WDTCR, WDP0);
                CLR_BIT(WDTCR, WDP1);
                CLR_BIT(WDTCR, WDP2);
                break;
            case WDGT_3V_68_5ms:
                CLR_BIT(WDTCR, WDP0);
                SET_BIT(WDTCR, WDP1);
                CLR_BIT(WDTCR, WDP2);
                break;
            case WDGT_3V_0_14s:
                SET_BIT(WDTCR, WDP0);
                SET_BIT(WDTCR, WDP1);
                CLR_BIT(WDTCR, WDP2);
                break;
            case WDGT_3V_0_27s:
                CLR_BIT(WDTCR, WDP0);
                CLR_BIT(WDTCR, WDP1);
                SET_BIT(WDTCR, WDP2);
                break;
            case WDGT_3V_0_55s:
                SET_BIT(WDTCR, WDP0);
                CLR_BIT(WDTCR, WDP1);
                SET_BIT(WDTCR, WDP2);
                break;
            case WDGT_3V_1_1s:
                CLR_BIT(WDTCR, WDP0);
                SET_BIT(WDTCR, WDP1);
                SET_BIT(WDTCR, WDP2);
                break;
            case WDGT_3V_2_2s:
                SET_BIT(WDTCR, WDP0);
                SET_BIT(WDTCR, WDP1);
                SET_BIT(WDTCR, WDP2);
                break;
            default:
                // Do nothing 
                break;
        }
    #endif

    // Enable wadg
    SET_BIT(WDTCR, WDE);
}

// Function to reset WDG
void WDG_stopTimer(void)
{
    // Make stop sequence
    SET_BIT(WDTCR, WDTOE);
    SET_BIT(WDTCR, WDE);
    CLR_BIT(WDTCR, WDE);
}
