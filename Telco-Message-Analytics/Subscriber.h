#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "defs.h"

/*
 * Class: Subscriber
 * Purpose: Represents a telephone company subscriber with a unique ID
 *          and phone number. Messages are stored by the Telco, not here.
 * Data members:
 *   nextId   - shared counter used to assign unique subscriber IDs
 *   id       - unique ID for this subscriber
 *   phoneNum - subscriber's phone number
 * Member functions:
 *   Subscriber()  - assigns the next ID and initializes the phone number
 *   getPhoneNum() - returns the subscriber's phone number
 *   print()       - displays the subscriber's ID and phone number
 */
class Subscriber
{
  public:
    Subscriber(const string&);
    const string& getPhoneNum() const;
    void print() const;

  private:
    static int nextId;
    int id;
    string phoneNum;
};

#endif
