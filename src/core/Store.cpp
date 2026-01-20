#include "Store.h"
#include <iostream>

using namespace std;

Store::Store(){
    // Kilka przykładowych produktów (do testów)
    products.push_back(Product(1, "Chleb", 3.0, "Produkty"));
    products.push_back(Product(2, "Mleko", 2.0, "Mleczne"));
    products.push_back(Product(3, "Jajka", 5.0, "Produkty"));
    products.push_back(Product(4, "Jabłko", 2.0, "Owoce"));
}

vector<Product> Store::getProducts(){
    return products;
}
