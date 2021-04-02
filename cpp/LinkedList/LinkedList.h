#include <iostream>
#include "Node.h"

class LinkedList {
private:
    int length;
    Node* first;
    int size();
    bool isEmpty();
    bool isSingle();
    bool contains(int value);
    Node* getPrevious(Node* node);

public:
    LinkedList() : first(nullptr) {};
    void print();
    int indexOf(int value);
    void addFirst(int value);
    void addLast(int value);
    void deleteFirst();
    void deleteLast();
    void deleteAt(int index);
    void deleteValue(int value);
    void clear();
    void reverse();
    int getKthFromEnd(int k);
};
