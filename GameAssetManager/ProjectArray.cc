#include "ProjectArray.h"
#include "Project.h"

ProjectArray::ProjectArray() {
  numProjects = 0;
  projects = new Project*[MAX_ARRAY];
}

ProjectArray::~ProjectArray() {
  // Non-owning: do not delete elements
  delete [] projects;
}

bool ProjectArray::add(Project* p) {
  if (isFull()) return false;
  projects[numProjects++] = p;
  return true;
}

Project* ProjectArray::get(int i) const {
  if (i < 0 || i >= numProjects) return nullptr;
  return projects[i];
}

Project* ProjectArray::get(const std::string& name) const {
  for (int i = 0; i < numProjects; ++i) {
    if (projects[i]->getName() == name) return projects[i];
  }
  return nullptr;
}

Project* ProjectArray::remove(const std::string& name) {
  int index = 0;
  while (index < numProjects) {
    if (projects[index]->getName() == name) break;
    ++index;
  }
  if (index >= numProjects) return nullptr;

  Project* goner = projects[index];
  while (index < numProjects - 1) {
    projects[index] = projects[index + 1];
    ++index;
  }
  --numProjects;
  return goner;
}

Project* ProjectArray::remove(int i) {
  if (i < 0 || i >= numProjects) return nullptr;

  Project* goner = projects[i];
  while (i < numProjects - 1) {
    projects[i] = projects[i + 1];
    ++i;
  }
  --numProjects;
  return goner;
}

int ProjectArray::size() const {
  return numProjects;
}

bool ProjectArray::isFull() const {
  return numProjects >= MAX_ARRAY;
}