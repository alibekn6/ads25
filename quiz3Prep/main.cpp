#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

// 10, 5, 5, 
void merge(int arr[], int left, int right, int mid) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int L[n1];
  int R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }

  for (int j = 0; j < n2; j++) {
    R[j] = arr[right + j];
  }

  int i = 0; 
  int j = 0;
  int k = left;
  // 
  while (i < n1 && j < n2) {
    if (L[i] >= R[j]) {
      arr[k] = 
    }
  }


}

class HashTable {
private:
  int SIZE;
  vector<list<pair<string, int>>> table;

  int hash(string key) {
    int hash = 0;
    for (char c : key) {
      hash += c;
    }
    return hash % SIZE;
  }

public:
  HashTable(int size) {
    SIZE = size;
    table.resize(size);
  }

  void insert(string key, int value) {
    int index = hash(key);

    for (auto &pair : table[index]) {
      if (pair.first == key) {
        pair.second == value;
        return;
      }

      table[index].push_back({key, value});
    }

    int search(string key) {
      int index = hash(key);

      for (auto &pair : table[index]) {
        if (pair.first == key) {
          return pair.second;
        }
      }

      return -1; // not found
    }
  }
};

int main() { return 0; }
