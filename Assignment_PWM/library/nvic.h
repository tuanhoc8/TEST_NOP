/*
 * nvic.h
 *
 *  Created on: Oct 4, 2023
 *      Author: TIN
 */

#ifndef NVIC_H_
#define NVIC_H_

#include <stdint.h>

typedef struct
{
	volatile uint32_t SETENA_bits;
}NVIC_Type;
#define NVIC_ISER0_BASE ((uint32_t)0xE000E100)
#define NVIC_ISER1_BASE ((uint32_t)0xE000E104)
#define NVIC_ISER0 ((NVIC_Type*)NVIC_ISER0_BASE)
#define NVIC_ISER1 ((NVIC_Type*)NVIC_ISER1_BASE)

#endif /* NVIC_H_ */
