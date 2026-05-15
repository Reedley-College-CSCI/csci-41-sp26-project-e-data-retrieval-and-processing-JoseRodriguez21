#include "Inventory.h"

using namespace std;

// Adds a new product into the array. Aks for name, stock, price and category.
void Inventory::addProduct(bool sortOrder, HistoryList& history, int& nextId, HashTable& hashTable) {
    // Ask for the user for a product name
    string productName;
    cout << "Enter product name: ";
    getline(cin, productName);
    // Checks that the user didn't leave the line empty
    while (productName.empty()) {
        cout << "Product name can't be empty. Enter product name: ";
        getline(cin, productName);
    }
    // Search for the item to make sure it doesn't exist
    long long ops;
    int index = searchProduct(productName, ops, sortOrder);
    // if statement if the item already exists
    if (index != -1) {
        cout << "Product already exists. Enter amount to add to stock." << endl;
        // Ask the user for the extra amount
        int extraAmount = getPositiveInt();
        product[index].itemStock += extraAmount;
        //Displays to the user the updated amount
        cout << "Stock of " << productName << " updated new total: " << product[index].itemStock << endl; 
        // Log a restock
        Transaction log;
        // Info about the restock
        log.id = nextId++;
        log.action = "Restock";
        log.name = productName;
        log.quantity = extraAmount;
        // Inserts the info into the linked list and saves to history.txt file
        history.Prepend(log);
        history.saveHistory("History.txt");
    }
    // Else: the item doesn't exist create a new one
    else {
        // checks if the capacity can fit a new product
        if (count == capacity) resize();
        // Asks for the  stock of the product
        product[count].productName = productName;
        
        cout << "Enter stock quantity: ";
        product[count].itemStock = getPositiveInt();
        // Asks for the price of the product
        cout << "Enter price: ";
        product[count].price = getPositiveDouble();
        // Asks for the category of the product
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a category (one word only): ";
        getline(cin, product[count].category);
        // Kepps only one word for category
        stringstream ss(product[count].category);
        ss >> product[count].category;

        //Edge case in case the user inputs a empty category.
        if (product[count].category.empty()) {
            product[count].category = "Uncategorize";
        } 

        // Inserts into hash table by category
        hashTable.insert(product[count].category, productName);

        // Log a new item added
        Transaction log;

        // Info about the new item
        log.id = nextId++;
        log.action = "Added";
        log.name = product[count].productName;
        log.quantity = product[count].itemStock;

        //Inserts the info into the linked list and saves the history.txt file
        history.Prepend(log);
        history.saveHistory("History.txt");


        count++;
        cout << "Product added succesfully." << endl;
        sortByName(sortOrder);
    }

    updateData("Storage.txt");
}

// Deletes specific product that the user wants remove.
void Inventory::deleteProduct(const string& targetProduct, bool sortOrder, HistoryList& history, int& nextId, HashTable& hashTable) {
    if (count == 0) {
        cout << "Inventory empty." << endl;
        return;
    }

    long long opCount;
    int index = searchProduct(targetProduct, opCount, sortOrder);

    if (index == -1 || index >= count) {
        cout << targetProduct << " not found." << endl;
        return;
    }

    // Removes from the hash table before the array
    hashTable.removeProduct(product[index].category, product[index].productName);
    // Log a item deleted
    Transaction log;

    // Info about the deleted item
    log.id = nextId++;
    log.action = "Removed";
    log.name = product[index].productName;
    log.quantity = product[index].itemStock;

    //Inserts the info about the removed item into the linked list.
    history.Prepend(log);
    history.saveHistory("History.txt");


    for (int i = index; i < count - 1; i++) {
        product[i] = product[i + 1];
    }
    
    product[count - 1] = Products();

    count--;
    cout << targetProduct << " has been deleted." << endl;
    updateData("Storage.txt");
}

