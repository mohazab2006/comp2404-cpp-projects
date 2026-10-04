#include "Conference.h"
#include <cstdlib>

Conference::Conference(const string& name, const string& description)
    : name(name), description(description) {
}

Conference::~Conference() {
    for (int i = 0; i < talks.getSize(); ++i) {
        delete talks[i];
    }
}

bool Conference::operator==(const string& rhs) const {
    return name == rhs;
}

Talk* Conference::getTalk(int index) const {
    if (index < 0 || index >= talks.getSize()) {
        cerr << "Conference talk index out of bounds" << endl;
        exit(1);
    }
    return talks[index];
}

int Conference::getSize() const {
    return talks.getSize();
}

const string& Conference::getName() const {
    return name;
}

void Conference::print(ostream& ost) const {
    ost << "Conference: " << name << endl;
    ost << "Description: " << description << endl;
}

void Conference::printWithTalks(ostream& ost) const {
    print(ost);
    for (int i = 0; i < talks.getSize(); ++i) {
        ost << endl;
        ost << *(talks[i]);
    }
}

void Conference::add(Talk* talk) {
    talks += talk;
}

ostream& operator<<(ostream& ost, const Conference& conference) {
    conference.print(ost);
    return ost;
}