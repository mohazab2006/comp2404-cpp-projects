#ifndef CONTROL_H
#define CONTROL_H

#include "Telco.h"
#include "View.h"

/*
 * Class: Control
 * Purpose: Controls the user menu and initializes the telephone company.
 * Data members:
 *   telco - dynamically allocated telephone company object
 *   view  - user interface object for menus and input
 * Member functions:
 *   Control()         - allocates the telephone company
 *   ~Control()        - releases the telephone company
 *   launch()          - initializes the data and handles user menu choices
 *   initData()        - invokes the provided subscriber/message initialization
 *   initSubscribers() - creates the provided subscribers
 *   initMsgs()        - creates the provided messages
 */
class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    Telco* telco;
    View view;

    void initData(Telco*);
    void initSubscribers(Telco*);
    void initMsgs(Telco*);
};

#endif
