#include <iostream>
#include <string>

using namespace std;

class BankUser
{
public:
    string name;
    int balance;
    int bank_number;
  
    void initializeAccount() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Bank Number: ";
        cin >> bank_number;
        cout << "Enter Initial Balance: ";
        cin >> balance;  
    }

    bool isSufficientBalance(int withdraw_amount) {
        return withdraw_amount <= balance;//dbg
    }

    void deposit(int deposit_amount) {
        balance += deposit_amount;
        cout << "Deposited Amount: " << deposit_amount << "\n" << "Current Balance: " << balance << endl;
    } 

    void withdraw(int w_amount) {
        if (isSufficientBalance(w_amount)) {
            balance -= w_amount;//dbg
            cout << "Withdraw Amount: " << w_amount << "\n" << "Current Balance: " << balance << endl;
        } else {
            cout << "Insufficient Balance, Can't Withdraw.\n";
        }
    }

    void displayBalance() {
        cout << bank_number << "   " << name << "   " << balance << "\n";
    }

    static int search(BankUser users[], int n, int target) {
        for (int i = 0; i < n; i++) {
            if (target == users[i].bank_number) {
                return i;
            }
        }
        return -1; 
    }
};

int main() {
    BankUser users[5];
    int numberOfUsers = 0;
    int choice;

    do {
        cout << "\nOperation Menu:\n";
        cout << "1. Initialize Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (numberOfUsers < 5) {
                users[numberOfUsers].initializeAccount();
                numberOfUsers++;
            } else {
                cout << "Maximum number of users reached.\n";
            }
            break;
        case 2: {
            int target;
            cout << "Enter Bank Number: ";
            cin >> target;
            int indx = BankUser::search(users, numberOfUsers, target);
            if (indx != -1) {
                int amount;
                cout << "Enter Amount To Deposit: ";
                cin >> amount;
                users[indx].deposit(amount);
            } else {
                cout << "User not found.\n";
            }
            break;
        }
        case 3: {
            int target;
            cout << "Enter Bank Number: ";
            cin >> target;
            int indx = BankUser::search(users, numberOfUsers, target);
            if (indx != -1) {
                int w_amount;
                cout << "Enter Amount To Withdraw: ";
                cin >> w_amount;
                users[indx].withdraw(w_amount);
            } else {
                cout << "User not found.\n";
            }
            break;
        }
        case 4:
            cout<<"\n\n Account No.            Name        Balance"<< endl;
            for (int i = 0; i < numberOfUsers; i++) {
                users[i].displayBalance();
            }
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
