
#include "AssetArray.h"

AssetArray::AssetArray(){
	numAssets = 0;
	assets = new Asset*[MAX_ARRAY];
}


AssetArray::~AssetArray(){
	delete [] assets;
}


bool AssetArray::add(Asset* s){
	if (isFull()) return false;
	assets[numAssets++] = s;
	return true;
}

Asset* AssetArray::remove(const string& name){
	int index = 0;

	while (index < numAssets){
		if (assets[index]->getName() == name){ break; }
		++index;
	}

	if (index >= numAssets) return NULL;

	Asset* goner;
	goner = assets[index];

	while (index < numAssets-1){
		assets[index] = assets[index+1];
		++index;
	}
	--numAssets;
	return goner;
}

Asset* AssetArray::remove(int i){
	if (i < 0 || i >= numAssets) return nullptr;
	Asset* goner = assets[i];

	while (i < numAssets-1){
		assets[i] = assets[i+1];
		++i;
	}
	--numAssets;
	return goner;
}

Asset* AssetArray::get(const string& name) const{
	for (int i = 0; i < numAssets; ++i){
		if (assets[i]->getName() == name){
			return assets[i];
		}
	}
	return NULL;
}

Asset* AssetArray::get(int i) const {
	if (i < 0 || i >= numAssets) return nullptr;
	return assets[i];
}

bool AssetArray::isFull() const{
	return numAssets >= MAX_ARRAY;
}

int AssetArray::size() const{
	return numAssets;
}
