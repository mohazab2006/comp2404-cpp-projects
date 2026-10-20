#include "MsgArray.h"

MsgArray::MsgArray()
{
  size = 0;
}

MsgArray::MsgArray(MsgArray& other)
{
  size = 0;
  add(other);
}

MsgArray::~MsgArray()
{
}

int MsgArray::getSize()
{
  return size;
}

Msg* MsgArray::get(int index)
{
  if (index < 0 || index >= size)
    return 0;

  return elements[index];
}

bool MsgArray::add(Msg* msg)
{
  if (msg == 0 || size >= MAX_ARR_SIZE)
    return false;

  int position = 0;
  while (position < size && !msg->greaterThan(elements[position]))
    ++position;

  for (int i = size; i > position; --i)
    elements[i] = elements[i - 1];

  elements[position] = msg;
  ++size;
  return true;
}

bool MsgArray::add(MsgArray& other)
{
  int numberToAdd = other.getSize();
  if (numberToAdd > MAX_ARR_SIZE - size)
    return false;

  if (&other == this) {
    MsgArray original(other);
    return add(original);
  }

  for (int i = 0; i < numberToAdd; ++i) {
    if (!add(other.get(i)))
      return false;
  }

  return true;
}

void MsgArray::cleanup()
{
  for (int i = 0; i < size; ++i) {
    delete elements[i];
    elements[i] = 0;
  }
  size = 0;
}

void MsgArray::print()
{
  if (size == 0) {
    cout << "No messages" << endl;
    return;
  }

  for (int i = 0; i < size; ++i)
    elements[i]->print();
}
