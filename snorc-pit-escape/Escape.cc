#include "defs.h"
#include "Escape.h"
#include "Pit.h"
#include "Hero.h"
#include "Snorc.h"
#include "Participant.h"

Escape::Escape()
  : numSnorcs(0), pit(NULL), timmy(NULL), harold(NULL)
{
  srand( (unsigned)time( NULL ) );

  const char templateGrid[MAX_ROW+1][MAX_COL+1]={
      "-------------------------",
      "-             --        -",
      "-                      --",
      "-       --              -",
      "                  --    -",
      "--       -              -",
      "---                    --",
      "---       --          ---",
      "--                     --",
      "-            --        --",
      "---               --     ",
      "--        --    ---    --",
      "--  --                  -",
      "--        --       -     ",
      "--                  -    ",
      "--     --         --    -",
      "---                    --",
      "--       ---    --      -",
      "--                     --",
      "-------------------------"
  };

  int timmyCol = random(10) + 7;
  int haroldCol = random(10) + 7;
  while (haroldCol == timmyCol) haroldCol = random(10) + 7;

  timmy = new Hero('T', MAX_ROW - 2, timmyCol, "Timmy");
  harold = new Hero('H', MAX_ROW - 2, haroldCol, "Harold");
  participants.add(timmy);
  participants.add(harold);
  pit = new Pit(templateGrid);
}

Escape::~Escape()
{
  for (int i = 0; i < participants.getSize(); i++) {
    delete participants.get(i);
  }
  delete pit;
}

void Escape::spawnSnorc()
{
  if (numSnorcs >= MAX_SNORCS) return;

  int row = MAX_ROW - 2 - random(5);
  int col = random(MAX_COL - 2) + 1;
  while (!pit->validPos(row, col)) col = random(MAX_COL - 2) + 1;
  int strength = random(3) + 2;

  Snorc* snorc = new Snorc(row, col, strength);
  participants.add(snorc);
  numSnorcs++;
}

Participant* Escape::checkForCollision(Participant* p)
{
  if (p == NULL) return NULL;

  for (int i = 0; i < participants.getSize(); i++) {
    Participant* other = participants.get(i);
    if (other != p && p->collide(other)) return other;
  }
  return NULL;
}

void Escape::moveParticipants()
{
  for (int i = 0; i < participants.getSize(); i++) {
    Participant* p = participants.get(i);
    if (p == NULL) continue;

    p->move(pit);
    Participant* other = checkForCollision(p);
    if (other != NULL) {
      p->incurDamage(other);
      other->incurDamage(p);
    }
  }
}

bool Escape::isOver()
{
  return (timmy->isDead() || timmy->isSafe()) &&
         (harold->isDead() || harold->isSafe());
}

void Escape::printOutcome()
{
  cout << endl;
  if (timmy->isSafe() && harold->isSafe()) {
    cout << "BOTH HEROES ESCAPED !!!" << endl;
  }
  else if (timmy->isDead() && harold->isDead()) {
    cout << "BOTH HEROES DIED..." << endl;
  }
  else if (timmy->isSafe()) {
    cout << "Timmy escaped, but Harold died..." << endl;
  }
  else {
    cout << "Harold escaped, but Timmy died..." << endl;
  }
}

void Escape::runEscape()
{
  while (!isOver()) {
    if (numSnorcs < MAX_SNORCS && random(100) < SNORC_SPAWN) {
      spawnSnorc();
    }

    moveParticipants();
    cout << "\033[2J\033[H";
    pit->print(&participants, timmy, harold);
    usleep(50000);
  }

  cout << "\033[2J\033[H";
  pit->print(&participants, timmy, harold);
  printOutcome();
}
