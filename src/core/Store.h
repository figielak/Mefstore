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

    vector<Product>& getProducts();

    vector<string> getCategories();

    void saveProducts(string filename, vector<Product> products);

    void addProduct(string filename, string product_name, double product_price, string product_category);

    bool removeProduct(string filename, string searchValue);

    void editProduct(string filename, string searchValue, string new_name, double new_price, string new_category);

    void loadProducts(string filename);


};

#endif //STORE_H
