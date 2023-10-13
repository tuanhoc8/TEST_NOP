#include "init.h"

volatile uint16_t frezPWM = 4000 - 1;
volatile uint16_t dutyCycle = 2000 - 1;

void init_pwmch1(void)
{
	FTM_0->SC &= ~(3U << 3);
	FTM_0->COMBINE = 0;
	FTM_0->POL = 0;
	
	FTM_0->MODE |= 0x4;
	
	FTM_0->SC |= (1 << 17) | (0 << 0);
	FTM_0->MOD = frezPWM;
	
	FTM_0->C1SC = 0x20 | 0x8;
	
	FTM_0->C1V = dutyCycle;
	
	FTM_0->SC |= (3 << 3);
}
