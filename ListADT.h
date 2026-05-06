#ifndef LIST_ADT_H
#define LIST_ADT_H

#include <iostream>
#include <string>

using namespace std;

struct Transaction {
    int id;
    string action;
    string name;
    int quantity;
};

class ListADT {
    public: 
    virtual ~ListADT() {}

    virtual void Prepend(Transaction item) = 0;
    virtual void Print() const = 0;

};

#endif