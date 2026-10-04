#include "Rental.h"

Rental::Rental()
{
    rentalId = 0;
    category = misc;
    description = "";
    maxPeople = 1;
    pricePerDay = 1.0;
    numReservations = 0;
}

Rental::Rental(int id, Category c, string desc, int maxP, double price)
{
    rentalId = id;
    category = c;
    description = desc;

    if (maxP < 1)
        maxP = 1;
    if (price <= 0)
        price = 1.0;

    maxPeople = maxP;
    pricePerDay = price;
    numReservations = 0;
}

int Rental::getRentalId() { return rentalId; }
Category Rental::getCategory() { return category; }

bool Rental::dateLE(Date &a, Date &b) { return a.lessThan(b) || a.equals(b); }

// Overlap exists unless: aOut <= bIn OR bOut <= aIn
bool Rental::overlaps(Date &aIn, Date &aOut, Date &bIn, Date &bOut)
{
    if (dateLE(aOut, bIn))
        return false;
    if (dateLE(bOut, aIn))
        return false;
    return true;
}

bool Rental::addReservation(string name, int numPeople, Date checkIn,
                            Date checkOut)
{
    if (numReservations >= MAX_ARRAY)
        return false;
    if (numPeople < 1 || numPeople > maxPeople)
        return false;

    // checkOut must be at least 1 day later => checkIn < checkOut
    if (!checkIn.lessThan(checkOut))
        return false;

    // find insertion position sorted by check-in
    int pos = 0;
    while (pos < numReservations &&
           reservations[pos].getCheckIn().lessThan(checkIn))
    {
        pos++;
    }

    // overlap with previous
    if (pos > 0)
    {
        Date &prevIn = reservations[pos - 1].getCheckIn();
        Date &prevOut = reservations[pos - 1].getCheckOut();
        if (overlaps(prevIn, prevOut, checkIn, checkOut))
            return false;
    }

    // overlap with next
    if (pos < numReservations)
    {
        Date &nextIn = reservations[pos].getCheckIn();
        Date &nextOut = reservations[pos].getCheckOut();
        if (overlaps(checkIn, checkOut, nextIn, nextOut))
            return false;
    }

    // shift right
    for (int i = numReservations; i > pos; i--)
    {
        reservations[i] = reservations[i - 1];
    }

    reservations[pos] = Reservation(name, numPeople, checkIn, checkOut);
    numReservations++;
    return true;
}

bool Rental::removeReservation(string name, Date &checkIn)
{
    for (int i = 0; i < numReservations; i++)
    {
        if (reservations[i].getName() == name &&
            reservations[i].getCheckIn().equals(checkIn))
        {
            for (int j = i; j < numReservations - 1; j++)
            {
                reservations[j] = reservations[j + 1];
            }
            numReservations--;
            return true;
        }
    }
    return false;
}

void Rental::print()
{
    cout << "Rental ID: " << rentalId << endl;
    cout << "Category: " << categoryToString(category) << endl;
    cout << "Description: " << description << endl;
    cout << "Max People: " << maxPeople << endl;
    cout << "Price per Day: $" << fixed << setprecision(2) << pricePerDay
         << endl;
}

void Rental::printReservations()
{
    for (int i = 0; i < numReservations; i++)
    {
        reservations[i].print();
    }
}

void Rental::printReservation(Date &date)
{
    // c.check_in <= date < c.check_out
    for (int i = 0; i < numReservations; i++)
    {
        Date &in = reservations[i].getCheckIn();
        Date &out = reservations[i].getCheckOut();

        if (dateLE(in, date) && date.lessThan(out))
        {
            reservations[i].print();
            return;
        }
    }
    cout << "No reservation found" << endl;
}
