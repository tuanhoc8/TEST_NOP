#include "project.h"

int8_t counter __attribute__((section(".new_variable")));
Color_LED led=RED;
uint8_t count_LED;
int8_t value __attribute__((section(".new_variable")));
void Project_Config(void){



	//SYS CLock
	//80MHZ Core   40MHz Bus  20Mhz Flash
	System_Clock_Out_Config(XTAL);
	
	//Clock GPIO
	value=VALUE_INIT;
	counter=0;
	count_LED=TIME_LED_ORIGIN/TIMER_0;
	
	//SET up MODE for GPIO
	GPIO_Config_Mode(PORT_D,GPIOD,PIN(0)|PIN(15)|PIN(16),OUTPUT);
	GPIO_Config_Mode(PORT_E,GPIOE,PIN(10),OUTPUT);
	GPIO_Config_Mode(PORT_C,GPIOC,PIN(12)|PIN(13),INPUT);
	GPIO_SetBits(GPIOD,0,ON);
	GPIO_SetBits(GPIOD,15,ON);
	GPIO_SetBits(GPIOD,16,ON);
//	System_Tick_Config();
	
	//Setup LPIT
	LPIT_Clock_Source();
	LPIT_Config(0,TIMER_0,ON);
	LPIT_Config(1,TIMER_UART,ON);
	
	
	//setup for uart
	LPUART_Config(LPUART_1,PORT_C,6,7,ON);
//	
//	CLKOUT_Config(SIM_CHIPCTL_CLKOUTSEL_SPLLDIV2,PORT_E,10);	

}
void Project_Do(void){

}
void SetLED(void){
	switch(led){
		case RED:
			GPIO_SetBits(GPIOD,0, ON);
			GPIO_SetBits(GPIOD,15, OFF);
			GPIO_SetBits(GPIOD,16, ON);
			return;
		case GREEN:
			GPIO_SetBits(GPIOD,0, ON);
			GPIO_SetBits(GPIOD,15, ON);
			GPIO_SetBits(GPIOD,16, OFF);
			return;
		case BLUE:
			GPIO_SetBits(GPIOD,0, OFF);
			GPIO_SetBits(GPIOD,15, ON);
			GPIO_SetBits(GPIOD,16, ON);
			return;
	}
}

