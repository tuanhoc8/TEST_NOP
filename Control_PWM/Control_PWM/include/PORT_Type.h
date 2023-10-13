#ifndef	PORT_TYPE_
#define PORT_TYPE_

#include <stdint.h>

#define PORT_A_BASE (0x40049000)
#define PORT_B_BASE (0x4004A000)
#define PORT_C_BASE (0x4004B000)
#define PORT_D_BASE (0x4004C000)
#define PORT_E_BASE (0x4004D000)

typedef struct PORT
{
	volatile uint32_t PCR[32];
	volatile uint32_t GPCLR;
	volatile uint32_t GPCHR;
	volatile uint32_t GICLR;
	volatile uint32_t GICHR;
	volatile uint32_t Reserved1[4];
	volatile uint32_t ISFR;
	volatile uint32_t Reserved2[7];
	volatile uint32_t DFER;
	volatile uint32_t DFCR;
	volatile uint32_t DFWR;
}	PORT_t;

#define PORT_A ((PORT_t *)PORT_A_BASE)
#define PORT_B ((PORT_t *)PORT_B_BASE)
#define PORT_C ((PORT_t *)PORT_C_BASE)
#define PORT_D ((PORT_t *)PORT_D_BASE)
#define PORT_E ((PORT_t *)PORT_E_BASE)

#endif
