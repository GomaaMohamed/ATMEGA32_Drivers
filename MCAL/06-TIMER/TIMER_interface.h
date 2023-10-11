/*****************************************************************************
* @file:    TIMER_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 06 Sep 2023 10:51:56 +0300
* @brief:   Timer Driver for Atmega32.
******************************************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

/* ==================================================================== */
/* ======================= public data types ========================== */
/* ==================================================================== */

/************************ Timer data types **************************/
/* Pre-Scaler and clock source data type */
typedef enum{
	TIMER_STOP=0,
	TIMER_SCALER_1,
	TIMER_SCALER_8,
	TIMER_SCALER_64,
	TIMER_SCALER_256,
	TIMER_SCALER_1024,
	TIMER_EXTERNAL_FALLING,
	TIMER_EXTERNAL_RISING,
	TIMER_MAX_SCALER
}TimerPrescaler_type;

/* Timer0 mode data type */
typedef enum
{
	TIMER_NORMAL_MODE=0,
	TIMER_PHASECORRECT_MODE,
	TIMER_CTC_MODE,
	TIMER_FASTPWM_MODE,
	TIMER_MAX_MODE
}TimerMode_type;

/* Timer1 mode data type */
typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE,
	TIMER1_PCPWM_ICR_TOP_MODE,
	TIMER1_PCPWM_OCRA_TOP_MODE,
	TIMER1_PCFCPWM_ICR_TOP_MODE,
	TIMER1_PCFCPWM_OCRA_TOP_MODE,
	TIMER1_MAX_MODE
}Timer1Mode_type;

/* Compare Output Mode data type */
typedef enum{
	TIMER_OC_DISCONNECTED=0,
	TIMER_OC_TOGGLE,
	// Note: Clear oc pin at non-pwm modes and generates pwm signal at pwm modes
	TIMER_OC_NON_INVERTING,
	// Note: Set oc pin at non-pwm modes and generates pwm signal at pwm modes  
	TIMER_OC_INVERTING,		 
    TIMER_MAX_OC
}TimerOcMode_type;

/* Input capture unit data type */
typedef enum{
	TIMER_ICU_RISING,
	TIMER_ICU_FALLING
}TimerIcuEdge_type;

/* ==================================================================== */
/* ==================== public functions Declaration ================== */
/* ==================================================================== */

/******************* Timer0 public functions declaration *********************/

/**
 * @brief---------------------> Initialize timer0
 * @parameter1----------------> (TimerMode) mode of timer0
 * @parameter2----------------> (TimerPrescaler) timer0 prescaler
 * @parameter3----------------> (TimerOcMode) mode of oc pin
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER0_init(TimerMode_type TimerMode,TimerPrescaler_type TimerPrescaler ,TimerOcMode_type TimerOcMode);

/**
 * @brief---------------------> Reload value of timer0
 * @parameter1----------------> (TimerValue) value to be loaded
 * @return--------------------> None
 * @preconditions-------------> Timer0 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER0_reloadTimerValue(u8 TimerValue);

/**
 * @brief---------------------> Reload value of output compare
 * @parameter1----------------> (CompareValue) value to be loaded
 * @return--------------------> None
 * @preconditions-------------> Timer0 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER0_reloadCompareValue(u8 CompareValue);

/**
 * @brief---------------------> Get current value of timer0
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer0 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
u8   TIMER0_getCurrentTimerValue(void);

/**
 * @brief---------------------> Stop timer0
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER0_stopTimer(void);

/**
 * @brief---------------------> Restart timer0
 * @param---------------------> Timer0 is initialized
 * @return--------------------> None
 * @preconditions-------------> Timer0 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER0_restartTimer(void);

/**
 * @brief---------------------> Enable overflow interrupt of timer0
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer0 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER0_enableOverflowInterrupt(void);

/**
 * @brief---------------------> Disable overflow interrupt of timer0
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER0_disableOverflowInterrupt(void);

/**
 * @brief---------------------> Enable output compare interrupt of timer0
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer0 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER0_enableOutputCompareInterrupt(void);

/**
 * @brief---------------------> Disable output compare interrupt of timer0
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER0_disableOutputCompareInterrupt(void);

/**
 * @brief---------------------> Set overflow callback of timer0
 * @parameter1----------------> (Callback) callback function to be called at interrupt
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER0_setOverflowCallBack(void(*Callback)(void));

/**
 * @brief---------------------> Set ovutput compare callback of timer0
 * @parameter1----------------> (Callback) callback function to be called at interrupt
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER0_setCompareCallBack(void(*Callback)(void));

/**
 * @brief---------------------> Generate PWM on timer0 
 * @parameter1----------------> (DutyCycle) duty cycle of the genrated signal
 * @return--------------------> None
 * @preconditions-------------> Timer0 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER0_generatePWM(u8 DutyCycle);

/********************* Timer1 public functions declaration ******************/

