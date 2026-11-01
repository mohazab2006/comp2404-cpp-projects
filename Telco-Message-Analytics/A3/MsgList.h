#ifndef MSGLIST_H
#define MSGLIST_H

#include "Msg.h"

/*
 * Class: MsgList
 * Purpose: Stores Msg pointers in a doubly linked list, ordered from
 *          newest to oldest by message date and time.
 * Nested class:
 *   Node     - holds a message pointer and links to adjacent nodes
 * Data members:
 *   head     - pointer to the first node, or null for an empty list
 *   size     - number of nodes currently in the list
 * Member functions:
 *   MsgList()   - initializes an empty list
 *   ~MsgList()  - deletes list nodes, but not the messages they point to
 *   getSize()   - returns the number of messages in the list
 *   add()       - inserts a message in descending chronological order
 *   copySubset()- adds references to messages matching a phone number
 *   cleanup()   - deletes all messages and list nodes
 *   print()     - prints messages forward and then backward
 */
class MsgList
{
  private:
    class Node
    {
      public:
        Node(Msg*);
        Msg* data;
        Node* next;
        Node* prev;
    };

    Node* head;
    int size;

  public:
    MsgList();
    ~MsgList();
    int getSize();
    void add(Msg*);
    void copySubset(string, MsgList&);
    void cleanup();
    void print();
};

#endif
