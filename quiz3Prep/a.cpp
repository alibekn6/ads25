#include <iostream>
#include <vector>
using namespace std;





int main() {
  const int TABLE_SIZE = 7;
  vector<int> hashTable[TABLE_SIZE];


  int keys[] = {5, 28, 19, 15, 20, 33, 12, 17, 10};


  int n = 9;

  for (int i = 0; i < n; i++) {
    int key = keys[i];
    int index = key % TABLE_SIZE;
    hashTable[index].push_back(key);
    cout << "Insert " << key << " at index " << index << endl;
  }

  cout << "\nFinal Hash Table:\n";

  for (int i = 0; i < TABLE_SIZE; i++) {
    cout << "Slot " << i << ": ";
    for (int j = 0; j < hashTable[i].size(); j++) {
      cout << hashTable[i][j];
      if (j < hashTable[i].size() - 1) cout << " -> ";
    }
    cout << endl;
  }


  return 0;
}
