#include "DeliveryQueue.h"

// Constructor:
// Constructor for DeliveryQueue which gives starting values
DeliveryQueue::DeliveryQueue() {
    front = nullptr;
    back = nullptr;
    ticketCount = 0;
    nextTicketId = 0;
}

// Destructor:
// Destructor to automatically delete the information in the queue when exiting the program
DeliveryQueue::~DeliveryQueue() {
    while (front) {
        DeliveryTicket* toBeDeleted = front;
        front = front->next;
        delete toBeDeleted;
    }
}

// getNextTicketId function: Adds one to the current Id to give a new id to the new ticket
int DeliveryQueue::getNextTicketId() const {
    return nextTicketId + 1;
}

// Contains function:
// Checks if a certain product has pending deliveries.
bool DeliveryQueue::contains(const string& productName) const {
    DeliveryTicket* current = front;
    // Goes through every ticket and product comparing it to the key
    // if found returns true and if not returns flase
    while (current) {
        SingleItem* item = current->head;
        while (item) {
            if (item->productName == productName) {
                return true;
            }
            item = item->next;
        }
        current = current->next;
    }
    return false;
}

// search Item function:
// Finds all the tickets that have a certain item 
void DeliveryQueue::searchItem(const string& productName) const {
    DeliveryTicket* current = front;
    bool found = false;
    // First while loop goes through every ticket
    while (current) {
        SingleItem* item = current->head;
        // Second while loop goes through every product in that ticket.
        while (item) {
            if (item->productName == productName) {
                // Prints the product and says it was found (only once).
                if (!found) {
                    cout << "\n" << productName << " found in: " << endl;
                    found = true;
                }
                // Displays a message with the ticket number and stock.
                cout << "    Ticket #" << current->ticketNumber << " - "
                << item->stock << " units pending" << endl;
                break;
            } 
            item = item->next;
        }
        current = current->next;
    }
        // Displays a message if there were no products in the delivery list.
        if (!found) {
            cout << productName << " is not in any pending deliveries." << endl;
        }
}

//isEmpty function: Checks if their are no deliveries schedule in the list
bool DeliveryQueue::isEmpty() const {
    return front == nullptr;
}

// Enqueue function: Adds a new ticket to the back of the queue
void DeliveryQueue::enqueue(DeliveryTicket* ticket) {
    
    // Checks if there is nothing in the queue
    if (back == nullptr) {
        front = ticket;
        back = ticket;
    }
    // else it makes this new ticket the new back of the queue
    else {
        back->next = ticket;
        back = ticket;
    }
    ticketCount++;
    nextTicketId++;
}

// Deque function: Removes a ticket from the front of the queue
DeliveryTicket* DeliveryQueue::dequeue() {
    // If the queue deliveries is empty it tells the user there are no pending deliveries to remove.
    if (isEmpty()) {
        cout << "\nNo pending deliveries." << endl;
        return nullptr;
    } 

    DeliveryTicket* ticket = front;
    front = front->next;

    // Checks if the next in the queue is empty, if it is then there are no more tickets in the queue.
    if (front == nullptr) {
        back = nullptr;
    }

    // Removes one from ticket count and sends the ticket to the user to verify that they got all the items.
    ticket->next = nullptr;
    ticketCount--;
    return ticket;
}

// returnToFront function:
// Returns the ticket to the front of the queue if the user didn't recieve all the products.
void DeliveryQueue::returnToFront(DeliveryTicket* ticket) {
    // Sets the old front second in line
    ticket->next = front;
    front = ticket;

    // If there are no tickets behind the one added back becomes the only one
    if (back == nullptr) {
        back = ticket;
    }

    ticketCount++;
}

