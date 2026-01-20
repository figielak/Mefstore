#include "Store.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
