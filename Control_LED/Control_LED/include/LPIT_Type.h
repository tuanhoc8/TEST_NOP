#ifndef LPIT_TYPE_
#define LPIT_TYPE_

#include <stdint.h>

#define LPIT_T_BASE (0x40037000)

typedef struct LPIT_T
{
	volatile uint32_t VERID;
	volatile uint32_t PARAM;
	volatile uint32_t MCR;
	volatile uint32_t MSR;
	volatile uint32_t MIER;
	volatile uint32_t SETTEN;
	volatile uint32_t CLRTEN;
	volatile uint32_t Reserved1;
	volatile uint32_t TVAL0;
	volatile uint32_t CVAL0;
	volatile uint32_t TCTRL0;
	volatile uint32_t Reserved2;
	volatile uint32_t TVAL1;
	volatile uint32_t CVAL1;
	volatile uint32_t TCTRL1;
	volatile uint32_t Reserved3;
	volatile uint32_t TVAL2;
	volatile uint32_t CVAL2;
	volatile uint32_t TCTRL2;
	volatile uint32_t Reserved4;
	volatile uint32_t TVAL3;
	volatile uint32_t CVAL3;
	volatile uint32_t TCTRL3;
}	LPIT_t;

#define LPIT_T ((LPIT_t *)LPIT_T_BASE)

void init_lpit(void);
void LPIT0_Ch0_IRQHandler(void);
void delay_ms(uint32_t ms);
void LPIT0_Ch1_IRQHandler(void);

#endif
