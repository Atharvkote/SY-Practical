#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int roll_number;
    string _class;

public:
    // Default constructor
    Student() : name("No Record"), roll_number(0), _class("No Class Allotted") {}

    // Parameterized constructor
    Student(string _name, int _roll_number, string __class)
        : name(_name), roll_number(_roll_number), _class(__class) {}

    // Function to print all student records
    static void print_shelf(Student division[], int class_strength) {
        for (int i = 0; i < class_strength; i++) {
            cout << "Name: " << division[i].name
                 << " | Roll Number: " << division[i].roll_number
                 << " | Class: " << division[i]._class << endl;
        }
    }

    // Function to check if the array is sorted
    static bool isSorted(Student division[], int class_strength) {
        for (int j = 0; j < class_strength - 1; j++) {
            if (!(division[j].roll_number < division[j + 1].roll_number)) {
                return false;
            }
        }
        return true;
    }

    // Selection sort algorithm
    static void selectionSort(Student division[], int class_strength) {
        for (int i = 0; i < class_strength - 1; i++) {
            for (int j = i + 1; j < class_strength; j++) {
                if (division[i].roll_number > division[j].roll_number) {
                    swap(division[i], division[j]);
                }
            }
        }
    }

    // Linear search algorithm
    static int linearSearch(Student division[], int class_strength, int target) {
        for (int i = 0; i < class_strength; i++) {
            if (division[i].roll_number == target) {
                return i;
            }
        }
        return -1;
    }

    // Binary search algorithm
    static int binarySearch(Student division[], int class_strength, int target) {
        if (!isSorted(division, class_strength)) {
            cout << "You entered an unsorted array. Sorting the array...\n";
            selectionSort(division, class_strength);
        }

        int low = 0, high = class_strength - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (division[mid].roll_number == target) {
                return mid;
            } else if (division[mid].roll_number < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    // Function to display student details
    void display() {
        cout << "Name: " << name << " | Roll Number: " << roll_number << " | Class: " << _class << endl;
    }
};

int main() {
    Student division[10];
    int class_strength, choice;

    cout << "Enter Number of Entries: ";
    cin >> class_strength;

    string _name, __class;
    int _roll_number;

    for (int i = 0; i < class_strength; i++) {
        cout << "Enter Details of Student - " << i + 1 << " : " << endl;
        cout << "  • Enter Roll Number: ";
        cin >> _roll_number;
        cout << "  • Enter Name: ";
        cin >> _name;
        cout << "  • Enter Class: ";
        cin >> __class;

        division[i] = Student(_name, _roll_number, __class);
    }

    do {
        cout << "\nOperation Menu:" << endl;
        cout << "1. Sort by Roll Number" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Check Student Presence (Optimized)" << endl;
        cout << "4. Check Student Presence (Unoptimized)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Student::selectionSort(division, class_strength);
                break;
            case 2:
                Student::print_shelf(division, class_strength);
                break;
            case 3: {
                int target;
                cout << "Enter Roll Number of Student: ";
                cin >> target;
                cout << "Searching using Binary Search..." << endl;
                int index = Student::binarySearch(division, class_strength, target);
                if (index != -1) {
                    division[index].display();
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            }
            case 4: {
                int target;
                cout << "Enter Roll Number of Student: ";
                cin >> target;
                cout << "Searching using Linear Search..." << endl;
                int index = Student::linearSearch(division, class_strength, target);
                if (index != -1) {
                    division[index].display();
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
