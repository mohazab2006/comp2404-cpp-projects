
#include <iostream>
#include <string>
#include <vector>
#include "Control.h"


const vector<string> Control::menu ={
    "Print LabTechs",
    "Print Patients",
    "Print Patient LabWork to complete",
    "Print LabTech LabWork completed",
    "Print Patient Medical History",
    "Assess Patient (generate LabWork for a Patient)",
    "Assign LabTech to Patient (process LabWork for a Patient)"
};

// void initLab();

// void printLabTechs();
// void printPatients();

// void inspectVehicle();
// void updateLabTechs();

void Control::launch(){
    //make a view, get input, launch the appropriate test
    View view;
    int choice = -1;

    initLab();

    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1: printLabTechs(); break;
            case 2: printPatients(); break;
            case 3: printPatientLabWork(); break;
            case 4: printLabTechLabWork(); break;
            case 5: printPatientMedicalHistory(); break;
            case 6: assessPatient(); break;
            case 7: assignLabTech(); break;
        }
    }
}

void Control::initLab(){
    cout<<"Initializing Lab..."<<endl;
    lab.addLabTech("Splinter");
    lab.addLabTech("Donatello");
    lab.addLabTech("Leonardo");
    lab.addPatient("Michelangelo", "Diabetes");
    lab.addPatient("Raphael", "High Blood Pressure");
    lab.addPatient("Beebop", "Asthma");
    lab.addPatient("Rocksteady", "Healthy");

   
}

void Control::printLabTechs(){
    cout<<"Printing LabTechs..."<<endl;
    lab.printLabTechs();
}

void Control::printPatients(){
    cout<<"Printing Patients..."<<endl;
    lab.printPatients();
}

void Control::printPatientLabWork(){
    cout<<"Choose Patient to print LabWork for: "<<endl;
    printPatients();
    string patientId;
    view.getId('P', patientId);
    cout<<"ID: "<<patientId<<endl;
    lab.printPatientPendingLabWork(patientId);
}

void Control::printPatientMedicalHistory(){
    cout<<"Choose Patient to print medical history for: "<<endl;
    printPatients();
    string patientId;
    view.getId('P', patientId);
    cout<<"ID: "<<patientId<<endl;
    lab.printPatientMedicalHistory(patientId);
}

void Control::printLabTechLabWork(){
    cout<<"Choose LabTech to print LabWork for: "<<endl;
    printLabTechs();
    string labTechId;
    view.getId('T', labTechId);
    lab.printLabTechLabWork(labTechId);
}


/* This generates some random LabWork 
   and adds them to a Patient
*/
void Control::assessPatient(){
    cout<<"Choose Patient to assess: "<<endl;
    printPatients();
    string patientId;
    view.getId('P', patientId);
    Patient* patient = lab.getPatient(patientId);
    if (patient == nullptr){
        cout<<"Patient "<<patientId<<" not found"<<endl;
        return;
    }

    int numLabWork = tester.ran(1,5);
    vector<int> LabWork;
    tester.ran(LabWork, numLabWork, 9);
    for (int r: LabWork){
        lab.addLabWork(patientId, static_cast<LabWorkCode>(r), tester.ran(25, 150));
    }
}

void Control::assignLabTech(){
    cout<<"Please choose a LabTech to analyze LabWork:"<<endl;
    lab.printLabTechs();
    string labTechId;
    view.getId('T', labTechId);
    LabTech* labTech = lab.getLabTech(labTechId);
    if (labTech == nullptr){
        cout<<"LabTech "<<labTechId<<" not found"<<endl;
        return;
    }
    cout<<"Please choose a Patient whose LabWork should be analyzed:"<<endl;
    lab.printPatients();
    string patientId;
    view.getId('P', patientId);
    Patient* patient = lab.getPatient(patientId);
    if (patient == nullptr){
        cout<<"Patient "<<patientId<<" not found"<<endl;
        return;
    }
    while(patient->hasPendingLabWork()){
        lab.processLabWork(labTechId, patientId);
    }   
}


