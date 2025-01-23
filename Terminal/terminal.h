#ifndef TERMINAL_H
#define TERMINAL_H



typedef struct ST_TerminalData_t
{

	float TransAmount;
	float MaxTransAmount;
	uint8_t TransactionDate[11];
}ST_TerminalData_t;


typedef enum EN_TerminalError_t
{
	TERMINAL_OK,
	WRONG_DATE,
	EXPIRED_CARD,
	INVALID_CARD,
	INVALID_AMOUNT,
	EXCEEED_MAX_AMOUNT,
	INVALID_MAX_AMOUNT,
}EN_TerminalError_t;

ST_TerminalData_t TerminalData;

EN_TerminalError_t GetTransactionDate(ST_TerminalData_t *terminalData);

EN_TerminalError_t IsCardExpired(ST_TerminalData_t* terminalData);

EN_TerminalError_t GetTransactionAmount(ST_TerminalData_t* terminalData);

EN_TerminalError_t IsBelowMaxAmount(ST_TerminalData_t *terminalData);

EN_TerminalError_t SetMaxAmount(ST_TerminalData_t* terminalData, float MaxAmount);






#endif