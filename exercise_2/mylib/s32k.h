/*
 * s32k.h
 *
 *  Created on: Sep 28, 2023
 *      Author: phana
 */

#ifndef S32K_H_
#define S32K_H_

#endif /* S32K_H_ */

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#define IPR12 ((volatile uint32_t*)(0xE000E400 + 4*12))
/* ----------------------------------------------------------------------------
   -- Generic macros
   ---------------------------------------------------------------------------- */

/* IO definitions (access restrictions to peripheral registers) */
/**
*   IO Type Qualifiers are used
*   \li to specify the access to peripheral variables.
*   \li for automatic generation of peripheral register debug information.
*/
#ifndef __IO
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */
#endif

#define setb 1
#define clear 0


/*!
 * @addtogroup PCC_Peripheral_Access_Layer PCC Peripheral Access Layer
 * @{
 */


/** PCC - Size of Registers Arrays */
#define PCC_PCCn_COUNT                           116u

/** PCC - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCCn[PCC_PCCn_COUNT];              /**< PCC Reserved Register 0..PCC CMP0 Register, array offset: 0x0, array step: 0x4 */
} PCC_Type, *PCC_MemMapPtr;

 /** Number of instances of the PCC module. */
#define PCC_INSTANCE_COUNT                       (1u)


/* PCC - Peripheral instance base addresses */
/** Peripheral PCC base address */
#define PCC_BASE                                 (0x40065000u)
/** Peripheral PCC base pointer */
#define PCC                                      ((PCC_Type *)PCC_BASE)
/** Array initializer of PCC peripheral base addresses */
#define PCC_BASE_ADDRS                           { PCC_BASE }
/** Array initializer of PCC peripheral base pointers */
#define PCC_BASE_PTRS                            { PCC }

/* PCC index offsets */
#define PCC_FTFC_INDEX                           32
#define PCC_DMAMUX_INDEX                         33
#define PCC_FlexCAN0_INDEX                       36
#define PCC_FlexCAN1_INDEX                       37
#define PCC_FTM3_INDEX                           38
#define PCC_ADC1_INDEX                           39
#define PCC_FlexCAN2_INDEX                       43
#define PCC_LPSPI0_INDEX                         44
#define PCC_LPSPI1_INDEX                         45
#define PCC_LPSPI2_INDEX                         46
#define PCC_PDB1_INDEX                           49
#define PCC_CRC_INDEX                            50
#define PCC_PDB0_INDEX                           54
#define PCC_LPIT_INDEX                           55
#define PCC_FTM0_INDEX                           56
#define PCC_FTM1_INDEX                           57
#define PCC_FTM2_INDEX                           58
#define PCC_ADC0_INDEX                           59
#define PCC_RTC_INDEX                            61
#define PCC_LPTMR0_INDEX                         64
#define PCC_PORTA_INDEX                          73
#define PCC_PORTB_INDEX                          74
#define PCC_PORTC_INDEX                          75
#define PCC_PORTD_INDEX                          76
#define PCC_PORTE_INDEX                          77
#define PCC_FlexIO_INDEX                         90
#define PCC_EWM_INDEX                            97
#define PCC_LPI2C0_INDEX                         102
#define PCC_LPUART0_INDEX                        106
#define PCC_LPUART1_INDEX                        107
#define PCC_LPUART2_INDEX                        108
#define PCC_CMP0_INDEX                           115


/*!
 * @}
 */ /* end of group PCC_Peripheral_Access_Layer */



//typedef struct{
//	volatile uint32_t PCCA;		//CLOCK PORT A ENABLE
//	volatile uint32_t PCCB;		//CLOCK PORT B ENABLE
//	volatile uint32_t PCCC;		//CLOCK PORT C ENABLE
//	volatile uint32_t PCCD;		//CLOCK PORT D ENABLE
//	volatile uint32_t PCCE;		//CLOCK PORT E ENABLE
//} PCC_Type;
//#define PCC ((PCC_Type *)0x40065124u)



