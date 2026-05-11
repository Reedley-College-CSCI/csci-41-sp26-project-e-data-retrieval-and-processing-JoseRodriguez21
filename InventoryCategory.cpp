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

void Inventory::deleteCategory(bool& sortOrder, HistoryList& history, int& nextId, HashTable& hashTable, string& category) {
    // comfirms if the user is sure of deleting the category
    cout << "Are you sure you want to delete the entire" << category << "category? (1 = yes, 0 = no): ";
    int userChoice = getValidInt();
    // Makes sure the user either input 1 or 0
    while (userChoice != 1 && userChoice != 0) {
        cout << "Invalid. Enter 1 or 0: ";
        userChoice = getValidInt();
    }
    // If 0 is inputted they the action gets cancelled
    if (userChoice == 0) {
        cout << "Deletion cancelled." << endl;
        return;
    } 
    // Goes through all the items in the array
    int newCount = 0;
    for (int i = 0; i < count; i++) {
        // If the category is not the same the product is kept on the array
        if (product[i].category != category) {
            product[newCount] = product[i];
            newCount++;
        }
        // If the category is the same then it get's removed
        else {    
            Transaction log;
            log.id = nextId++;
            log.action = "Removed";
            log.name = product[i].productName;
            log.quantity = product[i].itemStock;
            history.Prepend(log);
        }
    }
    // Clears the rest of the slots 
    for (int i = newCount; i < count; i++) {
        product[1] = Products();
    }
    count = newCount;
    // Remove category from the hash table
    hashTable.removeCategory(category);
    // Save everything into the text files
    history.saveHistory("History.txt");
    updateData("Storage.txt");
    sortByName(sortOrder);
    // Successful message of delition
    cout << category << " category deleted successfully." << endl;
    
}