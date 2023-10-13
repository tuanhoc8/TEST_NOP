#ifndef _S32K144_H_
#define _S32K144_H_

#include "stdint.h"

#define __IO 																	volatile							/* Read and Write*/
#define __I  																	volatile							/* Only Read*/
#define __O  																	volatile							/* Only Write*/
#define __ORI  																volatile							/* Write or Read*/	
#define EXTAL																	0
#define XTAL																	1
#define INPUT																	0
#define OUTPUT																1
#define OFF																		0
#define ON    																1


/***************************>>>ADDRESS<<<****************************************************************/
#define PCC_BASE_ADDRESS      								(0x40065080)
#define SCG_BASE_ADDRESS                      (0x40064000)
#define GPIOA_BASE_ADDRESS                    (0x400FF000)
#define GPIOB_BASE_ADDRESS                    (0x400FF040)
#define GPIOC_BASE_ADDRESS                    (0x400FF080)
#define GPIOD_BASE_ADDRESS                    (0x400FF0C0)
#define GPIOE_BASE_ADDRESS                    (0x400FF100)
#define PORTA_BASE_ADDRESS 		                (0x40049000)
#define PORTB_BASE_ADDRESS		                (0x4004A000)
#define PORTC_BASE_ADDRESS		                (0x4004B000)
#define PORTD_BASE_ADDRESS		                (0x4004C000)
#define PORTE_BASE_ADDRESS		                (0x4004D000)
#define NVIC_BASE_ADDRESS			                (0xE000E100)
#define SYS_TICK_BASE_ADDRESS                 (0xE000E010)
#define LPUART0_BASE_ADDRESS 									(0x4006A000)
#define LPUART1_BASE_ADDRESS 									(0x4006B000)
#define LPUART2_BASE_ADDRESS 									(0x4006C000)
#define LPIT_BASE_ADDRESS 										(0x40037000)
#define SIM_BASE_ADDRESS											(0x40048004)
#define LPSPI0_BASE_ADDRESS 									(0x4002C000)
#define LPSPI1_BASE_ADDRESS 									(0x4002D000)
#define LPSPI2_BASE_ADDRESS 									(0x4002E000)
#define LPI2C0_BASE_ADDRESS 									(0x40066000)
#define LPI2C1_BASE_ADDRESS 									(0x40067000)
#define FTM0_BASE_ADDRESS											(0x40038000)
#define FTM1_BASE_ADDRESS											(0x40039000)
#define FTM2_BASE_ADDRESS											(0x4003A000)
#define FTM3_BASE_ADDRESS											(0x40026000)
#define FTM4_BASE_ADDRESS											(0x4006E000)
#define FTM5_BASE_ADDRESS											(0x4006F000)
#define FTM6_BASE_ADDRESS											(0x40070000)
#define FTM7_BASE_ADDRESS											(0x40071000)










/** 
  * @brief Peripheral Clock Controller 
  */
