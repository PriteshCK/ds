#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Customer {
    int custID;
    string name;
    float due_amount;
};

// Function to create and write customer records to the file
void createFile() {
    ofstream outFile("customers.txt", ios::out);
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return;
    }

    int n;
    cout << "Enter the number of customers: ";
    cin >> n;

    Customer customer;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for customer " << i + 1 << endl;
        cout << "Customer ID: ";
        cin >> customer.custID;
        cin.ignore();  // Clear the newline character from the buffer
        cout << "Customer Name: ";
        getline(cin, customer.name);
        cout << "Due Amount: ";
        cin >> customer.due_amount;

        // Write the customer record to the file
        outFile << customer.custID << " " << customer.name << " " << fixed << setprecision(2) << customer.due_amount << endl;
    }
    outFile.close();
    cout << "\nCustomer records have been recorded successfully.\n";
}

// Function to read customer records and calculate the total due amount
void calculateTotalDue() {
    ifstream inFile("customers.txt", ios::in);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Customer customer;
    float total_due = 0.0;

    cout << "\nCustomer Records:\n";
    cout << setw(10) << "CustID" << setw(20) << "Name" << setw(15) << "Due Amount" << endl;
    cout << "-----------------------------------------------\n";

    while (inFile >> customer.custID >> ws) {  // Read customer ID and ignore whitespace
        getline(inFile, customer.name, ' ');   // Read the customer name until the next space
        inFile >> customer.due_amount;

        // Display the record
        cout << setw(10) << customer.custID
             << setw(20) << customer.name
             << setw(15) << fixed << setprecision(2) << customer.due_amount << endl;

        total_due += customer.due_amount;  // Accumulate due amount
    }

    inFile.close();
    cout << "\nTotal Due Amount: $" << fixed << setprecision(2) << total_due << endl;
}

int main() {
    int choice;
    do {
        cout << "\n--- Customer Record Management ---";
        cout << "\n1. Create Customer File";
        cout << "\n2. Calculate Total Due Amount";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                calculateTotalDue();
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

