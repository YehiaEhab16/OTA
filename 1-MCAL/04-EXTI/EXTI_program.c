/*******************************************************************************/
/*******************************************************************************/
/***********************   GRADUATION PROJECT : (IMT)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):EXTI 			 ***********************/
/***********************   DATE : 1-9-2022 			 	 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#include  "../../6-Library/STD_TYPES.h"
#include  "../../6-Library/BIT_MATH.h"
		  
#include  "EXTI_interface.h"
#include  "EXTI_config.h"
#include  "EXTI_private.h"
#include  "EXTI_register.h"


//Initializing EXTI 
void EXTI_voidInit(u8 Copy_u8InterruptLine, u8 Copy_u8SenseMode)
{

}
//Setting EXTI Sense Mode
void EXTI_voidSetSenseMode(u8 Copy_u8InterruptLine , u8 Copy_u8EXTISenseMode)
{	

}

//Enabling EXTI 
void EXTI_voidEnableEXTI(u8 Copy_u8InterruptLine)
{

}

//Disabling EXTI 
void EXTI_voidDisableEXTI(u8 Copy_u8InterruptLine)
{

}

//Setting Callback function
void EXTI_voidSetCallBack(u8 Copy_u8InterruptLine,void (*Copy_pvCallBackFunc) (void)) 
{
	
}