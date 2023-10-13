/*
 * scg.h
 *
 *  Created on: Sep 26, 2023
 *      Author: TIN
 */

#ifndef SCG_H_
#define SCG_H_

#include <stdint.h>

typedef struct
{
	volatile uint32_t VERID; 	   	 //Version ID Register
	volatile uint32_t PARAM; 		 //Parameter Register
	volatile uint32_t Res[2];
	volatile uint32_t CSR; 			 //Clock Status Register
	volatile uint32_t RCCR; 		 //Run Clock Control Register
	volatile uint32_t VCCR; 		 //VLPR Clock Control Register
	volatile uint32_t HCCR;			 //HSRUN Clock Control Register
	volatile uint32_t CLKOUTCNFG; 	 //SCG CLKOUT Configuration Register
	volatile uint32_t Res2[55];
	volatile uint32_t SOSCCSR; 		 //System OSC Control Status Register
	volatile uint32_t SOSCDIV;  	 //System OSC Divide Register
	volatile uint32_t SOSCCFG; 	     //System Oscillator Configuration Register
	volatile uint32_t Res3[61];
	volatile uint32_t SIRCCSR;  	 //Slow IRC Control Status Register
	volatile uint32_t SIRCDIV; 	 	 //Slow IRC Divide Register
	volatile uint32_t SIRCCFG; 		 //Slow IRC Configuration Register
	volatile uint32_t Res4[61]; //
	volatile uint32_t FIRCCSR; 		 //Fast IRC Control Status Register
	volatile uint32_t FIRCDIV;		 //Fast IRC Divide Register
	volatile uint32_t FIRCCFG; 	 	 //Fast IRC Configuration Register
	volatile uint32_t Res5[189]; 		 //308-600 m-> 600 - 30C = 2F4 -> 2F4/4 = BD(hex) = 189(dec)
	volatile uint32_t SPLLCSR;		 //System PLL Control Status Register
	volatile uint32_t SPLLDIV;		 //System PLL Divide Register
	volatile uint32_t SPLLCFG;		 //System PLL Configuration Register
}SCG_Type;
#define SCG_Base_ADD ((uint32_t) 0x40064000)
#define SCG			 ((SCG_Type*)SCG_Base_ADD)

void SCG_SOSC_80MHz_config(void);
void SCG_FIRC_80MHz_config(void);
void SCG_SOSC_24MHz_config(void);
void SCG_SOSC_8MHz_config(void);
void SCG_FIRC_48MHz_config(void);
#endif /* SCG_H_ */
