/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :HAL	                 ***********************/
/***********************   SWC (DRIVER):SDC 			 ***********************/
/***********************   DATE : 6-4-2023 				 ***********************/
/*******************************************************************************/
/*******************************************************************************/

// Functions Implementation
#include "../../4-Library/STD_TYPES.h"

#include "../../1-MCAL/01-GPIO/GPIO_interface.h"
#include "../../1-MCAL/07-SPI/SPI_interface.h"

#include "SDC_config.h"
#include "SDC_interface.h"
#include "SDC_private.h"


// Output Sound
void SDC_voidInit(void)
{
	// SPI Init
	SPI_s Local_SPI_sSdCard = {SPI1_PORT, SPI_MASTER, SPI_PORTA, SPI_PIN8,1,0xFF};
	SPI_voidInit(&Local_SPI_sSdCard);

	// 10 dummy bytes
	u8 Local_u8Iterator;
	for(Local_u8Iterator=0;Local_u8Iterator++;Local_u8Iterator<=10)
		SPI_u8Transcieve(&Local_SPI_sSdCard);

	// CMD0 command
	Local_SPI_sSdCard.SPI_u8BufferSize=6;
	Local_SPI_sSdCard.SPI_pu16TransmitData[0]=0x40;
	Local_SPI_sSdCard.SPI_pu16TransmitData[1]=0x00;
	Local_SPI_sSdCard.SPI_pu16TransmitData[2]=0x00;
	Local_SPI_sSdCard.SPI_pu16TransmitData[3]=0x00;
	Local_SPI_sSdCard.SPI_pu16TransmitData[4]=0x00;
	Local_SPI_sSdCard.SPI_pu16TransmitData[5]=0x95;
	SPI_u8Transcieve(&Local_SPI_sSdCard);

	// Dummy byte
	Local_SPI_sSdCard.SPI_u8BufferSize=1;
	Local_SPI_sSdCard.SPI_pu16TransmitData[0]=0xFF;
	SPI_u8Transcieve(&Local_SPI_sSdCard);

	// CMD8 command
	Local_SPI_sSdCard.SPI_u8BufferSize=6;
	Local_SPI_sSdCard.SPI_pu16TransmitData[0]=0x48;
	Local_SPI_sSdCard.SPI_pu16TransmitData[1]=0x00;
	Local_SPI_sSdCard.SPI_pu16TransmitData[2]=0x00;
	Local_SPI_sSdCard.SPI_pu16TransmitData[3]=0x01;
	Local_SPI_sSdCard.SPI_pu16TransmitData[4]=0xAA;
	Local_SPI_sSdCard.SPI_pu16TransmitData[5]=0x87;
	SPI_u8Transcieve(&Local_SPI_sSdCard);

	// CMD1 command
	Local_SPI_sSdCard.SPI_pu16TransmitData[0]=0x41;
	Local_SPI_sSdCard.SPI_pu16TransmitData[1]=0x00;
	Local_SPI_sSdCard.SPI_pu16TransmitData[2]=0x00;
	Local_SPI_sSdCard.SPI_pu16TransmitData[3]=0x00;
	Local_SPI_sSdCard.SPI_pu16TransmitData[4]=0x00;
	Local_SPI_sSdCard.SPI_pu16TransmitData[5]=0x94;
	SPI_u8Transcieve(&Local_SPI_sSdCard);
}
