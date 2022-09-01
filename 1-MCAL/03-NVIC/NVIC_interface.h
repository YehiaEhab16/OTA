/*******************************************************************************/
/*******************************************************************************/
/***********************   GRADUATION PROJECT : (IMT)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):NVIC 			 ***********************/
/***********************   DATE : 1-9-2022  			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


/**
 * @def this is represent of NVIC core peripheral initialization
 */
void NVIC_voidInit(void);

/**
 * @def Enable the interrupt
 * @param Copy_u8NameInterrupt Number of the interrupt
 * @return ErrprFlag
 */
u8 NVIC_u8EnableInterrupt(u8 Copy_u8NameInterrupt);

/**
 * @def Disable the interrupt
 * @param Copy_u8NameInterrupt Number of the interrupt
 * @return Error Flag
 */
u8 NVIC_u8DisableInterrupt(u8 Copy_u8NameInterrupt);


#endif
