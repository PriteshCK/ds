// 30 Write a C++ program to create a Indexed File. Use this file to store Items record(like Item No, Name and Price). Enlist from the File all the items which have price less than 100.0

#include <iostream>
#include <fstream>
#include <iomanip>  // For formatting output
#include <string>
using namespace std;

struct Item {
    int itemNo;
    char name[30];
    float price;
};

// Function to add items to the file
void createFile() {
    ofstream outFile("items.dat");
    if (!outFile) {
        cerr << "Error creating file!";
        return;
    }

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    Item item;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for item " << i + 1;
        cout << "Item No: ";
        cin >> item.itemNo;
        cout << "Item Name: ";
        cin.getline(item.name, 30);
        cout << "Item Price: ";
        cin >> item.price;

        // Write the item structure to the binary file
        outFile.write(reinterpret_cast<char*>(&item), sizeof(Item));
    }
    outFile.close();
    cout << "\nItems have been recorded successfully.\n";
}

// Function to read and list items with a price less than 100
void listLowPricedItems() {
    ifstream inFile("items.dat");
    if (!inFile) {
        cerr << "Error opening file!";
        return;
    }

    Item item;
    cout << "\nItems with price less than 100.0:\n";
    cout << setw(10) << "Item No" << setw(20) << "Item Name" << setw(10) << "Price\n";
    cout << "-----------------------------------------------\n";

    // Read each item and check the price
    while (inFile.read(reinterpret_cast<char*>(&item), sizeof(Item))) {
        if (item.price < 100.0) {
            cout << setw(10) << item.itemNo
                 << setw(20) << item.name
                 << setw(10) << fixed << setprecision(2) << item.price;
        }
    }
    inFile.close();
}

int main() {
    int choice;
    do {
        cout << "\n--- Item Record Management ---";
        cout << "\n1. Create Item File";
        cout << "\n2. List Items with Price < 100";
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
                cout << "Exiting program.";
                break;
            default:
                cout << "Invalid choice, please try again.";
        }
    } while (choice != 3);

    return 0;
}
