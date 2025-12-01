#include <iostream>
#include <vector>
#include <list>
using namespace std;


class HashTable {
private:
    int size;
    vector<list<int>> table;

    int hash(int key) {
        return key % size;
    }

public:
    HashTable(int size) {
        size = size;
        table.resize(size);
    }

    void insert(int key) {
        int index = hash(key);
        table[index].push_back(key);    
    }

    bool search(int key) {
        int index = hash(key);
        for (int k : table[index]) {
            if (k == key) {
                return true;
            }
        }

        return false;
    }


    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i].empty()) {
                cout << "empty";
            } else {
                for (int key : table[i]) {
                    cout << key << " -> ";
                }
                cout << "null";
            }

            cout << endl;
        }
    }
}