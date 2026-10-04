#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class List {

	public:
		// constructor
		List();

		// destructor
		~List();

		// operators / methods
		List<T>& operator+=(const T&);
		List<T>& operator-=(const T&);
		T& operator[](int index);
		const T& operator[](int index) const;
		int getSize() const;
		bool isFull() const;
		void clear();

	private:
		int numElements;
		T* elements;
};

template <class T>
List<T>::List() {
	elements = new T[MAX_ARRAY];
	numElements = 0;
}

template <class T>
List<T>::~List() {
	delete [] elements;
}

template <class T>
List<T>& List<T>::operator+=(const T& t) {
	if (numElements < MAX_ARRAY) {
		elements[numElements++] = t;
	}
	return *this;
}

template <class T>
List<T>& List<T>::operator-=(const T& t) {
	int index = 0;

	while (index < numElements) {
		if (elements[index] == t) {
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements) {
		elements[index] = elements[index + 1];
		++index;
	}

	return *this;
}

template <class T>
T& List<T>::operator[](int index) {
	if (index < 0 || index >= numElements) {
		cerr << "List index out of bounds" << endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
const T& List<T>::operator[](int index) const {
	if (index < 0 || index >= numElements) {
		cerr << "List index out of bounds" << endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
int List<T>::getSize() const {
	return numElements;
}

template <class T>
bool List<T>::isFull() const {
	return numElements >= MAX_ARRAY;
}

template <class T>
void List<T>::clear() {
	numElements = 0;
}

#endif