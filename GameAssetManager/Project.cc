#include "Project.h"

Project::Project(const string& name, const string& description, const string& type)
  : name(name), description(description), type(type) {}

Project::Project(const Project& other)
  : name(other.name), description(other.description), type(other.type) {
  for (int i = 0; i < other.assets.size(); ++i) {
    const Asset* a = other.assets.get(i);
    if (a) assets.add(new Asset(*a));
  }
}

Project& Project::operator=(const Project& other) {
  if (this == &other) return *this;

  name = other.name;
  description = other.description;
  type = other.type;

  cloneAssetsFrom(other);
  return *this;
}

Project::~Project() {
  clearAssets();
}

const string& Project::getName() const {
  return name;
}

void Project::clearAssets() {
  while (assets.size() > 0) {
    Asset* a = assets.remove(0);
    delete a;
  }
}

bool Project::addAsset(const Asset& asset) {
  if (assets.isFull()) return false;
  Asset* copy = new Asset(asset);     // deep copy
  return assets.add(copy);
}

bool Project::deleteAsset(const string& assetName) {
  Asset* removed = assets.remove(assetName);
  if (!removed) return false;
  delete removed;
  return true;
}

int Project::numAssets() const {
  return assets.size();
}

void Project::cloneAssetsFrom(const Project& project) {
  clearAssets();
  for (int i = 0; i < project.assets.size(); ++i) {
    const Asset* a = project.assets.get(i);
    if (a) assets.add(new Asset(*a)); // deep copy
  }
}

void Project::print() const {
  cout << "Name: " << name << endl;
  cout << "Project Type: " << description << endl;
  cout << "TYPE: " << type << endl;
  cout << "Assets: " << numAssets() << endl;
}

void Project::printAssets() const {
  print();
  cout << "Assets:" << endl;
  for (int i = 0; i < assets.size(); ++i) {
    const Asset* a = assets.get(i);
    if (a) a->printWithIcon();
  }
}