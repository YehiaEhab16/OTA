
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_register.h"

static u16 * ADC_u16Data_REG = NULL;
static u16 * ADC_u16Data_INJ = NULL;
static u8 ADC_u8Priority = 0 ; 
static void (*Notification)(void) NULL ;

// Initialization the channel of ADC
void ADC_voidInit (void)
{
	#if ADC_DATA_ALIGN == ADC_RIGHT_ALGN
	CLR_BIT(ADC1 -> CR2 ,ALIGN);
	#elif ADC_DATA_ALIGN == ADC_LEFT_ALGN
	SET_BIT(ADC1 -> CR2 ,ALIGN);
	#else
	#error "Please enter the correct interrupt state"
	#endif	
	
	#if ADC_REGULAR_CONV_INTERRUPT_STATE == ADC_ENABLE
	SET_BIT(ADC->CR1,EOCIE);
	#elif ADC_REGULAR_CONV_INTERRUPT_STATE == ADC_DISABLE
	CLR_BIT(ADC->CR1,EOCIE);
	#else
	#error "Please enter the correct interrupt state"
	#endif
	
	#if ADC_INJECTED_CONV_INTERRUPT_STATE == ADC_ENABLE
	SET_BIT(ADC->CR1,JEOCIE);
	#elif ADC_INJECTED_CONV_INTERRUPT_STATE == ADC_DISABLE
	CLR_BIT(ADC->CR1,JEOCIE);
	#else
	#error "Please enter the correct interrupt state"
	#endif
	
	SET_BIT(ADC->CR2,ADON);
	
}

ADC_Error ADC_voidPriorityChannel (ADC_Channel * Copy_pvChannel , u8 Copy_u8NewPriority)
{
	ADC_Error Local_u8ErrorState = ADC_u8OK ;
	if (ADC_Channel->ADC_u8ChannelType == ADC_REGULAR_CONV)
	{
		if (ADC_Channel->ADC_u8IDChannel < 16)
			Copy_pvChannel -> ADC_u8ChannelPriority = Copy_u8NewPriority ; 
		else
			Local_u8ErrorState =ADC_u8IdError ; 
	}
	else if (ADC_Channel->ADC_u8ChannelType == ADC_INJECTED_CONV)
	{
		if (ADC_Channel->ADC_u8IDChannel < 4)
			Copy_pvChannel -> ADC_u8ChannelPriority = Copy_u8NewPriority ;
		else
			Local_u8ErrorState =ADC_u8IdError ; 
			
	}
	else 
		Local_u8ErrorState =ADC_u8TypeError ; 
	
	return Local_u8ErrorState ; 
	
}

ADC_Error ADC_voidChangeChannel (ADC_Channel * Copy_pvChannel , u8 Copy_u8NewChannel)
{
	ADC_Error Local_u8ErrorState = ADC_u8OK ;
	if (ADC_Channel->ADC_u8ChannelType == ADC_REGULAR_CONV)
	{
		if (ADC_Channel->ADC_u8IDChannel < 16)
			ADC_Channel->ADC_u8IDChannel = Copy_u8NewChannel ; 
		else
			Local_u8ErrorState =ADC_u8IdError ; 
	}
	else if (ADC_Channel->ADC_u8ChannelType == ADC_INJECTED_CONV)
	{
		if (ADC_Channel->ADC_u8IDChannel < 4)
			ADC_Channel->ADC_u8IDChannel = Copy_u8NewChannel ; 
		else
			Local_u8ErrorState =ADC_u8IdError ; 
	}
	else 
		Local_u8ErrorState =ADC_u8TypeError ; 
	
	return Local_u8ErrorState ; 
	
}


