#ifndef RESERVATION_H
#define RESERVATION_H

#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

class Reservation
{
  public:
    Reservation();
    Reservation(string name, int numPeople, Date checkIn, Date checkOut);

    string getName();
    int getNumPeople();
    Date &getCheckIn();
    Date &getCheckOut();

    void print();

  private:
    string name;
    int numPeople;
    Date checkIn;
    Date checkOut;
};

#endif
