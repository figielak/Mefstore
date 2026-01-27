#ifndef BASKET_MANAGER_H
#define BASKET_MANAGER_H

#include "../core/Store.h"
#include "../core/Basket.h"
#include "../core/Product.h"
#include "ConsoleUI.h"
#include "ShowProducts.h"
#include <iostream>

using namespace std;

class BasketManager {
public:
    void runBasketManager(Store& store);
    Basket basket;

private:
    void showBasketManager(Store& store);

    void handleBasketManagerChoices(int choice, Store& store);

    void showBasket(Store& store);

    void generateReceipt(Store& store);

    void addToBasket(Store& store);

    void removeFromBasket(Store& store);
};


#endif // BASKET_MANAGER_H
