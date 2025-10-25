#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    Node(string val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void add_front(string book) {
        Node* newNode = new Node(book);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "ok\n";
    }

    void add_back(string book) {
        Node* newNode = new Node(book);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "ok\n";
    }

    void erase_front() {
        if (!head) {
            cout << "error\n";
            return;
        }
        cout << head->data << "\n";
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void erase_back() {
        if (!tail) {
            cout << "error\n";
            return;
        }
        cout << tail->data << "\n";
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void front() {
        if (!head) {
            cout << "error\n";
        } else {
            cout << head->data << "\n";
        }
    }

    void back() {
        if (!tail) {
            cout << "error\n";
        } else {
            cout << tail->data << "\n";
        }
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "ok\n";
    }
};

int main() {
    DoublyLinkedList list;
    string command;

    while (cin >> command) {
        if (command == "add_front") {
            string book;
            cin >> book;
            list.add_front(book);
        } else if (command == "add_back") {
            string book;
            cin >> book;
            list.add_back(book);
        } else if (command == "erase_front") {
            list.erase_front();
        } else if (command == "erase_back") {
            list.erase_back();
        } else if (command == "front") {
            list.front();
        } else if (command == "back") {
            list.back();
        } else if (command == "clear") {
            list.clear();
        } else if (command == "exit") {
            cout << "goodbye\n";
            break;
        }
    }

    return 0;
}
