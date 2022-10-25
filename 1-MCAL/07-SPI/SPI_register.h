/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):SPI 			 ***********************/
/***********************   DATA : 25-10-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_


//ADC Registers
typedef struct
{				
  volatile u32 SPI_CR1;   
  volatile u32 SPI_CR2;  
  volatile u32 SPI_SR;  
  volatile u32 SPI_DR;
  volatile u32 SPI_CRCPR;   
  volatile u32 SPI_RXCRCR;  
  volatile u32 SPI_TXCRCR;  
  volatile u32 SPI_I2SCFGR;
  volatile u32 SPI_I2SPR;
}SPI_t;

//SPI Base Addresses
#define SPI1						((volatile SPI_t *)0x40013000)
#define SPI2						((volatile SPI_t *)0x40003800)
#define SPI3						((volatile SPI_t *)0x40003C00)

#endif
