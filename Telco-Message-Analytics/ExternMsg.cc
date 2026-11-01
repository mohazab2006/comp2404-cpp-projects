#include "ExternMsg.h"

ExternMsg::ExternMsg(int d, int m, int y, int h, int min,
                     const string& source, const string& destination)
    : Msg(d, m, y, h, min), src(source), dest(destination)
{
}

string ExternMsg::getSrc()
{
  return src;
}

string ExternMsg::getDest()
{
  return dest;
}

void ExternMsg::print()
{
  Msg::print();
  cout << " E-Msg From: " << getSrc() << "  To: " << getDest() << endl;
}
