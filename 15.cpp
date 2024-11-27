// 15 Write a C++ program to create a Binary Search Tree for N nodes, and implement recursive pre-order tree traversal, in-order tree traversal and post-order tree traversal

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

// Pre-order Traversal (Root, Left, Right)
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";  // Visit the root
        preorderTraversal(root->left);  // Traverse the left subtree
        preorderTraversal(root->right);  // Traverse the right subtree
    }
}

// In-order Traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);  // Traverse the left subtree
        cout << root->data << " ";  // Visit the root
        inorderTraversal(root->right);  // Traverse the right subtree
    }
}

// Post-order Traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);  // Traverse the left subtree
        postorderTraversal(root->right);  // Traverse the right subtree
        cout << root->data << " ";  // Visit the root
    }
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

    // Perform tree traversals
    cout << "\nPre-order Traversal: ";
    preorderTraversal(root);

    cout << "\nIn-order Traversal: ";
    inorderTraversal(root);

    cout << "\nPost-order Traversal: ";
    postorderTraversal(root);

    return 0;
}