typedef struct{
	volatile uint32_t PCR[32];
}PORT_Type;
#define PORTA ((PORT_Type *)0x40049000u)
#define PORTB ((PORT_Type *)0x4004A000u)
#define PORTC ((PORT_Type *)0x4004B000u)
#define PORTD ((PORT_Type *)0x4004C000u)
#define PORTE ((PORT_Type *)0x4004D000u)

typedef struct{
	volatile uint32_t PDOR;		//Port Data Output Register
	volatile uint32_t PSOR;		//Port Set Output Register
	volatile uint32_t PCOR;		//Port Clear Output Register
	volatile uint32_t PTOR;		//Port Toggle Output Register
	volatile uint32_t PDIR;		//Port Data Input Register
	volatile uint32_t PDDR;		//Port Data Direction Register
	volatile uint32_t PIDR;		//Port Data Disable Register
} GPIO_Type;
#define GPIOA ((GPIO_Type *)0x400FF000u)
#define GPIOB ((GPIO_Type *)0x400FF040u)
#define GPIOC ((GPIO_Type *)0x400FF080u)
#define GPIOD ((GPIO_Type *)0x400FF0C0u)
#define GPIOE ((GPIO_Type *)0x400FF100u)

/* ----------------------------------------------------------------------------
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */


/** SIM - Size of Registers Arrays */

/** SIM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t CHIPCTL;                           /**< Chip Control register, offset: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t FTMOPT0;                           /**< FTM Option Register 0, offset: 0xC */
  __IO uint32_t LPOCLKS;                           /**< LPO Clock Select Register, offset: 0x10 */
       uint8_t RESERVED_2[4];
  __IO uint32_t ADCOPT;                            /**< ADC Options Register, offset: 0x18 */
  __IO uint32_t FTMOPT1;                           /**< FTM Option Register 1, offset: 0x1C */
  __IO uint32_t MISCTRL0;                          /**< Miscellaneous control register 0, offset: 0x20 */
  __I  uint32_t SDID;                              /**< System Device Identification Register, offset: 0x24 */
       uint8_t RESERVED_3[24];
  __IO uint32_t PLATCGC;                           /**< Platform Clock Gating Control Register, offset: 0x40 */
       uint8_t RESERVED_4[8];
  __IO uint32_t FCFG1;                             /**< Flash Configuration Register 1, offset: 0x4C */
       uint8_t RESERVED_5[4];
  __I  uint32_t UIDH;                              /**< Unique Identification Register High, offset: 0x54 */
  __I  uint32_t UIDMH;                             /**< Unique Identification Register Mid-High, offset: 0x58 */
  __I  uint32_t UIDML;                             /**< Unique Identification Register Mid Low, offset: 0x5C */
  __I  uint32_t UIDL;                              /**< Unique Identification Register Low, offset: 0x60 */
       uint8_t RESERVED_6[4];
  __IO uint32_t CLKDIV4;                           /**< System Clock Divider Register 4, offset: 0x68 */
  __IO uint32_t MISCTRL1;
} SIM_Type;

 /** Number of instances of the SIM module. */
#define SIM_INSTANCE_COUNT                       (1u)


/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                                 (0x40048000u)
/** Peripheral SIM base pointer */
#define SIM                                      ((SIM_Type *)SIM_BASE)
/** Array initializer of SIM peripheral base addresses */
#define SIM_BASE_ADDRS                           { SIM_BASE }
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASE_PTRS                            { SIM }


/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */

