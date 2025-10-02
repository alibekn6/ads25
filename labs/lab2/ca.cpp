#include <iostream>
using namespace std;
// linked list zaibal
//
//

struct Node {
  int val;
  Node* next;

  // Node(int val) : val(val), next(nullptr) {}

  Node(int val) {
    this->val = val;
    this->next = nullptr;

  }

};


class LinkedList {
private:
  Node* head;
  
}

int main() {

  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);

  head->next = second;
  second->next = third;

  cout << "Printing linked list :";
  Node* current = head;
  while (current != nullptr) {
    cout << current->val << " ";
    current = current->next;
  }

  cout << endl;


  // DELETING THE LINKED LIST
  //
  
  cout << "Deleting the nodes :" << endl;
  current = head;
  while (current != nullptr) {
    Node* nodeDelete = current;
    current = current->next;
    delete nodeDelete;
  }

  cout << "Done !" << endl;


  return 0;
}
