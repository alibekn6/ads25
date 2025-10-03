#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int val) : data(val), next(nullptr);

}

// queue
//

class Queue {
private:
  Node *front;
  Node *rear;
  int size;

public:
  Queue() : front(nullptr), rear(nullptr), size(0) {}

  ~Queue() {
    while (!isEmpty()) {
      dequeue(); // Dequeue all elements to free memory
    }
  }

}


int main() {
  return 0;
}
