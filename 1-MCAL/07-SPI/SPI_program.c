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
		CLR_BIT(SPI->CR1,SPI_CR1_MSTR);
	else
	{
		SET_BIT(SPI->CR1,SPI_CR1_SSI);
		SET_BIT(SPI->CR1,SPI_CR1_SSM);
		SET_BIT(SPI->CR1,SPI_CR1_MSTR);
	}

	// Baud Rate
	SPI->CR1&=BAUD_RATE_MASK;
	SPI->CR1|=SPI_BAUD_RATE;

	// DMA for TX and RX
	SET_BIT(SPI->CR2,SPI_CR2_RXDMAEN);
	SET_BIT(SPI->CR2,SPI_CR2_TXDMAEN);
	
	// Enable Peripheral
	SET_BIT(SPI->CR1,SPI_CR1_SPE);
}

//Transmitting and recieving Buffer Size
u8 SPI_u8Transcieve(SPI_s* Copy_pSPI_sData)
{
	u8 Local_u8ErrorState = OK, Local_u8Counter;
	u32 Local_u32Counter=0;
	
	SPI_t *SPI = SPI_Get(Copy_pSPI_sData->SPI_u8SpiPort);

	if((Copy_pSPI_sData->SPI_pu16TransmitData!=NULL) && (Copy_pSPI_sData->SPI_pu16RecivedData!=NULL))
		for(Local_u8Counter=0;Local_u8Counter<Copy_pSPI_sData->SPI_u8BufferSize; Local_u8Counter++)
		{
			if(SPI_u8State==SPI_IDLE)
			{	
				// Set State to SPI_BUSY
				SPI_u8State=SPI_BUSY;

				if(Copy_pSPI_sData->SPI_u8Role==SPI_MASTER)
					GPIO_u8SetPinValue(Copy_pSPI_sData->SPI_u8SlaveSelectPort
								,Copy_pSPI_sData->SPI_u8SlaveSelectPin,GPIO_PIN_LOW);

				while(GET_BIT(SPI->SR,SPI_SR_TXE)==0)
					Local_u32Counter++;

				if(Local_u32Counter==SPI_TIMEOUT)
					Local_u8ErrorState = TIMEOUT_STATE;

				else
				{
					// Send Data
					SPI->DR = 5;//Copy_pSPI_sData->SPI_pu16TransmitData[Local_u8Counter];

					// Wait on SPI_BUSY Flag
					Local_u32Counter=0;
					while(((GET_BIT(SPI->SR, SPI_SR_BSY))==0) && (Local_u32Counter<SPI_TIMEOUT))
						Local_u32Counter++;
				
					// Recieve Data
					if(Local_u32Counter==SPI_TIMEOUT)
						Local_u8ErrorState = TIMEOUT_STATE;
					else
					{
						Local_u32Counter=0;
						while(GET_BIT(SPI->SR,SPI_SR_RXNE)==0)
							Local_u32Counter++;

						if(Local_u32Counter==SPI_TIMEOUT)
							Local_u8ErrorState = TIMEOUT_STATE;
						else
							Copy_pSPI_sData->SPI_pu16RecivedData[Local_u8Counter] = SPI->DR;
					}
				}
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
