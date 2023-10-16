#include "project.h"
#define MODE_2MHZ													2
#define MODE_4MHZ													4
#define BUTTON(X)                                                   (11+X)
#define TIME_SEND_CAN												2
#define ID_STOP														(0xD0<<18)
#define ID_RESET													(0xC0<<18)
#define DATA_ORDER													0x01
#define BUTTON_RESET												10
#define BUTTON_STOP													11
uint8_t mode=MODE_2MHZ;
int8_t duty=5;
uint8_t flag_BUTTON=0;
char str[3];
uint32_t  RxCODE;              /*< Received message buffer code 			*/
uint32_t  RxID;                /*< Received message ID 					*/
uint32_t  RxLENGTH;            /*< Recieved message number of data bytes 	*/
uint32_t  RxDATA[2];           /*< Received message data (2 words) 		*/
uint32_t  RxTIMESTAMP;         /*< Received message time 					*/
void Project_Config(void){
	//SYS CLock
	//80MHZ Core   40MHz Bus  20Mhz Flash
	System_Clock_Out_Config(XTAL);
	
	//Clock GPIO
	CAN_Init(FlexCAN_0, 10, PORT_E, 4, 5);
	
	//SET up MODE for GPIO
//	GPIO_Config_Mode(PORT_D,GPIOD,PIN(0)|PIN(15)|PIN(16),OUTPUT);
//	
	GPIO_Config_Mode(PORT_C,GPIOC,PIN(12)|PIN(13)|PIN(14),INPUT);
//	GPIO_SetBits(GPIOD,0,ON);
//	GPIO_SetBits(GPIOD,15,ON);
//	GPIO_SetBits(GPIOD,16,ON);
//	System_Tick_Config();
	
	//Setup LPIT
	LPIT_Clock_Source();
	LPIT_Config(0,1000,ON);
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
	if ((FlexCAN_0->IFLAG1 >> 4) & 1) {  /* If CAN 0 MB 4 flag is set (received msg), read MB4 */
		Can_Recieve_Reset_msg(FlexCAN_0);      /* Read message */

	}
	if ((FlexCAN_0->IFLAG1 >> 1) & 1) {  /* If CAN 0 MB 4 flag is set (received msg), read MB4 */
		Can_Recieve_Stop_msg(FlexCAN_0);      /* Read message */
	}
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
	else if(flag_BUTTON==BUTTON_STOP){
		duty=0;
		PWM_Disable(FTM_0, 1);
		PWM_Out();
		flag_BUTTON=0;
	}
	else if(flag_BUTTON==BUTTON_RESET){
		PWM_Config(FTM_0,PORT_B,12,13,14,15);
		mode=MODE_2MHZ;
		duty=5;
		PWM_Out();
		flag_BUTTON=0;
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

	Can_Transmit_msg(FlexCAN_0);
	LPIT_T->MSR|=(1<<0);
}
void Can_Transmit_msg(FlexCAN_Typedef *FlexCAN_x){
		/*! Assumption:
	 * =================================
	 * Message buffer CODE is INACTIVE
	 */
  FlexCAN_x->IFLAG1 = 0x00000001;	/* Clear CAN 0 MB 0 flag without clearing others*/

  FlexCAN_x->RAMn[ 0*MSG_BUF_SIZE + 2] = duty;	/* MB0 word 2: data word 0 */
  FlexCAN_x->RAMn[ 0*MSG_BUF_SIZE + 3] = 0x44556677; /* MB0 word 3: data word 1 */
//#ifdef NODE_A
//  FlexCAN_x->RAMn[ 0*MSG_BUF_SIZE + 1] = 0x15540000; /* MB0 word 1: Tx msg with STD ID 0x555 */
//#else
//  FlexCAN_x->RAMn[ 0*MSG_BUF_SIZE + 1] = 0x14440000; /* MB0 word 1: Tx msg with STD ID 0x511 */
//#endif
  FlexCAN_x->RAMn[ 0*MSG_BUF_SIZE + 1] = 0xA0<<18;
  FlexCAN_x->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x0C400000 | 8 << 16;
  	  	  	  	  	  	  	  	  	  	  	  	/* MB0 word 0: 								*/
                                                /* EDL,BRS,ESI=0: CANFD not used 				*/
                                                /* CODE=0xC: Activate msg buf to transmit 		*/
                                                /* IDE=0: Standard ID 							*/
                                                /* SRR=1 Tx frame (not req'd for std ID) 		*/
                                                /* RTR = 0: data, not remote tx request frame	*/
                                                /* DLC = 8 bytes 	*/
}
void Can_Recieve_Reset_msg(FlexCAN_Typedef *FlexCAN_x){
	/*! Receive msg from ID 0x556 using msg buffer 4
 * =============================================
 */


  RxCODE   = (FlexCAN_x->RAMn[ 4*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;	/* Read CODE field */
  RxID     = (FlexCAN_x->RAMn[ 4*MSG_BUF_SIZE + 1] & FlexCAN_WMBn_ID_ID);	/* Read ID 			*/
  RxLENGTH = (FlexCAN_x->RAMn[ 4*MSG_BUF_SIZE + 0] & FlexCAN_WMBn_CS_DLC);	/* Read Message Length */
  for (uint8_t j=0; j<2; j++)
  {  /* Read two words of data (8 bytes) */
    RxDATA[j] = FlexCAN_x->RAMn[ 4*MSG_BUF_SIZE + 2 + j];
  }
  if(RxDATA[0]==DATA_ORDER){
	  if(RxID==ID_RESET) flag_BUTTON=BUTTON_RESET;
	  if(RxID==ID_STOP) flag_BUTTON=BUTTON_STOP;
  }
//  RxTIMESTAMP = (FlexCAN_x->RAMn[ 0*MSG_BUF_SIZE + 0] & 0x000FFFF);
//  dummy = FlexCAN_x->TIMER;             /* Read TIMER to unlock message buffers */
  FlexCAN_x->IFLAG1 = 0x00000010;       /* Clear CAN 0 MB 4 flag without clearing others*/
}
void Can_Recieve_Stop_msg(FlexCAN_Typedef *FlexCAN_x){
	/*! Receive msg from ID 0x556 using msg buffer 4
 * =============================================
 */
  RxCODE   = (FlexCAN_x->RAMn[ 1*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;	/* Read CODE field */
  RxID     = (FlexCAN_x->RAMn[ 1*MSG_BUF_SIZE + 1] & FlexCAN_WMBn_ID_ID);	/* Read ID 			*/
  RxLENGTH = (FlexCAN_x->RAMn[ 1*MSG_BUF_SIZE + 0] & FlexCAN_WMBn_CS_DLC);	/* Read Message Length */
  for (uint8_t j=0; j<2; j++)
  {  /* Read two words of data (8 bytes) */
    RxDATA[j] = FlexCAN_x->RAMn[ 1*MSG_BUF_SIZE + 2 + j];
  }
  if(RxDATA[0]==DATA_ORDER){
	  if(RxID==ID_RESET) flag_BUTTON=BUTTON_RESET;
	  if(RxID==ID_STOP) flag_BUTTON=BUTTON_STOP;
  }
//  RxTIMESTAMP = (FlexCAN_x->RAMn[ 0*MSG_BUF_SIZE + 0] & 0x000FFFF);
//  dummy = FlexCAN_x->TIMER;             /* Read TIMER to unlock message buffers */
  FlexCAN_x->IFLAG1 = 0b10;       /* Clear CAN 0 MB 4 flag without clearing others*/
}
void PWM_Disable(FTM_Typedef *FTM_x,uint8_t channel){
	FTM_x->MODE|=FTM_MODE_WPDIS;
	FTM_x->SC &= ~FTM_SC_PWMEN(channel);
	FTM_x->MODE &= ~FTM_MODE_WPDIS;
}
