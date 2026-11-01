#ifndef BANK_H
#define BANK_H

#include "defs.h"
#include "Customer.h"
#include "Transaction.h"

/*
 * Class: Bank
 * Purpose: Manages the bank's customers, accounts, and transactions.
 * Data members: name stores the bank name; customers and numCustomers store
 * the customer collection; pendingTransactions and numPending store pending
 * transactions; loggedTransactions and numLogged store processed transactions.
 */
class Bank
{
  public:
    Bank();

    void setName(string);
    bool addCustomer(int, string);
    bool containsCustomer(int);
    Customer& findCustomer(int);
    bool addAccount(int, int, float);
    bool containsAccount(int);
    Account& findAccount(int);
    void addToTrArray(Transaction*, int&, Transaction&);
    bool addTransaction(TransactionType, int, float, int, int, int);
    void processTransactions();
    void printCustomers();
    void printTransactions(Transaction*, int);
    void printPendingTr();
    void printLoggedTr();

  private:
    string name;
    Customer customers[MAX_ARR_SIZE];
    int numCustomers;
    Transaction pendingTransactions[MAX_ARR_SIZE];
    int numPending;
    Transaction loggedTransactions[MAX_ARR_SIZE];
    int numLogged;
};

#endif
