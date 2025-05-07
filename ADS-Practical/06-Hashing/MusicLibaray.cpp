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

class Album {
public:
    int album_number;
    string album_name;
    int number_of_songs;

    Album() {
        album_name = "";
        album_number = 0;
        number_of_songs = 0;
    }

    Album(string name, int number, int songs) {
        album_name = name;
        album_number = number;
        number_of_songs = songs;
    }

    void accept() {
        cout << "Enter Name of Album: ";
        cin >> ws; // clear newline
        getline(cin, album_name);
        cout << "Enter Album Number: ";
        cin >> album_number;
        cout << "Enter Number of Songs in this Album: ";
        cin >> number_of_songs;
    }

    void display() {
        cout << "  :: Album Number : " << album_number << ", :: Name : " << album_name
             << ", :: Songs : " << number_of_songs;
    }
};

class HashTable {
public:
    Album hash_table[100];
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

    void add(Album val) {
        if (is_table_full()) {
            cout << "Hash table is full. Cannot insert album number " << val.album_number << endl;
            return;
        }

        int hash_value = hash_function(val.album_number);
        int i = hash_value;
        int probe = 0;

        while (is_occupied[i]) {
            if (hash_table[i].album_number == val.album_number) {
                cout << "Duplicate album number! Cannot insert.\n";
                return;
            }
            i = (i + 1) % size;
            probe++;
        }

        hash_table[i] = val;
        is_occupied[i] = true;
        probes[i] = probe_pairs(val.album_number, probe);

        cout << "Inserted album number " << val.album_number << " at index " << i
             << " with " << probe << " probes\n";
    }

    void search() {
        Album val;
        val.accept();

        int hash_value = hash_function(val.album_number);
        int i = hash_value;
        int attempts = 0;
        

        while (is_occupied[i] && attempts < size) {
            if (hash_table[i].album_number == val.album_number) {
                cout << "Value Found at Index: " << i << endl;
                hash_table[i].display();
                cout << endl;
                return;
            }
            i = (i + 1) % size;
            attempts++;
        }

        cout << "Value Not Found!" << endl;
    }

    void effective_search(){
        Album val;
        val.accept();

        int hash_value = hash_function(val.album_number);
        int i = hash_value;
        int probe = probes[i].probe;

        if(hash_table[i + probe].album_number == val.album_number){
            cout << "Value Found at Index: " << i + probe << endl;
            hash_table[i + probe].display();
            cout << endl;
            return;
        }
        else{
            cout << "Value Not Found!" << endl;
            return;
        }
    }

    void remove() {
        Album val;
        val.accept();

        int hash_value = hash_function(val.album_number);
        int i = hash_value;
        int attempts = 0;

        while (is_occupied[i] && attempts < size) {
            if (hash_table[i].album_number == val.album_number) {
                is_occupied[i] = false;
                hash_table[i] = Album();
                probes[i] = probe_pairs();
                cout << "Album removed from index " << i << endl;
                return;
            }
            i = (i + 1) % size;
            attempts++;
        }

        cout << "Album not found. Cannot remove.\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << "  Key :: " << i;
            if (is_occupied[i]) {
                hash_table[i].display();
                cout << " (Probes: " << probes[i].probe << ")";
            } else {
                cout << "null";
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
        cout << "1. Add element\n";
        cout << "2. Search element\n";
        cout << "3. Remove element\n";
        cout << "4. Display table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Album val;
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
