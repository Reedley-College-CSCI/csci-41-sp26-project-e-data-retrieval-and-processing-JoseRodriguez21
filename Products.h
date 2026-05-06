#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <string>

using namespace std;

struct Products {
    string productName;
    int itemStock;
    double price;
    string category;

    Products() {
        productName = "";
        itemStock = 0;
        price = 0.0;
        category = "";
    }
};

#endif
