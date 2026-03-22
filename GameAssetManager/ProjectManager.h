#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <iostream>
#include <string>

#include "ProjectArray.h"

using namespace std;

// Control/Collection/View object for projects
class ProjectManager {
  public:
    ProjectManager();
    ~ProjectManager();

    bool addProject(const string& name, const string& description, const string& type);
    void deleteProject(int index);
    void cloneProject(int cloneTo, int cloneFrom);

    Project* getProject(int index) const;

    void printProjects() const;
    void printProjectDetails(int index) const;

  private:
    void clearProjects();
    ProjectArray projects; // ProjectManager OWNS Project* pointers
};

#endif