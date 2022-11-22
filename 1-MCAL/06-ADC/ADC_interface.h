
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_ 

/******************************************************************************************************************************/
/*******************************************************ADC Peripheral***********************************************************/
/******************************************************************************************************************************/

//*************************************************** ِADC API *******************************************************************/
typedef enum 
{
	u8 ADC_u8OK,
	u8 ADC_u8IdError , 
	u8 ADC_u8TypeError ,
	u8 ADC_u8ConvType 
	
	
}ADC_Error;
// Initialization the ADC
void ADC_voidInit (void);

//**************************************************** Global API *************************************************//
// Disable ADC
void ADC_voidDisable (void);

//Enable ADC
void ADC_voidEnable (void);

//Disable interrupt 
void ADC_voidDisableInt (u8 Copy_u8TypeInterrupt);



/******************************************************************************************************************************/
/*******************************************************Channel Module***********************************************************/
/******************************************************************************************************************************/

typedef struct 
{
	u8 ADC_u8IDChannel       ; 
	u8 ADC_u8ChannelPriority ;
	u8 ADC_u8ChannelType     ;
	
}ADC_Channel;
//******************************************Options of Channel's Feature*****************************************************/

												/*Channel Number */
												
#define 	CHANNEL0				0    			// POERTA		- PIN0
#define 	CHANNEL1				1				// POERTA		- PIN1
#define 	CHANNEL2				2				// POERTA		- PIN2
#define 	CHANNEL3				3				// POERTA		- PIN3
#define 	CHANNEL4				4				// POERTA		- PIN4
#define 	CHANNEL5				5				// POERTA		- PIN5
#define 	CHANNEL6				6				// POERTA		- PIN6
#define 	CHANNEL7				7				// POERTA		- PIN7
#define 	CHANNEL8				8				// POERTB		- PIN0
#define 	CHANNEL9 				9				// POERTB		- PIN1


												/*Channel Priority*/
//Select from 1(highest Prority) to 16 (Lowest Priority)
//Select from 1(highest Prority) to 4 (Lowest Priority)


												/* Channel Types  */

#define ADC_REGULAR_CONV				0			// has 16 conversion
#define ADC_INJECTED_CONV				1			// has 4  conversion 


												/* ADC_u8ConversionMode */

#define ADC_SINGLE_CHANNEL_SINGLE_CONV			0
#define ADC_SINGLE_CHANNEL_CONT_CONV			1
#define ADC_MULTI_CHANNEL_SINGLE_CONV			2
#define ADC_MULTI_CHANNEL_CONT_CONV				3
#define ADC_DISCONT_MODE						4


ADC_Error ADC_voidPriorityChannel (ADC_Channel * Copy_pvChannel , u8 Copy_u8NewPriority);

ADC_Error ADC_voidChangeChannel (ADC_Channel * Copy_pvChannel , u8 Copy_u8NewChannel);

// Change the conversion mode of the channel 
ADC_Error ADC_voidSingleASynStartConv (ADC_Channel * Copy_pvChannel , u8 Copy_u8ConvType , u16 * Copy_u16Data,, void(*Copy_pvNotify)(void) );

//Start the conversion as synchronous
ADC_Error ADC_voidSingleSynStartConv (ADC_Channel * Copy_pvChannel, u8 Copy_u8ConvType , u16 * Copy_u16Data );

//Start the conversion as Asynchronous
u8 ADC_voidASynStartConv (ADC_Channel * Copy_pvChannel);

/******************************************************************************************************************************/





#endif 