#include "LabWorkList.h"

LabWorkList::Node::Node(LabWork* data, Node* next)
    : data(data), next(next) {
}

LabWorkList::LabWorkList()
    : head(nullptr), tail(nullptr) {
}

LabWorkList::~LabWorkList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr->data;
        delete curr;
        curr = nextNode;
    }
}

void LabWorkList::add(LabWork* labWork) {
    if (labWork == nullptr) {
        return;
    }

    Node* node = new Node(labWork);

    if (tail == nullptr) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

LabWork* LabWorkList::getNext() {
    if (head == nullptr) {
        return nullptr;
    }

    Node* oldHead = head;
    LabWork* nextLabWork = oldHead->data;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }

    delete oldHead;
    return nextLabWork;
}

bool LabWorkList::isEmpty() const {
    return head == nullptr;
}

int LabWorkList::size() const {
    int count = 0;
    Node* curr = head;
    while (curr != nullptr) {
        ++count;
        curr = curr->next;
    }
    return count;
}

void LabWorkList::print() const {
    if (head == nullptr) {
        cout << "No LabWork." << endl;
        return;
    }

    Node* curr = head;
    while (curr != nullptr) {
        curr->data->print();
        curr = curr->next;
    }
}