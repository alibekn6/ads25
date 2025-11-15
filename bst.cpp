#include <vector>
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class bst {
private:
    Node* root;
public:
    bst() {
        root = NULL;
    }

    void insert(Node* current, int data) {
        if (root == nullptr) {
            root = new Node(data);
            return;
        }

        if (current -> val == data) {
            return;
        }

        if (current -> val < data) {
            if (current -> right == nullptr) {
                current -> right = new Node(data);
                return;
            }
            insert(current -> right, data);
            
        }
    }
}


int main () {


    return 0;
}