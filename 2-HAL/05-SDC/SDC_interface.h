/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :HAL	                 ***********************/
/***********************   SWC (DRIVER):SDC 			 ***********************/
/***********************   DATE : 6-4-2023 				 ***********************/
/*******************************************************************************/
/*******************************************************************************/

/* Preprocessor file guard 
   Macros and prototypes   */
#ifndef SDC_INTERFACE_H_
#define SDC_INTERFACE_H_


typedef enum {
	SD_OK,
	SD_IDLE_STATE_TIMEOUT,
	SD_GENERAL_ERROR,
	SD_CHECK_PATTERN_MISMATCH,
	SD_NONCOMPATABLE_VOLTAGE_RANGE,
	SD_POWER_UP_BIT_NOT_SET,
	SD_NOT_SD_CARD
}SD_RETURN_CODES;

#define SDC_PORTA					GPIO_PORTA
#define SDC_PORTB					GPIO_PORTB
#define SDC_PORTC					GPIO_PORTC

#define SDC_PIN0					GPIO_PIN_0
#define SDC_PIN1					GPIO_PIN_1
#define SDC_PIN2					GPIO_PIN_2
#define SDC_PIN3					GPIO_PIN_3
#define SDC_PIN4					GPIO_PIN_4
#define SDC_PIN5					GPIO_PIN_5
#define SDC_PIN6					GPIO_PIN_6
#define SDC_PIN7					GPIO_PIN_7
#define SDC_PIN8					GPIO_PIN_8
#define SDC_PIN9					GPIO_PIN_9
#define SDC_PIN10					GPIO_PIN_10
#define SDC_PIN11					GPIO_PIN_11
#define SDC_PIN12					GPIO_PIN_12
#define SDC_PIN13					GPIO_PIN_13
#define SDC_PIN14					GPIO_PIN_14
#define SDC_PIN15					GPIO_PIN_15

/**
 * @def SDC Initialization
 */
void SDC_voidInit(void);
static void sd_command(u8 cmd, u32 arg, u8 crc , SPI_s * Copy_SPI_SDCard);
static SD_RETURN_CODES sd_command_ACMD41(SPI_s * Copy_SPI_SDCard);
static u8 sd_read_response1(SPI_s * Copy_SPI_SDCard);
static void sd_read_response3_7(u8 *res ,SPI_s * Copy_SPI_SDCard);
SD_RETURN_CODES sd_init(void);

#endif
