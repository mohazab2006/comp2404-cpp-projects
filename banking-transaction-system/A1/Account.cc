#include "Account.h"

Account::Account(int aId, int cId, float b)
{
  accountId = aId;
  customerId = cId;
  balance = b;
}

int Account::getId()
{
  return accountId;
}

bool Account::credit(float amt)
{
  if (amt <= 0)
    return false;

  balance += amt;
  return true;
}

bool Account::debit(float amt)
{
  if (amt <= 0 || balance - amt < 0)
    return false;

  balance -= amt;
  return true;
}

void Account::print()
{
  cout << accountId << "  "
       << customerId << ":  $ "
       << right << setw(7) << fixed << setprecision(2)
       << balance << endl;
}
