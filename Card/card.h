#ifndef CARD_H
#define CARD_H
#include<stdio.h>
#include<string.h>
#include "../STD_Types.h"
#include<windows.h>

typedef struct ST_CardData_t
{
	uint8_t CardHolderName[25];
	uint8_t PrimaryAccountNumber[20];
	uint8_t CardExpiaryDate[6];
}ST_CardData_t;

typedef enum EN_cardError_t
{
	
	CARD_OK,
	WRONG_NAME,
	WRONG_EXP_DATE,
	WRONG_PAN,
} EN_cardError_t;

ST_CardData_t cardData;

EN_cardError_t GetCardHolderName(ST_CardData_t *CardData);

EN_cardError_t GetCardExpiaryDate(ST_CardData_t* CardData);

EN_cardError_t GetCard_PAN(ST_CardData_t* CardData);





#endif 