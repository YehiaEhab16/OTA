/*******************************************************************************/
/*******************************************************************************/
/***********************   GRADUATION PROJECT : (IMT)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):EXTI 			 ***********************/
/***********************   DATE : 1-9-2022 			 	 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/**
 * @def function to initialize EXTI
 */
void EXTI_voidInit(u8 Copy_u8InterruptLine, u8 Copy_u8SenseMode);

/**
 * @def function to set EXTI Sense Mode
 */
void EXTI_voidSetSenseMode(u8 Copy_u8InterruptLine , u8 Copy_u8EXTISenseMode);

/**
 * @def function to enable EXTI
 */
void EXTI_voidEnableEXTI(u8 Copy_u8InterruptLine);

/**
 * @def function to disable EXTI
 */
void EXTI_voidDisableEXTI(u8 Copy_u8InterruptLine);

/**
 * @def function to set callback function
 */
void EXTI_voidSetCallBack(u8 Copy_u8InterruptLine,void (*Copy_pvCallBackFunc) (void)) ;


#endif
