/*******************************************************************************/
/*******************************************************************************/
/***********************   IMT PROJECT : (MP4-Player)    ***********************/
/***********************   Layer :HAL	                 ***********************/
/***********************   SWC (DRIVER):SDC 			 ***********************/
/***********************   DATE : 6-4-2023 				 ***********************/
/*******************************************************************************/
/*******************************************************************************/

// Functions Implementation
#include "../../4-Library/STD_TYPES.h"
#include "../../4-Library/BIT_MATH.h"

#include "../../1-MCAL/01-GPIO/GPIO_interface.h"
#include "../../1-MCAL/05-STK/STK_interface.h"
#include "../../1-MCAL/07-SPI/SPI_interface.h"

#include "SDC_config.h"
#include "SDC_interface.h"
#include "SDC_private.h"


static u8 SD_CardType;

u8 SD_Buffer[SD_BUFFER_SIZE]; // reserve 1 byte for the null
u8 SD_ResponseToken;

// Output Sound
void SDC_voidInit(void)
{
	// SPI Init
	SPI_s Local_SPI_sSdCard = {SPI1_PORT, SPI_MASTER, SPI_PORTA, SPI_PIN8,1};
	SPI_voidInit(&Local_SPI_sSdCard);


}
static void SD_voidAssertCs(void){
	SPI_s Local_SPI_sSdCard = {SPI1_PORT, SPI_MASTER, SPI_PORTA, SPI_PIN8,1};
	Local_SPI_sSdCard.SPI_pu16TransmitData[0]=0xFF;

	SPI_u8Transcieve(&Local_SPI_sSdCard);
	SPI_CARD_CS_ENABLE();
	SPI_u8Transcieve(&Local_SPI_sSdCard);
}

static void SD_voidDeassertCs(void){
	SPI_s Local_SPI_sSdCard = {SPI1_PORT, SPI_MASTER, SPI_PORTA, SPI_PIN8,1};
	Local_SPI_sSdCard.SPI_pu16TransmitData[0]=0xFF;

	SPI_u8Transcieve(&Local_SPI_sSdCard);
	SPI_CARD_CS_DISABLE();
	SPI_u8Transcieve(&Local_SPI_sSdCard);
}
static void sd_command(u8 cmd, u32 arg, u8 crc , SPI_s * Copy_SPI_SDCard){
	// Transmit command
	Copy_SPI_SDCard ->SPI_pu16TransmitData[0]=cmd | 0x40;
	Copy_SPI_SDCard ->SPI_pu16TransmitData[1]=(u8)(arg >> 24);
	Copy_SPI_SDCard->SPI_pu16TransmitData[2]=(u8)(arg >> 16);
	Copy_SPI_SDCard->SPI_pu16TransmitData[3]=(u8)(arg >> 8);
	Copy_SPI_SDCard->SPI_pu16TransmitData[4]=(u8)(arg);
	Copy_SPI_SDCard->SPI_pu16TransmitData[5]=crc | 0x01;
	SPI_u8Transcieve(Copy_SPI_SDCard);

}
static SD_RETURN_CODES sd_command_ACMD41(SPI_s * Copy_SPI_SDCard){
	u8 response;
	u8 i = 100;

	// Initialization process can take up to 1 second so we add a 10ms delay
	// and a maximum of 100 iterations

	do{
		// CMD55 – APP_CMD – R1 response
		SD_voidAssertCs();
		sd_command(CMD55, CMD55_ARG, CMD55_CRC,Copy_SPI_SDCard);
		sd_read_response1(Copy_SPI_SDCard);
		SD_voidDeassertCs();

		// ACMD41 – SD_SEND_OP_COND (Send Operating Condition) - R1 response
		SD_voidAssertCs();
		if(SD_CardType == SD_V1_SDSC)
			sd_command(ACMD41, 0, ACMD41_CRC,Copy_SPI_SDCard);
		else
			sd_command(ACMD41, ACMD41_ARG, ACMD41_CRC,Copy_SPI_SDCard);

		response = sd_read_response1(Copy_SPI_SDCard);
		SD_voidDeassertCs();

		i--;
		STK_voidDelay(10,TIME_MILLE_SEC);

	}while((response != 0) && (i > 0));

	// Timeout
	if(i == 0) return SD_IDLE_STATE_TIMEOUT;

	return response;
}

