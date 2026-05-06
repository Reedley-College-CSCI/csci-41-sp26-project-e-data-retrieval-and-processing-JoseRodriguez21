#include "Inventory.h"

// Loads the data from the storage.txt file into the program.
void Inventory::loadData(const string& filename, HashTable& hashTable) {
    ifstream storageFile(filename);

    if (!storageFile) {
        cout << "Error opening Storage.txt." << endl;
        return;
    }

    count = 0;
    string line;

    while(getline(storageFile, line)) {
        if (line.empty()) {
            continue;
        }
        if (count == capacity) {
            resize();
        }
        stringstream ss(line);
        string words[20];
        int wordCount = 0;
        string word;

        while (ss >> word && wordCount < 20) {
            words[wordCount] = word;
            wordCount++;
        }
        
        if (wordCount < 4) continue;

        int stock = stoi(words[wordCount - 3]);
        double price = stod(words[wordCount - 2]);
        string category = words[wordCount - 1];

        string name = words[0];
        for (int i = 1; i < wordCount - 3; i++) {
            name += " " + words[i]; 
        }

        product[count].productName = name;
        product[count].itemStock = stock;
        product[count].price = price;
        product[count].category = category;
        // Creates the hash table when loading the items from the 
        // storage.txt file.
        hashTable.insert(category, name);

        count++;
    }

    storageFile.close();

    cout << "Loaded " << count << " products." << endl;
}

void Inventory::updateData(const string& filename) {
    ofstream storageFile(filename);

    if (!storageFile) {
        cout << "Error opening " << filename << " for uploading" << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        storageFile << product[i].productName << " "
                    << product[i].itemStock << " "
                    << product[i].price << " "
                    << product[i].category << endl;
    }

    storageFile.close();
    cout << "Data saved to " << filename << " successfully." << endl;
}