#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

struct Product {
    int id;
    string name;
    double price;
    string category;

    Product(int id, string name, double price, string category)
        : id(id), name(name), price(price), category(category) {}

    string getName() const {return name;}
    int getId() const {return id;}
};

#endif //PRODUCT_H
