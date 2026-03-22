#include "Patient.h"

const char Patient::code = 'P';
int Patient::nextId = 1;

Patient::Patient(const string& name, const string& medicalConditions)
    : Entity(code, nextId++, name), medicalConditions(medicalConditions) {
}

void Patient::addLabWork(LabWork* labWork) {
    pendingLabWork.add(labWork);
}

LabWork* Patient::processLabWork() {
    LabWork* nextLabWork = pendingLabWork.getNext();
    if (nextLabWork == nullptr) {
        return nullptr;
    }

    processedLabWork.add(nextLabWork);
    return nextLabWork;
}

bool Patient::hasPendingLabWork() const {
    return !pendingLabWork.isEmpty();
}

void Patient::print() const {
    Entity::print();
    cout << "Medical Conditions: " << medicalConditions << endl;
    cout << "Pending LabWork: " << pendingLabWork.size() << endl;
    cout << "Medical History: " << processedLabWork.size() << endl;
}

void Patient::printMedicalHistory() const {
    print();
    processedLabWork.print();
}

void Patient::printPendingLabWork() const {
    print();
    pendingLabWork.print();
}

void Patient::resetId() {
    nextId = 1;
}