typedef struct {
	__IO uint32_t FTFC; 						/*!< PCC FTFC     Register  ,                                  Address offset: 0x80h */
	__IO uint32_t DMAMUX;						/*!< PCC DMAMUX   Register  ,                                  Address offset: 0x84h */
	volatile uint32_t Reserved[2];
	__IO uint32_t FlexCAN0;					/*!< PCC FlexCAN0 Register  ,                                  Address offset: 0x90h */
	__IO uint32_t FlexCAN1;					/*!< PCC FlexCAN1 Register  ,                                  Address offset: 0x94h */
	__IO uint32_t FTM3;							/*!< PCC FTM3     Register  ,                                  Address offset: 0x98h */
	__IO uint32_t ADC1;							/*!< PCC ADC1     Register  ,                                  Address offset: 0x9Ch */
	volatile uint32_t Reserved1[3];			
	__IO uint32_t FlexCAN2;					/*!< PCC FlexCAN2 Register  ,                                  Address offset: 0xACh */
	__IO uint32_t LPSPI0;						/*!< PCC LPSPI0   Register  ,                                  Address offset: 0xB0h */
	__IO uint32_t LPSPI1;						/*!< PCC LPSPI1   Register  ,                                  Address offset: 0xB4h */
	__IO uint32_t LPSPI2;						/*!< PCC LPSPI2   Register  ,                                  Address offset: 0xB8h */
	volatile uint32_t Reserved2[2];			
	__IO uint32_t PDB1;							/*!< PCC PDB1     Register  ,                                  Address offset: 0xC4h */
	__IO uint32_t CRC;							/*!< PCC CRC      Register  ,                                  Address offset: 0xC8h */
	volatile uint32_t Reserved3[3];			
	__IO uint32_t PDB0;							/*!< PCC PDB0     Register  ,                                  Address offset: 0xD8h */
	__IO uint32_t LPIT;							/*!< PCC LPIT     Register  ,                                  Address offset: 0xDCh */
	__IO uint32_t FTM0;							/*!< PCC FTM0     Register  ,                                  Address offset: 0xE0h */
	__IO uint32_t FTM1;							/*!< PCC FTM1     Register  ,                                  Address offset: 0xE4h */
	__IO uint32_t FTM2;							/*!< PCC FTM2     Register  ,                                  Address offset: 0xE8h */
	__IO uint32_t ADC0;							/*!< PCC ADC0     Register  ,                                  Address offset: 0xECh */
	volatile uint32_t Reserved4[1];
	__IO uint32_t RTC;							/*!< PCC RTC      Register  ,                                  Address offset: 0xF4h */
	volatile uint32_t Reserved5[2];
	__IO uint32_t LPTMR0;						/*!< PCC LPTMR0   Register  ,                                  Address offset: 0x100h */
	volatile uint32_t Reserved6[8];
	__IO uint32_t PORTA;						/*!< PCC PORTA    Register  ,                                  Address offset: 0x124h */
	__IO uint32_t PORTB;						/*!< PCC PORTB    Register  ,                                  Address offset: 0x128h */
	__IO uint32_t PORTC;						/*!< PCC PORTC    Register  ,                                  Address offset: 0x12Ch */
	__IO uint32_t PORTD;						/*!< PCC PORTD    Register  ,                                  Address offset: 0x130h */
	__IO uint32_t PORTE;						/*!< PCC PORTE    Register  ,                                  Address offset: 0x134h */
	volatile uint32_t Reserved7[6];
	__IO uint32_t SAI0;							/*!< PCC SAI0     Register  ,                                  Address offset: 0x150h */
	__IO uint32_t SAI1;							/*!< PCC SAI1     Register  ,                                  Address offset: 0x154h */
	volatile uint32_t Reserved8[4];
	__IO uint32_t FlexIO;						/*!< PCC FlexIO   Register  ,                                  Address offset: 0x168h */
	volatile uint32_t Reserved10[6];
	__IO uint32_t EWM;							/*!< PCC EWM      Register  ,                                  Address offset: 0x184h */
	volatile uint32_t Reserved11[4];
	__IO uint32_t LPI2C0;						/*!< PCC LPI2C0   Register  ,                                  Address offset: 0x198h */
	__IO uint32_t LPI2C1;						/*!< PCC LPI2C1   Register  ,                                  Address offset: 0x19Ch */
	volatile uint32_t Reserved12[2];
	__IO uint32_t LPUART0;					/*!< PCC LPUART0  Register  ,                                  Address offset: 0x1A8h */
	__IO uint32_t LPUART1;					/*!< PCC LPUART1  Register  ,                                  Address offset: 0x1ACh */
	__IO uint32_t LPUART2;					/*!< PCC LPUART2  Register  ,                                  Address offset: 0x1B0h */
	volatile uint32_t Reserved13;
	__IO uint32_t FTM4;							/*!< PCC FTM4     Register  ,                                  Address offset: 0x1B8h */
	__IO uint32_t FTM5;							/*!< PCC FTM5     Register  ,                                  Address offset: 0x1BCh */
	__IO uint32_t FTM6;							/*!< PCC FTM6     Register  ,                                  Address offset: 0x1C0h */
	__IO uint32_t FTM7;							/*!< PCC FTM7     Register  ,                                  Address offset: 0x1C4h */
	volatile uint32_t Reserved14;
	__IO uint32_t CMP0;							/*!< PCC CMP0     Register  ,                                  Address offset: 0x1CCh */
	volatile uint32_t Reserved15[2];
	__IO uint32_t QSPI;							/*!< PCC QSPI     Register  ,                                  Address offset: 0x1D8h */
	volatile uint32_t Reserved16[2];
	__IO uint32_t ENET;							/*!< PCC ENET     Register  ,                                  Address offset: 0x1E4h */
}PCC_Typedef;


/** 
  * @brief System Clock Generator
  */
typedef struct 
{
	__I uint32_t VERID;							/*!< SCG FTFC     Version ID Register  ,                       Address offset: 0x0h */
	__I uint32_t PARAM;							/*!< SCG PARAM    Parameter Register   ,                       Address offset: 0x4h */
	volatile uint32_t Reserved1[2];
	__I uint32_t CSR;								/*!< SCG CSR      Clock Status Register,                       Address offset: 0x10h */
	__IO uint32_t RCCR;							/*!< SCG RCCR     Run Clock Control Register ,                 Address offset: 0x14h */
	__IO uint32_t VCCR;							/*!< SCG VCCR     VLPR Clock Control Register,                 Address offset: 0x18h */
	__IO uint32_t HCCR;							/*!< SCG HCCR     HSRUN Clock Control Register,                Address offset: 0x1Ch */
	__IO uint32_t CLKOUTCNFG;				/*!< CLKOUTCNFG   Configuration Register  ,                    Address offset: 0x20h */
	volatile uint32_t Reserved2[55];
	__IO uint32_t SOSCCSR;					/*!< SCG SOSCCSR  Control Status Register ,                    Address offset: 0x100h */
	__IO uint32_t SOSCDIV;					/*!< SCG SOSCDIV  Divide Register ,                            Address offset: 0x104h */
	__IO uint32_t SOSCCFG;					/*!< SCG SOSCCFG  System Oscillator Configuration Register ,   Address offset: 0x108h */
	volatile uint32_t Reserved3[61];
	__IO uint32_t SIRCCSR;					/*!< SCG SIRCCSR  Slow IRC Control Status Register  ,          Address offset: 0x200h */
	__IO uint32_t SIRCDIV;					/*!< SCG SIRCDIV  Slow IRC Divide Register,                    Address offset: 0x204h */
	__IO uint32_t SIRCCFG;					/*!< SCG SIRCCFG  Slow IRC Configuration Register ,            Address offset: 0x208h */
	volatile uint32_t Reserved4[61];
	__IO uint32_t FIRCCSR;					/*!< SCG FIRCCSR  Fast IRC Control Status Register,            Address offset: 0x300h */
	__IO uint32_t FIRCDIV;					/*!< SCG FIRCDIV  Fast IRC Divide Register,                    Address offset: 0x304h */
	__IO uint32_t FIRCCFG;					/*!< SCG FIRCCFG  Fast IRC Configuration Register,             Address offset: 0x308h */
	volatile uint32_t Reserved5[189];
	__IO uint32_t SPLLCSR;					/*!< SCG SPLLCSR  System PLL Control Status Register,          Address offset: 0x600h */
	__IO uint32_t SPLLDIV;					/*!< SCG SPLLDIV  System PLL Divide Register  ,                Address offset: 0x604h */
	__IO uint32_t SPLLCFG;					/*!< SCG SPLLCFG  System PLL Configuration Register,           Address offset: 0x608h */
}	SCG_Typedef;

