#ifndef MSGARRAY_H
#define MSGARRAY_H

#include "Msg.h"

/*
 * Class: MsgArray
 * Purpose: Stores pointers to text messages in descending chronological order.
 * Data members:
 *   elements - fixed-size array of pointers to existing Msg objects
 *   size     - number of message pointers currently stored
 * Member functions:
 *   MsgArray()       - constructs an empty collection
 *   MsgArray() copy  - makes a shallow copy of another collection
 *   ~MsgArray()      - does not delete shared messages
 *   getSize()        - returns the number of messages
 *   get()            - retrieves a message pointer at a given index
 *   add(Msg*)        - inserts a message in descending chronological order
 *   add(MsgArray&)   - inserts all messages from another collection
 *   cleanup()        - deletes contained messages when the array owns them
 *   print()          - prints every message or "No messages" when empty
 */
class MsgArray
{
  public:
    MsgArray();
    MsgArray(MsgArray&);
    ~MsgArray();

    int getSize();
    Msg* get(int);
    bool add(Msg*);
    bool add(MsgArray&);
    void cleanup();
    void print();

  private:
    Msg* elements[MAX_ARR_SIZE];
    int size;
};

#endif
