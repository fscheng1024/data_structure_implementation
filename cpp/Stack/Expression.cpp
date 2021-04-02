#include <iostream>
#include "Expression.h"
#include <stack>
#include <string>

using namespace std;

bool Expression::isLeftBracket(char ch) {
    for (int i = 0; i < nums_of_bracket; i++) {
        if (ch == leftBrackets[i])
            return true;
    }
    return false;
}


bool Expression::isRightBracket(char ch) {
    for (int i = 0; i < nums_of_bracket; i++) {
        if (ch == rightBrackets[i])
            return true;
    }
    return false;
}


char* stringToCharArray(std::string str) {
    int n = str.length();
    char char_array[n + 1];
    strcpy(char_array, str.c_str());
}


int indexOfChar(char* arr, char ch) {
    string tmp(arr);
    char* out = stringToCharArray(tmp);
    for (int i = 0; i < nums_of_bracket; ++i) {
        if (out[i] == ch)
            return i;
    }
    return -1;
}


bool Expression::isBracketsMatched(char left, char right) {

    return indexOfChar(leftBrackets, left) == indexOfChar(rightBrackets, right);
}


bool Expression::isBalanced(std::string input) {
    std::stack<int> myStack;

    for (int i = 0; i < input.size(); i++) {
        char ch = input[i];
        if (isLeftBracket(ch))
            myStack.push(ch);
        if (isRightBracket(ch)) {
            if (myStack.empty())
                return false;

            char top = myStack.top();
            myStack.pop();
            if (!isBracketsMatched(top, ch))
                return false;
        }
        return myStack.empty();
    }

}