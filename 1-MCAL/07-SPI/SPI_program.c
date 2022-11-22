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

static u8 SPI_u8State = IDLE;

//Array including all SPI Base Addresses
static SPI_t *const SPI_pSPI_tPorts[3]={SPI1,SPI2,SPI3};

//Initializng SPI
void SPI_voidInit(u8 Copy_u8SpiPort,u8 Copy_u8Role)
{	
	// Select SPI
	if((Copy_u8SpiPort<SPI1_PORT) || (Copy_u8SpiPort>SPI3_PORT))
		Copy_u8SpiPort=SPI1_PORT;
	SPI_t *SPI = SPI_pSPI_tPorts[Copy_u8SpiPort];
	
	// Initial Configurations
	SPI->CR1=SPI_REG_INIT;
	
	// Master or slave selection
	Copy_u8Role == SPI_SLAVE ? CLR_BIT(SPI->CR1,SPI_CR1_MSTR):SET_BIT(SPI->CR1,SPI_CR1_MSTR);
	
	// Baud Rate
	SPI->CR1&=BAUD_RATE_MASK;
	SPI->CR1|=SPI_BAUD_RATE;
	
	// Enable Peripheral
	SET_BIT(SPI->CR1,SPI_CR1_SPE);
}

//Transmitting and recieving data
u8 SPI_u8Transcieve(u8 Copy_u8SpiPort,u16 Copy_u16TransmitData, u16* Copy_pu16RecivedData)
{
	u8 Local_u8ErrorState = OK;
	u32 Local_u32Counter=0;
	
	if((Copy_u8SpiPort<SPI1_PORT) || (Copy_u8SpiPort>SPI3_PORT))
		Copy_u8SpiPort=SPI1_PORT;
	SPI_t *SPI = SPI_pSPI_tPorts[Copy_u8SpiPort];

	if(Copy_pu16RecivedData!=NULL)
	{
		if(SPI_u8State==IDLE)
		{	
			// Set State to busy
			SPI_u8State=BUSY;
	
			// Send Data
			SPI->DR = Copy_u16TransmitData;
	
			// Wait on Busy Flag
			while(((GET_BIT(SPI->SR, SPI_SR_BSY))==0) && (Local_u32Counter<SPI_u32Timeout))
			{
				Local_u32Counter++;
			}
			// Recieve Data
			if(Local_u32Counter==SPI_u32Timeout)
				Local_u8ErrorState = TIMEOUT_STATE;
			else
				*Copy_p168RecivedData = SPI->DR;
			
			// Set State to idle
			SPI_u8State=IDLE;
		}
		else
			Local_u8ErrorState=BUSY_STATE;
	}
	else
		Local_u8ErrorState=NULL_POINTER;

	return Local_u8ErrorState;
}