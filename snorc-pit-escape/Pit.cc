#include "Pit.h"
#include "Position.h"
#include "PartArray.h"
#include "Participant.h"
#include "Hero.h"

Pit::Pit(const char grid[MAX_ROW+1][MAX_COL+1])
{
  for (int i = 0; i < MAX_ROW + 1; i++) {
    for (int j = 0; j < MAX_COL + 1; j++) {
      layout[i][j] = grid[i][j];
    }
  }
}

bool Pit::withinBounds(int row, int col)
{
  return row > 0 && row < MAX_ROW - 1 &&
         col > 0 && col < MAX_COL - 1;
}

bool Pit::validPos(int row, int col)
{
  return withinBounds(row, col) && layout[row][col] != '-';
}

bool Pit::underLedge(Position* p)
{
  if (p == NULL || p->getRow() <= 1) return false;
  return layout[p->getRow() - 1][p->getCol()] == '-';
}

void Pit::print(PartArray* part, Hero* h1, Hero* h2)
{
  char grid[MAX_ROW+1][MAX_COL+1];

  for (int i = 0; i < MAX_ROW + 1; i++) {
    for (int j = 0; j < MAX_COL + 1; j++) {
      grid[i][j] = layout[i][j];
    }
  }

  if (part != NULL) {
    for (int i = 0; i < part->getSize(); i++) {
      Participant* p = part->get(i);
      if (p != NULL && !p->isSafe() &&
          withinBounds(p->getRow(), p->getCol())) {
        grid[p->getRow()][p->getCol()] = p->getAvatar();
      }
    }
  }

  if (h1 != NULL && !h1->isSafe() &&
      withinBounds(h1->getRow(), h1->getCol())) {
    grid[h1->getRow()][h1->getCol()] = h1->getAvatar();
  }
  if (h2 != NULL && !h2->isSafe() &&
      withinBounds(h2->getRow(), h2->getCol())) {
    grid[h2->getRow()][h2->getCol()] = h2->getAvatar();
  }

  for (int i = 0; i < MAX_ROW; i++) {
    for (int j = 0; j < MAX_COL; j++) cout << grid[i][j];

    if (i == MAX_ROW - 2 && h1 != NULL) {
      cout << "     " << left << setw(6) << h1->getName()
           << ": " << right << setw(2) << h1->getHealth();
    }
    if (i == MAX_ROW - 1 && h2 != NULL) {
      cout << "     " << left << setw(6) << h2->getName()
           << ": " << right << setw(2) << h2->getHealth();
    }
    cout << endl;
  }
}
