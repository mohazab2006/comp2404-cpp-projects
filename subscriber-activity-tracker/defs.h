#ifndef DEFS_H
#define DEFS_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX_ARR_SIZE    256
#define SUBSCRIBER_ID  2001

typedef enum { C_SENDER, C_RECEIVER } SubscriberType;

void selectionSort(int, int[], int[]);

#endif

