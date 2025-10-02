#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

// Nearest number

int main() {


  int n;
  cin >> n;

  int arr[n];


  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    arr[i] = input;
  }

  int k;
  int nearest_offset;
  int min_diff = INT_MAX;

  cin >> k;

  for (int i = 0; i < n; i++) {
    int current_diff = abs(arr[i] - k);
    if (current_diff < min_diff) {
      min_diff = current_diff;
      nearest_offset = i;
    }
  }

  cout << nearest_offset;



  return 0;
}
