#include "../ui/ConsoleUI.h"
#include <iostream>

using namespace std;

// Główna pętla programu
void ConsoleUI::run(Store& store) {
    int choice = -1;

    do {
        showMenu();
        cin >> choice;
        handleMenuChoices(choice, store);
    } while (choice != 0);
}

// Wyświetlanie głównego menu
void ConsoleUI::showMenu() {
    cout << "\n+=== Mefstore Menu ===+\n";
    cout << "[1] Menedzer sklepu \n";
    cout << "[2] Stworz koszyk \n";
    cout << "[0] Wyjście \n";
    cout << "+=====================+\n";
}

// Obsługa wyboru użytkownika z menu
void ConsoleUI::handleMenuChoices(int choice, Store& store){
    switch (choice){
        case 1: showProducts(store); break;
        case 2: addProduct(store); break;
        case 3: editProduct(store); break;
        case 4: removeProduct(store); break;
        case 0: cout << "Do zobaczenia!\n"; break;
        default: cout << "Nieprawidłowy wybór\n";
    }
}

// Wyświetlenie menedżera sklepu
void ConsoleUI::showStoreManager(Store& store){
    cout << "\n+=== Mefstore ===+\n";
    cout << "[1] Wyświetl produkty \n";
    cout << "[2] Dodaj produkt \n";
    cout << "[3] Edytuj produkt \n";
    cout << "[4] Usuń produkt \n";
    cout << "[0] Wroc do menu \n";
    cout << "+=====================+\n";
}

// Wyświetlenie zarządzania koszykiem
void ConsoleUI::showBasketManager(Store& store){
    cout << "\n+====== Koszyk ======+\n";
    cout << "[1] Wyświetl produkty \n";
    cout << "[2] Dodaj produkt \n";
    cout << "[3] Usun produkt \n";
    cout << "[4] Wyświetl koszyk \n";
    cout << "[5] Generuj paragon \n";
    cout << "[0] Wroc do menu \n";
    cout << "+=====================+\n";
}

// Wyświetlanie produktów
void ConsoleUI::showProductsMenu(Store& store){
    cout << "\n+=== Wybierz opcje ===+\n";
    cout << "[1] Sortowanie po id\n";
    cout << "[2] Sortowanie po nazwie\n";
    cout << "[3] Wybierz kategorie\n";
    cout << "[0] Wroc do menu\n";
    cout << "+=====================+\n";
}

void ConsoleUI::showProductsById(Store& store){
    cout << "\n+====== Produkty ======+\n";
    for (Product& product : store.getProducts()){
        cout << "[" << product.getId() << "] " << product.getName() << " \n";
    }
    cout << "+=====================+\n";
}


// Dodawanie produktu
void ConsoleUI::addProduct(Store& store){
    return;
}

// Edycja produktu
void ConsoleUI::editProduct(Store& store){
    return;
}

// Usuwanie produktu
void ConsoleUI::removeProduct(Store& store){
    return;
}
