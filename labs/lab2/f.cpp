#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
  Node* head;
public:
  LinkedList(): head(nullptr) {}


  ~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
      Node* nextNode = current -> next;
      delete current;
      current = nextNode;
    }
  }

  void append(int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
      head = newNode;
      return;
    }

    Node* last = head;

    while (last -> next != nullptr) {
      last = last -> next;
    }

    last -> next = newNode;
  }

  void printList() {
    Node* current = head;
    while (current != nullptr) {
      cout << current -> data << " ";
      current = current -> next;
    }

    cout << endl;
  }

  void insertNode(int val, int position) {
    Node* newNode = new Node(val);
    
    if (position == 0) {
      newNode -> next = head;
      head = newNode;
      return;
    }

    Node* prev = head;

    for (int i = 0; i < position - 1 && prev != nullptr; i++) {
      prev = prev -> next;
    }

    newNode -> next = prev -> next;
    prev -> next = newNode;
  }


  Node* getHead() {
    return head;
  }

};

int main() {

  int n;
  cin >> n;

  LinkedList list;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    list.append(val);
  }

  int dataInsert;
  cin >> dataInsert;
  int posInsert;
  cin >> posInsert;

  list.insertNode(dataInsert, posInsert);
  list.printList();


    

  return 0;

}
