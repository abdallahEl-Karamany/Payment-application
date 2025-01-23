#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "app.h"
#include<stdio.h>
//#include<stdio.h>
#include "../STD_TYPES.H"
#include"../Card/card.h"
#include"../Terminal/terminal.h"
#include "../Server/server.h"




uint8_t status;
uint8_t status1;




void main(void)
{
	status = WRONG_EXP_DATE;
		while (status != CARD_OK)
	{
		status = GetCardHolderName(&cardData);
		status = GetCard_PAN(&cardData);
		status = GetCardExpiaryDate(&cardData);
	}
		

	if (status == CARD_OK)
	{
		system("cls");
	}
	//puts(&Transaction_Data.CardHolderData.PrimaryAccountNumber);
	GetTransactionDate(&TerminalData);
	
	status=IsCardExpired(&TerminalData);

	if (status == EXPIRED_CARD)
	{
		printf("Declined \n");
		printf("sorry Expired Cared\n");
		exit(0);
	}
	else
	{
		system("cls");
	}

	SetMaxAmount(&TerminalData,maxAmount);
	status = INVALID_AMOUNT;
	while (status != TERMINAL_OK)
	{

		status=GetTransactionAmount(&TerminalData);
	}
	
	status = IsBelowMaxAmount(&TerminalData);
	
	if (status != TERMINAL_OK)
	{
		printf("Declined\n");
		printf("Sorry Transaction Exceed max amount\n");
		exit(0);
	}
	else
	{
		system("cls");
	}

	status = 0;

	status = RecieveTransactionData(&Transaction_Data);

	/*APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD,
		INTERNAL_SERVER_ERROR,*/

	if (status == DECLINED_INSUFFECIENT_FUND)
	{
		printf("Declined\n");
		printf("Sorry Insuffecient Fund\n");
		exit(0);
	}
	else if (status == DECLINED_STOLEN_CARD)
	{
		printf("Declined\n");
		printf("Sorry Stolen Card\n");
		exit(0);
	}
	else if (status == FRAUD_CARD)
	{
		printf("Declined\n");
		printf("Sorry Not Valid Account\n");
		exit(0);
	}
	else if (status == INTERNAL_SERVER_ERROR)
	{
		printf("Declined\n");
		printf("Sorry Server Error\n");
		exit(0);
	}
	else
	{
		//printf("have passed");
		system("cls");
	}
	
	SaveTransaction(&Transaction_Data);
	
	ListSavedTransactions();

	
}