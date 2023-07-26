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
#define CMD55_ARG		0×00000000
#define CMD55_CRC		0×00

#define ACMD41			41
#define ACMD41_ARG		0×40000000
#define ACMD41_CRC		0×00

#define CMD0			0
#define CMD0_ARG		0×00000000
#define CMD0_CRC		0×94

#define CMD58			58
#define CMD58_ARG		0×00000000
#define CMD58_CRC		0×00

// Card Type
#define SD_V1_SDSC		1
#define SD_V2_SDSC		2
#define SD_V2_SDHC_SDXC		3

#define SPI_CARD_CS_DISABLE()	SET_BIT(GPIO_PORTA,GPIO_PIN_4)

#define SPI_CARD_CS_ENABLE()    CLR_BIT(GPIO_PORTA,GPIO_PIN_4)



static void SD_voidAssertCs(void);

static void SD_voidDeassertCs(void);



#endif