/**
 * @brief---------------------> Initialize timer1
 * @parameter1----------------> (TimerMode) mode of timer1
 * @parameter2----------------> (TimerPrescaler) timer1 prescaler
 * @parameter3----------------> (TimerOcMode1A) mode of oc pinA
 * @parameter4----------------> (TimerOcMode1B) mode of oc pinB
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_init( Timer1Mode_type TimerMode,TimerPrescaler_type TimerPrescaler,TimerOcMode_type TimerOcMode1A,TimerOcMode_type TimerOcMode1B);

/**
 * @brief---------------------> Reload value of timer1
 * @parameter1----------------> (TimerValue) value to be loaded
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_reloadTimerValue(u16 TimerValue);

/**
 * @brief---------------------> Reload value of output compare A
 * @parameter1----------------> (CompareValue) value to be loaded
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_reloadCompareValueA(u16 CompareValue);

/**
 * @brief---------------------> Reload value of output compare B
 * @parameter1----------------> (CompareValue) value to be loaded
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_reloadCompareValueB(u16 CompareValue);

/**
 * @brief---------------------> Reload value of icu
 * @parameter1----------------> (IcuValue) value to be loaded
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_reloadIcuValue(u16 IcuValue);

/**
 * @brief---------------------> Get current value of timer1
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
u16  TIMER1_getCurrentTimerValue(void);

/**
 * @brief---------------------> Stop timer1
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_stopTimer(void);

/**
 * @brief---------------------> Restart timer1
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer0 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_restartTimer(void);

/**
 * @brief---------------------> Enable icu interrupt of timer1
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_enableIcuInterrupt(void);

/**
 * @brief---------------------> Disable icu interrupt of timer1
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_disableIcuInterrupt(void);

/**
 * @brief---------------------> Enable overflow interrupt of timer1
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_enableOverflowInterrupt(void);

/**
 * @brief---------------------> Disable overflow interrupt of timer1
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_disableOverflowInterrupt(void);

/**
 * @brief---------------------> Enable output compare A interrupt of timer1
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_enableOutputCompareAInterrupt(void);

/**
 * @brief---------------------> Disable output compare A interrupt of timer1
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_disableOutputCompareAInterrupt(void);

/**
 * @brief---------------------> Enable output compare B interrupt of timer1
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_enableOutputCompareBInterrupt(void);

/**
 * @brief---------------------> Disable output compare B interrupt of timer1
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_disableOutputCompareBInterrupt(void);

/**
 * @brief---------------------> Set input capture edge of timer1
 * @parameter1----------------> (TimerIcueEdge) edge type of icu
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_setInputCaptureEdge(TimerIcuEdge_type TimerIcueEdge);

/**
 * @brief---------------------> Get icu value of timer1
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
u16  TIMER1_getIcuValue(void);

/**
 * @brief---------------------> Set overflow callback of timer1
 * @parameter1----------------> (Callback) callback function to be called at interrupt
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_setOverflowCallBack(void(*Callback)(void));

/**
 * @brief---------------------> Set output compare A callback of timer1
 * @parameter1----------------> (Callback) callback function to be called at interrupt
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_setCompareACallBack(void(*Callback)(void));

/**
 * @brief---------------------> Set output compare B callback of timer1
 * @parameter1----------------> (Callback) callback function to be called at interrupt
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_setCompareBCallBack(void(*Callback)(void));

/**
 * @brief---------------------> Set icu callback of timer1
 * @parameter1----------------> (Callback) callback function to be called at interrupt
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_setIcuCallBack(void(*Callback)(void));

/**
 * @brief---------------------> Set fast pwm parameters for timer1
 * @parameter1----------------> (DutyCycle) duty cycle of the generated signal
 * @parameter2----------------> (Frequency) frequency of the generated signal
 * @parameter3----------------> (Clock) clock of the system
 * @parameter4----------------> (Prescaler) prescaler of timer clock
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_generateFastPWM(u8 DutyCycle,u32 Frequency,u32 Clock,u16 Prescaler);

/**
 * @brief---------------------> Set phase correct pwm parameters for timer1
 * @parameter1----------------> (DutyCycle) duty cycle of the generated signal
 * @parameter2----------------> (Frequency) frequency of the generated signal
 * @parameter3----------------> (Clock) clock of the system
 * @parameter4----------------> (Prescaler) prescaler of timer clock
 * @return--------------------> None
 * @preconditions-------------> Timer1 is initialized
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant            
 */
void TIMER1_generatePhaseCorrectPWM(u8 DutyCycle, u32 Frequency, u32 Clock, u16 Prescaler);




#endif

