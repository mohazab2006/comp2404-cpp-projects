#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "MsgArray.h"

/*
 * Class: Subscriber
 * Purpose: Represents a telephone subscriber and tracks messages sent
 *          and received using pointers to the existing Msg objects.
 * Data members:
 *   phoneNum     - subscriber's telephone number
 *   incomingMsgs - references to messages received by this subscriber
 *   outgoingMsgs - references to messages sent by this subscriber
 * Member functions:
 *   Subscriber()  - initializes the subscriber's telephone number
 *   getPhoneNum() - returns the telephone number without allowing changes
 *   getIncoming() - returns the incoming message collection by reference
 *   getOutgoing() - returns the outgoing message collection by reference
 *   addIncoming() - adds an existing message to the incoming collection
 *   addOutgoing() - adds an existing message to the outgoing collection
 *   print()       - prints the phone number and all messages in one list
 */
class Subscriber
{
  public:
    Subscriber(const string&);
    const string& getPhoneNum();
    MsgArray& getIncoming();
    MsgArray& getOutgoing();
    void addIncoming(Msg*);
    void addOutgoing(Msg*);
    void print();

  private:
    string phoneNum;
    MsgArray incomingMsgs;
    MsgArray outgoingMsgs;
};

#endif
