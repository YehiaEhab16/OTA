/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :SERVICE                   ***********************/
/***********************   SWC (DRIVER):SPI 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/


#include "../../4-Library/STD_TYPES.h"
#include "../../4-Library/BIT_MATH.h"

#include "../../1-MCAL/01-GPIO/GPIO_interface.h"
#include "../../1-MCAL/07-SPI/SPI_interface.h"

#include "SPI_S_interface.h"
#include "SPI_S_config.h"
#include "SPI_S_private.h"



// Initializing SPI
void SPI_S_voidInit(SPI_s* Copy_pSPI_sData)
{
	SPI_voidInit(Copy_pSPI_sData->SPI_u8SpiPort,Copy_pSPI_sData->SPI_u8Role);
}

//Transmitting and recieving data
u8 SPI_S_u8Transcieve(SPI_s* Copy_pSPI_sData)
{
	u8 Local_u8ErrorState = OK;
	
	//Clear Slave Select Pin
	GPIO_u8SetPinValue(Copy_pSPI_sData->SPI_u8SlaveSelectPort,
								Copy_pSPI_sData->SPI_u8SlaveSelectPin,GPIO_PIN_LOW);
	
	// Transcieve
	Local_u8ErrorState = SPI_u8Transcieve(Copy_pSPI_sData->SPI_u8SpiPort,
								Copy_pSPI_sData->SPI_pu16TransmitData[0],Copy_pSPI_sData->SPI_pu16RecivedData);
	
	//Set Slave Select Pin
	GPIO_u8SetPinValue(Copy_pSPI_sData->SPI_u8SlaveSelectPort,
								Copy_pSPI_sData->SPI_u8SlaveSelectPin,GPIO_PIN_HIGH);
	
	return Local_u8ErrorState;
}

//Transmitting and recieving Buffer Size
u8 SPI_S_u8TranscieveBuffer(SPI_s* Copy_pSPI_sData)
{
	u8 Local_u8ErrorState = OK, Local_u8Counter;

	if((Copy_pSPI_sData->SPI_pu16TransmitData!=NULL) && (Copy_pSPI_sData->SPI_pu16RecivedData!=NULL))
		for(Local_u8Counter=0;Local_u8Counter<Copy_pSPI_sData->SPI_u8BufferSize; Local_u8Counter++)
			Local_u8ErrorState = SPI_S_u8Transcieve(Copy_pSPI_sData);

	else
		Local_u8ErrorState = NULL_POINTER;
	
	return Local_u8ErrorState;
}
