#ifndef HASH_NODE_H
#define HASH_NODE_H

#include <string>
using namespace std;

// Struct that works as a linked list inside each category
// Stores product names 
struct ProductNode {
    string productName;
    ProductNode* next;
    
    ProductNode(string name) {
        productName = name;
        next = nullptr;
    }
};

struct HashNode {
    // key
    string category;
    // Linked list of products in this category
    ProductNode* products;
    // Next node in the chain when a collision occurs
    HashNode* next;

    // Constructor 
    HashNode(string category) {
        this->category = category;
        products = nullptr;
        next = nullptr;
    }
    // Destructor
    // Deletes all the products in the category
    ~HashNode() {
        ProductNode* current = products;
        while (current) {
            ProductNode* toBeDeleted = current;
            current = current->next;
            delete toBeDeleted;
        }
    }
    // Add product
    // Adds a product to the this category linked list
    void addProduct(const string& productName) {
        
        ProductNode* newNode = new ProductNode(productName);
        
        if (products == nullptr) {
            products = newNode;
        }

        else {
            ProductNode* current = products;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Remove product
    // Removes a product from the current catergory
    bool removeProduct(const string& productName) {
        // First product in the linked list
        ProductNode* current = products;
        // Previous null because their is no product before current
        ProductNode* previous = nullptr;

        while (current) {
            // Checks in the product name was found in the linked list
            if (current->productName == productName) {
                
                if (previous == nullptr) {
                    products = current->next;
                }
                else {
                    previous->next = current->next;
                }
                // Deletes the product and sets bool to true
                delete current;
                return true;
            }
            // Previous is now current
            previous = current;
            // Current is the next product after current
            current = current->next;
        }
        // No product with the name inputed was found
        return false;
    }
    // Traverses through the category and returns true if the product
    // was found in that category
    bool containsProduct(const string& productName) const {
        ProductNode* current = products;
        // Traverses through all the products in the category 
        // goes through every single product in the linked list
        while (current) {
            if (current->productName == productName) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

#endif