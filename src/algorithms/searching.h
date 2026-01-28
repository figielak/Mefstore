#ifndef SEARCHING_H
#define SEARCHING_H

#include "../core/Product.h"
#include <string>
#include <vector>

using namespace std;

namespace Search {
    int levenshteinDistance(const string& firstString, const string& secondString);
    Product searchProducts(const vector<Product>& products, const string& searchQuery);
}

#endif // SEARCHING_H
