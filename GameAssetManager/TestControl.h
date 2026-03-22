#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include "AssetStore.h"
#include <random>
#include <unordered_set>
#include <sstream>
#include "ProjectManager.h"
#include "Project.h"
#include "View.h"
#include "Tester.h"

using namespace std;

class TestControl {

	public:
		void launch();

	private:
		void initAssets(AssetStore& am);
		int testPrintAssets();
		int testPrintAssetDetails();
		int testDeleteAsset();

		void initProjects(ProjectManager& dm);
		int testPrintProjects();
		int testPrintProjectDetails();
		int testDeleteProject();

		int testAddAssetToProject();
		int testCloneProject();

		View view;
		Tester tester;
};

#endif