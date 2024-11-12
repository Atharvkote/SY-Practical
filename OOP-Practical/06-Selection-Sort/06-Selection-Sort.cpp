#include<iostream>
using namespace std;

template<typename T>
void print_array(T a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

template<typename T>
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
    int a[] = {10, 7, 8, 9, 1};
    float a2[] = {10.5, 7.2, 8.1, 3.2, 4.5};
    char a3[] = {'a', 's', 'c', 'v', 'f'};

    selectionSort(a,5);
    selectionSort(a2, 5);
    selectionSort(a3, 5);

    cout << "Sorted integer array: ";
    print_array(a, 5);
    
    cout << "Sorted float array: ";
    print_array(a2, 5);
    
    cout << "Sorted char array: ";
    print_array(a3, 5);

    return 0;
}