/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :SERVICE                   ***********************/
/***********************   SWC (DRIVER):SPI 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/


#ifndef SPI_INTERFACE_S_H_
#define SPI_INTERFACE_S_H_


#define SPI_SLAVE		0
#define SPI_MASTER		1

#define SPI1_PORT		0
#define SPI2_PORT		1
#define SPI3_PORT		2

#define SPI_PORTA		GPIO_PORTA
#define SPI_PORTB		GPIO_PORTB
#define SPI_PORTC		GPIO_PORTC

#define SPI_PIN0		GPIO_PIN_0
#define SPI_PIN1		GPIO_PIN_1
#define SPI_PIN2		GPIO_PIN_2
#define SPI_PIN3		GPIO_PIN_3
#define SPI_PIN4		GPIO_PIN_4
#define SPI_PIN5		GPIO_PIN_5
#define SPI_PIN6		GPIO_PIN_6
#define SPI_PIN7		GPIO_PIN_7
#define SPI_PIN8		GPIO_PIN_8
#define SPI_PIN9		GPIO_PIN_9
#define SPI_PIN10		GPIO_PIN_10
#define SPI_PIN11		GPIO_PIN_11
#define SPI_PIN12		GPIO_PIN_12
#define SPI_PIN13		GPIO_PIN_13
#define SPI_PIN14		GPIO_PIN_14
#define SPI_PIN15		GPIO_PIN_15

typedef struct
{
	u8 SPI_u8SpiPort;			// SPI1_PORT or SPI2_PORT or SPI3_PORT
	u8 SPI_u8Role;				// SPI_MASTER or SPI_SLAVE
	u8 SPI_u8SlaveSelectPort;
	u8 SPI_u8SlaveSelectPin;
	u8 SPI_u8BufferSize;
	u8 *SPI_pu16TransmitData;
	u8 *SPI_pu16RecivedData;
}SPI_s;

/**
 * @def function to initialize SPI
 * @param Copy_pSPI_sData: SPI Struct
 */
void SPI_S_voidInit(SPI_d* Copy_pSPI_sData);

/**
 * @def function to transmit data
 * @param Copy_pSPI_sData: SPI Struct
 * @ret error state: OK / NOK
 */
u8 SPI_S_u8Transcieve(SPI_d* Copy_pSPI_sData);

/**
 * @def function to transmit buffer of data
 * @param Copy_pSPI_sData: SPI Struct
 * @ret error state: OK / NOK
 */
u8 SPI_S_u8TranscieveBuffer(SPI_d* Copy_pSPI_sData);


#endif
