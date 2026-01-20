#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "../core/Store.h"
#include "../core/Product.h"
#include <string>
#include <iostream>

using namespace std;

class ConsoleUI {
public:
    void run(Store& store);

private:
    void showMenu();
    void handleMenuChoices(int choice, Store& store);

    void showProducts(Store& store);
    void addProduct(Store& store);
    void editProduct(Store& store);
    void removeProduct(Store& store);
};

#endif // CONSOLE_UI_H
