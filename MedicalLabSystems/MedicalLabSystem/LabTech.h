#ifndef LABTECH_H
#define LABTECH_H

#include <iostream>
#include <string>
#include "Entity.h"
#include "LabWorkList.h"

using namespace std;

class LabTech : public Entity {
public:
    LabTech(const string& name);

    void addLabWork(LabWork* labWork);
    void print() const;
    void printLabWork() const;

    static void resetId();

private:
    static const char code;
    static int nextId;

    LabWorkList processedLabWork;
};

#endif