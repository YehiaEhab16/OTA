/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):SPI 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/


#include "../../4-Library/STD_TYPES.h"
#include "../../4-Library/BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_register.h"
#include "SPI_private.h"

static u8 SPI_u8State = SPI_IDLE;

// Getting SPI Port and setting correct base address
static SPI_t *SPI_Get(u8 Copy_u8SpiPort)
{
	switch(Copy_u8SpiPort)
	{
		case SPI1_PORT: return (SPI_t*)SPI1;
		case SPI2_PORT: return (SPI_t*)SPI2;
		case SPI3_PORT: return (SPI_t*)SPI3;
		default:     	return (SPI_t*)SPI1;
	}
}

//Initializing SPI
void SPI_voidInit(SPI_s* Copy_pSPI_sData)
{	
	// Select SPI
	SPI_t *SPI = SPI_Get(Copy_pSPI_sData->SPI_u8SpiPort);
	
	// Initial Configurations
	SPI->CR1=SPI_REG_INIT;
	
	// Master or slave selection
	if(Copy_pSPI_sData->SPI_u8Role== SPI_SLAVE)
	{
		CLR_BIT(SPI->CR1,SPI_CR1_MSTR);
		SET_BIT(SPI->CR1,SPI_CR1_SSM);
		SET_BIT(SPI->CR1,SPI_CR1_SSI);
	}
	else
		SET_BIT(SPI->CR1,SPI_CR1_MSTR);
	
	// Baud Rate
	SPI->CR1&=BAUD_RATE_MASK;
	SPI->CR1|=SPI_BAUD_RATE;
	
	SET_BIT(SPI->CR1,SPI_CR1_SPE);

}

//Transmitting and recieving Buffer Size
u8 SPI_u8Transcieve(SPI_s* Copy_pSPI_sData)
{
	u8 Local_u8ErrorState = OK, Local_u8Counter;
	u32 Local_u32Counter=0;
	
	SPI_t *SPI = SPI_Get(Copy_pSPI_sData->SPI_u8SpiPort);

	if((Copy_pSPI_sData->SPI_pu16TransmitData!=NULL))
		for(Local_u8Counter=0;Local_u8Counter<Copy_pSPI_sData->SPI_u8BufferSize; Local_u8Counter++)
		{
			if(SPI_u8State==SPI_IDLE)
			{	
				// Set State to SPI_BUSY
				SPI_u8State=SPI_BUSY;

				if(Copy_pSPI_sData->SPI_u8Role==SPI_MASTER)
					GPIO_u8SetPinValue(Copy_pSPI_sData->SPI_u8SlaveSelectPort
								,Copy_pSPI_sData->SPI_u8SlaveSelectPin,GPIO_PIN_LOW);
					
				// Send Data
 				SPI->DR = Copy_pSPI_sData->SPI_pu16TransmitData[0];
	
				// Wait on SPI_BUSY Flag
				while(((GET_BIT(SPI->SR, SPI_SR_BSY))==1) && (Local_u32Counter<SPI_TIMEOUT))
					Local_u32Counter++;
				// Recieve Data
				if(Local_u32Counter==SPI_TIMEOUT)
					Local_u8ErrorState = TIMEOUT_STATE;
				else
					Copy_pSPI_sData->SPI_pu16RecivedData[Local_u8Counter] = SPI->DR;
				
				if(Copy_pSPI_sData->SPI_u8Role==SPI_MASTER)
					GPIO_u8SetPinValue(Copy_pSPI_sData->SPI_u8SlaveSelectPort
								,Copy_pSPI_sData->SPI_u8SlaveSelectPin,GPIO_PIN_HIGH);
			
				// Set State to SPI_IDLE
				SPI_u8State=SPI_IDLE;
			}
			else
				Local_u8ErrorState=BUSY_STATE;
		}

	else
		Local_u8ErrorState = NULL_POINTER;
	
	return Local_u8ErrorState;
}
