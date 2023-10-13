#include "init.h"
#include "stdint.h"
#include "stdio.h"
#define SYS_CLOCK_MHZ											80
#define SPLLDIV2													4
#define SETUP_PORT_PCR_ALTERNATIVE(LPUART_X,PORT_X,pin)							\
	if(LPUART_X==LPUART_0){																						\
		if(PORT_X==PORT_A) PORT_X->PCR[pin]|=(6<<8);										\
		else if(PORT_X==PORT_B) PORT_X->PCR[pin]|=(2<<8);								\
		else PORT_X->PCR[pin]|=(4<<8);																	\
	}																																	\
	else if(LPUART_X==LPUART_1){																			\
		if(PORT_X==PORT_C) PORT_X->PCR[pin]|=(2<<8);										\
		else PORT_X->PCR[pin]|=(3<<8);																	\
	}																																	\
	else{																															\
		if(PORT_X==PORT_E) PORT_X->PCR[pin]|=(3<<8);										\
		else if(pin==17) PORT_X->PCR[pin]|=(3<<8);											\
		else PORT_X->PCR[pin]|=(2<<8);																	\
	}
void System_Clock_Out_Config(uint8_t EXTAL_OR_XTAL){
	uint32_t xccr=0;
	/*************>>>>>>> STEPS FOLLOWED <<<<<<<<************
	
	1. ENABLE SYStem OCS by write SOSCCFFG_ERFEFS and Choose mode EXTAL OR XTAL and wait for it turn on
	2. COnfigure the PLL , enable the PLL and wait for it to become ready
	3. Setup CCR
	4. Configure the PRESCALARS HCLK, PCLK1, PCLK2
	5. Configure the MAIN PLL
	6. Enable the PLL and wait for it to become ready
	7. Select the Clock Source and wait for it to be set
	
	********************************************************/
	
	//1. ENABLE SYStem OCS by write SOSCCFFG_ERFEFS and Choose mode EXTAL OR XTAL and wait for it turn on
	//First OFF System OCS to write SOSCCFFG in the SOSCCSR
	SCG->SOSCCSR &=~SCG_SOSCCSR_SOSCEN;
	//Write the SOSCCFFG
	if(EXTAL_OR_XTAL==XTAL)
		//if XTAL must set the HGO to high and RANGE is High
	{
		SCG->SOSCCFG|=SCG_SOSCCFG_EREFS_XTAL;
		SCG->SOSCCFG|=SCG_SOSCCFG_HGO;
		SCG->SOSCCFG|=SCG_SOSCCFG_RANGE_HIGH;
	}
	else SCG->SOSCCFG|=SCG_SOSCCFG_EREFS_EXTAL;
	//Turn on the System OCS
	SCG->SOSCCSR|=SCG_SOSCCSR_SOSCEN;
	//wait for it turn on
	while(!(SCG->SOSCCSR & SCG_SOSCCSR_SOSCVLD));
	
	
	//2. COnfigure the PLL, enable the PLL and wait for it to become ready
	//Turn off the SYSTEM PLL for write
	SCG->SPLLCSR &=~SCG_SPLLCSR_SPLLEN;
	//write PLLCFR 
		//want the SPLL_CLK=80Mhz 
		//V_CO_CLOCK=SPLL_SOURCE/(PREV+1)*(MULT+16),SPLL_CLK=V_CO_CLOCK/2
	SCG->SPLLCFG|=SCG_SPLLCFG_MULT_(4);
	SCG->SPLLCFG|=SCG_SPLLCFG_PREDIV_(0);
	
	//Enable the PLL and wait for it ready
	SCG->SPLLCSR|=SCG_SPLLCSR_SPLLEN;
	while(!(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD));
	
	
	//3. Setup CCR
	//must write all 32 bits at once time
	
	//source in XCCR is PLL
	xccr|=SCG_XCCR_SYS_PLL;
	//CORE_CLK and SYS_CLK must be<112MHZ in HRUN and 80MHZ in normal RUN, 
	//CORE_CLK=SYS_CLK=SPLL_CLK/(DIVCORE+1)
	xccr|=SCG_XCCR_DIVCORE_(0);
	//BUC_CLK must be <56MHZ in HRUN and <48MHz in Normal RUn (expect PLL is <=40Mhz) and CORE_CLK % BUS_CLK=0, 
	//BUS_CLK=SPLL_CLK/(DIVBUS+1)
	xccr|=SCG_XCCR_DIVBUS_(1);
	//FLASH_CLK must be <56MHZ in HRUN and <26.67MHz in Normal RUn and CORE_CLK % FLASH_CLK=0
	//FLASH_CLK=SPLL_CLK/(DIVFLASH+1)
	xccr|=SCG_XCCR_DIVFLASH_(3);
	
	SCG->RCCR|=xccr;

	//UART - LPIT
	SCG->SPLLDIV|=SCG_SPLLDIV_2_DIV2;
}
void GPIO_Config_Clock(GPIO_Typedef *GPIOx){
	if(GPIOx==GPIOA) PCC->PORTA|=PCC_PORT_CGC;
	else if (GPIOx==GPIOB) PCC->PORTB|=PCC_PORT_CGC;
	else if (GPIOx==GPIOC) PCC->PORTC|=PCC_PORT_CGC;
	else if (GPIOx==GPIOD) PCC->PORTD|=PCC_PORT_CGC;
	else PCC->PORTE|=PCC_PORT_CGC;
}
void GPIO_Config_Mode(PORT_Typedef *PORT_x,GPIO_Typedef *GPIOx,uint32_t pin,uint8_t MODE_INPUT_OUTPUT){
	/*************>>>>>>> STEPS FOLLOWED to Configure all microcontroller<<<<<<<<************
	 After config clock of gpio
	1. Enable the mode of GPIO
	2. Configure that mode
	
	********************************************************/
	PORT_Config(PORT_x);
	for(uint8_t i=0;i<32;i++){
		if((pin>>i) & 1){
			//1. Enable the mode of GPIO the GPIOx mode depend on the PORTx_PCR[pin] Register
			//turn on the GPIO
			if(GPIOx==GPIOA) PORT_A->PCR[i]|=PORT_CRNx_MUX_GPIO;
			else if (GPIOx==GPIOB) PORT_B->PCR[i]|=PORT_CRNx_MUX_GPIO;
			else if (GPIOx==GPIOC) PORT_C->PCR[i]|=PORT_CRNx_MUX_GPIO;
			else if (GPIOx==GPIOD) PORT_D->PCR[i]|=PORT_CRNx_MUX_GPIO;
			else PORT_E->PCR[i]|=PORT_CRNx_MUX_GPIO;
			//2. Configure that mode
			if(MODE_INPUT_OUTPUT==OUTPUT){
					GPIOx->PDDR|=PIN(i);
					GPIOx->PCOR|=PIN(i);
			}
			//mode Input with hight
			else{
				if(i==12)
					PORT_x->PCR[i] |= ((0x09 << 16));
				if(i==13)
					PORT_x->PCR[i] |= ((0x0B << 16));
				PORT_x->PCR[i]|=PORT_PCR_PE;
				GPIOx->PDDR &=~PIN(i);
			}
		}
	}
	if(MODE_INPUT_OUTPUT==INPUT){
		if (GPIOx==GPIOC){
			NVIC->ISER[1] |= (1U<<29);
			NVIC->IPR[15]|=(4U<<12);
		}
	}
}
void System_Tick_Config(void){
	/*************>>>>>>> STEPS FOLLOWED to Configure all microcontroller<<<<<<<<************
	 After config clock of SYS_CLOCK
	1. Enable the mode of SYS_Tick Counter
	2. Configure the SYS_TICK
	
	********************************************************/
	//1. Enable the mode of SYS_Tick and the source of SYS_TICK 
	SYSTICK->CSR|=SYSTICK_ENABLE;
	SYSTICK->CSR|=SYSTICK_CLOCKSOURCE;
	//2. Configure the SYS_TICK
	
	
	//Set reload for timer to count ms
	SYSTICK->RVR=SYS_CLOCK_MHZ*1000-1;
	
	//Set the interupt
	SYSTICK->CSR|=SYSTICK_TICKINT;
}
void LPUART_Config(LPUART_Typedef *LPUART_x,PORT_Typedef *PORT_x,uint8_t pin_RX,uint8_t pin_TX,uint8_t interrupt){
	
	uint32_t baud=0;
	/*************>>>>>>> STEPS FOLLOWED to Configure all microcontroller<<<<<<<<************
	
	1. Enable the CLock of UART and CLOCK GPIO for it
	2. Configure GPIO for Tx and Rx
	3. Setting BAUDRATE
	4. Seting Framework
	5. Enable TE and RE
	6. if have interuppt, enable interupt
	********************************************************/
	
	//1. Enable the CLock and source of UART and CLOCK GPIO for it
	//Enable UART CLOCK and Source
	

	if(LPUART_x==LPUART_0){
			PCC->LPUART0 |=PCC_LPUART_PCS_SPLLDIV2;
			PCC->LPUART0 |= PCC_LPUART_CGC;
	}
	else if(LPUART_x==LPUART_1){
			PCC->LPUART1 |=PCC_LPUART_PCS_SPLLDIV2;
			PCC->LPUART1 |= PCC_LPUART_CGC;
	}
	else{
			PCC->LPUART1 |=PCC_LPUART_PCS_SPLLDIV2;
			PCC->LPUART1 |= PCC_LPUART_CGC;
	}

	//CLOCK GPIOx
	PORT_Config(PORT_x);

	//2. Configure GPIO for Tx and Rx
	//set alterfunction
	SETUP_PORT_PCR_ALTERNATIVE(LPUART_x,PORT_x,pin_RX)
	SETUP_PORT_PCR_ALTERNATIVE(LPUART_x,PORT_x,pin_TX)



	//3.Setting BAUDRATE
	//bd 9600 OSC+1=17;
	

	
	baud=416;
	baud|=(0x09<<24);
	LPUART_x->BAUD=baud;
	

	//4. Seting Framework
	//set stop bit
	//classic is one stop bits
	
	
	//Set data characters number:
	//classic is 8bits-10bits
	//if want 7bits set CTRL_M7=1<<11
	
	//Set parity bit: CTRL[PE]
//	LPUART_x->CTRL|=LPUART_CTRL_PE;
	
	//5.ENable TE and RE
	LPUART_x->CTRL|=LPUART_CTRL_TE;
	LPUART_x->CTRL|=LPUART_CTRL_RE;
	
	if(interrupt==ON){
		if(LPUART_x==LPUART_0) NVIC->ISER[NVIC_INTERRUPT_ID_LPUART0/32]|=(1u<<(NVIC_INTERRUPT_ID_LPUART0 %32));
		else if(LPUART_x==LPUART_1) NVIC->ISER[NVIC_INTERRUPT_ID_LPUART1/32]|=(1<<(NVIC_INTERRUPT_ID_LPUART1 %32));
		else NVIC->ISER[NVIC_INTERRUPT_ID_LPUART2/32]|=(1u<<(NVIC_INTERRUPT_ID_LPUART2 %32));
		
		
		//enable interupt
		LPUART_x->CTRL|=LPUART_CTRL_RIE;
//		LPUART_x->CTRL|=LPUART_CTRL_TIE;
//		LPUART_x->CTRL|=LPUART_CTRL_TCIE;
		
	}

}
void LPIT_Clock_Source(void){
	/*************>>>>>>> STEPS FOLLOWED to Configure all microcontroller<<<<<<<<************
	 After config clock of SYS_CLOCK
	1. SEtting CLOCKINg: 
		+ Peripheral Clock Source Select: PCC[PCS]
		+ Enable clock for LPIT: PCC[CGC]
	2. Timer Initialization (LPIT in S32K)
		+ Module Clock Enable: MCR[M_CEN]
		+ Run in Debug mode: MCR[DBG_EN]
	3.Configuration for channel
		+ Timer Operation Mode: TCTR?Ln[MODE]
	
	4.Get Timer Counter value
		+ Read Current Timer Value: CVALn
	5.Timer Channel
		+ Enable Timer Channel: TCTR?Ln[T_EN]
	********************************************************/
	
	
	//1. SEtting CLOCKINg: 
	//	+ Peripheral Clock Source Select: PCC[PCS]
	PCC->LPIT|=PCC_LPIT_PCS_SPLLDIV2_CLK;
	//	+ Enable clock for LPIT: PCC[CGC]
	PCC->LPIT|=PCC_LPIT_CGC;
	
	//d
	
	//2. Timer Initialization (LPIT in S32K)
	//	+ Module Clock Enable: MCR[M_CEN]
	LPIT_T->MCR|=LPIT_MCR_M_CEN;
	//	+ Run in Debug mode: MCR[DBG_EN]
	LPIT_T->MCR|=LPIT_MCR_DBG_EN;

}
void LPIT_Config(uint8_t channel,uint32_t ms,uint8_t interrupt){
	//3.Configuration for channel
	//	+ Timer Operation Mode: TCTR?Ln[MODE]
	//classic is 00b - 32-bit Periodic Counter
	if(channel==0) LPIT_T->TCTRL0 &= ~LPIT_TCTRL_T_EN;
	else if(channel==1) LPIT_T->TCTRL1 &= ~LPIT_TCTRL_T_EN;
	else if(channel==2) LPIT_T->TCTRL2 &= ~LPIT_TCTRL_T_EN;
	else  LPIT_T->TCTRL3 &= ~ LPIT_TCTRL_T_EN;
	
	if(channel==0) LPIT_T->TCTRL0 |= LPIT_TCTRL_MODE_32BIT;
	else if(channel==1) LPIT_T->TCTRL1 |= LPIT_TCTRL_MODE_32BIT;
	else if(channel==2) LPIT_T->TCTRL2 |= LPIT_TCTRL_MODE_32BIT;
	else  LPIT_T->TCTRL3 |= LPIT_TCTRL_MODE_32BIT;
	//4.Get Timer Counter value
	//	+ Read Current Timer Value: CVALn
	if(channel==0) LPIT_T->TVAL0=1000*(SYS_CLOCK_MHZ/SPLLDIV2)*ms-1;
	else if(channel==1) LPIT_T->TVAL1=1000*(SYS_CLOCK_MHZ/SPLLDIV2)*ms-1;
	else if(channel==2) LPIT_T->TVAL2=1000*(SYS_CLOCK_MHZ/SPLLDIV2)*ms-1;
	else  LPIT_T->TVAL3=1000*(SYS_CLOCK_MHZ/SPLLDIV2)*ms-1;
	if(interrupt==ON){
		LPIT_T->MIER|=(1<<channel);
		NVIC->ISER[1] |= (1U << (16+channel));
		if(channel==0){
			NVIC->IPR[12]|=(5U<<(4+channel*8));
		}
		else if(channel==1){
//			NVIC->IPR[12]|=(5U<<(4+channel*8));
		}
		else if(channel==2){
			NVIC->IPR[12]|=(5U<<(4+channel*8));
		}
		else{
			NVIC->IPR[12]|=(5U<<(4+channel*8));
		}
	}
	
	
	//5.Timer Channel
	//	+ Enable Timer Channel: TCTR?Ln[T_EN]
	if(channel==0) LPIT_T->TCTRL0|=LPIT_TCTRL_T_EN;
	else if(channel==1) LPIT_T->TCTRL1|=LPIT_TCTRL_T_EN;
	else if(channel==2) LPIT_T->TCTRL2|=LPIT_TCTRL_T_EN;
	else  LPIT_T->TCTRL3|=LPIT_TCTRL_T_EN;
	
}
void CLKOUT_Config(uint8_t source,PORT_Typedef *PORT_x,uint8_t pin){
	/*************>>>>>>> STEPS FOLLOWED to Configure all microcontroller<<<<<<<<************
	The below sequence should be followed while CLKOUT configuration:
	1. OPEN CLOCK SOURCE FOR PIN 
	2. CONFIG PIN EXTERNAL CLOCKOUT
	3. Configure SIM_CHIPCTL[CLKOUTSEL]
	4. Configure SIM_CHIPCTL[CLKOUTDIV]
	5. Enable SIM_CHIPCTL[CLKOUTEN]
	********************************************************/





	SIM->CHIPCTL&=~SIM_CHIPCTL_CLKOUTEN;
	while((SIM->CHIPCTL & SIM_CHIPCTL_CLKOUTEN));

	SCG->CLKOUTCNFG&=~(15u<<24);
	//1. OPEN CLOCK SOURCE FOR PIN 
	PORT_Config(PORT_x);
	//2. CONFIG PIN EXTERNAL CLOCKOUT
	if(PORT_x==PORT_B) PORT_x->PCR[pin]|=(5<<8);
	else if (PORT_x==PORT_D) PORT_x->PCR[pin]|=(7<<8);
	else if (PORT_x==PORT_E) PORT_x->PCR[pin]|=(2<<8);
	


	//3. Configure SIM_CHIPCTL[CLKOUTSEL]
	
	if(source==SIM_CHIPCTL_CLKOUTSEL_SPLLDIV2){
		SCG->CLKOUTCNFG=SCG_CLKOUTCNFG_SPLL_CLK;
	}
	else if(source==SIM_CHIPCTL_CLKOUTSEL_SOSCDIV2){
		SCG->CLKOUTCNFG=SCG_CLKOUTCNFG_SOSC_CLK;
	}
	else if(source==SIM_CHIPCTL_CLKOUTSEL_FIRCDIV2){
		SCG->CLKOUTCNFG=SCG_CLKOUTCNFG_FIRC_CLK;
	}
	else if(source==SIM_CHIPCTL_CLKOUTSEL_SIRCDIV2){
		SCG->CLKOUTCNFG=SCG_CLKOUTCNFG_SIRC_CLK;
	}
		SIM->CHIPCTL &= ~(15u<<4);
		SIM->CHIPCTL|=source;

	
	//4. Configure SIM_CHIPCTL[CLKOUTDIV]
		SIM->CHIPCTL &= ~(7u<<8);
		if(source==SIM_CHIPCTL_CLKOUTSEL_SPLLDIV2){
			SIM->CHIPCTL|=SIM_CHIPCTL_CLOCKOUTDIV(5);
		}
		else if(source==SIM_CHIPCTL_CLKOUTSEL_SOSCDIV2){
			SIM->CHIPCTL|=SIM_CHIPCTL_CLOCKOUTDIV(1);
		}
		else if(source==SIM_CHIPCTL_CLKOUTSEL_FIRCDIV2){
			SIM->CHIPCTL|=SIM_CHIPCTL_CLOCKOUTDIV(3);
		}
		else if(source==SIM_CHIPCTL_CLKOUTSEL_SIRCDIV2){
			SIM->CHIPCTL|=SIM_CHIPCTL_CLOCKOUTDIV(1);
		}

	
	
	//5. Enable SIM_CHIPCTL[CLKOUTEN]


	SIM->CHIPCTL|=SIM_CHIPCTL_CLKOUTEN;
	while(!(SIM->CHIPCTL & SIM_CHIPCTL_CLKOUTEN));
	
	
}
void PORT_Config(PORT_Typedef *PORT_x){
	if(PORT_x==PORT_A) PCC->PORTA|=PCC_PORT_CGC;
	else if (PORT_x==PORT_B) PCC->PORTB|=PCC_PORT_CGC;
	else if (PORT_x==PORT_C) PCC->PORTC|=PCC_PORT_CGC;
	else if (PORT_x==PORT_D) PCC->PORTD|=PCC_PORT_CGC;
	else PCC->PORTE|=PCC_PORT_CGC;        
}
void LPSPI_Config(LPSPI_Typedef *LPSPI_x){
	/*************>>>>>>> STEPS FOLLOWED to Configure all microcontroller<<<<<<<<************
	The below sequence should be followed while CLKOUT configuration:
	1. Setting SCK/PCS/SOUT/SIN pin
		+ Enable clock for PORT: PCC[CGC]
		+ Set alternate function pin: PORT_PCR[MUX]
	2. Select source LPSPI
		+ Peripheral Clock Source Select: PCC[PCS]
		+ Enable clock for LPSPI: PCC[CGC]
	3. Setting Clock
		+ Set Prescaler Value: TCR[PRESCALE]
		+ Set divide ratio of the SCK pin: CCR[SCKDIV]
	4. Configures Clock Phase and Polarity
		+ Set Clock Polarity: TCR[CPOL]
		+ Set Clock Phase: TCR[CPHA]
	5. Setting Frame data
		+ Set Frame Size: TCR[FRAMESZ]
		+ Set type of transfer data: TCR[LSBF]
	6. Configures the peripheral chip select
		+ Set Peripheral Chip Select: TCR[PCS]
	7. Setting Transmit/Receive FIFO
		+ Set Receive FIFO Watermark: FCR[RXWATER]
		+ Set Transmit FIFO Watermark: FCR[TXWATER]
		+ Set FIFO underrun: CFGR1[NOSTALL]
	8. Configures LPSPI mode
		+ Set mode: CFGR1[MASTER]
		+ Debug Enable: CR[DBGEN]
	9. Enable LPSPI module
		+ Module Enable: CR[MEN]

	
	********************************************************/
	
	
	//1. Setting SCK/PCS/SOUT/SIN pin
	//	+ Enable clock for PORT: PCC[CGC]
	if(LPSPI_x==LPSPI_0) PCC->LPSPI0|=PCC_LPSPI_CGC;
	else if(LPSPI_x==LPSPI_1) PCC->LPSPI1|=PCC_LPSPI_CGC;
	else PCC->LPSPI2|=PCC_LPSPI_CGC;
	
	
	//	+ Set alternate function pin: PORT_PCR[MUX]
	
		//PIN CS-Enable clock PORT and and configure MUX
		PCC->PORTB|=PCC_PORT_CGC;
		PORT_RESET_MUX(PORT_B,0);
		PORT_SET_MUX(PORT_B,0,0x3);
		
		
		//PIN ClK-Enable clock PORT and and configure MUX
		PCC->PORTB|=PCC_PORT_CGC;
		PORT_RESET_MUX(PORT_B,2);
		PORT_SET_MUX(PORT_B,2,0x3);
		
		//PIN SOUT-Enable clock PORT and and configure MUX
		PCC->PORTB|=PCC_PORT_CGC;
		PORT_RESET_MUX(PORT_B,1);
		PORT_SET_MUX(PORT_B,1,0x3);
		
		//PIN SIN-Enable clock PORT and and configure MUX
		PCC->PORTB|=PCC_PORT_CGC;
		PORT_RESET_MUX(PORT_B,3);
		PORT_SET_MUX(PORT_B,3,0x3);
		
		//2. Select source LPSPI
		//+ Peripheral Clock Source Select: PCC[PCS] /// source is PCS_SPLLDIV2
		if(LPSPI_x==LPSPI_0) PCC->LPSPI0|=PCC_LPSPI_PCS_SPLLDIV2;
		else if(LPSPI_x==LPSPI_1) PCC->LPSPI1|=PCC_LPSPI_PCS_SPLLDIV2;
		else PCC->LPSPI2|=PCC_LPSPI_PCS_SPLLDIV2;
		//+ Enable clock for LPSPI: PCC[CGC]
		if(LPSPI_x==LPSPI_0) PCC->LPSPI0|=PCC_LPSPI_CGC;
		else if(LPSPI_x==LPSPI_1) PCC->LPSPI1|=PCC_LPSPI_CGC;
		else PCC->LPSPI2|=PCC_LPSPI_CGC;

}
void LPI2C_Config(LPI2C_Typedef *LPI2C_x,PORT_Typedef *PORT_x,uint8_t pin_SDA,uint8_t pin_SCL){
	/**** STEPS FOLLOWED  ************
1. Enable the I2C CLOCK and GPIO CLOCK
2. Configure the I2C PINs for ALternate Functions
3. Reset the I2C 	
4. Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
5. Configure the clock control registers
6. Configure the rise time register
7. Program the I2C_CR1 register to enable the peripheral
*******************************************************************************/
	
	//1. Enable the I2C CLOCK and GPIO CLOCK
	//Enable I2C CLOCK
	if(LPI2C_x==LPI2C_0){
		PCC->LPI2C0|=PCC_LPI2C_PCS_SPLLDIV2;
		PCC->LPI2C0|=PCC_LPI2C_CGC;
	}
	else{
		PCC->LPI2C1|=PCC_LPI2C_PCS_SPLLDIV2;
		PCC->LPI2C1|=PCC_LPI2C_CGC;
	}
	//ENABLE GPIO CLOCK
	PORT_Config(PORT_x);
	
	//2. Configure the I2C PINs for ALternate Functions
	if(PORT_x==PORT_A){
		PORT_x->PCR[pin_SDA]|=(3<<8);
		PORT_x->PCR[pin_SCL]|=(3<<8);
	}
	else if(PORT_x==PORT_B){
		PORT_x->PCR[pin_SDA]|=(2<<8);
		PORT_x->PCR[pin_SCL]|=(2<<8);
	}
	//3. Reset the I2C 	
	//4. Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
	//Setup with Clock frquency =8MHZ mode Fast Baudrate 400kbps PRescale 0x0
	LPI2C_x->MCCR0=0;
	LPI2C_x->MCCR0|=LPI2C_MCCR0_DATAVD(0x02);
	LPI2C_x->MCCR0|=LPI2C_MCCR0_SETHOLD(0x04);
	LPI2C_x->MCCR0|=LPI2C_MCCR0_CLKHI(0x05);
	LPI2C_x->MCCR0|=LPI2C_MCCR0_CLKLO(0x0B);
	
	// [24] DATAVD  0x02
	// [16] SETHOLD 0x04
	// [8]  CLKHI   0x05
	// [0]  CLKLO   0x0B

	// Master Interrupt Enable Register (MIER)
	LPI2C_x->MIER|=LPI2C_MIER_PLTIE;
	LPI2C_x->MIER|=LPI2C_MIER_FEIE;
	LPI2C_x->MIER|=LPI2C_MIER_ALIE;
	LPI2C_x->MIER|=LPI2C_MIER_NDIE;
	// [14] DMIE = 0  (Data match interrupt disabled)
	// [13] PLTIE = 1 (Pin low timeout interrupt enabled)
	// [12] FEIE = 1  (FIFO error interrupt enabled)
	// [11] ALIE = 1  (Arbitration lost interrupt enabled)
	// [10] NDIE = 1  (NACK detect interrupt enabled)
	// [9]  SDIE = 0  (STOP detect interrupt disabled)
	// [8]  EPIE = 0  (End packet interrupt disabled)

	// Master Configuration Register 0
	LPI2C_x->MCFGR0 = 0x0000;
	// [9] RDMO = 0    (Received data is stored in the receive FIFO as normal)
	// [8] CIRFIFO = 0 (Circular FIFO is disabled)
	// [2] HRSEL = 0   (Host request input is pin HREQ)
	// [1] HRPOL = 0   (Active low)
	// [0] HREN = 0    (Host request input is disabled)

	// Master Configuration Register 1
	LPI2C_x->MCFGR1|=LPI2C_MCFGR1_TIMECFG;
	LPI2C_x->MCFGR1|=LPI2C_PRESCALE_DIV1;
	// [26-14] PINCFG     = 0b000 (LPI2C configured for 2-pin open drain mode)
	// [16-16] MATCFG     = 0b000 (Match disabled)
	// [10]    TIMECFG    = 1     (Pin Low Timeout Flag will set if either SCL or SDA is low for longer than the configured timeout)
	// [9]     IGNACK     = 0     (LPI2C Master will receive ACK and NACK normally)
	// [8]     AUTOSTOP   = 0     (Without autostop generation)
	// [2-0]   PRESCALE   = 0b000 (Divided by 1)

	// Master Configuration Register 2
	LPI2C_x->MCFGR2|=LPI2C_FILTSCL(0x0);
	LPI2C_x->MCFGR2|=LPI2C_FILTSDA(0x0); //>FILTSDA
	LPI2C_x->MCFGR2|=LPI2C_BUSIDLE(0x22);
	// [27-24] FILTSDA = 0x0  (Disable the glitch filter)
	// [19-16] FILTSDL = 0x0  (Disable the glitch filter)
	// [11-0]  BUSIDLE = 0x1F (Bus idle timeout period in clock cycles) min> {2*(SETHOLD+CLKLo+2),CLKHI+1}

	// Master Configuration Register 3
	LPI2C_x->MCFGR3 = 0x00000200;
	// [19-8] PINLOW = 0x0002 (Pin Low Timeout enabled)

	// Master FIFO Control Register
	LPI2C_x->MFCR|= LPI2C_MFCR_RXWATER(0);
	LPI2C_x->MFCR|= LPI2C_MFCR_TXWATER(0);
	// [17-16] RXWATER = 0 (Receive FIFO watermark)
	// [1-0]   TXWATER = 0 (Transmit FIFO watermark)

	// Master Control Register
	LPI2C_x->MCR|=LPI2C_MCR_RRF;
	LPI2C_x->MCR|=LPI2C_MCR_RTF;
	LPI2C_x->MCR|=LPI2C_MCR_RST;
	LPI2C_x->MCR|=LPI2C_MCR_MEN;
	// [9] RRF = 1   (Receive FIFO is reset)
	// [8] RTF = 1   (Transmit FIFO is reset)
	// [3] DBGEN = 0 (Master is disabled in debug mode)
	// [2] DOZEN = 0 (Master is disabled in Doze mode)
	// [1] RST = 0   (Master logic is not reset)
	// [0] MEN = 1   (Master logic is enabled)
}

