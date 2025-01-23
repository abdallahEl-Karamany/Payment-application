#include"../Card/card.h"
#include "../Terminal/terminal.h"
#include"server.h"
#include "DataBase.h"

ST_AccountsDB_t* Account_Ref = AccountDB;
uint8_t sequenceNumber = 0;

EN_TransState_t RecieveTransactionData(ST_Transaction_t* transData)
{
	float New_Balance;

	transData->CardHolderData = cardData;
	
	transData->TerminalData=TerminalData;
	
	
	
	_isValidAccount = IsValidAccount(&cardData, Account_Ref);
	_isAmountAvailable = IsAmountAvailable(&TerminalData, Account_Ref);
	_isBlockedAccount = IsBlockedAccount(Account_Ref);
	//_saveTransaction = SaveTransaction(Transaction_DB);

	if (_isValidAccount != SERVER_OK)
	{
		return FRAUD_CARD;
	}
	else if (_isAmountAvailable !=SERVER_OK)
	{
		return DECLINED_INSUFFECIENT_FUND;
	}
	else if (_isBlockedAccount!=SERVER_OK)
	{
		return DECLINED_STOLEN_CARD;
	}
	/*else if ( _saveTransaction!= SERVER_OK)
	{
		return INTERNAL_SERVER_ERROR;
	}*/
	else
	{
		New_Balance = Account_Ref->balance - transData->TerminalData.TransAmount;
		Account_Ref->balance = New_Balance;
		 //maxAmount = maxAmount - transData->TerminalData.TransAmount;
		return APPROVED;
	}
	
}
EN_ServerError_t IsValidAccount(ST_CardData_t* cardData, ST_AccountsDB_t* accountRefrence)
{
	
	uint8_t stat ;
	for (uint8_t i = 0; i < 11; i++)
	{
		stat = strcmp(accountRefrence[i].PrimaryAccountNumber, cardData->PrimaryAccountNumber);
		if (stat == 0)
		{
			Account_Ref = &accountRefrence[i];
			/*puts(Account_Ref->PrimaryAccountNumber);
			printf("\n\n");*/
			return SERVER_OK ;
		}
		

	}
	Account_Ref = NULL;
	return ACCOUNT_NOT_FOUND;
}
EN_ServerError_t IsBlockedAccount(ST_AccountsDB_t* accountRefrence)
{
	if (accountRefrence->State == RUNNING)
	{
		return SERVER_OK;
			
	}
	return BLOCKED_ACCOUNT;
}
EN_ServerError_t IsAmountAvailable(ST_TerminalData_t* termData, ST_AccountsDB_t* accountRefrence)
{
	if (termData->TransAmount <= accountRefrence->balance)
	{
		return SERVER_OK;
	}

	return LOW_BALANCE;

}
EN_ServerError_t SaveTransaction(ST_Transaction_t* transData)
{
	
	if (transData->transactionSequenceNumber < 255)
	{
		Transaction_DB[sequenceNumber].CardHolderData = transData->CardHolderData;
		Transaction_DB[sequenceNumber].TerminalData = transData->TerminalData;
		Transaction_DB[sequenceNumber].transactionSequenceNumber = sequenceNumber;

		if (_isValidAccount != SERVER_OK)
		{
			Transaction_DB[sequenceNumber].TransState = FRAUD_CARD;
		}
		else if (_isAmountAvailable != SERVER_OK)
		{
			Transaction_DB[sequenceNumber].TransState = DECLINED_INSUFFECIENT_FUND;
		}
		else if (_isBlockedAccount != SERVER_OK)
		{
			Transaction_DB[sequenceNumber].TransState = DECLINED_STOLEN_CARD;
		}
		else
		{
			Transaction_DB[sequenceNumber].TransState = APPROVED;
		}
		sequenceNumber++;

		return SERVER_OK;
	}
	
		return SAVING_FAILED;
}
void ListSavedTransactions(void)
{
	printf("########################################### \n");
	for(uint8_t i=0;i <= sequenceNumber-1;i++)
	{
		
		printf("Transaction Sequence Number :	%d\n", Transaction_DB[i].transactionSequenceNumber);
		printf("Transaction Date :	%s\n", Transaction_DB[i].TerminalData.TransactionDate);
		printf("Transaction Amount :	%f\n", Transaction_DB[i].TerminalData.TransAmount);
		printf("Transaction State :	%d\n", Transaction_DB[i].TransState);
		printf("Terminal Max Amount :	%f\n", Transaction_DB[i].TerminalData.MaxTransAmount);
		printf("Cardholder Name :	%s", Transaction_DB[i].CardHolderData.CardHolderName);
		printf("PAN:	%s\n", Transaction_DB[i].CardHolderData.PrimaryAccountNumber);
		printf("Card Expiration Date :	%s\n", Transaction_DB[i].CardHolderData.CardExpiaryDate);
		printf("########################################### \n");
	}
	
}