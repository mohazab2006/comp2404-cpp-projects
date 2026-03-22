#ifndef RENTAL_H
#define RENTAL_H

#include <iomanip>
#include <iostream>
#include <string>

#include "Category.h"
#include "Reservation.h"
#include "defs.h"

using namespace std;
using namespace cat;

class Rental
{
  public:
    Rental();
    Rental(int rentalId, Category category, string description, int maxPeople,
           double pricePerDay);

    int getRentalId();
    Category getCategory();

    bool addReservation(string name, int numPeople, Date checkIn,
                        Date checkOut);
    bool removeReservation(string name, Date &checkIn);

    void print();
    void printReservations();
    void printReservation(Date &date);

  private:
    int rentalId;
    Category category;
    string description;
    int maxPeople;
    double pricePerDay;

    Reservation reservations[MAX_ARRAY];
    int numReservations;

    bool dateLE(Date &a, Date &b); // a <= b
    bool overlaps(Date &aIn, Date &aOut, Date &bIn, Date &bOut);
};

#endif
