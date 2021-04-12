#include <iostream>
#include "Expression.h"
#include <string>
using namespace std;

int main() {
    Expression exp;
    string str = "[{()}]";
    bool result = exp.isBalanced(str);
    printf(result ? "true\n" : "false\n");

}
