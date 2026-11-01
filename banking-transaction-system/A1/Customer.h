#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "defs.h"
#include "Account.h"

/*
 * Class: Customer
 * Purpose: Represents a bank customer and the accounts owned by that customer.
 * Data members: customerId uniquely identifies the customer, name stores the
 * customer's name, accounts stores the customer's Account objects, and
 * numAccounts stores the number of accounts currently in the array.
 */
class Customer
{
  public:
    Customer(int = 0, string = "");

    int getId();
    bool addAccount(int, float);
    bool containsAccount(int);
    Account& findAccount(int);
    void print();

  private:
    int customerId;
    string name;
    Account accounts[MAX_ARR_SIZE];
    int numAccounts;
};

#endif
