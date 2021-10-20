#include <iostream>
#include "Node.h"

class LinkedList {
private:
    int _size;
    Node* head;
    int getSize();
    bool isEmpty();
    bool isSingle();
    bool contains(int value);
    Node* getPrevious(Node* node);

public:
    LinkedList() : head(nullptr) {};
    void print();
    int indexOf(int value);
    void addFirst(int value);
    void addLast(int value);
    void addAt(int index, int value);
    void deleteFirst();
    void deleteLast();
    void deleteAt(int index);
    void deleteValue(int value);
    void clear();
    void reverse();
    int getKthFromEnd(int k);
    Node* swapPairs(Node* head);
};
