#include "Msg.h"

Msg::Msg(int d, int m, int y, int h, int min)
{
  date = new Date(d, m, y);
  time = new Time(h, min);
}

Msg::~Msg()
{
  delete date;
  delete time;
}

bool Msg::greaterThan(Msg* msg)
{
  if (msg == 0)
    return false;

  if (date->greaterThan(msg->date))
    return true;

  if (date->equals(msg->date))
    return time->greaterThan(msg->time);

  return false;
}

string Msg::getSrc()
{
  return "";
}

string Msg::getDest()
{
  return "";
}

void Msg::print()
{
  date->print();
  cout << "  ";
  time->print();
}
