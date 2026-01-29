#include "searching.h"
#include <algorithm>

using namespace std;

namespace Search {
    // ciekawe, ale mózg mi się gotuje 
    // Funkcja obliczająca odległość Levenshteina
    int levenshteinDistance(const string& firstString, const string& secondString) {
        int firstLength = firstString.length();
        int secondLength = secondString.length();

        vector<vector<int>> distanceMatrix(firstLength + 1, vector<int>(secondLength + 1));

        for (int row = 0; row <= firstLength; row++) {
            for (int col = 0; col <= secondLength; col++) {
                if (row == 0) {
                    distanceMatrix[row][col] = col; 
                } else if (col == 0) {
                    distanceMatrix[row][col] = row; 
                } else if (firstString[row - 1] == secondString[col - 1]) {
                    distanceMatrix[row][col] = distanceMatrix[row - 1][col - 1]; 
                } else {
                    distanceMatrix[row][col] = 1 + min({
                        distanceMatrix[row - 1][col],      
                        distanceMatrix[row][col - 1],      
                        distanceMatrix[row - 1][col - 1]   
                    });
                }
            }
        }
        return distanceMatrix[firstLength][secondLength];
    }

    // Funkcja wyszukująca najbliższy produkt na podstawie nazwy
    Product searchProducts(const vector<Product>& products, const string& searchQuery) {
        // Obsługa pustej listy produktów
        if (products.empty()) {
            return Product(-1, "", 0.0, ""); 
        }
        
        Product closestProduct = products[0];
        int minDistance = 15;
        
        // Przeszukuje wszystkie produkty i znajduje najbliższy
        for (const auto& product : products) {
            int distance = levenshteinDistance(searchQuery, product.getName());
            if (distance < minDistance) {
                minDistance = distance;
                closestProduct = product;
            }
        }
        
        return closestProduct;
    }
}
