#ifndef	LPUART_TYPE_
#define LPUART_TYPE_

#include <stdint.h>

#define LPUART0_BASE (0x4006A000)
#define LPUART1_BASE (0x4006B000)
#define LPUART2_BASE (0x4006C000)

typedef struct LPUART_T
{
	volatile uint32_t VERID;
	volatile uint32_t PARAM;
	volatile uint32_t GLOBAL;
	volatile uint32_t PINCFG;
	volatile uint32_t BAUD;
	volatile uint32_t STAT;
	volatile uint32_t CTRL;
	volatile uint32_t DATA;
	volatile uint32_t MATCH;
	volatile uint32_t MODIR;
	volatile uint32_t FIFO;
	volatile uint32_t WATER;
}	LPUART_t;

#define LPUART0_T ((LPUART_t *)LPUART0_BASE)
#define LPUART1_T ((LPUART_t *)LPUART1_BASE)
#define LPUART2_T ((LPUART_t *)LPUART2_BASE)

void init_lpuart1(void);
void send_uart(const char * data);

#endif
