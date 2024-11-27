// 3 Write a C++ program to store a matrix of given order(Max 10 and Min 5) and arrange the elements of each row in ascending order using selection sort.

#include <iostream>
using namespace std;

// func to bubble on array/row
void selectionSort(int row[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume the minimum is at index i
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (row[j] < row[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            int temp = row[i];
            row[i] = row[minIndex];
            row[minIndex] = temp;
        }
    }
}

int main(){
	int rows, cols;
	int matrix [10][10];
	do {
		cout << "Enter rows: ";
		cin >> rows;

		cout << "Enter cols: ";
		cin >> cols;

		if (rows < 5 || rows > 10 || cols > 10 || cols < 5) {
			cout << "out of range\n";
		}
	} while (rows < 5 || rows > 10 || cols > 10 || cols < 5);
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			cin >> matrix[i][j];
		}
	}

	// disp matrix
	cout << "\nMatrix:\n";
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	// sort matrix
    	for (int i = 0; i < rows; i++) {
		selectionSort(matrix[i], cols);
	}

	// disp sorted matrix
	cout << "\nSorted Matrix:\n";
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}


	
return 0;
}
