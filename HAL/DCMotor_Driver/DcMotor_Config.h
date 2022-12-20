/*
 * DcMotor_Config.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Kimo Store
 */

#ifndef HAL_DCMOTOR_DRIVER_DCMOTOR_CONFIG_H_
#define HAL_DCMOTOR_DRIVER_DCMOTOR_CONFIG_H_

/*
 * in SetDuty Function you must put value from 0 to 255
 * because Timer0 Register is 8 bit register
 *
 * 100 % DutyCycle -- > 255
 * 50 %  DutyCycle -- > 127
 * 0 %   DutyCycle -- > 0
 *
 * */


#define DcMotor_Port GPIOC
#define DcMotor_Pin0 PIN0
#define DcMotor_Pin1 PIN1




#endif /* HAL_DCMOTOR_DRIVER_DCMOTOR_CONFIG_H_ */
