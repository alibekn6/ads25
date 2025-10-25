#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string val) : data(val), next(nullptr) {}
};

Node* shiftList(Node* head, int k) {
    if (!head || k == 0) return head;

    Node* tail = head;
    int length = 1;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    k = k % length;
    if (k == 0) return head;

    Node* newTail = head;
    for (int i = 0; i < k - 1; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;

    return newHead;
}

int main() {
    int n, k;
    cin >> n >> k;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        Node* newNode = new Node(word);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = shiftList(head, k);

    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next) cout << " ";
        curr = curr->next;
    }
    cout << "\n";

    return 0;
}
