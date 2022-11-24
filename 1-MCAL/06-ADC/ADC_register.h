
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_ 

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
  volatile u32 JDR1[4];
  volatile u32 DR;
}ADC_t;

// Bits ADC Status Register 
#define EOC			1
#define STRT		4
#define JSTRT		3

// Bits ADC control register 2

#define ADON 		0
#define ALIGN 		11
#define JSWSTART    21
#define SWSTART     22
#define CONT		1


// Bits of ADC control register 1
#define JEOCIE		7
#define EOCIE		5

#define ADC   ((volatile ADC_t *)(0x40012400))





#endif
