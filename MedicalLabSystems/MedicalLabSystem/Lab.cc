#include "Lab.h"

Lab::Lab() {
}

Lab::~Lab() {
    for (unsigned int i = 0; i < patients.size(); ++i) {
        delete patients[i];
    }

    for (unsigned int i = 0; i < labTechs.size(); ++i) {
        delete labTechs[i];
    }
}

void Lab::addLabTech(const string& name) {
    labTechs.push_back(new LabTech(name));
}

void Lab::addPatient(const string& name, const string& medicalConditions) {
    patients.push_back(new Patient(name, medicalConditions));
}

void Lab::addLabWork(const string& patientId, LabWorkCode labWorkCode, double cost) {
    Patient* patient = getPatient(patientId);
    if (patient == nullptr) {
        cout << "Error: Patient " << patientId << " not found." << endl;
        return;
    }

    patient->addLabWork(new LabWork(labWorkCode, cost));
}

void Lab::processLabWork(const string& labTechId, const string& patientId) {
    LabTech* labTech = getLabTech(labTechId);
    if (labTech == nullptr) {
        cout << "Error: LabTech " << labTechId << " not found." << endl;
        return;
    }

    Patient* patient = getPatient(patientId);
    if (patient == nullptr) {
        cout << "Error: Patient " << patientId << " not found." << endl;
        return;
    }

    LabWork* patientLabWork = patient->processLabWork();
    if (patientLabWork == nullptr) {
        cout << "Error: Patient " << patientId << " has no pending LabWork." << endl;
        return;
    }

    patientLabWork->completeLabWork(labTechId);

    LabWork* techCopy = new LabWork(*patientLabWork);
    labTech->addLabWork(techCopy);
}

Patient* Lab::getPatient(const string& id) const {
    for (unsigned int i = 0; i < patients.size(); ++i) {
        if (patients[i]->getId() == id) {
            return patients[i];
        }
    }
    return nullptr;
}

LabTech* Lab::getLabTech(const string& id) const {
    for (unsigned int i = 0; i < labTechs.size(); ++i) {
        if (labTechs[i]->getId() == id) {
            return labTechs[i];
        }
    }
    return nullptr;
}

void Lab::printLabTechs() const {
    for (unsigned int i = 0; i < labTechs.size(); ++i) {
        labTechs[i]->print();
    }
}

void Lab::printPatients() const {
    for (unsigned int i = 0; i < patients.size(); ++i) {
        patients[i]->print();
    }
}

void Lab::printLabTechLabWork(const string& id) const {
    LabTech* labTech = getLabTech(id);
    if (labTech == nullptr) {
        cout << "Error: LabTech " << id << " not found." << endl;
        return;
    }

    labTech->printLabWork();
}

void Lab::printPatientPendingLabWork(const string& id) const {
    Patient* patient = getPatient(id);
    if (patient == nullptr) {
        cout << "Error: Patient " << id << " not found." << endl;
        return;
    }

    patient->printPendingLabWork();
}

void Lab::printPatientMedicalHistory(const string& id) const {
    Patient* patient = getPatient(id);
    if (patient == nullptr) {
        cout << "Error: Patient " << id << " not found." << endl;
        return;
    }

    patient->printMedicalHistory();
}

void Lab::resetIds() {
    Patient::resetId();
    LabTech::resetId();
}