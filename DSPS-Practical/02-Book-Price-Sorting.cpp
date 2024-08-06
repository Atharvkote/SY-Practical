#include <iostream>
#include <string>
using namespace std;

class Library {

public:
    string book_name;
    float prize;

    void add_book() {
        cout << "  • Book Name: ";
        cin >> book_name;
        cout << "  • Book Prize: ";
        cin >> prize;
    }
    
    static void remove_duplicates_with_temp(Library shelf[], int &entries) {
        cout << "\nRemoving Duplicates with Temporary Array......." << endl;
        Library temp[10];
        int temp_index = 0;

        for (int i = 0; i < entries; i++) {
            bool duplicate = false;
            for (int j = 0; j < temp_index; j++) {
                if (shelf[i].book_name == temp[j].book_name) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) {
                temp[temp_index] = shelf[i];
                temp_index++;
            }
        }

        for (int i = 0; i < temp_index; i++) {
            shelf[i] = temp[i];
        }

        entries = temp_index;
    }

    static void sort_books(Library shelf[], int entries) {
        for (int i = 0; i < entries - 1; i++) {
            for (int j = i + 1; j < entries; j++) {
                if (shelf[i].prize < shelf[j].prize) {
                    // Swap logic for descending order
                    Library temp = shelf[i];
                    shelf[i] = shelf[j];
                    shelf[j] = temp;
                }
            }
        }
    }

    static void drop_duplicate(Library shelf[], int &entries) {
        cout << "\nDropping Duplicates......." << endl;
        for (int i = 0; i < entries; i++) {
            for (int j = i + 1; j < entries; j++) {
                if (shelf[i].book_name == shelf[j].book_name) {
                    for (int k = j; k < entries - 1; k++) {
                        shelf[k] = shelf[k + 1];
                    }
                    entries--;
                    j--;
                }
            }
        }
    }

    static void print_shelf(Library shelf[], int entries) {
        cout << "----------------------------------------------------------" << endl;
        cout << "|         Book Name          ""         Prize              |" << endl;
        cout << "----------------------------------------------------------" << endl;
        for (int i = 0; i < entries; i++) {
            cout << "          " << shelf[i].book_name << "                        " << shelf[i].prize << "          " << endl;
        }
        cout << "----------------------------------------------------------" << endl;
    }

    static void sort_in_range(Library shelf[], int target, int entries) {
        int count = 0;
        
        cout << "Books Under Provided Prize:" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|         Book Name          ""         Prize              |" << endl;
        cout << "----------------------------------------------------------" << endl;
        
        for (int i = 0; i < entries; i++) {
            if (shelf[i].prize < target) {
                cout << "        " << shelf[i].book_name << "                  ""          " << shelf[i].prize << "              " << endl;
                count++;
            }
        }
        cout << "----------------------------------------------------------" << endl;
        
        cout << "\n\nNumber of Books Available Under Given Prize Tag: [ " << count <<" ]"<< endl;

        count = 0;
        cout << "Books Above Provided Prize:" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|         Book Name          ""         Prize              |" << endl;
        cout << "----------------------------------------------------------" << endl;
        for (int i = 0; i < entries; i++) {
            if (shelf[i].prize >= target) {
                cout << "        " << shelf[i].book_name << "                           " << shelf[i].prize << "              " << endl;
                count++;
            }
        }
        cout << "----------------------------------------------------------" << endl;
        cout << "\n\nNumber of Books Available Above Given Prize Tag: [ " << count <<" ]"<< endl;
    }
};

int main() {
    Library shelf[10];
    int entries, choice;

    cout << "Enter Number of Entries: ";
    cin >> entries;

    for (int i = 0; i < entries; i++) {
        cout<<"Enter Details of Book - "<<i+1<<" : "<<endl;
        shelf[i].add_book();
    }

    do {
        cout << "\nOperation Menu:" << endl;
        cout << "1. Sort Books" << endl;
        cout << "2. Drop Duplicate ( Optimized ) " << endl;
        cout << "3. Display" << endl;
        cout << "4. Remove Duplicates " << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Library::sort_books(shelf, entries);
                cout << "Books sorted by prize." << endl;
                break;
            }
            case 2: {
                Library::drop_duplicate(shelf, entries);
                break;
            }
            case 3: {
                Library::print_shelf(shelf, entries);
                break;
            }
            case 4: {
                Library::remove_duplicates_with_temp(shelf, entries);
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
