#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "../core/Store.h"
#include "../core/Product.h"
#include "StoreManager.h"
#include "BasketManager.h"

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class ConsoleUI {
public:
    void run(Store& store);

private:
    void showMenu();

    void handleMenuChoices(int choice, Store& store);
};

#endif // CONSOLE_UI_H
