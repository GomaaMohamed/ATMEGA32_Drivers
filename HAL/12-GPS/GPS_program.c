/*****************************************************************************
* @file:    GPS_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed. 
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sun, 10 Sep 2023 13:26:58 +0300
* @brief:   GPS Driver.
******************************************************************************/

/* ==================================================================== */
/* ========================== Include Files =========================== */
/* ==================================================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <util/delay.h>

#include "GPS_interface.h"
#include "GPS_private.h"
#include "GPS_config.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to initialize GPS Module
void GPS_init(void){
    LED_init();
    UART_init();
    memset(GGABuffer, 0, 150);
	memset(DegreesBuffer,0,20);
    Counter = 0;      
    CommaCounter = 0; 
    ReceivedState = 0;        
    TimeIndex = 0;       
    LatitudeIndex = 0;   
    LongitudeIndex = 0;  
    FixIndex = 0;        
    SatellitesIndex = 0; 
    AltitudeIndex = 0;   
}

// Function used as a task to update the location and time
void GPS_update(void){
    
/*===================== Action1: Receive a GGA frame ====================*/  

    // Receive a Charachter
    u8 Check = UART_receiveCharacter(&GGABuffer[Counter]);

    // Check if a new charachter was received or not 
    // Validate that we have already received a start of frame '$'
    if (Check == 1 && GGABuffer[0] == '$' && ReceivedState == 0)
    {
        // Check if we received a complete GGA frame or not
        if (GGABuffer[Counter] == '*')
        {
            // Reset counter
            Counter = 0;

            // Stop receiving and analyze the received frame
            ReceivedState = 1;
        }
        else
        {
            // Increment counter to receive a new character and store it in GGABuffer
            Counter++;
        }
        
    }

/*======================= Action2: Anayze GGA frame ========================*/

    // Check that a GGA frame was received
    if(ReceivedState == 1)
    {
        // Get the Indeces of the frame Parts check position
        u8 check = 0;
        for (u8 i = 0; GGABuffer[i]!='*'; i++)
        {
            if (GGABuffer[i] == ',')
            {
                check++;
                if (check == 1){TimeIndex = i+1;}
                else if (check == 2){LatitudeIndex = i+1;}
                else if (check == 4){LongitudeIndex = i+1;}
                else if (check == 6){FixIndex = i+1;}
                else if (check == 7){SatellitesIndex = i+1;}
                else if (check == 9){AltitudeIndex = i+1;}
            }
        
        }
        // Check that GGA frame is related to a valid position
        if (GGABuffer[FixIndex]=='1')
        {
            u8 index = 0;
            u8 i;

            // Loop on the GGA frame and extract Time into its buffer
            for (i = TimeIndex; GGABuffer[i]!=','; i++)
            {
                TimeFlag = 1;
                TimeBuffer[index++] = GGABuffer[i];
            }
            TimeBuffer[index] = '0';
            index = 0;

            // Loop on the GGA frame and extract Latitude into its buffer
            for (i = LatitudeIndex; GGABuffer[i]!=','; i++)
            {
                LatitudeFlag = 1;
                LatitudeBuffer[index++] = GGABuffer[i];
            }
            LatitudeBuffer[index] = GGABuffer[i + 1];
            index = 0;

            // Loop on the GGA frame and extract Longitude into its buffer
            for (i = LongitudeIndex; GGABuffer[i]!=','; i++)
            {
                LongitudeFlag = 1;
                LongitudeBuffer[index++] = GGABuffer[i];
            }
            LongitudeBuffer[index] = GGABuffer[i + 1];
            index = 0;

            // Loop on the GGA frame and extract Altitude into its buffer
            for (i = AltitudeIndex; GGABuffer[i]!=','; i++)
            {
                AltitudeFlag = 1;
                AltitudeBuffer[index++] = GGABuffer[i];
            }
            AltitudeBuffer[index] = GGABuffer[i + 1];
            index = 0;
            }
        
        // Indicate that the received frame was a
        ReceivedState = 0;
    }
}

// Function to read the current Time in UTC
u8* GPS_getTime(void)
{
    if (TimeFlag == 1)
    {
    // Convert Time to UTC 
    GPS_convertTimeToUTC();
    TimeFlag = 0;
    }
    // Return time buffer
    return TimeBuffer;
}

// Function to read the current Latitude in Degrees
u8* GPS_getLatitude(void)
{
    if (LatitudeFlag == 1)
    {
    // Convert Latitude to degrees
    GPS_convertToDegrees(LatitudeBuffer);
    LatitudeFlag = 0;
    }
    // Return latitude buffer
    return LatitudeBuffer;
}

// Function to read the current Longitude in Degrees
u8* GPS_getLongitude(void)
{
    if (LongitudeFlag == 1)
    {
    // Convert Longitude to degrees
    GPS_convertToDegrees(LongitudeBuffer);
    LongitudeFlag = 0;
    }   
    // Return longitude buffer
    return LongitudeBuffer;
}

// Function to read the current Altitude in Degrees
u8* GPS_getAltitude(void)
{
    // Return altitude buffer
    return AltitudeBuffer;
}

/* ==================================================================== */
/* ================ Private Functions Implementation ================== */
/* ==================================================================== */

static void GPS_convertTimeToUTC()
{
    u32 Hour, Min, Sec;
    u32 TimeValue;

    // Convert string to integer
    TimeValue = atol(TimeBuffer);   
    // Get hour from integer   
    Hour = (TimeValue / 10000); 
    // Get minute from integer     
    Min = (TimeValue / 100) % 100;  
    // Get second from integer
    Sec = (TimeValue % 100); 
    
    sprintf(TimeBuffer, "%02d:", Hour);
    sprintf(TimeBuffer+3, "%02d:", Min);
    sprintf(TimeBuffer+6, "%02d", Sec);

}

static void GPS_convertToDegrees(u8 *Raw)
{
    f32 Value;
    f32 DecimalValue,Temp;
    s32 Degrees;

    float Position;
    // Convert string into float 
    Value = atof(Raw);  

    // convert raw to degree format 
    DecimalValue = (Value/100);
    Degrees = (s32)(DecimalValue);
    Temp = (DecimalValue - (s32)DecimalValue)/0.6;
    Position = (float)Degrees + Temp;
    // Convert float value into string 
    dtostrf(Position, 6, 4, DegreesBuffer); 
}






