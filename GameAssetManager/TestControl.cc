
#include "TestControl.h"
#include "ProjectManager.h"
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;
#define NUM_PROJECTS 4
#define NUM_TYPE 5
extern const  string DESCRIPTION[NUM_PROJECTS];
extern const  string TYPE[NUM_TYPE];
extern const string projectNames[5];
extern int description[5];
extern int type[5];
extern const string assetNames[10];
extern const string descriptions[10];
extern const string icons[10];



void TestControl::launch(){

    vector<string> menu ={
        "Test print assets",
        "Test print asset details",
        "Test delete asset",
        "Test print projects",
        "Test print project assets",
        "Test delete project",
        "Test add asset to project", 
        "Test clone project",
        "Test all and get mark"
    };

    int choice = -1;

    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1: testPrintAssets(); break;
            case 2: testPrintAssetDetails(); break;
            case 3: testDeleteAsset(); break;
            case 4: testPrintProjects(); break;
            case 5: testPrintProjectDetails(); break;
            case 6: testDeleteProject(); break;
            case 7: testAddAssetToProject(); break;
            case 8: testCloneProject(); break;
            case 9: int mark = testPrintAssets();
                    mark+= testPrintAssetDetails();
                    mark+= testDeleteAsset();
                    mark+= testPrintProjects();
                    mark+= testPrintProjectDetails();
                    mark+= testDeleteProject();
                    mark+= testAddAssetToProject();
                    mark+= testCloneProject();
                    cout<<"Total mark: "<<mark<<"/18"<<endl;
                    break;
        }
    }
    cout<<"exiting program!!!"<<endl;
}

void TestControl::initAssets(AssetStore& am){
    cout<<"Initializing assets..."<<endl;
    for (int i = 0; i < 10; ++i){
        am.addAsset(assetNames[i], descriptions[i], icons[i]);
    }
    cout<<"Assets initialized!"<<endl;
}

void TestControl::initProjects(ProjectManager& dm){
    cout<<"Initializing projects..."<<endl;
    for (int i = 0; i < 5; ++i){
        dm.addProject(projectNames[i], DESCRIPTION[description[i]], TYPE[type[i]]);
    }
    cout<<"Projects initialized!"<<endl;
}

int TestControl::testPrintAssets(){
    cout<<"1. Test print assets"<<endl;
    AssetStore am;
    cout<<"Initializing asset market"<<endl;
    initAssets(am);
    cout<<"Printing assets..."<<endl;
    tester.initCapture();
    am.printAssets();
    tester.endCapture();
    vector<int> keys = {0,1,2,3,4,5,6,7,8,9};
    int error = 0;
    tester.find(keys, assetNames, error);
    if (error>0 && error <10){
        cout<<error<<" names not found, test failed, 1/2 marks"<<endl;
        return 1;
    }else if (error >= 10){
        cout<<"No asset names found, test failed, 0/2 marks"<<endl;
        return 0;
    }
    cout<<"All asset names found, test passed, 2 marks"<<endl;
    return 2;
}

int TestControl::testPrintAssetDetails(){
    cout<<"2. Test print asset details"<<endl;
    AssetStore am;
    cout<<"Initializing asset market"<<endl;
    initAssets(am);
    cout<<"Printing selected assets..."<<endl;
    vector<int> keys;
    tester.ran(keys, 4, 10);
    tester.initCapture();
    for (int i: keys){
        am.printAssetDetails(i);
    }
    tester.endCapture();
    
    int error = 0;
    int marks = 2;
    tester.findInOrder(keys, assetNames, error);
    if (error>0){
        cout<<"Some names our of order, -1"<<endl;
        --marks;
    }
    cout<<"All asset names found in order, test passed"<<endl;
    cout<<"Searching for icons"<<endl;
    error = 0;
    tester.findInOrder(keys, icons, error);
    if (error>0){
        cout<<"Some icons out of order, -1"<<endl;
        --marks;
    }
    cout<<"All icons found in order, test passed"<<endl;
    cout<<"Mark: "<<marks<<"/2"<<endl;
    return marks;
}
		
int TestControl::testDeleteAsset(){
    cout<<"3. Test delete asset"<<endl;
    AssetStore am;
    cout<<"Initializing asset market"<<endl;
    initAssets(am);
    cout<<"Printing assets..."<<endl;
    tester.initCapture();
    am.printAssets();
    tester.endCapture();
    vector<int> keys = {0,1,2,3,4,5,6,7,8,9};
    int error = 0;
    tester.find(keys, assetNames, error);
    if (error>0){
        cout<<error<<" names not found, test aborted"<<endl;
        return 0;
    }
    vector<int> todelete;
    tester.ran(todelete, 4, 10);
    // sort todelete
    sort(todelete.begin(), todelete.end());
    int count = 0;
    for (int i: todelete){
        am.deleteAsset(i-count);
        for (int j = 0; j < keys.size(); ++j){
            if (keys[j] == i){
                keys.erase(keys.begin()+j);
                break;
            }
        }
        ++count;
    }
    cout<<"Printing assets after delete..."<<endl;
    tester.initCapture();
    am.printAssets();
    tester.endCapture();
    error = 0;
    tester.find(keys, assetNames, error);
    if (error>0){
        cout<<error<<" names not found, test failed"<<endl;
        return 0;
    }
    error = 0;
    tester.find(todelete, assetNames, error);
    if (error!=todelete.size()){
        cout<<"Deleted assets found, test failed"<<endl;
        return 0;
    }
    cout<<"Delete asset test successful, 2 marks"<<endl;
    return 2;
}


