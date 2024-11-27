// 24 Write a C++ program to create a sequential File. Use this file to store student record(like Roll No, Name and Marks). Implement Search to locate a student record with roll no.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to hold student details
struct Student {
    int rollNo;
    char name[50];
    float marks;
};

// Function to create and write student records to the file
void createFile() {
    ofstream outFile("students.txt", ios::out);  // Create or overwrite the file
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return;
    }

    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student student;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << endl;
        cout << "Roll Number: ";
        cin >> student.rollNo;
        cin.ignore();  // Clear the newline character from the buffer
        cout << "Student Name: ";
        cin.getline(student.name, 50);
        cout << "Marks: ";
        cin >> student.marks;

        // Write the student record to the file
        outFile << student.rollNo << " " << student.name << " " << fixed << setprecision(2) << student.marks << endl;
    }
    outFile.close();
    cout << "\nStudent records have been recorded successfully.\n";
}

// Function to search for a student record by roll number
void searchRecord() {
    ifstream inFile("students.txt", ios::in);  // Open the file for reading
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    int searchRollNo;
    cout << "Enter the roll number to search: ";
    cin >> searchRollNo;

    Student student;
    bool found = false;

    // Read each record and compare the roll number
    while (inFile >> student.rollNo >> ws) {  // Read roll number and ignore whitespace
        inFile.getline(student.name, 50, ' '); // Read the name
        inFile >> student.marks;

        if (student.rollNo == searchRollNo) {
            cout << "\nStudent Record Found:\n";
            cout << "Roll Number: " << student.rollNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Marks: " << fixed << setprecision(2) << student.marks << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with roll number " << searchRollNo << " not found." << endl;
    }
    inFile.close();
}

// Main function to provide a menu for user interaction
int main() {
    int choice;
    do {
        cout << "\n--- Student Management System ---";
        cout << "\n1. Create Student File";
        cout << "\n2. Search Student by Roll Number";
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
