#include <iostream>
#include <string>
using namespace std;

struct Node {
  std::string data;
  Node *next;
  Node *prev;

  // Constructor to initialize a node
  Node(std::string val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
  Node* head;
  Node* tail;
  int size;

public:
  DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
  ~DoublyLinkedList () {
    clear();
  }

  void add_front(const string bookName) {
    Node* newNode = new Node(bookName);
    if (isEmpty()) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    size++;
    cout << "ok" << endl;
  }


}


int main() { return 0; }
