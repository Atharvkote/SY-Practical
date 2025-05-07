#include <iostream>
#include <iomanip>
using namespace std;

class Hashtable {
public:
    string name;
    string id;
    string history;
    string treatment;
    Hashtable() {
        name = "empty";
        id = "empty";
        history = "empty";
        treatment = "empty";
    }
};

void insert(Hashtable *&h, string name, string id, string history, string treatment, int *&array, int &n);

void rehash(Hashtable *&h, int *&array, int &n) {
    int old_n = n;
    n = n * 2;
    Hashtable *new_h = new Hashtable[n];
    int *new_array = new int[n];
    for (int i = 0; i < n; i++) {
        new_array[i] = -1;
    }
    for (int i = 0; i < old_n; i++) {
        if (array[i] == 0) {
            insert(new_h, h[i].name, h[i].id, h[i].history, h[i].treatment, new_array, n);
        }
    }
    delete[] h;
    delete[] array;
    h = new_h;
    array = new_array;
}

void insert(Hashtable *&h, string name, string id, string history, string treatment, int *&array, int &n) {
    int val = 0;
    for (char c : id) {
        val += (int)c;
    }
    val = val % n;
    int i = 0, j = 1, k = 0;
    if (array[val] == -1 || array[val] == -2) {
        h[val].name = name;
        h[val].id = id;
        h[val].history = history;
        h[val].treatment = treatment;
        array[val] = 0;
        cout << "Inserted at: " << val << endl;
    } else {
        while (i != 1) {
            cout << "Collision occurred at: " << val << endl;
            k++;
            val = (val + (k * k)) % n;
            j++;
            if (array[val] == -1 || array[val] == -2) {
                h[val].name = name;
                h[val].id = id;
                h[val].history = history;
                h[val].treatment = treatment;
                array[val] = 0;
                cout << "Inserted at: " << val << endl;
                i = 1;
            }
            if (j == n) {
                cout << "Hashtable is full! Rehashing..." << endl;
                rehash(h, array, n);
                insert(h, name, id, history, treatment, array, n);
                return;
            }
        }
    }
}

 // Add this at the top of your file

void display(Hashtable *h, int *array, int n) {
    cout << "\n"
         << left
         << setw(6) << "Index"
         << setw(15) << "Patient ID"
         << setw(20) << "Name"
         << setw(25) << "History"
         << setw(25) << "Treatment" << endl;

    cout << string(91, '-') << endl;

    for (int i = 0; i < n; i++) {
        if (array[i] == 0) {
            cout << left
                 << setw(6) << i
                 << setw(15) << h[i].id
                 << setw(20) << h[i].name
                 << setw(25) << h[i].history
                 << setw(25) << h[i].treatment
                 << endl;
        }
    }
}

void update(Hashtable *h, int *array, int n, string id) {
    int val = 0;
    int i = 0, j = 1, k = 0;
    for (char c : id) {
        val += (int)c;
    }
    val = val % n;
    if (h[val].id == id && array[val] == 0) {
        string name1, history1, treatment1, id1;
        cout << "Enter the new patient id: ";
        cin >> id1;
        cout << "Enter the new patient name: ";
        cin >> name1;
        cout << "Enter the new patient history: ";
        cin >> history1;
        cout << "Enter the new patient treatment: ";
        cin >> treatment1;
        h[val].name = name1;
        h[val].id = id1;
        h[val].history = history1;
        h[val].treatment = treatment1;
        return;
    }
    while (i != 1) {
        k++;
        val = (val + (k * k)) % n;
        j++;
        if (h[val].id == id && array[val] == 0) {
            string name1, history1, id1, treatment1;
            cout << "Enter the new patient id: ";
            cin >> id1;
            cout << "Enter the new patient name: ";
            cin >> name1;
            cout << "Enter the new patient history: ";
            cin >> history1;
            cout << "Enter the new patient treatment: ";
            cin >> treatment1;
            h[val].name = name1;
            h[val].id = id1;
            h[val].history = history1;
            h[val].treatment = treatment1;
            i = 1;
        }
        if (j == n) {
            cout << "Track not found" << endl;
            i = 1;
        }
    }
}

void search(Hashtable *h, int *array, int n, string id) {
    int val = 0;
    int i = 0, j = 1, k = 0;
    for (char c : id) {
        val += (int)c;
    }
    val = val % n;
    if (h[val].id == id && array[val] == 0) {
        cout << "Name: " << h[val].name << endl;
        cout << "ID: " << h[val].id << endl;
        cout << "History: " << h[val].history << endl;
        cout << "Treatment: " << h[val].treatment << endl;
        return;
    }
    while (i != 1) {
        k++;
        val = (val + (k * k)) % n;
        j++;
        if (h[val].id == id && array[val] == 0) {
            cout << "Name: " << h[val].name << endl;
            cout << "ID: " << h[val].id << endl;
            cout << "History: " << h[val].history << endl;
            cout << "Treatment: " << h[val].treatment << endl;
            i = 1;
        }
        if (j == n) {
            cout << "Record not found!" << endl;
            i = 1;
        }
    }
}

void deleterecord(Hashtable *h, int *array, int n, string id) {
    int val = 0;
    int i = 0, j = 1, k = 0;
    for (char c : id) {
        val += (int)c;
    }
    val = val % n;
    if (h[val].id == id && array[val] == 0) {
        array[val] = -2;
        cout << "Record deleted!" << endl;
        return;
    }
    while (i != 1) {
        k++;
        val = (val + (k * k)) % n;
        j++;
        if (h[val].id == id && array[val] == 0) {
            array[val] = -2;
            cout << "Record deleted!" << endl;
            i = 1;
        }
        if (j == n) {
            cout << "Track not found" << endl;
            i = 1;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of patient tracks you want to insert (Hashtable size): ";
    cin >> n;
    Hashtable *h = new Hashtable[n];
    int *array = new int[n];
    for (int i = 0; i < n; i++) {
        array[i] = -1;
    }
    int ch;
    string name, history, id, id1, treatment;
    do {
        cout << "1.Insert\n2.Search\n3.Update\n4.Delete\n5.Display\n6.Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter the patient ID: ";
            cin >> id;
            cout << "Enter the patient name: ";
            cin >> name;
            cout << "Enter the patient history: ";
            cin >> history;
            cout << "Enter the patient treatment: ";
            cin >> treatment;
            insert(h, name, id, history, treatment, array, n);
            break;
        case 2:
            cout << "Enter the ID which you want to search: ";
            cin >> id1;
            search(h, array, n, id1);
            break;
        case 3:
            cout << "Enter the ID which you want to update: ";
            cin >> id1;
            update(h, array, n, id1);
            break;
        case 4:
            cout << "Enter the ID which you want to delete: ";
            cin >> id1;
            deleterecord(h, array, n, id1);
            break;
        case 5:
            display(h, array, n);
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Wrong choice! Try again." << endl;
        }
    } while (ch != 6);
    delete[] h;
    delete[] array;
    return 0;
}