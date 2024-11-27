// 25 Write a C++ program to create a sequential File. Use this file to store Employee record(like Emp No, Name and Salary). Implement Search to locate a Employee record with roll no.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to hold employee details
struct Employee {
    int empNo;
    char name[50];
    float salary;
};

// Function to create and write employee records to the file
void createFile() {
    ofstream outFile("employees.txt", ios::out);
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return;
    }

    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee emp;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for employee " << i + 1 << endl;
        cout << "Employee Number: ";
        cin >> emp.empNo;
        cin.ignore();  // Clear the newline character from the buffer
        cout << "Employee Name: ";
        cin.getline(emp.name, 50);
        cout << "Employee Salary: ";
        cin >> emp.salary;

        // Write the employee record to the file
        outFile << emp.empNo << " " << emp.name << " " << fixed << setprecision(2) << emp.salary << endl;
    }
    outFile.close();
    cout << "\nEmployee records have been recorded successfully.\n";
}

// Function to search for an employee record by employee number
void searchRecord() {
    ifstream inFile("employees.txt", ios::in);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    int searchEmpNo;
    cout << "Enter the employee number to search: ";
    cin >> searchEmpNo;

    Employee emp;
    bool found = false;

    // Read each record and compare the employee number
    while (inFile >> emp.empNo >> ws) {  // Read employee number and ignore whitespace
        inFile.getline(emp.name, 50, ' ');
        inFile >> emp.salary;

        if (emp.empNo == searchEmpNo) {
            cout << "\nEmployee Record Found:\n";
            cout << "Employee Number: " << emp.empNo << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Salary: $" << fixed << setprecision(2) << emp.salary << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee with number " << searchEmpNo << " not found." << endl;
    }
    inFile.close();
}

int main() {
    int choice;
    do {
        cout << "\n--- Employee Management System ---";
        cout << "\n1. Create Employee File";
        cout << "\n2. Search Employee by Number";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                searchRecord();
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



