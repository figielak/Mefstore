#include "BasketManager.h"
#include "../algorithms/searching.h"

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
    cout << "║[4] Edytuj produkt w koszyku          ║\n";
    cout << "║[5] Wyświetl koszyk                   ║\n";
    cout << "║[6] Generuj paragon                   ║\n";
    cout << "║[0] Wroc do menu                      ║\n";
    cout << "╚══════════════════════════════════════╝\n";
}

void BasketManager::handleBasketManagerChoices(int choice, Store& store){
    ShowProducts showProducts;

    switch (choice){
        case 1: showProducts.showProducts(store); break;
        case 2: addToBasket(store); break;
        case 3: removeFromBasket(store); break;
        case 4: editBasket(store); break;
        case 5: showBasket(store); break;
        case 6: generateReceipt(store); break;
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
    string productInput;
    cout << "Podaj nazwę produktu: ";
    cin >> productInput;

    Product closestProduct = Search::searchProducts(store.getProducts(), productInput);

    if (closestProduct.getName() != productInput) {
        char choice;
        cout << "Nie znaleziono \"" << productInput << "\". Czy chodziło Ci o: "
             << closestProduct.getName() << " - (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            cout << "Anulowano dodawanie produktu.\n";
            return;
        }
    }

    basket.addProduct(productInput, store.getProducts());

    cout << "Dodano produkt: " << closestProduct.getName() << " - " << closestProduct.getPrice() << " PLN\n";
}

void BasketManager::removeFromBasket(Store& store){
    string productInput;
    cout << "Podaj nazwę produktu do usunięcia: ";
    cin >> productInput;

    Product closestProduct = Search::searchProducts(basket.getBasket(), productInput);

    if (closestProduct.getId() == -1) {
        cout << "Koszyk jest pusty.\n";
        return;
    }

    if (closestProduct.getName() != productInput) {
        char choice;
        cout << "Nie znaleziono \"" << productInput << "\". Czy chodziło Ci o: "
             << closestProduct.getName() << " - (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            cout << "Anulowano usuwanie produktu.\n";
            return;
        }
    }

    basket.removeProduct(productInput);

    cout << "Usunięto produkt: " << closestProduct.getName() << "\n";
}

void BasketManager::editBasket(Store& store){
    string oldProductInput, newProductInput;
    cout << "Podaj nazwę produktu do edycji: ";
    cin >> oldProductInput;

    Product oldClosestProduct = Search::searchProducts(basket.getBasket(), oldProductInput);

    if (oldClosestProduct.getId() == -1) {
        cout << "Koszyk jest pusty.\n";
        return;
    }

    if (oldClosestProduct.getName() != oldProductInput) {
        char choice;
        cout << "Nie znaleziono \"" << oldProductInput << "\". Czy chodziło Ci o: "
             << oldClosestProduct.getName() << " - (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            cout << "Anulowano edycję produktu.\n";
            return;
        }
    }

    cout << "Podaj nową nazwę produktu: ";
    cin >> newProductInput;

    Product newClosestProduct = Search::searchProducts(store.getProducts(), newProductInput);

    if (newClosestProduct.getName() != newProductInput) {
        char choice;
        cout << "Nie znaleziono \"" << newProductInput << "\". Czy chodziło Ci o: "
             << newClosestProduct.getName() << " - (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            cout << "Anulowano edycję produktu.\n";
            return;
        }
    }

    basket.editProduct(oldProductInput, newProductInput, store.getProducts());

    cout << "Zamieniono " << oldClosestProduct.getName() << " na " << newClosestProduct.getName() << "\n";
}
