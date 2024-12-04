#include <iostream>
#include <string>
using namespace std;

class Television {
private:
    int modelNo;
    int screenSz;
    float prc;

public:
    Television() {
        modelNo = 0;
        screenSz = 0;
        prc = 0.0f;
    }

    void input() {
        try {
            cout << "Enter model number: ";
            cin >> modelNo;
            if (modelNo > 9999) {
                throw string("Error: Model number cannot exceed 4 digits.");
            }

            cout << "Enter screen size (in inches): ";
            cin >> screenSz;
            if (screenSz < 12 || screenSz > 70) {
                throw string("Error: Screen size must be between 12 and 70 inches.");
            }

            cout << "Enter price: ";
            cin >> prc;
            if (prc < 0 || prc > 5000) {
                throw string("Error: Price must be between $0 and $5000.");
            }
        } catch (const string& err) {
            cout << err << endl;
            reset();
            throw;
        }
    }

    void display() {
        if (modelNo == 0 && screenSz == 0 && prc == 0.0f) {
            cout << "Television details are not available due to invalid input." << endl;
        } else {
            cout << "Model Number: " << modelNo << endl;
            cout << "Screen Size: " << screenSz << " inches" << endl;
            cout << "Price: $" << prc << endl;
        }
    }

    void reset() {
        modelNo = 0;
        screenSz = 0;
        prc = 0.0f;
    }
};

int main() {
    Television tv;

    try {
        tv.input();
        cout << "\nTelevision Details:\n";
        tv.display();
    } catch (...) {
        cout << "An error occurred while entering television details. All values have been reset.\n";
        tv.display();
    }

    return 0;
}
