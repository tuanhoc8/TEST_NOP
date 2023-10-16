#include "interrupt.h"

uint8_t flag_LED=0;		// timer 0
uint8_t flag_BUTTON=0;		// PORT C
void LPIT0_Ch0_IRQHandler(void){
	flag_LED=ON;
	LPIT_T->MSR|=(1<<0);
}
void LPIT0_Ch1_IRQHandler(void){

	char str[5];
	changeToArrayChar(str,value);
//	sprintf(str,"%d",value);
	sendUart((uint8_t *)str,LPUART_1);
	sendUart((uint8_t *)"\n",LPUART_1);
	LPIT_T->MSR|=(1<<1);
}
void PORTC_IRQHandler(void){
	if(((PORT_C->PCR[BUTTON(1)]) & (1<<24))!=0){
		flag_BUTTON=BUTTON(1);
		value++;
		while(GPIO_ReadBits(GPIOC, BUTTON(1)));
		PORT_C->PCR[BUTTON(1)] |= (1U << 24);
	}
	else if(((PORT_C->PCR[BUTTON(2)]) & (1<<24))!=0){
		flag_BUTTON=BUTTON(2);
		while(GPIO_ReadBits(GPIOC, BUTTON(2)));
		value--;
		PORT_C->PCR[BUTTON(2)] |= (1U << 24);
	}
}
/*
* Function: changeToArrayChar
* Description: This function change the number to char array
* Input:
*   char str[5] the char array will take
*   int8_t number: number want to change
* Output:
*   the char array str
*/
void changeToArrayChar(char str[5],int8_t number){
	int8_t number_new=number;
    uint8_t i=0;
    if(number_new<0) {
        str[i]='-';i++;
        number_new=0-number_new;
    }
    if(number_new<10){
        str[i]='0'+number_new;i++;
        str[i]='\0';
    }
    else if(number_new<100){
        str[i]='0'+number_new/10;i++;
        str[i]=number_new%10+'0';i++;
        str[i]='\0';
    }
    else{
        str[i]='0'+number_new/100;i++;
        number_new%=100;
        str[i]='0'+number_new/10;i++;
        str[i]=number_new%10+'0';i++;
        str[i]='\0';
    }
}
void sendUart(uint8_t *data_TX,LPUART_Typedef *LPUART_x){
	for(uint8_t i=0;data_TX[i]!='\0';i++){
		while(!(LPUART_x->STAT & LPUART_STAT_TDRE));
		LPUART_x->DATA=data_TX[i];
	}
}
