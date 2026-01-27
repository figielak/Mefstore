#include "StoreManager.h"

void StoreManager::runStoreManager(Store& store) {
    int choice = -1;

    do {
        showStoreManager(store);
        cin >> choice;
        cout << "\033[2J\033[H";
        handleStoreManagerChoices(choice, store);
    } while (choice != 0);
}

void StoreManager::showStoreManager(Store& store){
    cout << "╔══════════════════════════════════════════╗\n"
         << "║                 MEFSTORE                 ║\n"
         << "╠══════════════════════════════════════════╣\n";
    cout << "║[1] Wyświetl produkty                     ║\n";
    cout << "║[2] Dodaj produkt                         ║\n";
    cout << "║[3] Edytuj produkt                        ║\n";
    cout << "║[4] Usuń produkt                          ║\n";
    cout << "║[0] Wroc do menu                          ║\n";
    cout << "╚══════════════════════════════════════════╝\n";
}

void StoreManager::handleStoreManagerChoices(int choice, Store& store){
    ShowProducts showProducts;

    switch (choice){
        case 1: showProducts.showProducts(store); break;
        case 2: addProduct(store); break;
        case 3: editProduct(store); break;
        case 4: removeProduct(store); break;
        case 0: break;
        default: cout << "Nieprawidłowy wybór\n";
    }
}

void StoreManager::addProduct(Store& store){
    string name;
    string category;
    double price = 0.0;
    cout << "╔══════════════════════════════════════════╗\n"
         << "║            DODAWANIE PRODUKTU            ║\n"
         << "╠══════════════════════════════════════════╝\n";
    cout << "║Podaj nazwę produktu: ";
    cin >> name;
    cout << "║Podaj cenę produktu: ";
    cin >> price;
    cout << "║Podaj kategorię produktu: ";
    cin >> category;
    cout << "╚═══════════════════════════════════════════\n";

    store.addProduct("products.csv", name, price, category);
}

void StoreManager::editProduct(Store& store){
    string searchValue;
    string new_name;
    string new_category;
    double new_price = 0.0;
    cout << "╔══════════════════════════════════════════╗\n"
         << "║            EDYCJA PRODUKTU               ║\n"
         << "╠══════════════════════════════════════════╝\n";
    cout << "║Podaj ID lub nazwę produktu: ";
    cin >> searchValue;
    cout << "║Podaj nową nazwę produktu: ";
    cin >> new_name;
    cout << "║Podaj nową cenę produktu: ";
    cin >> new_price;
    cout << "║Podaj nową kategorię produktu: ";
    cin >> new_category;
    cout << "╚═══════════════════════════════════════════\n";
    store.editProduct("products.csv", searchValue, new_name, new_price, new_category);
}

void StoreManager::removeProduct(Store& store){
    string searchValue;

    cout << "╔══════════════════════════════════════════╗\n"
         << "║            USUWANIE PRODUKTU             ║\n"
         << "╠══════════════════════════════════════════╝\n";
    cout << "║Podaj ID lub nazwę produktu: ";
    cin >> searchValue;
    cout << "╚═══════════════════════════════════════════\n";

    store.removeProduct("products.csv", searchValue);
}
