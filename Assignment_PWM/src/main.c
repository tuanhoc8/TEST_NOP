/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "ftm.h"
#include "gpio.h"
#include "lpuart.h"
#include "nvic.h"
#include "pcc.h"
#include "port.h"
#include "scg.h"
#include "systick.h"
#include "stdbool.h"
#include "string.h"

void configure_BUTTON(void);
void configure_LED(void);
void External_BUTTON_config(void);
void int_to_char(uint32_t int_num);
void LPUART1_print_string(void);

char output_str[10];
volatile bool BT1_flag = false;
volatile bool BT2_flag = false;
volatile uint32_t BT3_count = 1;
static uint32_t PWM_freq = 2000;
static uint32_t duty = 50; //default duty cycle 50%
int main(void)
{
	SCG_SOSC_8MHz_FTM_config(); //SOSCDIV1 8MHz
	LPUART1_config();
	External_BUTTON_config();
	configure_BUTTON();
	PWM_config(duty, PWM_freq);
	while(1)
	{
		//CHECK EXTERNAL BUTTON IS PRESS
		if(((GPIO_D->PDIR)&(1<<1)) == 0)
		{
			//delay(1);
			BT3_count++;
			if(BT3_count%2 == 0)
			{
				duty = 50;
				PWM_freq = 4000; //PWM freq = 4KHz
				PWM_config(duty, PWM_freq);
			}
			else
			{
				duty = 50;
				PWM_freq = 2000; //PWM freq = 2KHz
				PWM_config(duty, PWM_freq);
			}
		}


		if (BT1_flag == true)
		{
			BT1_flag = false;

			if(duty < 10)
			{
				duty += 1;
			}

			duty += duty*0.1;

			if(duty <= 100)
			{
				duty = duty;
			}
			else
			{
				duty = 100;
			}

			PWM_config(duty, PWM_freq);
			int_to_char(duty);
			LPUART1_print_string();
		}
		if (BT2_flag == true)
		{
			BT2_flag = false;

			if(duty >= 0)
			{
				duty -= duty*0.1;
			}
			else
			{
				duty = 0;
			}
			PWM_config(duty, PWM_freq);
			int_to_char(duty);
			LPUART1_print_string();
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
	PORT_C->PORT_PCR[13] |= ((1 << 8) | (9 << 16));  //rising-edge
	GPIO_C->PDDR &= ~(1U << 13);
}

void External_BUTTON_config(void)
{
	PCC->PCC_PORTD |= (1 << 30);

	PORT_D->PORT_PCR[1] |= ((1 << 8)|(1u << 1)|(1u << 0));  //rising-edge = 9 // falling = 10, [1]Pull enable, [0]Pull select
	GPIO_D->PDDR &= ~(1U << 1);  //INPUT MODE

}
void PORTC_IRQHandler(void)
{
	//check SW2
	if (((PORT_C->PORT_PCR[12]) & (1 << 24)) != 0U)
	{
		PORT_C->PORT_PCR[12] |= (1 << 24);
		BT1_flag = true;

	}

	//check SW3
	if (((PORT_C->PORT_PCR[13]) & (1 << 24)) != 0U)
	{
		PORT_C->PORT_PCR[13] |= (1 << 24);
		BT2_flag = true;
	}
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

void int_to_char(uint32_t int_num)
{
	memset(output_str, 0, 10);
	if(int_num < 100)
	{
		output_str[0] = ((int_num/10)+48);
		output_str[1] = '.';
		output_str[2] = ((int_num%10)+48);
		output_str[3] = 10; //line feed
	}
	else
	{
		output_str[0] = 49;
		output_str[1] = 48;
		output_str[2] = 10;
	}
}

void LPUART1_print_string(void)
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
