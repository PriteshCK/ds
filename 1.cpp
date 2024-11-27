// 1 Write a C++ program to store a matrix of given order(Max 10 and Min 5) and arrange the elements of each row in ascending order using insertion sort.

#include <iostream>
using namespace std;

// Function to perform insertion sort on an array (row)
void insertionSort(int row[], int n) {
    for (int i = 1; i < n; i++) {
        int key = row[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && row[j] > key) {
            row[j + 1] = row[j];
            j--;
        }
        row[j + 1] = key;
    }
}

int main() {
    int rows, cols;
    int matrix[10][10];

    // Input order of the matrix (must be between 5 and 10)
    do {
        cout << "Enter the number of rows (5 to 10): ";
        cin >> rows;
        cout << "Enter the number of columns (5 to 10): ";
        cin >> cols;

        if (rows < 5 || rows > 10 || cols < 5 || cols > 10) {
            cout << "out of range\n";
        }
    } while (rows < 5 || rows > 10 || cols < 5 || cols > 10);


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
    for (int i = 0; i < rows; i++) {
        insertionSort(matrix[i], cols);
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
