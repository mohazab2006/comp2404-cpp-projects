#ifndef DATE_H
#define DATE_H

#include "defs.h"

/*
 * Class: Date
 * Purpose: Represents a calendar date and supports chronological comparison.
 * Data members:
 *   day   - day of the month
 *   month - month of the year
 *   year  - calendar year
 * Member functions:
 *   Date()          - constructs and validates a date
 *   greaterThan()   - tests whether this date is later than another date
 *   equals()        - tests whether two dates are the same
 *   print()         - displays the date
 *   lastDayInMonth()- gives the number of days in a particular month
 *   leapYear()      - tests whether a year is a leap year
 */
class Date
{
  public:
    Date(int=1, int=1, int=2000);
    bool greaterThan(Date*);
    bool equals(Date*);
    void print();

  private:
    int day;
    int month;
    int year;
    int lastDayInMonth(int, int);
    bool leapYear(int);
};

#endif
