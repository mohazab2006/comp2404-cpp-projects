#include "Transaction.h"

Transaction::Transaction(TransactionType t, int id, float amt,
                         int yr, int mth, int day)
  : date(yr, mth, day)
{
  type = t;
  accountId = id;
  amount = amt;
}

int Transaction::getAccountId()
{
  return accountId;
}

Date& Transaction::getDate()
{
  return date;
}

bool Transaction::process(Account& acct)
{
  bool success = false;

  if (type == TR_DEBIT) {
    success = acct.debit(amount);

    if (!success) {
      cout << "ERROR: Account " << accountId
           << " could not be debited by amount $"
           << fixed << setprecision(2) << amount << endl;
    }
  }
  else if (type == TR_CREDIT) {
    success = acct.credit(amount);

    if (!success) {
      cout << "ERROR: Account " << accountId
           << " could not be credited by amount $"
           << fixed << setprecision(2) << amount << endl;
    }
  }
  else {
    cout << "ERROR: invalid transaction type" << endl;
  }

  return success;
}

void Transaction::print()
{
  cout << accountId << " :: ";

  if (type == TR_DEBIT)
    cout << left << setw(8) << "Debit";
  else if (type == TR_CREDIT)
    cout << left << setw(8) << "Credit";
  else
    cout << left << setw(8) << "Other";

  cout << ":: ";
  date.print();
  cout << " ::  $ "
       << right << setw(7) << fixed << setprecision(2)
       << amount << endl;
}
