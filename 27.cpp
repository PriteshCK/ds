// 27 Write a C++ program to a create sequential File. Use this file to store bank account record(like acc No, Name and balance). Implement delete function to delete an account with given number.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct BankAccount {
    int accNo;
    char name[50];
    float balance;
};

// Function to create and write bank account records to the file
void createFile() {
    ofstream outFile("accounts.txt", ios::out);
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return;
    }

    int n;
    cout << "Enter the number of bank accounts: ";
    cin >> n;

    BankAccount account;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for account " << i + 1 << endl;
        cout << "Account Number: ";
        cin >> account.accNo;
        cin.ignore();  // Clear the newline character from the buffer
        cout << "Account Holder Name: ";
        cin.getline(account.name, 50);
        cout << "Balance: ";
        cin >> account.balance;

        // Write the account record to the file
        outFile << account.accNo << " " << account.name << " " << fixed << setprecision(2) << account.balance << endl;
    }
    outFile.close();
    cout << "\nBank account records have been recorded successfully.\n";
}

// Function to display all account records
void displayRecords() {
    ifstream inFile("accounts.txt", ios::in);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    BankAccount account;
    cout << "\nBank Account Records:\n";
    cout << setw(12) << "Acc No" << setw(20) << "Name" << setw(15) << "Balance" << endl;
    cout << "-----------------------------------------------\n";

    while (inFile >> account.accNo >> ws) {
        inFile.getline(account.name, 50, ' ');
        inFile >> account.balance;

        // Display the record
        cout << setw(12) << account.accNo
             << setw(20) << account.name
             << setw(15) << fixed << setprecision(2) << account.balance << endl;
    }

    inFile.close();
}

// Function to delete a record with a specific account number
void deleteRecord() {
    ifstream inFile("accounts.txt", ios::in);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    int delAccNo;
    cout << "Enter the account number to delete: ";
    cin >> delAccNo;

    ofstream tempFile("temp.txt", ios::out);
    if (!tempFile) {
        cerr << "Error creating temporary file!" << endl;
        return;
    }

    BankAccount account;
    bool found = false;

    while (inFile >> account.accNo >> ws) {
        inFile.getline(account.name, 50, ' ');
        inFile >> account.balance;

        // Write all records except the one to be deleted into the temp file
        if (account.accNo == delAccNo) {
            found = true;
            cout << "\nAccount " << delAccNo << " has been deleted successfully.\n";
        } else {
            tempFile << account.accNo << " " << account.name << " " << fixed << setprecision(2) << account.balance << endl;
        }
    }

    if (!found) {
        cout << "\nAccount with number " << delAccNo << " not found." << endl;
    }

    inFile.close();
    tempFile.close();

    // Replace the old file with the new one
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}

int main() {
    int choice;
    do {
        cout << "\n--- Bank Account Management ---";
        cout << "\n1. Create Account File";
        cout << "\n2. Display All Accounts";
        cout << "\n3. Delete Account by Number";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