int TestControl::testPrintProjects(){
    cout<<"4. Test print projects"<<endl;
    ProjectManager dm;
    cout<<"Initializing project manager"<<endl;
    initProjects(dm);
    cout<<"Printing projects..."<<endl;
    tester.initCapture();
    dm.printProjects();
    tester.endCapture();
    vector<int> keys = {0,1,2,3,4};
    int error = 0;
    tester.find(keys, projectNames, error);
    if (error>0 && error <5){
        cout<<error<<" project names not found, test failed, 1/2 marks"<<endl;
        return 1;
    }else if (error >= 10){
        cout<<"No project names found, test failed, 0/2 marks"<<endl;
        return 0;
    }
    cout<<"All project names found, test passed, 2 marks"<<endl;
    return 2;
}


// half marks here, half marks after we test loading assets
int TestControl::testPrintProjectDetails(){
    cout<<"5. Test print project details"<<endl;
    ProjectManager dm;
    cout<<"Initializing project manager"<<endl;
    initProjects(dm);
    cout<<"Printing selected projects..."<<endl;
    vector<int> keys;
    tester.ran(keys, 4, 5);
    tester.initCapture();
    for (int i: keys){
        cout<<"Testing project "<<i<<endl;
        dm.printProjectDetails(i);
    }
    tester.endCapture();
    
    int error = 0;
    tester.findInOrder(keys, projectNames, error);
    if (error>0){
        cout<<"Some names not found or out of order, test failed"<<endl;
        return 0;
    }
    cout<<"All project names found in order, test passed, 2 marks"<<endl;
    return 2;
}

int TestControl::testDeleteProject(){
    cout<<"6. Test delete project"<<endl;
    ProjectManager dm;
    cout<<"Initializing project manager"<<endl;
    initProjects(dm);
    cout<<"Printing projects..."<<endl;
    tester.initCapture();
    dm.printProjects();
    tester.endCapture();
    vector<int> keys = {0,1,2,3,4};
    int error = 0;
    tester.find(keys, projectNames, error);
    if (error>0){
        cout<<error<<" project names not found, test aborted"<<endl;
        return 0;
    }
    vector<int> todelete;
    tester.ran(todelete, 2, 5);
    // sort todelete
    sort(todelete.begin(), todelete.end());
    cout<<"Deleting: "<<endl;
    for (int i: todelete){
        cout<<projectNames[i]<<" "<<i<<endl;
    }  
    int count = 0;
    for (int i: todelete){
        dm.deleteProject(i-count);
        for (int j = 0; j < keys.size(); ++j){
            if (keys[j] == i){
                keys.erase(keys.begin()+j);
                break;
            }
        }
        ++count;
    }
     
    cout<<"Printing projects after delete..."<<endl;
    tester.initCapture();
    dm.printProjects();
    tester.endCapture();
    error = 0;
    tester.find(keys, projectNames, error);
    if (error>0){
        cout<<error<<" project names not found, test failed"<<endl;
        return 0;
    }
    error = 0;
    tester.find(todelete, projectNames, error);
    if (error!=todelete.size()){
        cout<<"Deleted projects found, test failed"<<endl;
        return 0;
    }
    cout<<"Delete project test successful, 2 marks"<<endl;
    return 2;
}

int TestControl::testAddAssetToProject(){
    cout<<"7. Test add asset to project"<<endl;
    AssetStore am;
    cout<<"Initializing asset market"<<endl;
    initAssets(am);
    ProjectManager dm;
    cout<<"Initializing project manager"<<endl;
    initProjects(dm);
    vector<int> assetKeys1;
    vector<int> assetKeys2;
    vector<int> projectKeys;
    tester.ran(assetKeys1, 4, 10);
    tester.ran(assetKeys2, 4, 10);
    tester.ran(projectKeys, 2, 5);
    cout<<"Adding assets to projects"<<endl;
    Project* d1 = dm.getProject(projectKeys[0]);
    Project* d2 = dm.getProject(projectKeys[1]);
    for (int i: assetKeys1){
        // dm.downloadToProject(projectKeys[0], i, am);
        const Asset* a = am.getAsset(i);
        d1->addAsset(*a);
    }
    for (int i: assetKeys2){
        // dm.downloadToProject(projectKeys[1], i, am);
        const Asset* a = am.getAsset(i);
        d2->addAsset(*a);
    }
    cout<<"Printing project details"<<endl;
    tester.initCapture();
    dm.printProjectDetails(projectKeys[0]);
    tester.endCapture();
    int error = 0;
    tester.findInOrder(assetKeys1, assetNames, error);
    if (error>0){
        cout<<"Some assets not found, test failed"<<endl;
        return 0;
    }
    tester.initCapture();
    dm.printProjectDetails(projectKeys[1]);
    tester.endCapture();
    error = 0;
    tester.findInOrder(assetKeys2, assetNames, error);
    if (error>0){
        cout<<"Some assets not found, test failed"<<endl;
        return 0;
    }
    cout<<"All assets found, test passed, 2 marks"<<endl;
    return 2;
}
		
