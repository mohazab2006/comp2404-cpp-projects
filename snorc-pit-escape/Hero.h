#ifndef HERO_H
#define HERO_H

#include "Participant.h"
#include <string>

/*
  Represents Timmy or Harold.
  name identifies the hero and health tracks their remaining health.
  move() handles climbing and incurDamage() handles being bitten.
*/
class Hero : public Participant
{
  public:
    Hero(char avatar, int row, int col, const std::string& name);
    virtual void move(Pit* p);
    virtual void incurDamage(Participant* p);
    virtual int causeDamage();
    std::string getName();
    int getHealth();

  private:
    std::string name;
    int health;
};

#endif
