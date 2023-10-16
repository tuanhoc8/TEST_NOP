#include "project.h"
#define MODE_2MHZ													2
#define MODE_4MHZ													4
#define BUTTON(X)                                                   (11+X)
uint8_t mode=MODE_2MHZ;
int8_t duty=5;
uint8_t flag_BUTTON=0;
char str[3];
void Project_Config(void){
	//SYS CLock
	//80MHZ Core   40MHz Bus  20Mhz Flash
	System_Clock_Out_Config(XTAL);
	
	//Clock GPIO
	
	
	//SET up MODE for GPIO
//	GPIO_Config_Mode(PORT_D,GPIOD,PIN(0)|PIN(15)|PIN(16),OUTPUT);
//	
	GPIO_Config_Mode(PORT_C,GPIOC,PIN(12)|PIN(13)|PIN(14),INPUT);
//	GPIO_SetBits(GPIOD,0,ON);
//	GPIO_SetBits(GPIOD,15,ON);
//	GPIO_SetBits(GPIOD,16,ON);
//	System_Tick_Config();
	
	//Setup LPIT
//	LPIT_Clock_Source();
//	LPIT_Config(0,1000,ON);
//	init_lpit(0);
	
	
	//setup for uart
	LPUART_Config(LPUART_1,PORT_C,6,7,ON);

//	
//	CLKOUT_Config(SIM_CHIPCTL_CLKOUTSEL_SPLLDIV2,PORT_E,10);	



	PWM_Config(FTM_0,PORT_B,12,13,14,15);
	PWM_Out();
//	Edge_Align_PWM_Config(FTM_0,PORT_B,12,13,14,15);
}
void Project_Do(void){
	
}
void ChangeDutyMode(void){
	if(flag_BUTTON==BUTTON(1)){
		duty++;
		if(duty>10) duty=10;
		sprintf(str,"%d",duty);
		sendUart((uint8_t *)"Muc duty: ",LPUART_1);
		sendUart((uint8_t *)str,LPUART_1);
		sendUart((uint8_t *)"\n",LPUART_1);
		flag_BUTTON=0;
		PWM_Out();
		//while(GPIO_ReadBits(GPIOC, BUTTON(1)));
	}
	if(flag_BUTTON==BUTTON(2)){
		duty--;
		if(duty<0) duty=0;
		sprintf(str,"%d",duty);
		sendUart((uint8_t *)"Muc duty: ",LPUART_1);
		sendUart((uint8_t *)str,LPUART_1);
		sendUart((uint8_t *)"\n",LPUART_1);
		flag_BUTTON=0;
		PWM_Out();
		//while(GPIO_ReadBits(GPIOC, BUTTON(2)));
	}
	if(flag_BUTTON==BUTTON(3)){
		duty=5;

		if(mode==MODE_2MHZ) {
			mode=MODE_4MHZ;
			sendUart((uint8_t *)"Change mode 4Mhz\n",LPUART_1);
		}
		else {
			mode=MODE_2MHZ;
			sendUart((uint8_t *)"Change mode 2Mhz\n",LPUART_1);
		}
		sprintf(str,"%d",duty);
		sendUart((uint8_t *)"Muc duty: ",LPUART_1);
		sendUart((uint8_t *)str,LPUART_1);
		sendUart((uint8_t *)"\n",LPUART_1);
		flag_BUTTON=0;
		PWM_Config(FTM_0,PORT_B,12,13,14,15);
		while(GPIO_ReadBits(GPIOC, BUTTON(3)));
		PWM_Out();
	}

}
void PWM_Out(void){
	if(duty==0){

		FTM_0->C1V=0;

	}
	else if(duty==10){
		FTM_0->C1V=FTM_0->MOD+1;
	}
	else{
		FTM_0->C1V=8000/10/mode*duty-1;

	}

}
void PORTC_IRQHandler(void){
	if(((PORT_C->PCR[BUTTON(1)]) & (1<<24))!=0){
		flag_BUTTON=BUTTON(1);
		PORT_C->PCR[BUTTON(1)] |= (1U << 24);
	}
	else if(((PORT_C->PCR[BUTTON(2)]) & (1<<24))!=0){
		flag_BUTTON=BUTTON(2);
		PORT_C->PCR[BUTTON(2)] |= (1U << 24);
	}
	else if(((PORT_C->PCR[BUTTON(3)]) & (1<<24))!=0){
		flag_BUTTON=BUTTON(3);
		PORT_C->PCR[BUTTON(3)] |= (1U << 24);
	}
}
void PWM_Config(FTM_Typedef *FTM_x,PORT_Typedef *PORT_x,uint8_t pin_channel0,uint8_t pin_channel1,uint8_t pin_channel2,uint8_t pin_channel3){

	PCC->FTM0 &= ~PCC_FTM_CGC;
	PCC->FTM0|=PCC_FTM_PCS_SIRCDIV1|PCC_FTM_CGC;
	FTM_x->SC &= ~(3<<3);


	FTM_x->MODE|=FTM_MODE_WPDIS;
	FTM_x->SC|=FTM_SC_PWMEN(0)|FTM_SC_PWMEN(1)|FTM_SC_PS(0);
	FTM_x->COMBINE=0;
	FTM_x->POL=0;
	FTM_x->MOD=8000/mode-1;//SET 2kHZ from 8MHz

	FTM_x->C0SC|=FTM_CnSC_MSB|FTM_CnSC_ELSB;
	FTM_x->C1SC|=FTM_CnSC_MSB|FTM_CnSC_ELSB;
	FTM_x->C2SC|=FTM_CnSC_MSB|FTM_CnSC_ELSB;
	FTM_x->C3SC|=FTM_CnSC_MSB|FTM_CnSC_ELSB;





	PORT_Config(PORT_x);
	PORT_x->PCR[pin_channel0]|=2<<8;
	PORT_x->PCR[pin_channel1]|=2<<8;
	PORT_x->PCR[pin_channel2]|=2<<8;
	PORT_x->PCR[pin_channel3]|=2<<8;
	FTM_x->SC|=FTM_SC_CLK_EXTERN_CLK;
	FTM_x->MODE &= ~FTM_MODE_WPDIS;
}
void LPIT0_Ch0_IRQHandler(void){


	LPIT_T->MSR|=(1<<0);
}
