#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "defs.h"

/*
 * Class: Account
 * Purpose: Represents one bank account belonging to a customer.
 * Data members: accountId uniquely identifies the account, customerId
 * identifies its owner, and balance stores the current account balance.
 */
class Account
{
  public:
    Account(int = 0, int = 0, float = 0);

    int getId();
    bool credit(float);
    bool debit(float);
    void print();

  private:
    int accountId;
    int customerId;
    float balance;
};

#endif
