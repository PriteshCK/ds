// 10 Write a C++ program to store N elements in a singly linked list and perform Bubble sort.

#include <iostream>
using namespace std;

// Structure to represent each node of the linked list
struct Node {
    int data;       // Data part
    Node* next;     // Pointer to the next node
};

// Class to represent the linked list
class LinkedList {
private:
    Node* head;  // Pointer to the head (first node) of the list

public:
    // Constructor to initialize the list as empty
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node();  // Create a new node
        newNode->data = value;       // Set its data
        newNode->next = nullptr;     // The next pointer is initially null

        if (head == nullptr) {       // If the list is empty
            head = newNode;          // New node becomes the head
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;     // Insert the new node at the end
        }
    }

    // Function to print the linked list
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";  // Print the data of each node
            temp = temp->next;          // Move to the next node
        }
        cout << endl;
    }

    // Function to perform Bubble Sort on the linked list
    void bubbleSort() {
        if (head == nullptr) return;  // If the list is empty, do nothing

        bool swapped;
        do {
            swapped = false;
            Node* temp = head;
            while (temp != nullptr && temp->next != nullptr) {
                // If the data in the current node is greater than the next node
                if (temp->data > temp->next->data) {
                    // Swap the data of the two nodes
                    int tempData = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = tempData;

                    swapped = true;  // Mark that a swap was made
                }
                temp = temp->next;  // Move to the next node
            }
        } while (swapped);  // Continue until no swaps are made in a full pass
    }
};

int main() {
    LinkedList list;
    int N, value;

    // Input number of elements to be inserted into the list
    cout << "Enter the number of elements: ";
    cin >> N;

    // Input the elements
    cout << "Enter the elements:\n";
    for (int i = 0; i < N; i++) {
        cin >> value;
        list.insert(value);
    }

    // Print the original list
    cout << "Original list: ";
    list.print();

    // Perform Bubble Sort
    list.bubbleSort();

    // Print the sorted list
    cout << "Sorted list: ";
    list.print();

    return 0;
}
