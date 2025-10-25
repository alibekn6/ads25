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

    if (value < current->data) {
      current->left = insertRecursive(current->left, value);
    }

    if (value > current->data) {
      current->right = insertRecursive(current->right, value);
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


  void inOrderRecursive(Node* current) {
    if (current != nullptr) {
      inOrderRecursive(current->left);
      cout << current->data << " ";
      inOrderRecursive(current->right);
    }
  }

public:
  BinarySearchTree() {
    root = nullptr;
  }

  ~BinarySearchTree() {
    destroyTree(root);
  }

  void insert(int value) {
    root = insertRecursive(root, value);
  }

  void displayInOrder() {
    cout << "In-order traversal: ";
    inOrderRecursive(root);
    cout << endl;
  }

  bool isPathAvaliable(const string path) {
    Node* current = root;
    for (char direction : path) {
      if (current == nullptr) {
        return false;
      }

      if (direction == 'L') {
        current = current->left;
      } else if (direction == 'R') {
        current = current->right;
      }
    }
    return current != nullptr;
  }
};



int main() {
  
  int n, m;
  cin >> n >> m;

  BinarySearchTree bst;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    bst.insert(value);
  }

  for (int i = 0; i < m; i++) {
    string path;
    cin >> path;

    if (bst.isPathAvaliable(path)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }





  return 0;
}
