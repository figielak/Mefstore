#include "ui/ConsoleUI.h"
#include "core/Store.h"
#include "core/Product.h"

int main() {
    Store store;
    ConsoleUI ui;

    system("CLS");
    system("clear");
    ui.run(store);

    return 0;
}
