#ifndef STORE_MANAGER_H
#define STORE_MANAGER_H

#include "../core/Store.h"
#include "ShowProducts.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class StoreManager {
public:
    void runStoreManager(Store& store);

private:
    void showStoreManager(Store& store);

    void handleStoreManagerChoices(int choice, Store& store);

    void addProduct(Store& store);

    void editProduct(Store& store);

    void removeProduct(Store& store);
};

#endif // STORE_MANAGER_H
