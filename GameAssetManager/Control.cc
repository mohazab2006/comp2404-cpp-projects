#include "Control.h"
#include "ProjectManager.h"
#include "Project.h"
#include <limits>
#include <vector>

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

void Control::launch(){

    vector<string> menu ={
        "Print assets",
        "Print projects",
        "Print project assets",
        "Add assets to project",
        "Delete asset",
        "Delete project",
        "Clone project"
    };

    initAssets();
    initProjects();
    int choice = -1;

    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1: printAssets(); break;
            case 2: printProjects(); break;
            case 3: printProjectDetails(); break;
            case 4: addAssetsToProject(); break;
            case 5: deleteAsset(); break;
            case 6: deleteProject(); break;
            case 7: cloneProject(); break;
        }
    }
    cout<<"exiting program!!!"<<endl;
}

void Control::initAssets(){
    cout<<"Initializing assets..."<<endl;
    for (int i = 0; i < 10; ++i){
        assetStore.addAsset(assetNames[i], descriptions[i], icons[i]);
    }
    cout<<"Assets initialized!"<<endl;
}

void Control::initProjects(){
    cout<<"Initializing projects..."<<endl;
    for (int i = 0; i < 5; ++i){
        projectManager.addProject(projectNames[i], DESCRIPTION[description[i]], TYPE[type[i]]);
    }
    cout<<"Projects initialized!"<<endl;
}

void Control::printAssets(){
    cout<<"Printing assets..."<<endl;
    assetStore.printAssets();
    cout<<"Assets printed!"<<endl;
}

void Control::printProjects(){
    cout<<"Printing projects..."<<endl;
    projectManager.printProjects();
    cout<<"Projects printed!"<<endl;
}

void Control::printAssetDetails(){
    printAssets();
    int index;
    view.getNumber(index);
    cout<<"Printing asset details..."<<endl;
    assetStore.printAssetDetails(index);
}

void Control::printProjectDetails(){
    printProjects();
    int index;
    view.getNumber(index);
    cout << "Printing project details..." << endl;
    projectManager.printProjectDetails(index);
}

void Control::addAssetsToProject(){
    cout << "Choose project to install on:" << endl;
    printProjects();
    int pIndex;
    view.getNumber(pIndex);
    Project* p = projectManager.getProject(pIndex);
    if (!p) {
        cout << "Error: Project does not exist" << endl;
        return;
    }

    cout << "How many assets are you installing?" << endl;
    int n;
    view.getNumber(n);
    printAssets();

    for (int i = 0; i < n; ++i) {
        int aIndex;
        view.getNumber(aIndex);
        const Asset* a = assetStore.getAsset(aIndex);
        if (!a) {
            cout << "Error: Asset does not exist" << endl;
            continue;
        }
        cout << "Adding asset to project..." << endl;
        p->addAsset(*a);
    }
}

void Control::deleteAsset(){
    printAssets();
    int index;
    view.getNumber(index);
    cout << "Deleting asset..." << endl;
    assetStore.deleteAsset(index);
}

void Control::deleteProject(){
    printProjects();
    int index;
    view.getNumber(index);
    cout << "Deleting project..." << endl;
    projectManager.deleteProject(index);
}

void Control::cloneProject(){
    cout << "Printing projects..." << endl;
    projectManager.printProjects();

    cout << "Enter index of project to clone from: ";
    int fromIndex;
    view.getNumber(fromIndex);

    cout << "Printing projects..." << endl;
    projectManager.printProjects();

    cout << "Enter index of project to clone to: ";
    int toIndex;
    view.getNumber(toIndex);

    projectManager.cloneProject(toIndex, fromIndex);
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