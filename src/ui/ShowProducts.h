#ifndef SHOW_PRODUCTS_H
#define SHOW_PRODUCTS_H

#include "../core/Store.h"
#include <iostream>

using namespace std;

class ShowProducts {
public:
    void showProducts(Store& store);

private:
    void showAllProducts(Store& store);
    
    void showProductsMenu(Store& store);

    void handleProductsMenuChoices(int choice, Store& store);

    void showProductsById(Store& store);

    void showProductsByName(Store& store);

    void showProductsByCategory(Store& store);
};

#endif // SHOW_PRODUCTS_H
