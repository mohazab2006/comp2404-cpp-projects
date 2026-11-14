#ifndef ESCAPE_H
#define ESCAPE_H

#include "PartArray.h"

class Pit;
class Hero;
class Participant;

/*
  Runs the escape simulation.
  numSnorcs tracks spawned enemies, participants holds all pointers,
  pit stores the game grid, and timmy/harold point to the two heroes.
  The private functions handle spawning, movement, collisions, and ending.
*/
class Escape
{
  public:
    Escape();
    ~Escape();
    void runEscape();

  private:
    int numSnorcs;
    PartArray participants;
    Pit* pit;
    Hero* timmy;
    Hero* harold;

    void spawnSnorc();
    void moveParticipants();
    Participant* checkForCollision(Participant* p);
    bool isOver();
    void printOutcome();
};

#endif
