/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :HAL	                 ***********************/
/***********************   SWC (DRIVER):TFT 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

// Functions Implementation
#include "../../4-Library/STD_TYPES.h"

#include "../../1-MCAL/01-GPIO/GPIO_interface.h"
#include "../../1-MCAL/05-STK/STK_interface.h"
#include "../../1-MCAL/07-SPI/SPI_interface.h"

#include "TFT_config.h"
#include "TFT_interface.h"
#include "TFT_private.h"

// Initializing TFT
void TFT_voidInit(void)
{
	STK_voidInit();
	
	// Reset Pulse
	GPIO_u8SetPinValue(TFT_CTRL_PORT,TFT_RST_PIN,GPIO_PIN_HIGH);
	STK_voidDelay(100);
	GPIO_u8SetPinValue(TFT_CTRL_PORT,TFT_RST_PIN,GPIO_PIN_LOW);
	STK_voidDelay(1);
	GPIO_u8SetPinValue(TFT_CTRL_PORT,TFT_RST_PIN,GPIO_PIN_HIGH);
	STK_voidDelay(100);
	GPIO_u8SetPinValue(TFT_CTRL_PORT,TFT_RST_PIN,GPIO_PIN_LOW);
	STK_voidDelay(100);
	GPIO_u8SetPinValue(TFT_CTRL_PORT,TFT_RST_PIN,GPIO_PIN_HIGH);
	STK_voidDelay(120000);
	
	// Sleep Out Command
	TFT_voidSendCommand(0x11);
	STK_voidDelay(150000);
	
	// Color Mode
	TFT_voidSendCommand(0x3A);
	TFT_voidSendData(0x05);
	
	// Display ON
	TFT_voidSendCommand(0x29);
}

// Sending Command to TFT
void TFT_voidSendCommand(u8 Copy_u8Command)
{
	SPI_s Local_SPi_sCom = {SPI1_PORT,SPI_MASTER,SPI_PORTA,SPI_PIN9,1};
	
	GPIO_u8SetPinValue(TFT_CTRL_PORT,TFT_A0_PIN,GPIO_PIN_LOW);
	Local_SPi_sCom.SPI_pu16TransmitData[0]=Copy_u8Command;
	SPI_u8Transcieve(&Local_SPi_sCom);
}

// Sending Data to TFT
void TFT_voidSendData(u8 Copy_u8Data)
{
	SPI_s Local_SPi_sCom = {SPI1_PORT,SPI_MASTER,SPI_PORTA,SPI_PIN9,1};
	
	GPIO_u8SetPinValue(TFT_CTRL_PORT,TFT_A0_PIN,GPIO_PIN_HIGH);
	Local_SPi_sCom.SPI_pu16TransmitData[0]=Copy_u8Data;
	SPI_u8Transcieve(&Local_SPi_sCom);
}

// Displaying on TFT
void TFT_voidDisplayImage(const u8* Copy_pu8Image)
{
	u16 Local_u16Counter;
	
	// Set X address
	TFT_voidSendCommand(0x2A);
	// Start Address
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	// End Address
	TFT_voidSendData(0);
	TFT_voidSendData(127);
	
	// Set Y address
	TFT_voidSendCommand(0x2B);
	// Start Address
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	// End Address
	TFT_voidSendData(0);
	TFT_voidSendData(159);
	
	for(Local_u16Counter;Local_u16Counter<TFT_PIXELS;Local_u16Counter++)
	{
		// High Byte
		TFT_voidSendData(Copy_pu8Image[Local_u16Counter]>>8);
		// Low Byte
		TFT_voidSendData(Copy_pu8Image[Local_u16Counter] & 0x00FF);
	}
}
