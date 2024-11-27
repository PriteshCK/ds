// 18 Write a C++ program to create a Binary Search Tree for N nodes, and search a given element.

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

// Function to search a given element in the BST
bool search(Node* root, int key) {
    // Base case: root is null or key is present at the root
    if (root == nullptr) {
        return false;
    }

    // If key is smaller than the root's data, search in the left subtree
    if (key < root->data) {
        return search(root->left, key);
    }
    // If key is greater than the root's data, search in the right subtree
    else if (key > root->data) {
        return search(root->right, key);
    }
    // If key is equal to the root's data, the key is found
    else {
        return true;
    }
}

int main() {
    Node* root = nullptr;
    int N, data, searchKey;

    // Input number of nodes
    cout << "Enter number of nodes: ";
    cin >> N;

    // Inserting nodes into the BST
    cout << "Enter the nodes to insert into the BST:\n";
    for (int i = 0; i < N; i++) {
        cin >> data;
        root = insert(root, data);
    }

    // Input the element to search
    cout << "Enter the element to search: ";
    cin >> searchKey;

    // Search for the element in the BST
    if (search(root, searchKey)) {
        cout << "Element " << searchKey << " found in the BST.\n";
    } else {
        cout << "Element " << searchKey << " not found in the BST.\n";
    }

    return 0;
}
