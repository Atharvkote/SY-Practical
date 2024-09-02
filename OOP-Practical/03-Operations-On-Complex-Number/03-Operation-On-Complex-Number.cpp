#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Complex {
private:
    float real_part;
    float imaginary_part;

public:
    Complex() {
        real_part = 0.0;
        imaginary_part = 0.0;
    }

    Complex(float real_part, float imaginary_part) {
        this->real_part = real_part;
        this->imaginary_part = imaginary_part;
    }

    Complex operator+(Complex &second_operand) {
        Complex answer;
        answer.real_part = real_part + second_operand.real_part;
        answer.imaginary_part = imaginary_part + second_operand.imaginary_part;
        return answer;
    }

    Complex operator*(Complex &second_operand) {
        Complex answer;
        answer.real_part = real_part * second_operand.real_part - imaginary_part * second_operand.imaginary_part;
        answer.imaginary_part = real_part * second_operand.imaginary_part + imaginary_part * second_operand.real_part;
        return answer;
    }

    Complex operator-(Complex &second_operand) {
        Complex answer;
        answer.real_part = real_part - second_operand.real_part;
        answer.imaginary_part = imaginary_part - second_operand.imaginary_part;
        return answer;
    }

    Complex operator/(Complex &second_operand) {
        Complex answer;
        float denominator = pow(second_operand.real_part, 2.0) + pow(second_operand.imaginary_part, 2.0);
        answer.real_part = (real_part * second_operand.real_part + imaginary_part * second_operand.imaginary_part) / denominator;
        answer.imaginary_part = (imaginary_part * second_operand.real_part - real_part * second_operand.imaginary_part) / denominator;
        return answer;
    }

    void show() {
        cout << "\t [" << fixed << setprecision(2) << real_part << "] + i ["
             << fixed << setprecision(2) << imaginary_part << "]" << endl;
    }

    friend ostream& operator<<(ostream &out, const Complex &a);
    friend istream& operator>>(istream &in, Complex &a);
};

ostream& operator<<(ostream &output, const Complex &a) {
    output << "\t ● [ Answer ] -> (" << a.real_part << ") + i (" << a.imaginary_part << ")";
    return output;
}

istream& operator>>(istream &input, Complex &a) {
    cout << "\t ● Enter Real Part Of the Complex Number: ";
    input >> a.real_part;
    cout << "\t ● Enter Imaginary Part Of the Complex Number: ";
    input >> a.imaginary_part;
    return input;
}

int main() {
    Complex x, y, z;
    int choice;

    cout << "Enter Data For Complex Number 1:\n";
    cin >> x;
    cout << "Enter Data For Complex Number 2:\n";
    cin >> y;

    do {
        cout << "\nOperation Menu:" << endl;
        cout << "1. ADD Complex Number " << endl;
        cout << "2. SUBTRACT Complex Number" << endl;
        cout << "3. MULTIPLY Complex Number " << endl;
        cout << "4. DIVIDE Complex Number " << endl;
        cout << "5. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                z = x + y;
                cout << z << endl;
                break;
            case 2:
                z = x - y;
                cout << z << endl;
                break;
            case 3:
                z = x * y;
                cout << z << endl;
                break;
            case 4:
                z = x / y;
                cout << z << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
