#include "Control.h"

Control::Control()
{
  telco = new Telco("Christine's Telephone Co.");
}

Control::~Control()
{
  delete telco;
}

void Control::launch()
{
  initData(telco);

  int choice = -1;
  do {
    view.showMenu(choice);

    if (choice == 1)
      telco->printMessages();
    else if (choice == 2)
      telco->printSubscribers();
    else if (choice == 3)
      telco->printByActivity();

  } while (choice != 0);
}



void Control::initData(Telco* tel)
{
  initSubscribers(tel);
  initMsgs(tel);
}

void Control::initSubscribers(Telco* tel)
{
  tel->addSub("613-999-0000"); 
  tel->addSub("613-333-4444");
  tel->addSub("613-888-9999"); 
  tel->addSub("613-111-2222");
  tel->addSub("613-222-3333");
  tel->addSub("613-444-5555"); 
}

void Control::initMsgs(Telco* tel)
{
  tel->addMsg("613-999-0000", "613-333-4444", 2026, 1, 1, 0, 31);
  tel->addMsg("613-999-0000", "613-222-3333", 2025, 2, 2, 10, 54);

  tel->addMsg("613-222-3333", "613-999-0000", 2025, 2, 23, 6, 33);
  tel->addMsg("613-222-3333", "613-999-0000", 2026, 3, 2, 10, 54);
  tel->addMsg("613-222-3333", "613-999-0000", 2025, 2, 20, 14, 22);
  tel->addMsg("613-222-3333", "613-111-2222", 2025, 12, 18, 4, 5);
  tel->addMsg("613-222-3333", "613-777-8888", 2026, 10, 1, 14, 35);

  tel->addMsg("613-111-2222", "613-222-3333", 2026, 6, 30, 6, 2);
  tel->addMsg("613-111-2222", "613-999-0000", 2025, 8, 9, 8, 34);
  tel->addMsg("613-111-2222", "613-000-0000", 2025, 8, 9, 8, 29);
  tel->addMsg("613-111-2222", "613-888-9999", 2026, 3, 10, 15, 12);
  tel->addMsg("613-111-2222", "613-888-9999", 2025, 3, 10, 15, 12);

  tel->addMsg("613-444-5555", "613-888-9999", 2026, 3, 10, 15, 22);
  tel->addMsg("613-444-5555", "613-888-7777", 2026, 3, 10, 15, 24);
}

