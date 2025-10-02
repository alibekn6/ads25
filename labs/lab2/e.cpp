#include <iostream>
using namespace std;
#include <string>


struct Node {
  string name;
  Node* next;

  Node(const string& n) : name(n), next(nullptr) {}
};

void deleteList(Node* head) {
  Node* current = head;
  while (current != nullptr) {
    Node* nextNode = current->next;
    delete current;
    current = nextNode;
  }
}



int main() {

  int n;
  cin >> n;

  Node* head = nullptr;

  for (int i = 0; i < n; i++) {
    string currentName;
    cin >> currentName;
    if (head == nullptr || head -> name != currentName) {
      Node* newNode = new Node(currentName);
      newNode->next = head;
      head = newNode;
    }
  }

  int studentCount = 0;
  Node* counter = head;
  while (counter != nullptr) {
    studentCount++;
    counter = counter->next;
  }

  cout << "All in all: " << studentCount << "\n";
  cout << "Students:\n";

  Node* printer = head;

  while (printer != nullptr) {
    cout << printer -> name << "\n";
    printer = printer->next;
  }

  deleteList(head);

  return 0;
}
