#include "s32k144.h"
#include "project.h"
//#define LED_ON_ADDRESS				0xa004
//#define myfunc ((void (*)(void))	LED_ON_ADDRESS+1)
void LED_On(void)__attribute__ ((section(".flash_blinkled_section")));

void LED_On(void){
	while(1){
		if(flag_BUTTON==BUTTON(1)){
			counter++;
			count_LED++;
			flag_BUTTON=OFF;
		}
		else if(flag_BUTTON==BUTTON(2)){
			if (counter+TIME_LED_ORIGIN/TIMER_0>1)
				counter--;
			count_LED--;
			flag_BUTTON=OFF;
		}
		if(flag_LED){
			count_LED--;
			if(count_LED<=0){
				SetLED();
				led++;
				if(led>BLUE) led=RED;
				count_LED=counter+TIME_LED_ORIGIN/TIMER_0;
			}
			flag_LED=OFF;
		}
	}
}
int main(void){
	while(1){
		LED_On();
	}
}
