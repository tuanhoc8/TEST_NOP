#ifndef	GPIO_TYPE_
#define GPIO_TYPE_

#include <stdint.h>

#define GPIO_A_BASE (0x400FF000)
#define GPIO_B_BASE (0x400FF040)
#define GPIO_C_BASE (0x400FF080)
#define GPIO_D_BASE (0x400FF0C0)
#define GPIO_E_BASE (0x400FF100)

typedef struct GPIO
{
	volatile uint32_t PDOR; // Offset 0x00 - Port Data Output Register
	volatile uint32_t PSOR; // Offset 0x04 - Port Set Output Register
	volatile uint32_t PCOR; // Offset 0x08 - Port Clear Output Register
	volatile uint32_t PTOR; // Offset 0x0C - Port Toggle Output Register
	volatile uint32_t PDIR; // Offset 0x10 - Port Data Input Register
	volatile uint32_t PDDR; // Offset 0x14 - Port Data Direction Register
	volatile uint32_t PIDR; // Offset 0x18 - Port Input Disable Register
}	GPIO_t;

#define GPIOA ((GPIO_t *)GPIO_A_BASE)
#define GPIOB ((GPIO_t *)GPIO_B_BASE)
#define GPIOC ((GPIO_t *)GPIO_C_BASE)
#define GPIOD ((GPIO_t *)GPIO_D_BASE)
#define GPIOE ((GPIO_t *)GPIO_E_BASE)

void init_gpio(void);
void PORTC_IRQHandler(void);

#endif
