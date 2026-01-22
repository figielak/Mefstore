#ifndef STORE_MANAGER_H
#define STORE_MANAGER_H

class StoreManager {
public:
    void runStoreManager(Store& store);

private:
    /// STORE MANAGER
    void showStoreManager(Store& store);

    void handleStoreManagerChoices(int choice, Store& store);

    void addProduct(Store& store);

    void editProduct(Store& store);

    void removeProduct(Store& store);

    void showProducts(Store& store);

    /// PRODUCTS MENU
    void showProductsMenu(Store& store);

    void handleProductsMenuChoices(int choice, Store& store);

    void showProductsById(Store& store);

    void showProductsByName(Store& store);

    void showProductsByCategory(Store& store);
};

#endif // STORE_MANAGER_H
