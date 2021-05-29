#include <iostream>
#include <string>
#include "Expression.h"
#include "StackArray.h"

using namespace std;

int main() {
    Expression exp;
    string str = "[{()}]";
    bool result = exp.isBalanced(str);
    printf(result ? "true\n" : "false\n");


    StackArray sa;
    sa.push(1);
    sa.push(2);
    sa.push(3);
    sa.push(4);
    sa.push(5);
    sa.print();

    cout << sa.pop() << endl;
    sa.print();
    cout << sa.peek() << endl;
}