/** 
  * @brief GPIO
  */
typedef struct{
	volatile uint32_t PDOR; // Offset 0x00 - Port Data Output Register
	volatile uint32_t PSOR; // Offset 0x04 - Port Set Output Register
	volatile uint32_t PCOR; // Offset 0x08 - Port Clear Output Register
	volatile uint32_t PTOR; // Offset 0x0C - Port Toggle Output Register
	volatile uint32_t PDIR; // Offset 0x10 - Port Data Input Register
	volatile uint32_t PDDR; // Offset 0x14 - Port Data Direction Register
	volatile uint32_t PIDR; // Offset 0x18 - Port Input Disable Register
}GPIO_Typedef;


/** 
  * @brief PORT
  */
typedef struct
{
	__IO uint32_t PCR[32];			// Offset 0x00 - Pin Control Register
	__O uint32_t GPCLR;					// Offset 0x80 - Global Pin Control Low Register
	__O uint32_t GPCHR;					// Offset 0x84 - Global Pin Control High Register
	__O uint32_t GICLR;					// Offset 0x88 - Global Interrupt Control Low Register
	__O uint32_t GICHR;					// Offset 0x8C - Global Interrupt Control HIGH Register	
	volatile uint32_t Reserved1[4];			//
	__O uint32_t ISFR;					// Offset 0xA0 - Interrupt Status Flag Register
	volatile uint32_t Reserved2[7];
	__ORI uint32_t DFER;				// Offset 0xC0 - Digital Filter Enable Register
	__IO uint32_t DFCR;					// Offset 0xC4 - Digital Filter Clock Register
	__IO uint32_t DFWR;					// Offset 0xC8 - Digital Filter Width Register
}	PORT_Typedef;

/** 
  * @brief NVIC
  */

typedef struct
{
	__IO uint32_t ISER[8];
	volatile uint32_t res1[24];
	__IO uint32_t ICER[8];
	volatile uint32_t res2[24];
	__IO uint32_t ISPR[8];
	volatile uint32_t res3[24];
	__IO uint32_t ICPR[8];
	 uint32_t res4[24];
	__I uint32_t IABR[8];
	volatile uint32_t res5[56];
	__IO uint32_t IPR[60];
	volatile uint32_t res6[644];
//	volatile uint32_t STIR;
} NVIC_Typedef;

/** 
  * @brief SYSTICKS
  */
typedef struct 
{
	__IO uint32_t CSR;																	
	__IO uint32_t RVR;
	__IO uint32_t CVR;
	__I  uint32_t CALIB;
}	SysTick_Typedef;

/** 
  * @brief LPUART
  */

typedef struct 
{
	__I uint32_t VERID;
	__I uint32_t PARAM;
	__IO uint32_t GLOBAL;
	__IO uint32_t PINCFG;
	__IO uint32_t BAUD;
	__IO uint32_t STAT;
	__IO uint32_t CTRL;
	__IO uint32_t DATA;
	__IO uint32_t MATCH;
	__IO uint32_t MODIR;
	__IO uint32_t FIFO;
	__IO uint32_t WATER;
}	LPUART_Typedef;

/** 
  * @brief LPIT
  */

typedef struct 
{
	__I uint32_t VERID;																	/*Version ID Register (VERID)																		0h*/
	__I uint32_t PARAM;																	/*Parameter Register (PARAM)																		4h*/
	__IO uint32_t MCR;																	/*Module Control Register (MCR)																	8h*/
	volatile uint32_t MSR;															/*Module Status Register (MSR)																	Ch*/
	__IO uint32_t MIER;															    /*Module Interrupt Enable Register (MIER)												10h*/
	__IO uint32_t SETTEN;															  /*Set Timer Enable Register (SETTEN)			       								14h*/
	volatile uint32_t CLRTEN;														/*Clear Timer Enable Register (CLRTEN)			       							18h*/
	 uint32_t Reserved1;
	__IO uint32_t TVAL0;																/*Timer Value Register TVAL0																		20h*/
	__I uint32_t CVAL0;																	/*Current Timer Value (CVAL0																		24h*/
	__IO uint32_t TCTRL0;																/*Timer Control Register (TCTRL0 																28h*/
	volatile uint32_t Reserved2;
	__IO uint32_t TVAL1;																/*Timer Value Register TVAL1																		30h*/
	__I uint32_t CVAL1;																	/*Current Timer Value (CVAL1																		34h*/
	__IO uint32_t TCTRL1;																/*Timer Control Register (TCTRL1 																38h*/
	volatile uint32_t Reserved3;
	__IO uint32_t TVAL2;																/*Timer Value Register TVAL2																		40h*/
	__IO uint32_t CVAL2;																/*Current Timer Value (CVAL2																		44h*/
	__I uint32_t TCTRL2;																/*Timer Control Register (TCTRL2 																48h*/
	volatile uint32_t Reserved4;
	__IO uint32_t TVAL3;																/*Timer Value Register TVAL3																		50h*/
	__I uint32_t CVAL3;																  /*Current Timer Value (CVAL3																		54h*/
	__IO uint32_t TCTRL3;																/*Timer Control Register (TCTRL3 																58h*/
}	LPIT_Typedef;


