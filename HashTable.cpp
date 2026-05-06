#include "HashTable.h"

// Constructor
// Goes through all the buckets in the table and sets them equal
// null, having them empty at the start
HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}
// Destructor
// Frees all the buckets in the hash table
// Also removes the linked list attach to each category
HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = table[i];
        while (current) {
            HashNode* toBeDeleted = current;
            current = current->next;
            delete toBeDeleted;
        }
    }
}
// Hash function
// Finds which bucket the category will be allocated
int HashTable::hash(const string& key) const {
    int hashValue = 0;
    for (char ch : key) {
        hashValue = (hashValue * 31 + tolower(ch)) % TABLE_SIZE;
    }
    return hashValue;
}
// Insert Function
// Adds a product to it's category
// If the category doesn't exists it get created in the hash table
// If the category exists it adds it to that category and the linked list
void HashTable::insert(const string& category, const string& productName) {
    // Finds the index of the category
    int index = hash(category);

    HashNode* current = table[index];
    // Traverses through all the categories in the index and sees if it exists
    while (current) {
        if (current->category == category) {
            current->addProduct(productName);
            return;
        }
        // Moves to the next category in the index
        current = current->next;
    }
    // Category was not found
    // Creates a new category into the hash table and adds the products
    // name into that category
    HashNode* newNode = new HashNode(category);
    newNode->addProduct(productName);
    newNode->next = table[index];
    table[index] = newNode;
}
// Search function
// Finds the category and returns it, if not found just returns null
HashNode* HashTable::search(const string& category) const {
    int index = hash(category);

    HashNode* current = table[index];
    while (current) {
        if (current->category == category) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
// Remove product Function
// Returns a product from the it's category if the product is found
// it returns true and removed, if false nothing is found
bool HashTable::removeProduct(const string& category, const string& productName) {
    HashNode* node = search(category);

    if (node == nullptr) {
        return false;
    }

    return node->removeProduct(productName);
}
// Remove category function
// Removes the entire category, all the products are deleted
bool HashTable::removeCategory(const string& category) {
    // Get the index of the category
    int index = hash(category);
    // Starts in the first node of the chain
    HashNode* current = table[index];
    // Null because their is nothing before the first
    HashNode* previous = nullptr;
    // Traverses through all the categories in that bucket
    while (current) {
        // If found in the first node of the chain
        if (current->category == category) {
            table[index] = current->next;
        }
        // The rest of the nodes in the chain
        else {
            previous->next = current->next;
        }
        // Deletes the category and automatically triggers the destructor
        // Deleting also the linked list with the product names
        delete current;
        // returns true telling the category was found and deleted
        return true;
    }
    // Returns false if the category was not found
    return false;
}
// Display Function
// Displays all the categories with their products
void HashTable::display() const {
    // Prints the header when printing all the items by category
    cout << "\n       PRODUCTS BY CATEGORY       " << endl;
    cout << string(55, '-') << endl;
    // sets empty true
    bool isEmpty = true;
    // Traverses through all the categories and display all the products
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = table[i];
        while (current) {
            // Prints the category
            isEmpty = false;
            cout << "\n " << current->category << endl;
            cout << string(50, '-') << endl;

            ProductNode* product = current->products;
            int count = 1;
            // Prints the product names
            while (product) {
                cout << " " << count++ << ". " << product->productName << endl;
                product = product->next;
            }
            // Moves to the next category
            current = current->next;
        }
    }
    // If their is nothing inside the hash table
    if (isEmpty) {
        cout << "No categories found." << endl;
    }

    cout << string(55, '-');
}
// Category exists
// Returns true if category was found in the hash table
bool HashTable::categoryExists(const string& category) const {
    return search(category) != nullptr;
}
// Product exists in the category
// returns true if the product exists in a certain category
bool HashTable::productExistsInCategory(const string& category, const string& productName) const {
    HashNode* node = search(category);
    if (node == nullptr) {
        return false;
    }
    return node->containsProduct(productName);
}