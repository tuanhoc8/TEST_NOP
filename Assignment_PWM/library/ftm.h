/*
 * ftm.h
 *
 *  Created on: Oct 6, 2023
 *      Author: TIN
 */

#ifndef FTM_H_
#define FTM_H_

#include "stdint.h"

/** FTM - Size of Registers Arrays */
#define FTM_CONTROLS_COUNT                       8u

typedef struct
{
	volatile	uint32_t		SC;						//	Status And Control
	volatile	uint32_t		CNT;					//	Counter
	volatile	uint32_t		MOD;					//	Modulo
	struct {                                            /* offset: 0xC, array step: 0x8 */
		volatile uint32_t CnSC;                         /**< Channel (n) Status And Control, array offset: 0xC, array step: 0x8 */
		volatile uint32_t CnV;                          /**< Channel (n) Value, array offset: 0x10, array step: 0x8 */
	} CONTROLS[FTM_CONTROLS_COUNT];
	/*
	volatile	uint32_t		C0SC;					//	Channel  Status And Control
	volatile	uint32_t		C0V;					//	Channel  Value
	volatile	uint32_t		C1SC;					//	Channel  Status And Control
	volatile	uint32_t		C1V;					//	Channel  Value
	volatile	uint32_t		C2SC;					//	Channel  Status And Control
	volatile	uint32_t		C2V;					//	Channel  Value
	volatile	uint32_t		C3SC;					//	Channel  Status And Control
	volatile	uint32_t		C3V;					//	Channel  Value
	volatile	uint32_t		C4SC;					//	Channel  Status And Control
	volatile	uint32_t		C4V;					//	Channel  Value
	volatile	uint32_t		C5SC;					//	Channel  Status And Control
	volatile	uint32_t		C5V;					//	Channel  Value
	volatile	uint32_t		C6SC;					//	Channel  Status And Control
	volatile	uint32_t		C6V;					//	Channel  Value
	volatile	uint32_t		C7SC;					//	Channel  Status And Control
	volatile	uint32_t		C7V;					//	Channel  Value
	*/
	volatile	uint32_t		CNTIN;					//	Counter Initial Value
	volatile	uint32_t		STATUS;					//	Capture And Compare Status
	volatile	uint32_t		MODE;					//	Features Mode Selection
	volatile	uint32_t		SYNC;					//	Synchronization
	volatile	uint32_t		OUTINIT;				//	Initial State For Channels Output
	volatile	uint32_t		OUTMASK;				//	Output Mask
	volatile	uint32_t		COMBINE;				//	Function For Linked Channels
	volatile	uint32_t		DEADTIME;				//	Deadtime Configuration
	volatile	uint32_t		EXTTRIG;				//	FTM External Trigger
	volatile	uint32_t		POL;					//	Channels Polarity
	volatile	uint32_t		FMS;					//	Fault Mode Status
	volatile	uint32_t		FILTER;					//	Input Capture Filter Control
	volatile	uint32_t		FLTCTRL;				//	Fault Control
	volatile	uint32_t		QDCTRL;					//	Quadrature Decoder Control And Status
	volatile	uint32_t		CONF;					//	Configuration
	volatile	uint32_t		FLTPOL;					//	FTM Fault Input Polarity
	volatile	uint32_t		SYNCONF;				//	Synchronization Configuration
	volatile	uint32_t		INVCTRL;				//	FTM Inverting Control
	volatile	uint32_t		SWOCTRL;				//	FTM Software Output Control
	volatile	uint32_t		PWMLOAD;				//	FTM PWM Load
	volatile	uint32_t		HCR;					//	Half Cycle Register
	volatile	uint32_t		PAIR0DEADTIME;			//Pair 0 Deadtime Configuration
	volatile	uint32_t		Reserve_1;
	volatile	uint32_t		PAIR1DEADTIME;			//Pair 1 Deadtime Configuration
	volatile	uint32_t		Reserve_2;
	volatile	uint32_t		PAIR2DEADTIME;			//Pair 2 Deadtime Configuration
	volatile	uint32_t		Reserve_3;
	volatile	uint32_t		PAIR3DEADTIME;			//Pair 3 Deadtime Configuration
	volatile	uint32_t		Reserve_4[51];
	volatile	uint32_t		MOD_MIRROR;				//Mirror of Modulo Value
	volatile 	uint32_t 		CnV_MIRROR[8];          //Mirror of Channel  Match Value
}FTM_Type;
#define FTM0_BASE	((uint32_t)0x40038000)
#define FTM1_BASE	((uint32_t)0x40039000)
#define FTM2_BASE	((uint32_t)0x4003A000)
#define FTM3_BASE	((uint32_t)0x40026000)
#define FTM4_BASE	((uint32_t)0x4006E000)
#define FTM5_BASE	((uint32_t)0x4006F000)
#define FTM6_BASE	((uint32_t)0x40070000)
#define FTM7_BASE	((uint32_t)0x40071000)
#define FTM0		((FTM_Type*)FTM0_BASE)
#define FTM1		((FTM_Type*)FTM1_BASE)
#define FTM2		((FTM_Type*)FTM2_BASE)
#define FTM3		((FTM_Type*)FTM3_BASE)
#define FTM4		((FTM_Type*)FTM4_BASE)
#define FTM5		((FTM_Type*)FTM5_BASE)
#define FTM6		((FTM_Type*)FTM6_BASE)
#define FTM7		((FTM_Type*)FTM7_BASE)

void PWM_config(uint32_t duty_cycle, uint32_t PWM_freq);
#endif /* FTM_H_ */
