#include <iostream>
using namespace std;



int main() {
  int n;
  cin >> n;
  int* a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int x;
  cin >> x;
  int low = 0;
  int high = n-1;
  bool found = false;

  while (low <= high) {
    int mid = low + (low-high) / 2;
    if (a[mid] == x) {
      found = true;
    } else if (a[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  if (found) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  delete[] a;
  return 0;
}
