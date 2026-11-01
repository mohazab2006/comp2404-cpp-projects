#include "MsgList.h"

MsgList::Node::Node(Msg* msg)
    : data(msg), next(0), prev(0)
{
}

MsgList::MsgList()
    : head(0), size(0)
{
}

MsgList::~MsgList()
{
  Node* current = head;
  while (current != 0) {
    Node* nextNode = current->next;
    delete current;
    current = nextNode;
  }
  head = 0;
  size = 0;
}

int MsgList::getSize()
{
  return size;
}

void MsgList::add(Msg* msg)
{
  if (msg == 0)
    return;

  Node* current = head;
  Node* previous = 0;

  while (current != 0 && !msg->greaterThan(current->data)) {
    previous = current;
    current = current->next;
  }

  Node* newNode = new Node(msg);
  newNode->prev = previous;
  newNode->next = current;

  if (previous == 0)
    head = newNode;
  else
    previous->next = newNode;

  if (current != 0)
    current->prev = newNode;

  ++size;
}

void MsgList::copySubset(string phoneNum, MsgList& origList)
{
  if (&origList == this)
    return;

  Node* current = origList.head;
  while (current != 0) {
    if (current->data->getSrc() == phoneNum ||
        current->data->getDest() == phoneNum)
      add(current->data);

    current = current->next;
  }
}

void MsgList::cleanup()
{
  Node* current = head;
  while (current != 0) {
    Node* nextNode = current->next;
    delete current->data;
    delete current;
    current = nextNode;
  }
  head = 0;
  size = 0;
}

void MsgList::print()
{
  if (head == 0) {
    cout << "No messages." << endl;
    return;
  }

  cout << "FORWARD:" << endl;
  Node* current = head;
  Node* last = 0;

  while (current != 0) {
    current->data->print();
    last = current;
    current = current->next;
  }

  cout << "BACKWARD:" << endl;
  current = last;
  while (current != 0) {
    current->data->print();
    current = current->prev;
  }
}
