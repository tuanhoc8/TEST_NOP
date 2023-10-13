#ifndef SYS_TICK_
#define SYS_TICK_

#include <stdint.h>

#define SYST_T_BASE (0xE000E010)

typedef struct SYST
{
	volatile uint32_t CSR;
	volatile uint32_t RVR;
	volatile uint32_t CVR;
	volatile uint32_t CALIB;
}	SYST_t;

#define SYST ((SYST_t *)SYST_T_BASE)

#endif
