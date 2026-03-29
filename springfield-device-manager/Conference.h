#ifndef CONFERENCE_H
#define CONFERENCE_H

#include <iostream>
#include <string>
#include "List.h"
#include "Talk.h"

using namespace std;

class Conference {
    public:
        Conference(const string& name, const string& description);
        ~Conference();

        bool operator==(const string& rhs) const;

        Talk* getTalk(int index) const;
        int getSize() const;
        const string& getName() const;

        void print(ostream& ost) const;
        void printWithTalks(ostream& ost) const;
        void add(Talk* talk);

    private:
        List<Talk*> talks;
        string name;
        string description;
};

ostream& operator<<(ostream& ost, const Conference& conference);

#endif