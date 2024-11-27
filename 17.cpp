// 17. Write a C++ program to create a Binary Search Tree for N nodes, Enlist all the nodes with data having less than zero.

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

// Function to traverse the tree and list nodes with data less than zero
void listNegativeNodes(Node* root) {
    if (root != nullptr) {
        // If the data is less than zero, print it
        if (root->data < 0) {
            cout << root->data << " ";
        }
        // Traverse the left and right subtrees
        listNegativeNodes(root->left);
        listNegativeNodes(root->right);
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

    // Listing all the nodes with data less than zero
    cout << "Nodes with data less than zero: ";
    listNegativeNodes(root);
    cout << endl;

    return 0;
}
