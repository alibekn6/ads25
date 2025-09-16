#include <iostream>
#include <queue>
using namespace std;


template <typename T>
class Queue {
private:
    // Node structure for the linked list
    struct Node {
        T data;
        Node* next;

        Node(T data) : data(data), next(nullptr) {}
    };

    Node* frontNode; // Pointer to the front of the queue
    Node* rearNode;  // Pointer to the back of the queue
    size_t count;    // Number of elements in the queue

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Add an element to the back of the queue
    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot dequeue from an empty queue.");
        }
        
        Node* temp = frontNode; // Temporarily store the front node
        frontNode = frontNode->next; // Move front to the next node
        
        // If the queue becomes empty after dequeue, reset rear as well
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        
        delete temp; // Free the memory of the old front node
        count--;
    }

    // Get the element at the front of the queue without removing it
    T& front() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot get front from an empty queue.");
        }
        return frontNode->data;
    }
    
    const T& front() const {
        if (isEmpty()) {
            throw std::runtime_error("Cannot get front from an empty queue.");
        }
        return frontNode->data;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return count == 0;
    }

    // Get the number of elements in the queue
    size_t size() const {
        return count;
    }
};

int main() {
    cout << "--- Linked List Queue Demo ---" << std::endl;
    Queue<int> myQueue;

    cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;

    cout << "Enqueuing 10, 20, 30..." << std::endl;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Queue size: " << myQueue.size() << std::endl;
    std::cout << "Front element: " << myQueue.front() << std::endl;

    std::cout << "Dequeuing..." << std::endl;
    myQueue.dequeue();

    std::cout << "Queue size: " << myQueue.size() << std::endl;
    std::cout << "Front element: " << myQueue.front() << std::endl;

    std::cout << "Enqueuing 40..." << std::endl;
    myQueue.enqueue(40);

    std::cout << "Dequeuing all elements..." << std::endl;
    while (!myQueue.isEmpty()) {
        std::cout << "Dequeuing " << myQueue.front() << std::endl;
        myQueue.dequeue();
    }

    std::cout << "Queue size: " << myQueue.size() << std::endl;
    std::cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}