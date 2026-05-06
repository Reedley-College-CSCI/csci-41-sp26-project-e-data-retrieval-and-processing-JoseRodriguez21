#ifndef QUEUE_ADT_H
#define QUEUE_ADT_H

#include <string>
using namespace std;

struct DeliveryTicket;

class QueueADT {
    public:
        virtual ~QueueADT() {}

        virtual void enqueue(DeliveryTicket* ticket) = 0;
        virtual DeliveryTicket* dequeue() = 0;
        virtual void returnToFront(DeliveryTicket* ticket) = 0;
        virtual bool isEmpty() const = 0;
        virtual void display() const = 0;
        virtual bool contains(const string& productName) const = 0;
        virtual void searchItem(const string& productName) const = 0;
};

#endif