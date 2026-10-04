#include "Entity.h"

Entity::Entity(char code, int num, const string& name)
    : name(name), id(string(1, code) + to_string(num)) {
}

Entity::~Entity() {
}

const string& Entity::getId() const {
    return id;
}

const string& Entity::getName() const {
    return name;
}

void Entity::print() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
}