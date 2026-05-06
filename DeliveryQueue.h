#ifndef DELIVERY_QUEUE_H
#define DELIVERY_QUEUE_H

#include "QueueADT.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

// A single item from the ticket
struct SingleItem {
    string productName;
    int stock;
    double price;
    string category;
    SingleItem* next;

    SingleItem(string productName, int stock, double price, string category) {
        this->productName = productName;
        this->stock = stock;
        this->price = price;
        this->category = category;
        next = nullptr;
    }
};

// Delivery ticket that uses a linked list of single items
struct DeliveryTicket {
    int ticketNumber;
    SingleItem* head;
    int itemCount;
    DeliveryTicket* next;

    DeliveryTicket(int id) {
        ticketNumber = id;
        head = nullptr;
        itemCount = 0;
        next = nullptr;
    }

    ~DeliveryTicket() {
        SingleItem*  current = head;
        while (current) {
            SingleItem* toBeDeleted = current;
            current = current->next;
            delete toBeDeleted;
        }
    }
    // Add items into the ticket
    void addItem(SingleItem* item) {
        if (head == nullptr) {
            head = item;
        }
        else {
            SingleItem* current = head;
            while (current->next) {
               current = current->next;
            }
            current->next = item;
        }
        itemCount++;
    }
};

class DeliveryQueue : public QueueADT {
    private: 
        DeliveryTicket* front;
        DeliveryTicket* back;
        int ticketCount;
        int nextTicketId;

    public: 
        DeliveryQueue();
        ~DeliveryQueue();

        int getNextTicketId() const;

        // Checks if the tickets contain a certain item, also tells in which ones
        // if there is more than one ticket.
        bool contains(const string& productName) const override;
        void searchItem(const string& productName) const override;

        //Makes sure the ticket is not empty
        virtual bool isEmpty() const override;

        void enqueue(DeliveryTicket* ticket) override;
        DeliveryTicket* dequeue() override;

        // Returns the ticket to the front of the queue
        void returnToFront(DeliveryTicket* ticket) override;
        
        // Displays all deliveries in progress
        void display() const override;

        //Loads and saves deliveries into the Deliveries.txt file
        void saveDeliveries(const string& filename) const;
        int loadDeliveries(const string& filename);
    
};


#endif