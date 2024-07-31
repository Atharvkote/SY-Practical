#include <iostream>
#include <string>

using namespace std;

class BankUser
{
private:
    string name;
    int balance;
    int bank_number;

public:
    // Default constructor
    BankUser(){
        this->name = "name";
        this->bank_number = 0;
        this->balance = 0;
    }

    // Overloaded constructor
    BankUser(string name, int bank_number, int balance){
        this->name = name;
        this->bank_number = bank_number;
        this->balance = balance;
    }

    int getBalance(){
        return this->balance;
    }

    string getName(){
        return this->name;
    }

    int getBankNumber(){
        return this->bank_number;
    }

    bool isSufficientBalance(int withdraw_amount){
        return withdraw_amount <= this->balance;
    }

    void deposit(int deposit_amount){
        this->balance += deposit_amount;
    }

    void withdraw(int withdraw_amount){
        if (isSufficientBalance(withdraw_amount)){
            this->balance -= withdraw_amount;
        }
        else{
            cout << "Insufficient Balance, Can't Withdraw.\n";
        }
    }

    void displayBalance(){
        cout << "\n\n\t\t-----------Account Holder Details-------------\n";
        cout << "\t\t\tAccount Holder Name: " << this->getName() << endl;
        cout << "\t\t\tAccount Holder Bank Number: " << this->getBankNumber() << endl;
        cout << "\t\t\tAccount Holder Balance: " << this->getBalance() << endl;
        cout << "\n";
    }

    void requestWithdraw(){
        int w_amount;
        cout << "Enter Amount To Withdraw: ";
        cin >> w_amount;

        this->withdraw(w_amount);
    }
};

int main()
{
    BankUser user;
    int choice, amount;

    do{
        cout << "\nOperation Menu:\n";
        cout << "1. Initialize Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
        case 1:{
            string name;
            int bank_number, balance;
            
            // Clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Bank Number: ";
            cin >> bank_number;
            cout << "Enter Initial Balance: ";
            cin >> balance;

            user = BankUser(name, bank_number, balance);
            break;
        }
        case 2:
            cout << "Enter Amount To Deposit: ";
            cin >> amount;
            user.deposit(amount);
            break;
        case 3:
            user.requestWithdraw();
            break;
        case 4:
            user.displayBalance();
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
