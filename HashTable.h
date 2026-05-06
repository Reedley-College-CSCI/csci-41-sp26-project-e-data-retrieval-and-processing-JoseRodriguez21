#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "HashNode.h"
#include <iostream>
#include <iomanip>
using namespace std;

class HashTable {
    private:
        static const int TABLE_SIZE = 13;
        HashNode* table[TABLE_SIZE];

        int hash(const string& key) const;
    
    public:
        // Constructor and Destructor
        // Initialize the hash with 13 empty slots null
        HashTable();
        // Frees all the buckets and the lists with the product names
        ~HashTable();
        // Inserts a product into their category bucket
        void insert(const string& category, const string& productName);
        // Search for a category
        HashNode* search(const string& category) const;
        // Removes a product from a category
        bool removeProduct(const string& category, const string& productName);
        // Removes a whole category with all the products in it
        bool removeCategory(const string& category);
        // Displays all the categories with their products
        void display() const;
        // Checks if category is in the hash table
        bool categoryExists(const string& category) const;
        // Checks in product exists in a certain category
        bool productExistsInCategory(const string& category, const string& productName) const;
};

#endif