/** 
  * @brief SIM
  */
typedef struct{
	__IO uint32_t CHIPCTL; 								/*Chip Control register															 4h*/
	volatile uint32_t Reserved0;						
	__IO uint32_t FTMOPT0;								/*Chip FTM Option Register													 Ch*/
	__IO uint32_t LPOCLKS;								/*Chip LPO CLOCK Select Register			 							10h*/
	volatile uint32_t Reserved1;
	__IO uint32_t ADCOPT;									/*Chip ADC OPtion Register						 							18h*/
	__IO uint32_t FMOPT1;									/*Chip FTM Option Register 1					 							1Ch*/
	__IO uint32_t MISCTRL0;								/*Chip Miscellaneous control register 0							20h*/
	__IO uint32_t SDID;										/*System Device Identification Register						  24h*/
	volatile uint32_t Reserved2[6];
	__IO uint32_t PLATCGC;								/*Platform Clock Gating Control Register            40h*/
	volatile uint32_t Reserved3[2];
	__IO uint32_t FCFG1;									/*Flash Configuration Register 1										4Ch*/
	volatile uint32_t Reserved4;
	__I uint32_t UIDH;										/*Unique Identification Register High								54Ch*/
	__I uint32_t UIDMH;										/*Unique Identification Register Medium High        58Ch*/
	__I uint32_t UIDML;										/*Unique Identification Register Medium LOW         5CCh*/
	__I uint32_t UIDL;										/*Unique Identification Register Low                60Ch*/
	volatile uint32_t Reserved5;
	__IO uint32_t CLKDIV4;								/*System Clock Divider Register 4						        68Ch*/
	__IO uint32_t MISCTRL1;               /*Miscellaneous Control register 1 						      6CCh*/
}SIM_Typedef;




/** 
  * @brief LPSPI
  */


typedef struct LPSPI_T
{
	volatile uint32_t VERID;
	volatile uint32_t PARAM;
	volatile uint32_t Reserved1[2];
	volatile uint32_t CR;
	volatile uint32_t SR;
	volatile uint32_t IER;
	volatile uint32_t DER;
	volatile uint32_t CFGR0;
	volatile uint32_t CFGR1;
	volatile uint32_t Reserved2[2];
	volatile uint32_t DMR0;
	volatile uint32_t DMR1;
	volatile uint32_t Reserved3[2];
	volatile uint32_t CCR;
	volatile uint32_t Reserved4[5];
	volatile uint32_t FCR;
	volatile uint32_t FSR;
	volatile uint32_t TCR;
	volatile uint32_t TDR;
	volatile uint32_t Reserved5[2];
	volatile uint32_t RSR;
	volatile uint32_t RDR;
}	LPSPI_Typedef;








/** 
  * @brief LPI2C
  */

typedef struct 
{
	__I uint32_t VERID;																						/*Version ID Register (VERID)																		0h*/
	__I uint32_t PARAM;																						/*Parameter Register (PARAM)																		4h*/
	volatile uint32_t Reserved1[2];
	__IO uint32_t MCR;																						/*Master Control Register (MCR)																	10h*/
	volatile uint32_t MSR;																				/*Master Status Register (MSR)																	14h*/
	__IO uint32_t MIER;																						/*Master Interrupt Enable Register (MIER)												18h*/
	__IO uint32_t MDER;																						/*Master DMA Enable Register (MDER)															1Ch*/
	__IO uint32_t MCFGR0;																					/*Master Configuration Register 0 (MCFGR0)											20h*/
	__IO uint32_t MCFGR1;																					/*Master Configuration Register 1 (MCFGR0)											24h*/
	__IO uint32_t MCFGR2;																					/*Master Configuration Register 2 (MCFGR0)											28h*/
	__IO uint32_t MCFGR3;																					/*Master Configuration Register 3 (MCFGR0)											2Ch*/
	volatile uint32_t Reserved2[4];
	__IO uint32_t MDMR;																						/*Master Data Match Register (MDMR)															40h*/
	volatile uint32_t Reserved3[1];
	__IO uint32_t MCCR0;																					/*Master Clock Configuration Register 0 (MCCR0)									48h*/
	volatile uint32_t Reserved4[1];
	__IO uint32_t MCCR1;																					/*Master Clock Configuration Register 1 (MCCR0)									50h*/																	
	volatile uint32_t Reserved5[1];
	__IO uint32_t MFCR;																						/*Master FIFO Control Register (MFCR)														58h*/
	__I uint32_t MFSR;																						/*Master FIFO Status Register (MFSR)														5Ch*/
	__O uint32_t MTDR;																						/*Master Transmit Data Register (MTDR)													60h*/
	volatile uint32_t Reserved6[3];
	__I uint32_t MRDR;																						/*Master Receive Data Register (MRDR)														70h*/
	volatile uint32_t Reserved7[39];
	__IO uint32_t SCR;																						/*Slave Control Register (SCR)																	110h*/
	volatile uint32_t SSR;																				/*Slave Status Register (SSR)																		114h*/
	__IO uint32_t SIER;																						/*Slave Interrupt Enable Register (SIER)												118h*/
	__IO uint32_t SDER;																						/*Slave DMA Enable Register (SDER)															11Ch*/
	volatile uint32_t Reserved8[1];
	__IO uint32_t SCFGR1;																					/*Slave Configuration Register 1 (SCFGR1)												124h*/
	__IO uint32_t SCFGR2;																					/*Slave Configuration Register 2 (SCFGR2)												128h*/
	volatile uint32_t Reserved9[5];
	__IO uint32_t SAMR;																						/*Slave Address Match Register (SAMR)														140h*/
	volatile uint32_t Reserved10[3];
	__I uint32_t SASR;																						/*Slave Address Status Register (SASR)													150h*/
	__IO uint32_t STAR;																						/*Slave Transmit ACK Register (STAR)														154h*/
	volatile uint32_t Reserved11[2];
	__O uint32_t STDR;																						/*Slave Transmit Data Register (STDR)														160h*/
	volatile uint32_t Reserved12[3];
	__I uint32_t SRDR;																						/*Slave Receive Data Register (SRDR)														170h*/
}	LPI2C_Typedef;



