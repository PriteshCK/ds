// 8 Write a C++ program to store N elements in an array and perform quick sort.

#include <iostream>
using namespace std;

// Function to perform partitioning for quick sort
int partition(int arr[], int low, int high) {
    // Pivot element is chosen as the rightmost element
    int pivot = arr[high];
    int i = low - 1;  // Index of the smaller element

    // Rearranging elements so that all elements less than pivot come before it, 
    // and all elements greater than pivot come after it.
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {  // If current element is smaller than the pivot
            i++;  // Increment index of smaller element
            swap(arr[i], arr[j]);  // Swap current element with arr[i]
        }
    }
    swap(arr[i + 1], arr[high]);  // Place the pivot element at the correct position
    return (i + 1);  // Return the partition index
}

// Function to implement quick sort recursively
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the pivot element and partition the array
        int pi = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pi - 1);  // Left sub-array
        quickSort(arr, pi + 1, high);  // Right sub-array
    }
}

// Function to print the array
void printArray(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N;

    // Input number of elements
    cout << "Enter the number of elements: ";
    cin >> N;

    int arr[N];
    
    // Input the elements
    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Perform Quick Sort
    quickSort(arr, 0, N - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    printArray(arr, N);

    return 0;
}
