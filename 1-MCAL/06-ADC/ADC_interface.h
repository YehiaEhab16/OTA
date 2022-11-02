/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):ADC 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/**
 * @def function to initialize ADC
 */
void ADC_voidInit(void);

/**
 * @def function to start ADC Conversion
 * @param Copy_u8Channel ADC Channel
 * @param Copy_u32Data Data after conversion
 */
void ADC_voidStartConversion(u8 Copy_u8Channel,u16 *Copy_u16Data);


#endif