// 4 Write a C++ program to store a matrix of given order(Max 10 and Min 5) and arrange the elements of each column in ascending order using insertion sort.

#include <iostream>
using namespace std;

// Function to perform insertion sort on an array (col)
void insertionSort(int col[], int n) {
    for (int j = 1; j < n; j++) {
        int key = col[j];
        int i = j - 1;

        // Move elements greater than key one position ahead
        while (i >= 0 && col[i] > key) {
            col[i + 1] = col[i];
            i--;
        }
        col[i + 1] = key;
    }
}

int main() {
    int rows, cols;

    // Input order of the matrix (must be between 5 and 10)
    do {
        cout << "Enter the number of rows (5 to 10): ";
        cin >> rows;
        cout << "Enter the number of columns (5 to 10): ";
        cin >> cols;

        if (rows < 5 || rows > 10 || cols < 5 || cols > 10) {
            cout << "Invalid order! Please enter values between 5 and 10.\n";
        }
    } while (rows < 5 || rows > 10 || cols < 5 || cols > 10);

    int matrix[10][10];

    // Input matrix elements
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Display the matrix
    cout << "\nMatrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // Sort each row using insertion sort
    for (int j = 0; j < cols; j++) {
        insertionSort(matrix[j], cols);
    }

    // Display the sorted matrix
    cout << "\nMatrix after sorting each row in ascending order:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
