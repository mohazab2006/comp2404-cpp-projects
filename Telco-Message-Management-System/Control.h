#ifndef CONTROL_H
#define CONTROL_H

#include "Telco.h"
#include "View.h"

/*
 * Class: Control
 * Purpose: Manages the interactive menu and coordinates View and Telco.
 * Data members:
 *   view  - displays the menu and reads the user's choice
 *   telco - dynamically allocated telephone company, owned by Control
 * Member functions:
 *   Control()         - allocates the Telco object
 *   ~Control()        - deletes the owned Telco object
 *   launch()          - loads the initial data and runs the menu
 *   initData()        - calls the supplied initialization functions
 *   initSubscribers() - loads the professor's subscriber data
 *   initMsgs()        - loads the professor's message data
 */
class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    View view;
    Telco* telco;
    void initData(Telco*);
    void initSubscribers(Telco*);
    void initMsgs(Telco*);
};

#endif
