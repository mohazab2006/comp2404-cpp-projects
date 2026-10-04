#include "LabTech.h"

const char LabTech::code = 'T';
int LabTech::nextId = 1;

LabTech::LabTech(const string& name)
    : Entity(code, nextId++, name) {
}

void LabTech::addLabWork(LabWork* labWork) {
    processedLabWork.add(labWork);
}

void LabTech::print() const {
    Entity::print();
    cout << "Processed LabWork: " << processedLabWork.size() << endl;
}

void LabTech::printLabWork() const {
    print();
    processedLabWork.print();
}

void LabTech::resetId() {
    nextId = 1;
}