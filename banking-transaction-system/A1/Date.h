#ifndef DATE_H
#define DATE_H

#include "defs.h"

/*
 * Class: Date
 * Purpose: Represents a calendar date.
 * Data members: year, month, and day store the date components.
 */
class Date
{
  public:
    Date(int = 1901, int = 1, int = 1);

    bool lessThan(Date&);
    void print();

  private:
    int year;
    int month;
    int day;
};

#endif
