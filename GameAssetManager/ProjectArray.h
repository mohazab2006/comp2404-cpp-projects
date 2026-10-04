#ifndef PROJECTARRAY_H
#define PROJECTARRAY_H

#include <string>
#include "defs.h"

class Project;

// Non-owning pointer container (mirrors AssetArray)
class ProjectArray {
  public:
    ProjectArray();
    ~ProjectArray();

    bool add(Project*);
    Project* get(int) const;
    Project* get(const std::string& name) const;
    Project* remove(const std::string& name);
    Project* remove(int);
    int size() const;
    bool isFull() const;

  private:
    int numProjects;
    Project** projects;
};

#endif