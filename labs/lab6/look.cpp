#include <iostream>
using namespace std;

int main() {

  int arr[26] = {0};


  char z = 'z';
  arr[z-'a']++;


  cout << z - 'a';


  for (int i = 0; i < 26; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
