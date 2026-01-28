#include "Basket.h"
#include "../algorithms/searching.h"

vector<Product> Basket::getBasket(){
    return products;
}

void Basket::addProduct(string product_input, const vector<Product>& storeProducts){
    // Wyszukiwanie najbliższego produktu na podstawie wprowadzonej nazwy
    // i dodanie go do koszyka
    Product closestProduct = Search::searchProducts(storeProducts, product_input);
    products.push_back(closestProduct);
}

void Basket::removeProduct(string product_input){
    // Wyszukiwanie najbliższego produktu na podstawie wprowadzonej nazwy
    Product closestProduct = Search::searchProducts(products, product_input);
    
    // Usuwanie produktu z koszyka na podstawie ID
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].getId() == closestProduct.getId()) {
            products.erase(products.begin() + i);
            return;
        }
    }
}

void Basket::editProduct(string oldProduct_input, string newProduct_input, const vector<Product>& storeProducts){
    // Wyszukiwanie starego produktu w koszyku
    Product oldProduct = Search::searchProducts(products, oldProduct_input);
    // Wyszukiwanie nowego produktu w sklepie
    Product newProduct = Search::searchProducts(storeProducts, newProduct_input);
    
    // Edycja produktu w koszyku
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].getId() == oldProduct.getId()) {
            products[i] = newProduct;
            return;
        }
    }
}
