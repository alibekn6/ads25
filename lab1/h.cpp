#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool is_prime = true;

  if (n == 1 || n == 0) {
    is_prime = false;
  }

  for (int i = 2; i <= n/2; i++) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }

  if (is_prime) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
