
#include "TestControl.h"


const vector<string> TestControl::menu ={
    "Print Patient test (4 marks)",
    "Print LabTech test (4 marks)",
    "Add LabWork test (10 marks)",
    "Process LabWork test (16 marks)",
    "Print Medical History test (10 marks)\n",
    "Test all and get mark (44 marks)\n"
};


void TestControl::launch(){
    //get input, launch the appropriate test
    int choice = -1;

    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1: printPatients(); break;
            case 2: printLabTechs(); break;
            case 3: generateLabWorkForPatient(); break;
            case 4: processLabWork(); break;
            case 5: printMedicalHistory(); break;
            case 6: int mark = 0;
                    mark += printPatients();
                    mark += printLabTechs();
                    mark += generateLabWorkForPatient();
                    mark += processLabWork();
                    mark += printMedicalHistory();
                    cout<<endl<<"Your mark is "<<mark<<"/44"<<endl;
                    break;
        }
    }
}

void TestControl::initLab(Lab& Lab){
    cout<<"Initializing Lab..."<<endl;
    Lab.resetIds();
    for (int i = 0; i < 3; i++){
        Lab.addLabTech(labTechs[i]);
    }
    for (int i = 0; i < 4; i++){
        Lab.addPatient(patients[i], medicalConditions[i]);
    }
  
}

int TestControl::printPatients(){
    cout<<"Testing printPatients..."<<endl;
    Lab Lab;
    initLab(Lab);
    tester.initCapture();
    Lab.printPatients();
    tester.endCapture();

    int error = 0;
    int mark = 0;
    tester.find(patients, error);
    if (error == 0){
        mark += 2;
        cout<<"Patient names found, 2 marks"<<endl;
    }else{
        cout<<"Patient names not found"<<endl;
    }

    tester.find(medicalConditions, error);
    if (error == 0){
        mark += 2;
        cout<<"Medical conditions found, 2 marks"<<endl;
    }else{
        cout<<"Medical conditions not found"<<endl;
    }


    if (mark == 4){
        cout<<"All Patient information found"<<endl;
    }
    cout<<"Tests complete, mark is "<<mark<<"/4"<<endl;

    return mark;
}

int TestControl::printLabTechs(){
    cout<<"Testing printLabTechs..."<<endl;
    Lab Lab;
    initLab(Lab);
    tester.initCapture();
    Lab.printLabTechs();
    tester.endCapture();

    int error = 0;
    int mark = 0;
    tester.find(labTechs, error);
    if (error == 0){
        mark += 4;
        cout<<"LabTech names found, 4 marks"<<endl;
    }else{
        cout<<"LabTech names not found"<<endl;
    }

    cout<<"Tests complete, mark is "<<mark<<"/4"<<endl;

    return mark;
}

int TestControl::findPatient(int index){
    int error = 0;
    int mark = 0;
    tester.find({index}, patients, error);
    if (error == 0){
        mark += 1;
        cout<<"Patient name found, 1 mark"<<endl;
    }else{
        cout<<"Patient name "<<patients[index]<<" not found"<<endl;
    }

    tester.find({index}, medicalConditions, error);
    if (error == 0){
        mark += 1;
        cout<<"Medical histories found, 1 mark"<<endl;
    }else{
        cout<<"Medical history "<<medicalConditions[index]<<" not found"<<endl;
    }

    return mark;
}

