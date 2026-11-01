#ifndef TELCO_H
#define TELCO_H

#include "SubArray.h"
#include "MsgList.h"

/*
 * Class: Telco
 * Purpose: Manages the subscribers of a telephone company and all
 *          messages sent to and from its subscribers.
 * Data members:
 *   name        - name of the telephone company
 *   subscribers - collection of Subscriber pointers
 *   messages    - chronological doubly linked list of Msg pointers
 * Member functions:
 *   Telco()           - initializes the telephone company name
 *   ~Telco()          - releases all owned messages
 *   addSub()          - creates and adds a new subscriber
 *   addMsg()          - creates an internal or external message
 *   printMessages()   - prints every message
 *   printSubscribers()- prints subscribers and their messages
 *   printByActivity() - prints subscribers ranked by message count
 *   findSub()         - finds a subscriber using an output parameter
 */
class Telco
{
  public:
    Telco(const string&);
    ~Telco();

    void addSub(const string&);
    void addMsg(const string&, const string&, int, int, int, int, int);
    void printMessages();
    void printSubscribers();
    void printByActivity();
    bool findSub(const string&, Subscriber*&);

  private:
    string name;
    SubArray subscribers;
    MsgList messages;
};

#endif
