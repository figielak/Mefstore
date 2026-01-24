#include "ShowProducts.h"

void ShowProducts::showProducts(Store& store){
    int choice = -1;

    do {
        showProductsMenu(store);
        cin >> choice;
        system("CLS");
        system("clear");
        handleProductsMenuChoices(choice, store);
    } while (choice != 0);
}

void ShowProducts::showProductsMenu(Store& store){
    cout << "\n+=== Wybierz opcje ===+\n";
    cout << "[1] Sortowanie po id\n";
    cout << "[2] Sortowanie po nazwie\n";
    cout << "[3] Wybierz kategorie\n";
    cout << "[4] Pokaż wszystkie produkty\n";
    cout << "[0] Wroc do menu\n";
    cout << "+=====================+\n";
}

void ShowProducts::handleProductsMenuChoices(int choice, Store& store){
    switch (choice){
        case 1: showProductsById(store); break;
        case 2: showProductsByName(store); break;
        case 3: showProductsByCategory(store); break;
        case 4: showAllProducts(store); break;
        case 0: break;
        default: cout << "Nieprawidłowy wybór\n";
    }
}

// Wyświetlenie produktów posortowanych po ID
void ShowProducts::showProductsById(Store& store){
    system("CLS");
    system("clear");
    cout << "\n+====== Produkty ======+\n";
    for (Product& product : store.getProducts()){
        cout << "[" << product.getId() << "] " << product.getName() << " - " << product.getPrice() << " PLN" << endl;
    }
    cout << "+=====================+\n";
}

// Wyświetlenie produktów posortowanych po nazwie
void ShowProducts::showProductsByName(Store& store){
    // TODO: Dodaj sortowanie po nazwie
    return;
}

// Wyświetlenie produktów danej kategorii
void ShowProducts::showProductsByCategory(Store& store){
    // TODO: Dodaj wybór kategorii
    return;
}
