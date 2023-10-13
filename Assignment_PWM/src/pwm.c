/*
 * pwm.c
 *
 *  Created on: Oct 9, 2023
 *      Author: TIN
 */
#include "ftm.h"
#include "scg.h"
#include "pcc.h"
#include "gpio.h"
#include "port.h"

#define sys_clock 8000000

void PWM_config(uint32_t duty_cycle, uint32_t PWM_freq)
{
	uint32_t mod_num;

	/* Enable clock for PORTD */
	PCC->PCC_PORTA = (1u << 30);
	/* Set PORTD pins for FTM0 */
	PORT_A->PORT_PCR[17] = (2U << 8); //Alternative 2, FTM0_CH6, Channel_6, PTA17

	/* Select and enable clock for FTM0 */
	PCC->PCC_FTM0 &= ~(1U << 30); //Disable CGC
	PCC->PCC_FTM0 |= (1u << 24); //Clock source SOSCDIV1
	PCC->PCC_FTM0 |= (1U << 30); //Enable CGC

	/* Disable FTM clock -> disable FTM counter*/
	FTM0->SC &= ~(3u << 3);

	/* Enable registers updating from write buffers */
	FTM0->MODE = (1u << 0);
	mod_num =  sys_clock/PWM_freq;
	/* Set Moduloin initialization stage(2kHz PWM frequency @8MHz system clock) */
	FTM0->MOD= (mod_num - 1); //gen 4kHz PWM from 8MHz SOSCDIV1
	/* Set CNTINin initialization stage*/
	FTM0->CNTIN= 0u;
	/* Enable high-true pulses of PWM signals */
	FTM0->CONTROLS[6].CnSC= ((1U << 5) | (1U << 3));
	/*Set channel value in initialization stage */
	FTM0->CONTROLS[6].CnV = (duty_cycle*(mod_num/100));
	/* Reset FTM counter */
	FTM0->CNT = 0;
	/* Clock selection and enabling PWM generation */
	FTM0->SC |= ((3u << 3) | (1u << 22));//[3]Source: external clock; [16] = Channel_0 PWM enable bit
}


/*
void pwm_config(void)
{
	PORTD->PCR[0] = PORT_PCR_MUX(2); // FTM0, Channel2
	PORTD->PCR[1] = PORT_PCR_MUX(2); // FTM0, Channel3
	//Enable registers updating from write buffers
	FTM0->MODE = 1u;
	//Set Modulo in initialization stage (19,5kHz PWM frequency @80MHz system clock)
	FTM0->MOD = FTM_MOD_MOD(4096-1); // 12bit D/A - 4096
	//Set CNTIN in initialization stage
	FTM0->CNTIN = 0;
	//Enable high-true pulses of PWM signals
	FTM0->CONTROLS[2].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	FTM0->CONTROLS[3].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	//Set channel value in initialization stage
	FTM0->CONTROLS[2].CnV=FTM_CnV_VAL(2048); // 50% duty cycle
	FTM0->CONTROLS[3].CnV=FTM_CnV_VAL(2048); // 50% duty cycle
	//Enable reload opportunity when FTM counter reach CNTMAX value
	FTM0->SYNC |= FTM_SYNC_CNTMAX_MASK;
	//Enable software synchronization
	FTM0->SYNCONF = FTM_SYNCONF_SYNCMODE_MASK | FTM_SYNCONF_SWWRBUF_MASK;
	//Enables PWM synchronization of registers C2V and C3V
	FTM0->COMBINE = FTM_COMBINE_SYNCEN1_MASK;
	//Reset FTM counter
	FTM0->CNT = 0;
	//Clock selection and enabling PWM generation
	FTM0->SC |= FTM_SC_CLKS(1) | FTM_SC_PWMEN2_MASK | FTM_SC_PWMEN3_MASK;
}
*/
