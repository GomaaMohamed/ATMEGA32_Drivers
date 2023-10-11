/*****************************************************************************
* @file:    ADC_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Mon, 18 Sep 2023 09:29:28 +0300
* @brief:   ADC Driver for Atmega32.
******************************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/* ==================================================================== */
/* ======================= Public Data Types ========================== */
/* ==================================================================== */

/* Voltage refrence data type */
typedef enum {
	ADC_VREF_AREF_PIN=0,
    ADC_VREF_AVCC_PIN,
	ADC_VREF_INTERNAL_2560mV,
    ADC_VREF_ERR
}AdcReferenceVoltage_type;

/* Channel data type */
typedef enum {
    // Single ended options
	SINGLE_ENDED_CH0_ADC0 = 0 ,
	SINGLE_ENDED_CH1_ADC1 ,
	SINGLE_ENDED_CH2_ADC2 ,
	SINGLE_ENDED_CH3_ADC3 ,
	SINGLE_ENDED_CH4_ADC4 ,
	SINGLE_ENDED_CH5_ADC5 ,
	SINGLE_ENDED_CH6_ADC6 ,
	SINGLE_ENDED_CH7_ADC7 ,
	// Differential options
	DIFFERENTIAL_GAIN_10X_POSITIVE_ADC1_NEGATIVE_ADC0  ,
	DIFFERENTIAL_GAIN_200X_POSITIVE_ADC1_NEGATIVE_ADC0 ,
	DIFFERENTIAL_GAIN_10X_POSITIVE_ADC3_NEGATIVE_ADC2  ,
	DIFFERENTIAL_GAIN_200X_POSITIVE_ADC3_NEGATIVE_ADC2 ,
	DIFFERENTIAL_GAIN_1X_POSITIVE_ADC0_NEGATIVE_ADC1 ,
	DIFFERENTIAL_GAIN_1X_POSITIVE_ADC2_NEGATIVE_ADC1 ,
	DIFFERENTIAL_GAIN_1X_POSITIVE_ADC3_NEGATIVE_ADC1 ,
	DIFFERENTIAL_GAIN_1X_POSITIVE_ADC4_NEGATIVE_ADC1 ,
	DIFFERENTIAL_GAIN_1X_POSITIVE_ADC5_NEGATIVE_ADC1 ,
	DIFFERENTIAL_GAIN_1X_POSITIVE_ADC6_NEGATIVE_ADC1 ,
	DIFFERENTIAL_GAIN_1X_POSITIVE_ADC7_NEGATIVE_ADC1 ,
	DIFFERENTIAL_GAIN_1X_POSITIVE_ADC0_NEGATIVE_ADC2 ,
	DIFFERENTIAL_GAIN_1X_POSITIVE_ADC1_NEGATIVE_ADC2 ,
	DIFFERENTIAL_GAIN_1X_POSITIVE_ADC3_NEGATIVE_ADC2 ,
	DIFFERENTIAL_GAIN_1X_POSITIVE_ADC4_NEGATIVE_ADC2 ,
	DIFFERENTIAL_GAIN_1X_POSITIVE_ADC5_NEGATIVE_ADC2,
    ADC_CHANNEL_ERR
}AdcChannel_type;

/* Prescaler data type */
typedef enum{
	ADC_PRESCALER_DIV_2 = 0 ,
	ADC_PRESCALER_DIV_4 ,
	ADC_PRESCALER_DIV_8 ,
	ADC_PRESCALER_DIV_16 ,
	ADC_PRESCALER_DIV_32 ,
	ADC_PRESCALER_DIV_64 ,
	ADC_PRESCALER_DIV_128,
}AdcPrescaler_type;

/* Autotrigger data type */
typedef enum {
	AUTOTRIGGER_DISABLED=0,
	AUTOTRIGGER_FREE_RUNNING,
	AUTOTRIGGER_ANALOG_COMPARATOR,
	AUTOTRIGGER_EXTERNAL_INT0,
	AUTOTRIGGER_TIMER_COUNTER0_COMPARE_MATCH,
	AUTOTRIGGER_TIMER_COUNTER0_OVERFLOW,
	AUTOTRIGGER_TIMER_COUNTER_COMPARE_MATCH_B,
	AUTOTRIGGER_TIMER_COUNTER1_OVERFLOW,
	AUTOTRIGGER_TIMER_COUNTER1_CAPTURE_EVENT,
    AUTOTRIGGER_ERR
}AdcAutotriggerSource_type;

/* Configuration data type */
typedef struct adcconfig {
	AdcReferenceVoltage_type  AdcReferenceVoltage ;
	AdcChannel_type           AdcChannel ;
	AdcPrescaler_type         AdcPrescaler ;
	AdcAutotriggerSource_type AdcAutotriggerSource ;
}AdcConfig_type;

 
/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Initialize adc module
 * @parameter1----------------> (Object) initialization object that holds adc configurations
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void ADC_init(AdcConfig_type *Object);

/**
 * @brief---------------------> Read adc current channel
 * @param---------------------> None
 * @return--------------------> Channel value
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
u16  ADC_read(void);

/**
 * @brief---------------------> Change prescaler
 * @parameter1----------------> (AdcPrescaler) the needed prescaler to be set
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void ADC_changePrescalar(AdcPrescaler_type AdcPrescaler);

/**
 * @brief---------------------> Change channel
 * @parameter1----------------> (AdcChannel)the needed channel
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void ADC_changeChannel(AdcChannel_type AdcChannel);

/**
 * @brief---------------------> Change trigger source
 * @parameter1----------------> (AdcAutotriggerSource) the needed source to be changed
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void ADC_changeTriggerSource(AdcAutotriggerSource_type AdcAutotriggerSource);

/**
 * @brief---------------------> Change refreence voltage
 * @parameter1----------------> (AdcReferenceVoltage) the needed voltage to be changed
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void ADC_changeReferenceVoltage(AdcReferenceVoltage_type AdcReferenceVoltage);

/**
 * @brief---------------------> Enable adc
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void ADC_enable(void);

/**
 * @brief---------------------> Disable adc
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void ADC_disable(void);

/**
 * @brief---------------------> Start conversion
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Reentrant             
 */
void ADC_startConversion(void);


#endif

