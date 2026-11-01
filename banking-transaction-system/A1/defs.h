#ifndef DEFS_H
#define DEFS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

#define MAX_ARR_SIZE  128


typedef enum { TR_DEBIT, TR_CREDIT, TR_OTHER} TransactionType;

class Bank;

void loadCustomerData(Bank&);
void loadTransactionData(Bank&);
void printMenu(int&);
void currentDate(int&, int&, int&);

#endif

