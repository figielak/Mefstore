#include "../core/Store.h"
#include "StoreManager.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void StoreManager::runStoreManager(Store& store) {
    int choice = -1;

    do {
        showStoreManager(store);
        cin >> choice;
        system("CLS");
        system("clear");
        handleStoreManagerChoices(choice, store);
    } while (choice != 0);
}

void StoreManager::showStoreManager(Store& store){
    cout << "\n+=== Mefstore ===+\n";
    cout << "[1] Wyświetl produkty \n";
    cout << "[2] Dodaj produkt \n";
    cout << "[3] Edytuj produkt \n";
    cout << "[4] Usuń produkt \n";
    cout << "[0] Wroc do menu \n";
    cout << "+=====================+\n";
}

void StoreManager::handleStoreManagerChoices(int choice, Store& store){
    switch (choice){
        case 1: showProducts(store); break;
        case 2: addProduct(store); break;
        case 3: editProduct(store); break;
        case 4: removeProduct(store); break;
        case 0: cout << "Do zobaczenia!\n"; break;
        default: cout << "Nieprawidłowy wybór\n";
    }
}

void StoreManager::addProduct(Store& store){
    return;
}

void StoreManager::editProduct(Store& store){
    return;
}

void StoreManager::removeProduct(Store& store){
    return;
}

///////////////////////////////////////////
/// PRODUCTS MENU
///////////////////////////////////////////
void StoreManager::showProducts(Store& store){
    int choice = -1;

    do {
        showProductsMenu(store);
        cin >> choice;
        system("CLS");
        system("clear");
        handleProductsMenuChoices(choice, store);
    } while (choice != 0);
}

void StoreManager::showProductsMenu(Store& store){
    cout << "\n+=== Wybierz opcje ===+\n";
    cout << "[1] Sortowanie po id\n";
    cout << "[2] Sortowanie po nazwie\n";
    cout << "[3] Wybierz kategorie\n";
    cout << "[0] Wroc do menu\n";
    cout << "+=====================+\n";
}

void StoreManager::handleProductsMenuChoices(int choice, Store& store){
    switch (choice){
        case 1: showProductsById(store); break;
        case 2: showProductsByName(store); break;
        case 3: showProductsByCategory(store); break;
        case 0: break;
        default: cout << "Nieprawidłowy wybór\n";
    }
}

void StoreManager::showProductsById(Store& store){
    system("CLS");
    system("clear");
    cout << "\n+====== Produkty ======+\n";
    for (Product& product : store.getProducts()){
        cout << "[" << product.getId() << "] " << product.getName() << " \n";
    }
    cout << "+=====================+\n";
}

void StoreManager::showProductsByName(Store& store){
    return;
}

void StoreManager::showProductsByCategory(Store& store){
    return;
}
