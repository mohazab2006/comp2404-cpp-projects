#include "Date.h"

Date::Date() { setDate(1901, 1, 1); }

Date::Date(int y, int m, int d) { setDate(y, m, d); }

// ✅ FIX: const copy constructor
Date::Date(const Date &d) { setDate(d.year, d.month, d.day); }

// setters
void Date::setDay(int d)
{
    int max = getDaysInMonth();
    if (d > max)
        d = max;
    if (d < 1)
        d = 1;
    day = d;
}

void Date::setMonth(int m)
{
    if (m > 12)
        m = 12;
    if (m < 1)
        m = 1;
    month = m;
}

void Date::setYear(int y)
{
    if (y < 1901)
        y = 1901;
    year = y;
}

void Date::setDate(int y, int m, int d)
{
    // set year first so Feb bounds correct for leap years
    setYear(y);
    setMonth(m);
    setDay(d);
}

void Date::setDate(Date &d) { setDate(d.year, d.month, d.day); }

// getters
int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }

string Date::getMonthName()
{
    string months[12] = {"January",   "February", "March",    "April",
                         "May",       "June",     "July",     "August",
                         "September", "October",  "November", "December"};
    // ✅ Jan 14 fix
    return months[month - 1];
}

string Date::getShortMonthName()
{
    string smonths[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    // ✅ Jan 14 fix
    return smonths[month - 1];
}

// other
bool Date::isLeapYear(int year)
{
    if (year % 4 != 0)
        return false;
    if (year % 100 != 0)
        return true;
    return year % 400 == 0;
}

int Date::getDaysInMonth(int y, int m)
{
    switch (m)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return isLeapYear(y) ? 29 : 28;
        default:
            return 31;
    }
}

int Date::getDaysInMonth() { return getDaysInMonth(year, month); }

int Date::convertToDays()
{
    int total = 0;

    for (int y = 1901; y < year; y++)
    {
        total += 365;
        if (isLeapYear(y))
            total++;
    }

    for (int m = 1; m < month; m++)
    {
        total += getDaysInMonth(year, m);
    }

    total += day;
    return total;
}

// required by spec
bool Date::equals(Date &d)
{
    return year == d.year && month == d.month && day == d.day;
}

// required by spec
bool Date::lessThan(Date &d) { return convertToDays() < d.convertToDays(); }

void Date::print()
{
    cout << getMonthName() << " " << getDay() << ", " << getYear() << endl;
}
