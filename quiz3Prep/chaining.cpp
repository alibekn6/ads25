#include <vector>
#include <list>
#include <iostream>
using namespace std;



class HashTableChaining {
private:
    int table_size;
    vector<list<int>> table; // each slot is linked list
    
    int hash(int key) {
        return key % table_size;
    }

public:
    HashTableChaining(int size) {
        table_size = size;
        table.resize(size);
    }

    void insert(int key) {
        int index = hash(key);
        table[index].push_back(key);
        cout << "Inserted " << key << " at index " << index << endl;
    }

    void search(int key) {
        int index = hash(key);
        for (int x : table[index]) {
            if (x == key) return true
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        table[index].remove(key)
    }


    void display() {
        cout << "===== Hash Table ====="
        for (int i = 0; i < table_size; i++) {
            cout << "Slot " << i << ": ";
            if (table[i].empty()) {
                cout << "empty";
            } else {
                for (int key : table[i]) {
                    cout << key << " -> ";
                }
                cout << "NULL";
            }
            cout << endl;
        }
        cout << "==================\n" << endl;
    }

    double loadFactor() {
        int total_elements = 0;
        for (auto& chain : table) {
            total_elements += chain.size();
        }
        return (double)total_elements / table_size;
    }

};

void solveQuizQuestion1() {
    cout << "=== Quiz Question 1: Chaining with 7 slots ===" << endl;
    HashTableChaining ht(7);
    
    vector<int> keys = {5, 28, 19, 15, 20, 33, 12, 17, 10};
    
    for (int key : keys) {
        ht.insert(key);
    }
    
    ht.display();
    cout << "Load factor: " << ht.loadFactor() << endl;
}


int main () {



    return 0;
}