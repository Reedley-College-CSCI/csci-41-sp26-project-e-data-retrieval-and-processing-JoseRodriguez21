#include "Inventory.h"


// Validates the user did input a interger.
int Inventory::getValidInt() const {
    int val;
    while (!(cin >> val)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a whole number: ";
    }
    return val;
}

// Validates the user did input a double.
double Inventory::getValidDouble() const {
    double val;
    while (!(cin >> val)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a price (2.50): ";
    }
    return val;
}

// Validates that the user enter number greater than 0.
int Inventory::getPositiveInt() const {
    int val;
    while (!(cin >> val) || val <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a number greater than 0: " << endl;
    }
    return val;
}

// Validates that the user enters a number greater than 0.0
double Inventory::getPositiveDouble() const {
    double val;
    while (!(cin >> val) || val <= 0.0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a price greater than 0.0: ";
    }
    return val;
}

// Resize the array when the capacity is reached.
void Inventory::resize() {
    
    int newCapacity = capacity + capacity / 2;

    if (newCapacity <= capacity) {
        newCapacity = capacity + 1;
    }

    Products* newArray = new Products[newCapacity];

    for (int i = 0; i < count; i++) {
        newArray[i] = product[i];
    }

    delete[] product;

    product = newArray;
    capacity = newCapacity;
}
