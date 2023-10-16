#include "function.h"
#define TIMEDELAY 4000
uint8_t size_RX=0;
char Data_RX={0};
static uint32_t count=0;
volatile static uint8_t status=0;
void GPIO_SetBits(GPIO_Typedef *GPIOx,uint8_t pin,uint8_t LEVEL){
	if(LEVEL==ON) GPIOx->PSOR|=PIN(pin);
	else GPIOx->PCOR|=PIN(pin);
}
uint8_t GPIO_ReadBits(GPIO_Typedef *GPIOx,uint8_t pin){
	if(GPIOx->PDIR & PIN(pin)) return ON;
	else return OFF;
}
void Delay_ms(uint32_t ms){
	count=ms;
	while(count>0);
	
}
void SysTick_Handler(void){
	count--;
}
void LPUART1_RxTx_IRQHandler(void){
	Data_RX=(LPUART_1->DATA & 0xff);
	if(Data_RX=='1'){
		GPIO_SetBits(GPIOD,0,ON);
		GPIO_SetBits(GPIOD,15,ON);
		GPIO_SetBits(GPIOD,16,ON);
	}
	else{
		GPIO_SetBits(GPIOD,0,OFF);
		GPIO_SetBits(GPIOD,15,OFF);
		GPIO_SetBits(GPIOD,16,OFF);
	}
	
}
void sendUart(uint8_t *data_TX,LPUART_Typedef *LPUART_x){
	for(uint8_t i=0;data_TX[i]!='\0';i++){
		while(!(LPUART_x->STAT & LPUART_STAT_TDRE));
		LPUART_x->DATA=data_TX[i];
	}
}

