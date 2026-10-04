
#ifndef ASSETARRAY_H
#define ASSETARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Asset.h"
#include "defs.h"

using namespace std;

class AssetArray {
		
	public:
		//constructor
		AssetArray();
		
		//destructor
		~AssetArray();
		
		//other
		bool add(Asset*);
		Asset* get(int) const;
		Asset* get(const string&) const;
		Asset* remove(const string& name);
		Asset* remove(int);
		int size() const;
		bool isFull() const;
	
	private:
		int numAssets;
		Asset** assets;
};
#endif
