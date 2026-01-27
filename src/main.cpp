#include "ui/ConsoleUI.h"
#include "core/Store.h"
#include "core/Product.h"

int main() {
    Store store;
    ConsoleUI ui;

    cout << "\033[2J\033[H";
    ui.run(store);

    return 0;
}
