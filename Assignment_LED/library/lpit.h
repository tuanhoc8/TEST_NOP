/*
 * lpit.h
 *
 *  Created on: Oct 4, 2023
 *      Author: TIN
 */

#ifndef LPIT_H_
#define LPIT_H_

#include <stdint.h>

typedef struct
{
	volatile uint32_t	VERID; 		//	Version ID Register
	volatile uint32_t	PARAM; 		//	Parameter Register
	volatile uint32_t	MCR; 		//	Module Control Register
	volatile uint32_t	MSR; 		//	Module Status Register
	volatile uint32_t	MIER; 		//	Module Interrupt Enable Register
	volatile uint32_t	SETTEN;		//	Set Timer Enable Register
	volatile uint32_t	CLRTEN;		//	Clear Timer Enable Register
	volatile uint32_t	Reserve_1;	//
	volatile uint32_t	TVAL0;		//	Timer Value Register
	volatile uint32_t	CVAL0; 		//	Current Timer Value
	volatile uint32_t	TCTRL0;		//	Timer Control Register
	volatile uint32_t	Reserve_2;	//
	volatile uint32_t	TVAL1; 		//	Timer Value Register
	volatile uint32_t	CVAL1; 		//	Current Timer Value
	volatile uint32_t	TCTRL1;		//	Timer Control Register
	volatile uint32_t	Reserve_3;	//
	volatile uint32_t	TVAL2;		//	Timer Value Register
	volatile uint32_t	CVAL2;		//	Current Timer Value
	volatile uint32_t	TCTRL2;		//	Timer Control Register
	volatile uint32_t	Reserve_4;	//
	volatile uint32_t	TVAL3;		//	Timer Value Register
	volatile uint32_t	CVAL3;		//	Current Timer Value
	volatile uint32_t	TCTRL3;		//	Timer Control Register
}LPIT_Type;
#define LPIT_BASE	((uint32_t)0x40037000)
#define LPIT		((LPIT_Type*)LPIT_BASE)

void LPIT_config();
void LPIT_INTERRUPT_config();
void LPIT0_Ch0_IRQHandler (void);
#endif /* LPIT_H_ */
