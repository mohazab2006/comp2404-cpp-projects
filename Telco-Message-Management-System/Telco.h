#ifndef TELCO_H
#define TELCO_H

#include "Subscriber.h"

/*
 * Class: Telco
 * Purpose: Manages telephone subscribers and the messages they send or receive.
 * Data members:
 *   name           - the telephone company's name
 *   numSubscribers - number of subscribers currently stored
 *   subscribers    - primitive array of dynamically allocated Subscriber pointers
 *   allMsgs        - primary, owning collection of message pointers
 * Member functions:
 *   Telco()           - initializes the name and subscriber collection
 *   ~Telco()          - deletes all subscribers and all owned messages
 *   addSub()          - adds a subscriber to the end of the array
 *   addMsg()          - creates one message and shares its pointer with subscribers
 *   printFrequent()   - prints subscribers ordered by sent/received totals
 *   printSubscribers()- prints each subscriber and their messages
 *   findSub()         - finds a subscriber using an output pointer parameter
 */
class Telco
{
  public:
    Telco(const string&);
    ~Telco();

    void addSub(const string&);
    void addMsg(const string&, const string&, int, int, int, int, int);
    void printFrequent(SubscriberType);
    void printSubscribers();
    bool findSub(const string&, Subscriber*&);

  private:
    string name;
    int numSubscribers;
    Subscriber* subscribers[MAX_ARR_SIZE];
    MsgArray allMsgs;
};

#endif
