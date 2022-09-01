/*******************************************************************************/
/*******************************************************************************/
/***********************   GRADUATION PROJECT : (IMT)   ***********************/
/***********************   Layer :HAL                    ***********************/
/***********************   SWC (DRIVER):LCD 			 ***********************/
/***********************   DATE : 1-9-2022  			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

/* Preprocessor file guard 
   Macros and prototypes   */
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#define LCD_PORTA					GPIO_PORTA
#define LCD_PORTB					GPIO_PORTB
#define LCD_PORTC					GPIO_PORTC

#define LCD_PIN0					GPIO_PIN_0
#define LCD_PIN1					GPIO_PIN_1
#define LCD_PIN2					GPIO_PIN_2
#define LCD_PIN3					GPIO_PIN_3
#define LCD_PIN4					GPIO_PIN_4
#define LCD_PIN5					GPIO_PIN_5
#define LCD_PIN6					GPIO_PIN_6
#define LCD_PIN7					GPIO_PIN_7
#define LCD_PIN8					GPIO_PIN_8
#define LCD_PIN9					GPIO_PIN_9
#define LCD_PIN10					GPIO_PIN_10
#define LCD_PIN11					GPIO_PIN_11
#define LCD_PIN12					GPIO_PIN_12
#define LCD_PIN13					GPIO_PIN_13
#define LCD_PIN14					GPIO_PIN_14
#define LCD_PIN15					GPIO_PIN_15

/**
 * @def LCD Display
 */
void LCD_voidDisplay(void);

#endif