void Inventory::modifyProduct(bool& sortOrder, HistoryList& history, int& nextId, HashTable& hashTable) {
    // Checks that their are items inside the storage system
    if (count == 0) {
        cout << "Inventory empty." << endl;
        return;
    }

    // Displays all products numbered for the user to choose
    cout << "\nProduct List: " << endl;
    cout << string(40, '-') << endl;
    for (int i = 0; i < count; i++) {
        cout << " " << i + 1 << ". " << product[i].productName << endl;
    }
    cout << string(40, '-') << endl;
    // Ask the user for a product number to modify
    cout << "Enter product number to Modify (0 to cancel): ";
    int choice = getValidInt();

    // Returns if the user inputs 0
    if (choice == 0) {
        cout << "You have return back to the main menu." << endl;
        return;
    }
    // Makes sure the user enters a item inside the range
    while (choice < 1 || choice > count) {
        cout << "Invalid. Enter a number between 1 and " << count << ": ";
        choice = getValidInt();
    }
    // Index where the product is located
    int index = choice - 1;
    
    int modifyChoice;
    while (true) {
        cout << "\nModifying: " << product[index].productName << endl;
        cout << string(40, '-') << endl;
        cout << "  Stock:     " << product[index].itemStock << endl;
        cout << "  Price:     $" << fixed << setprecision(2) << product[index].price << endl;
        cout << "  Category:  " << product[index].category << endl;

        cout << string(40, '-') << endl;

        cout << " 1 - Change Price    " << endl;
        cout << " 2 - Change Stock    " << endl;
        cout << " 3 - Change Category " << endl;
        cout << " 4 - Change Name     " << endl;
        cout << "-1 - Back            " << endl;
        cout << string(40, '-') << endl;
        cout << "Enter choice:        " << endl;  

        while (!(cin >> modifyChoice)) {
            cin.clear();
            cout << "Invalid input. Enter a number: ";
        }

        if (modifyChoice == -1) {
            cout << "You have return back to the main menu." << endl;
            return;
        }

        switch (modifyChoice) {
            case 1: {
                // Asks for the user for a new price and makes sure it's positive
                cout << "Enter new price: $";
                double newPrice = getPositiveDouble();
                product[index].price = newPrice;
                cout << "Price updated to $" << fixed << setprecision(2) << newPrice << endl;
                // Saves the log into the history records
                Transaction log;
                log.id       = nextId++;
                log.action   = "Modifed";
                log.name     = product[index].productName;
                log.quantity = product[index].itemStock;
                history.Prepend(log);
                history.saveHistory("History.txt");
                updateData("Storage.txt");

                break;
                }
            case 2: {
                // Asks for the user for new stock and makes sure it's positive
                cout << "Enter new Stock: ";
                double newStock = getPositiveInt();
                product[index].itemStock = newStock;
                cout << "Stock updated to " << fixed << setprecision(2) << newStock << endl;
                // Saves the log into the history records
                Transaction log;
                log.id       = nextId++;
                log.action   = "Modifed";
                log.name     = product[index].productName;
                log.quantity = product[index].itemStock;
                history.Prepend(log);
                history.saveHistory("History.txt");
                updateData("Storage.txt");

                break;
                }
            case 3: {
                // Asks the user for a category
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string newCategory;
                cout << "Enter new category (one word only): ";
                getline(cin, newCategory);
                // only takes the first word
                stringstream ss(newCategory);
                ss >> newCategory;
                // If the category is left empty give a value
                if (newCategory.empty()) {
                    newCategory = "Uncategorized";
                }
                // Remove old category from hash table
                hashTable.removeProduct(product[index].category, product[index].productName);
                // Updates the category in the array to the new one
                string oldCategory = product[index].category;
                product[index].category = newCategory;
                // Inserts the product with the category into the hash table
                hashTable.insert(newCategory, product[index].productName);
                // Shows the category changed and the new one
                cout << product[index].productName << " moved from " << oldCategory << " to " << newCategory << endl;
                // Saves the log into the history records
                Transaction log;
                log.id       = nextId++;
                log.action   = "Modifed";
                log.name     = product[index].productName;
                log.quantity = product[index].itemStock;
                history.Prepend(log);
                history.saveHistory("History.txt");
                updateData("Storage.txt");

                break;
                }
            case 4: {
                // Asks the user for a new name
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string newName;
                cout << "Enter new product name: ";
                getline(cin, newName);
                // Checks if the name is empty
                while (newName.empty()) {
                    cout << "Name can't be empty. Enter product name: ";
                    getline(cin, newName);
                }
                // Updates the hash Table 
                hashTable.removeProduct(product[index].category, product[index].productName);
                hashTable.insert(product[index].category, newName);
                // Shows the user the new product name
                product[index].productName = newName;
                cout << "Product name updated to " << newName << endl;
                // Saves the log into the history records
                Transaction log;
                log.id       = nextId++;
                log.action   = "Modifed Name";
                log.name     = newName;
                log.quantity = product[index].itemStock;
                history.Prepend(log);
                history.saveHistory("History.txt");
                updateData("Storage.txt");
                // Updated index after sort 
                long long ops;
                index = searchProduct(newName, ops, sortOrder);
                break;
                } 
            default: 
                cout << "invalid Option. " << endl; 
                break;
        }
     
    }
}