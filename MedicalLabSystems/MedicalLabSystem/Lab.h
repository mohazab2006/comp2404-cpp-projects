#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <vector>
#include "Patient.h"
#include "LabTech.h"
#include "LabWork.h"

using namespace std;

class Lab {
public:
    Lab();
    ~Lab();

    void addLabTech(const string& name);
    void addPatient(const string& name, const string& medicalConditions);

    void addLabWork(const string& patientId, LabWorkCode labWorkCode, double cost);
    void processLabWork(const string& labTechId, const string& patientId);

    Patient* getPatient(const string& id) const;
    LabTech* getLabTech(const string& id) const;

    void printLabTechs() const;
    void printPatients() const;
    void printLabTechLabWork(const string& id) const;
    void printPatientPendingLabWork(const string& id) const;
    void printPatientMedicalHistory(const string& id) const;

    void resetIds();

private:
    vector<Patient*> patients;
    vector<LabTech*> labTechs;
};

#endif