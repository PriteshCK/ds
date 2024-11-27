// 26 Write a C++ program to create a sequential File. Use this file to store Items record(like Item No, Name and Price). Enlist from the File all the items which have price less than 100.0

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to hold item details
struct Item {
    int itemNo;
    char name[50];
    float price;
};

// Function to create and write item records to the file
void createFile() {
    ofstream outFile("items.txt", ios::out);
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return;
    }

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    Item item;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for item " << i + 1 << endl;
        cout << "Item Number: ";
        cin >> item.itemNo;
        cin.ignore();  // Clear newline character from the buffer
        cout << "Item Name: ";
        cin.getline(item.name, 50);
        cout << "Item Price: ";
        cin >> item.price;

        // Write the item record to the file
        outFile << item.itemNo << " " << item.name << " " << fixed << setprecision(2) << item.price << endl;
    }
    outFile.close();
    cout << "\nItem records have been recorded successfully.\n";
}

// Function to read items and list those with a price less than 100.0
void listLowPricedItems() {
    ifstream inFile("items.txt", ios::in);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Item item;
    cout << "\nItems with Price Less Than 100.0:\n";
    cout << setw(10) << "Item No" << setw(20) << "Name" << setw(10) << "Price\n";
    cout << "-----------------------------------------------\n";

    // Read each item and check the price
    while (inFile >> item.itemNo >> ws) {  // Read item number and ignore whitespace
        inFile.getline(item.name, 50, ' '); // Read the item name
        inFile >> item.price;

        if (item.price < 100.0) {
            cout << setw(10) << item.itemNo
                 << setw(20) << item.name
                 << setw(10) << fixed << setprecision(2) << item.price << endl;
        }
    }

    inFile.close();
}

int main() {
    int choice;
    do {
        cout << "\n--- Item Management System ---";
        cout << "\n1. Create Item File";
        cout << "\n2. List Items with Price < 100.0";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                listLowPricedItems();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
