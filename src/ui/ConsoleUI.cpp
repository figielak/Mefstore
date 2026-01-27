#include "ConsoleUI.h"

// Główna pętla programu
void ConsoleUI::run(Store& store) {
    int choice = -1;

    do {
        showMenu();
        cin >> choice;
        cout << "\033[2J\033[H";
        handleMenuChoices(choice, store);
    } while (choice != 0);
}

// Wyświetlanie głównego menu
void ConsoleUI::showMenu() {
    cout << "╔═══════════════════════════╗\n"
         << "║        MENU GLÓWNE        ║\n"
         << "╠═══════════════════════════╣\n";
    cout << "║[1] Menedzer sklepu        ║\n";
    cout << "║[2] Stworz koszyk          ║\n";
    cout << "║[0] Wyjście                ║\n";
    cout << "╚═══════════════════════════╝\n";
}

void ConsoleUI::showGoodbye() {
    cout << "----------------------\n"
            "    DO ZOBACZENIA\n"
            "----------------------\n";
}

// Obsługa wyboru użytkownika z menu
void ConsoleUI::handleMenuChoices(int choice, Store& store){
    StoreManager storeManager;
    BasketManager basketManager;

    switch (choice){
        case 1: storeManager.runStoreManager(store); break;
        case 2: basketManager.runBasketManager(store); break;
        case 0: showGoodbye(); break;
        default: cout << "Nieprawidłowy wybór\n";
    }
}
