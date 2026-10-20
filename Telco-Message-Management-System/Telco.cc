#include "Telco.h"

Telco::Telco(const string& telcoName)
{
  name = telcoName;
  numSubscribers = 0;

  for (int i = 0; i < MAX_ARR_SIZE; ++i)
    subscribers[i] = 0;
}

Telco::~Telco()
{
  for (int i = 0; i < numSubscribers; ++i)
    delete subscribers[i];

  allMsgs.cleanup();
}

void Telco::addSub(const string& phoneNumber)
{
  Subscriber* existing = 0;

  if (phoneNumber.empty() || numSubscribers >= MAX_ARR_SIZE ||
      findSub(phoneNumber, existing))
    return;

  subscribers[numSubscribers] = new Subscriber(phoneNumber);
  ++numSubscribers;
}

bool Telco::findSub(const string& phoneNumber, Subscriber*& sub)
{
  sub = 0;

  for (int i = 0; i < numSubscribers; ++i) {
    if (subscribers[i]->getPhoneNum() == phoneNumber) {
      sub = subscribers[i];
      return true;
    }
  }

  return false;
}

void Telco::addMsg(const string& source, const string& destination,
                   int year, int month, int day, int hours, int minutes)
{
  Subscriber* sender = 0;
  Subscriber* receiver = 0;

  bool senderExists = findSub(source, sender);
  bool receiverExists = findSub(destination, receiver);

  if ((!senderExists && !receiverExists) || allMsgs.getSize() >= MAX_ARR_SIZE)
    return;

  Msg* msg = new Msg(day, month, year, hours, minutes, source, destination);

  if (!allMsgs.add(msg)) {
    delete msg;
    return;
  }

  if (senderExists)
    sender->addOutgoing(msg);

  if (receiverExists)
    receiver->addIncoming(msg);
}

void Telco::printSubscribers()
{
  cout << endl << "TELCO " << name << ":" << endl << endl;

  if (numSubscribers == 0) {
    cout << "No subscribers" << endl;
    return;
  }

  for (int i = 0; i < numSubscribers; ++i) {
    subscribers[i]->print();
    cout << endl;
  }
}

void Telco::printFrequent(SubscriberType subType)
{
  int totals[MAX_ARR_SIZE];
  int indexes[MAX_ARR_SIZE];

  if (subType == C_SENDER)
    cout << endl << "==> MOST FREQUENT SENDING SUBSCRIBERS:" << endl << endl;
  else if (subType == C_RECEIVER)
    cout << endl << "==> MOST FREQUENTLY RECEIVING SUBSCRIBERS:" << endl << endl;
  else
    return;

  if (numSubscribers == 0) {
    cout << "No subscribers" << endl;
    return;
  }

  for (int i = 0; i < numSubscribers; ++i) {
    indexes[i] = i;

    if (subType == C_SENDER)
      totals[i] = subscribers[i]->getOutgoing().getSize();
    else
      totals[i] = subscribers[i]->getIncoming().getSize();
  }

  selectionSort(numSubscribers, totals, indexes);

  for (int i = 0; i < numSubscribers; ++i) {
    Subscriber* sub = subscribers[indexes[i]];
    MsgArray& messages = (subType == C_SENDER) ?
      sub->getOutgoing() : sub->getIncoming();

    cout << "FROM: " << sub->getPhoneNum() << ":";
    if (messages.getSize() > 0) {
      cout << endl;
      messages.print();
    } else {
      cout << "  No messages" << endl;
    }
    cout << endl;
  }
}
