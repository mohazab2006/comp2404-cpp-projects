#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

using namespace std;

class Entity {
public:
    Entity(char code, int num, const string& name);
    virtual ~Entity();

    const string& getId() const;
    const string& getName() const;
    virtual void print() const;

protected:
    string name;
    string id;
};

#endif