static u8 sd_read_response1(SPI_s * Copy_SPI_SDCard){
	u8 i = 0;

	// Keep polling until actual data received
	while(Copy_SPI_SDCard->SPI_pu16RecivedData[0] == 0xFF){
		i++;

		// If no data received for 16 bytes, break
		if(i > 16) break;
	}

	return Copy_SPI_SDCard->SPI_pu16RecivedData[0];
}

static void sd_read_response3_7(u8 *res ,SPI_s * Copy_SPI_SDCard){
	res[0] = Copy_SPI_SDCard->SPI_pu16RecivedData[0]; // read response 1 in R3 or R7

	if(res[0] > 1) return; // if error reading R1, return

	res[1] = Copy_SPI_SDCard->SPI_pu16RecivedData[0];
	res[2] = Copy_SPI_SDCard->SPI_pu16RecivedData[1];
	res[3] = Copy_SPI_SDCard->SPI_pu16RecivedData[2];
	res[4] = Copy_SPI_SDCard->SPI_pu16RecivedData[4];
}
SD_RETURN_CODES sd_init(void){
	u8 SD_Response[5]; // array to hold response
	u8 cmdAttempts = 0;

	SPI_s Local_SPI_sSdCard = {SPI1_PORT, SPI_MASTER, SPI_PORTA, SPI_PIN8,6};

	// SPI Setup
	SPI_voidInit(&Local_SPI_sSdCard);

	// Give SD card time to power up
	STK_voidDelay(1,TIME_MILLE_SEC);

	// Send 80 clock cycles to synchronize
	// The card must be deselected during this time
	SD_voidDeassertCs();

	for(u8 i = 0; i < 10; i++) SPI_u8Transcieve(&Local_SPI_sSdCard);

	// Send CMD0 (GO_IDLE_STATE) - R1 response
	// Resets the SD Memory Card
	// Argument is 0×00 for the reset command, precalculated checksum
	while(SD_Response[0] != 0x01){
		// Assert chip select
		SD_voidAssertCs();

		// Send CMD0
		sd_command(CMD0, CMD0_ARG, CMD0_CRC,&Local_SPI_sSdCard);

		// Read R1 response
		SD_Response[0] = sd_read_response1(&Local_SPI_sSdCard);

		// Deassert chip select
		SD_voidDeassertCs();

		cmdAttempts++;

		if(cmdAttempts > 10){
			SPI_CARD_CS_DISABLE();
			return SD_IDLE_STATE_TIMEOUT;
		}
	}



	// Send CMD8 - SEND_IF_COND (Send Interface Condition) - R7 response (or R1 for < V2 cards)
	// Sends SD Memory Card interface condition that includes host supply voltage information and asks the
	// accessed card whether card can operate in supplied voltage range.
	// Check whether the card is first generation or Version 2.00 (or later).
	// If the card is of first generation, it will respond with R1 with bit 2 set (illegal command)
	// otherwise the response will be 5 bytes long R7 type
	// Voltage Supplied (VHS) argument is set to 3.3V (0b0001)
	// Check Pattern argument is the recommended pattern '0b10101010'
	// CRC is 0b1000011 and is precalculated
	SD_voidAssertCs();
	sd_command(CMD8, CMD8_ARG, CMD8_CRC,&Local_SPI_sSdCard);
	sd_read_response3_7(SD_Response,&Local_SPI_sSdCard);
	SD_voidDeassertCs();


	// Select initialization sequence path
	if(SD_Response[0] == 0x01){
		// The card is Version 2.00 (or later) or SD memory card
		// Check voltage range
		if(SD_Response[3] != 0x01){
			return SD_NONCOMPATABLE_VOLTAGE_RANGE;
		}

		// Check echo pattern
		if(SD_Response[4] != 0xAA){
			return SD_CHECK_PATTERN_MISMATCH;
		}

		// CMD58 – read OCR (Operation Conditions Register) - R3 response
		SD_voidAssertCs();
		sd_command(CMD58, CMD58_ARG,CMD58_CRC,&Local_SPI_sSdCard);
		sd_read_response3_7(SD_Response,&Local_SPI_sSdCard);
		SD_voidDeassertCs();

		// ACMD41 – starts the initialization process – R1 response
		// Continue to send ACMD41 (always preceded by CMD55) until the card responds
		// with 'in_idle_state', which is R1 = 0×00.
		if(sd_command_ACMD41(&Local_SPI_sSdCard) > 0) return SD_IDLE_STATE_TIMEOUT;

		// CMD58 – read OCR (Operation Conditions Register) - R3 response
		SD_voidAssertCs();
		sd_command(CMD58, CMD58_ARG, CMD58_CRC,&Local_SPI_sSdCard);
		sd_read_response3_7(SD_Response,&Local_SPI_sSdCard);
		SD_voidDeassertCs();

		// Check if the card is ready
		// Read bit OCR 31 in R3
		if(!(SD_Response[1] & 0x80)){
			return SD_POWER_UP_BIT_NOT_SET;
		}

		// Read CCS bit OCR 30 in R3
		if(SD_Response[1] & 0x40){
			// SDXC or SDHC card
			SD_CardType = SD_V2_SDHC_SDXC;
		}else{
			// SDSC
			SD_CardType = SD_V2_SDSC;
		}

	}else if(SD_Response[0] == 0x05){
		// Response code 0×05 = Idle State + Illegal Command indicates
		// the card is of first generation. SD or MMC card.
		SD_CardType = SD_V1_SDSC;

		// ACMD41
		SD_Response[0] = sd_command_ACMD41(&Local_SPI_sSdCard);
		if(ILLEGAL_CMD(SD_Response[0])) return SD_NOT_SD_CARD;
		if(SD_Response[0]) return SD_IDLE_STATE_TIMEOUT;

	}else{
		return SD_GENERAL_ERROR;
	}



	return SD_OK;
}