/** SCG - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __I  uint32_t CSR;                               /**< Clock Status Register, offset: 0x10 */
  __IO uint32_t RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
  __IO uint32_t VCCR;                              /**< VLPR Clock Control Register, offset: 0x18 */
  __IO uint32_t HCCR;                              /**< HSRUN Clock Control Register, offset: 0x1C */
  __IO uint32_t CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
       uint8_t RESERVED_1[220];
  __IO uint32_t SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
  __IO uint32_t SOSCDIV;                           /**< System OSC Divide Register, offset: 0x104 */
  __IO uint32_t SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x108 */
       uint8_t RESERVED_2[244];
  __IO uint32_t SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
  __IO uint32_t SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
  __IO uint32_t SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208 */
       uint8_t RESERVED_3[244];
  __IO uint32_t FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
  __IO uint32_t FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
  __IO uint32_t FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
       uint8_t RESERVED_4[756];
  __IO uint32_t SPLLCSR;                           /**< System PLL Control Status Register, offset: 0x600 */
  __IO uint32_t SPLLDIV;                           /**< System PLL Divide Register, offset: 0x604 */
  __IO uint32_t SPLLCFG;                           /**< System PLL Configuration Register, offset: 0x608 */
} SCG_Type, *SCG_MemMapPtr;

 /** Number of instances of the SCG module. */
#define SCG_INSTANCE_COUNT                       (1u)


/* SCG - Peripheral instance base addresses */
/** Peripheral SCG base address */
#define SCG_BASE                                 (0x40064000u)
/** Peripheral SCG base pointer */
#define SCG                                      ((SCG_Type *)SCG_BASE)
/** Array initializer of SCG peripheral base addresses */
#define SCG_BASE_ADDRS                           { SCG_BASE }
/** Array initializer of SCG peripheral base pointers */
#define SCG_BASE_PTRS                            { SCG }
 /** Number of interrupt vector arrays for the SCG module. */
#define SCG_IRQS_ARR_COUNT                       (1u)
 /** Number of interrupt channels for the SCG module. */
#define SCG_IRQS_CH_COUNT                        (1u)
/** Interrupt vectors for the SCG peripheral type */
#define SCG_IRQS                                 { SCG_IRQn }

/*!
 * @}
 */ /* end of group SCG_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- LPIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPIT_Peripheral_Access_Layer LPIT Peripheral Access Layer
 * @{
 */


/** LPIT - Size of Registers Arrays */
#define LPIT_TMR_COUNT                           4u

/** LPIT - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t MCR;                               /**< Module Control Register, offset: 0x8 */
  __IO uint32_t MSR;                               /**< Module Status Register, offset: 0xC */
  __IO uint32_t MIER;                              /**< Module Interrupt Enable Register, offset: 0x10 */
  __IO uint32_t SETTEN;                            /**< Set Timer Enable Register, offset: 0x14 */
  __IO uint32_t CLRTEN;                            /**< Clear Timer Enable Register, offset: 0x18 */
       uint8_t RESERVED[4];
       	   	   	   	   	   	   	   	   	   	   	   /* offset: 0x20, array step: 0x10 */
  __IO uint32_t TVAL0;                              /**< Timer Value Register, array offset: 0x20, array step: 0x10 */
  __I  uint32_t CVAL0;                              /**< Current Timer Value, array offset: 0x24, array step: 0x10 */
  __IO uint32_t TCTRL0;                             /**< Timer Control Register, array offset: 0x28, array step: 0x10 */
         uint8_t RESERVED_0[4];

  __IO uint32_t TVAL1;
  __I  uint32_t CVAL1;
  __IO uint32_t TCTRL1;
       uint8_t RESERVED_1[4];

} LPIT_Type, *LPIT_MemMapPtr;

 /** Number of instances of the LPIT module. */
#define LPIT_INSTANCE_COUNT                      (1u)


/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT0 base address */
#define LPIT0_BASE                               (0x40037000u)
/** Peripheral LPIT0 base pointer */
#define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { LPIT0_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { LPIT0 }
 /** Number of interrupt vector arrays for the LPIT module. */
#define LPIT_IRQS_ARR_COUNT                      (1u)
 /** Number of interrupt channels for the LPIT module. */
#define LPIT_IRQS_CH_COUNT                       (4u)
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { LPIT0_Ch0_IRQn, LPIT0_Ch1_IRQn, LPIT0_Ch2_IRQn, LPIT0_Ch3_IRQn }

/*!
 * @}
 */ /* end of group LPIT_Peripheral_Access_Layer */

