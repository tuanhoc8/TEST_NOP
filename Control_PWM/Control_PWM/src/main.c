
/*______________________________MADE BY KHOA______________________________*/

#include "init.h"

int main(void)
{
	frezPWM = 4000 - 1;
	dutyCycle = 2000 - 1;

	init_clock();
	init_gpio();
	init_lpit();
	init_lpuart1();
	init_pwmch1();

	while(1)
	{

	}
}