int TestControl::testCloneProject(){
    cout<<"8. Test clone project"<<endl;
    AssetStore am;
    cout<<"Initializing asset market"<<endl;
    initAssets(am);
    ProjectManager dm;
    cout<<"Initializing project manager"<<endl;
    initProjects(dm);
    vector<int> assetKeys;
    vector<int> projectKeys;
    tester.ran(projectKeys, 2, 5);
    sort(projectKeys.begin(), projectKeys.end()); 
    tester.ran(assetKeys, 4, 10);
    cout<<"Adding assets to project"<<endl;
    Project* d1 = dm.getProject(projectKeys[0]);
    for (int i: assetKeys){
        //dm.downloadToProject(projectKeys[0], i, am);
        const Asset* a = am.getAsset(i);
        d1->addAsset(*a);
    }
    cout<<"Printing original project details"<<endl;
    dm.printProjectDetails(projectKeys[0]);
    cout<<"Cloning above project to "<<projectNames[projectKeys[1]]<<endl;
    tester.pressEnterToContinue();
    tester.pressEnterToContinue(); 
    dm.cloneProject(projectKeys[1], projectKeys[0]);
    cout<<"Printing clone project details"<<endl;
    tester.initCapture();
    dm.printProjectDetails(projectKeys[1]);
    tester.endCapture();
    int error = 0;
    tester.findInOrder(assetKeys, assetNames, error);
    if (error>0){
        cout<<"Some assets not found, test failed"<<endl;
        return 0;
    }
    cout<<"All assets found, test passed"<<endl;
    cout<<"Deleting original project (did you do a deep copy of the assets?)"<<endl;
    tester.pressEnterToContinue();
    dm.deleteProject(projectKeys[0]);
    cout<<"Printing clone project details"<<endl;
    tester.initCapture();
    dm.printProjectDetails(projectKeys[1]-1);
    tester.endCapture();
    error = 0;
    tester.findInOrder(assetKeys, assetNames, error);
    if (error>0){
        cout<<"Some assets not found, test failed"<<endl;
        return 2;
    }
    cout<<"All assets found, test passed, 2 marks"<<endl;
    return 4;
}

#define NUM_PROJECTS 4
#define NUM_TYPE 5

const  string DESCRIPTION[NUM_PROJECTS]={"My attempt at 3D", "Aliens invading Earth", "Work in progress", "RPG perhaps?"};
const  string TYPE[NUM_TYPE] = {"Generic 3D", "Generic 2D", "FPS", "Platformer", "Rogue-like"};

const string projectNames[5] = {"My 3D Game", "Alien Attack", "Learning To Make Games", "Paladin!", "Dog Catcher Simulator"};
int description[5] = {0, 1, 3, 2, 2};
int type[5] = {0, 1, 2, 3, 4};

const string assetNames[10] = {"Cat", "Dog", "Car", "Truck", "Rocket", "Airplane", "Fish", "Bird", "House", "Phone"};
const string descriptions[10] = {"A cute cat asset", "A friendly dog asset", "A fast car asset", "A big truck asset", "A powerful rocket asset", "A sleek airplane asset", "A colorful fish asset", "A chirpy bird asset", "A cozy house asset", "A smart phone asset"};

const string icons[10] = {

R"(
 /\_/\
( o.o )
 > ^ <
)",

R"(
 /^ ^\
/ 0 0 \
V\ Y /V
 / - \
 |    \
 || (__V
)",

R"(
  ______
 //  ||\ \
_____||_\___
 )  _  \
 |_/ \_________|
___\_/_________/
)",

R"(
 ___________
|  _ _ _   |
| | | | |  |
|_|_|_|_|__|
   O     O
)",

R"(
    /\
   /  \
   |  |
   |  |
  /____\
    ||
    ||
)",

R"(
     __|__
--o--(_)--o--
)",

R"(
   ><(((('>
)",

R"(
  \\
 (o>
 //\
 V_/_
)",

R"(
   /\
  /  \
 /____\
 | [] |
 |____|
)",

R"(
  ______
 |  __ |
 | |__||
 |______|
   |  | 
)" 
};