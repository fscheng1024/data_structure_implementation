#include <iostream>
#include "Array.h"

using namespace std;


bool Array::isFull() {
    return count == sizeof(items) / sizeof(items[0]);
}

bool Array::isEmpty() {
    return count == 0;
}

void Array::resize() {
    int *newItems = new int[count * 2];
    for(int i=0; i<count; i++)
        newItems[i] = items[i];

    delete [] items;
    items = newItems;
}

void Array::insert(int item) {
    if(isFull()) resize();
    items[count++] = item;
}

void Array::insertAt(int item, int index) {
    if(isFull()) resize();
    for(int i = count-1; i >= index; i--)
        items[i + 1] = items[i];
    items[index] = item;
    count++;
}

void Array::remove() {
    items[count] = 0;
    count--;
}

void Array::removeAt(int index) {
    for(int i = index; i < count; i++)
        items[i] = items[i + 1];
    count--;
}

void Array::reverse() {
    int* newItems = new int[count];
    for(int i = 0; i < count; i++)
        newItems[i] = items[count - i - 1];
    items = newItems;
}

void Array::print() {
    for(int i = 0; i < count; i++)
        cout << items[i] << " ";
    cout << endl;
}

int Array::indexOf(int item) {
    for(int i = 0; i < count; i++)
        if (items[i] == item)
            return i;
    return -1;
}


Array Array::intersect(Array other) {
    Array intersection;
    for(int i = 0; i < count; i++) {
        if (other.indexOf(items[i]) >= 0)
            intersection.insert(items[i]);
    }
    return intersection;
}


