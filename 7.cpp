// 7 Write a C++ program to create two arrays and store elements in order. Create another array and merge these two arrays.

#include <iostream>
using namespace std;

// Function to merge two arrays
void mergeArrays(int arr1[], int arr2[], int arr3[], int size1, int size2) {
    // Copy elements from arr1 to arr3
    for (int i = 0; i < size1; i++) {
        arr3[i] = arr1[i];
    }

    // Copy elements from arr2 to arr3
    for (int i = 0; i < size2; i++) {
        arr3[size1 + i] = arr2[i];
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size1, size2;

    // Input size of first array
    cout << "Enter the number of elements in the first array: ";
    cin >> size1;

    int arr1[size1];

    // Input elements for the first array
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    // Input size of second array
    cout << "Enter the number of elements in the second array: ";
    cin >> size2;

    int arr2[size2];

    // Input elements for the second array
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    // Create a third array to store the merged result
    int arr3[size1 + size2];

    // Merge the two arrays
    mergeArrays(arr1, arr2, arr3, size1, size2);

    // Print the merged array
    cout << "Merged array: ";
    printArray(arr3, size1 + size2);

    return 0;
}

