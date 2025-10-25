#include <iostream>
#include <stack>
using namespace std;



int main() {
  // LIFO last in first out ( заходит с конца выходит с начала
  // so first out means removes the last one
  // FIFO
  // It means that most recently inserted element is removed first and the first inserted element will be removed last.

  stack<int> numbers;

  numbers.push(5);
  numbers.push(13);
  numbers.push(9);
  numbers.push(83);

  numbers.pop();
  cout << numbers.top();
  

  // FIFO


  return 0;
}
