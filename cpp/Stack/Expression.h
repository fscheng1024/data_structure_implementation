#include <string>

const int nums_of_bracket = 4;
int indexOfChar(char* arr, char ch);
char* stringToCharArray(std::string str);

class Expression {
private:
    char leftBrackets[nums_of_bracket] = { '(', '{', '[', '<' };
    char rightBrackets[nums_of_bracket] = { ')', '}', ']', '>' };

    bool isLeftBracket(char ch);
    bool isRightBracket(char ch);
    bool isBracketsMatched(char left, char right);

public:
    bool isBalanced(std::string input);
};

