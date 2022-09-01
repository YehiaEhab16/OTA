/*******************************************************************************/
/*******************************************************************************/
/***********************   GRADUATION PROJECT : (IMT)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):GPIO 			 ***********************/
/***********************   DATE : 1-9-2022 				 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#include "../../6-Library/STD_TYPES.h"
#include "../../6-Library/BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_register.h"

//Initializing all pins direction
void GPIO_voidDirectionInit(void)
{

}

//Seting Output value for certain pin
u8 GPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Value)
{

}

//Setting Output for a certain port
u8 GPIO_u8SetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{

}

//Toggling output on a certin pin
u8 GPIO_u8TogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{

}

//Reading Input Value from a certain pin
u8 GPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8*Copy_pu8Value)
{

}
