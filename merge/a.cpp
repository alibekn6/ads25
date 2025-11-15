#include <iostream>
using namespace std;


void merge(vector<int>& arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;


  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // copying remaining elements;
  
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }


}

void mergeSort(vector<int>& arr, int left, int right) {
  if (left >= right)
    return;
  // 0 -> 3 | mid = 1;
  //
  int mid = left + (right - left) / 2;
  mergeSort(arr, left, mid); // mergeSort(arr, 0, 1); 
  mergeSort(arr, mid + 1, right); // mergeSort(arr, 2, 3);
  merge(arr, left, mid, right);
}


int main() {
  vector<int> arr;
  arr.push_back(38);
  arr.push_back(27);
  arr.push_back(43);
  arr.push_back(10);
  arr.push_back(33);
  arr.push_back(49);
  arr.push_back(11);
  arr.push_back(390);
  arr.push_back(32);
  arr.push_back(65);
  arr.push_back(192);
  arr.push_back(8);
  arr.push_back(49);

  int n = arr.size();
  // 38, 27, 43, 10
  mergeSort(arr, 0, n-1);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  cout << endl;

  return 0;
}
