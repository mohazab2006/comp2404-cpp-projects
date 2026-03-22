#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include "Entity.h"
#include "LabWorkList.h"

using namespace std;

class Patient : public Entity {
public:
    Patient(const string& name, const string& medicalConditions);

    void addLabWork(LabWork* labWork);
    LabWork* processLabWork();
    bool hasPendingLabWork() const;

    void print() const;
    void printMedicalHistory() const;
    void printPendingLabWork() const;

    static void resetId();

private:
    static const char code;
    static int nextId;

    string medicalConditions;
    LabWorkList pendingLabWork;
    LabWorkList processedLabWork;
};

#endif