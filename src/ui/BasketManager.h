#ifndef BASKET_MANAGER_H
#define BASKET_MANAGER_H

#include "../core/Store.h"
#include "ConsoleUI.h"

class BasketManager {
public:
    void runBasketManager(Store& store);

private:
    void showBasketManager(Store& store);

    void handleBasketManagerChoices(int choice, Store& store);

    void showProducts(Store& store);

    void addToBasket(Store& store);

    void removeFromBasket(Store& store);

    void showBasket(Store& store);

    void generateReceipt(Store& store);
};


#endif // BASKET_MANAGER_H
