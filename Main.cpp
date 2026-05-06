#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <chrono>
#include <limits>
#include <iomanip>

#include "Inventory.h"

using namespace std;

int main() {
    string userName;
    int productCount = 0;
    
    Inventory store;
    HistoryList history;
    DeliveryQueue queue;
    HashTable hashTable;
    bool sortOrder = true;
    
    // Loads information about the products available
    store.loadData("Storage.txt", hashTable);
    // Sorts the products available
    store.sortByName(true);
    // Loads the history on what has been done to the products
    int nextId = history.loadHistory("History.txt") + 1;
    // Loads any deliveries pending
    queue.loadDeliveries("Deliveries.txt");
    
    // Asks the user for their name
    cout << "Enter your name: ";
    getline(cin, userName);

    // Welcomes the user and opens the menu for the user to interact
    cout << "\nWelcome " << userName << " to your storage system." << endl;
    store.selectOption(sortOrder, history, nextId, queue, hashTable);
    // Update all the data into the storage.txt file
    store.updateData("Storage.txt");

    return 0;

}