/** 
  * @brief FTM
  */
typedef struct{
	__IO uint32_t SC;																							/*Status and control (SC)																				0h*/		
	__IO uint32_t CNT; 																						/*Counter(CNT)																									4h*/
	__IO uint32_t MOD;																						/*Modulo (MOD)																									8h*/
	__IO uint32_t C0SC;																						/*Channel (0) status and Control (C0SC)													Ch*/
	__IO uint32_t C0V;																						/*Channel (0) value C0V																				  10h*/
	__IO uint32_t C1SC;																						/*Channel (1) status and Control (C1SC)													14h*/
	__IO uint32_t C1V;																						/*Channel (1) value C0V																				  18h*/
	__IO uint32_t C2SC;																						/*Channel (2) status and Control (C1SC)													1Ch*/
	__IO uint32_t C2V;																						/*Channel (2) value C0V																				  20h*/
	__IO uint32_t C3SC;																						/*Channel (3) status and Control (C1SC)													24h*/
	__IO uint32_t C3V;																						/*Channel (3) value C0V																				  28h*/
	__IO uint32_t C4SC;																						/*Channel (4) status and Control (C1SC)													2Ch*/
	__IO uint32_t C4V;																						/*Channel (4) value C0V																				  30h*/
	__IO uint32_t C5SC;																						/*Channel (5) status and Control (C1SC)													34h*/
	__IO uint32_t C5V;																						/*Channel (5) value C0V																				  38h*/
	__IO uint32_t C6SC;																						/*Channel (6) status and Control (C1SC)													3Ch*/
	__IO uint32_t C6V;																						/*Channel (6) value C0V																				  40h*/
	__IO uint32_t C7SC;																						/*Channel (7) status and Control (C1SC)													44h*/
	__IO uint32_t C7V;																						/*Channel (7) value C0V																				  48h*/
	__IO uint32_t CNTIN;																					/*Counter Initial Value(CNTIN)																	4Ch*/
	__IO uint32_t STATUS;																					/*Captuure AND COMPARE STATUS (STATUS)													50h*/
	__IO uint32_t MODE;																						/*Feature Mode Selection (MODE)																	54h*/
	__IO uint32_t SYNC;																						/*Synchronization																								58h*/
	__IO uint32_t OUTINIT;																				/*Initial State For Channels Output (OUTINIT) 									5Ch*/
	__IO uint32_t OUTMASK;																				/*Output Mask (OUTMASK) 																				60h*/
	__IO uint32_t COMBINE;																				/*Function For Linked Channels (COMBINE)                        64h*/
	__IO uint32_t DEADTIME;																				/*Deadtime Configuration (DEADTIME) 														68h*/
	__IO uint32_t EXTTRIG;																				/*FTM External Trigger (EXTTRIG) 																6Ch*/
	__IO uint32_t POL;																						/*Channels Polarity (POL)																				70h*/
	__IO uint32_t FMS;																						/*Fault Mode Status (FMS)																				74h*/
	__IO uint32_t FILTER;																					/*Input Capture Filter Control (FILTER)													78h*/
  __IO uint32_t FLTCTRL;																				/*Fault Control (FLTCTRL)                                       7Ch*/
	__IO uint32_t QDCTRL;																					/*Quadrature Decoder Control And Status (QDCTRL)								80h*/
  __IO uint32_t CONF;																						/*Configuration (CONF)																					84h*/
	__IO uint32_t FLTPOL;																					/*FTM Fault Input Polarity (FLTPOL)															88h*/
  __IO uint32_t SYNCONF;																				/*Synchronization Configuration (SYNCONF)												8Ch*/
	__IO uint32_t INVCTRL;																				/*FTM Inverting Control (INVCTRL)																90h*/
  __IO uint32_t SWOCTRL;																				/*FTM Software Output Control (SWOCTRL)													94h*/
	__IO uint32_t PWMLOAD;																				/*FTM PWM Load (PWMLOAD)                                        98h*/
	__IO uint32_t HCR;                                            /*Half Cycle Register (HCR) 																		9Ch*/
	__IO uint32_t PAIR0DEADTIME;                                  /*Pair 0 Deadtime Configuration (PAIR0DEADTIME) 								A0h*/
	volatile uint32_t Rev0;
	__IO uint32_t PAIR1DEADTIME;                                  /*Pair 0 Deadtime Configuration (PAIR0DEADTIME) 								A8h*/
	volatile uint32_t Rev1;
	__IO uint32_t PAIR2DEADTIME;                                  /*Pair 0 Deadtime Configuration (PAIR0DEADTIME) 								B0h*/
	volatile uint32_t Rev2;
	__IO uint32_t PAIR3DEADTIME;                                  /*Pair 0 Deadtime Configuration (PAIR0DEADTIME) 								B8h*/
	volatile uint32_t Rev3[81];
	__IO uint32_t MOD_MIRROR;                                     /*Mirror of Modulo Value (MOD_MIRROR) 													200h*/
	__IO uint32_t C0V_MIRROR;																			/*Mirror of Channel (0) Match Value (C0V_MIRROR) 								204h*/
	__IO uint32_t C1V_MIRROR;																			/*Mirror of Channel (1) Match Value (C0V_MIRROR) 								208h*/
	__IO uint32_t C2V_MIRROR;																			/*Mirror of Channel (2) Match Value (C0V_MIRROR) 								20Ch*/
	__IO uint32_t C3V_MIRROR;																			/*Mirror of Channel (3) Match Value (C0V_MIRROR) 								210h*/
	__IO uint32_t C4V_MIRROR;																			/*Mirror of Channel (4) Match Value (C0V_MIRROR) 								214h*/
	__IO uint32_t C5V_MIRROR;																			/*Mirror of Channel (5) Match Value (C0V_MIRROR) 								218h*/
	__IO uint32_t C6V_MIRROR;																			/*Mirror of Channel (6) Match Value (C0V_MIRROR) 								21Ch*/
	__IO uint32_t C7V_MIRROR;																			/*Mirror of Channel (7) Match Value (C0V_MIRROR) 								220h*/
	
 




	

	

	


	

	







 

}FTM_Typedef;




