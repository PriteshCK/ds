// 16. Write a C++ program to create a Binary Search Tree for N nodes, and count and display all leaf nodes.

#include <iostream>
using namespace std;

// Structure to define a node of the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node in the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);  // Create a new node if the tree is empty
    }

    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert in the left subtree
    } else {
        root->right = insert(root->right, data);  // Insert in the right subtree
    }

    return root;
}

// Function to count and display all leaf nodes
int countLeafNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    // If the node has no children, it's a leaf node
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";  // Display the leaf node data
        return 1;
    }

    // Recursively count leaf nodes in both left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int N, data;

    // Input number of nodes
    cout << "Enter number of nodes: ";
    cin >> N;

    // Inserting nodes into the BST
    cout << "Enter the nodes to insert into the BST:\n";
    for (int i = 0; i < N; i++) {
        cin >> data;
        root = insert(root, data);
    }

    // Count and display all leaf nodes
    cout << "Leaf nodes in the BST: ";
    int leafCount = countLeafNodes(root);
    cout << "\nTotal number of leaf nodes: " << leafCount << endl;

    return 0;
}
