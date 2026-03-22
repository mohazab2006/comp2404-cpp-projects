#ifndef ASSETSTORE_H
#define ASSETSTORE_H

#include <iostream>
#include <string>

#include "AssetArray.h"

using namespace std;

// Control/Collection/View object for assets
class AssetStore {
  public:
    AssetStore();
    ~AssetStore();

    bool addAsset(const string& name, const string& description, const string& icon);
    void deleteAsset(int index);
    const Asset* getAsset(int index) const;

    void printAssets() const;
    void printAssetDetails(int index) const;

  private:
    void clearAssets();
    AssetArray assets; // AssetStore OWNS the Asset* pointers
};

#endif