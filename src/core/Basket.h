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

    void addProduct(Product product);

    void removeProduct(Product product);
};

#endif //BASKET_H
