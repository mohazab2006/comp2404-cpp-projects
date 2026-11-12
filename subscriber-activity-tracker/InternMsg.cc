#include "InternMsg.h"

InternMsg::InternMsg(int d, int m, int y, int h, int min,
                     Subscriber* source, Subscriber* destination)
    : Msg(d, m, y, h, min), src(source), dest(destination)
{
}

string InternMsg::getSrc()
{
  if (src == 0)
    return "";

  return src->getPhoneNum();
}

string InternMsg::getDest()
{
  if (dest == 0)
    return "";

  return dest->getPhoneNum();
}

void InternMsg::print()
{
  Msg::print();
  cout << " I-Msg From: " << getSrc() << "  To: " << getDest() << endl;
}
