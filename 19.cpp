// 19 Write a C++ program to create a Binary Search Tree for N nodes, and insert a given element

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

// Function to perform in-order traversal of the tree
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);  // Visit left subtree
        cout << root->data << " ";     // Visit node
        inorderTraversal(root->right); // Visit right subtree
    }
}

int main() {
    Node* root = nullptr;
    int N, data, newElement;

    // Input number of nodes
    cout << "Enter number of nodes: ";
    cin >> N;

    // Inserting nodes into the BST
    cout << "Enter the nodes to insert into the BST:\n";
    for (int i = 0; i < N; i++) {
        cin >> data;
        root = insert(root, data);
    }

    // Display the inorder traversal of the BST
    cout << "Inorder traversal of the BST before insertion: ";
    inorderTraversal(root);
    cout << endl;

    // Input the new element to insert
    cout << "Enter the element to insert: ";
    cin >> newElement;

    // Insert the new element into the BST
    root = insert(root, newElement);

    // Display the inorder traversal after insertion
    cout << "Inorder traversal of the BST after insertion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
