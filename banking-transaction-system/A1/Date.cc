#include "Date.h"

Date::Date(int y, int m, int d)
{
  year = y;
  month = m;
  day = d;
}

bool Date::lessThan(Date& d)
{
  if (year < d.year)
    return true;

  if (year > d.year)
    return false;

  if (month < d.month)
    return true;

  if (month > d.month)
    return false;

  return day < d.day;
}

void Date::print()
{
  cout << right << setfill('0')
       << setw(4) << year << "-"
       << setw(2) << month << "-"
       << setw(2) << day
       << setfill(' ');
}
