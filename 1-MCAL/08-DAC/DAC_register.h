/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):DAC 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef DAC_REGISTER_H_
#define DAC_REGISTER_H_


//DAC Registers
typedef struct
{				
  volatile u32 DAC_CR;
  volatile u32 DAC_SWTRIGR;
  volatile u32 DAC_DHR12R1;
  volatile u32 DAC_DHR12L1;
  volatile u32 DAC_DHR8R1;
  volatile u32 DAC_DHR12R2;
  volatile u32 DAC_DHR12L2;
  volatile u32 DAC_DHR8R2;
  volatile u32 DAC_DHR12RD;
  volatile u32 DAC_DHR12LD;
  volatile u32 DAC_DHR8RD;
  volatile u32 DAC_DOR1;
  volatile u32 DAC_DOR2;
}DAC_t;


//DAC Base Address
#define DAC						((volatile DAC_t *)0x40007400)


#endif
