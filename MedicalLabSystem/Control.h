
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include <random>
#include <unordered_set>
#include <sstream>
#include "Lab.h"
#include "View.h"
#include "Tester.h"

using namespace std;

class Control {
		
	public:
		
		void launch();

	
	private:
		void initLab();

		void printLabTechs();
		void printPatients();

		void printPatientLabWork();
		void printLabTechLabWork();

		void printPatientMedicalHistory();

		void assessPatient();
		void assignLabTech();
		
		
		Lab lab;
		View view;
		Tester tester;

		static const vector<string> menu;

};
#endif