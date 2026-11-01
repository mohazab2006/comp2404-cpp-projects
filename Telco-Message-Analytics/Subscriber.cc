#include "Subscriber.h"

int Subscriber::nextId = SUBSCRIBER_ID;

Subscriber::Subscriber(const string& number)
    : id(nextId++), phoneNum(number)
{
}

const string& Subscriber::getPhoneNum() const
{
  return phoneNum;
}

void Subscriber::print() const
{
  cout << "Subscriber :: " << id << " :: " << phoneNum << endl;
}
