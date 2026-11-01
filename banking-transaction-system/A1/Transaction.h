#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "defs.h"
#include "Date.h"
#include "Account.h"

/*
 * Class: Transaction
 * Purpose: Represents a debit or credit transaction on a bank account.
 * Data members: type stores the transaction type, accountId identifies the
 * affected account, amount stores the transaction amount, and date stores the
 * date on which the transaction is scheduled.
 */
class Transaction
{
  public:
    Transaction(TransactionType = TR_OTHER, int = 0, float = 0,
                int = 1901, int = 1, int = 1);

    int getAccountId();
    Date& getDate();
    bool process(Account&);
    void print();

  private:
    TransactionType type;
    int accountId;
    float amount;
    Date date;
};

#endif
