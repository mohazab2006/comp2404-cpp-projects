#include "defs.h"
#include "Hero.h"
#include "Pit.h"
#include "Position.h"

Hero::Hero(char a, int r, int c, const std::string& n)
  : Participant(a, r, c), name(n), health(MAX_HEALTH)
{
}

void Hero::move(Pit* p)
{
  if (p == NULL || isDead() || isSafe()) return;

  int row = pos->getRow();
  int col = pos->getCol();

  if (p->underLedge(pos)) {
    if (random(2) == 0) col--;
    else col++;
  }
  else {
    int choice = random(10);
    if (choice < 5) row--;
    else if (choice == 5) row -= 2;
    else row++;
    col += random(5) - 2;
  }

  Position next(row, col);
  if ((next.getRow() == 0 && next.getCol() > 0 &&
       next.getCol() < MAX_COL - 1) ||
      p->validPos(next.getRow(), next.getCol())) {
    pos->set(next.getRow(), next.getCol());
  }
}

void Hero::incurDamage(Participant* p)
{
  if (p == NULL || isDead() || isSafe()) return;

  health -= p->causeDamage();
  if (health <= 0) {
    health = 0;
    dead = true;
    avatar = '+';
  }
}

int Hero::causeDamage()
{
  return 0;
}

std::string Hero::getName()
{
  return name;
}

int Hero::getHealth()
{
  return health;
}
