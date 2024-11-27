// 5 Write a C++ program to store a matrix of given order(Max 10 and Min 5) and arrange the elements of each column in ascending order using Bubble sort.

#include <iostream>
using namespace std;

// Function to perform Bubble Sort on each column
void bubbleSortColumn(int matrix[][10], int rows, int col) {
    // Perform Bubble Sort for the specified column
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (matrix[j][col] > matrix[j + 1][col]) {
                // Swap the elements if they are in the wrong order
                swap(matrix[j][col], matrix[j + 1][col]);
            }
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;

    // Input number of rows and columns (within the range 5 to 10)
    do {
        cout << "Enter number of rows (5 to 10): ";
        cin >> rows;
    } while (rows < 5 || rows > 10);

    do {
        cout << "Enter number of columns (5 to 10): ";
        cin >> cols;
    } while (cols < 5 || cols > 10);

    int matrix[10][10];

    // Input the matrix elements
    cout << "Enter the matrix elements: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Perform bubble sort on each column
    for (int col = 0; col < cols; col++) {
        bubbleSortColumn(matrix, rows, col);
    }

    // Print the sorted matrix
    cout << "\nMatrix after sorting each column in ascending order:\n";
    printMatrix(matrix, rows, cols);

    return 0;
}
