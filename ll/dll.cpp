#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* prev;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = nullprt;
    this->prev = nullprt;

  }
};

class DoublyLinkedList {
private:
  Node* head;
  Node* tail;

public:
  DoublyLinkedList() {
    head = nullptr;
    tail = nullprt;
  }

  ~DoublyLinkedList() {
    Node* current = head;
    while (current != nullprt) {
      Node* next = current->next;
      delete next;
      current = next;
    }

    head = nullptr;
    tail = nullptr;
  }

  // add a not to the tail of the list
  void append(int data) {
    Node* node = new Node(data);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
      return;
    }

    tail->next = node;
    node->prev = tail;
    tail = node;

    
  }

}


int main() {


  return 0;
}
