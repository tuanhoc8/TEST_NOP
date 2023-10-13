#include "init.h"

void init_clock(void)
{
	uint32_t rccr = 0;
	
	SCG->SOSCCSR &= ~(1u << 0);
	
	SCG->SOSCCFG |= (1 << 2);
	SCG->SOSCCFG |= (1 << 3);
	SCG->SOSCCFG |= (0x03 << 4);
	
	SCG->SOSCCSR |= (1u << 0);
	
	while((SCG->SOSCCSR & (1u << 24)) == 0)
	{
		// do nothing
	}
	
	SCG->SPLLCSR &= ~(1u << 0);
	SCG->SPLLCFG |= (0x04 << 16);
	// SPLLDIV devide 4, 20MHz
	SCG->SPLLDIV |= (0x03 << 8);
	
	rccr |= (0x06 << 24);
	rccr &= ~(0x0Fu << 16);
	rccr |= (0x01 << 4);
	rccr |= (0x03 << 0);
	
	SCG->RCCR = rccr;
	
	SCG->SPLLCSR |= (1u << 0);
	
	while((SCG->SPLLCSR & (1u << 24)) == 0)
	{
		// Do nothing
	}
	
	// Enable SIRC, SIRCDIV2 devide 1 = 8MHz, SIRCDIV1 devide 1 = 8MHz
	SCG->SIRCDIV |= (1 << 8) | (1 << 0);
	SCG->SIRCCSR |= (1 << 0);
	SCG->SIRCCFG |= (1 << 0);
	while((SCG->SIRCCSR & (1u << 24)) == 0)
	{
		// Do nothing
	}
	
	// Clock enable for PORT
	PCC->PORTA |= (1U << 30);
	PCC->PORTB |= (1U << 30);
	PCC->PORTC |= (1U << 30);
	PCC->PORTD |= (1U << 30);
	PCC->PORTE |= (1U << 30);
	
	// Clock enable for LPIT0
	PCC->LPIT |= (0x06 << 24);
	PCC->LPIT |= (0x01 << 30);
	
	// Clock enable for LPUART1
	PCC->LPUART1 |= (0x06 << 24);
	PCC->LPUART1 |= (0x01 << 30);
	
	//set bit 1 to SysTick uses the processor clock
	SYST->CSR |= (1<<2);
	//processor clock = 80000000 means that in 1 second the system timer will count 80000000 times, if you want to count 1ms, you will have to set 80000
	SYST->RVR = (80000000/1000) - 1;
	//SYST->CSR |= (0x03 << 0);
}

void SysTick_Handler(void)
{
	
}
