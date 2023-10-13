#include "gpio.h"
#include "lpuart.h"
#include "nvic.h"
#include "pcc.h"
#include "port.h"
#include "scg.h"
#include "systick.h"
#include "stdbool.h"
#include "string.h"

/* PROTOTYPE */
void periodic_LED(void);
void configure_BUTTON(void);
void configure_LED(void);
void hold_LED(void);
void int_to_char(uint32_t in_num);
void LPUART1_print_string(char output_str[]);

/* GLOBAL VARIABLES */
volatile bool BT1_flag = false;
volatile bool BT2_press_flag = false;
volatile bool BT2_release_flag = false;
static uint32_t current_LED_light = 15;
static uint32_t delay_time = 10;
static uint32_t counter_value = 10;
volatile uint32_t m_systick = 0;
char output_str[10];
static bool tick_delay = false;
static bool tick_500ms = false;
void SysTick_Handler(void)
{
	m_systick++; //100ms each time
	if (m_systick >= 0xFFFFFFFE)
	{
		m_systick = 0;
	}
	if(m_systick % delay_time == 0)
	{
		tick_delay = true;
	}
	if(m_systick % 5 == 0)
	{
		tick_500ms = true;
	}
}

int main(void)
{
	SCG_FIRC_48MHz_config();
	LPUART1_config();
	configure_BUTTON();
	configure_LED();
	SysTick_Setup();

	while (1)
	{
		if (BT2_press_flag == true)
		{
			hold_LED();
		}
		else
		{
			periodic_LED();
		}

		if(tick_500ms == true)
		{
			tick_500ms = false;

			strcpy(output_str, "count value: ");
			LPUART1_print_string(output_str);
			int_to_char(counter_value);
			LPUART1_print_string(output_str);

			strcpy(output_str, "\n");
			LPUART1_print_string(output_str);
		}
	}
	return 0;
}

void periodic_LED(void) __attribute__ ((section(".flash_blinkled")));
void periodic_LED(void)
{
	
	////Turn off all LED
	//GPIO_D->PDOR |= (1 << 15);  //disable LED 15 (RED)
	//GPIO_D->PDOR |= (1 << 16);  //disable LED 16 (GREEN)
	//GPIO_D->PDOR |= (1 << 0);  //disable LED 0 (BLUE)
	
	if (current_LED_light == 15 && BT2_press_flag == false)
	{
		current_LED_light = 15;
		GPIO_D->PDOR &= ~(1U << 15);  //enable LED 15 (RED)
		//delay(delay_time);
		if (tick_delay == true)
		{
			GPIO_D->PDOR |= (1 << 15);  //disable LED 15 (RED)
			current_LED_light = 16;
			tick_delay = false;
		}
		
	}
	
	if (current_LED_light == 16 && BT2_press_flag == false)
	{
		current_LED_light = 16;
		GPIO_D->PDOR &= ~(1U << 16);  //enable LED 16 (GREEN)
		//delay(delay_time);
		
		if (tick_delay == true)
		{
			GPIO_D->PDOR |= (1 << 16);  //disable LED 16 (GREEN)
			current_LED_light = 0;
			tick_delay = false;
		}
	}

	if (current_LED_light == 0 && BT2_press_flag == false)
	{
		current_LED_light = 0;
		GPIO_D->PDOR &= ~(1U << 0);  //enable LED 0 (BLUE)
		//delay(delay_time);
		
		if (tick_delay == true)
		{
			GPIO_D->PDOR |= (1 << 0);  //disable LED 0 (BLUE)
			current_LED_light = 15;
			tick_delay = false;
		}
	}
	
}

void hold_LED(void)
{
	if (current_LED_light == 15)
	{
		GPIO_D->PDOR &= ~(1U << 15);  //enable LED 15 (RED)
	}
	else if (current_LED_light == 16)
	{
		GPIO_D->PDOR &= ~(1U << 16);  //enable LED 16 (GREEN)
	}
	else if (current_LED_light == 0)
	{
		GPIO_D->PDOR &= ~(1U << 0);  //enable LED 16 (BLUE)
	}
}

void PORTC_IRQHandler(void)
{
	//check SW2 
	if (((PORT_C->PORT_PCR[12]) & (1 << 24)) != 0U)
	{
		PORT_C->PORT_PCR[12] |= (1 << 24);
		//BT1_flag = true;
		delay_time ++;
		counter_value ++;
	}

	//check SW3 
	if (((PORT_C->PORT_PCR[13]) & (1 << 24)) != 0U)
	{
		PORT_C->PORT_PCR[13] |= (1 << 24);
		if (((GPIO_C->PDIR) >> 13) == 1)
		{
			BT2_press_flag = true;
			BT2_release_flag = false;
		}
		if (((GPIO_C->PDIR) >> 13) == 0)
		{
			BT2_press_flag = false;
			BT2_release_flag = true;
			if (delay_time > 0 || counter_value > 0)
			{
				delay_time--;
				counter_value--;
			}
			else
			{
				delay_time = 0;
				counter_value = 0;
			}
			
		}
		
	}
}

void configure_BUTTON(void)
{
	
	NVIC_ISER1->SETENA_bits |= (1 << 29);
	PCC->PCC_PORTC |= (1 << 30);

	//Interrupt for sw3
	PORT_C->PORT_PCR[12] |= ((1 << 8) | (9 << 16));  //rising-edge = 9 // falling = 10
	GPIO_C->PDDR &= ~(1U << 12);

	//Interrupt for sw2
	PORT_C->PORT_PCR[13] |= ((1 << 8) | (11 << 16));  //either-edge
	GPIO_C->PDDR &= ~(1U << 13);
}

void configure_LED(void)
{
	//LED PTD15
	PCC->PCC_PORTD |= (1U << 30);
	PORT_D->PORT_PCR[15] |= ((1U << 8) | (1U << 1) | (0U << 0));
	GPIO_D->PDDR |= (1U << 15);

	//LED PTD16
	PORT_D->PORT_PCR[16] |= ((1U << 8) | (1U << 1) | (0U << 0));
	GPIO_D->PDDR |= (1U << 16);

	//LED PTD0
	PORT_D->PORT_PCR[0] |= ((1U << 8) | (1U << 1) | (0U << 0));
	GPIO_D->PDDR |= (1U << 0);

	//Turn off all LED
	GPIO_D->PDOR |= (1 << 15);  //disable LED 15 (RED)
	GPIO_D->PDOR |= (1 << 16);  //disable LED 16 (GREEN)
	GPIO_D->PDOR |= (1 << 0);  //disable LED 0 (BLUE)
}

void int_to_char(uint32_t in_num)
{
	memset(output_str, 0, 10);
	uint32_t count = 0, copy_num = in_num;
	while (copy_num != 0)
	{
		copy_num = copy_num / 10;
		count++;
	}
	for (uint32_t i = 1; i <= count; i++)
	{
		output_str[count - i] = (in_num % 10) + 48;
		in_num = in_num / 10;
	}
}

void LPUART1_print_string(char output_str[])
{
	uint32_t length = (uint32_t)strlen(output_str);
	for (uint32_t i = 0; i < length; i++)
	{
		//TRANSMIT DATA
		while (((UART1->STAT) & (1U << 23)) == 0) //[Send Data] Check the STAT(TDRE) == 0?
		{
		}
		UART1->DATA = output_str[i];
	}
}
