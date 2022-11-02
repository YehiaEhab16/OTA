/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):SPI 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


#define SPI_MASTER		1
#define SPI_SLAVE		2

/**
 * @def function to initialize SPI
 * @param Copy_u8Role: SPI_MASTER / SPI_SLAVE
 */
void SPI_voidInit(u8 Copy_u8Role);

/**
 * @def function to transmit data
 * @param Copy_u8Data: Transmitted Data
 * @param Copy_pu8RecivedData: Recieved Data
 * @ret error state: OK / NOK
 */
u8 SPI_u8Transcieve(u8 Copy_u8Data, u8* Copy_pu8RecivedData);

/**
 * @def function to transmit buffer of data
 * @param Copy_u8Data: Transmitted Data
 * @param Copy_pu8RecivedData: Recieved Data
 * @param Copy_u8BufferSize: Size of buffer
 * @ret error state: OK / NOK
 */
u8 SPI_u8TranscieveBuffer(u8* Copy_pu8Data, u8* Copy_pu8RecivedData, u8 Copy_u8BufferSize);


#endif
