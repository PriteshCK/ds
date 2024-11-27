// 20 Write a C++ program to create a Binary Search Tree for N nodes, and delete a specified node.

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

// Function to find the minimum value node in a given subtree
Node* minNode(Node* root) {
    Node* current = root;
    while (current && current->left != nullptr) {
        current = current->left;  // Keep moving to the left
    }
    return current;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int key) {
    // Base case: If the tree is empty
    if (root == nullptr) {
        return root;
    }

    // Recur down the tree to find the node to be deleted
    if (key < root->data) {
        root->left = deleteNode(root->left, key);  // Delete in the left subtree
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);  // Delete in the right subtree
    } else {
        // This is the node to be deleted

        // Case 1: Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        // Get the inorder successor (smallest in the right subtree)
        Node* temp = minNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
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
    int N, data, deleteKey;

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
    cout << "Inorder traversal of the BST before deletion: ";
    inorderTraversal(root);
    cout << endl;

    // Input the key to be deleted
    cout << "Enter the value to delete: ";
    cin >> deleteKey;

    // Delete the node from the BST
    root = deleteNode(root, deleteKey);

    // Display the inorder traversal after deletion
    cout << "Inorder traversal of the BST after deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
