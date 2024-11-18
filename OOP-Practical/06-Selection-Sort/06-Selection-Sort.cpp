#include <iostream>
using namespace std;

template <typename T>
void print_array(T a[], int size) {
    cout <<"[ ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ,";
    }
    cout <<" ]"<< endl;
}

template <typename T>
void selectionSort(T a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        T temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp;
    }
}

int main() {
    int choice;
    do {
        cout << "Choose the type of array to sort:" << endl;
        cout << "1. Integer array" << endl;
        cout << "2. Float array" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int a[100], size;
                cout << "Enter the size of the integer array (max 100): ";
                cin >> size;

                if (size > 100) {
                    cout << "Size exceeds limit of 100. Try again." << endl;
                    break;
                }

                cout << "Enter " << size << " elements: ";
                for (int i = 0; i < size; i++) {
                    cin >> a[i];
                }

                selectionSort(a, size);
                cout << "Sorted integer array: ";
                print_array(a, size);
                break;
            }
            case 2: {
                float a[100];
                int size;
                cout << "Enter the size of the float array (max 100): ";
                cin >> size;

                if (size > 100) {
                    cout << "Size exceeds limit of 100. Try again." << endl;
                    break;
                }

                cout << "Enter " << size << " elements: ";
                for (int i = 0; i < size; i++) {
                    cin >> a[i];
                }

                selectionSort(a, size);
                cout << "Sorted float array: ";
                print_array(a, size);
                break;
            }
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
