#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <string>

#include "AssetArray.h"
#include "Asset.h"

using namespace std;

// Entity object representing a game project.
class Project {
  public:
    Project(const string& name, const string& description, const string& type);
    Project(const Project& other);
    Project& operator=(const Project& other);
    ~Project();

    const string& getName() const;

    bool addAsset(const Asset& asset);
    bool deleteAsset(const string& name);
    int numAssets() const;

    void cloneAssetsFrom(const Project& project);

    void print() const;
    void printAssets() const;

  private:
    void clearAssets();

    string name;
    string description;
    string type;
    AssetArray assets; // Project OWNS the Asset* stored in this array
};

#endif