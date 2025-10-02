#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

struct LinkedList {
    Node* head;
    
    LinkedList() {
        this->head = nullptr;
    }

    Node* inserts(Node* head, int x, int p) {
        Node* newNode = new Node(x);

        if (p == 0) {
            newNode->next = head;
            return newNode;
        }

        Node* prev = head;
        for (int i = 0; i < p - 1; ++i) {
            prev = prev->next;
        }

        newNode->next = prev->next;
        prev->next = newNode;
        return head;
    }

    Node* remove(Node* head, int p) {
        if (!head) return nullptr;

        if (p == 0) {
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return head;
        }

        Node* prev = head;
        for (int i = 0; i < p - 1; ++i) {
            prev = prev->next;
        }

        Node* nodeToDelete = prev->next;
        prev->next = nodeToDelete->next;
        delete nodeToDelete;
        return head;
    }

    void print(Node* head) {
        if (!head) {
            cout << -1 << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->val;
            if (current->next) {
                cout << " ";
            }
            current = current->next;
        }
        cout << endl;
    }

    Node* replace(Node* head, int p1, int p2) {
        if (p1 == p2) return head;

        Node* nodeToMove;
        if (p1 == 0) {
            nodeToMove = head;
            head = head->next;
        } else {
            Node* prev1 = head;
            for (int i = 0; i < p1 - 1; ++i) {
                prev1 = prev1->next;
            }
            nodeToMove = prev1->next;
            prev1->next = nodeToMove->next;
        }
        
        if (p2 == 0) {
            nodeToMove->next = head;
            return nodeToMove;
        }
        
        Node* prev2 = head;
        for (int i = 0; i < p2 - 1; ++i) {
            prev2 = prev2->next;
        }
        nodeToMove->next = prev2->next;
        prev2->next = nodeToMove;

        return head;
    }

    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    Node* cyclic_left(Node* head, int x) {
        if (!head || !head->next || x == 0) return head;
        
        int len = 1;
        Node* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        
        tail->next = head;

        Node* newTail = head;
        for (int i = 0; i < x - 1; i++) {
            newTail = newTail->next;
        }

        Node* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }

    Node* cyclic_right(Node* head, int x) {
        if (!head || !head->next || x == 0) return head;
        
        int len = 1;
        Node* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        tail->next = head;
        
        int steps_to_new_tail = len - x - 1;
        Node* newTail = head;
        for (int i = 0; i < steps_to_new_tail; i++) {
            newTail = newTail->next;
        }

        Node* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};

int main() {
    LinkedList list;
    int command;
    
    while (cin >> command && command != 0) {
        if (command == 1) {
            int x, p;
            cin >> x >> p;
            list.head = list.inserts(list.head, x, p);
        } else if (command == 2) {
            int p;
            cin >> p;
            list.head = list.remove(list.head, p);
        } else if (command == 3) {
            list.print(list.head);
        } else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            list.head = list.replace(list.head, p1, p2);
        } else if (command == 5) {
            list.head = list.reverse(list.head);
        } else if (command == 6) {
            int x;
            cin >> x;
            list.head = list.cyclic_left(list.head, x);
        } else if (command == 7) {
            int x;
            cin >> x;
            list.head = list.cyclic_right(list.head, x);
        }
    }

    return 0;
}
