#include "LabWork.h"

const string LabWork::LABTESTS[NUM_LABTESTS] = {
    "Blood Test",
    "Urine Test",
    "X-Ray",
    "MRI",
    "CT Scan",
    "Ultrasound",
    "Biopsy",
    "Genetic Test",
    "Allergy Test",
    "COVID-19 Test"
};

const string LabWork::NOTCOMPLETE = "not complete";

LabWork::LabWork(LabWorkCode labWorkCode, double cost)
    : labWorkCode(labWorkCode), cost(cost), labTechId(NOTCOMPLETE) {
}

bool LabWork::isComplete() const {
    return labTechId != NOTCOMPLETE;
}

void LabWork::completeLabWork(const string& labTechId) {
    this->labTechId = labTechId;
}

void LabWork::print() const {
    cout << "LabWork:" << endl;
    cout << "  Test: " << LABTESTS[labWorkCode] << endl;
    cout << "  Cost: " << cost << endl;
    cout << "  Completed By: " << labTechId << endl;
}