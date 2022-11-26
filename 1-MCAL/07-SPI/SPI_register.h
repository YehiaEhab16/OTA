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


//GPIO Registers
typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_t;

//GPIO Base Addresses
#define GPIOA					((volatile GPIO_t*)0x40010800)
#define GPIOB					((volatile GPIO_t*)0x40010C00)
#define GPIOC					((volatile GPIO_t*)0x40011000)

// SPI Registers
typedef struct
{				
  volatile u32 CR1;
  volatile u32 CR2;
  volatile u32 SR;
  volatile u32 DR;
  volatile u32 CRCPR;
  volatile u32 RXCRCR;
  volatile u32 TXCRCR;
  volatile u32 I2SCFGR;
  volatile u32 I2SPR;
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
