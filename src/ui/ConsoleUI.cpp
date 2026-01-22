#include "ConsoleUI.h"

// Główna pętla programu
void ConsoleUI::run(Store& store) {
    int choice = -1;

    do {
        showMenu();
        cin >> choice;
        system("CLS");
        system("clear");
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
    StoreManager storeManager;
    BasketManager basketManager;

    switch (choice){
        case 1: storeManager.runStoreManager(store); break;
        case 2: basketManager.runBasketManager(store); break;
        case 0: cout << "Do zobaczenia!\n"; break;
        default: cout << "Nieprawidłowy wybór\n";
    }
}
