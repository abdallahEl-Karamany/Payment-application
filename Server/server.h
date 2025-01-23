#ifndef SERVER_H
#define SERVER_H

typedef enum EN_TransState_t 
{
	APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD,
	INTERNAL_SERVER_ERROR,

}EN_TransState_t;

typedef struct ST_Transaction_t
{
	ST_CardData_t CardHolderData;
	ST_TerminalData_t TerminalData;
	EN_TransState_t TransState;
	uint32_t transactionSequenceNumber;

}ST_Transaction_t;

ST_Transaction_t Transaction_Data;

typedef enum EN_ServerError_t
{
	SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
}EN_ServerError_t;

typedef enum EN_AccountState_t
{
	RUNNING,
	BLOCKED
}EN_AccountState_t;

typedef struct ST_AccountsDB_t
{
	float balance;
	EN_AccountState_t State;
	uint8_t PrimaryAccountNumber[20];
}ST_AccountsDB_t;


EN_ServerError_t _isValidAccount;
EN_ServerError_t _isBlockedAccount;
EN_ServerError_t _isAmountAvailable;
EN_ServerError_t _saveTransaction;

EN_TransState_t RecieveTransactionData(ST_Transaction_t* transData);

EN_ServerError_t IsValidAccount(ST_CardData_t* cardData, ST_AccountsDB_t* accountRefrence);

EN_ServerError_t IsBlockedAccount(ST_AccountsDB_t* accountRefrence);

EN_ServerError_t IsAmountAvailable(ST_TerminalData_t* termData, ST_AccountsDB_t *accountRefrence);

EN_ServerError_t SaveTransaction(ST_Transaction_t* transData);

void ListSavedTransactions(void);







#endif