#include <iostream>
using namespace std;

class Person {
public:
    string name;
    string id;
    string gender;
    int age;
    string mobile_number;

    void accept(int x) {
        cout << x << " Person details:\n";
        cout << "Enter the Name: ";
        cin >> name;
        cout << "Enter the ID: ";
        cin >> id;
        cout << "Enter the Gender: ";
        cin >> gender;
        cout << "Enter the Age: ";
        cin >> age;
        cout << "Enter the Mobile Number: ";
        cin >> mobile_number;
    }

    void show() {
        cout << "Name: " << name << endl
             << "ID: " << id << endl
             << "Gender: " << gender << endl
             << "Age: " << age << endl
             << "Mobile Number: " << mobile_number << endl;
    }
};

class Doctor : virtual public Person {
public:
    string specialization;
    float experience;
    string availability;

    void acceptD() {
        cout << "Enter Specialization: ";
        cin >> specialization;
        cout << "Enter Experience (years): ";
        cin >> experience;
        cout << "Enter Availability: ";
        cin >> availability;
    }

    void showD() {
        cout << "Specialization: " << specialization << endl
             << "Experience: " << experience << " years" << endl
             << "Availability: " << availability << endl;
    }
};

class Nurse : virtual public Person {
public:
    string department;
    float shift;

    void acceptN() {
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Shift (hours): ";
        cin >> shift;
    }

    void showN() {
        cout << "Department: " << department << endl
             << "Shift: " << shift << " hours" << endl;
    }
};

class AdministrativeStaff : public Doctor, public Nurse {
public:
    string position;

    void acceptA() {
        cout << "Enter Position: ";
        cin >> position;
    }

    void showA() {
        cout << "Position: " << position << endl;
    }
};

int main() {
    Doctor D[5];
    Nurse N[5];
    AdministrativeStaff A[5];
    int ch, sizeN = 0, sizeD = 0;

    do {
        cout << "Menu\n1. Doctor\n2. Display Doctor Details\n3. Nurse\n4. Display Nurse Details\n5. Search by Name\n6. Exit\n";
        cin >> ch;

        switch (ch) {
        case 1: {
            cout << "Enter the Total no. of Doctor staff: ";
            cin >> sizeD;
            for (int i = 0; i < sizeD; i++) {
                D[i].accept(i + 1);
                D[i].acceptD();
            }
            break;
        }
        case 2: {
            for (int i = 0; i < sizeD; i++) {
                cout << i + 1 << " Doctor Detail\n";
                D[i].show();
                D[i].showD();
                cout << endl;
            }
            break;
        }
        case 3: {
            cout << "Enter the Total no. of Nurse staff: ";
            cin >> sizeN;
            for (int i = 0; i < sizeN; i++) {
                N[i].accept(i + 1);
                N[i].acceptN();
            }
            break;
        }
        case 4: {
            for (int i = 0; i < sizeN; i++) {
                cout << i + 1 << " Nurse Detail\n";
                N[i].show();
                N[i].showN();
                cout << endl;
            }
            break;
        }
        case 5: {
            string searchName;
            cout << "Enter the Name to search (Doctor/Nurse): ";
            cin >> searchName;

            // Search in Doctors
            bool found = false;
            for (int i = 0; i < sizeD; i++) {
                if (D[i].name == searchName) {
                    cout << "Doctor found:\n";
                    D[i].show();
                    D[i].showD();
                    found = true;
                    break; // Exit the loop once found
                }
            }
            if (!found) {
                cout << "Doctor not found.\n";
            }

            // Search in Nurses
            found = false;
            for (int i = 0; i < sizeN; i++) {
                if (N[i].name == searchName) {
                    cout << "Nurse found:\n";
                    N[i].show();
                    N[i].showN();
                    found = true;
                    break; // Exit the loop once found
                }
            }
            if (!found) {
                cout << "Nurse not found.\n";
            }

            break;
        }
        }
    } while (ch != 6);

    return 0;
}
