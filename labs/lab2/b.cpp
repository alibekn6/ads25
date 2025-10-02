#include <iostream>
#include <string>

struct Node {
    std::string word;
    Node *next;
    Node(const std::string& w) : word(w), next(nullptr) {}
};

Node* shiftList(Node* head, int k) {
    if (!head || k == 0) {
        return head;
    }

    Node* current = head;
    int count = 1;

    while (count < k && current != nullptr) {
        current = current->next;
        count++;
    }

    Node* kthNode = current;
    Node* newHead = kthNode->next;

    current = newHead;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = head;
    kthNode->next = nullptr;

    return newHead;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->word;
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;
        Node* newNode = new Node(word);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* newHead = shiftList(head, k);

    printList(newHead);

    deleteList(newHead);

    return 0;
}
