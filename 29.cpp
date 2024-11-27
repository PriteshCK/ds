// 29 Write a C++ program to create a Indexed File. Use this file to store student record(like Roll No, Name and Marks). Implement Search to locate a student record with roll no.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

// Function to create and write student records to the file
void createFile() {
    ofstream outFile("students.dat", ios::binary | ios::out);
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
        cout << "Roll No: ";
        cin >> student.rollNo;
        cin.ignore();  // Clear newline character from the buffer
        cout << "Name: ";
        cin.getline(student.name, 50);
        cout << "Marks: ";
        cin >> student.marks;

        // Write the student structure to the binary file
        outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
    }
    outFile.close();
    cout << "\nStudent records have been recorded successfully.\n";
}

// Function to search for a student record by roll number
void searchRecord() {
    ifstream inFile("students.dat", ios::binary | ios::in);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    int rollNumber;
    cout << "Enter roll number to search: ";
    cin >> rollNumber;

    Student student;
    bool found = false;

    // Read each record and compare the roll number
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNo == rollNumber) {
            cout << "\nStudent Record Found:\n";
            cout << "Roll No: " << student.rollNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Marks: " << fixed << setprecision(2) << student.marks << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll No " << rollNumber << " not found." << endl;
    }
    inFile.close();
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Record Management ---";
        cout << "\n1. Create Student File";
        cout << "\n2. Search Student by Roll No";
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

