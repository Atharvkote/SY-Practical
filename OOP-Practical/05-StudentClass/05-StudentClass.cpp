#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_RECORDS = 100;

class Student {
protected:
    string name;
    int rollNo;
    string subject;

public:
    virtual void buildMasterTable() = 0;
    virtual void listTable() const = 0;
    virtual void insertEntry() = 0;
    virtual void deleteEntry(int roll) = 0;
    virtual void editEntry(int roll) = 0;
    virtual void searchRecord(int roll) const = 0;

    virtual ~Student() {}
};

class Marks : public Student {
private:
    struct Record {
        string name;
        int rollNo;
        string subject;
        string subjectCode;
        int internalMarks;
        int universityMarks;

        // Initialize fields separately in methods, avoiding shorthand constructors
        void setDetails(string n, int r, string s, string sc, int im, int um) {
            name = n;
            rollNo = r;
            subject = s;
            subjectCode = sc;
            internalMarks = im;
            universityMarks = um;
        }
    };

    Record records[MAX_RECORDS];
    int recordCount;

public:
    Marks() {
        recordCount = 0;
    }

    void buildMasterTable() override {
        int n;
        cout << "Enter the number of students: ";
        cin >> n;

        if (n > MAX_RECORDS) {
            cout << "Exceeds maximum capacity! Only " << MAX_RECORDS << " entries allowed.\n";
            return;
        }

        for (int i = 0; i < n; ++i) {
            Record rec;
            string name, subject, subjectCode;
            int rollNo, internalMarks, universityMarks;

            cout << "\nEnter details for student " << i + 1 << ":\n";
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Roll Number: ";
            cin >> rollNo;
            cout << "Subject: ";
            cin.ignore();
            getline(cin, subject);
            cout << "Subject Code: ";
            getline(cin, subjectCode);
            cout << "Internal Assessment Marks: ";
            cin >> internalMarks;
            cout << "University Examination Marks: ";
            cin >> universityMarks;

            rec.setDetails(name, rollNo, subject, subjectCode, internalMarks, universityMarks);
            records[recordCount++] = rec;
        }
    }

    void listTable() const override {
        if (recordCount == 0) {
            cout << "No records available!\n";
            return;
        }

        cout << "\nMaster Table:\n";
        cout << left << setw(15) << "Name" << setw(10) << "Roll No" << setw(15) << "Subject" 
             << setw(12) << "Sub Code" << setw(10) << "Internal" << setw(10) << "University" << endl;
        for (int i = 0; i < recordCount; ++i) {
            const Record& rec = records[i];
            cout << left << setw(15) << rec.name << setw(10) << rec.rollNo << setw(15) << rec.subject 
                 << setw(12) << rec.subjectCode << setw(10) << rec.internalMarks << setw(10) << rec.universityMarks << endl;
        }
    }

    void insertEntry() override {
        if (recordCount >= MAX_RECORDS) {
            cout << "No space to add more records.\n";
            return;
        }

        Record rec;
        string name, subject, subjectCode;
        int rollNo, internalMarks, universityMarks;

        cout << "\nEnter details for new student:\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Roll Number: ";
        cin >> rollNo;
        cout << "Subject: ";
        cin.ignore();
        getline(cin, subject);
        cout << "Subject Code: ";
        getline(cin, subjectCode);
        cout << "Internal Assessment Marks: ";
        cin >> internalMarks;
        cout << "University Examination Marks: ";
        cin >> universityMarks;

        rec.setDetails(name, rollNo, subject, subjectCode, internalMarks, universityMarks);
        records[recordCount++] = rec;

        cout << "New entry added successfully!\n";
    }

    void deleteEntry(int roll) override {
        int index = -1;
        for (int i = 0; i < recordCount; ++i) {
            if (records[i].rollNo == roll) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < recordCount - 1; ++i) {
                records[i] = records[i + 1];
            }
            --recordCount;
            cout << "Entry with Roll Number " << roll << " deleted successfully!\n";
        } else {
            cout << "No record found with Roll Number " << roll << "!\n";
        }
    }

    void editEntry(int roll) override {
        int index = -1;
        for (int i = 0; i < recordCount; ++i) {
            if (records[i].rollNo == roll) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            Record& rec = records[index];
            string name, subject, subjectCode;
            int internalMarks, universityMarks;

            cout << "Editing entry for Roll Number " << roll << ":\n";
            cout << "New Name (current: " << rec.name << "): ";
            cin.ignore();
            getline(cin, name);
            cout << "New Subject (current: " << rec.subject << "): ";
            getline(cin, subject);
            cout << "New Subject Code (current: " << rec.subjectCode << "): ";
            getline(cin, subjectCode);
            cout << "New Internal Assessment Marks (current: " << rec.internalMarks << "): ";
            cin >> internalMarks;
            cout << "New University Examination Marks (current: " << rec.universityMarks << "): ";
            cin >> universityMarks;

            rec.setDetails(name, rec.rollNo, subject, subjectCode, internalMarks, universityMarks);
            cout << "Entry updated successfully!\n";
        } else {
            cout << "No record found with Roll Number " << roll << "!\n";
        }
    }

    void searchRecord(int roll) const override {
        for (int i = 0; i < recordCount; ++i) {
            if (records[i].rollNo == roll) {
                const Record& rec = records[i];
                cout << "\nRecord found:\n";
                cout << left << setw(15) << "Name" << setw(10) << "Roll No" << setw(15) << "Subject" 
                     << setw(12) << "Sub Code" << setw(10) << "Internal" << setw(10) << "University" << endl;
                cout << left << setw(15) << rec.name << setw(10) << rec.rollNo << setw(15) << rec.subject 
                     << setw(12) << rec.subjectCode << setw(10) << rec.internalMarks << setw(10) << rec.universityMarks << endl;
                return;
            }
        }
        cout << "No record found with Roll Number " << roll << "!\n";
    }
};

int main() {
    Marks marks;
    int choice, roll;

    do {
        cout << "\nMenu:\n";
        cout << "1. Build Master Table\n2. List Table\n3. Insert New Entry\n4. Delete Entry\n";
        cout << "5. Edit Entry\n6. Search for a Record\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: marks.buildMasterTable(); break;
            case 2: marks.listTable(); break;
            case 3: marks.insertEntry(); break;
            case 4:
                cout << "Enter Roll Number to delete: ";
                cin >> roll;
                marks.deleteEntry(roll);
                break;
            case 5:
                cout << "Enter Roll Number to edit: ";
                cin >> roll;
                marks.editEntry(roll);
                break;
            case 6:
                cout << "Enter Roll Number to search: ";
                cin >> roll;
                marks.searchRecord(roll);
                break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
