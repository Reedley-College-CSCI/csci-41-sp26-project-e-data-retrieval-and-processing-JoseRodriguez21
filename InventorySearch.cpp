#include "Inventory.h"


// Prints the header when printing all the products or specific products.
void Inventory::printHeader() {
    cout << left 
    << setw(20) << "Name" 
    << setw(10) << "Stock"  
    << setw(12) << "Price"  
    << "Category" << endl;
}

// Prints all the products that the database has.
void Inventory::printProducts() {  
    
    if (count == 0) {
        cout << "Inventory empty." << endl;
        return;
    }

    cout << "\nPRODUCT LIST:\n";
    printHeader();

    for (int i = 0; i < count; i++) {
        cout << left 
        << setw(20) << product[i]. productName 
        << setw(10) << product[i].itemStock 
        << "$" << left << setw(12) << fixed << setprecision(2) << product[i].price
        << product[i].category << endl;
    }
}

// Search function to search for a specific product by name
int Inventory::searchProduct(const string& targetProduct, long long& opCount, bool sortOrder) {
    int low = 0;
    int high = count - 1;
    opCount = 0;

    while (low <= high) {
        opCount++;
        int mid = (low + high) / 2;

        if (!compareCase(product[mid].productName, targetProduct, sortOrder) &&
           (!compareCase(targetProduct, product[mid].productName, sortOrder))) {
            return mid;
        }
        else if (compareCase(product[mid].productName, targetProduct, sortOrder)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}