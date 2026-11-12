#ifndef VIEW_H
#define VIEW_H

#include "defs.h"

/*
 * Class: View
 * Purpose: Handles the program's menu, input, and text output.
 * Data members:
 *   None.
 * Member functions:
 *   showMenu() - displays the menu and reads the user's selection
 *   printStr() - prints a string
 *   readInt()  - reads an integer
 *   readStr()  - reads a string
 */
class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif
