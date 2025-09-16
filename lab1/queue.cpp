#include <iostream>
using namespace std;

class Queue{
private:
  int* data;
  int capacity;
  int currentSize;
  int head;
  int tail;

public:
  Queue(int size) {
    if (size <= 0) {
      throw std::invalid_argument("Размер должен быть положительным числом");
    }
    capacity = size;
    data = new int[capacity];
    currentSize = 0;
    head = 0;
    tail = 0;
  }

  ~Queue() {
    delete[] data;
  }

  void enqueue(int value) {
    if (isFull()) {
      cout << "Ошибка: Очередь полна!" << endl;
      return;
    }

    data[tail] = value;
    tail = (tail + 1) % capacity;
    currentSize++;
  }

  int dequeue() {
    if (isEmpty()) {
      throw std::runtime_error("Ошибка: Очередь пуста!");
    }

    int value = data[head];
    head = (head + 1) % capacity;
    currentSize--;
    return value;

  }

  int front() {
    if (isEmpty()) {
      throw std::runtime_error("Ошибка: Очередь пуста!");
    }
    return data[head];
  }



  bool isFull() const {
    return currentSize == capacity;
  }

  bool isEmpty() {
    return currentSize == 0;
  }

  int size() const {
    return currentSize;
  }

};

int main() {

  Queue myQueue(3);
  myQueue.enqueue(1);
  myQueue.enqueue(5);
  myQueue.enqueue(99);
  // 5 99
  //  1 5 
  
  while (!myQueue.isEmpty()) {
    cout << myQueue.dequeue() << " ";
  }
  


  cout << endl;

  return 0;
}
