#include <iostream>
using namespace std;

// o(n);
int lin_search(int *arr, int n, int key) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      return i;
    }
  }

  return -1;
}

int bin_search(int *arr, int begin, int end, int key) {

  if (begin <= end) {

    int mid = (begin + end) / 2;

    if (arr[mid] == key) {
      return mid;
    }

    if (key < arr[mid]) {
      return bin_search(arr, begin, mid - 1, key);
    } else {
      return bin_search(arr, mid + 1, end, key);
    }
  }

  return -1;
}

int main() {

  int arr[7] = {1, 2, 3, 4, 5, 6, 7};

  int res = bin_search(arr, 0, 6, 5);
  cout << res;

  return 0;
}
