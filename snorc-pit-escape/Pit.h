#ifndef PIT_H
#define PIT_H

#include "defs.h"

class PartArray;
class Hero;
class Position;

/*
  Stores the empty pit layout in the layout array.
  withinBounds() checks coordinates, validPos() also checks ledges,
  underLedge() checks the space above a participant, and print()
  displays a temporary copy with all the participants.
*/
class Pit
{
  public:
    Pit(const char grid[MAX_ROW+1][MAX_COL+1]);
    bool validPos(int row, int col);
    bool withinBounds(int row, int col);
    bool underLedge(Position* p);
    void print(PartArray* part, Hero* h1, Hero* h2);

  private:
    char layout[MAX_ROW+1][MAX_COL+1];
};

#endif
