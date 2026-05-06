#ifndef History_Linked_List_H
#define History_Linked_List_H

#include "ListADT.h"
#include "HistoryListNode.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class HistoryList : public ListADT {
    private:
        HistoryNode* head;
        HistoryNode* tail;

    public:
        HistoryList() {
            head = nullptr;
            tail = nullptr;
        }
        
        virtual ~HistoryList() {
            HistoryNode* currentNode = head;
            while (currentNode) {
                HistoryNode* toBeDeleted = currentNode;
                currentNode = currentNode->next;
                delete toBeDeleted;
            }
        }

        virtual void Prepend(Transaction item) override {
            PrependNode(new HistoryNode(item));
        }

        virtual void PrependNode(HistoryNode* newNode) {
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->next = head;
                head = newNode;
            }
        }

        virtual void Print() const override {   
            if (head == nullptr) {
                cout << "\nNo logs found." << endl;
                return;
            }

            HistoryNode* node = head;
            cout << endl;
            cout << left 
                 << setw(10) << "Id" 
                 << setw(12) << "Action"  
                 << setw(21) << "Product"  
                 << "Quantity" << endl;
            
            while (node) {
                cout << left << setw(10) << node->data.id 
                     << setw(12) << node->data.action
                     << setw(21) << node->data.name
                     << node->data.quantity << endl;
                node = node->next;
            }
            
        }
        
        virtual void SearchById(int targetId) {
            HistoryNode* current = head;
            bool found = false;

            while (current) {
                if (current->data.id == targetId) {
                    cout << "Found log: " << current->data.action << " " << current->data.name << endl; 
                    found = true;
                    break;
                }
                current = current->next;
            }
            if(!found) {
                cout << "Log Id: " << targetId << " wasn't found."  << endl;
            }
        
            
        }

        void saveHistory(const string& filename) const {
            ofstream historyFile(filename);

            if (!historyFile) {
                cout << "Error opening " << filename << " for uploading." << endl;
                return;
            }

            HistoryNode* current = head;
            while (current) {
                historyFile << current->data.id       << " "
                            << current->data.action   << " "
                            << current->data.quantity << " "
                            << current->data.name     << " " << endl;
                            current = current->next;
            }
            
            historyFile.close();

        }

        int loadHistory(const string& filename) {
            ifstream historyFile(filename);
            string line;
            int logCount = 0;
            

            if (!historyFile) {
                cout << "History text file couldn't be open successfully" << endl; 
                return 0;  
            }

            while(getline(historyFile, line)) {
                if (line.empty()) {
                    continue;
                }

                stringstream ss(line);
                Transaction log;

                if (!(ss >> log.id >> log.action >> log.quantity)) {
                    continue;
                }

                getline(ss, log.name);
                if (!log.name.empty() && log.name[0] == ' ') {
                    log.name = log.name.substr(1);
                    
                }
                Prepend(log);
                logCount++;
            }
            historyFile.close();
            cout << "Loaded " << logCount << " history logs." << endl;
            return logCount;
        }

        void clearHistory(const string& filename) {
            HistoryNode* current = head;
            while (current) {
                HistoryNode* toBeDeleted = current;
                current = current->next;
                delete toBeDeleted;
            }

            head = nullptr;
            tail = nullptr;

            ofstream historyFile(filename);
            historyFile.close();
        }
        
        bool isEmpty() const {
            return head == nullptr;
        }
};

#endif