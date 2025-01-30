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

    void reset() {
        modelNo = 0;
        screenSz = 0;
        prc = 0.0f;
    }

    friend istream& operator>>(istream& in, Television& tv) {
        try {
            cout << "Enter model number: ";
            in >> tv.modelNo;
            if (tv.modelNo > 9999) {
                throw string("Error: Model number cannot exceed 4 digits.");
            }

            cout << "Enter screen size (in inches): ";
            in >> tv.screenSz;
            if (tv.screenSz < 12 || tv.screenSz > 70) {
                throw string("Error: Screen size must be between 12 and 70 inches.");
            }

            cout << "Enter price: ";
            in >> tv.prc;
            if (tv.prc < 0 || tv.prc > 5000) {
                throw string("Error: Price must be between $0 and $5000.");
            }
        } catch (const string& err) {
            cout << err << endl;
            tv.reset();
            throw;
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const Television& tv) {
        if (tv.modelNo == 0 && tv.screenSz == 0 && tv.prc == 0.0f) {
            out << "Television details are not available due to invalid input." << endl;
        } else {
            out << "Model Number: " << tv.modelNo << endl;
            out << "Screen Size: " << tv.screenSz << " inches" << endl;
            out << "Price: $" << tv.prc << endl;
        }
        return out;
    }
};

int main() {
    Television tv;

    try {
        cin >> tv;
        cout << "\nTelevision Details:\n" << tv;
    } catch (...) {
        cout << "An error occurred while entering television details. All values have been reset.\n";
        cout << tv;
    }

    return 0;
}
