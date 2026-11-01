#ifndef SUBARRAY_H
#define SUBARRAY_H

#include "Subscriber.h"

/*
 * Class: SubArray
 * Purpose: Stores pointers to the subscribers belonging to a telco.
 * Data members:
 *   elements - fixed-size array of Subscriber pointers
 *   size     - number of subscribers currently stored
 * Member functions:
 *   SubArray()  - initializes an empty subscriber collection
 *   ~SubArray() - deallocates the subscribers owned by the collection
 *   getSize()  - returns the number of subscribers
 *   get()      - returns a subscriber at an index, or null if invalid
 *   add()      - appends a subscriber pointer to the collection
 */
class SubArray
{
  public:
    SubArray();
    ~SubArray();

    int getSize();
    Subscriber* get(int);
    void add(Subscriber*);

  private:
    Subscriber* elements[MAX_ARR_SIZE];
    int size;
};

#endif
