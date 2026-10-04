#ifndef ASSET_H
#define ASSET_H

#include <iostream>
#include <string>

using namespace std;

// Entity object representing a downloadable asset (art, models, etc.)
class Asset {
  public:
    Asset(const string& name, const string& description, const string& icon);
    Asset(const Asset& other);
    ~Asset();

    const string& getName() const;

    void print() const;
    void printWithIcon() const;

  private:
    string name;
    string description;
    string icon;
};

#endif