/*
 * port.h
 *
 *  Created on: Sep 25, 2023
 *      Author: TIN
 */

#ifndef PORT_H_
#define PORT_H_

#include <stdio.h>
#include <stdint.h>

#define PCR_index 32u

typedef struct
{
	volatile uint32_t PORT_PCR[PCR_index];
	volatile uint32_t PORT_GPCLR;
	volatile uint32_t PORT_GPCHR;
	volatile uint32_t GICLR;
	volatile uint32_t GICHR;
	volatile uint8_t RESERVED_0[16];
	volatile uint32_t ISFR;
	volatile uint8_t RESERVED_1[28];
	volatile uint32_t DFER;
	volatile uint32_t DFCR;
	volatile uint32_t DFWR;
}PORT_Type;
#define PORT_A_BASE ((uint32_t)0x40049000)
#define PORT_B_BASE ((uint32_t)0x4004A000)
#define PORT_C_BASE ((uint32_t)0x4004B000)
#define PORT_D_BASE ((uint32_t)0x4004C000)
#define PORT_E_BASE ((uint32_t)0x4004D000)
#define PORT_A		((PORT_Type*)PORT_A_BASE)
#define PORT_B		((PORT_Type*)PORT_B_BASE)
#define PORT_C		((PORT_Type*)PORT_C_BASE)
#define PORT_D		((PORT_Type*)PORT_D_BASE)
#define PORT_E		((PORT_Type*)PORT_E_BASE)

#endif /* PORT_H_ */
