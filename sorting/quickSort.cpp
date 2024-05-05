#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choose the pivot as the first element
    int i = low + 1;

    for (int j = low + 1; j <= high; ++j) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            ++i;
        }
    }

    swap(arr[low], arr[i - 1]);
    return i - 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int myArray[] = {3, 6, 8, 10, 1, 2, 1};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    cout << "Original Array: ";
    for (int i = 0; i < arraySize; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    quicksort(myArray, 0, arraySize - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < arraySize; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    return 0;
}
