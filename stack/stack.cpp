#include <iostream>
using namespace std;


class Stack {
  int *arr;
  int top;
  int capacity;

public:
  Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
  }

  void push(int value) {
    if (top == capacity - 1) {
      cout << "Stack Overflow\n";
      return;
    }
    arr[++top] = value;
  }

  int pop() {
    if (top == -1) {
      cout << "Stack is empty\n";
      return -1;
    }

    return arr[top--];
  }

  int peek() {
    if (top == -1) {
      cout << "Stack is empty\n";
      return -1;
    }
    return arr[top];
  }

  bool isEmpty() {
    return top == -1;
  }

};


int main() {

  Stack st(5);

  st.pop();





  return 0;
}
