#ifndef INTERNMSG_H
#define INTERNMSG_H

#include "Msg.h"
#include "Subscriber.h"

/*
 * Class: InternMsg
 * Purpose: Represents a text message sent between two subscribers of
 *          the same telco. Inherits the message date and time from Msg.
 * Data members:
 *   src  - pointer to the existing source Subscriber (not owned)
 *   dest - pointer to the existing destination Subscriber (not owned)
 * Member functions:
 *   InternMsg() - initializes the date, time, source, and destination
 *   getSrc()    - returns the source subscriber's phone number
 *   getDest()   - returns the destination subscriber's phone number
 *   print()     - prints the date, time, and both phone numbers
 */
class InternMsg : public Msg
{
  public:
    InternMsg(int, int, int, int, int, Subscriber*, Subscriber*);
    virtual string getSrc();
    virtual string getDest();
    virtual void print();

  private:
    Subscriber* src;
    Subscriber* dest;
};

#endif