//Start the conversion as synchronous
ADC_Error ADC_voidSingleASynStartConv (ADC_Channel * Copy_pvChannel , u8 Copy_u8ConvType , u16 * Copy_u16Data,, void(*Copy_pvNotify)(void) )
{
	ADC_Error Local_u8ErrorState = ADC_u8OK ;
	if (ADC_Channel->ADC_u8ChannelType == ADC_REGULAR_CONV)
	{
		if (ADC_Channel->ADC_u8IDChannel < 16)
		{
			if (Copy_u8ConvType == ADC_SINGLE_CHANNEL_SINGLE_CONV)
			{
				CLR_BIT (ADC->CR2,CONT);
				ADC->SQR1 = ADC_IDE_MASK ; 
				ADC->SQR1 |= (ADC_ONE_CONV>>ADC_ONE_CONV_DIS) ; 
				ADC->SQR1 |= ((ADC_Channel->ADC_u8IDChannel)>>ADC_ONE_PRI) ; 
				SET_BIT(ADC->CR1,EOCIE);
				ADC_u16Data_REG = Copy_u16Data;
				Notification=Copy_pvNotify ;
			}
			else if (Copy_u8ConvType == ADC_SINGLE_CHANNEL_CONT_CONV)
			{
				SET_BIT (ADC->CR2,CONT);
				ADC->SQR1 = ADC_IDE_MASK ; 
				ADC->SQR1 |= (ADC_ONE_CONV>>ADC_ONE_CONV_DIS) ; 
				ADC->SQR1 |= ((ADC_Channel->ADC_u8IDChannel)>>ADC_ONE_PRI) ;
				SET_BIT(ADC->CR1,EOCIE);	
				ADC_u16Data_REG = Copy_u16Data;		
				Notification=Copy_pvNotify ;	
			}
			else 
				Local_u8ErrorState = ADC_u8ConvType ;
			SET_BIT(ADC->CR2 , SWSTART); 
		}
		else
			Local_u8ErrorState =ADC_u8IdError ; 
		}
	else if (ADC_Channel->ADC_u8ChannelType == ADC_INJECTED_CONV)
	{
		if (ADC_Channel->ADC_u8IDChannel < 4)
		{
			if (Copy_u8ConvType == ADC_SINGLE_CHANNEL_SINGLE_CONV)
			{
				CLR_BIT(ADC->CR2,CONT);
				ADC->JSQR = ADC_IDE_MASK ; 
				ADC->JSQR |= (ADC_ONE_CONV<<ADC_ONE_CONV_DIS) ; 
				ADC->JSQR |= ((ADC_Channel->ADC_u8IDChannel)<<ADC_ONE_PRI) ;
				SET_BIT(ADC->CR1,EOCIE);
				ADC_u16Data_INJ = Copy_u16Data;		
				Notification=Copy_pvNotify ;	
				ADC_u8Priority = ADC->JDR1[ADC_Channel->ADC_u8ChannelPriority] ;
			}
			else 
				Local_u8ErrorState = ADC_u8ConvType;
			
			SET_BIT(ADC->CR2 , JSWSTART); 
		}
		else
			Local_u8ErrorState =ADC_u8IdError ; 
			
	}
	else 
		Local_u8ErrorState =ADC_u8TypeError ; 
	
	return Local_u8ErrorState ; 
	
}

