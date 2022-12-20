/*
 * SS_Config.h
 *
 *  Created on: Nov 13, 2022
 *      Author: Kimo Store
 */

#ifndef HAL_SEVENSEGMENT_DRIVER_SS_CONFIG_H_
#define HAL_SEVENSEGMENT_DRIVER_SS_CONFIG_H_


/* Options
 * 1) GPIOA
 * 2) GPIOB
 * 3) GPIOC
 * 4) GPIOD
*/
#define SevenSegment_GPIO GPIOB


/* Options
 * 1) WithoutDecoder
 * 2) WithDecoder
*/
#define SevenSegment_Mode WithDecoder

#define SevenSegmentCommon Cathode




#endif /* HAL_SEVENSEGMENT_DRIVER_SS_CONFIG_H_ */
