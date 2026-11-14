#ifndef PARTARRAY_H
#define PARTARRAY_H

#include "defs.h"

class Participant;

/*
  Stores the Participant pointers used by the simulation.
  elements is the array and size is the current number of elements.
  add() inserts a pointer; get() and getSize() return stored data.
*/
class PartArray
{
  public:
    PartArray();
    void add(Participant* p);
    Participant* get(int index);
    int getSize();

  private:
    Participant* elements[MAX_ARR];
    int size;
};

#endif
