#ifndef MSG_H
#define MSG_H

#include "Date.h"
#include "Time.h"

/*
 * Class: Msg
 * Purpose: Represents the metadata of one text message.
 * Data members:
 *   src  - sender's telephone number
 *   dest - receiver's telephone number
 *   date - dynamically allocated date when the message was sent
 *   time - dynamically allocated time when the message was sent
 * Member functions:
 *   Msg()         - constructs a message and allocates its date and time
 *   ~Msg()        - deletes the owned date and time objects
 *   greaterThan() - checks whether this message was sent later
 *   print()       - displays the sender, receiver, date and time
 */
class Msg
{
  public:
    Msg(int, int, int, int, int, const string&, const string&);
    ~Msg();
    bool greaterThan(Msg*);
    void print();

  private:
    string src;
    string dest;
    Date* date;
    Time* time;
};

#endif
