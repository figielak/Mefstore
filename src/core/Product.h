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

    // Getters
    string getName() const {return name;}
    int getId() const {return id;}
    double getPrice() const {return price;}
    string getCategory() const {return category;}

    // Setters
    void setName(const string& newName) { name = newName; }
    void setPrice(double newPrice) { price = newPrice; }
    void setCategory(const string& newCategory) { category = newCategory; }
};

#endif //PRODUCT_H
