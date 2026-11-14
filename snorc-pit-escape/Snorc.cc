#include "defs.h"
#include "Snorc.h"
#include "Pit.h"
#include "Position.h"

Snorc::Snorc(int r, int c, int s)
  : Participant('s', r, c), strength(s)
{
}

void Snorc::move(Pit* p)
{
  if (p == NULL) return;

  int row = getRow();
  int col = getCol();
  int newRow = row;

  if (random(2) == 0) newRow--;
  else newRow++;

  if (newRow >= MAX_ROW - 8 && newRow <= MAX_ROW - 2) row = newRow;
  col += random(3) - 1;

  if (p->withinBounds(row, col)) pos->set(row, col);
}

void Snorc::incurDamage(Participant*)
{
}

int Snorc::causeDamage()
{
  return strength;
}
