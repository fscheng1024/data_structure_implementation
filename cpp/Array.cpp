#include <iostream>

using namespace std;

class Array {
    private:
        int *items;
        int count=0;
        void resize();
        bool isFull();
        bool isEmpty();

    public:
        Array() { items = new int[count](); }
        void insert(int item);
        void insertAt(int item, int index);
        void remove();
        void removeAt(int index);
        void reverse();
        void print();
        int indexOf(int item);
        Array intersect(Array other);
};

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
    for(int i=count-1; i>=index; i--)
        items[i + 1] = items[i];
    items[index] = item;
    count++;
}

void Array::remove() {
    items[count] = 0;
    count--;
}

void Array::removeAt(int index) {
    for(int i=index; i<count; i++)
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
    for(int i=0; i<count; i++)
        cout << items[i] << " ";
    cout << endl;
}

int Array::indexOf(int item) {
    for(int i=0; i<count; i++)
        if (items[i] == item)
            return i;
    return -1;
}


Array Array::intersect(Array other) {
    Array intersection;
    for(int i=0; i<count; i++) {
        if (other.indexOf(items[i]) >= 0)
            intersection.insert(items[i]);
    }
    return intersection;
}


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