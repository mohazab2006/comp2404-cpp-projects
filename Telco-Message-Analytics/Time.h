#ifndef TIME_H
#define TIME_H

#include "defs.h"

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
