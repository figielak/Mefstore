#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include <vector>
#include <string>

using namespace std;

class Store  {
private:
    vector<Product> products;

public:
    Store();

    vector<Product> getProducts();

    void addProduct(const Product& product);

    void removeProduct(const string& name);

    void editProduct(const string& name);

    void loadProducts(string filename);

};

#endif //STORE_H
