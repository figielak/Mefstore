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

// Wczytywanie produktów z pliku
void Store::loadProducts(string filename){
    string filepath = "data/" + filename;
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
int Store::addProduct(const Product& product, string filename, string product_name, double product_price, string product_category) {
    string filepath = "data/" + filename;
    
    // Sprawdzamy czy istnieje produkt o danej nazwie jeśli tak to zwracamy jego ID aby uniknąć duplikatów
    for (const auto& p : products) {
        if (p.getName() == product_name) {
            cout << "Produkt o nazwie '" << product_name << "' juz istnieje z ID: " << p.getId() << endl;
            return p.getId();
        }
    }
    
    // Znajdujemy pierwszy wolny ID dla nowego produktu 
    int newId = -1;
    for(int i = 1; i <= products.size() + 1; i++){
        bool exists = false;
        for(const auto& p : products){
            if(p.getId() == i){
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
    for(int i = 0; i < products.size(); i++){
        if(products[i].getId() < newId){
            insertPos = i + 1;
        }
    }
    products.insert(products.begin() + insertPos, Product(newId, product_name, product_price, product_category));
    cout << "Dodano nowy produkt '" << product_name << "' z ID: " << newId << endl;
    
    // Zapisujemy wszystkie produkty do pliku CSV
    ofstream outfile(filepath, ios::trunc);
    if (!outfile.is_open()) {
        cout << "Nie udalo sie otworzyc pliku do zapisu: " << filename << endl;
        return -1;
    }
    
    for (const auto& p : products) {
        outfile << p.getId() << ", " << p.getName() << ", " 
                << p.getPrice() << ", " << p.getCategory() << endl;
    }
    
    outfile.close();
    cout << "Plik " << filename << " zostal zaktualizowany." << endl;
    return newId;
}