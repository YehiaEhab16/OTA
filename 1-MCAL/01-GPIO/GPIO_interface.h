/*******************************************************************************/
/*******************************************************************************/
/***********************   GRADUATION PROJECT : (IMT)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):GPIO 			 ***********************/
/***********************   DATE : 1-9-2022 				 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_



/**
 * @def initialize all pin directions and initial values
 */
void GPIO_voidDirectionInit(void);

/**
 * @def function that sets output value to specific pin
 * @param Copy_u8Port required GPIO Port
 * @param Copy_u8Pin required GPIO Pin
 * @param Copy_u8Value required Output Value
 * @return ErrorFlag
 */
u8 GPIO_u8SetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Value);

/**
 * @def function that sets output value to specific port
 * @param Copy_u8Port required GPIO Port
 * @param Copy_u8Value required Output Value
 * @return ErrorFlag
 */
u8 GPIO_u8SetPortValue (u8 Copy_u8Port,u8 Copy_u8Value);

/**
 * @def function that gets toggles output on specific pin
 * @param Copy_u8Port required GPIO Port
 * @param Copy_u8Pin required GPIO Pin
 * @return ErrorFlag
 */
u8 GPIO_u8TogglePinValue (u8 Copy_u8Port, u8 Copy_u8Pin);

/**
 * @def function that sets output value to specific pin
 * @param Copy_u8Port required GPIO Port
 * @param Copy_u8Pin required GPIO Pin
 * @param Copy_pu8Value is the read input value
 * @return ErrorFlag
 */
u8 GPIO_u8GetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 *Copy_pu8Value);


#endif