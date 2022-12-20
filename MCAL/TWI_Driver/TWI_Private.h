/*
 * TWI_Private.h
 *
 *  Created on: Oct 27, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_TWI_DRIVER_TWI_PRIVATE_H_
#define MCAL_TWI_DRIVER_TWI_PRIVATE_H_

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"


#define OFFSET_ADDRESS 0x20

#define TWBR _MMIO_BYTE(OFFSET_ADDRESS + 0x00)
#define TWBR0 0
#define TWBR1 1
#define TWBR2 2
#define TWBR3 3
#define TWBR4 4
#define TWBR5 5
#define TWBR6 6
#define TWBR7 7

#define TWCR _MMIO_BYTE(OFFSET_ADDRESS + 0x36)
#define TWINT 7
#define TWEA 6
#define TWSTA 5
#define TWSTO 4
#define TWWC 3
#define TWEN 2
#define TWIE 0


#define TWSR _MMIO_BYTE(OFFSET_ADDRESS +0x01 )
#define TWS7 7
#define TWS6 6
#define TWS5 5
#define TWS4 4
#define TWS3 3
#define TWPS1 1
#define TWPS0 0

#define TWDR _MMIO_BYTE(OFFSET_ADDRESS + 0x03)
#define TWD0 0
#define TWD1 1
#define TWD2 2
#define TWD3 3
#define TWD4 4
#define TWD5 5
#define TWD6 6
#define TWD7 7

#define TWAR _MMIO_BYTE(OFFSET_ADDRESS + 0x02)
#define TWGCE 0
#define TWA0 1
#define TWA1 2
#define TWA2 3
#define TWA3 4
#define TWA4 5
#define TWA5 6
#define TWA6 7

#endif /* MCAL_TWI_DRIVER_TWI_PRIVATE_H_ */
