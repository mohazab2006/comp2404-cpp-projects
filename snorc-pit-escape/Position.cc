#include "defs.h"
#include "Position.h"

Position::Position(int r, int c)
{
  set(r, c);
}

void Position::set(int r, int c)
{
  if (r < 0) r = 0;
  if (r >= MAX_ROW) r = MAX_ROW - 1;
  if (c < 0) c = 0;
  if (c >= MAX_COL) c = MAX_COL - 1;

  row = r;
  col = c;
}

bool Position::equals(Position* p)
{
  if (p == NULL) return false;
  return row == p->getRow() && col == p->getCol();
}

int Position::getRow()
{
  return row;
}

int Position::getCol()
{
  return col;
}
