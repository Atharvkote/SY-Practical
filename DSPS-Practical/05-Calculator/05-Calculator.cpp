#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
        char stack[30];
        int top;
        int currentSize;
    
    public:
        Stack() {
            top = -1;
            currentSize = 0;
        }
        
        void push(char x) {
            if (top < 29) {
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

        bool isEmpty() {
            return top == -1;
        }

        char peek() {
            if (top >= 0) {
                return stack[top];
            }
            return '$';
        }
};

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else
        return -1;
}

int lengthOf(string s) {
    int len = 0, i = 0;
    while (s[i] != '\0') {
        len++;
        i++;
    }
    return len;
}

string infixToPostfix(string infix) {
    Stack stack;
    string postfix_string = "";
    char c;

    int length = lengthOf(infix);
    for (int i = 0; i < length; i++) {
        c = infix[i];
        if (precedence(c) > 0) {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(c)) {
                postfix_string += stack.pop();
            }
            stack.push(c);
        } else if (c == ')') {
            char x = stack.pop();
            while (x != '(') {
                postfix_string += x;
                x = stack.pop();
            }
        } else if (c == '(') {
            stack.push(c);
        } else {
            postfix_string += c;
        }
    }

    while (!stack.isEmpty()) {
        postfix_string += stack.pop();
    }

    return postfix_string;
}

int main() {
    string infix_expression;
    
    cout << "ENTER AN INFIX EXPRESSION: ";
    getline(cin, infix_expression);
    
    string postfix_expression = infixToPostfix(infix_expression);
    
    cout << "POSTFIX EXPRESSION: " << postfix_expression << endl;

    return 0;
}
