/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :HAL	                 ***********************/
/***********************   SWC (DRIVER):SPK 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

// Functions Implementation
#include "../../4-Library/STD_TYPES.h"

#include "../../1-MCAL/01-GPIO/GPIO_interface.h"

#include "SPK_config.h"
#include "SPK_interface.h"
#include "SPK_private.h"


// Output Sound
void SPK_voidOutput(u8 Copy_u8AnalogValue)
{
	GPIO_u8SetHalfPortValue(SPK_PORT, Copy_u8AnalogValue);
}