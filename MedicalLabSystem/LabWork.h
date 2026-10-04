#ifndef LABWORK_H
#define LABWORK_H

#include <iostream>
#include <string>

using namespace std;

enum LabWorkCode {
    BLOOD_TEST, URINE_TEST, XRAY, MRI, CT_SCAN,
    ULTRASOUND, BIOPSY, GENETIC_TEST,
    ALLERGY_TEST, COVID19_TEST, NUM_LABTESTS
};

class LabWork {
public:
    LabWork(LabWorkCode labWorkCode, double cost);

    bool isComplete() const;
    void completeLabWork(const string& labTechId);
    void print() const;

    static const string LABTESTS[NUM_LABTESTS];
    static const string NOTCOMPLETE;

private:
    LabWorkCode labWorkCode;
    double cost;
    string labTechId;
};

#endif