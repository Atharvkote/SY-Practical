#include <iostream>
using namespace std;

// Function to check if the array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

// Selection sort function
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = a[i];
        arr[i] = temp;
    }
}
// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index of the target element
        }
    }
    return -1;  // Return -1 if the target is not found
}

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (!isSorted(arr, n)) {
        cout << "Array is not sorted. Sorting the array...\n";
        selectionSort(arr, n);
    } else {
        cout << "Array is already sorted.\n";
    }

    cout << "Enter the target element to search for: ";
    cin >> target;

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        cout << "Element found at index " << result << ".\n";
    } else {
        cout << "Element not found.\n";
    }

    return 0;
}
