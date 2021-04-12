#include <string>

const int kElementsOfBracket = 4;
int indexOfChar(char* arr, char ch);
char* stringToCharArray(std::string str);

class Expression {
private:
    char leftBrackets[kElementsOfBracket] = { '(', '{', '[', '<' };
    char rightBrackets[kElementsOfBracket] = { ')', '}', ']', '>' };

    bool isLeftBracket(char ch);
    bool isRightBracket(char ch);
    bool isBracketsMatched(char left, char right);

public:
    bool isBalanced(std::string input);
};

