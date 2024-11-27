// 14 Write a C++ program to create a Binary Search Tree for N nodes, and implement non- recursive in-order tree traversal Write a C++ program to create a Binary Search Tree for N nodes, and implement non- recursive post-order tree traversal.

#include <iostream>
#include <stack>
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

// Non-recursive In-order Traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current != nullptr || !s.empty()) {
        // Reach the leftmost node
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Process the node at the top of the stack
        current = s.top();
        s.pop();
        cout << current->data << " ";

        // Move to the right subtree
        current = current->right;
    }
}

// Non-recursive Post-order Traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root == nullptr) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left and right children of the node to s1
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }

    // Process nodes in s2 (post-order)
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
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

    // Non-recursive in-order traversal
    cout << "\nNon-recursive In-order Traversal: ";
    inorderTraversal(root);

    // Non-recursive post-order traversal
    cout << "\nNon-recursive Post-order Traversal: ";
    postorderTraversal(root);

    return 0;
}

