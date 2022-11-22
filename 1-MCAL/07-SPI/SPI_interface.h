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


#define SPI_SLAVE		0
#define SPI_MASTER		1

#define SPI1_PORT		0
#define SPI2_PORT		1
#define SPI3_PORT		2


/**
 * @def function to initialize SPI
 * @param Copy_u8SpiPort: SPI1_PORT / SPI2_PORT / SPI3_PORT
 * @param Copy_u8Role   : SPI_MASTER / SPI_SLAVE
 */
void SPI_voidInit(u8 Copy_u8SpiPort,u8 Copy_u8Role);

/**
 * @def function to transmit data
 * @param Copy_u8SpiPort: SPI1_PORT / SPI2_PORT / SPI3_PORT
 * @param Copy_u8TransmitData: Transmitted Data
 * @param Copy_pu8RecivedData: Recieved Data
 * @ret error state: OK / NOK
 */
u8 SPI_u8Transcieve(u8 Copy_u8SpiPort,u8 Copy_u16TransmitData, u8* Copy_pu16RecivedData);


#endif
