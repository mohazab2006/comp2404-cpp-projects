#include "AssetStore.h"
#include "Asset.h"

AssetStore::AssetStore() {}

AssetStore::~AssetStore() {
  clearAssets();
}

void AssetStore::clearAssets() {
  while (assets.size() > 0) {
    Asset* a = assets.remove(0);
    delete a;
  }
}

bool AssetStore::addAsset(const string& name, const string& description, const string& icon) {
  if (assets.isFull()) {
    cout << "Error: AssetStore full" << endl;
    return false;
  }
  Asset* a = new Asset(name, description, icon);
  if (!assets.add(a)) {
    delete a;
    cout << "Error: could not add asset" << endl;
    return false;
  }
  cout << "Asset " << name << " added" << endl; // tests ignore
  return true;
}

void AssetStore::deleteAsset(int index) {
  Asset* removed = assets.remove(index);
  if (!removed) {
    cout << "Error: Asset does not exist" << endl;
    return;
  }
  cout << "Asset " << removed->getName() << " deleted" << endl;
  delete removed;
}

const Asset* AssetStore::getAsset(int index) const {
  return assets.get(index);
}

void AssetStore::printAssets() const {
  cout << "Assets:" << endl;
  for (int i = 0; i < assets.size(); ++i) {
    cout << i << ":" << endl;
    const Asset* a = assets.get(i);
    if (a) a->print();
  }
}

void AssetStore::printAssetDetails(int index) const {
  const Asset* a = assets.get(index);
  if (!a) {
    cout << "Error: Asset does not exist" << endl;
    return;
  }
  a->printWithIcon();
}