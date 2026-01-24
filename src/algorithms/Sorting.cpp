#include "Sorting.h"

void Sorting::bubbleSortByNameAZ(vector<Product>& products) {
    for (int i = 0; i < products.size(); i++) {
        for (int j = 0; j < products.size() - 1; j++) {
            if (products[j].getName() > products[j + 1].getName()) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void Sorting::bubbleSortByNameZA(vector<Product>& products) {
    for (int i = 0; i < products.size(); i++) {
        for (int j = 0; j < products.size() - 1; j++) {
            if (products[j].getName() < products[j + 1].getName()) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}
