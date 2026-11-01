#include "Bank.h"

Bank::Bank()
{
  name = "";
  numCustomers = 0;
  numPending = 0;
  numLogged = 0;
}

void Bank::setName(string n)
{
  name = n;
}

bool Bank::addCustomer(int custId, string n)
{
  if (numCustomers >= MAX_ARR_SIZE)
    return false;

  if (containsCustomer(custId))
    return false;

  Customer newCustomer(custId, n);
  customers[numCustomers] = newCustomer;
  numCustomers++;

  return true;
}

bool Bank::containsCustomer(int custId)
{
  for (int i = 0; i < numCustomers; i++) {
    if (customers[i].getId() == custId)
      return true;
  }

  return false;
}

Customer& Bank::findCustomer(int custId)
{
  for (int i = 0; i < numCustomers; i++) {
    if (customers[i].getId() == custId)
      return customers[i];
  }

  cout << "ERROR: customer not found" << endl;
  exit(1);
}

bool Bank::addAccount(int acctId, int custId, float initBalance)
{
  if (!containsCustomer(custId))
    return false;

  if (containsAccount(acctId))
    return false;

  Customer& customer = findCustomer(custId);
  return customer.addAccount(acctId, initBalance);
}

bool Bank::containsAccount(int acctId)
{
  for (int i = 0; i < numCustomers; i++) {
    if (customers[i].containsAccount(acctId))
      return true;
  }

  return false;
}

Account& Bank::findAccount(int acctId)
{
  for (int i = 0; i < numCustomers; i++) {
    if (customers[i].containsAccount(acctId))
      return customers[i].findAccount(acctId);
  }

  cout << "ERROR: account not found" << endl;
  exit(1);
}

void Bank::addToTrArray(Transaction* arr, int& numTr,
                        Transaction& newTr)
{
  if (numTr >= MAX_ARR_SIZE)
    return;

  int pos = numTr;

  while (pos > 0 &&
         !arr[pos - 1].getDate().lessThan(newTr.getDate())) {
    arr[pos] = arr[pos - 1];
    pos--;
  }

  arr[pos] = newTr;
  numTr++;
}

bool Bank::addTransaction(TransactionType t, int acctId, float amt,
                          int yr, int mth, int day)
{
  if (!containsAccount(acctId))
    return false;

  if (numPending >= MAX_ARR_SIZE)
    return false;

  Transaction newTr(t, acctId, amt, yr, mth, day);
  addToTrArray(pendingTransactions, numPending, newTr);

  return true;
}

void Bank::processTransactions()
{
  int year, month, day;
  currentDate(year, month, day);
  Date today(year, month, day);

  int numProcessed = 0;

  for (int i = 0; i < numPending; i++) {
    if (today.lessThan(pendingTransactions[i].getDate()))
      break;

    Account& acct = findAccount(pendingTransactions[i].getAccountId());

    if (pendingTransactions[i].process(acct)) {
      addToTrArray(loggedTransactions, numLogged, pendingTransactions[i]);
    }
    else {
      cout << "ERROR: Transaction failed" << endl;
    }

    numProcessed++;
  }

  for (int i = numProcessed; i < numPending; i++)
    pendingTransactions[i - numProcessed] = pendingTransactions[i];

  numPending -= numProcessed;
}

void Bank::printCustomers()
{
  cout << endl << "CUSTOMERS:" << endl;

  for (int i = 0; i < numCustomers; i++)
    customers[i].print();
}

void Bank::printTransactions(Transaction* arr, int numTr)
{
  for (int i = 0; i < numTr; i++)
    arr[i].print();
}

void Bank::printPendingTr()
{
  cout << endl << "PENDING TRANSACTIONS:" << endl;
  printTransactions(pendingTransactions, numPending);
}

void Bank::printLoggedTr()
{
  cout << endl << "LOGGED TRANSACTIONS:" << endl;
  printTransactions(loggedTransactions, numLogged);
}
