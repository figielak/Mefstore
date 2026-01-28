#include "Basket.h"

vector<Product> Basket::getBasket(){
    return products;
}

void Basket::addProduct(Product product){
    products.push_back(product);
}

void Basket::removeProduct(Product product){
    // TODO: Usuwanie produktu z koszyka
    return;
}
