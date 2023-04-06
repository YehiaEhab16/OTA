/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :Application            ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#include "../4-Library/STD_TYPES.h"

#include "../1-MCAL/01-GPIO/GPIO_interface.h"
#include "../1-MCAL/02-RCC/RCC_interface.h"
#include "../1-MCAL/05-STK/STK_interface.h"

#include "../2-HAL/03-TFT/TFT_interface.h"
#include "../2-HAL/04-SPK/SPK_interface.h"

#include "../3-SERVICE/01-SYS/SYS_interface.h"

#include "song.h"

void PlaySong(void);

void main(void)
{
	//SYS_voidInit();
	RCC_voidInit();
	STK_voidInit();

	TFT_voidInit();
	
	STK_u8DelayAsyPeriodic(125, &PlaySong);

	while(1)
	{
		
	}

}

void PlaySong(void)
{
	static u16 Local_u16Iterator=0;

	SPK_voidOutput(song_raw[Local_u16Iterator]);
	Local_u16Iterator++;
	if(Local_u16Iterator==40124)
		Local_u16Iterator=0;
}
