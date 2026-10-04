#ifndef DATE_H
#define DATE_H

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const int MAX_DURATION = 3;

class Date
{
  public:
    // constructors
    Date();
    Date(int year, int month, int day);
    Date(const Date &); // ✅ FIX: must be const so initializer lists compile

    // setters
    void setDay(int);
    void setMonth(int);
    void setYear(int);

    void setDate(int, int, int);
    void setDate(Date &);

    // getters
    int getDay();
    int getMonth();
    int getYear();
    string getMonthName();
    string getShortMonthName();

    // required by spec
    bool equals(Date &d);
    bool lessThan(Date &d);

    // other
    bool isLeapYear(int year);

    void print();
    int convertToDays();

  private:
    int getDaysInMonth();             // uses current year/month
    int getDaysInMonth(int y, int m); // helper for convertToDays

    int day;
    int month;
    int year;
};

#endif
