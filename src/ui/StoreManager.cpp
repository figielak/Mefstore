#include "StoreManager.h"

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
    
    return;
}

void StoreManager::editProduct(Store& store){
    // TODO: Edytowanie produktu (gdy Mati skończy funkcje)
    return;
}

void StoreManager::removeProduct(Store& store){
    // TODO: Usuwanie produktu (gdy Mati skończy funkcje)
    return;
}
