#include <iostream>
using namespace std;

class probe_pairs
{
public:
    int val;
    int probe;

    probe_pairs()
    {
        val = 0;
        probe = 0;
    }

    probe_pairs(int v, int p)
    {
        val = v;
        probe = p;
    }
};

class HashTable
{
public:
    int hash_table[100];
    bool is_occupied[100];
    probe_pairs probes[100]; // Same size as hash_table
    int size;

    HashTable(int s)
    {
        size = s;
        for (int i = 0; i < size; i++)
        {
            hash_table[i] = 0;
            is_occupied[i] = false;
            probes[i] = probe_pairs();
        }
    }

    int hash_function(int key)
    {
        return key % size;
    }

    bool is_table_full()
    {
        for (int i = 0; i < size; i++)
        {
            if (!is_occupied[i])
                return false;
        }
        return true;
    }

    int get_probe(int val)
    {
        for (int i = 0; i < size; i++)
        {
            if (probes[i].val == val)
            {
                return probes[i].probe;
            }
        }
        return 0;
    }

    void add(int val)
    {
        if (is_table_full())
        {
            cout << "Hash table is full. Cannot insert " << val << endl;
            return;
        }

        int hash_value = hash_function(val);
        int i = hash_value;
        int probe = 0;

        while (is_occupied[i])
        {
            i = (i + 1) % size;
            probe++;
        }

        hash_table[i] = val;
        is_occupied[i] = true;
        probes[i] = probe_pairs(val, probe);

        cout << "Inserted " << val << " at index " << i << " with " << probe << " probes\n";
    }

    void search()
    {
        int val;
        cout << "Enter element you want to search : ";
        cin >> val;

        int hash_value = hash_function(val);
        int probe_value = get_probe(val);

        if (val == hash_table[hash_value + probe_value])
            cout << "Value Found at Key :: " << hash_value + probe_value << endl;
        else 
          cout << "Value Not Found!";
    }
    bool slient_search(int val)
    {
        int hash_value = hash_function(val);
        int probe_value = get_probe(val);

        if (val == hash_table[hash_value + probe_value])
            return true;
        return false;
    }

    void remove(int val)
    {
        int probe_value = get_probe(val);
        int hash_value = hash_function(val);
        int index = (hash_value + probe_value) % size;

        if (hash_table[index] == val && is_occupied[index])
        {
            is_occupied[index] = false;
            hash_table[index] = 0;
            probes[index] = probe_pairs();

            cout << "Value " << val << " removed from index " << index << endl;
        }
        else
        {
            cout << "Value you are trying to remove does not exist\n";
        }
    }

    void display()
    {
        cout << "\n\nHash Table :: {\n";
        for (int i = 0; i < size; i++)
        {
            if (is_occupied[i])
                cout << "   Key : " << i << " :: Value : " << hash_table[i]
                     << " (Probes: " << probes[i].probe << "),\n";
            else
                cout << "   Key : " << i << " :: null,\n";
        }
        cout << "};" << endl;
    }
};

int main()
{
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;
    HashTable h(size);

    int choice, val;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add element\n";
        cout << "2. Search element\n";
        cout << "3. Remove element\n";
        cout << "4. Display table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to add: ";
            cin >> val;
            h.add(val);
            break;
        case 2:
            h.search();
            break;
        case 3:
            cout << "Enter value to remove: ";
            cin >> val;
            h.remove(val);
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
