#include "Reservation.h"

Reservation::Reservation()
{
    name = "dummy";
    numPeople = 1;
    checkIn = Date(1901, 1, 1);
    checkOut = Date(1901, 1, 2);
}

Reservation::Reservation(string n, int p, Date ci, Date co)
{
    name = n;
    numPeople = p;
    checkIn = ci;
    checkOut = co;
}

string Reservation::getName() { return name; }
int Reservation::getNumPeople() { return numPeople; }
Date &Reservation::getCheckIn() { return checkIn; }
Date &Reservation::getCheckOut() { return checkOut; }

void Reservation::print()
{
    cout << "Reservation: " << name << endl;
    cout << "Num people: " << numPeople << endl;

    cout << "Check-in: ";
    checkIn.print();

    cout << "Check-out: ";
    checkOut.print();
}
