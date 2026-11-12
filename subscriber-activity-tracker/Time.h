#ifndef TIME_H
#define TIME_H

#include "defs.h"

/*
 * Class: Time
 * Purpose: Stores the hour and minute of a message timestamp.
 * Data members:
 *   hours   - hour of the day
 *   minutes - minute within the hour
 * Member functions:
 *   Time()          - initializes and validates the time
 *   greaterThan()   - compares this time with another
 *   print()         - displays hours and minutes
 *   convertToMins() - converts the time to minutes for comparison
 */
class Time
{
  public:
    Time(int=0, int=0);
    bool greaterThan(Time*);
    void print();

  private:
    int hours;
    int minutes;
    int convertToMins();
};

#endif
