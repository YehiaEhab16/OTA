/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):SPI 			 ***********************/
/***********************   DATE : 2-11-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


// Concatenation Function
#define CONC2(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELPER2(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER2(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)     0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0

// Init Register
#define SPI_REG_INIT		CONC2(SPI_BIDIRECTION,SPI_BIDIRECTION,SPI_CRC_CALC,SPI_CRC_TRANSFER,SPI_DF_FORMAT,SPI_RX_MODE,SPI_DISABLE,SPI_DISABLE,SPI_LSB_FIRST,SPI_DISABLE,SPI_DISABLE,SPI_DISABLE,SPI_DISABLE,SPI_DISABLE,SPI_CLK_POLARITY,SPI_CLK_PHASE)

// States
#define SPI_DISABLE			0
#define SPI_ENABLE			1
#define SPI_IDLE			0
#define SPI_BUSY			1

// Clock Polarity
#define FIRST_CLK			0
#define SECOND_CLK			1

// Baud Rate
#define BAUD_RATE_MASK		0xFFC7
#define DIVIDE_BY_2			0
#define DIVIDE_BY_4			1
#define DIVIDE_BY_8			2
#define DIVIDE_BY_16		3
#define DIVIDE_BY_32		4
#define DIVIDE_BY_64		5
#define DIVIDE_BY_128		6
#define DIVIDE_BY_256		7

// Recieve Mode
#define FULL_DUPLEX			0
#define OUT_DISABLED		1

// Data Frame Format
#define BITS_8				0
#define BITS_16				1

//Port Options
#define GPIO_PORTA          0
#define GPIO_PORTB          1
#define GPIO_PORTC          2

//Pin Options
#define GPIO_PIN_0			0
#define GPIO_PIN_1          1
#define GPIO_PIN_2          2
#define GPIO_PIN_3          3
#define GPIO_PIN_4          4
#define GPIO_PIN_5          5
#define GPIO_PIN_6          6
#define GPIO_PIN_7          7
#define GPIO_PIN_8          8
#define GPIO_PIN_9          9
#define GPIO_PIN_10         10
#define GPIO_PIN_11         11
#define GPIO_PIN_12         12
#define GPIO_PIN_13         13
#define GPIO_PIN_14         14
#define GPIO_PIN_15         15

//Pin and Port States
#define GPIO_PORT_HIGH		0xff
#define GPIO_PORT_LOW		0

#define GPIO_PIN_HIGH		1
#define GPIO_PIN_LOW		0

/**
 * @def Getting SPI Port and setting correct base address
 * @param Copy_u8SpiPort: required SPI port
 * @return SPI base address
 */
static SPI_t *SPI_Get(u8 Copy_u8SpiPort);

/**
 * @def function that sets output value to specific pin
 * @param Copy_u8Port required GPIO Port
 * @param Copy_u8Pin required GPIO Pin
 * @param Copy_u8Value required Output Value
 * @return ErrorFlag
 */
static u8 GPIO_u8SetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Value);


#endif
