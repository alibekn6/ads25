#include <iostream>

struct Node {
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};


void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

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
    std::cin >> n;

    if (n == 0) {
        return 0;
    }

    // Build the linked list from user input.
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }


    if (head == nullptr || head->next == nullptr) {
        printList(head);
        deleteList(head);
        return 0;
    }
    
    
    Node* previous = head;
    Node* current = head->next;
    int position = 2;

    while (current != nullptr) {
        if (position % 2 == 0) {
            previous->next = current->next; 
            delete current;
            current = previous->next;
        } else {
            previous = current;
            current = current->next;
        }
        position++;
    }

    printList(head);

    deleteList(head);

    return 0;
}
