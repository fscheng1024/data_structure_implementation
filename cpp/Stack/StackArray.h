#include <iostream>

class StackArray {
    private:
        int *items;
        int count;
        bool isFull();
        bool isEmpty();

    public:
        StackArray(int length): count(0) { items = new int[length]; }
        void print();
        void push(int item);
        int pop();
        int peek();
};