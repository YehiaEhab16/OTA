/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :HAL	                 ***********************/
/***********************   SWC (DRIVER):SDC 			 ***********************/
/***********************   DATE : 6-4-2023 				 ***********************/
/*******************************************************************************/
/*******************************************************************************/

/* Preprocessor file guard 
   Static functions*/
#ifndef SDC_PRIVATE_H_
#define SDC_PRIVATE_H_

#define CMD55			55
#define CMD55_ARG		0x00000000
#define CMD55_CRC		0x00

#define ACMD41			41
#define ACMD41_ARG		0x40000000
#define ACMD41_CRC		0x00

#define CMD0			0
#define CMD0_ARG		0x00000000
#define CMD0_CRC		0x94

#define CMD8			8
#define CMD8_ARG		0x0000001AA
#define CMD8_CRC		0x86

#define F_CPU			8000000
#define SD_BUFFER_SIZE 	512+1

#define CMD17                   17
#define CMD17_CRC               0x00
#define SD_MAX_READ_ATTEMPTS    (0.1 * F_CPU) / (2 * 8)

#define CMD58			58
#define CMD58_ARG		0x00000000
#define CMD58_CRC		0x00

// Card Type
#define SD_V1_SDSC		1
#define SD_V2_SDSC		2
#define SD_V2_SDHC_SDXC		3

// R1 Response
#define PARAM_ERROR(X)		X & 0b01000000
#define ADDR_ERROR(X)		X & 0b00100000
#define ERASE_SEQ_ERROR(X)	X & 0b00010000
#define CRC_ERROR(X)		X & 0b00001000
#define ILLEGAL_CMD(X)		X & 0b00000100
#define ERASE_RESET(X)		X & 0b00000010
#define IN_IDLE(X)			X & 0b00000001

#define SPI_CARD_CS_DISABLE()	GPIO_u8SetPinValue(GPIO_PORTA, GPIO_PIN_4,GPIO_PIN_HIGH)

#define SPI_CARD_CS_ENABLE()    GPIO_u8SetPinValue(GPIO_PORTA, GPIO_PIN_4,GPIO_PIN_LOW)


static void SD_voidAssertCs(void);

static void SD_voidDeassertCs(void);



#endif
