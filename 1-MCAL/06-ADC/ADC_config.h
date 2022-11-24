#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_ 


//Select the Number of conversion in regural Group 
#define ADC_NUM_CONV_REG			1					//from 1 to 16

//Select the Number of conversion in Inected Group 
#define ADC_NUM_CONV_INJ			1					//from 1 to 4

// Enable and disable Injected a nd regular interrupt
#define ADC_REGULAR_CONV_INTERRUPT_STATE			ADC_DISABLE
#define ADC_INJECTED_CONV_INTERRUPT_STATE		 	ADC_DISABLE

// Select the mode of the data alignment 
#define ADC_DATA_ALIGN 				ADC_RIGHT_ALGN


#endif