// Define the Register
#define PCC 											((PCC_Typedef *) PCC_BASE_ADDRESS)
#define SCG 											((SCG_Typedef *) SCG_BASE_ADDRESS)
#define GPIOA											((GPIO_Typedef *) GPIOA_BASE_ADDRESS)
#define GPIOB											((GPIO_Typedef *) GPIOB_BASE_ADDRESS)
#define GPIOC											((GPIO_Typedef *) GPIOC_BASE_ADDRESS)
#define GPIOD											((GPIO_Typedef *) GPIOD_BASE_ADDRESS)
#define GPIOE											((GPIO_Typedef *) GPIOE_BASE_ADDRESS)
#define PORT_A										((PORT_Typedef *) PORTA_BASE_ADDRESS)
#define PORT_B										((PORT_Typedef *) PORTB_BASE_ADDRESS)
#define PORT_C										((PORT_Typedef *) PORTC_BASE_ADDRESS)
#define PORT_D										((PORT_Typedef *) PORTD_BASE_ADDRESS)
#define PORT_E										((PORT_Typedef *) PORTE_BASE_ADDRESS)
#define PIN(X)										(1<<X)
#define NVIC											((NVIC_Typedef *) NVIC_BASE_ADDRESS)
#define SYSTICK							   		((SysTick_Typedef *)SYS_TICK_BASE_ADDRESS)
#define LPUART_0									((LPUART_Typedef *)LPUART0_BASE_ADDRESS)
#define LPUART_1									((LPUART_Typedef *)LPUART1_BASE_ADDRESS)
#define LPUART_2									((LPUART_Typedef *)LPUART2_BASE_ADDRESS)
#define LPIT_T										((LPIT_Typedef *)LPIT_BASE_ADDRESS)
#define SIM												((SIM_Typedef *)SIM_BASE_ADDRESS)
#define LPSPI_0										((LPSPI_Typedef *)LPSPI0_BASE_ADDRESS)
#define LPSPI_1										((LPSPI_Typedef *)LPSPI1_BASE_ADDRESS)
#define LPSPI_2										((LPSPI_Typedef *)LPSPI2_BASE_ADDRESS)
#define LPI2C_0										((LPI2C_Typedef *)LPI2C0_BASE_ADDRESS)
#define LPI2C_1										((LPI2C_Typedef *)LPI2C1_BASE_ADDRESS)
#define FTM_0											((FTM_Typedef 	*)FTM0_BASE_ADDRESS);
#define FTM_1											((FTM_Typedef 	*)FTM1_BASE_ADDRESS);
#define FTM_2											((FTM_Typedef 	*)FTM2_BASE_ADDRESS);
#define FTM_3											((FTM_Typedef 	*)FTM3_BASE_ADDRESS);
#define FTM_4											((FTM_Typedef 	*)FTM4_BASE_ADDRESS);
#define FTM_5											((FTM_Typedef 	*)FTM5_BASE_ADDRESS);
#define FTM_6											((FTM_Typedef 	*)FTM6_BASE_ADDRESS);
#define FTM_7 										((FTM_Typedef 	*)FTM7_BASE_ADDRESS);














/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SCG register  ********************/
#define SCG_SOSCCFG_EREFS_XTAL																	(1<<2)
#define SCG_SOSCCFG_EREFS_EXTAL																	(0<<2)
#define SCG_SOSCCFG_HGO																					(1<<3)
#define SCG_SOSCCFG_RANGE																				(0<<4)
#define SCG_SOSCCFG_RANGE_LOW																		(1<<4)
#define SCG_SOSCCFG_RANGE_MEDIUM																(2<<4)
#define SCG_SOSCCFG_RANGE_HIGH																	(3<<4)


#define SCG_SOSCCSR_SOSCEN																			(1u<<0)
#define SCG_SOSCCSR_SOSCVLD																			(1u<<24)

#define SCG_SPLLCSR_SPLLEN																			(1u<<0)
#define SCG_SPLLCSR_SPLLVLD																			(1u<<24)

#define SCG_SPLLCFG_PREDIV_(x)																	(x<<8)
#define SCG_SPLLCFG_MULT_(X)																		(X<<16)


#define SCG_XCCR_SOCS																						(1<<24)
#define SCG_XCCR_SLOW_IRC																				(2<<24)
#define SCG_XCCR_FAST_IRC																				(3<<24)
#define SCG_XCCR_SYS_PLL																				(0x06<<24)