typedef struct NVIC_Type
	{
		volatile uint32_t ISER[8];
		volatile uint32_t res1[24];
		volatile uint32_t ICER[8];
		volatile uint32_t res2[24];
		volatile uint32_t ISPR[8];
		volatile uint32_t res3[24];
		volatile uint32_t ICPR[8];
		volatile uint32_t res4[24];
		volatile uint32_t IABR[8];
		volatile uint32_t res5[56];
		volatile uint32_t IPR[60];
		volatile uint32_t res6[644];
		volatile uint32_t STIR;
	}NVIC_Type;
#define NVIC_BASE_ADD 0xE000E100
#define NVIC ((NVIC_Type*)(NVIC_BASE_ADD))

/* ----------------------------------------------------------------------------
   -- LPUART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
   * @addtogroup LPUART_Peripheral_Access_Layer LPUART Peripheral Access Layer
   * @{
   */


/** LPUART - Size of Registers Arrays */

/** LPUART - Register Layout Typedef */
typedef struct {
	  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
	  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
	  __IO uint32_t GLOBAL;                            /**< LPUART Global Register, offset: 0x8 */
	  __IO uint32_t PINCFG;                            /**< LPUART Pin Configuration Register, offset: 0xC */
	  __IO uint32_t BAUD;                              /**< LPUART Baud Rate Register, offset: 0x10 */
	  __IO uint32_t STAT;                              /**< LPUART Status Register, offset: 0x14 */
	  __IO uint32_t CTRL;                              /**< LPUART Control Register, offset: 0x18 */
	  __IO uint32_t DATA;                              /**< LPUART Data Register, offset: 0x1C */
	  __IO uint32_t MATCH;                             /**< LPUART Match Address Register, offset: 0x20 */
	  __IO uint32_t MODIR;                             /**< LPUART Modem IrDA Register, offset: 0x24 */
	  __IO uint32_t FIFO;                              /**< LPUART FIFO Register, offset: 0x28 */
	  __IO uint32_t WATER;                             /**< LPUART Watermark Register, offset: 0x2C */
	} LPUART_Type, *LPUART_MemMapPtr;

	 /** Number of instances of the LPUART module. */
	#define LPUART_INSTANCE_COUNT                    (3u)


	/* LPUART - Peripheral instance base addresses */
	/** Peripheral LPUART0 base address */
	#define LPUART0_BASE                             (0x4006A000u)
	/** Peripheral LPUART0 base pointer */
	#define LPUART0                                 ((LPUART_Type *)LPUART0_BASE)
	/** Peripheral LPUART1 base address */
	#define LPUART1_BASE                             (0x4006B000u)
	/** Peripheral LPUART1 base pointer */
	#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
	/** Peripheral LPUART2 base address */
	#define LPUART2_BASE                             (0x4006C000u)
	/** Peripheral LPUART2 base pointer */
	#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
	/** Array initializer of LPUART peripheral base addresses */
	#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE }
	/** Array initializer of LPUART peripheral base pointers */
	#define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2 }
	 /** Number of interrupt vector arrays for the LPUART module. */
	#define LPUART_IRQS_ARR_COUNT                    (1u)
	 /** Number of interrupt channels for the RX_TX type of LPUART module. */
	#define LPUART_RX_TX_IRQS_CH_COUNT               (1u)
	/** Interrupt vectors for the LPUART peripheral type */
	#define LPUART_RX_TX_IRQS                        { LPUART0_RxTx_IRQn, LPUART1_RxTx_IRQn, LPUART2_RxTx_IRQn }

