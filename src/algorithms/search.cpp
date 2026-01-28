#include "search.h"
#include <algorithm>

using namespace std;

namespace Search {
    // Funkcja obliczająca odległość Levenshteina
    int levenshteinDistance(const string& firstString, const string& secondString) {
        int firstLength = firstString.length();
        int secondLength = secondString.length();

        // Tworzymy macierz programowania dynamicznego o rozmiarach (firstLength+1) x (secondLength+1)
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
                    distanceMatrix[row][col] = 1 + min({distanceMatrix[row - 1][col],      // Usunięcie
                                                         distanceMatrix[row][col - 1],      // Wstawienie
                                                         distanceMatrix[row - 1][col - 1]}); // Zamiana
                }
            }
        }
        return distanceMatrix[firstLength][secondLength];
    }

    // Funkcja wyszukująca produkty na podstawie nazwy z tolerancją błędów
    vector<Product> searchProducts(const vector<Product>& products, const string& searchQuery, int errorThreshold) {
        vector<Product> matchingProducts;
        
        int errorThreshold = max(1, (int)(searchQuery.length() * 0.25)); // Ustalanie progu błędów na 25% długości zapytania

        for (const auto& product : products) {
            int distance = levenshteinDistance(searchQuery, product.getName());
            if (distance <= errorThreshold) {
                matchingProducts.push_back(product);
            }
        }
        
        return matchingProducts;
    }
}