#define SCG_XCCR_DIVCORE_(X)                                    (X<<16)
#define SCG_XCCR_DIVBUS_(X)                                     (X<<4)
#define SCG_XCCR_DIVFLASH_(X)                                   (X<<0)
#define SCG_SPLLDIV_2_DIV1																			(1<<8)
#define SCG_SPLLDIV_2_DIV2																			(2<<8)
#define SCG_SPLLDIV_2_DIV4																			(3<<8)
#define SCG_SPLLDIV_2_DIV8																			(4<<8)
#define SCG_SPLLDIV_2_DIV16																			(5<<8)
#define SCG_SPLLDIV_2_DIV32																			(6<<8)
#define SCG_SPLLDIV_2_DIV64																			(7<<8)






#define SCG_SOSCDIV_2_DIV1																			(1<<8)
#define SCG_SOSCDIV_2_DIV2																			(2<<8)
#define SCG_SOSCDIV_2_DIV4																			(3<<8)
#define SCG_SOSCDIV_2_DIV8																			(4<<8)
#define SCG_SOSCDIV_2_DIV16																			(5<<8)
#define SCG_SOSCDIV_2_DIV32																			(6<<8)
#define SCG_SOSCDIV_2_DIV64																			(7<<8)


#define SCG_FIRCDIV_2_DIV1																			(1<<8)
#define SCG_FIRCDIV_2_DIV2																			(2<<8)
#define SCG_FIRCDIV_2_DIV4																			(3<<8)
#define SCG_FIRCDIV_2_DIV8																			(4<<8)
#define SCG_FIRCDIV_2_DIV16																			(5<<8)
#define SCG_FIRCDIV_2_DIV32																			(6<<8)
#define SCG_FIRCDIV_2_DIV64																			(7<<8)




#define SCG_SIRCDIV_2_DIV1																			(1<<8)
#define SCG_SIRCDIV_2_DIV2																			(2<<8)
#define SCG_SIRCDIV_2_DIV4																			(3<<8)
#define SCG_SIRCDIV_2_DIV8																			(4<<8)
#define SCG_SIRCDIV_2_DIV16																			(5<<8)
#define SCG_SIRCDIV_2_DIV32																			(6<<8)
#define SCG_SIRCDIV_2_DIV64																			(7<<8)




#define SCG_CLKOUTCNFG_SOSC_CLK																		(1<<24)
#define SCG_CLKOUTCNFG_SLOW_CLK																		(0<<24)
#define SCG_CLKOUTCNFG_SIRC_CLK																		(2<<24)
#define SCG_CLKOUTCNFG_FIRC_CLK																		(3<<24)
#define SCG_CLKOUTCNFG_SPLL_CLK																		(6<<24)



/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PCC register  ********************/
#define PCC_PORT_CGC																						(1U<<30)
#define PCC_LPUART_CGC																					(1U<<30)
#define PCC_LPIT_CGC																						(1U<<30)
#define PCC_LPSPI_CGC																						(1U<<30)
#define PCC_LPI2C_CGC																						(1U<<30)
#define PCC_LPIT_PCS_SOSCDIV2_CLK																(1<<24)
#define PCC_LPIT_PCS_SIRCDIV2_CLK																(2<<24)
#define PCC_LPIT_PCS_FIRCDIV2_CLK																(3<<24)
#define PCC_LPIT_PCS_SPLLDIV2_CLK																(6<<24)
#define PCC_LPIT_PCS_LPO128_CLK																  (7<<24)
#define PCC_LPSPI_PCS_SOSCDIV2																	(1<<24)		
#define PCC_LPSPI_PCS_SIRCDIV2																	(2<<24)
#define PCC_LPSPI_PCS_FIRCDIV2																	(3<<24)
#define PCC_LPSPI_PCS_SPLLDIV2																	(6<<24)

#define PCC_LPI2C_PCS_SOSCDIV2																	(1<<24)		
#define PCC_LPI2C_PCS_SIRCDIV2																	(2<<24)
#define PCC_LPI2C_PCS_FIRCDIV2																	(3<<24)
#define PCC_LPI2C_PCS_SPLLDIV2																	(6<<24)







#define PCC_LPUART_PCS_SOSCDIV2																	(1<<24)		
#define PCC_LPUART_PCS_SIRCDIV2																	(2<<24)
#define PCC_LPUART_PCS_FIRCDIV2																	(3<<24)
#define PCC_LPUART_PCS_SPLLDIV2																	(6<<24)






/******************************************************************************/
/*                                                                            */
/*                         Core and System Modules                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PORT register  ********************/
#define PORT_CRNx_MUX_GPIO																			(1<<8)
#define PORT_CRNx_MUX_ANALOG																		(0<<8)
#define PORT_RESET_MUX(PORT_x,pin)															PORT_x->PCR[pin]&= ~(7u<<8)
#define PORT_SET_MUX(PORT_x,pin,mux)														PORT_x->PCR[pin]|= (mux<<8)
#define PORT_PCR_PE																							(1u<<1)


/******************************************************************************/
/*                                                                            */
/*                                  SYSTEM TICK                               */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SYSTEM_TICK register  ***************/
#define SYSTICK_CLOCKSOURCE																			(1<<2)
#define SYSTICK_ENABLE																					(1<<0)
#define SYSTICK_TICKINT																					(1<<1)