/*!
 * @}
 */ /* end of group LPUART_Peripheral_Access_Layer */


	/*!
	 * @addtogroup FTM_Peripheral_Access_Layer FTM Peripheral Access Layer
	 * @{
	 */


	/** FTM - Size of Registers Arrays */
	#define FTM_CONTROLS_COUNT                       8u

	/** FTM - Register Layout Typedef */
	typedef struct {
	  __IO uint32_t SC;                                /**< Status And Control, offset: 0x0 */
	  __IO uint32_t CNT;                               /**< Counter, offset: 0x4 */
	  __IO uint32_t MOD;                               /**< Modulo, offset: 0x8 */
	  struct {                                         /* offset: 0xC, array step: 0x8 */
	    __IO uint32_t CnSC;                              /**< Channel (n) Status And Control, array offset: 0xC, array step: 0x8 */
	    __IO uint32_t CnV;                               /**< Channel (n) Value, array offset: 0x10, array step: 0x8 */
	  } CONTROLS[FTM_CONTROLS_COUNT];
	  __IO uint32_t CNTIN;                             /**< Counter Initial Value, offset: 0x4C */
	  __IO uint32_t STATUS;                            /**< Capture And Compare Status, offset: 0x50 */
	  __IO uint32_t MODE;                              /**< Features Mode Selection, offset: 0x54 */
	  __IO uint32_t SYNC;                              /**< Synchronization, offset: 0x58 */
	  __IO uint32_t OUTINIT;                           /**< Initial State For Channels Output, offset: 0x5C */
	  __IO uint32_t OUTMASK;                           /**< Output Mask, offset: 0x60 */
	  __IO uint32_t COMBINE;                           /**< Function For Linked Channels, offset: 0x64 */
	  __IO uint32_t DEADTIME;                          /**< Deadtime Configuration, offset: 0x68 */
	  __IO uint32_t EXTTRIG;                           /**< FTM External Trigger, offset: 0x6C */
	  __IO uint32_t POL;                               /**< Channels Polarity, offset: 0x70 */
	  __IO uint32_t FMS;                               /**< Fault Mode Status, offset: 0x74 */
	  __IO uint32_t FILTER;                            /**< Input Capture Filter Control, offset: 0x78 */
	  __IO uint32_t FLTCTRL;                           /**< Fault Control, offset: 0x7C */
	  __IO uint32_t QDCTRL;                            /**< Quadrature Decoder Control And Status, offset: 0x80 */
	  __IO uint32_t CONF;                              /**< Configuration, offset: 0x84 */
	  __IO uint32_t FLTPOL;                            /**< FTM Fault Input Polarity, offset: 0x88 */
	  __IO uint32_t SYNCONF;                           /**< Synchronization Configuration, offset: 0x8C */
	  __IO uint32_t INVCTRL;                           /**< FTM Inverting Control, offset: 0x90 */
	  __IO uint32_t SWOCTRL;                           /**< FTM Software Output Control, offset: 0x94 */
	  __IO uint32_t PWMLOAD;                           /**< FTM PWM Load, offset: 0x98 */
	  __IO uint32_t HCR;                               /**< Half Cycle Register, offset: 0x9C */
	  __IO uint32_t PAIR0DEADTIME;                     /**< Pair 0 Deadtime Configuration, offset: 0xA0 */
	       uint8_t RESERVED_0[4];
	  __IO uint32_t PAIR1DEADTIME;                     /**< Pair 1 Deadtime Configuration, offset: 0xA8 */
	       uint8_t RESERVED_1[4];
	  __IO uint32_t PAIR2DEADTIME;                     /**< Pair 2 Deadtime Configuration, offset: 0xB0 */
	       uint8_t RESERVED_2[4];
	  __IO uint32_t PAIR3DEADTIME;                     /**< Pair 3 Deadtime Configuration, offset: 0xB8 */
	} FTM_Type, *FTM_MemMapPtr;
	 /** Number of instances of the FTM module. */
	#define FTM_INSTANCE_COUNT                       (4u)


	/* FTM - Peripheral instance base addresses */
	/** Peripheral FTM0 base address */
	#define FTM0_BASE                                (0x40038000u)
	/** Peripheral FTM0 base pointer */
	#define FTM0                                     ((FTM_Type *)FTM0_BASE)
	/** Peripheral FTM1 base address */
	#define FTM1_BASE                                (0x40039000u)
	/** Peripheral FTM1 base pointer */
	#define FTM1                                     ((FTM_Type *)FTM1_BASE)
	/** Peripheral FTM2 base address */
	#define FTM2_BASE                                (0x4003A000u)
	/** Peripheral FTM2 base pointer */
	#define FTM2                                     ((FTM_Type *)FTM2_BASE)
	/** Peripheral FTM3 base address */
	#define FTM3_BASE                                (0x40026000u)
	/** Peripheral FTM3 base pointer */
	#define FTM3                                     ((FTM_Type *)FTM3_BASE)
	/** Array initializer of FTM peripheral base addresses */
	#define FTM_BASE_ADDRS                           { FTM0_BASE, FTM1_BASE, FTM2_BASE, FTM3_BASE }
	/** Array initializer of FTM peripheral base pointers */
	#define FTM_BASE_PTRS                            { FTM0, FTM1, FTM2, FTM3 }
	 /** Number of interrupt vector arrays for the FTM module. */
	#define FTM_IRQS_ARR_COUNT                       (4u)
	 /** Number of interrupt channels for the FTM module. */
	#define FTM_IRQS_CH_COUNT                        (8u)
	 /** Number of interrupt channels for the Fault type of FTM module. */
	#define FTM_Fault_IRQS_CH_COUNT                  (1u)
	 /** Number of interrupt channels for the Overflow type of FTM module. */
	#define FTM_Overflow_IRQS_CH_COUNT               (1u)
	 /** Number of interrupt channels for the Reload type of FTM module. */
	#define FTM_Reload_IRQS_CH_COUNT                 (1u)
	/** Interrupt vectors for the FTM peripheral type */
	#define FTM_IRQS                                 { { FTM0_Ch0_Ch1_IRQn, FTM0_Ch0_Ch1_IRQn, FTM0_Ch2_Ch3_IRQn, FTM0_Ch2_Ch3_IRQn, FTM0_Ch4_Ch5_IRQn, FTM0_Ch4_Ch5_IRQn, FTM0_Ch6_Ch7_IRQn, FTM0_Ch6_Ch7_IRQn }, \
	                                                   { FTM1_Ch0_Ch1_IRQn, FTM1_Ch0_Ch1_IRQn, FTM1_Ch2_Ch3_IRQn, FTM1_Ch2_Ch3_IRQn, FTM1_Ch4_Ch5_IRQn, FTM1_Ch4_Ch5_IRQn, FTM1_Ch6_Ch7_IRQn, FTM1_Ch6_Ch7_IRQn }, \
	                                                   { FTM2_Ch0_Ch1_IRQn, FTM2_Ch0_Ch1_IRQn, FTM2_Ch2_Ch3_IRQn, FTM2_Ch2_Ch3_IRQn, FTM2_Ch4_Ch5_IRQn, FTM2_Ch4_Ch5_IRQn, FTM2_Ch6_Ch7_IRQn, FTM2_Ch6_Ch7_IRQn }, \
	                                                   { FTM3_Ch0_Ch1_IRQn, FTM3_Ch0_Ch1_IRQn, FTM3_Ch2_Ch3_IRQn, FTM3_Ch2_Ch3_IRQn, FTM3_Ch4_Ch5_IRQn, FTM3_Ch4_Ch5_IRQn, FTM3_Ch6_Ch7_IRQn, FTM3_Ch6_Ch7_IRQn } }
	#define FTM_Fault_IRQS                           { FTM0_Fault_IRQn, FTM1_Fault_IRQn, FTM2_Fault_IRQn, FTM3_Fault_IRQn }
	#define FTM_Overflow_IRQS                        { FTM0_Ovf_Reload_IRQn, FTM1_Ovf_Reload_IRQn, FTM2_Ovf_Reload_IRQn, FTM3_Ovf_Reload_IRQn }
	#define FTM_Reload_IRQS                          { FTM0_Ovf_Reload_IRQn, FTM1_Ovf_Reload_IRQn, FTM2_Ovf_Reload_IRQn, FTM3_Ovf_Reload_IRQn }

	/* ----------------------------------------------------------------------------
	   -- FTM Register Masks
	   ---------------------------------------------------------------------------- */

	/*!
	 * @}
	 */ /* end of group FTM_Peripheral_Access_Layer */

