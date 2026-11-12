#include "Date.h"

Date::Date(int d, int m, int y)
{
  day = 1;
  month = 1;
  year = 2000;

  if (y >= 1 && m >= 1 && m <= 12 &&
      d >= 1 && d <= lastDayInMonth(m, y)) {
    day = d;
    month = m;
    year = y;
  }
}

bool Date::greaterThan(Date* d)
{
  if (d == 0)
    return false;

  if (year != d->year)
    return year > d->year;

  if (month != d->month)
    return month > d->month;

  return day > d->day;
}

bool Date::equals(Date* d)
{
  if (d == 0)
    return false;

  return year == d->year && month == d->month && day == d->day;
}

void Date::print()
{
  cout << year << "-" << setfill('0') << setw(2) << month
       << "-" << setw(2) << day << setfill(' ');
}

int Date::lastDayInMonth(int m, int y)
{
  if (m == 2)
    return leapYear(y) ? 29 : 28;

  if (m == 4 || m == 6 || m == 9 || m == 11)
    return 30;

  if (m >= 1 && m <= 12)
    return 31;

  return 0;
}

bool Date::leapYear(int y)
{
  return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
