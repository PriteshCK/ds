// 23 Write a C++ program to Store N(Max 10) integers in an array and implement hash table using division method , with linear probing with replacement

#include <iostream>
#define TABLE_SIZE 10  // Maximum hash table size
using namespace std;

// Structure for the hash table entry
struct HashEntry {
    int key;
    bool isOccupied;
};

// Function to initialize the hash table
void initializeTable(HashEntry table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].isOccupied = false;
        table[i].key = -1;  // Default value for empty slots
    }
}

// Function to display the hash table
void displayTable(HashEntry table[]) {
    cout << "\nHash Table:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].isOccupied)
            cout << "Index " << i << ": " << table[i].key << endl;
        else
            cout << "Index " << i << ": [Empty]\n";
    }
}

// Function to insert a key into the hash table with linear probing and replacement
void insertKey(HashEntry table[], int key) {
    int index = key % TABLE_SIZE;  // Calculate hash index
    if (!table[index].isOccupied) {
        // If slot is empty, insert key directly
        table[index].key = key;
        table[index].isOccupied = true;
    } else {
        // Collision occurred
        if ((table[index].key % TABLE_SIZE) != index) {
            // Replace only if the existing key does not naturally belong here
            int temp = table[index].key;
            table[index].key = key;
            key = temp;  // Reinsert the displaced key
        }

        // Find next available slot (linear probing)
        int i = (index + 1) % TABLE_SIZE;
        while (table[i].isOccupied) {
            i = (i + 1) % TABLE_SIZE;  // Move to the next slot
        }
        table[i].key = key;
        table[i].isOccupied = true;
    }
}

int main() {
    HashEntry hashTable[TABLE_SIZE];
    initializeTable(hashTable);

    int n;
    cout << "Enter the number of integers (Max 10): ";
    cin >> n;

    if (n > TABLE_SIZE) {
        cout << "Exceeds maximum allowed size of 10. Exiting." << endl;
        return 0;
    }

    int keys[10];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
        insertKey(hashTable, keys[i]);
    }

    displayTable(hashTable);
    return 0;
}
