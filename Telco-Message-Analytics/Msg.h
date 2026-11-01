#ifndef MSG_H
#define MSG_H

#include "Date.h"
#include "Time.h"

/*
 * Class: Msg
 * Purpose: Represents the date and time of a text message and acts as
 *          the base class for internal and external messages.
 * Data members:
 *   date - pointer to the dynamically allocated message date
 *   time - pointer to the dynamically allocated message time
 * Member functions:
 *   Msg()         - constructs a message and allocates Date and Time objects
 *   ~Msg()        - releases the owned Date and Time objects
 *   greaterThan() - checks whether this message was sent later than another
 *   getSrc()      - returns an empty string (overridden in derived classes)
 *   getDest()     - returns an empty string (overridden in derived classes)
 *   print()       - prints the message's date and time
 */
class Msg
{
  public:
    Msg(int, int, int, int, int);
    virtual ~Msg();

    bool greaterThan(Msg*);
    virtual string getSrc();
    virtual string getDest();
    virtual void print();

  private:
    Date* date;
    Time* time;
};

#endif