//Start the conversion as Asynchronous
ADC_Error ADC_voidSingleSynStartConv (ADC_Channel * Copy_pvChannel, u8 Copy_u8ConvType , u16 * Copy_u16Data )
{
	ADC_Error Local_u8ErrorState = ADC_u8OK ;
	if (ADC_Channel->ADC_u8ChannelType == ADC_REGULAR_CONV)
	{
		if (ADC_Channel->ADC_u8IDChannel < 16)
		{
			if (Copy_u8ConvType == ADC_SINGLE_CHANNEL_SINGLE_CONV)
			{
				CLR_BIT (ADC->CR2,CONT);
				ADC->SQR1 = ADC_IDE_MASK ; 
				ADC->SQR1 |= (ADC_ONE_CONV<<ADC_ONE_CONV_DIS) ; 
				ADC->SQR1 |= ((ADC_Channel->ADC_u8IDChannel)<<ADC_ONE_PRI) ; 
				
			}
			else if (Copy_u8ConvType == ADC_SINGLE_CHANNEL_CONT_CONV)
			{
				SET_BIT (ADC->CR2,CONT);
				ADC->SQR1 = ADC_IDE_MASK ; 
				ADC->SQR1 |= (ADC_ONE_CONV<<ADC_ONE_CONV_DIS) ; 
				ADC->SQR1 |= ((ADC_Channel->ADC_u8IDChannel)<<ADC_ONE_PRI) ; 
			}
			else 
				Local_u8ErrorState = ADC_u8ConvType ;
			
			SET_BIT(ADC->CR2 , SWSTART); 
			while (GET_BIT(ADC->SR , EOC) != 1);
			#if ADC_DATA_ALIGN == ADC_RIGHT_ALGN
			*Copy_u16Data = ADC->DR ;
			#elif ADC_DATA_ALIGN == ADC_LEFT_ALGN
			*Copy_u16Data = ((ADC->DR)>>ADC_REG_LEFT_SHIFT) ;;
			#else
			#error "Please enter the correct interrupt state"
			#endif	
			 
			CLR_BIT(ADC->SR , EOC);
			CLR_BIT(ADC->SR , STRT);
		}
			
		else
			Local_u8ErrorState =ADC_u8IdError ; 
	}
	else if (ADC_Channel->ADC_u8ChannelType == ADC_INJECTED_CONV)
	{
		if (ADC_Channel->ADC_u8IDChannel < 4)
		{
			if (Copy_u8ConvType == ADC_SINGLE_CHANNEL_SINGLE_CONV)
			{
				CLR_BIT(ADC->CR2,CONT);
				ADC->JSQR = ADC_IDE_MASK ; 
				ADC->JSQR |= (ADC_ONE_CONV<<ADC_ONE_CONV_DIS) ; 
				ADC->JSQR |= ((ADC_Channel->ADC_u8IDChannel)<<ADC_ONE_PRI) ;
				
			}
			else 
				Local_u8ErrorState = ADC_u8ConvType;
			
			SET_BIT(ADC->CR2 , JSWSTART); 
			while (GET_BIT(ADC->SR , EOC) != 1);
			#if ADC_DATA_ALIGN == ADC_RIGHT_ALGN
			*Copy_u16Data = ADC->JDR1[ADC_Channel->ADC_u8ChannelPriority]; 
			#elif ADC_DATA_ALIGN == ADC_LEFT_ALGN
			*Copy_u16Data = ((ADC->JDR1[ADC_Channel->ADC_u8ChannelPriority])>>ADC_REG_LEFT_SHIFT) ;;
			#else
			#error "Please enter the correct interrupt state"
			#endif	
			
			CLR_BIT(ADC->SR , EOC) ;
			CLR_BIT(ADC->SR , JSTRT);
		}
		else
			Local_u8ErrorState =ADC_u8IdError ; 
		

	}
	else
		Local_u8ErrorState =ADC_u8TypeError ; 
	
	return Local_u8ErrorState ; 
	
}


//**************************************************** Global API *************************************************//
// Disable ADC
void ADC_voidDisable (void)
{
	CLR_BIT(ADC->CR2,ADON);
}

//Enable ADC
void ADC_voidEnable (void);
{
	SET_BIT(ADC->CR2,ADON);
}

//Disable interrupt 
u8 ADC_voidDisableInt (u8 Copy_u8TypeInterrupt)
{
	ADC_Error Local_u8ErrorState = ADC_u8OK ; 
	
	if (Copy_u8TypeInterrupt == ADC_REGULAR_CONV)
		CLR_BIT(ADC->CR1,EOCIE);
	else if (Copy_u8TypeInterrupt == ADC_INJECTED_CONV)
		CLR_BIT(ADC->CR1,JEOCIE);
	else
		Local_u8ErrorState = ADC_u8TypeError ; 
		
	return Local_u8ErrorState ; 
}


void ADC1_2_IRQHandler (void)
{
	#if ADC_DATA_ALIGN == ADC_RIGHT_ALGN
	ADC_u16Data_REG = ADC->DR ;
	#elif ADC_DATA_ALIGN == ADC_LEFT_ALGN
	ADC_u16Data_REG = ((ADC->DR)>>ADC_REG_LEFT_SHIFT) ;;
	#else
	#error "Please enter the correct interrupt state"
	#endif	
	
	#if ADC_DATA_ALIGN == ADC_RIGHT_ALGN
	ADC_u16Data_INJ = ADC->JDR1[ADC_u8Priority]; 
	#elif ADC_DATA_ALIGN == ADC_LEFT_ALGN
	ADC_u16Data_INJ = ((ADC->JDR1[ADC_u8Priority])>>ADC_REG_LEFT_SHIFT) ;;
	#else
	#error "Please enter the correct interrupt state"
	#endif
	
	CLR_BIT(ADC->SR , EOC);
	CLR_BIT(ADC->SR , STRT);
	
}