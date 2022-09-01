/*******************************************************************************/
/*******************************************************************************/
/***********************   GRADUATION PROJECT : (IMT)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):RCC 			 ***********************/
/***********************   DATE : 1-9-2022 				 ***********************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/**
 * @def function to initialize RCC peripheral and provide clock for all needed peripherals
 */
void RCC_voidInit (void);

/**
 * @def function to Enable certain peripheral
 * @param Copy_u8PeripheralID required peripheral
 * @return ErrorFlag
 */
u8 RCC_u8EnablePeripheral(u8 Copy_u8PeripheralID);

/**
 * @def function to disable certain peripheral
 * @param Copy_u8PeripheralID required peripheral
 * @return ErrorFlag
 */
u8 RCC_u8DisablePeripheral(u8 Copy_u8PeripheralID);


#endif
