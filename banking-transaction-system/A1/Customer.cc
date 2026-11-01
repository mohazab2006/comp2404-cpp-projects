#include "Customer.h"

Customer::Customer(int id, string n)
{
  customerId = id;
  name = n;
  numAccounts = 0;
}

int Customer::getId()
{
  return customerId;
}

bool Customer::addAccount(int acctId, float acctBalance)
{
  if (numAccounts >= MAX_ARR_SIZE)
    return false;

  if (containsAccount(acctId))
    return false;

  Account newAccount(acctId, customerId, acctBalance);
  accounts[numAccounts] = newAccount;
  numAccounts++;

  return true;
}

bool Customer::containsAccount(int acctId)
{
  for (int i = 0; i < numAccounts; i++) {
    if (accounts[i].getId() == acctId)
      return true;
  }

  return false;
}

Account& Customer::findAccount(int acctId)
{
  for (int i = 0; i < numAccounts; i++) {
    if (accounts[i].getId() == acctId)
      return accounts[i];
  }

  cout << "ERROR: account not found" << endl;
  exit(1);
}

void Customer::print()
{
  cout << "== " << customerId << "  " << name << endl;

  if (numAccounts == 0) {
    cout << "   -- No accounts" << endl;
    return;
  }

  for (int i = 0; i < numAccounts; i++)
    accounts[i].print();
}
