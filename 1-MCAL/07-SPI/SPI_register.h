/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):SPI 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_


// ADC Registers
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

// SPI Base Addresses
#define SPI1					((volatile SPI_t *)0x40013000)
#define SPI2					((volatile SPI_t *)0x40003800)
#define SPI3					((volatile SPI_t *)0x40003C00)

// SPI Pins
#define SPI_CR1_CPHA			0
#define SPI_CR1_CPOL			1
#define SPI_CR1_MSTR			2
#define SPI_CR1_BR0				3
#define SPI_CR1_BR1				4
#define SPI_CR1_BR2				5
#define SPI_CR1_SPE				6
#define SPI_CR1_LSBFIRST		7
#define SPI_CR1_SSI				8
#define SPI_CR1_SSM				9
#define SPI_CR1_RXONLY			10
#define SPI_CR1_DFF				11
#define SPI_CR1_CRCNEXT			12
#define SPI_CR1_CRCEN			13
#define SPI_CR1_BIDIOE			14
#define SPI_CR1_BIDIMODE		15

#define SPI_SR_BSY				7

#endif
