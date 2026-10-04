#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include "AssetStore.h"
#include <random>
#include <unordered_set>
#include <sstream>
#include "ProjectManager.h"
#include "View.h"

using namespace std;

class Control {
		
	public:
		void launch();
	
	private:
		void initAssets();
		void initProjects();
		void printAssets();
		void printProjects();
		void printAssetDetails();
		void printProjectDetails();
		void addAssetsToProject();
		void deleteAsset();
		void deleteProject();
		void cloneProject();
		

		View view;

		AssetStore assetStore;
		ProjectManager projectManager;
	
};
#endif