int TestControl::generateLabWorkForPatient(){
    cout<<"Testing addLabWork..."<<endl;
    Lab lab;
    initLab(lab);
    vector<LabWorkCode> LabWorkCodes = {ULTRASOUND, URINE_TEST, GENETIC_TEST, MRI};
    vector<string> patientIds = {"P1", "P3", "P3", "P1"};
    for (int i = 0; i < 4; i++){
        lab.addLabWork(patientIds[i], LabWorkCodes[i], costs[LabWorkCodes[i]]);
    }

    tester.initCapture();
    lab.printPatientPendingLabWork("P1");
    tester.endCapture();

    cout<<"Checking for Patient P1 information..."<<endl;

    int mark = findPatient(0);
    
    int error = 0;
    cout<<"Checking for P1 LabWork information..."<<endl;

    tester.find({5,3},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"LabWork found, 2 marks"<<endl;
    }else{
        cout<<"LabWork not found"<<endl;
    }

    // look for wrong LabWork
    tester.confirmAbsent({0,1,2,4,6,7,8,9},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"No wrong LabWork found, 2 marks"<<endl;
    }else{
        cout<<"Wrong LabWork found"<<endl;
    }

    cout<<"Checking P3 LabWork information"<<endl;
    tester.initCapture();
    lab.printPatientPendingLabWork("P3");
    tester.endCapture();

    tester.find({1,7},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"LabWork found, 2 marks"<<endl;
    }else{
        cout<<"LabWork not found"<<endl;
    }

    // look for wrong LabWork
    tester.confirmAbsent({0,2,3,4,5,6,8,9},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"No wrong LabWork found, 2 marks"<<endl;
    }else{
        cout<<"Wrong LabWork found"<<endl;
    }
    cout<<"Tests complete, mark is "<<mark<<"/10"<<endl;
    
    return mark;
}

int TestControl::printMedicalHistory(){
    cout<<"Testing printMedicalHistory..."<<endl;
    Lab lab;
    initLab(lab);
    vector<LabWorkCode> LabWorkCodes = {ULTRASOUND, URINE_TEST, GENETIC_TEST, MRI};
    vector<string> patientIds = {"P1", "P3", "P3", "P1"};
    for (int i = 0; i < 4; i++){
        lab.addLabWork(patientIds[i], LabWorkCodes[i], costs[LabWorkCodes[i]]);
    }
    tester.initCapture();
    lab.printPatientMedicalHistory("P3");
    tester.endCapture();

    int error = 0;
    int mark = 0;

    cout<<"Checking for P3 previous LabWork information (should be nothing)..."<<endl;


    // look for wrong LabWork
    tester.confirmAbsent({0,1,2,3,4,5,6,7,8,9},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"No LabWork found, 2 marks"<<endl;
    }else{
        cout<<"Error: LabWork found (but should be nothing)"<<endl;
    }
    
    cout<<"Processing P3 LabWork..."<<endl;
    lab.processLabWork("T2", "P3");
    tester.initCapture();
    lab.printPatientMedicalHistory("P3");
    tester.endCapture();

    cout<<"Checking for P3 previous LabWork information..."<<endl;
    tester.find({1},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"LabWork found, 2 marks"<<endl;
    }else{
        cout<<"LabWork not found"<<endl;
    }

    // look for wrong LabWork
    tester.confirmAbsent({0,2,3,4,5,6,7,8,9},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"No wrong LabWork found, 2 marks"<<endl;
    }else{
        cout<<"Wrong LabWork found"<<endl;
    }

    cout<<"Processing P3 LabWork again (second time should be nothing to process)..."<<endl;
    lab.processLabWork("T2", "P3");
    lab.processLabWork("T2", "P3");
    tester.initCapture();
    lab.printPatientMedicalHistory("P3");
    tester.endCapture();
    cout<<"Checking for P3 previous LabWork information..."<<endl;
    tester.find({1,7},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"LabWork found, 2 marks"<<endl;
    }else{
        cout<<"LabWork not found"<<endl;
    }

    // look for wrong LabWork
    tester.confirmAbsent({0,2,3,4,5,6,8,9},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"No wrong LabWork found, 2 marks"<<endl;
    }else{
        cout<<"Wrong LabWork found"<<endl;
    }
    cout<<"Tests complete, mark is "<<mark<<"/10"<<endl;

    return mark;
}

