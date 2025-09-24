#include <iostream>
using namespace std;


class Queue {
private:
  int* data;
  int capacity;
  int currentSize;
  int head;
  int tail;
public:
  Queue(int size) {
    capacity = size;
    data = new int[capacity];
    head = 0;
    tail = 0;
    currentSize = 0;
  }

  ~Queue() {
    delete[] data;
  }

  void enqueue(int value) {
    if (isFull()) {
      cout << "Its full";
      return;
    }

    data[tail] = value;
    currentSize++;
    tail = (tail + 1) % capacity;
  }

  int dequeue() {
    if (isEmpty()) {
      cout << "Its empty";
      return 0;
    }
    int value = data[head];
    head = (head+1) % capacity;
    currentSize--;
    return value;
  }

  int front() {
    return data[head];
  }





  // enqueue
  // dequeue

  bool isEmpty() {
    return currentSize == 0;
  }

  int size() {
    return currentSize;
  }

  int isFull() const {
    return capacity == currentSize;
  }

};
int main() {

  Queue myQueue(5);

  myQueue.enqueue(1);
  myQueue.enqueue(90);
  myQueue.enqueue(36);
  myQueue.enqueue(44);
  myQueue.enqueue(95);

  while (!myQueue.isEmpty()) {
    cout << myQueue.dequeue();
  }





  return 0;
}
