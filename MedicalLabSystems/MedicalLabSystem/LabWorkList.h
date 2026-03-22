#ifndef LABWORKLIST_H
#define LABWORKLIST_H

#include <iostream>
#include "LabWork.h"

using namespace std;

class LabWorkList {
public:
    LabWorkList();
    ~LabWorkList();

    void add(LabWork* labWork);
    LabWork* getNext();
    bool isEmpty() const;
    int size() const;
    void print() const;

private:
    class Node {
    public:
        Node(LabWork* data, Node* next = nullptr);
        LabWork* data;
        Node* next;
    };

    Node* head;
    Node* tail;
};

#endif