#include "BasketManager.h"

void BasketManager::runBasketManager(Store& store) {
    int choice = -1;

    do {
        showBasketManager(store);
        cin >> choice;
        cout << "\033[2J\033[H";
        handleBasketManagerChoices(choice, store);
    } while (choice != 0);
}

void BasketManager::showBasketManager(Store& store){
    cout << "╔══════════════════════════════════════╗\n"
         << "║             OPCJE KOSZYKA            ║\n"
         << "╠══════════════════════════════════════╣\n";
    cout << "║[1] Wyświetl produkty                 ║\n";
    cout << "║[2] Dodaj produkt do koszyka          ║\n";
    cout << "║[3] Usuń produkt z koszyka            ║\n";
    cout << "║[4] Wyświetl koszyk                   ║\n";
    cout << "║[5] Generuj paragon                   ║\n";
    cout << "║[0] Wroc do menu                      ║\n";
    cout << "╚══════════════════════════════════════╝\n";
}

void BasketManager::handleBasketManagerChoices(int choice, Store& store){
    ShowProducts showProducts;

    switch (choice){
        case 1: showProducts.showProducts(store); break;
        case 2: addToBasket(store); break;
        case 3: removeFromBasket(store); break;
        case 4: showBasket(store); break;
        case 5: generateReceipt(store); break;
        case 0: break;
        default: cout << "Nieprawidłowy wybór\n";
    }
}

void BasketManager::showBasket(Store& store){
    double total = 0;
    cout << "╔══════════════════════════════════════╗\n"
         << "║             TWÓJ KOSZYK              ║\n"
         << "╠══════════════════════════════════════╝\n";
    for (const Product& p : basket.getBasket()) {
        cout << "║ " << p.getName() << " - " << p.getPrice() << " PLN\n";
        total += p.getPrice();
    }
    cout << "╠═══════════════════════════════════════\n";
    cout << "║ Suma: " << total << " PLN\n";
    cout << "╚═══════════════════════════════════════\n";
    return;
}

void BasketManager::generateReceipt(Store& store){
    // TODO: Generowanie paragonu
    return;
}

void BasketManager::addToBasket(Store& store){
    // TODO: Dodawanie produktu do koszyka
    return;
}

void BasketManager::removeFromBasket(Store& store){
    // TODO: Usuwanie produktu z koszyka
    return;
}

void BasketManager::editBasket(Store& store){

    return;
}
