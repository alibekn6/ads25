#include <iostream>
#include <string>
struct Node {
  std::string data;
  Node *next;
  Node *prev;

  Node(std::string val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
  Node *head;
  Node *tail;
  int size;

public:
  DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

  ~DoublyLinkedList() { clear(); }

  void add_front(const std::string &bookName) {
    Node *newNode = new Node(bookName);
    if (isEmpty()) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    size++;
    std::cout << "ok" << std::endl;
  }

  void add_back(const std::string &bookName) {
    Node *newNode = new Node(bookName);
    if (isEmpty()) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    size++;
    std::cout << "ok" << std::endl;
  }

  void erase_front() {
    if (isEmpty()) {
      std::cout << "error" << std::endl;
      return;
    }
    Node *temp = head;
    std::cout << temp->data << std::endl;
    head = head->next;
    if (head != nullptr) {
      head->prev = nullptr;
    } else {
      tail = nullptr;
    }
    delete temp;
    size--;
  }

  void erase_back() {
    if (isEmpty()) {
      std::cout << "error" << std::endl;
      return;
    }
    Node *temp = tail;
    std::cout << temp->data << std::endl;
    tail = tail->prev;
    if (tail != nullptr) {
      tail->next = nullptr;
    } else {
      head = nullptr;
    }
    delete temp;
    size--;
  }

  void front() {
    if (isEmpty()) {
      std::cout << "error" << std::endl;
    } else {
      std::cout << head->data << std::endl;
    }
  }

  void back() {
    if (isEmpty()) {
      std::cout << "error" << std::endl;
    } else {
      std::cout << tail->data << std::endl;
    }
  }

  void clear() {
    while (head != nullptr) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
    tail = nullptr;
    size = 0;
  }

  void clear_command() {
    clear();
    std::cout << "ok" << std::endl;
  }

  bool isEmpty() const { return size == 0; }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  DoublyLinkedList bookList;
  std::string command;

  while (std::cin >> command && command != "exit") {
    if (command == "add_front") {
      std::string bookName;
      std::cin >> bookName;
      bookList.add_front(bookName);
    } else if (command == "add_back") {
      std::string bookName;
      std::cin >> bookName;
      bookList.add_back(bookName);
    } else if (command == "erase_front") {
      bookList.erase_front();
    } else if (command == "erase_back") {
      bookList.erase_back();
    } else if (command == "front") {
      bookList.front();
    } else if (command == "back") {
      bookList.back();
    } else if (command == "clear") {
      bookList.clear_command();
    }
  }

  std::cout << "goodbye" << std::endl;

  return 0;
}
