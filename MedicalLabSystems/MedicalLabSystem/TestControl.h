#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include <vector>

#include "Lab.h"
#include "View.h"
#include "Tester.h"

using namespace std;


class TestControl
{
  public:
    
    void launch();
    

  private:
    int printPatients();
    int printLabTechs();
    int generateLabWorkForPatient();
    int processLabWork();
    int printMedicalHistory();

    //helper function
    void initLab(Lab& Lab);
    int findPatient(int);


    View view;
    Tester tester;

    const static vector<string> menu;

    // LabTech and Patient information
    static vector<string> labTechs;
    
    static vector<string> patients;
    static vector<string> medicalConditions;

    // LabWork information
    const static double costs[10];


    
};

#endif
