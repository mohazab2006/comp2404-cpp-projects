#ifndef SNORC_H
#define SNORC_H

#include "Participant.h"

/*
  Represents a snorc in the bottom seven rows of the pit.
  strength stores how much damage it does to heroes.
  Snorcs move randomly and do not take damage.
*/
class Snorc : public Participant
{
  public:
    Snorc(int row, int col, int strength);
    virtual void move(Pit* p);
    virtual void incurDamage(Participant* p);
    virtual int causeDamage();

  private:
    int strength;
};

#endif
