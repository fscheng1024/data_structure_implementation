#include <iostream>
#include "Expression.h"
#include <stack>
#include <string>

using namespace std;


char* stringToCharArray(std::string str) {
    int n = str.length();
    char char_array[n + 1];
    strcpy(char_array, str.c_str());
}


int indexOfChar(char* arr, char ch) {
    size_t len = strlen(arr);
    for (int i = 0; i < len; ++i) {
        if (arr[i] == ch)
            return i;
    }
    return -1;
}


bool Expression::isLeftBracket(char ch) {
    for (int i = 0; i < kElementsOfBracket; i++) {
        if (ch == leftBrackets[i])
            return true;
    }
    return false;
}


bool Expression::isRightBracket(char ch) {
    for (int i = 0; i < kElementsOfBracket; i++) {
        if (ch == rightBrackets[i])
            return true;
    }
    return false;
}


bool Expression::isBracketsMatched(char left, char right) {

    return indexOfChar(leftBrackets, left) == indexOfChar(rightBrackets, right);
}


bool Expression::isBalanced(std::string input) {
    std::stack<char> result;

    for (int i = 0; i < input.size(); i++) {
        char ch = input[i];

        if (isLeftBracket(ch)) result.push(ch);

        else if (isRightBracket(ch)) {

            if (result.empty()) return false;
        
            char top = result.top();
            result.pop();
            if (!isBracketsMatched(top, ch)) return false;
        }
    }
    return result.empty();

}