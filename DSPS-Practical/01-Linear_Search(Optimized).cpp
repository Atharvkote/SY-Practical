#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Element at index [" << i << "]: ";
        cin >> arr[i];
    }

    if (!isSorted(arr, n)) {
        cout << "Array is not sorted. Sorting the array...\n";
        selectionSort(arr, n);
        cout << "Sorted array: [";
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << (i < n - 1 ? ", " : "");
        }
        cout << "]\n";
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
