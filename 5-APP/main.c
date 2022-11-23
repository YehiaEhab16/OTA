/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :Application            ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#include "../4-Library/STD_TYPES.h"

#include "../1-MCAL/01-GPIO/GPIO_interface.h"

#include "../3-SERVICE/01-SYS/SYS_interface.h"
#include "../3-SERVICE/02-SPI_S/SPI_S_interface.h"

void main(void)
{
	//SYS_voidInit();
	SPI_s Local_SPI_sCom={SPI1_PORT,SPI_MASTER,SPI_PORTA,SPI_PIN0};
	SPI_S_voidInit(&Local_SPI_sCom);
	
	while(1)
	{
		
	}
}
