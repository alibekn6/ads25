#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int findMaxSum(Node* head) {
    if (!head) return 0;

    int maxSum = INT_MIN;
    int currentSum = 0;

    Node* curr = head;
    while (curr) {
        currentSum += curr->data;
        maxSum = max(maxSum, currentSum);

        if (currentSum < 0) {
            currentSum = 0;
        }

        curr = curr->next;
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << findMaxSum(head) << "\n";

    return 0;
}
