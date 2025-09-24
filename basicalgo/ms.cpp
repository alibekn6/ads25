#include <iostream>
using namespace std;

void mergeSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j = j - 1;
    }
    arr[j+1] = key;
  }
}

void print(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {

  int data[] = {5,2,34,1,3,9,13,45,2,-3};
  int size = sizeof(data) / sizeof(data[0]);
  mergeSort(data, size);
  print(data, size);

  return 0;
}

