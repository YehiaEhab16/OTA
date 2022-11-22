/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):SPI 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


// Concatenation Function
#define CONC2(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELPER2(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER2(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)     0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0

// Init Register
#define SPI_REG_INIT		CONC2(SPI_BIDIRECTION,SPI_BIDIRECTION,SPI_CRC_CALC,SPI_CRC_TRANSFER,SPI_DF_FORMAT,SPI_RX_MODE,SPI_SLAVE_SM,SPI_INT_SS,SPI_LSB_FIRST,SPI_DISABLE,SPI_DISABLE,SPI_DISABLE,SPI_DISABLE,SPI_DISABLE,SPI_CLK_POLARITY,SPI_CLK_PHASE)

// States
#define SPI_DISABLE			0
#define SPI_ENABLE			1

// Clock Polarity
#define FIRST_CLK			0
#define SECOND_CLK			1

// Baud Rate
#define BAUD_RATE_MASK		0xFFC7
#define DIVIDE_BY_2			0
#define DIVIDE_BY_4			1
#define DIVIDE_BY_8			2
#define DIVIDE_BY_16		3
#define DIVIDE_BY_32		4
#define DIVIDE_BY_64		5
#define DIVIDE_BY_128		6
#define DIVIDE_BY_256		7

// Recieve Mode
#define FULL_DUPLEX			0
#define OUT_DISABLED		1

// Data Frame Format
#define BITS_8				0
#define BITS_16				1


#endif
