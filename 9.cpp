// 9 Write a C++ program to store N elements in an array and perform Shell sort.

#include <iostream>
using namespace std;

// Function to perform Shell Sort
void shellSort(int arr[], int N) {
    // Start with a large gap, then reduce the gap
    for (int gap = N / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort for each gap size
        for (int i = gap; i < N; i++) {
            // Store the current element to be compared and inserted
            int temp = arr[i];
            int j = i;

            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Place the current element at its correct position
            arr[j] = temp;
        }
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

    // Perform Shell Sort
    shellSort(arr, N);

    // Print the sorted array
    cout << "Sorted array: ";
    printArray(arr, N);

    return 0;
}

