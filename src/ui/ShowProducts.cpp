#include "ShowProducts.h"

void ShowProducts::showProducts(Store& store){
    int choice = -1;

    do {
        showProductsMenu(store);
        cin >> choice;
        cout << "\033[2J\033[H";
        handleProductsMenuChoices(choice, store);
    } while (choice != 0);
}

void ShowProducts::showProductsMenu(Store& store){
    cout << "╔══════════════════════════════════════════╗\n"
         << "║                 WYBÓR OPCJI              ║\n"
         << "╠══════════════════════════════════════════╣\n";
    cout << "║[1] Wyświetl wszystkie produkty           ║\n";
    cout << "║[2] Sortowanie po nazwie A-Z              ║\n";
    cout << "║[3] Sortowanie po nazwie Z-A              ║\n";
    cout << "║[4] Wybierz kategorie                     ║\n";
    cout << "║[0] Wroc do menu                          ║\n";
    cout << "╚══════════════════════════════════════════╝\n";
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
void ShowProducts::showAllProducts(Store& store) {
    cout << "\033[2J\033[H";
    cout << "╔══════════════════════════════════════════════╗\n"
         << "║                 LISTA PRODUKTÓW              ║\n"
         << "╚══════════════════════════════════════════════╝\n";
    for (const Product& p : store.getProducts()) {
        cout << right << "[" << p.getId() << "] " << left << p.getName() << " - " << right << p.getPrice() << " PLN\n";
    }
    cout << "────────────────────────────────────────────────\n";
}

// Wyświetlenie produktów posortowanych po nazwie A-Z
void ShowProducts::showProductsByNameAZ(Store& store){
    cout << "\033[2J\033[H";
    cout << "╔══════════════════════════════════════════════╗\n"
         << "║                 LISTA PRODUKTÓW              ║\n"
         << "╚══════════════════════════════════════════════╝\n";
    Sorting::bubbleSortByNameAZ(store.getProducts());
    for (Product& product : store.getProducts()){
        cout << right << "[" << product.getId() << "] " << left << product.getName() << " - " << right << product.getPrice() << " PLN" << endl;
    }
    cout << "────────────────────────────────────────────────\n";
    return;
}

// Wyświetlenie produktów posortowanych po nazwie Z-A
void ShowProducts::showProductsByNameZA(Store& store){
    cout << "\033[2J\033[H";
    cout << "╔══════════════════════════════════════════════╗\n"
         << "║                 LISTA PRODUKTÓW              ║\n"
         << "╚══════════════════════════════════════════════╝\n";
    Sorting::bubbleSortByNameZA(store.getProducts());
    for (Product& product : store.getProducts()){
        cout << right << "[" << product.getId() << "] " << left << product.getName() << " - " << right << product.getPrice() << " PLN" << endl;
    }
    cout << "────────────────────────────────────────────────\n";
    return;
}

// Wyświetlenie produktów danej kategorii
void ShowProducts::showProductsByCategory(Store& store){
    int choice = -1;

    do {
        cout << "╔══════════════════════════════════════════════╗\n"
             << "║                 WYBÓR KATEGORII              ║\n"
             << "╚══════════════════════════════════════════════╝\n";
        for (int i = 0; i < store.getCategories().size(); i++){
            cout << "[" << i + 1 << "] " << store.getCategories()[i] << endl;
        }
        cout << "[0] Wróć do menu głównego\n";

        cin >> choice;
        cout << "\033[2J\033[H";

        if (choice < 1 || choice > store.getCategories().size()) {
            cout << "Nieprawidłowy wybór\n";
            continue;
        }

        cout << "╔══════════════════════════════════════════════╗\n"
             << "║                 LISTA PRODUKTÓW              ║\n"
             << "╚══════════════════════════════════════════════╝\n";
        for (Product& product : store.getProducts()) {
            if (product.getCategory() == store.getCategories()[choice - 1]) {
                cout << right << "[" << product.getId() << "] " << left << product.getName() << " - " << right << product.getPrice() << " PLN" << endl;
            }
        }
        cout << "────────────────────────────────────────────────\n";
        break;
    } while (choice != 0);


    return;
}
