#include "Inventory.h"

// Display a menu to the user with their options.
void Inventory::displayMenu() {
    cout << "\n         Storage         " << endl;
    cout << "--------------------------" << endl;
    cout << "1 - Add Product           " << endl;
    cout << "2 - Delete Product        " << endl;
    cout << "3 - Display all Products  " << endl;
    cout << "4 - Search for a Product  " << endl;
    cout << "5 - Sorting A - Z or Z - A" << endl;
    cout << "6 - Log history           " << endl;
    cout << "7 - Pending Deliveries    " << endl;
    cout << "8 - Browse by category    " << endl;
    cout << "-99 - Exit the program    " << endl;
    cout << "--------------------------" << endl;
    cout << "Enter a choice: ";

}

// Display a submenu for the user to interact with the logs
void Inventory::logMenu() {
    cout << "\n   Transaction History    " << endl;
    cout << "----------------------------" << endl;
    cout << " 1 - Display all history log" << endl;
    cout << " 2 - Search log by Id       " << endl;
    cout << " 3 - Clear all history      " << endl;
    cout << "-1 - Return                 " << endl;
    cout << "----------------------------" << endl;
    cout << "Enter a choice: ";
}

// Display a submenu for the user to interact with the pending deliveries
void Inventory::deliveryMenu() {
    cout << "\n          Pending Deliveries        " << endl;
    cout << "--------------------------------------" << endl;
    cout << " 1 - New Delivery ticket              " << endl;
    cout << " 2 - Process Delivery                 " << endl;
    cout << " 3 - Display all pending deliveries   " << endl;
    cout << " 4 - Search for a product in the queue" << endl;
    cout << "-1 - Return back to the main menu     " << endl;
    cout << " Enter a Choice: ";
}
// Display a menu for category Hash table
void Inventory::categoryMenu() {
    cout << "\n          Browse By Category        " << endl;
    cout << "--------------------------------------" << endl;
    cout << " 1 - Display all categories           " << endl;
    cout << " 2 - Display products of a category   " << endl;
    cout << " 3 - Search for a category            " << endl;
    cout << " 4 - Delete entire category           " << endl;
    cout << "-1 - Return back to the main menu     " << endl;
    cout << " Enter a Choice: ";
}
// Selection option at the start of the program
// Manages all the components from the program
void Inventory::selectOption(bool& sortOrder, HistoryList& history, int& nextId, DeliveryQueue& queue, HashTable& hashTable) {
    int userChoice;
    while(true) {
        displayMenu();
        while (!(cin >> userChoice)) {
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Invalid input. Enter a number from the menu:" << endl;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (userChoice == -99) {
            cout << "You have exited the program." << endl;
            break;
        }
        switch (userChoice) {
            
            case 1: addProduct(sortOrder, history, nextId, hashTable); 
                    break;
            
            case 2: {
                    string productName;

                    cout << "Enter product name to delete: ";
                    getline(cin, productName);

                    //Edge case if the user left the product name empty.
                    while (productName.empty()) {
                        cout << "Product name cannot be empty." << endl;
                        getline(cin, productName);
                    }

                    deleteProduct(productName, sortOrder, history, nextId, hashTable);
                    break;
                    } 
            
            case 3: printProducts(); 
                    break;
            
            case 4: {
                    string productName;

                    cout << "\nEnter product name to search: ";
                    getline(cin, productName);
                    
                    //Edge case if the user left the product name empty.
                    while (productName.empty()) {
                        cout << "Product name cannot be empty." << endl;
                        getline(cin, productName);
                    }
                      
                    long long opCount;
                    auto start = chrono::high_resolution_clock::now();
                    int index = searchProduct(productName, opCount, sortOrder);
                    auto end = chrono::high_resolution_clock::now();
                      
                    cout << "Binary Search: " << opCount << " ops, "
                           << chrono::duration_cast<chrono::microseconds>(end - start).count()
                           << " us" << endl;
                        
                        if (index == -1) {
                            cout << productName << " not found." << endl;
                        }
                        else {
                            printHeader();
                            cout << left 
                            << setw(20) << product[index]. productName 
                            << setw(10) << product[index].itemStock 
                            << "$" << left << setw(12) << fixed << setprecision(2) << product[index].price
                            << product[index].category << endl;
                        }

                        break;
                    }
            
            case 5: {
                    cout << "\nSelect 1 to sort ascending or 2 to sort descending: ";
                    int choice = getValidInt();

                        if (choice == 1) {
                            sortOrder = true;
                            sortByName(sortOrder);
                            cout << "Sorted A - Z" << endl;
                        }
                        else if (choice == 2) {
                            sortOrder = false;
                            sortByName(sortOrder);
                            cout << "Sorted Z - A" << endl;
                        }
                        else {
                            cout << "Invalid choice. Kept original order" << endl;
                        }
                    break;
                    }
            
            case 6: {
                    logSelectionOption(history, nextId);
                    break;
                    }

            case 7: {
                    deliverySelectionOption(queue, history, nextId, hashTable);
                    break;
                    }
            case 8: {
                    categorySelectionOption(sortOrder, history, nextId, hashTable);
                    break;
                    }
            // Invalid option
            default: cout << "\n Invalid option." << endl; break;
        }
    }
}
// Log Selection Option
// Manages the linked list from the program which is access through option 6 in the selection option in the start
// Manages every log done by the user, such as adding and removing
void Inventory::logSelectionOption(HistoryList& history, int& nextId) {
    int historyChoice;
    while (true) {
        logMenu();
        while (!(cin >> historyChoice)) {
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Invalid input. Enter a number from the menu:" << endl;
            continue;
        }


        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (historyChoice == -1) {
            cout << "\nYou have return back to the main menu." << endl;
            break; 
        }

        switch (historyChoice) {

            case 1:
                history.Print();
                break;

            case 2: {
                cout << "Enter log ID to search: ";
                int targetId = getPositiveInt();
                history.SearchById(targetId);
                break;
            }
            case 3: {
                //Edge case, if the log is already empty
                if (history.isEmpty()) {
                    cout << "Log history is already empty." << endl;
                    break;
                }

                cout << "\nAre you sure you want to delete all the history? (1 = Yes, 0 = No): ";
                int confirm = getValidInt();
                if (confirm == 1) {
                    history.clearHistory("History.txt");
                    nextId = 1;
                }
                else if (confirm == 0) {
                    cout << "Clear logs Cancelled." << endl;
                }
                else {
                    cout << "Invalid input. Enter 1 or 0." << endl;
                    confirm = getValidInt();
                }
                break;
            }
            //Invalid option
            default: cout << "\n Invalid option." << endl; break;
        }
    }   
} 
// Delivery Selection Option 
// Manages the queue from the program accessed in option 7 in the selection option at the start
// Let/s the user interact with orders making sure that all the items arrived
void Inventory::deliverySelectionOption(DeliveryQueue& queue, HistoryList& history, int& nextId, HashTable& hashTable) {
    int deliveryChoice;
    
    while(true) {
        deliveryMenu();
        while (!(cin >> deliveryChoice)) {
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Invalid input. Enter a number from the menu:" << endl;
            continue;
        }


        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (deliveryChoice == -1) {
            cout << "\nYou have return back to the main menu." << endl;
            break; 
        }

        switch(deliveryChoice) {
            // Creates a new delivery ticket and sends it to the end of the queue
            case 1: {
                createTicket(queue);
                break;
            }
            // Process the items in the ticket and makes sure they all arrive
            case 2: {
                processTicket(queue, history, nextId, hashTable);
                break;
            }
            // Display all deliveries
            case 3: {
                queue.display();
                break;
            }
            // Search for a item in every ticket in the queue
            case 4: {
                searchQueue(queue);
                break;
            }
            // Invalid option 
            default: cout << "\n Invalid option." << endl; break;
        }
    }
}
// Category Selection Option
// Manages the Hash Table from the program and it's accessed in option 8 in the selection option at the start
// Let's the user interact with category and all the products that belong that that specific
void Inventory::categorySelectionOption(bool& sortOrder, HistoryList& history, int& nextId, HashTable& hashTable) {
    int categoryChoice;

    while (true) {
        categoryMenu();

        while(!(cin >> categoryChoice)) {
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Invalid input. Enter a number from the menu:" << endl;
            continue;
        }

        if (categoryChoice == -1) {
            cout << "\nYou have return back to the main menu." << endl;
            break; 
        }

        switch(categoryChoice) {
            case 1: {
                hashTable.display();
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                searchCategory(hashTable);
                break;
            }
            case 4: {
                string category;
                if (categoryExist(hashTable, category)) {
                    deleteCategory(sortOrder, history, nextId, hashTable, category);
                }
                break;
            }
            default: cout << "\n Invalid option." << endl; break;
                
        }
    }
}