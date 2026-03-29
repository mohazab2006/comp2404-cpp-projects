#ifndef SEARCHFACTORY_H
#define SEARCHFACTORY_H

#include <iostream>
#include <string>
#include "Search.h"
#include "Talk.h"

using namespace std;

class SearchFactory {
	public:
		Search* createSearch(const string& type, const string& param1, const string& param2 = "") const {
			if (type == "speaker") {
				return new S_Search(param1);
			} else if (type == "keyword") {
				return new K_Search(param1);
			} else if (type == "speaker or keyword") {
				return new SK_Search(param1, param2);
			}
			return 0;
		}
};

#endif