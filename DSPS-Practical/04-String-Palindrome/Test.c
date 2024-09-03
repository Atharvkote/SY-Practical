#include <iostream>
#include <string>
#include <cctype>  // For tolower function

using namespace std;

class Stack {
    private:
        char stack[10];
        int top;
        int currentSize;
    
    public:
        Stack() {
            top = -1;
            currentSize = 0;
        }
        
        void push(char x) {
            if (top < 9) {
                top++;
                stack[top] = x;
                currentSize++;
            } else {
                cout << "Stack Overflow" << endl;
            }
        }
        
        char pop() {
            if (top >= 0) {
                char x = stack[top];
                top--;
                currentSize--;
                return x;
            }
            return '\0'; // Return null character if stack is empty
        }
        
        int size() {
            return currentSize;
        }
};

bool isPalindrome(string s) {
    if (s.length() > 10) {
        cout << "Error: String length exceeds maximum allowed length of 10 (excluding spaces)." << endl;
        return false;
    }

    Stack stack;
    
    // Push non-space characters onto the stack in lowercase
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            stack.push(tolower(s[i]));
        }
    }
    
    // Pop and compare with non-space characters in lowercase
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            if (stack.pop() != tolower(s[i])) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    string s;
    cout << "  • Enter a String ( Max Length : 10 excluding spaces ) : ";
    getline(cin, s);
    
    if (isPalindrome(s)) {
        cout << "  》 Given String is Palindrome!" << endl;
    } else {
        cout << "  》 Given String is NOT a Palindrome!" << endl;
    }
    
    return 0;
}
