#ifndef NVIC_TYPE_
#define NVIC_TYPE_

#include <stdint.h>

#define	NVIC_T_BASE	(0xE000E100)

typedef struct NVIC_T
{
	volatile uint32_t ISER[8];
	volatile uint32_t res1[24];
	volatile uint32_t ICER[8];
	volatile uint32_t res2[24];
	volatile uint32_t ISPR[8];
	volatile uint32_t res3[24];
	volatile uint32_t ICPR[8];
	volatile uint32_t res4[24];
	volatile uint32_t IABR[8];
	volatile uint32_t res5[56];
	volatile uint32_t IPR[60];
	volatile uint32_t res6[644];
	volatile uint32_t STIR;
} NVIC_t;

#define NVIC ((NVIC_t*)NVIC_T_BASE)

#endif