// Display function:
// Shows all pending tickets to the user
void DeliveryQueue::display() const {
    // Returns if there is no deliveries to display.
    if (isEmpty()) {
        cout << "No pending deliveries." << endl;
        return;
    }

    cout << "\n        Pending Deliveries        " << endl;
    cout << string(55, '-') << endl;

    DeliveryTicket* current = front;
    while(current) {
        // Prints the ticket number
        cout << "Ticket #" << current->ticketNumber << endl;
        // Prints the headers: Product, Stock, Price and Category
        cout << left
             << setw(20) << "  Product"
             << setw(10) << "Stock"
             << setw(12) << "Price"
             << "Category" << endl;
        cout << "  " << string(53, '-') << endl;
        
        SingleItem* item = current->head;
        // Prints the information from the product
        while(item) {
            cout << "  " << left
                 << setw(20) << item->productName
                 << setw(10) << item->stock
                 << "$" << setw(11) << fixed 
                 << setprecision(2) << item->price
                 << item->category  << endl;
            // Moves to the next product      
            item = item->next;
        }
        // Ends the ticket by adding a line and moves to the next ticket
        cout << string(55, '-') << endl;
        current = current->next;
    }

}

void DeliveryQueue::saveDeliveries(const string& filename) const {
    ofstream deliveryFile(filename);

    // If statement that makes sure the file was open 
    if (!deliveryFile) {
        cout << "Error opening " << filename << endl;
        return;
    }

    DeliveryTicket* current = front;

    while (current) {
        // Saves ticket number and number of items in the ticket
        deliveryFile << "TICKET " << current->ticketNumber << " " << current->itemCount << endl;
        //Starts at the first item in the ticket
        SingleItem* item = current->head;
        // Saves the information about each product
        while (item) {
            deliveryFile << item->productName << " "
                         << item->stock << " "
                         << item->price << " "
                         << item->category << endl;
            item = item->next;
        }
        // Moves to the next ticket after reading all items
        current = current->next;
    }
    deliveryFile.close();
}

int DeliveryQueue::loadDeliveries(const string& filename) {
    ifstream deliveryFile(filename); 
    int loaded = 0;
    string line;

    // If statement making sure the file was open
    if (!deliveryFile) {
        cout << "Error opening " << filename << endl;
        return 0;
    }

    while (getline(deliveryFile, line)) {
        string key;
        // Skips empty line 
        if (line.empty()) continue;

        stringstream ss(line);
        ss >> key;
        // Skips line if the key word is not found
        if (key != "TICKET") continue;
        
        int ticketId;
        int itemCount;

        // Makes sure their are two numbers for ID and ticket count if not continues
        if (!(ss >> ticketId >> itemCount)) continue;

        DeliveryTicket* ticket = new DeliveryTicket(ticketId);

        for (int i = 0; i < itemCount; i++) {
            // String to save the line
            string itemLine;
            if (!getline(deliveryFile, itemLine)) break;
            // Makes sure the line is not empty
            if (itemLine.empty()) continue;

            stringstream itemSS(itemLine);
            string words[20];
            int wordCount = 0;
            string word;

            // One word at the time from the line
            while (itemSS >> word && wordCount < 20) {
                words[wordCount++] = word;
            }

            // Makes sure there are 4 words in the line if not continues
            if (wordCount < 4) continue;
            
            int stock = stoi(words[wordCount - 3]);
            double price = stod(words[wordCount - 2]);
            string category = words[wordCount - 1];
            string productName = words[0];

            for (int j = 1; j < wordCount - 3; j++) {
                productName += " " + words[j];
            }
            // Creates a new item and adds it into the ticket
            SingleItem* item = new SingleItem(productName, stock, price, category);
            ticket->addItem(item);
        }

        // Tracks the ids from the items being inputed.
        if (ticket->head != nullptr) {
            enqueue(ticket);
            loaded++;

            if (ticketId > nextTicketId) {
                nextTicketId = ticketId;
            }
        }
        else {
            delete ticket;
        }
    }
    // Closes the file and returns the loaded amount
    deliveryFile.close();
    cout << "Loaded " << loaded << " pending deliveries." << endl;
    return loaded;
}
