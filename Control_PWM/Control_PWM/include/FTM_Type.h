#ifndef	FTM_TYPE_
#define FTM_TYPE_

#include <stdint.h>

#define FTM_0_BASE (0x40038000)
#define FTM_1_BASE (0x40039000)
#define FTM_2_BASE (0x4003A000)
#define FTM_3_BASE (0x40026000)
#define FTM_4_BASE (0x4006E000)
#define FTM_5_BASE (0x4006F000)
#define FTM_6_BASE (0x40070000)
#define FTM_7_BASE (0x40071000)

typedef struct FTM
{
	volatile uint32_t SC;
	volatile uint32_t CNT;
	volatile uint32_t MOD;
	volatile uint32_t C0SC;
	volatile uint32_t C0V;
	volatile uint32_t C1SC;
	volatile uint32_t C1V;
	volatile uint32_t C2SC;
	volatile uint32_t C2V;
	volatile uint32_t C3SC;
	volatile uint32_t C3V;
	volatile uint32_t C4SC;
	volatile uint32_t C4V;
	volatile uint32_t C5SC;
	volatile uint32_t C5V;
	volatile uint32_t C6SC;
	volatile uint32_t C6V;
	volatile uint32_t C7SC;
	volatile uint32_t C7V;
	volatile uint32_t CNTIN;
	volatile uint32_t STATUS;
	volatile uint32_t MODE;
	volatile uint32_t SYNC;
	volatile uint32_t OUTINIT;
	volatile uint32_t OUTMASK;
	volatile uint32_t COMBINE;
	volatile uint32_t DEADTIME;
	volatile uint32_t EXTTRIG;
	volatile uint32_t POL;
	volatile uint32_t FMS;
	volatile uint32_t FILTER;
	volatile uint32_t FLTCTRL;
	volatile uint32_t QDCTRL;
	volatile uint32_t CONF;
	volatile uint32_t FLTPOL;
	volatile uint32_t SYNCONF;
	volatile uint32_t INVCTRL;
	volatile uint32_t SWOCTRL;
	volatile uint32_t PWMLOAD;
	volatile uint32_t HCR;
	volatile uint32_t PAIR0DEADTIME;
	volatile uint32_t Reserved1[1];
	volatile uint32_t PAIR1DEADTIME;
	volatile uint32_t Reserved2[1];
	volatile uint32_t PAIR2DEADTIME;
	volatile uint32_t Reserved3[1];
	volatile uint32_t PAIR3DEADTIME;
	volatile uint32_t Reserved4[81];
	volatile uint32_t MOD_MIRROR;
	volatile uint32_t C0V_MIRROR;
	volatile uint32_t C1V_MIRROR;
	volatile uint32_t C2V_MIRROR;
	volatile uint32_t C3V_MIRROR;
	volatile uint32_t C4V_MIRROR;
	volatile uint32_t C5V_MIRROR;
	volatile uint32_t C6V_MIRROR;
	volatile uint32_t C7V_MIRROR;
}	FTM_t;

#define FTM_0 ((FTM_t *)FTM_0_BASE)
#define FTM_1 ((FTM_t *)FTM_1_BASE)
#define FTM_2 ((FTM_t *)FTM_2_BASE)
#define FTM_3 ((FTM_t *)FTM_3_BASE)
#define FTM_4 ((FTM_t *)FTM_4_BASE)
#define FTM_5 ((FTM_t *)FTM_5_BASE)
#define FTM_6 ((FTM_t *)FTM_6_BASE)
#define FTM_7 ((FTM_t *)FTM_7_BASE)

// Function init
void init_pwmch1(void);

#endif