u8 SD_u8ReadSingleBlock(u32 addr, u8 *buf){
	u8 res1, read = 0;
	u32 readAttempts;

	SPI_s Local_SPI_sSdCard = {SPI1_PORT, SPI_MASTER, SPI_PORTA, SPI_PIN8,1};

	if(SD_CardType == SD_V1_SDSC) addr *= 512;

	// set token to none
	SD_ResponseToken = 0xFF;

	SD_voidAssertCs();
	sd_command(CMD17, addr, CMD17_CRC,&Local_SPI_sSdCard);

	// read R1
	res1 = sd_read_response1(&Local_SPI_sSdCard);

	// if response received from card
	if(res1 != 0xFF){
		// wait for a response token
		// the host should use 100ms timeout (minimum) for single and multiple read operations
		readAttempts = 0;

		while(++readAttempts != SD_MAX_READ_ATTEMPTS){
			Local_SPI_sSdCard.SPI_pu16TransmitData[0]=0xFF;
			SPI_u8Transcieve(&Local_SPI_sSdCard);
			if((read = Local_SPI_sSdCard.SPI_pu16RecivedData[0]) != 0xFF) break;
		}

		// if response token is 0xFE
		if(read == 0xFE){
			// read 512 byte block
			SPI_u8Transcieve(&Local_SPI_sSdCard);
			for(u16 i = 0; i < SD_BUFFER_SIZE; i++) *buf++ = Local_SPI_sSdCard.SPI_pu16RecivedData[0];

			// add null to the end
			*buf = 0;

			// read and discard 16-bit CRC
			SPI_u8Transcieve(&Local_SPI_sSdCard);
			SPI_u8Transcieve(&Local_SPI_sSdCard);
		}

		// set token to card response
		SD_ResponseToken = read;
	}

	SD_voidDeassertCs();
	return res1;
}
