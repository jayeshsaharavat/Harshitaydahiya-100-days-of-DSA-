//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//An input string is valid if: Open brackets must be closed by the same type of brackets.

#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int n = strlen(s);
    char stack[n];     // stack array
    int top = -1;

    for(int i = 0; i < n; i++) {
        char ch = s[i];

        // Push opening brackets
        if(ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else {
            // If stack empty → invalid
            if(top == -1) {
                return false;
            }

            char topChar = stack[top--];

            // Check matching pairs
            if((ch == ')' && topChar != '(') ||
               (ch == '}' && topChar != '{') ||
               (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    // If stack empty → valid
    return (top == -1);
}
