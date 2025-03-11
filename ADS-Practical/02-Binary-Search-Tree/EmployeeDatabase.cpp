#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
public:
    string name;
    int tenure;
    int salary;
    int employeeId;
    Employee *left, *right;

    Employee(string name, int tenure, int salary, int employeeId) {
        this->name = name;
        this->tenure = tenure;
        this->salary = salary;
        this->employeeId = employeeId;
        this->left = this->right = nullptr;
    }

    void display() {
        cout << "| " << setw(10) << employeeId << " | "
             << setw(18) << name << " | "
             << setw(9) << tenure << " | "
             << setw(12) << salary << " |\n";
    }
};

class EmployeeDatabase {
public:
    Employee *root;

    EmployeeDatabase() {
        root = nullptr;
    }

    void displayTableHeader() {
        cout << "+============+====================+===========+==============+\n";
        cout << "| EmployeeID | Name               | Tenure    | Salary       |\n";
        cout << "+============+====================+===========+==============+\n";
    }
    
    void displayTableFooter() {
        cout << "+============+====================+===========+==============+\n";
    }

    void insertEmployee(Employee *&root, string name, int tenure, int salary, int employeeId) {
        if (root == nullptr) {
            root = new Employee(name, tenure, salary, employeeId);
            return;
        }
        if (salary < root->salary) {
            insertEmployee(root->left, name, tenure, salary, employeeId);
        } else {
            insertEmployee(root->right, name, tenure, salary, employeeId);
        }
    }

    void displayDatabase(Employee *root) {
        if (root == nullptr)
            return;
        displayDatabase(root->left);
        root->display();
        displayDatabase(root->right);
    }

    void createDatabase() {
        cout << "Creating Employee Database... \nEnter Details of CEO: \n";
        string name;
        int tenure, salary, employeeId;
        cout << "Enter CEO Name: ";
        cin >> name;
        cout << "Enter CEO Tenure: ";
        cin >> tenure;
        cout << "Enter CEO Salary: ";
        cin >> salary;
        cout << "Enter CEO ID: ";
        cin >> employeeId;
        root = new Employee(name, tenure, salary, employeeId);
        cout << "Employee Database Created Successfully! CEO Added.\n";

        int choice;
        do {
            cout << "Do you want to continue inserting?\n[0] Continue \n[1] Exit\n";
            cin >> choice;
            if (choice == 0) {
                cout << "Enter NAME: ";
                cin >> name;
                cout << "Enter Tenure: ";
                cin >> tenure;
                cout << "Enter Salary: ";
                cin >> salary;
                cout << "Enter ID: ";
                cin >> employeeId;
                insertEmployee(root, name, tenure, salary, employeeId);
            }
        } while (choice == 0);
    }

    void searchBySalaryRecursive(Employee *root, int salary, bool &found) {
        if (root == nullptr)
            return;

        searchBySalaryRecursive(root->left, salary, found);

        if (root->salary == salary) {
            if (!found) {
                cout << "Employees with salary " << salary << "  found:\n";
                displayTableHeader();
                found = true;
            }
            root->display();
        }

        searchBySalaryRecursive(root->right, salary, found);
    }

    void searchBySalary() {
        if (root == nullptr) {
            cout << "Database is empty. Create a database first!\n";
            return;
        }

        int salary;
        cout << "Enter Salary to search: ";
        cin >> salary;
        bool found = false;
        searchBySalaryRecursive(root, salary, found);
        if (found) {
            displayTableFooter();
        } else {
            cout << "No employee found with salary " << salary << " .\n";
        }
    }

    void updateEmployee() {
        int key;
        cout << "Enter Employee ID to update: ";
        cin >> key;
        Employee *result = searchById(root, key);
        if (result) {
            cout << "Updating Employee...\n";
            cout << "Enter new name: ";
            cin >> result->name;
            cout << "Enter new tenure: ";
            cin >> result->tenure;
            cout << "Enter new salary: ";
            cin >> result->salary;
            cout << "Employee Updated Successfully!\n";
        }
    }

    void searchBySalaryIterative(int salary) {
        if (root == nullptr) {
            cout << "Database is empty. Create a database first!\n";
            return;
        }

        Employee *current = root;
        bool found = false;

        while (current != nullptr) {
            if (current->salary == salary) {
                if (!found) {
                    cout << "Employees with salary " << salary << "  found:\n";
                    displayTableHeader();
                    found = true;
                }
                current->display();
            }

            if (salary < current->salary) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (found) {
            displayTableFooter();
        } else {
            cout << "No employee found with salary " << salary << " .\n";
        }
    }

    Employee *searchById(Employee *root, int id) {
        if (root == nullptr || root->employeeId == id)
            return root;
        if (id < root->employeeId)
            return searchById(root->left, id);
        return searchById(root->right, id);
    }

    void findLowestSalary() {
        if (root == nullptr) {
            cout << "No employees in the database.\n";
            return;
        }
        Employee *temp = root;
        while (temp->left != nullptr)
            temp = temp->left;
        cout << "Employee with Lowest Salary:\n";
        displayTableHeader();
        temp->display();
        displayTableFooter();
    }

    void findHighestSalary() {
        if (root == nullptr) {
            cout << "No employees in the database.\n";
            return;
        }
        Employee *temp = root;
        while (temp->right != nullptr)
            temp = temp->right;
        cout << "Employee with Highest Salary:\n";
        displayTableHeader();
        temp->display();
        displayTableFooter();
    }

    int calculateTotalSalary(Employee *root) {
        if (root == nullptr)
            return 0;
        return root->salary + calculateTotalSalary(root->left) + calculateTotalSalary(root->right);
    }

    int countEmployees(Employee *root) {
        if (root == nullptr)
            return 0;
        return 1 + countEmployees(root->left) + countEmployees(root->right);
    }

    float calculateAverageSalary() {
        int totalEmployees = countEmployees(root);
        return totalEmployees > 0 ? (float)calculateTotalSalary(root) / totalEmployees : 0;
    }
};

int main() {
    EmployeeDatabase database;
    database.createDatabase();

    int choice;
    do {
        cout << "\nChoose an option:\n";
        cout << "[1] Display Employee Database\n";
        cout << "[2] Search Employee by Salary (Recursive)\n";
        cout << "[3] Search Employee by Salary (Iterative)\n";
        cout << "[4] Update Employee\n";
        cout << "[5] Get Employee with Lowest Salary\n";
        cout << "[6] Get Employee with Highest Salary\n";
        cout << "[7] Get Average Salary\n";
        cout << "[8] Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            database.displayTableHeader();
            database.displayDatabase(database.root);
            database.displayTableFooter();
            break;
        case 2:
            database.searchBySalary();
            break;
        case 3:
            int salary;
            cout << "Enter Salary to search: ";
            cin >> salary;
            database.searchBySalaryIterative(salary);
            break;
        case 4:
            database.updateEmployee();
            break;
        case 5:
            database.findLowestSalary();
            break;
        case 6:
            database.findHighestSalary();
            break;
        case 7:
            cout << fixed << setprecision(2);
            cout << "Average Salary: " << database.calculateAverageSalary() << " \n";
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid Choice...\n";
            break;
        }
    } while (choice != 8);

    return 0;
}