/******************************************************************************/
/*                                                                            */
/*                                  LPUART TICK                               */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for UART register  **********************/
#define LPUART_CTRL_M_7BITS																										(1<<11)
#define LPUART_CTRL_M_CLASSIC																									(0<<11)
#define LPUART_CTRL_PE																												(1<<2)
#define LPUART_CTRL_TE																												(1<<19)
#define LPUART_CTRL_RE																												(1<<18)
#define LPUART_CTRL_RIE																												(1<<21)
#define LPUART_CTRL_TCIE																											(1<<22)
#define LPUART_CTRL_TIE																												(1<<23)
#define LPUART_FIFO_TXFE																											(1<<7)
#define LPUART_STAT_TDRE																											(1<<23)				/*Transmit data buffer empty*/







/******************************************************************************/
/*                                                                            */
/*                                  INTERRUPT                                 */
/*                                                                            */
/******************************************************************************/
/******************** Bit definition for Interrupt NVIC  **********************/
#define NVIC_INTERRUPT_ID_LPUART0																						 (31)
#define NVIC_INTERRUPT_ID_LPUART1																						 (33)
#define NVIC_INTERRUPT_ID_LPUART2																						 (35)










/******************************************************************************/
/*                                                                            */
/*                      Low Power Interrupt Timer (LPIT)                      */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for LPIT Register  **********************/
#define LPIT_MCR_M_CEN																													(1<<0)
#define LPIT_MCR_DBG_EN																													(1<<3)
#define LPIT_TCTRL_T_EN																													(1<<0)
#define LPIT_TCTRL_MODE_32BIT																											(0<<2)




/******************************************************************************/
/*                                                                            */
/*                      System Integration Module	                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SIM Register   **********************/

#define SIM_CHIPCTL_CLKOUTSEL_SGVCLOUT																					(0<<4)
#define SIM_CHIPCTL_CLKOUTSEL_SOSCDIV2																					(2<<4)
#define SIM_CHIPCTL_CLKOUTSEL_SIRCDIV2																					(4<<4)
#define SIM_CHIPCTL_CLKOUTSEL_FIRCDIV2																					(6<<4)
#define SIM_CHIPCTL_CLKOUTSEL_HCLK																							(7<<4)
#define SIM_CHIPCTL_CLKOUTSEL_SPLLDIV2																					(8<<4)
#define SIM_CHIPCTL_CLKOUTSEL_BUS_CLK 																					(9<<4)
#define SIM_CHIPCTL_CLKOUTSEL_LPO128K 																					(10<<4)
#define SIM_CHIPCTL_CLKOUTSEL_QSPI_Module                             					(11<<4)
#define SIM_CHIPCTL_CLKOUTSEL_LPO_CLK                                 					(12<<4)
#define SIM_CHIPCTL_CLKOUTSEL_QSPI_SFIF_CLK                       					    (13<<4)
#define SIM_CHIPCTL_CLKOUTSEL_RTC_CLK                              					    (14<<4)
#define SIM_CHIPCTL_CLKOUTSEL_QSPI_2xSFIF_CLK                       					  (15<<4)
#define SIM_CHIPCTL_CLOCKOUTDIV(x)																							((x-1)<<8)
#define SIM_CHIPCTL_CLKOUTEN																										(1u<<11)






/******************************************************************************/
/*                                                                            */
/*                                  LPSI                                      */
/*                                                                            */
/******************************************************************************/
/******************** Bit definition for LPSI Register   **********************/



























/******************************************************************************/
/*                                                                            */
/*                                  LPI2C                                      */
/*                                                                            */
/******************************************************************************/
/******************** Bit definition for LPI2C Register   **********************/
#define LPI2C_MCCR0_DATAVD(x)																										(x<<24)
#define LPI2C_MCCR0_SETHOLD(x)																									(x<<16)
#define LPI2C_MCCR0_CLKHI(x)																										(x<<8)
#define LPI2C_MCCR0_CLKLO(x)																										(x<<0)

#define LPI2C_MIER_DMIE																													(1u<<14)
#define LPI2C_MIER_PLTIE																												(1u<<13)
#define LPI2C_MIER_FEIE																													(1u<<12)
#define LPI2C_MIER_ALIE																													(1u<<11)
#define LPI2C_MIER_NDIE																													(1u<<10)
#define LPI2C_MIER_SDIE																													(1u<<9)
#define LPI2C_MIER_EPIE																													(1u<<8)
#define LPI2C_MIER_RDIE																													(1u<<1)
#define LPI2C_MIER_TDIE																													(1u<<0)
#define LPI2C_MCFGR1_TIMECFG																										(1u<<10)




#define LPI2C_PRESCALE_DIV1																											(0<<8)
#define LPI2C_PRESCALE_DIV2																											(1<<8)
#define LPI2C_PRESCALE_DIV4																											(2<<8)
#define LPI2C_PRESCALE_DIV8																											(3<<8)
#define LPI2C_PRESCALE_DIV16																										(4<<8)
#define LPI2C_PRESCALE_DIV32																										(5<<8)
#define LPI2C_PRESCALE_DIV64																										(6<<8)
#define LPI2C_PRESCALE_DIV128																										(7<<8)

#define LPI2C_FILTSCL(X)																												(X<<16)
#define LPI2C_FILTSDA(X)																												(X<<24)
#define LPI2C_BUSIDLE(X)																												(X<<0)
#define LPI2C_MFCR_RXWATER(x)																										(x<<16)
#define LPI2C_MFCR_TXWATER(x)																										(x<<16)
#define LPI2C_MCR_RRF																														(1u<<9)
#define LPI2C_MCR_RTF																														(1u<<8)
#define LPI2C_MCR_DBGEN																													(1u<<3)
#define LPI2C_MCR_DOZEN																													(1u<<2)
#define LPI2C_MCR_RST																														(1u<<1)
#define LPI2C_MCR_MEN																														(1u<<0)











#endif //_S32K144_H_
