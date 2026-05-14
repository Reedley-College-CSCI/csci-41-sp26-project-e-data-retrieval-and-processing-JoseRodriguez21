#ifndef INVENTORY_H
#define INVENTORY_H
 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <chrono>
#include <limits>
#include <iomanip>

#include "Products.h"
#include "HistoryLinkedList.h"
#include "DeliveryQueue.h"
#include "HashTable.h"

using namespace std;

class Inventory {
    private:
        Products* product;
        int count;
        int capacity;
        bool compareCase(const string& product1, const string& product2, bool sortOrder) const;
        void quickSort(int low, int high, bool sortOrder);
        int partition(int low, int high, bool sortOrder);
        void displayMenu();
        void logMenu();
        void deliveryMenu();
        void categoryMenu();
        void createTicket(DeliveryQueue& queue);
        void processTicket(DeliveryQueue& queue, HistoryList& history, int& nextId, HashTable& hashTable);
        void searchQueue(DeliveryQueue& queue);
        bool categoryExist(HashTable& hashTable, string& category);
        void deleteCategory(bool& sortOrder, HistoryList& history, int& nextId, HashTable& hashTable, string& category);
        void modifyProduct(bool& sortOrder, HistoryList& history, int& nextId, HashTable& hashTable);

        void resize();
        void printHeader();
        int getValidInt() const;
        double getValidDouble() const;
        int getPositiveInt() const;
        double getPositiveDouble() const;
        
    public:
    Inventory() {
        capacity = 30;
        count = 0;
        product = new Products[capacity];
    }

    ~Inventory() {
        delete[] product;
    }

    void loadData(const string& filename, HashTable& hashTable);
    void updateData(const string& filename);
    void sortByName(bool sortOrder);
    void printProducts();
    void selectOption(bool& sortOrder, HistoryList& history, int& nextId, DeliveryQueue& queue, HashTable& hashTable);
    void logSelectionOption(HistoryList& history, int& nextId);
    void deliverySelectionOption(DeliveryQueue& queue, HistoryList& history, int& nextId, HashTable& hashTable);
    void categorySelectionOption(bool& sortOrder, HistoryList& history, int& nextId, HashTable& hashTable);
    void addProduct(bool sortOrder, HistoryList& history, int& nextId, HashTable& hashTable);
    void deleteProduct(const string& targetProduct, bool sortOrder, HistoryList& history, int& nextId, HashTable& hashTable);
    int searchProduct(const string& targetProduct, long long& opCount, bool sortOrder);
    void searchCategory(HashTable& hashTable, string& category);
};

#endif