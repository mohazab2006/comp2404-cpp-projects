#ifndef EXTERNMSG_H
#define EXTERNMSG_H

#include "Msg.h"

/*
 * Class: ExternMsg
 * Purpose: Represents a message between a telco subscriber and an
 *          external phone number. Inherits date and time from Msg.
 * Data members:
 *   src  - source phone number
 *   dest - destination phone number
 * Member functions:
 *   ExternMsg() - initializes the message date, time, and phone numbers
 *   getSrc()   - returns the source phone number
 *   getDest()  - returns the destination phone number
 *   print()    - displays the message date, time, and phone numbers
 */
class ExternMsg : public Msg
{
  public:
    ExternMsg(int, int, int, int, int, const string&, const string&);
    virtual string getSrc();
    virtual string getDest();
    virtual void print();

  private:
    string src;
    string dest;
};

#endif
