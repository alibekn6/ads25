#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* inserts(Node* head, int x, int p) {
    Node* newNode = new Node(x);

    if (p == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    for (int i = 0; i < p - 1 && curr; i++) {
        curr = curr->next;
    }

    if (curr) {
        newNode->next = curr->next;
        curr->next = newNode;
    }

    return head;
}

Node* remove(Node* head, int p) {
    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* curr = head;
    for (int i = 0; i < p - 1 && curr; i++) {
        curr = curr->next;
    }

    if (curr && curr->next) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    return head;
}

void print(Node* head) {
    if (!head) {
        cout << -1 << "\n";
        return;
    }

    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next) cout << " ";
        curr = curr->next;
    }
    cout << "\n";
}

Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2) return head;

    Node* prev1 = nullptr;
    Node* node1 = head;
    for (int i = 0; i < p1; i++) {
        prev1 = node1;
        node1 = node1->next;
    }

    if (prev1) {
        prev1->next = node1->next;
    } else {
        head = node1->next;
    }

    if (p2 == 0) {
        node1->next = head;
        return node1;
    }

    Node* curr = head;
    for (int i = 0; i < p2 - 1 && curr; i++) {
        curr = curr->next;
    }

    if (curr) {
        node1->next = curr->next;
        curr->next = node1;
    }

    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node* cyclic_left(Node* head, int x) {
    if (!head || x == 0) return head;

    Node* tail = head;
    int length = 1;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    x = x % length;
    if (x == 0) return head;

    Node* newTail = head;
    for (int i = 0; i < x - 1; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;

    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    if (!head || x == 0) return head;

    Node* tail = head;
    int length = 1;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    x = x % length;
    if (x == 0) return head;

    Node* newTail = head;
    for (int i = 0; i < length - x - 1; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;

    return newHead;
}

int main() {
    Node* head = nullptr;
    int command;

    while (cin >> command) {
        if (command == 0) {
            break;
        } else if (command == 1) {
            int x, p;
            cin >> x >> p;
            head = inserts(head, x, p);
        } else if (command == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        } else if (command == 3) {
            print(head);
        } else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (command == 5) {
            head = reverse(head);
        } else if (command == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        } else if (command == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }

    return 0;
}
