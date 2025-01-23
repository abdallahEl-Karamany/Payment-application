#include "card.h"







EN_cardError_t GetCardHolderName(ST_CardData_t* CardData)
{
	printf("\nplease enter your full name: \n");

	fgets(CardData->CardHolderName,25, stdin);
	
	_strupr_s(CardData->CardHolderName,25);
	//puts(CardData->CardHolderName);

	if (strlen(CardData->CardHolderName) < 20 || strlen(CardData->CardHolderName) >= 24 )
	{
		return WRONG_NAME;
	}
	else if(strlen(CardData->CardHolderName) == 0)
	{

		return WRONG_NAME;
	}
	else
	{
		return CARD_OK;
	}
	



}

EN_cardError_t GetCardExpiaryDate(ST_CardData_t* CardData)
{
	printf("\n please enter your Expiration date: \n");

	gets(CardData->CardExpiaryDate);
	//puts(CardData->CardExpiaryDate);

	if (strlen(CardData->CardExpiaryDate) == 0)
	{
		return WRONG_EXP_DATE;
	}
	else if (strlen(CardData->CardExpiaryDate) > 5 || strlen(CardData->CardExpiaryDate) < 5)
	{

		return WRONG_EXP_DATE;
	}
	else 
	{
		if (CardData->CardExpiaryDate[2] != '/')
		{
			return WRONG_EXP_DATE;

		}
		else if (CardData->CardExpiaryDate[0] > '1' )
		{
			return WRONG_EXP_DATE;
		}
		else if (CardData->CardExpiaryDate[0] == '1' && CardData->CardExpiaryDate[1] > '2')
		{
			return WRONG_EXP_DATE;
		}
		else
		{
			return CARD_OK;
		}

	}

}

EN_cardError_t GetCard_PAN(ST_CardData_t* CardData)
{
	printf("\nplease enter your Primary Acount Number: \n");

	gets(CardData->PrimaryAccountNumber);
	//puts(CardData->PrimaryAccountNumber);

	if (strlen(CardData->PrimaryAccountNumber) > 19 || strlen(CardData->PrimaryAccountNumber) < 16)
	{
		return WRONG_PAN;
	}
	
	else
	{
		return CARD_OK;
	}


}
