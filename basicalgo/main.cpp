#include <iostream>
#include <vector>
using namespace std;



void insertionSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key;
  }
}


// 12 11 13 5 6
// 11 12 13 5 6


void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {

  int arr[] = {5,2,4,6,1,3};

  int n = sizeof(arr) / sizeof(arr[0]);
  insertionSort(arr, n);
  printArray(arr, n);


  return 0;
}
