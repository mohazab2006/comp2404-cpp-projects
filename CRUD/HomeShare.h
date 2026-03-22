#ifndef HOMESHARE_H
#define HOMESHARE_H

#include <iostream>
#include <string>

#include "Rental.h"
#include "defs.h"

using namespace std;
using namespace cat;

class HomeShare
{
  public:
    HomeShare();

    bool addRental(int rentalId, Category category, string description,
                   int maxPeople, double pricePerDay);
    bool removeRental(int rentalId);

    bool addReservation(int rentalId, string name, int numPeople, Date checkIn,
                        Date checkOut);
    bool removeReservation(int rentalId, string name, Date &checkIn);

    void printRentals();
    void printReservations(int rentalId);
    void printReservations(Date &date);
    void printRentalsByCategory(Category category);

  private:
    Rental rentals[MAX_ARRAY];
    int numRentals;

    int findRentalIndex(int rentalId);
};

#endif
