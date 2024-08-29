#include <iostream>
#include <cstring>
#include <string>

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
            }
        }
        
        char pop() {
            if (top >= 0) {
                char x = stack[top];
                top--;
                currentSize--;
                return x;
            }

        }
        
        int size() {
            return currentSize;
        }
};

bool isPalindrome(string s) {
    
    Stack stack;
    
    for (int i = 0; i < s.length(); i++) {
        stack.push(s[i]);
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (stack.pop() != s[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string s;
    cout << "  • Enter a String ( Max Length : 10 ) : ";
    getline(cin, s);
    
    if (isPalindrome(s)) {
        cout << "  》 Given String is Palindrome!";
    } else {
        cout << "  》 Given String is NOT a Palindrome!";
    }
    
    return 0;
}
