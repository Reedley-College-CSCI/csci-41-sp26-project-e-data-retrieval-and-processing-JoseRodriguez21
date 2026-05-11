#include "Inventory.h"

// Create Ticket: Makes a new delivery ticket that goes into the queue
void Inventory::createTicket(DeliveryQueue& queue) {
    // Create a new ticket with a unique Id
    DeliveryTicket* ticket = new DeliveryTicket(queue.getNextTicketId());
    cout << "\nCreating Delivery ticket #" << ticket->ticketNumber << endl;
    cout << "Add products to the ticket: " << endl;
    while(true) {
        // Askes the user for the product name
        string productName;
        cout << "\nEnter product name: ";
        getline(cin, productName);
        // Makes sure the product is not empty
        while (productName.empty()) {
            cout << "Product name can't be empty. Enter product name: ";
            getline(cin, productName);
        }
        // Asks the user for the quantity expected for deliver
        cout << "Enter quantity expected: ";
        int quantity = getPositiveInt();
        // Asks the user for the price
        cout << "Enter price: $";
        double price = getPositiveDouble();
        // Asks the user for the category
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string category;
        cout << "Enter category (one word only): ";
        getline(cin, category);
        // Keeps only the first word for category
        stringstream ss(category);
        ss >> category;

        // Gives a uncategorized value when left empty
        if (category.empty()) {
            category = "Uncategorized";
        }
        // Add the item to the ticket
        SingleItem* item = new SingleItem(productName, quantity, price, category);
        ticket->addItem(item);
        cout << '\n' << productName << " added to ticket." << endl;

        // Ask the user if they want to add another product
        cout << "Add another product? (yes = 1, no = 0): ";
        int another = getValidInt();
        // Makes sure the user inputs either 1 or 0
        while (another != 1 && another != 0) {
            cout << "Invalid number. Enter 1 or 0: ";
            another = getValidInt();
        }
        // Stops adding numbers into the delivery ticket
        if (another == 0) break;
    }
    // if the ticket is empty eliminate it
    if (ticket->head == nullptr) {
        cout << "No items added. Ticket cancelled." << endl;
        delete ticket;
    }
    // if the ticket has something add it to the queue and update it into the text file
    else {
        queue.enqueue(ticket);
        queue.saveDeliveries("Deliveries.txt");
        cout << "\nTicket #" << ticket->ticketNumber << " queued successfully." << endl;
    }
}

// Process ticket: The user process the ticket and sees if the stock did arrive
void Inventory::processTicket(DeliveryQueue& queue, HistoryList& history, int& nextId, HashTable& hashTable) {
    // Returns if the queue is empty
    if (queue.isEmpty()) {
        cout << "No pending deliveries." << endl;
        return;
    }
    // Brings the ticket from the front of the queue
    DeliveryTicket* ticket = queue.dequeue();
    cout << "\nProcessing ticket #" << ticket->ticketNumber << endl;
    cout << string(55, '-');
    // Sets ticket completion as true
    bool ticketComplete = true;
    SingleItem* item = ticket->head;

    while (item) {
        // Prints the product and expected amount
        cout << "\nProduct: " << item->productName << endl;
        cout << "Expected: " << item->stock << endl;
        // Asks the user how many items arrived
        cout << "How many arrived? ";
        int arrived = getValidInt();
        // Makes sure the value inputed is not negative
        while (arrived < 0) {
            cout << "Invalid. Enter a positive number: ";
            arrived = getValidInt();
        }
        // Edge case if more products were sent from the supplier
        if (arrived > item->stock) {
            cout << "\nWarning: Received more than expected. "
                 << "Expected " << item->stock << " but got " 
                 << arrived << endl;
        }
        if (arrived > 0) {
            // Search to see if the product already exists 
            long long ops;
            int index = searchProduct(item->productName, ops, true);
            // Updated the stock of existing product
            if (index != -1) {
                product[index].itemStock += arrived;
                cout << '\n' << item->productName << " stock updated. New total: "
                     << product[index].itemStock << endl;
            }
            // Added a new item into the inventory
            else {
                // Makes sure the array can hold the new product
                while (count == capacity) resize();
                // Adds the product into the inventory
                product[count].productName = item->productName;
                product[count].itemStock = arrived;
                product[count].price = item->price;
                product[count].category = item->category;
                count++;
                // Sorts the product and tells the user the item was added
                sortByName(true);
                hashTable.insert(item->category, item->productName);
                cout << item->productName << " added to inventory." << endl;
            }
            // Creates a history log from the items delivered
            Transaction log;
            log.id = nextId++; 
            log.action = "Delivery";
            log.name = item->productName;
            log.quantity = arrived;
            history.Prepend(log);
            // Makes the stock in the ticket equal to zero
            item->stock -= arrived;
        }
        // False even if only one product is not recieved        
        if (item->stock > 0) {
            ticketComplete = false;
        }
        // Moves to the next item
        item = item->next;
    }
    // Updates the files
    updateData("Storage.txt");
    history.saveHistory("History.txt");
    // Fully remove the ticket when the ticket is complete
    if (ticketComplete) {
        cout << "\nTicket #" << ticket->ticketNumber
             << " fully received. Ticket remove from queue completly."
             << endl;
        delete ticket;
    }
    else {
        SingleItem* current = ticket->head;
        SingleItem* previous = nullptr;
        // While: Checks that the items sent were the correct or some are missing
        while (current) {
            // If: the stock of the products sent was met
            if (current->stock == 0) {
                // Deletes the product and moves to the next one
                SingleItem* toBeDeleted = current;
                
                if (previous == nullptr) {
                    ticket->head = current->next;
                }
                else {
                    previous->next = current->next;
                }
                current = current->next;
                ticket->itemCount--;
                delete toBeDeleted;
            }
            // Else: If the order for that product wasn't met
            else {
                // Moves to the next product nothing is deleted.
                previous = current;
                current = current->next;
            }
        }
        // Returning the partial deliver ticket to the front of the queue
        cout << "\n Ticket #" << ticket->ticketNumber 
             << " partially delivered. Returning ticket to the front"
             << " of the queue" << endl;
             queue.returnToFront(ticket);
    }
    // Updating the deliveries text file
    queue.saveDeliveries("Deliveries.txt");
}
// Search item: User search for a item to see if it's on a ticket
// Also the user can see all the tickets were it's locates at

void Inventory::searchQueue(DeliveryQueue& queue) {
    // No deliveries pending
    if (queue.isEmpty()) {
        cout << "No pending deliveries." << endl;
        return;
    }
    // Ask the user for the product name to be search
    string productName;
    cout << "Enter product name to search: ";
    getline(cin, productName);
    // Check that the product name is not empty
    while (productName.empty()) {
        cout << "Product name can't be empty. Enter product name: ";
        getline(cin, productName);
    }
    // Uses the function in the queue file to search the product name.
    queue.searchItem(productName);
}