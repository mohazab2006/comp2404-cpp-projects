#ifndef POSITION_H
#define POSITION_H

/*
  Stores the row and column of a participant.
  row and col are private. set() checks the grid limits,
  equals() compares positions, and the getters return the coordinates.
*/
class Position
{
  public:
    Position(int row, int col);
    void set(int row, int col);
    bool equals(Position* p);
    int getRow();
    int getCol();

  private:
    int row;
    int col;
};

#endif
