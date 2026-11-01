#include "SubArray.h"

SubArray::SubArray()
{
  size = 0;
}

SubArray::~SubArray()
{
  for (int i = 0; i < size; ++i) {
    delete elements[i];
  }
}

int SubArray::getSize()
{
  return size;
}

Subscriber* SubArray::get(int index)
{
  if (index < 0 || index >= size)
    return 0;

  return elements[index];
}

void SubArray::add(Subscriber* sub)
{
  if (sub == 0 || size >= MAX_ARR_SIZE)
    return;

  elements[size] = sub;
  ++size;
}
