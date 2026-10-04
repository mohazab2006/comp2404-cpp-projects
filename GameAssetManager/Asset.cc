#include "Asset.h"

Asset::Asset(const string& name, const string& description, const string& icon)
  : name(name), description(description), icon(icon) {}

Asset::Asset(const Asset& other)
  : name(other.name), description(other.description), icon(other.icon) {}

Asset::~Asset() {}

const string& Asset::getName() const {
  return name;
}

void Asset::print() const {
  // Tests search for names; keep output stable.
  cout << "Name : " << name << endl;
  cout << "Description: " << description << endl;
}

void Asset::printWithIcon() const {
  print();
  cout << icon << endl;
}