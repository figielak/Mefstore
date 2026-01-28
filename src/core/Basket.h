#ifndef BASKET_H
#define BASKET_H

#include "Product.h"
#include <vector>

using namespace std;

struct Basket {
private:
    vector<Product> products;
public:
    vector<Product> getBasket();

    void addProduct(string product_input, const vector<Product>& storeProducts);

    void removeProduct(string product_input);

    void editProduct(string oldProduct_input, string newProduct_input, const vector<Product>& storeProducts);
};

#endif //BASKET_H
