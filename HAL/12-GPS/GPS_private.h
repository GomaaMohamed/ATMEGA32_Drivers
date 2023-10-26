/*****************************************************************************
* @file:    GPS_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Sun, 10 Sep 2023 13:26:58 +0300
* @brief:   GPS Driver.
******************************************************************************/
#ifndef _GPS_PRIVATE_H
#define _GPS_PRIVATE_H

/* ==================================================================== */
/* ========================== Private Variables ======================= */
/* ==================================================================== */

static u8 GGABuffer[150];       // Buffer to hold the GGA frame
static u8 LatitudeBuffer[15];   // Buffer to hold the Latitude part
static u8 LongitudeBuffer[15];  // Buffer to hold the Longitude part
static u8 TimeBuffer[10];       // Buffer to hold the Time part
static u8 AltitudeBuffer[15];   // Buffer to hold the Altitude part
static u8 DegreesBuffer[20];    // Buffer to hold the converted (Lat/Long) in form of degrees part
static u8* TempAltitudeBuffer;  // Temp buffer o hold the Altitude part

static volatile u8 Counter;      // Counter to 
static volatile u8 CommaCounter; // Counter to hold the number of commas
static u8 ReceivedState;         // Flag to indicate the state of Module task

u8 TimeFlag = 0;      // Flag to protect TimeBuffer
u8 LatitudeFlag;      // Flag to protect LatitudeBuffer
u8 LongitudeFlag;     // Flag to protect LongitudeBuffer
u8 AltitudeFlag;      // Flag to protect AltiitudeBuffer

static u8 TimeIndex;       // Time index in GGA frame
static u8 LatitudeIndex;   // Latitude index in GGA frame
static u8 LongitudeIndex;  // Longitude index in GGA frame
static u8 FixIndex;        // Fix Quality index in GGA frame
static u8 SatellitesIndex; // Number of Satellites index in GGA frame
static u8 AltitudeIndex;   // Altitude index in GGA frame

/* ==================================================================== */
/* ==================== Private Functions Declaration ================= */
/* ==================================================================== */

static void GPS_convertTimeToUTC(void);
static void GPS_convertToDegrees(u8 *Raw);
static void GPS_Callback(void);

#define SREG *((volatile u8*)0x5F)




#endif

