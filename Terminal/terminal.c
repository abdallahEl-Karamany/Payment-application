#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include"../Card/card.h"
#include "terminal.h"


float maxAmount = 1000000;




EN_TerminalError_t GetTransactionDate(ST_TerminalData_t *terminalData) 
{
    
	
    uint8_t Conv[5];

    SYSTEMTIME t; // Declare SYSTEMTIME struct
    GetLocalTime(&t); // Fill out the struct so that it can be used
    
    snprintf(Conv, 3, "%d", t.wDay);
    
    if (t.wDay < 10)
    {
        strcat(terminalData->TransactionDate, "0");
        strcat(terminalData->TransactionDate, Conv);
        strcat(terminalData->TransactionDate, "/");
    }
    else
    {
        strcpy(terminalData->TransactionDate, Conv);
        strcat(terminalData->TransactionDate, "/");
    }
    snprintf(Conv, 3, "%d", t.wMonth);
    
    if (t.wMonth < 10)
    {
        strcat(terminalData->TransactionDate, "0");
        strcat(terminalData->TransactionDate, Conv);
    }
    else
    {
        strcat(terminalData->TransactionDate, Conv);
    }
    snprintf(Conv, 5, "%d", t.wYear);
    strcat(terminalData->TransactionDate, "/");
    strcat(terminalData->TransactionDate, Conv);
     
    puts(terminalData->TransactionDate);
    //puts(&terminalData->TransactionDate[8]);

    return TERMINAL_OK;
}

EN_TerminalError_t IsCardExpired(ST_TerminalData_t* terminalData)
{ 
    if (terminalData->TransactionDate[8] <  cardData.CardExpiaryDate[3])
    {
        if(cardData.CardExpiaryDate[0]=='1'&& cardData.CardExpiaryDate[1]>'2')
        {
            return EXPIRED_CARD;
        }
        else
        { 
            return TERMINAL_OK;
        } 
    }
    else if (terminalData->TransactionDate[8] == cardData.CardExpiaryDate[3])
    {
        if (terminalData->TransactionDate[9] <  cardData.CardExpiaryDate[4])
        {
            return TERMINAL_OK;
        }
        else
        {
            if (terminalData->TransactionDate[3] > cardData.CardExpiaryDate[0])
            {
                return EXPIRED_CARD;

            }
            else if (terminalData->TransactionDate[4] > cardData.CardExpiaryDate[1])
            {
                 
                    return EXPIRED_CARD;
                
            }
            else
            {
                if (cardData.CardExpiaryDate[0] == '1' && cardData.CardExpiaryDate[1] > '2')
                {
                    return WRONG_EXP_DATE;
                }
                else
                {
                    return TERMINAL_OK;
                }
            }
        }
    }
    else
    {
        return EXPIRED_CARD;
    }    
}


EN_TerminalError_t GetTransactionAmount(ST_TerminalData_t* terminalData)
{
    printf("\nplease enter your Transacation Amount\n");
    scanf_s("%f", &terminalData->TransAmount);
    if (terminalData->TransAmount <= 0.0)
    {
        return INVALID_AMOUNT;
    }
    return TERMINAL_OK;
}
EN_TerminalError_t IsBelowMaxAmount(ST_TerminalData_t* terminalData)
{
    if (terminalData->TransAmount > terminalData->MaxTransAmount)
    {
        return EXCEEED_MAX_AMOUNT;
    }

    return TERMINAL_OK;
}

EN_TerminalError_t SetMaxAmount(ST_TerminalData_t* terminalData,float MaxAmount)
{
    
    if (MaxAmount <= 0.0)
    {
        return INVALID_MAX_AMOUNT;
    }
    terminalData->MaxTransAmount = MaxAmount;
    return TERMINAL_OK;
}