int TestControl::processLabWork(){
    cout<<"Testing makeLabWork..."<<endl;
    Lab lab;
    initLab(lab);
    vector<LabWorkCode> LabWorkCodes = {ULTRASOUND, URINE_TEST, GENETIC_TEST, MRI};
        //{5, 1, 7, 3};
    vector<string> patientIds = {"P1", "P3", "P3", "P1"};
    for (int i = 0; i < 4; i++){
        lab.addLabWork(patientIds[i], LabWorkCodes[i], costs[LabWorkCodes[i]]);
    }
    lab.processLabWork("T2", "P3");

    /*
    * We are going to be careful here. One LabWork should be moved from P3 to T2
    */

    tester.initCapture();
    lab.printLabTechLabWork("T2");
    tester.endCapture();

    int mark = 0;
    int error = 0;

    cout<<"Checking for LabTech T2 information..."<<endl;
    
    tester.find({1}, labTechs, error);
    if (error == 0){
        mark += 2;
        cout<<"LabTech name found, 2 marks"<<endl;
    }else{
        cout<<"LabTech name not found"<<endl;
    }

    cout<<"Checking for T2 LabWork information..."<<endl;

    tester.find({1},LabWork::LABTESTS, error);

    if (error == 0){
        mark += 2;
        cout<<"LabWork found, 2 marks"<<endl;
    }else{
        cout<<"LabWork not found"<<endl;
    }

    // look for wrong LabWork
    tester.confirmAbsent({0,2,3,4,5,6,7,8,9},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"No wrong LabWork found, 2 marks"<<endl;
    }else{
        cout<<"Wrong LabWork found"<<endl;
    }

    cout<<"Checking P3 LabWork information"<<endl;
    tester.initCapture();
    lab.printPatientPendingLabWork("P3");
    tester.endCapture();

    tester.find({7},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"Patient LabWork found, 2 marks"<<endl;
    }else{
        cout<<"Patient LabWork not found"<<endl;
    }

    // look for wrong LabWork
    tester.confirmAbsent({0,1,2,3,4,5,6,8,9},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"No wrong LabWork found, 2 marks"<<endl;
    }else{
        cout<<"Wrong LabWork found"<<endl;
    }

    cout<<"Processing P1 three times (only two LabWork available)"<<endl;
    lab.processLabWork("T1", "P1");
    lab.processLabWork("T1", "P1");
    lab.processLabWork("T1", "P1");

    tester.initCapture();
    lab.printLabTechLabWork("T1");
    tester.endCapture();

    cout<<"Checking for T1 processed LabWork information..."<<endl;

    tester.find({5,3},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"LabWork found, 2 marks"<<endl;
    }else{
        cout<<"LabWork not found"<<endl;
    }

    // look for wrong LabWork
    tester.confirmAbsent({0,1,2,4,6,7,8,9},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"No wrong LabWork found, 2 marks"<<endl;
    }else{
        cout<<"Wrong LabWork found"<<endl;
    }

    cout<<"Checking P1 LabWork information"<<endl;
    tester.initCapture();
    lab.printPatientPendingLabWork("P1");
    tester.endCapture();

    tester.confirmAbsent({0,1,2,3,4,5,6,7,8,9},LabWork::LABTESTS, error);
    if (error == 0){
        mark += 2;
        cout<<"No wrong LabWork found, 2 marks"<<endl;
    }else{
        cout<<"Wrong LabWork found"<<endl;
    }
    

    cout<<"Tests complete, mark is "<<mark<<"/16"<<endl;
    return mark;

}


vector<string> TestControl::labTechs = {
    "Splinter",
    "Donatello",
    "Leonardo"
};

vector<string> TestControl::patients = {
    "Michelangelo",
    "Raphael",
    "Beebop",
    "Rocksteady"
};

vector<string> TestControl::medicalConditions = {
    "Diabetes",
    "High Blood Pressure",
    "Asthma",
    "Healthy"
};



const double TestControl::costs[10] = {
    10.00,
    20.00,
    30.00,
    40.00,
    50.00,
    60.00,
    70.00,
    80.00,
    90.00,
    100.00
};
