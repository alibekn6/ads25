#include <iostream>
using namespace std;


struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
  }
};

class BinarySearchTree {
private:
  Node* root;

  Node* insertRecursive(Node* current, int value) {
    if (current == nullptr) {
      return new Node(value);
    }

    if (value > current->data) {
      current->right = insertRecursive(current->right, value);
    } else if (value < current->data) {
      current->left = insertRecursive(current->left, value);
    }

    return current;
  }



  void destroyTree(Node* node) {
    if (node != nullptr) {
      destroyTree(node->left);
      destroyTree(node->right);
      delete node;
    }
  }

  int sizeRecursize(Node* node) {
    if (node == nullptr) {
      return 0;
    }

    return 1 + sizeRecursize(node->left) + sizeRecursize(node->right);
  }

  Node* findNodeRecursive(Node* current, int value) {
    if (current == nullptr || current->data == value) {
      return current;
    }

    if (value < current->data) {
      return findNodeRecursive(current->left, value);
    }

    return findNodeRecursive(current->right, value);
  }


public:
  BinarySearchTree() {
    root = nullptr;
  }

  ~BinarySearchTree() {
    destroyTree(root);
  }

  int getSize() {
    return sizeRecursive(root);
  }

  int getSubtreeSize(int value) {
    Node* subtreeRoot = findNodeRecursive(root, value);
    if (subtreeRoot == nullptr) {
      return 0;
    }

    return sizeRecursive(subtreeRoot);
  }

  void insert(int value) {
    root = onsertRecursive(root, value);
  }

  int getSubtreeSize(int value) {
    Node* subtreeRoot = findNodeRecursive(root, value);

    if (subtreeRoot == nullptr) {
      return 0;
    }

    return sizeRecursive(subtreeRoot);
  }
};



int main() {
  int n;
  cin >> n;
  BinarySearchTree bst;

  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    bst.insert(value);
  }

  int x;
  cin >> x;

  
  return 0;
}
