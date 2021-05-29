#include <iostream>
#include "StackArray.h"
using namespace std;


bool StackArray::isEmpty() {
    return count == 0;
}


bool StackArray::isFull() {
    return count == sizeof(items) / sizeof(items[0]);
}


void StackArray::push(int item) {
    if (isFull()) cout << "Is full" << endl;
    items[count++] = item;
}


int StackArray::pop() {
    if (isEmpty()) cout << "Is empty" << endl;
    return items[--count];
}


int StackArray::peek() {
    return items[count-1];
}


void StackArray::print() {
    for(int i = 0; i < count; i++)
        cout << items[i] << " ";
    cout << endl;
}