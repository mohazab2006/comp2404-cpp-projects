#include "ProjectManager.h"
#include "Project.h"

ProjectManager::ProjectManager() {}

ProjectManager::~ProjectManager() {
  clearProjects();
}

void ProjectManager::clearProjects() {
  while (projects.size() > 0) {
    Project* p = projects.remove(0);
    delete p;
  }
}

bool ProjectManager::addProject(const string& name, const string& description, const string& type) {
  if (projects.isFull()) {
    cout << "Error: ProjectManager full" << endl;
    return false;
  }
  Project* p = new Project(name, description, type);
  if (!projects.add(p)) {
    delete p;
    cout << "Error: could not add project" << endl;
    return false;
  }
  cout << "Project " << name << " added" << endl; // tests ignore
  return true;
}

void ProjectManager::deleteProject(int index) {
  Project* removed = projects.remove(index);
  if (!removed) {
    cout << "Error: Project does not exist" << endl;
    return;
  }
  cout << "Project " << removed->getName() << " deleted" << endl;
  delete removed;
}

void ProjectManager::cloneProject(int cloneTo, int cloneFrom) {
  Project* to = projects.get(cloneTo);
  Project* from = projects.get(cloneFrom);
  if (!to || !from) {
    cout << "Error: Project does not exist" << endl;
    return;
  }
  cout << "Cloning project..." << endl;
  cout << "Cloning assets" << endl;
  to->cloneAssetsFrom(*from);
  cout << "Project " << to->getName() << " cloned" << endl;
}

Project* ProjectManager::getProject(int index) const {
  return projects.get(index);
}

void ProjectManager::printProjects() const {
  cout << "Projects:" << endl;
  for (int i = 0; i < projects.size(); ++i) {
    cout << i << ":" << endl;
    Project* p = projects.get(i);
    if (p) p->print();
  }
}

void ProjectManager::printProjectDetails(int index) const {
  Project* p = projects.get(index);
  if (!p) {
    cout << "Error: Project does not exist" << endl;
    return;
  }
  p->printAssets();
}