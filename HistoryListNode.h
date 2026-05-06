#ifndef History_List_Node_h
#define History_List_Node_h

#include "ListADT.h"

using namespace std;

struct HistoryNode {
    Transaction data;
    HistoryNode* next;

    HistoryNode(Transaction val) {
        data = val;
        next = nullptr;
    }

};


#endif
