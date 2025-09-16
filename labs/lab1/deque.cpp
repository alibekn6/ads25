#include <iostream>
using namespace std;

class Deque {
private:
  int *data;
  int capacity;
  int currentSize;
  int head;
  int tail;

public:
  Deque(int size) {
    if (size <= 0) {
      throw std::invalid_argument("Размер должен быть положительным числом");
    }

    capacity = size;
    data = new int[capacity];
    currentSize = 0;
    tail = 0;
    head = 0;
  }

  ~Deque() { delete[] data; }

  void push_back(int value) {
    if (isFull()) {
      cout << "Ошибка: Дек полон!" << endl;
      return;
    }

    data[tail] = value;
    tail = (tail + 1) % capacity;
    currentSize++;
  }

  int pop_back() {
    if (isEmpty()) {
      throw std::runtime_error("Ошибка: Дек пуст!");
    }

    tail = (tail - 1 + capacity) % capacity;
    int value = data[tail];
    currentSize--;

    return value;
  }

  int pop_front() {
    if (isEmpty()) {
      throw std::runtime_error("Ошибка: Дек пуст!");
    }
    int value = data[head];
    head = (head + 1) % capacity;
    currentSize--;
    return value;
  }

  int front() {
    if (isEmpty()) {
      throw std::runtime_error("Ошибка: Дек пуст!");
    }
    return data[head];
  }

  int back() {
    if (isEmpty()) {
      throw std::runtime_error("Ошибка: Дек пуст!");
    }
    return data[(tail - 1 + capacity) % capacity];
  }

  void push_front(int value) {
    if (isFull()) {
      cout << "Ошибка: Дек полон!" << endl;
      return;
    }

    head = (head - 1 + capacity) % capacity;
    data[head] = value;
    currentSize++;
  }

  bool isFull() { return capacity == currentSize; }

  bool isEmpty() { return currentSize == 0; }

  int size() const { return currentSize; }
};

int main() {
  cout << "sfd";
  return 0;
}
