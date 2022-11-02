/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):ADC 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

//ADC Registers
typedef struct
{				
  volatile u32 SR;   
  volatile u32 CR1;  
  volatile u32 CR2;  
  volatile u32 SMPR1;
  volatile u32 SMPR2;
  volatile u32 JOFR1;
  volatile u32 JOFR2;
  volatile u32 JOFR3;
  volatile u32 JOFR4;
  volatile u32 HTR;   
  volatile u32 LTR;  
  volatile u32 SQR1;  
  volatile u32 SQR2;
  volatile u32 SQR3;
  volatile u32 JSQR;
  volatile u32 JDR1;
  volatile u32 JDR2;
  volatile u32 JDR3;      
  volatile u32 JDR4;
  volatile u32 DR;
}ADC_t;


//ADC Base Addresses
#define ADC1						((volatile ADC_t *)0x40012400)
#define ADC2						((volatile ADC_t *)0x40012800)
#define ADC3						((volatile ADC_t *)0x40013C00)

//CR1 Register
#define ADC_CR1_EOCIE			 	5
#define ADC_CR1_JEOCIE			 	7
#define ADC_CR1_SCAN             	8
#define ADC_CR1_DISCEN           	11
#define ADC_CR1_DISCNUM			 	13
#define ADC_CR1_JAWDEN           	22
#define ADC_CR1_AWDEN            	23

/*CR2 Register*/
#define	ADC_CR2_ADON              	0
#define	ADC_CR2_CONT              	1
#define	ADC_CR2_CAL       	      	2
#define	ADC_CR2_RSTCAL  		  	3
#define	ADC_CR2_DMA			      	8
#define	ADC_CR2_ALIGN             	11
#define	ADC_CR2_JEXTSEL_0         	12
#define	ADC_CR2_JEXTSEL_1         	13
#define	ADC_CR2_JEXTSEL_2         	14
#define	ADC_CR2_JEXTTRIG          	15
#define	ADC_CR2_EEXTSEL    		  	17
#define	ADC_CR2_EXTTRIG			  	20
#define	ADC_CR2_SWSTART           	22

// SMPR2 Register
#define ADC_SMPR2_SMP0     			0
#define ADC_SMPR2_SMP1     			3
#define ADC_SMPR2_SMP2     			6
#define ADC_SMPR2_SMP3     			9
#define ADC_SMPR2_SMP4     			12
#define ADC_SMPR2_SMP5     			15
#define ADC_SMPR2_SMP6     			18
#define ADC_SMPR2_SMP7     			21
#define ADC_SMPR2_SMP8     			24
#define ADC_SMPR2_SMP9     			27

// SMPR1 Register
#define ADC_SMPR1_SMP10    			0
#define ADC_SMPR1_SMP11    			3
#define ADC_SMPR1_SMP12    			6
#define ADC_SMPR1_SMP13    			9
#define ADC_SMPR1_SMP14    			12
#define ADC_SMPR1_SMP15    			15
#define ADC_SMPR1_SMP16    			18
#define ADC_SMPR1_SMP17    			21

// SR Register
#define ADC_SR_AWD				  	0
#define ADC_SR_EOC                	1
#define ADC_SR_JEOC               	2
#define ADC_SR_JSTRT              	3
#define ADC_SR_STRT               	4


#endif
