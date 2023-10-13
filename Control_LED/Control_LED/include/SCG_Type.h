#ifndef	SCG_TYPE_
#define SCG_TYPE_

#include <stdint.h>

#define	SCG_T_BASE	(0x40064000)

typedef struct SCG_T
{
	volatile uint32_t VERID;
	volatile uint32_t PARAM;
	volatile uint32_t Reserved1[2];
	volatile uint32_t CSR;
	volatile uint32_t RCCR;
	volatile uint32_t VCCR;
	volatile uint32_t HCCR;
	volatile uint32_t CLKOUTCNFG;
	volatile uint32_t Reserved2[55];
	volatile uint32_t SOSCCSR;
	volatile uint32_t SOSCDIV;
	volatile uint32_t SOSCCFG;
	volatile uint32_t Reserved3[61];
	volatile uint32_t SIRCCSR;
	volatile uint32_t SIRCDIV;
	volatile uint32_t SIRCCFG;
	volatile uint32_t Reserved4[61];
	volatile uint32_t FIRCCSR;
	volatile uint32_t FIRCDIV;
	volatile uint32_t FIRCCFG;
	volatile uint32_t Reserved5[189];
	volatile uint32_t SPLLCSR;
	volatile uint32_t SPLLDIV;
	volatile uint32_t SPLLCFG;
}	SCG_t;

#define SCG ((SCG_t *)SCG_T_BASE)

void init_clock(void);
void SysTick_Handler(void);

#endif
