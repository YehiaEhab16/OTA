/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :HAL	                 ***********************/
/***********************   SWC (DRIVER):TFT 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

/* Preprocessor file guard 
   Static functions*/
#ifndef TFT_PRIVATE_H_
#define TFT_PRIVATE_H_


#define TFT_PORTA		GPIO_PORTA
#define TFT_PORTB		GPIO_PORTB
#define TFT_PORTC		GPIO_PORTC

#define TFT_PIN0		GPIO_PIN_0
#define TFT_PIN1		GPIO_PIN_1
#define TFT_PIN2		GPIO_PIN_2
#define TFT_PIN3		GPIO_PIN_3
#define TFT_PIN4		GPIO_PIN_4
#define TFT_PIN5		GPIO_PIN_5
#define TFT_PIN6		GPIO_PIN_6
#define TFT_PIN7		GPIO_PIN_7
#define TFT_PIN8		GPIO_PIN_8
#define TFT_PIN9		GPIO_PIN_9
#define TFT_PIN10		GPIO_PIN_10
#define TFT_PIN11		GPIO_PIN_11
#define TFT_PIN12		GPIO_PIN_12
#define TFT_PIN13		GPIO_PIN_13
#define TFT_PIN14		GPIO_PIN_14
#define TFT_PIN15		GPIO_PIN_15

#define TFT_PIXELS		20480

/**
 * @def Send Command to Screen
 * @param Copy_u8Command Command to be sent
 */
void TFT_voidSendCommand(u8 Copy_u8Command);

/**
 * @def Send Data to Screen
 * @param Copy_u8Command Data to be sent
 */
void TFT_voidSendData(u8 Copy_u8Data);


#endif
