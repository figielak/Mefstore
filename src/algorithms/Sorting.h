#ifndef SORTING_H
#define SORTING_H

#include "../core/Product.h"
#include <vector>

using namespace std;

namespace Sorting {
    void bubbleSortByNameAZ(vector<Product>& products);
    void bubbleSortByNameZA(vector<Product>& products);
}

#endif // SORTING_H
