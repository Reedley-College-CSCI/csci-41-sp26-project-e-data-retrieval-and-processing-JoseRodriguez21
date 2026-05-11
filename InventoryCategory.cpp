#include "Inventory.h"

void Inventory::searchCategory(HashTable& hashTable) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string category;
    cout << "\nEnter category name to search: ";
    getline(cin, category);

    while (category.empty()) {
        cout << "\nCategory name can't be empty. Enter category: ";
        getline(cin, category);
    }

    HashNode* node = hashTable.search(category);

    if (node == nullptr) {
        cout << category << " not found." << endl;
    }

    else {
        cout << "\n " << node->category << endl;
        cout << string(50, '-') << endl;
        ProductNode* product = node->products;
        int count = 1;
        while (product) {
            cout << " " << count++ << ". " << product->productName << endl;
            product = product->next;
        }
    }
}
bool Inventory::categoryExist(HashTable& hashTable, string& category) {
    cout << "Enter category name: ";
    getline(cin, category);

    while (category.empty()) {
        cout << "\nCategory name can't be empty. Enter category: ";
        getline(cin, category);
    }

    if (!hashTable.categoryExists(category)) {
        cout << category << " category couldn't be found." << endl;
        return false;
    }
    return true;
}