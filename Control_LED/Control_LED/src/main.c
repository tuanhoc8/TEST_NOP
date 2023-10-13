#include "init.h"

volatile int8_t counter __attribute__((section(".new_variable")));
volatile uint16_t DELAY = 1000;

void blinkLed(void)__attribute__((section(".flash_blinkled")));
void blinkLed(void)
{
	for(;;)
	{
		GPIOD->PDOR = (1 << 0) | (1 << 16);
		delay_ms(DELAY);
		GPIOD->PDOR = (1 << 0) | (1 << 15);
		delay_ms(DELAY);
		GPIOD->PDOR = (1 << 15) | (1 << 16);
		delay_ms(DELAY);
	}
}

int main(void)
{
	DELAY = 1000;
	counter = 10;

	void (*function_pointer)(void);
	function_pointer = (void (*)(void))0x00002001;

	init_clock();
	init_gpio();
	init_lpit();
	init_lpuart1();

	function_pointer();
}
