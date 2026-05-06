#include "Inventory.h"

// Compares two products using case sensitive.
bool Inventory::compareCase(const string& product1, const string& product2, bool sortOrder) const {
    
    int n = (product1.length() < product2.length()) ? product1.length() : product2.length();

    for (int i = 0; i < n; i++) {
        char char1 = tolower(product1[i]);
        char char2 = tolower(product2[i]);

        if (sortOrder) {
            if (char1 < char2) return true;
            if (char1 > char2) return false;
            }
        else {
            if (char1 > char2) return true;
            if (char1 < char2) return false;
            }
        }
    
    if (sortOrder) {
        return product1.length() < product2.length();
        }
    else {
        return product1.length() > product2.length();
        };
}

// Sorting function that calls the quicksort function.
void Inventory::sortByName(bool sortOrder) {
    quickSort(0, count - 1, sortOrder);
}

int Inventory::partition(int low, int high, bool sortOrder) {
    int mid = low + (high - low) / 2;
    Products pivot = product[mid];
    int i = low;
    int j = high;
    bool done = false;

    while (!done) {
        while (compareCase(product[i].productName, pivot.productName, sortOrder)&& i < high) {
            i++;
        }

        while (compareCase(pivot.productName, product[j].productName, sortOrder)) {
            j--;
        }

        if (i >= j) {
            done = true;
        }
        else {
            Products temp = product[i];
            product[i] = product[j];
            product[j] = temp;

            i++;
            j --;
        }
    }
    return j;
    
}

// 
void Inventory:: quickSort(int low, int high, bool sortOrder) {
    
    if (low >= high) {
        return;
    }
    int splitPoint = partition(low, high, sortOrder);

    quickSort(low, splitPoint, sortOrder);
    quickSort(splitPoint + 1, high, sortOrder);

}
