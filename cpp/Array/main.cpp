#include <iostream>
#include "Array.h"

using namespace std;


int main(){
    Array array;
    array.insert(1);
    array.insert(2);
    array.insert(3);
    array.insert(4);
    array.insert(5);
    array.insertAt(6, 3);
    array.print();

    array.reverse();
    array.print();

    array.remove();
    array.print();

    array.removeAt(2);
    array.print();
    return 0;
}