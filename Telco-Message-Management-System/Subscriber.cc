#include "Subscriber.h"

Subscriber::Subscriber(const string& number)
{
  phoneNum = number;
}

const string& Subscriber::getPhoneNum()
{
  return phoneNum;
}

MsgArray& Subscriber::getIncoming()
{
  return incomingMsgs;
}

MsgArray& Subscriber::getOutgoing()
{
  return outgoingMsgs;
}

void Subscriber::addIncoming(Msg* inMsg)
{
  incomingMsgs.add(inMsg);
}

void Subscriber::addOutgoing(Msg* outMsg)
{
  outgoingMsgs.add(outMsg);
}

void Subscriber::print()
{
  cout << "Subscriber " << phoneNum << ":" << endl;

  MsgArray allMsgs(incomingMsgs);
  allMsgs.add(outgoingMsgs);
  allMsgs.print();
}
