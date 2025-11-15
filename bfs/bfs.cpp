#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        while (isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(int val) {
        Node* newNode = new Node;
        newNode -> data = val;
        newNode -> next = nullptr;

        // if queue is empty
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear -> next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        Node* temp = front;
        int value = temp -> data;

        front = front -> next;

        // if queue becomes empty

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return value;
    }


    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue ";
        Node* temp = front;

        while (temp != nullptr) {
            cout << temp -> data << " ";
            temp = temp -> next;
        }

        cout << "\n";
    }
};


struct GraphNode {
    int vertex;
    GraphNode* next;
};

class Graph {

    
};

int main() {

    Queue q;
    cout << "==== Queue with pointers ==== \n\n";

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    q.display();

    cout << "removing";

    cout << q.dequeue();

    // first in first out



    // Now BFS



    return 0;
}