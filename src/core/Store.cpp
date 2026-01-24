#include "Store.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Store::Store(){
    loadProducts("products.csv");
}

vector<Product> Store::getProducts(){
    return products;
}
// Zapis produktów do pliku
void Store::saveProducts(string filename, vector<Product> products){
    string filepath = "src/data/" + filename;
    ofstream outfile(filepath, ios::trunc);
    if (!outfile.is_open()) {
        cout << "Nie udalo sie otworzyc pliku do zapisu: " << filename << endl;
        return;
    }
    
    for (const auto& p : products) {
        outfile << p.getId() << "," << p.getName() << "," 
                << p.getPrice() << "," << p.getCategory() << endl;
    }
    
    outfile.close();
    cout << "Plik " << filename << " zostal zaktualizowany." << endl;
}

// Wczytywanie produktów z pliku
void Store::loadProducts(string filename){
    string filepath = "src/data/" + filename;
    cout << "Wczytywanie produktów z pliku: " << filepath << endl;
    ifstream file(filepath);

    if (!file.is_open()) {
        cout << "Nie udalo sie otworzyc pliku: " << filename << endl;
        return;
    }

    string line;
    while(getline(file, line)){
        if(line.empty()) continue;

        stringstream ss(line);
        string id_str, name , price_str, category;

        getline(ss, id_str, ',');
        getline(ss, name, ',');
        getline(ss, price_str, ',');
        getline(ss, category, ',');

        int id = stoi(id_str);
        double price = stod(price_str);

        try {
            products.push_back(Product(id, name, price, category));
        } catch (const exception& e) {
            cout << "Nie udalo sie wczytac produktu: " << e.what() << endl;
            continue;
        }
    }

    file.close();
}

// Dodawanie produktu z sprawdzeniem istnienia o danej nazwie
void Store::addProduct(string filename, string product_name, double product_price, string product_category) {
    // Wczytujemy aktualne produkty
    products.clear();
    loadProducts(filename);
    
    string filepath = "src/data/" + filename;
    
    // Sprawdzamy czy istnieje produkt o danej nazwie jeśli tak to zwracamy jego ID aby uniknąć duplikatów
    for (const auto& p : products) {
        if (p.getName() == product_name) {
            cout << "Produkt o nazwie '" << product_name << "' juz istnieje z ID: " << p.getId() << endl;
            return;
        }
    }
    
    // Znajdujemy pierwszy wolny ID dla nowego produktu 
    int newId = -1;
    for(size_t i = 1; i <= products.size() + 1; i++){
        bool exists = false;
        for(const auto& p : products){
            if(p.getId() == (int)i){
                exists = true;
                break;
            }
        }
        if(!exists){
            newId = i;
            break;
        }
    }
    
    // Dodajemy nowy produkt z wolnym ID na właściwą pozycję według ID
    int insertPos = 0;
    for( size_t i = 0; i < products.size(); i++){
        if(products[i].getId() < newId){
            insertPos = i + 1;
        }
    }
    products.insert(products.begin() + insertPos, Product(newId, product_name, product_price, product_category));
    cout << "Dodano nowy produkt '" << product_name << "' z ID: " << newId << endl;
    
    // Zapis 
    saveProducts(filename, products);
}

void Store::editProduct(string filename, string searchValue, string new_name, double new_price, string new_category){
    // Wczytujemy aktualne produkty
    products.clear();
    loadProducts(filename);

    string filepath = "src/data/" + filename;
    
    bool found = false;
    try {
        int id = stoi(searchValue);
        // Szukamy po ID
        for(size_t i = 0; i < products.size(); i++){
            if(products[i].getId() == id){
                cout << "Znaleziono produkt po ID: " << products[i].getName() << " (ID: " << id << ")" << endl;
                products[i].setName(new_name);
                products[i].setPrice(new_price);
                products[i].setCategory(new_category);
                found = true;
                break;
            }
        }
    } catch(...) {
        // Szukamy po nazwie
        for(size_t i = 0; i < products.size(); i++){
            if(products[i].getName() == searchValue){
                cout << "Znaleziono produkt po nazwie: " << searchValue << " (ID: " << products[i].getId() << ")" << endl;
                products[i].setName(new_name);
                products[i].setPrice(new_price);
                products[i].setCategory(new_category);
                found = true;
                break;
            }
        }
    }
    
    if(!found){
        cout << "Nie znaleziono produktu: " << searchValue << endl;
        return;
    }
    
    // Zapis
    saveProducts(filename, products);
}

// Usuwanie produktu - automatyczne wykrywanie po czym szukać (ID lub nazwa)
bool Store::removeProduct(string filename, string searchValue) {
    // Wczytujemy aktualne produkty
    products.clear();
    loadProducts(filename);

    string filepath = "src/data/" + filename;
    
    bool found = false;
    int indexToRemove = -1;
    
    try {
        int id = stoi(searchValue);
        // Szukamy po ID
        for(size_t i = 0; i < products.size(); i++){
            if(products[i].getId() == id){
                cout << "Znaleziono produkt po ID: " << products[i].getName() << " (ID: " << id << ")" << endl;
                indexToRemove = i;
                found = true;
                break;
            }
        }
    } catch(...) {
        // Szukamy po nazwie
        for(size_t i = 0; i < products.size(); i++){
            if(products[i].getName() == searchValue){
                cout << "Znaleziono produkt po nazwie: " << searchValue << " (ID: " << products[i].getId() << ")" << endl;
                indexToRemove = i;
                found = true;
                break;
            }
        }
    }
    
    if(!found){
        cout << "Nie znaleziono produktu: " << searchValue << endl;
        return false;
    }
    
    // Usuń produkt
    products.erase(products.begin() + indexToRemove);
    cout << "Produkt został usunięty." << endl;
    
    // Zapis
    saveProducts(filename, products);
    return true;
}