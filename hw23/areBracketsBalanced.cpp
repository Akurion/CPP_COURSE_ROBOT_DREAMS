#include "areBracketsBalanced.h"
#include <stack>

bool areBracketsBalanced(const std::string& expression) {
    std::stack<char> bracketStack;

    for (char bracket : expression) {
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            bracketStack.push(bracket);
        }
        else if (bracket == ')' || bracket == '}' || bracket == ']') {
            if (bracketStack.empty() ||
                (bracket == ')' && bracketStack.top() != '(') ||
                (bracket == '}' && bracketStack.top() != '{') ||
                (bracket == ']' && bracketStack.top() != '[')) {
                return false;  
            }
            else {
                bracketStack.pop();
            }
        }
    }

    return bracketStack.empty();
}
