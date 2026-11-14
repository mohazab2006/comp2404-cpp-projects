#include "PartArray.h"
#include "Participant.h"

PartArray::PartArray()
  : size(0)
{
  for (int i = 0; i < MAX_ARR; i++) elements[i] = NULL;
}

void PartArray::add(Participant* p)
{
  if (p == NULL || size >= MAX_ARR) {
    cerr << "Cannot add participant to array" << endl;
    return;
  }
  elements[size] = p;
  size++;
}

Participant* PartArray::get(int index)
{
  if (index < 0 || index >= size) return NULL;
  return elements[index];
}

int PartArray::getSize()
{
  return size;
}
