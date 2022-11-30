/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):SPI 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

// Initialization
#define SPI_CLK_PHASE			SECOND_CLK		// FIRST_CLK or SECOND_CLK
#define SPI_CLK_POLARITY		1
#define SPI_BAUD_RATE			DIVIDE_BY_32	// 2 -> DIVIDE_BY_2 -> 256
#define SPI_LSB_FIRST			SPI_DISABLE		// SPI_DISABLE or SPI_ENABLE
#define SPI_RX_MODE				FULL_DUPLEX		// FULL_DUPLEX or OUT_DISABLED
#define SPI_DF_FORMAT			BITS_8			// BITS_8 or BITS_16
#define SPI_CRC_TRANSFER		SPI_DISABLE		// SPI_DISABLE or SPI_ENABLE
#define SPI_CRC_CALC			SPI_DISABLE		// SPI_DISABLE or SPI_ENABLE
#define SPI_BIDIRECTION			SPI_DISABLE		// SPI_DISABLE or SPI_ENABLE

// Timeout
#define SPI_TIMEOUT				10000UL


#endif
