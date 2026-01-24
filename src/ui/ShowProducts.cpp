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
    cout << "[1] Wyświetl wszystkie produkty\n";
    cout << "[2] Sortowanie po nazwie A-Z\n";
    cout << "[3] Sortowanie po nazwie Z-A\n";
    cout << "[4] Wybierz kategorie\n";
    cout << "[0] Wroc do menu\n";
    cout << "+=====================+\n";
}

void ShowProducts::handleProductsMenuChoices(int choice, Store& store){
    switch (choice){
        case 1: showAllProducts(store); break;
        case 2: showProductsByNameAZ(store); break;
        case 3: showProductsByNameZA(store); break;
        case 4: showProductsByCategory(store); break;
        case 0: break;
        default: cout << "Nieprawidłowy wybór\n";
    }
}

// Wyświetlenie wszystkich produktów
void ShowProducts::showAllProducts(Store& store){
    system("CLS");
    system("clear");
    cout << "\n+====== Produkty ======+\n";
    for (Product& product : store.getProducts()){
        cout << "[" << product.getId() << "] " << product.getName() << " - " << product.getPrice() << " PLN" << endl;
    }
    cout << "+=====================+\n";
}

// Wyświetlenie produktów posortowanych po nazwie A-Z
void ShowProducts::showProductsByNameAZ(Store& store){
    system("CLS");
    system("clear");
    cout << "\n+====== Produkty ======+\n";
    Sorting::bubbleSortByNameAZ(store.getProducts());
    for (Product& product : store.getProducts()){
        cout << "[" << product.getId() << "] " << product.getName() << " - " << product.getPrice() << " PLN" << endl;
    }
    cout << "+=====================+\n";
    return;
}

// Wyświetlenie produktów posortowanych po nazwie Z-A
void ShowProducts::showProductsByNameZA(Store& store){
    system("CLS");
    system("clear");
    cout << "\n+====== Produkty ======+\n";
    Sorting::bubbleSortByNameZA(store.getProducts());
    for (Product& product : store.getProducts()){
        cout << "[" << product.getId() << "] " << product.getName() << " - " << product.getPrice() << " PLN" << endl;
    }
    cout << "+=====================+\n";
    return;
}

// Wyświetlenie produktów danej kategorii
void ShowProducts::showProductsByCategory(Store& store){
    int choice = -1;

    do {
        cout << "\n+====== Wybierz kategorię ======+\n";
        for (int i = 0; i < store.getCategories().size(); i++){
            cout << "[" << i + 1 << "] " << store.getCategories()[i] << endl;
        }
        cout << "[0] Wróć do menu głównego\n";
        cout << "+=====================+\n";

        cin >> choice;
        system("CLS");
        system("clear");

        if (choice < 1 || choice > store.getCategories().size()) {
            cout << "Nieprawidłowy wybór\n";
            continue;
        }

        cout << "\n+====== Produkty ======+\n";
        for (Product& product : store.getProducts()) {
            if (product.getCategory() == store.getCategories()[choice - 1]) {
                cout << "[" << product.getId() << "] " << product.getName() << " - " << product.getPrice() << " PLN" << endl;
            }
        }
        cout << "+=====================+\n";
        break;
    } while (choice != 0);


    return;
}
