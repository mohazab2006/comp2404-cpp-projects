#ifndef PARTICIPANT_H
#define PARTICIPANT_H

class Position;
class Pit;

/*
  Base class for heroes and snorcs.
  avatar is the character shown on the grid, dead is the death status,
  and pos points to the participant's Position.
  Derived classes provide movement and damage functions.
*/
class Participant
{
  public:
    Participant(char avatar, int row, int col);
    virtual ~Participant();

    virtual void move(Pit* p) = 0;
    virtual void incurDamage(Participant* p) = 0;
    virtual int causeDamage() = 0;

    bool collide(Participant* p);
    bool isDead();
    bool isSafe();
    char getAvatar();
    int getRow();
    int getCol();

  protected:
    char avatar;
    bool dead;
    Position* pos;
};

#endif
