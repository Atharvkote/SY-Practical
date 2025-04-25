#include <iostream>
using namespace std;

class probe_pairs {
public:
    int val;
    int probe;

    probe_pairs() {
        val = 0;
        probe = 0;
    }

    probe_pairs(int v, int p) {
        val = v;
        probe = p;
    }
};

class Patient {
public:
    int patient_id;
    string patient_name;
    string treatment_type;

    Patient() {
        patient_id = 0;
        patient_name = "";
        treatment_type = "";
    }

    Patient(string name, int id, string treatment) {
        patient_name = name;
        patient_id = id;
        treatment_type = treatment;
    }

    void accept() {
        cout << "Enter Patient ID: ";
        cin >> patient_id;
        cin.ignore();  // Clear newline
        cout << "Enter Patient Name: ";
        getline(cin, patient_name);
        cout << "Enter Treatment Type: ";
        getline(cin, treatment_type);
    }

    void display() {
        cout << "  :: ID : " << patient_id << ", :: Name : " << patient_name
             << ", :: Treatment : " << treatment_type;
    }
};

class HashTable {
public:
    Patient hash_table[100];
    bool is_occupied[100];
    probe_pairs probes[100];
    int size;

    HashTable(int s) {
        size = s;
        for (int i = 0; i < size; i++) {
            is_occupied[i] = false;
            probes[i] = probe_pairs();
        }
    }

    int hash_function(int key) {
        return key % size;
    }

    bool is_table_full() {
        for (int i = 0; i < size; i++) {
            if (!is_occupied[i])
                return false;
        }
        return true;
    }

    void add(Patient val) {
        if (is_table_full()) {
            cout << "Hash table is full. Cannot insert patient ID " << val.patient_id << endl;
            return;
        }
    
        int hash_value = hash_function(val.patient_id);
        int i = hash_value;
        int probe = 0;
    
        while (is_occupied[i]) {
            if (hash_table[i].patient_id == val.patient_id) {
                cout << "Duplicate patient ID! Cannot insert.\n";
                return;
            }
    
            cout << "Collision occurred at index " << i << " for patient ID " << val.patient_id << endl;
    
            probe++;
            i = (hash_value + probe * probe) % size;
        }
    
        hash_table[i] = val;
        is_occupied[i] = true;
        probes[i] = probe_pairs(val.patient_id, probe);
    
        cout << "Inserted patient ID " << val.patient_id << " at index " << i
             << " with " << probe << " probes\n";
    }
    

    void search() {
        Patient val;
        cout << "Enter patient ID to search: ";
        cin >> val.patient_id;

        int hash_value = hash_function(val.patient_id);
        int i = hash_value;
        int probe = 0;

        while (is_occupied[i] && probe < size) {
            if (hash_table[i].patient_id == val.patient_id) {
                cout << "Patient found at index " << i << endl;
                hash_table[i].display();
                cout << endl;
                return;
            }
            probe++;
            i = (hash_value + probe * probe) % size;
        }

        cout << "Patient not found!\n";
    }

    void remove() {
        Patient val;
        cout << "Enter patient ID to remove: ";
        cin >> val.patient_id;

        int hash_value = hash_function(val.patient_id);
        int i = hash_value;
        int probe = 0;

        while (is_occupied[i] && probe < size) {
            if (hash_table[i].patient_id == val.patient_id) {
                is_occupied[i] = false;
                hash_table[i] = Patient();
                probes[i] = probe_pairs();
                cout << "Patient removed from index " << i << endl;
                return;
            }
            probe++;
            i = (hash_value + probe * probe) % size;
        }

        cout << "Patient not found. Cannot remove.\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << "  Key :: " << i;
            if (is_occupied[i]) {
                hash_table[i].display();
                cout << " (Probes: " << probes[i].probe << ")";
            } else {
                cout << " null";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;
    HashTable h(size);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add patient\n";
        cout << "2. Search patient\n";
        cout << "3. Remove patient\n";
        cout << "4. Display table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Patient val;
                val.accept();
                h.add(val);
                break;
            }
            case 2:
                h.search();
                break;
            case 3:
                h.remove();
                break;
            case 4:
                h.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
