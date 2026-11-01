#include "Telco.h"
#include "InternMsg.h"
#include "ExternMsg.h"

Telco::Telco(const string& telcoName)
    : name(telcoName)
{
}

Telco::~Telco()
{
  messages.cleanup();
}

void Telco::addSub(const string& phoneNum)
{
  Subscriber* existing = 0;

  if (phoneNum.empty() || subscribers.getSize() >= MAX_ARR_SIZE ||
      findSub(phoneNum, existing))
    return;

  Subscriber* sub = new Subscriber(phoneNum);
  subscribers.add(sub);
}

bool Telco::findSub(const string& phoneNum, Subscriber*& sub)
{
  sub = 0;

  for (int i = 0; i < subscribers.getSize(); ++i) {
    Subscriber* current = subscribers.get(i);

    if (current != 0 && current->getPhoneNum() == phoneNum) {
      sub = current;
      return true;
    }
  }

  return false;
}

void Telco::addMsg(const string& srcNum, const string& destNum,
                   int year, int month, int day, int hours, int mins)
{
  Subscriber* source = 0;
  Subscriber* destination = 0;

  bool hasSource = findSub(srcNum, source);
  bool hasDestination = findSub(destNum, destination);

  Msg* msg = 0;

  if (hasSource && hasDestination) {
    msg = new InternMsg(day, month, year, hours, mins,
                        source, destination);
  } else {
    msg = new ExternMsg(day, month, year, hours, mins,
                        srcNum, destNum);
  }

  messages.add(msg);
}

void Telco::printMessages()
{
  cout << endl << "TELCO " << name << " MESSAGES:" << endl;
  messages.print();
  cout << endl;
}

void Telco::printSubscribers()
{
  cout << endl << "TELCO " << name << " SUBSCRIBERS:" << endl << endl;

  if (subscribers.getSize() == 0) {
    cout << "No subscribers." << endl;
    return;
  }

  for (int i = 0; i < subscribers.getSize(); ++i) {
    Subscriber* sub = subscribers.get(i);
    sub->print();

    MsgList subset;
    subset.copySubset(sub->getPhoneNum(), messages);
    subset.print();
    cout << endl;
  }
}

void Telco::printByActivity()
{
  cout << endl << "==> MOST ACTIVE SUBSCRIBERS:" << endl << endl;

  int count = subscribers.getSize();

  if (count == 0) {
    cout << "No subscribers." << endl;
    return;
  }

  int totals[MAX_ARR_SIZE];
  int indexes[MAX_ARR_SIZE];

  for (int i = 0; i < count; ++i) {
    MsgList subset;
    Subscriber* sub = subscribers.get(i);
    subset.copySubset(sub->getPhoneNum(), messages);

    totals[i] = subset.getSize();
    indexes[i] = i;
  }

  selectionSort(count, totals, indexes);

  for (int i = 0; i < count; ++i) {
    Subscriber* sub = subscribers.get(indexes[i]);
    cout << "Subscriber " << sub->getPhoneNum() << ":" << endl;

    MsgList subset;
    subset.copySubset(sub->getPhoneNum(), messages);
    subset.print();
    cout << endl;
  }
}
