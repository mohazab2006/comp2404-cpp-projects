#include "HomeShare.h"

HomeShare::HomeShare() { numRentals = 0; }

int HomeShare::findRentalIndex(int rentalId)
{
    for (int i = 0; i < numRentals; i++)
    {
        if (rentals[i].getRentalId() == rentalId)
            return i;
    }
    return -1;
}

bool HomeShare::addRental(int rentalId, Category category, string description,
                          int maxPeople, double pricePerDay)
{
    if (numRentals >= MAX_ARRAY)
    {
        cout << "Add rental failed: no space" << endl;
        return false;
    }

    if (findRentalIndex(rentalId) != -1)
    {
        cout << "Add rental failed: duplicate rental id" << endl;
        return false;
    }

    rentals[numRentals] =
        Rental(rentalId, category, description, maxPeople, pricePerDay);
    numRentals++;

    cout << "Rental added" << endl;
    return true;
}

bool HomeShare::removeRental(int rentalId)
{
    int idx = findRentalIndex(rentalId);
    if (idx == -1)
    {
        cout << "Remove rental failed: rental not found" << endl;
        return false;
    }

    for (int i = idx; i < numRentals - 1; i++)
    {
        rentals[i] = rentals[i + 1];
    }
    numRentals--;

    cout << "Rental removed" << endl;
    return true;
}

bool HomeShare::addReservation(int rentalId, string name, int numPeople,
                               Date checkIn, Date checkOut)
{
    int idx = findRentalIndex(rentalId);
    if (idx == -1)
    {
        cout << "Add reservation failed: rental not found" << endl;
        return false;
    }

    bool ok = rentals[idx].addReservation(name, numPeople, checkIn, checkOut);
    if (ok)
    {
        cout << "Reservation added" << endl;
    }
    else
    {
        cout << "Add reservation failed" << endl;
    }
    return ok;
}

bool HomeShare::removeReservation(int rentalId, string name, Date &checkIn)
{
    int idx = findRentalIndex(rentalId);
    if (idx == -1)
    {
        cout << "Remove reservation failed: rental not found" << endl;
        return false;
    }

    bool ok = rentals[idx].removeReservation(name, checkIn);
    if (ok)
    {
        cout << "Reservation removed" << endl;
    }
    else
    {
        cout << "Remove reservation failed" << endl;
    }
    return ok;
}

void HomeShare::printRentals()
{
    for (int i = 0; i < numRentals; i++)
    {
        rentals[i].print();
    }
}

void HomeShare::printReservations(int rentalId)
{
    int idx = findRentalIndex(rentalId);
    if (idx == -1)
    {
        cout << "Rental not found" << endl;
        return;
    }
    rentals[idx].printReservations();
}

void HomeShare::printReservations(Date &date)
{
    for (int i = 0; i < numRentals; i++)
    {
        rentals[i].printReservation(date);
    }
}

void HomeShare::printRentalsByCategory(Category category)
{
    for (int i = 0; i < numRentals; i++)
    {
        if (rentals[i].getCategory() == category)
        {
            rentals[i].print();
        }
    }
}
