#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node *prev;

  Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
  Node *head;
  Node *tail;
  int current_size;

public:
  Deque() : head(nullptr), tail(nullptr), current_size(0) {};
  

  ~Deque() {
    Node *current = head;
    while (current != nullptr) {
      Node *nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }


  void enqueueFront(int data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
      head = tail = newNode;
    } else {
      newNode -> next = head;
      head -> prev = newNode;
      head = newNode;
    }

    current_size++;
  }

  void enqueueBack(int data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
      head = tail = newNode;
    } else {
      tail -> next = newNode;
      newNode -> prev = tail;
      tail = newNode;
    }
    current_size++;
  }


  void dequeueFront() {
    if (isEmpty()) {
      cout << "Error";
    }

    Node* temp = head;
    if (head == tail) {
      head = tail = nullptr; // deque is empty;
    } else {
      head = head -> next;
      head->prev = nullptr;
    }
  }

  void dequeueBack() {
    if (isEmpty()) {
      cout << "Error";
    }
    Node* temp = tail;
    if (head == tail) {
      head = tail == nullptr; // empty
    } else {
      tail = tail -> prev;
      tail->next = nullptr;
    }

    current_size--;

  bool isEmpty() {};


};
