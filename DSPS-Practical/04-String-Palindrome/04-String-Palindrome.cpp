#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

class Stack {
    private:
        char stack[20];
        int top;
        int currentSize;
    
    public:
        Stack() {
            top = -1;
            currentSize = 0;
        }
        
        void push(char x) {
            if (top < 19) {
                top++;
                stack[top] = x;
                currentSize++;
            }
        }
        
        char pop() {
            if (top >= 0) {
                char x = stack[top];
                top--;
                currentSize--;
                return x;
            }
            return '$'; 
        }
        
        int size() {
            return currentSize;
        }
};

string remove_symbols(string& text) {
    string result;
    for (char ch : text) {
        if (!ispunct(ch) && ch != ' ') {
            result += tolower(ch);
        }
    }
    return result;
}

bool isPalindrome(string s) {
    Stack stack;
    string clean_string = remove_symbols(s);
    int len = clean_string.length();

    for (int i = 0; i < len; i++) {
        stack.push(clean_string[i]);
    }
    
    for (int i = 0; i < len; i++) {
        if (stack.pop() != clean_string[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string s;
    cout << "  • Enter a String ( Max Length : 20 ) : ";
    getline(cin, s);
    
    if (isPalindrome(s)) {
        cout << "  》 Given String is Palindrome!" << endl;
    } else {
        cout << "  》 Given String is NOT a Palindrome!" << endl;
    }
    
    return 0;
}
