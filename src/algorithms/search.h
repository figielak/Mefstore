#ifndef SEARCH_H
#define SEARCH_H

#include "../core/Product.h"
#include <string>
#include <vector>

using namespace std;

namespace Search {
    int levenshteinDistance(const string& firstString, const string& secondString);
    vector<Product> searchProducts(const vector<Product>& products, const string& searchQuery, int errorThreshold = 2);
}

#endif // SEARCH_H
