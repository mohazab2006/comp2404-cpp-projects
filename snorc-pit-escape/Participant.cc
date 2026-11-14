#include "defs.h"
#include "Participant.h"
#include "Position.h"

Participant::Participant(char a, int r, int c)
  : avatar(a), dead(false)
{
  pos = new Position(r, c);
}

Participant::~Participant()
{
  delete pos;
}

bool Participant::collide(Participant* p)
{
  if (p == NULL || p == this) return false;
  return pos->equals(p->pos);
}

bool Participant::isDead()
{
  return dead;
}

bool Participant::isSafe()
{
  return pos->getRow() == 0;
}

char Participant::getAvatar()
{
  return avatar;
}

int Participant::getRow()
{
  return pos->getRow();
}

int Participant::getCol()
{
  return pos->getCol();
}
